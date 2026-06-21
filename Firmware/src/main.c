#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/**
 * @brief The last 1KB (page size) of flash is reserved for user data.
 * The maximum program capasity is 63KB.
 */
  
#include <stdint.h>

#include "K1921VK035.h"

#include "../inc/board.h"
#include "../inc/tick.h"
#include "../inc/flash_if.h"
#include "../inc/MATA_37644.h"
#include "../inc/MALD_37645.h"
#include "../inc/sfp28.h"
#include "../inc/soft_slave_i2c.h"
#include "../inc/soft_master_i2c.h"

void Init_variables(void);
void periph_init(void);
void Check_timer_interval(void);
void Load_memory_from_Flash(void);
void Check_register_action(void);
void Update_diagnostic_regs(void);

extern uint8_t Time_flags;

//Temp variables
uint8_t Temp_buffer[128];
uint8_t Temp_page_data[128];

A0_Page_t A0_Page __attribute__((aligned(128)));
A2_Page_t A2_Page __attribute__((aligned(128)));
A2Up_Page_t A2Up_Page __attribute__((aligned(128)));

//-----------------------------------------------------------------------------
// main() Routine
// ----------------------------------------------------------------------------
int main (void) {
  SystemCoreClockUpdate();
  
  periph_init();

  Init_variables();

	//Load SFP28 module memory blocks from flash
	Load_memory_from_Flash();
  
  Init_MALD_37645();
  Init_MATA_37644();

  while (1) {
    //Check timer intervals
    Check_timer_interval();

    Check_register_action();

  }
}

//====================================
static void gpio_init(){
	//Enable GPIO function for ports A and B
	RCU->HCLKCFG_bit.GPIOAEN = 1;
	RCU->HRSTCFG_bit.GPIOAEN = 1;
	RCU->HCLKCFG_bit.GPIOBEN = 1;
	RCU->HRSTCFG_bit.GPIOBEN = 1;

  // Disable alternate function for A4, A5, A6
	GPIO_DEV_I2C->LOCKKEY = 0xADEADBEE; // unlock LOCKSET [page 226]
  GPIO_DEV_I2C->LOCKCLR = SFP_SCL_MASK | SFP_SDA_MASK | TX_FAULT_MASK; // unlock A4, A5, A6
  GPIO_DEV_I2C->LOCKKEY = 0x00000000; // lock LOCKSET [page 226]
  GPIO_DEV_I2C->ALTFUNCCLR = SFP_SCL_MASK | SFP_SDA_MASK | TX_FAULT_MASK; // clear alternative function for A4, A5, A6

	// Soft I2C slave interface to external connector 
	// It is init in appropriate function

	// Soft I2C master interface to internal devices

	// TX_FAULT output
	GPIO_TX_FAULT->DENSET = TX_FAULT_MASK; // enable Pin [page 210]
  GPIO_TX_FAULT->DATAOUTCLR = TX_FAULT_MASK; // default level is Low
  GPIO_TX_FAULT->OUTENSET = TX_FAULT_MASK; // Enable Out[page 51], [page 9]

	// TX_DISABLE input
	GPIO_TX_DISABLE->DENSET = TX_DISABLE_MASK; // enable pin [page 210]
  GPIO_TX_DISABLE->INMODE_bit.TX_DISABLE_PIN = 0x1; //CMOS input [page 51], [page 9]
  
	// RST_TX output
	GPIO_RST_TX->DENSET = RST_TX_MASK; // enable Pin [page 210]
  GPIO_RST_TX->DATAOUTSET = RST_TX_MASK; // default level is High
  GPIO_RST_TX->OUTENSET = RST_TX_MASK; // Enable Out[page 51], [page 9]

	// RST_RX output
	GPIO_RST_RX->DENSET = RST_RX_MASK; // enable Pin [page 210]
  GPIO_RST_RX->DATAOUTSET = RST_RX_MASK; // default level is High
  GPIO_RST_RX->OUTENSET = RST_RX_MASK; // Enable Out[page 51], [page 9]

	// IC_RS0 output
	GPIO_IC_RS0->DENSET = IC_RS0_MASK; // enable Pin [page 210]
  GPIO_IC_RS0->DATAOUTSET = IC_RS0_MASK; // default level is High (28Gb/s mode)
  GPIO_IC_RS0->OUTENSET = IC_RS0_MASK; // Enable Out[page 51], [page 9]
	// IC_RS1 output
	GPIO_IC_RS1->DENSET = IC_RS1_MASK; // enable Pin [page 210]
  GPIO_IC_RS1->DATAOUTSET = IC_RS1_MASK; // default level is High (28Gb/s mode)
  GPIO_IC_RS1->OUTENSET = IC_RS1_MASK; // Enable Out[page 51], [page 9]

	// LOS 
	GPIO_LOS->DENSET = LOS_PIN_MASK; // OUT enable [page 210]
  GPIO_LOS->OUTENSET = LOS_PIN_MASK; // [page 51], [page 9]
	//TEST
//  GPIO_LOS->OUTMODE_bit.LOS_PIN = 0x1 ; // open drain [page 51] [page 212]
	//TEST
  GPIO_LOS->DATAOUTSET = LOS_PIN_MASK;       // default level is High

	// RS0 input from SFP connector
	GPIO_RS0->DENSET = RS0_PIN_MASK; // enable pin [page 210]
  GPIO_RS0->INMODE_bit.RS0_PIN = 0x1; //CMOS input  [page 51], [page 9]
  
	// RS1 input from SFP connector
	GPIO_RS1->DENSET = RS1_PIN_MASK; // enable pin [page 210]
  GPIO_RS1->INMODE_bit.RS1_PIN = 0x1; //CMOS input  [page 51], [page 9]
  
}
//====================================

//====================================
void Init_variables(void) {
  int i;
	memset(&A0_Page, 0, 128);
  memset(&A2_Page, 0, 128);
  memset(&A2Up_Page, 0, 128);
	
	for(i=0; i<128; i++) {
		A0_Page.Bytes[i] = i;
		A2_Page.Bytes[i] = i+128;
		A2Up_Page.Bytes[i] = 127-i;
	}
}
//====================================

//====================================
void periph_init() {
  gpio_init();

  tick_init(SystemCoreClock); // periodic timers
  
	// Init slave interface to external connector
	soft_i2c_slave_init();

	// Init master interface to internal devices 
	soft_i2c_master_init();
}
//====================================

//====================================
void Check_timer_interval() {
  if(Time_flags & TIME_100MS_FLAG) { // 100 ms
    Time_flags &= ~TIME_100MS_FLAG;

    Work_with_MATA_ADC();
    Work_with_MALD_ADC();

    Update_diagnostic_regs();
  }
	
  if(Time_flags & TIME_500MS_FLAG) { // 500 ms
    Time_flags &= ~TIME_500MS_FLAG;

    Read_MALD_state();
    Read_MATA_state();
  }
	
  if(Time_flags & TIME_1SEC_FLAG) { // 1 s
    //1 second interval
    Time_flags &= ~TIME_1SEC_FLAG;

    //Read CPU temperature
    //Read_temperature_sensor();

    //TEST
		GPIO_LOS->DATAOUTTGL = LOS_PIN_MASK;
//		GPIO_LOS->DATAOUTCLR = LOS_PIN_MASK;
//		GPIO_LOS->DATAOUTSET = LOS_PIN_MASK;
		GPIO_RST_TX->DATAOUTTGL = RST_TX_MASK;
    //TEST
	}
}
//====================================

//====================================
//Function to check CC_BASE and CC_EXT fields
//Output: 0 - both fields are correct, 1..3 - one or both fields are incorrect
static uint8_t Check_CC_BASE_and_CC_EXT(const uint8_t *A0Low_ptr) {
  uint8_t result = 0;  //default result is OK

  //Check CC_BASE
  uint16_t crc = 0;
  for(uint16_t i = CC_BASE_START; i < CC_BASE_POS; i++) {
    crc += A0Low_ptr[i];
  }
  if(A0Low_ptr[CC_BASE_POS] != (crc & 0xFF)) {
    result += 1;
  }

  //Check CC_BASE
  crc = 0;
  for(uint16_t i = CC_EXT_START; i < CC_EXT_POS; i++) {
    crc += A0Low_ptr[i];
  }
  if(A0Low_ptr[CC_EXT_POS] != (crc & 0xFF)) {
    result += 2;
  }

  return result;
}
//====================================

//====================================
static uint8_t Check_CC_DMI(const uint8_t *A2Low_ptr) {
  //Check CC_DMI
  uint16_t crc = 0;
  for(uint16_t i = CC_DMI_START; i < CC_DMI_POS; i++) {
    crc += A2Low_ptr[i];
  }

  return A2Low_ptr[CC_DMI_POS] != (crc & 0xFF);
}
//====================================

//====================================
static uint8_t Check_Cfg_data_CSum(const A2Up_Page_t *A2UpPtr) {
  //Check CC_BASE
  uint16_t crc = 0;
  for(uint16_t i = 0; i < sizeof(MATA_cfg_t) + sizeof(MALD_cfg_t); i++) {
    crc += A2UpPtr->Bytes[i];
  }

  return crc != A2UpPtr->var.CSum;
}
//====================================

//====================================
void Load_memory_from_Flash(void)
{
	uint8_t Temp_u8;
	uint16_t Temp_u16, i;
	//Load A0 Page
  flash_read(FLASH_A0,    (uint8_t*)&A0_Page,   sizeof(A0_Page));
	Temp_u8 = Check_CC_BASE_and_CC_EXT(A0_Page.Bytes);
	if(Temp_u8 != 0) {
		//Incorrect values for CC_BASE and CC_EXT -> init default values
		//Init default values of non-volatile elements of A0 Low Page
		//A0.92 - DDM is implemented (bit6), internally calibrated (bit5), average power (bit3)
		// other bits are zero
		A0_Page.var.DiagMon_Type = 0x68;

		//Calc CC_BASE
		Temp_u16 = 0;
		for(i=CC_BASE_START; i<CC_BASE_POS; i++) {
			Temp_u16 += A0_Page.Bytes[i];
		}
		A0_Page.Bytes[CC_BASE_POS] = (Temp_u16 & 0xFF);

		//Calc CC_EXT
		Temp_u16 = 0;
		for(i=CC_EXT_START; i<CC_EXT_POS; i++) {
			Temp_u16 += A0_Page.Bytes[i];
		}
		A0_Page.Bytes[CC_EXT_POS] = (Temp_u16 & 0xFF);
	}

	//Load A2 Low Page
  flash_read(FLASH_A2,    (uint8_t*)&A2_Page,   sizeof(A2_Page));
	Temp_u8 = Check_CC_DMI(A2_Page.Bytes);
	if(Temp_u8 != 0) {
		//Incorrect value for CC_DMI -> init default values
		// Init default values of non-volatile elements of A2 Low Page
		memset(A2_Page.var.CalibrConst, 0, sizeof(A2_Page.var.CalibrConst));
		A2_Page.Bytes[71] = 1;	//Rx_PWR(1) should be set to 1 for "internally calibrated" devices
		A2_Page.Bytes[77] = 1;	//Tx_I(Slope) should be set to 1 for "internally calibrated" devices
		A2_Page.Bytes[81] = 1;	//Tx_PWR(Slope) should be set to 1 for "internally calibrated" devices
		A2_Page.Bytes[85] = 1;	//T(Slope) should be set to 1 for "internally calibrated" devices
		A2_Page.Bytes[89] = 1;	//V(Slope) should be set to 1 for "internally calibrated" devices
		//Calc CC_DMI
		Temp_u16 = 0;
		for(i=CC_DMI_START; i<CC_DMI_POS; i++) {
			Temp_u16 += A2_Page.Bytes[i];
		}
		A2_Page.Bytes[CC_DMI_POS] = (Temp_u16 & 0xFF);
	}

	//Load A2 Up Page to temp buffer
  flash_read(FLASH_A2_UP, Temp_page_data, sizeof(A2Up_Page));
	//Check CSum
	if(Check_Cfg_data_CSum((A2Up_Page_t *)&Temp_page_data) == 0) {
		//Correct CSum -> Copy only config data from temp buffer to config structure
		memcpy((uint8_t *)&A2Up_Page, Temp_page_data, (sizeof(MATA_cfg_t) + sizeof(MALD_cfg_t) + 2));	//copy data with CSum
	} else {
		//CSum is incorrect -> leave default values of config (it is init early)
	}
}
//====================================

//====================================
static void cmd_update_flash_page(void) {
  uint16_t check_sum = 0;
  for(uint8_t i = 0; i < 128; i++) {
    check_sum += Temp_page_data[i];
  }
  
  const uint16_t correct_crc = ((A2Up_Page.var.GrpBuf_CRC[0] << 8) | A2Up_Page.var.GrpBuf_CRC[1]);
  
  if (check_sum != correct_crc) {
    A2Up_Page.var.GrpCmdResult = GRP_CMD_RESULT_CRC_FAIL;
    return;
  }
  //Correct CRC -> check page number (UpPage05.var.GrpAddress)

  switch (A2Up_Page.var.GrpAddress) {
  case FLASH_UPD_A0_LOW: {
      //Update A0 Low Page -> Check CC_BASE and CC_EXT
      const uint8_t result = Check_CC_BASE_and_CC_EXT(Temp_page_data);
      if(result != 0) { 
        A2Up_Page.var.GrpCmdResult = GRP_CMD_RESULT_CC_BASE_FAIL + result - 1;
        return;
      }
      //Correct values for CC_BASE and CC_EXT
      //Copy data to A0 Low Page in RAM
      memcpy(&A0_Page.Bytes[0], Temp_page_data, 128);
      //Update A0 Low page in Flash
			if(flash_update(FLASH_A0, Temp_page_data, 128) != 0) {
        A2Up_Page.var.GrpCmdResult = GRP_CMD_RESULT_FL_UPD_FAIL;
        return;
			}				
    }
    break;
  case FLASH_UPD_A2_LOW: {
      //Update A2 Low Page -> Check CC_DMI
      const uint8_t result = Check_CC_DMI(Temp_page_data);
      if (result != 0) {
        A2Up_Page.var.GrpCmdResult = GRP_CMD_RESULT_CC_DMI_FAIL;
        return;
      }
      //Correct values for CC_DMI
      //Copy data to A2 Low Page in RAM
      memcpy(&A2_Page.Bytes[0], Temp_page_data, 128);
      //Update A2 Low page in Flash
			if(flash_update(FLASH_A2, Temp_page_data, 128) != 0) {
        A2Up_Page.var.GrpCmdResult = GRP_CMD_RESULT_FL_UPD_FAIL;
        return;
			}				
    }
    break;
  case FLASH_UPD_A2_HI: {
      // Convert CRC from big endian to litle endian
      const uint8_t tmp_byte = Temp_page_data[54];
      Temp_page_data[54] = Temp_page_data[55];
      Temp_page_data[55] = tmp_byte;
      if (Check_Cfg_data_CSum((A2Up_Page_t *)&Temp_page_data) != 0) {
        A2Up_Page.var.GrpCmdResult = GRP_CMD_RESULT_CFG_CRC_FAIL;
        return;
      }
      //Copy only config structure to A2Up page in RAM
      memcpy((uint8_t *)&A2Up_Page, Temp_page_data, (sizeof(MATA_cfg_t) + sizeof(MALD_cfg_t) + 2));  //copy data with CSum
      //Update A2 Hi page in Flash
			if(flash_update(FLASH_A2_UP, Temp_page_data, 128) != 0) {
        A2Up_Page.var.GrpCmdResult = GRP_CMD_RESULT_FL_UPD_FAIL;
        return;
			}				
    }
    break;
  default:
    break;
  }
  A2Up_Page.var.GrpCmdResult = GRP_CMD_RESULT_OK;
}
//====================================

//====================================
void Check_register_action(void) {
  if(A2Up_Page.var.GrpCommand == 0) {
    return; // Nothing to do.
  }

  //There is active group command
  A2Up_Page.var.GrpCmdResult = 0xFF;

  switch (A2Up_Page.var.GrpCommand) {
  case GRP_CMD_MATA_DATA_RD:
//    cmd_read_data_from(MATA_CHIPID);
    break;
  case GRP_CMD_MATA_DATA_WR:
//    cmd_write_data_to(MATA_CHIPID);
    break;
  case GRP_CMD_MALD_DATA_RD:
//    cmd_read_data_from(MALD_CHIPID);
    break;
  case GRP_CMD_MALD_DATA_WR:
//    cmd_write_data_to(MALD_CHIPID);
    break;
  case GRP_CMD_UPD_TX_CFG:
//    cmd_write_MALD_config();
    break;
  case GRP_CMD_UPD_GLB_RX_CFG:
//    cmd_write_MATA_config();
    break;
  case GRP_CMD_WRITE_1ST_QUARTER:
    //Group command to write 1st quarter (32 bytes) of page data
    memcpy(Temp_page_data, A2Up_Page.var.GrpBuffer, 32);
    break;
  case GRP_CMD_WRITE_2ND_QUARTER:
    //Group command to write 2nd quarter (32 bytes) of page data
    memcpy(&Temp_page_data[32], A2Up_Page.var.GrpBuffer, 32);
    break;
  case GRP_CMD_WRITE_3RD_QUARTER:
    //Group command to write 3rd quarter (32 bytes) of page data
    memcpy(&Temp_page_data[64], A2Up_Page.var.GrpBuffer, 32);
    break;
  case GRP_CMD_WR_4TH_Q_AND_UPDATE:
    //Group command to write 4th quarter (32 bytes) of page data and update flash page
    memcpy(&Temp_page_data[96], A2Up_Page.var.GrpBuffer, 32);
    cmd_update_flash_page();
    break;
  default:
    break;
  }

  A2Up_Page.var.GrpCommand = 0;  //Command is handled -> Clear it
}
//====================================

//====================================
void Update_diagnostic_regs(void) {
	// Stat_Control is updated in `read_in_pins`
	A2_Page_TypeDef* A2 = &A2_Page.var;
	A2Up_Page_TypeDef* A2Up = &A2Up_Page.var;
	
	const float MATA_temp = 0.29f * ((float)A2Up->MATA_ADC_Temp - 1133.f) + 25.f; // [deg]
	const int16_t MATA_temp_i = (int16_t)(MATA_temp * 256.f + 0.5f); // compatibility with old CARL GUI
	A2->MATA_Temp[0] = MATA_temp_i >> 8;
	A2->MATA_Temp[1] = MATA_temp_i & 0xFF;
	
	const float MATA_3v3 = (float)A2Up->MATA_ADC_V33 / 594.f; // [V]
	const int16_t MATA_3v3_i = (int16_t)(MATA_3v3 * 10000.f + 0.5f); // compatibility with old CARL GUI
	A2->MATA_Vcc[0] = MATA_3v3_i >> 8;
	A2->MATA_Vcc[1] = MATA_3v3_i & 0xFF;
	
	const float IBIAS_VAR1 = 1.f; // MALD datasheet page 18
	const uint16_t IBIAS_VAR2 = A2Up_Page.var.MALD_ADC_IBIAS_ref;
	const uint16_t IBIAS_VAR3 = A2Up->MALD_ADC_IBIAS_msrt;
	const float MALD_IBIAS = (float)(IBIAS_VAR3 - IBIAS_VAR2) * IBIAS_VAR1 * 40.1e-6f * 1000.f; // [mA] MALD datasheet page 16
	const int16_t MALD_IBIAS_i = (int16_t)(MALD_IBIAS * 500.f + 0.5f); // compatibility with old CARL GUI
	A2->TxBias[0] = MALD_IBIAS_i >> 8;
	A2->TxBias[1] = MALD_IBIAS_i & 0xFF;
	
	const float MALD_IMON = (float)A2Up->MALD_ADC_IMON * 411e-9f * 1e3f; // [mA]
	const int16_t MALD_IMON_i = (int16_t)(MALD_IMON * 10000.f + 0.5f); // compatibility with old CARL GUI
	A2->TxPower[0] = MALD_IMON_i >> 8;
	A2->TxPower[1] = MALD_IMON_i & 0xFF;
	
	const float MATA_RSII = (float)A2Up->MATA_ADC_RSSI * 411e-9f * 1e3f; // [mA]
	const int16_t MATA_RSII_i = (int16_t)(MATA_RSII * 10000.f + 0.5f); // compatibility with old CARL GUI
	A2->RxPower[0] = MATA_RSII_i >> 8;
	A2->RxPower[1] = MATA_RSII_i & 0xFF;

//	A2->MALD_Vcc[0] = A2Up->MALD_ADC_V33 >> 8;
//	A2->MALD_Vcc[1] = A2Up->MALD_ADC_V33 & 0xFF;

//	A2->MALD_Temp[0] = A2Up->MALD_ADC_Temp >> 8;
//	A2->MALD_Temp[1] = A2Up->MALD_ADC_Temp & 0xFF;
}
//====================================


