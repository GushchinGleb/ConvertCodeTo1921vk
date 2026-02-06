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
#include "../inc/eeprom_a0a2.h"
#include "../inc/flash_if.h"
#include "../inc/MASC_37029_defs.h"
#include "../inc/pages.h"
#include "../inc/sfp28.h"
#include "../inc/soft_i2c.h"
#include "../inc/tick.h"

#include "../Retarget/retarget_conf.h" // printf

#define CHECK_INT_I2C // perform internal I2C check

extern uint8_t Time_flags;
extern A0_Page_t A0_Page; // from eeprom_a0a2.c
extern A2_Page_t A2_Page; // from eeprom_a0a2.c
extern A2Up_Page_t A2Up_Page; // from eeprom_a0a2.c

extern uint8_t i2c_dbg_rd[128];
extern uint8_t i2c_dbg_wr[128];
extern uint8_t i2c_dbg_rdp;
extern uint8_t i2c_dbg_wrp;

static void gpio_init(void);
static uint8_t Check_CC_BASE_and_CC_EXT(const uint8_t *A0Low_ptr);
static uint8_t Check_CC_DMI(const uint8_t *A2Low_ptr);
static uint8_t Check_Cfg_data_CSum(const A2Up_Page_t *A2UpPtr);
static void Check_timer_interval(void);
static void Check_register_action(void);
static void i2c_check(void);
static void Init_variables(void);
static void periph_init(void);
static void read_in_pins(void);

//-----------------------------------------------------------------------------
// main() Routine
// ----------------------------------------------------------------------------
// Note: the software watchdog timer is not disabled by default in this
// example, so a long-running program will reset periodically unless
// the timer is disabled or your program periodically writes to it.
//
// Review the "Watchdog Timer" section under the part family's datasheet
// for details. To find the datasheet, select your part in the
// Simplicity Launcher and click on "Data Sheet".
//-----------------------------------------------------------------------------
int main (void) {
  SystemCoreClockUpdate();
  retarget_init();
  
  printf(
    "Hello from K1921VK035.\n\r"
    "Compilation time: " __TIME__ "\n\r"
    "Core Frequency %u Hz\n\r", SystemCoreClock);
  //while (1);
  
  periph_init();

  Init_variables();
    
//  i2c_check(); /** TODO: Remove after testing */
//  
//  printf("\n\rCOMPLETE\n\r");

  while(1) {
    if (Time_flags & TIME_1SEC_FLAG) {
      Time_flags &= ~TIME_1SEC_FLAG;
			printf("R: | ");
      for (int r = 0; r < i2c_dbg_rdp; r += 2) {
        printf("a:0x%02X v:0x%02X |", i2c_dbg_rd[r], i2c_dbg_rd[r + 1]);
      }
			printf("\n\rW: | ");
      for (int w = 0; w < i2c_dbg_wrp; w += 2) {
        printf("a:0x%02X v:0x%02X |", i2c_dbg_wr[w], i2c_dbg_wr[w + 1]);
      }
			printf("\n\r");
    }
  }

  Init_MALD_37645();
  Init_MATA_37644();

  while (1) {
    //Check timer intervals
    Check_timer_interval();

    Check_register_action();
  }
}

static void gpio_init(){
  RCU->HCLKCFG_bit.GPIOAEN = 1;
  RCU->HRSTCFG_bit.GPIOAEN = 1;
  RCU->HCLKCFG_bit.GPIOBEN = 1;
  RCU->HRSTCFG_bit.GPIOBEN = 1;
  
  // Pin LED (A8) OUT
  #define GPIO_LED GPIOA
  #define PIN_LED PIN8
  
  GPIO_LED->DENSET_bit.PIN_LED  = 0x1; // OUT enable [page 210]
  GPIO_LED->OUTENSET_bit.PIN_LED = 0x1; // [page 51], [page 9]
  
  // Pin TX_DISABLE (A7) IN
  #define GPIO_TX_DISABLE GPIOA
  #define TX_DISABLE_PIN PIN7
  #define TX_DISABLE ((GPIO_TX_DISABLE->DATA_bit.VAL & (1 << 7)) >> 7)
  
  GPIO_TX_DISABLE->INMODE_bit.TX_DISABLE_PIN = 0x1; // [page 51], [page 9]
  
  // Pin TX_FAULT (A6) IN
  #define GPIO_TX_FAULT GPIOA
  #define TX_FAULT_PIN PIN6
  #define TX_FAULT ((GPIO_TX_FAULT->DATA_bit.VAL & (1 << 6)) >> 6)
  
  GPIO_TX_FAULT->INMODE_bit.TX_FAULT_PIN = 0x1; // [page 51], [page 9]
  
  // Pin LOS (A13) IN
  #define GPIO_LOS GPIOA
  #define LOS_PIN PIN13
  #define LOS ((GPIO_LOS->DATA_bit.VAL & (1 << 13)) >> 13)
  
  GPIO_LOS->INMODE_bit.LOS_PIN = 0x1; // [page 51], [page 9]
  
  // Pin RS0 (A12) IN
  #define GPIO_RS0 GPIOA
  #define RS0_PIN PIN12
  #define RS0 ((GPIO_RS0->DATA_bit.VAL & (1 << 12)) >> 12)
  
  GPIO_RS0->INMODE_bit.RS0_PIN = 0x1; // [page 51], [page 9]
  
  // Pin RS1 (A14) IN
  #define GPIO_RS1 GPIOA
  #define RS1_PIN PIN14
  #define RS1_EN GPIOAEN
  #define RS1 ((GPIO_RS1->DATA_bit.VAL & (1 << 14)) >> 14)
  
  GPIO_RS1->INMODE_bit.RS1_PIN = 0x1; // [page 51], [page 9]
  
  // Pin M_RS0 (A10) OUT
  #define GPIO_M_RS0 GPIOA
  #define M_RS0_PIN PIN10
  #define M_RS0 GPIO_M_RS0->DATAOUTCLR_bit.M_RS0_PIN
  
  GPIO_M_RS0->DENSET_bit.M_RS0_PIN  = 0x1; // push pull [page 212]
  GPIO_M_RS0->OUTENSET_bit.M_RS0_PIN = 0x1; // [page 51], [page 9]
  
  // Pin M_RS1 (A11) OUT
  #define GPIO_M_RS1 GPIOA
  #define M_RS1_PIN PIN11
  #define M_RS1 GPIO_M_RS1->DATAOUTCLR_bit.M_RS1_PIN
  
  GPIO_M_RS1->DENSET_bit.M_RS1_PIN  = 0x1; // push pull [page 212]
  GPIO_M_RS1->OUTENSET_bit.M_RS1_PIN = 0x1; // [page 51], [page 9]
}

static uint8_t Check_CC_BASE_and_CC_EXT(const uint8_t *A0Low_ptr) {
  uint8_t result = 0;  //default result is OK

  //Check CC_BASE
  uint16_t Temp_u16 = 0;
  for(uint16_t i = CC_BASE_START; i < CC_BASE_POS; i++) {
    Temp_u16 += A0Low_ptr[i];
  }
  if(A0Low_ptr[CC_BASE_POS] != (Temp_u16 & 0xFF))
    result += 1;

  //Check CC_BASE
  Temp_u16 = 0;
  for(uint16_t i = CC_EXT_START; i < CC_EXT_POS; i++) {
    Temp_u16 += A0Low_ptr[i];
  }
  if(A0Low_ptr[CC_EXT_POS] != (Temp_u16 & 0xFF))
    result += 2;

  return(result);
}

static uint8_t Check_CC_DMI(const uint8_t *A2Low_ptr) {
  uint8_t result = 0;  //default result is OK

  //Check CC_DMI
  uint16_t Temp_u16 = 0;
  for(uint16_t i = CC_DMI_START; i < CC_DMI_POS; i++) {
    Temp_u16 += A2Low_ptr[i];
  }
  if(A2Low_ptr[CC_DMI_POS] != (Temp_u16 & 0xFF))
    result = 1;

  return(result);
}

static uint8_t Check_Cfg_data_CSum(const A2Up_Page_t *A2UpPtr) {
  uint8_t result = 0;  //default result is OK

  //Check CC_BASE
  uint16_t Temp_u16 = 0;
  for(uint16_t i = 0; i < sizeof(MATA_cfg_t) + sizeof(MALD_cfg_t); i++) {
    Temp_u16 += A2UpPtr->Bytes[i];
  }
  if(Temp_u16 != A2UpPtr->var.CSum)
    result = 1;    //Bad CSum

  return(result);
}

void Check_timer_interval() {
  if(Time_flags & TIME_100MS_FLAG) { // 100 ms
    Time_flags &= ~TIME_100MS_FLAG;

    read_in_pins();
    
    Work_with_MATA_ADC();
    Work_with_MALD_ADC();
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
    GPIO_LED->DATAOUTTGL_bit.PIN_LED = 1; // [page 51]
  }
}

static void Check_register_action(void) {
  static uint8_t Temp_page_data[128];
  
  if(A2Up_Page.var.GrpCommand != 0) {
    //printf("grp com: %d\n\r", A2Up_Page.var.GrpCommand);
    //There is active group command
    A2Up_Page.var.GrpCmdResult = 0xFF;
    if(A2Up_Page.var.GrpCommand == GRP_CMD_MASC_DATA_RD) {
      //Group command to read data from MASC chip (max 15 bytes)
      if(A2Up_Page.var.GrpSize > SMB_IN_BUF_SIZE)
        A2Up_Page.var.GrpSize = SMB_IN_BUF_SIZE;
      if(int_I2C_read(A2Up_Page.var.GrpAddress, A2Up_Page.var.GrpBuffer, A2Up_Page.var.GrpSize) == 0)
        A2Up_Page.var.GrpCmdResult = GRP_CMD_RESULT_OK;  //success
      else
        A2Up_Page.var.GrpCmdResult = GRP_CMD_RESULT_ERR;  //error
    }
    else if(A2Up_Page.var.GrpCommand == GRP_CMD_MASC_DATA_WR) {
      //Group command to write data to MASC chip (max 16 bytes)
      if(A2Up_Page.var.GrpSize > SMB_OUT_BUF_SIZE)
        A2Up_Page.var.GrpSize = SMB_OUT_BUF_SIZE;
      if(int_I2C_write(A2Up_Page.var.GrpAddress, A2Up_Page.var.GrpBuffer, A2Up_Page.var.GrpSize) == 0)
        A2Up_Page.var.GrpCmdResult = GRP_CMD_RESULT_OK;  //success
      else
        A2Up_Page.var.GrpCmdResult = GRP_CMD_RESULT_ERR;  //error
    }
    else if(A2Up_Page.var.GrpCommand == GRP_CMD_WRITE_1ST_QUARTER) {
      //Group command to write 1st quarter (32 bytes) of page data
      memcpy(Temp_page_data, A2Up_Page.var.GrpBuffer, 32);
    }
    else if(A2Up_Page.var.GrpCommand == GRP_CMD_WRITE_2ND_QUARTER) {
      //Group command to write 2nd quarter (32 bytes) of page data
      memcpy(&Temp_page_data[32], A2Up_Page.var.GrpBuffer, 32);
    }
    else if(A2Up_Page.var.GrpCommand == GRP_CMD_WRITE_3RD_QUARTER) {
      //Group command to write 3rd quarter (32 bytes) of page data
      memcpy(&Temp_page_data[64], A2Up_Page.var.GrpBuffer, 32);
    }
    else if(A2Up_Page.var.GrpCommand == GRP_CMD_WR_4TH_Q_AND_UPDATE) {
      //Group command to write 4th quarter (32 bytes) of page data and update flash page
      memcpy(&Temp_page_data[96], A2Up_Page.var.GrpBuffer, 32);
      uint16_t Temp_u16 = 0;
      for(uint8_t i = 0; i < 128; i++) {
        Temp_u16 += Temp_page_data[i];
      }
      if(Temp_u16 == ((A2Up_Page.var.GrpBuf_CRC[0] << 8) | A2Up_Page.var.GrpBuf_CRC[1])) {
        //Correct CRC -> check page number (UpPage05.var.GrpAddress)
        A2Up_Page.var.GrpCmdResult = GRP_CMD_RESULT_OK;
        if(A2Up_Page.var.GrpAddress == FLASH_UPD_A0_LOW) {
          //Update A0 Low Page -> Check CC_BASE and CC_EXT
          uint8_t Temp_u8 = Check_CC_BASE_and_CC_EXT(Temp_page_data);
          if(Temp_u8 == 0) {
            //Correct values for CC_BASE and CC_EXT
            //Copy data to A0 Low Page in RAM
            memcpy(&A0_Page.Bytes[0], Temp_page_data, 128);
            //Update A0 Low page in Flash
            a0a2_pages_commit_to_flash();
          } else
            A2Up_Page.var.GrpCmdResult = GRP_CMD_RESULT_CC_BASE_FAIL + Temp_u8 - 1;
        } else if(A2Up_Page.var.GrpAddress == FLASH_UPD_A2_LOW) {
          //Update A2 Low Page -> Check CC_DMI
          uint8_t Temp_u8 = Check_CC_DMI(Temp_page_data);
          if(Temp_u8 == 0) {
            //Correct values for CC_DMI
            //Copy data to A2 Low Page in RAM
            memcpy(&A2_Page.Bytes[0], Temp_page_data, 128);
            //Update A2 Low page in Flash
            a0a2_pages_commit_to_flash();
          } else
            A2Up_Page.var.GrpCmdResult = GRP_CMD_RESULT_CC_DMI_FAIL;
        } else if(A2Up_Page.var.GrpAddress == FLASH_UPD_A2_HI) {
          //Update A2 Up Page -> Check config CRC
          if(Check_Cfg_data_CSum((A2Up_Page_t *)&Temp_page_data) == 0) {
            //Copy only config structure to A2Up page in RAM
            memcpy((uint8_t *)&A2Up_Page, Temp_page_data, (sizeof(MATA_cfg_t) + sizeof(MALD_cfg_t) + 2));  //copy data with CSum
            memcpy(&A0_Page.Bytes[0], Temp_page_data, 128);
            //Update A0 Low page in Flash
            a0a2_pages_commit_to_flash();
          } else
            A2Up_Page.var.GrpCmdResult = GRP_CMD_RESULT_CFG_CRC_FAIL;
        }
      }
      else
        A2Up_Page.var.GrpCmdResult = GRP_CMD_RESULT_CRC_FAIL;
    }
//    else if(UpPage07.var.GrpCommand == GRP_CMD_Tx_CALIBR_UPDATE) {
//      //Group command to update values of calibration coefs in RAM
//      memcpy(&UpPage04.var.TxPwr_calibration, &UpPage07.var.GrpBuffer[0], 8);  //copy Tx Pwr calibration
//    }
//    else if(UpPage07.var.GrpCommand == GRP_CMD_Rx_CALIBR_UPDATE) {
//      //Group command to update values of calibration coefs in RAM
//      memcpy(&UpPage04.var.RxPwr_calibration, &UpPage07.var.GrpBuffer[0], 8);  //copy Rx Pwr calibration
//    }

    A2Up_Page.var.GrpCommand = 0;  //Command is handled -> Clear it
  }
}

static void i2c_check(void) {  
#ifdef CHECK_INT_I2C
  const uint8_t SLAVE_ADDR = 0x51;
  // uint8_t tx_data[2] = {0x00, 0xAB};
  const uint8_t tx_data1[] = {123, 0xA3, 0x25, 0xA0, 0x6F};
  const uint8_t tx_data2[] = {127, 0x80};
  const uint8_t tx_data3[] = {208, 0x01, 0x02, 0x03, 0x55};
  const uint8_t tx_data4[] = {208};
  uint8_t rx_data4[4];
  
  uint8_t tx_databuf[33] = {0};
  tx_databuf[0] = 224;
  tx_databuf[6] = 1;
  uint8_t tx_com1_buf[] = {218, 0x03};
  uint8_t tx_com2_buf[] = {218, 0x04};
  uint8_t tx_com3_buf[] = {218, 0x05};
  uint8_t tx_com31_buf[] = {219, 0x01}; // a0 low
  uint8_t tx_com32_buf[] = {222, 0x00, 0x04}; // crc
  uint8_t tx_com4_buf[] = {218, 0x06};
  
  uint8_t res_addr = 221;
  uint8_t res_data = 0;
  

  uint8_t rx_data[2];
  memset(rx_data, 0, sizeof(rx_data));
  
  printf("i2c_check: run test\n\r");
  volatile int i = 0;

  /* Write example */
  if (int_I2C_write(SLAVE_ADDR, tx_data1, sizeof(tx_data1)) != 0) {
    /* error handling */
    printf("i2c_write_buffer1 failed\n\r");
    GPIO_LED->DATAOUTSET_bit.PIN_LED = 1; // [page 51];
    while (1)
      ;
  }
  int_I2C_write(SLAVE_ADDR, tx_data2, sizeof(tx_data2));
  int_I2C_write(SLAVE_ADDR, tx_data3, sizeof(tx_data3));
  
  //int_I2C_write(SLAVE_ADDR, tx_data4, 1);
  //int_I2C_read(SLAVE_ADDR, rx_data4, sizeof(rx_data4));
  int_I2C_request(SLAVE_ADDR, tx_data4, 1, rx_data4, sizeof(rx_data4));
  
  printf("data from slave:\n\r");
  for (uint32_t i = 0; i < sizeof(rx_data4); ++i) {
    printf("0x%02X ", rx_data4[i]);
  }

  printf("\n\r");
  
  for (int i = 0; i < 4; i++) {
    printf("0x%02X ", A2_Page.var.PassEntry[i]);
  }
  printf("| 0x%02X | ", A2_Page.var.TableSelect);
  for (int i = 0; i < 8; i++) {
    printf("0x%02X ", A2Up_Page.var.Reserved206[i]);
  }
  printf("\n\r");
  
  int_I2C_write(SLAVE_ADDR, tx_databuf, sizeof(tx_databuf));
  Check_register_action();
  int_I2C_write(SLAVE_ADDR, tx_com1_buf, sizeof(tx_com1_buf));
  Check_register_action();
  int_I2C_write(SLAVE_ADDR, tx_com2_buf, sizeof(tx_com2_buf));
  Check_register_action();
  int_I2C_write(SLAVE_ADDR, tx_com3_buf, sizeof(tx_com3_buf));
  Check_register_action();
  int_I2C_write(SLAVE_ADDR, tx_com31_buf, sizeof(tx_com31_buf));
  Check_register_action();
  int_I2C_write(SLAVE_ADDR, tx_com32_buf, sizeof(tx_com32_buf));
  Check_register_action();
  int_I2C_write(SLAVE_ADDR, tx_com4_buf, sizeof(tx_com4_buf));
  Check_register_action();
  
  printf("Request result\n\r");
  
  int_I2C_request(SLAVE_ADDR,&res_addr, 1, &res_data, 1);
  
  printf("result: %d\n\r", res_data);
  for (uint32_t i = 0; i < 128; ++i) {
    printf("%02X ", A0_Page.Bytes[i]);
  }
  printf("\n\r");

  printf("i2c_check success\n\r");
#endif // CHECK_INT_I2C
}

static void Init_variables(void) {
  memset(&A0_Page, 0, 128);
  memset(&A2_Page, 0, 128);
  memset(&A2Up_Page, 0, 128);

  a0a2_pages_init_from_flash();
  
//  printf("A0:\n\r");
//  for (uint32_t i = 0; i < 128; ++i) {
//    printf("%02X ", A0_Page.Bytes[i]);
//  }
//  printf("\n\r");
}

static void periph_init() {
  gpio_init();

  tick_init(SystemCoreClock); // periodic timers
  
  soft_I2C_init();
}

static void read_in_pins() {
  if(TX_DISABLE) {
    A2_Page.var.Stat_Control |= ST_TX_DISABLE_STATE_FLAG;
  } else {
    A2_Page.var.Stat_Control &= ~ST_TX_DISABLE_STATE_FLAG;
  }
  //Check Tx Fault pin
  if(TX_FAULT) {
    A2_Page.var.Stat_Control |= ST_TX_FAULT_STATE_FLAG;
  } else {
    A2_Page.var.Stat_Control &= ~ST_TX_FAULT_STATE_FLAG;
  }
  //Check Rx LOS pin
  if(LOS) {
    A2_Page.var.Stat_Control |= ST_RX_LOS_STATE_FLAG;
  } else {
    A2_Page.var.Stat_Control &= ~ST_RX_LOS_STATE_FLAG;
  }
  //Check RS0 pin and translate signal to M_RS0
  if(RS0) {
    A2_Page.var.Stat_Control |= ST_RS0_STATE_FLAG;
    M_RS0 = 1;
  } else {
    A2_Page.var.Stat_Control &= ~ST_RS0_STATE_FLAG;
    M_RS0 = 0;
  }
  //Check RS1 pin and translate signal to M_RS1
  if(RS1) {
    A2_Page.var.Stat_Control |= ST_RS1_STATE_FLAG;
    M_RS1 = 1;
  } else {
    A2_Page.var.Stat_Control &= ~ST_RS1_STATE_FLAG;
    M_RS1 = 0;
  }
}

#ifdef __cplusplus
}
#endif // __cplusplus
