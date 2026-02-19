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

// #define CHECK_INT_I2C // perform internal I2C check
// #define CHECK_COM_I2C // perform external I2C check (disable main logic)

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
static void Init_variables(void);
static void periph_init(void);
static void read_in_pins(void);

#ifdef CHECK_INT_I2C
static void i2c_check(void);
#endif // CHECK_INT_I2C

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
    
#ifdef CHECK_INT_I2C
  i2c_check(); /** TODO: Remove after testing */  
  printf("\n\rCOMPLETE\n\r");
#endif // CHECK_INT_I2C

#ifdef CHECK_COM_I2C
  while(1) {
    if (Time_flags & TIME_1SEC_FLAG) {
      Time_flags &= ~TIME_1SEC_FLAG;
      printf("R:\n\r");
      for (int r = 0; r < i2c_dbg_rdp; r += 3) {
        printf("addr:0x%02X reg:0x%02X val:0x%02X |\n\r", i2c_dbg_rd[r], i2c_dbg_rd[r + 1], i2c_dbg_rd[r + 2]);
      }
      printf("\n\rW:\n\r");
      for (int w = 0; w < i2c_dbg_wrp; w += 3) {
        printf("addr:0x%02X reg:0x%02X val:0x%02X |\n\r", i2c_dbg_wr[w], i2c_dbg_wr[w + 1], i2c_dbg_wr[w + 2]);
      }
      printf("\n\r");
    }
  }
#endif // CHECK_COM_I2C

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

static uint8_t Temp_page_data[128];

static void cmd_read_data_from_internal_chips(void);
static void cmd_write_data_to_internal_chips(void);
static void cmd_write_data_to_flash_pages(void);

static void Check_register_action(void) {
  if(A2Up_Page.var.GrpCommand == 0) {
    return; // Nothing to do.
  }

  //There is active group command
  A2Up_Page.var.GrpCmdResult = 0xFF;

  switch (A2Up_Page.var.GrpCommand) {
  case GRP_CMD_MASC_DATA_RD:
    cmd_read_data_from_internal_chips();
    break;
  case GRP_CMD_MASC_DATA_WR:
    cmd_write_data_to_internal_chips();
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
    cmd_write_data_to_flash_pages();
    break;
	default:
		printf("Unrecognized command: 0x%02X (%hhu)\n\r", A2Up_Page.var.GrpCommand, A2Up_Page.var.GrpCommand);
    break;
  }

  A2Up_Page.var.GrpCommand = 0;  //Command is handled -> Clear it
}

static void cmd_read_data_from_internal_chips(void) {
  //Group command to read data from MASC chip (max 15 bytes)
  if(A2Up_Page.var.GrpSize > SMB_IN_BUF_SIZE)
    A2Up_Page.var.GrpSize = SMB_IN_BUF_SIZE;
  if(int_I2C_read(A2Up_Page.var.GrpAddress, A2Up_Page.var.GrpBuffer, A2Up_Page.var.GrpSize) == 0)
    A2Up_Page.var.GrpCmdResult = GRP_CMD_RESULT_OK;  //success
  else
    A2Up_Page.var.GrpCmdResult = GRP_CMD_RESULT_ERR;  //error
}

static void cmd_write_data_to_internal_chips(void) {
    //Group command to write data to MASC chip (max 16 bytes)
    if(A2Up_Page.var.GrpSize > SMB_OUT_BUF_SIZE)
      A2Up_Page.var.GrpSize = SMB_OUT_BUF_SIZE;
    if(int_I2C_write(A2Up_Page.var.GrpAddress, A2Up_Page.var.GrpBuffer, A2Up_Page.var.GrpSize) == 0)
      A2Up_Page.var.GrpCmdResult = GRP_CMD_RESULT_OK;  //success
    else
      A2Up_Page.var.GrpCmdResult = GRP_CMD_RESULT_ERR;  //error
}

static void cmd_write_data_to_flash_pages(void) {
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

#ifdef CHECK_INT_I2C
static void i2c_check(void) {  
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
}
#endif // CHECK_INT_I2C

static void Init_variables(void) {
  memset(&A0_Page, 0, 128);
  memset(&A2_Page, 0, 128);
  memset(&A2Up_Page, 0, 128);

  a0a2_pages_init_from_flash();

#ifdef CHECK_COM_I2C
  A0_Page.Bytes[  0] =   3; // ID
  A0_Page.Bytes[  1] =   4; // Ext ID
  A0_Page.Bytes[  2] =   7; // Connector
  A0_Page.Bytes[  3] =   0; // Transceiver
  A0_Page.Bytes[  4] =   0; // -
  A0_Page.Bytes[  5] =   0; // -
  A0_Page.Bytes[  6] =   0; // -
  A0_Page.Bytes[  7] =   0; // -
  A0_Page.Bytes[  8] =   0; // -
  A0_Page.Bytes[  9] =   0; // -
  A0_Page.Bytes[ 10] =   0; // Transceiver10
  A0_Page.Bytes[ 11] =   3; // Encoding
  A0_Page.Bytes[ 12] = 255; // SigRate_Nom
  A0_Page.Bytes[ 13] =   0; // Rate Id
  A0_Page.Bytes[ 14] =   0; // Length14
  A0_Page.Bytes[ 15] =   0; // Length15
  A0_Page.Bytes[ 16] =   0; // Length16
  A0_Page.Bytes[ 17] =   0; // Length17
  A0_Page.Bytes[ 18] =  10; // Length18
  A0_Page.Bytes[ 19] =   7; // Length19
  A0_Page.Bytes[ 20] =  87; // Vendor Name
  A0_Page.Bytes[ 21] =  84; // -
  A0_Page.Bytes[ 22] =  68; // -
  A0_Page.Bytes[ 23] =  32; // -
  A0_Page.Bytes[ 24] =  32; // -
  A0_Page.Bytes[ 25] =  32; // -
  A0_Page.Bytes[ 26] =  32; // -
  A0_Page.Bytes[ 27] =  32; // -
  A0_Page.Bytes[ 28] =  32; // -
  A0_Page.Bytes[ 29] =  32; // -
  A0_Page.Bytes[ 30] =  32; // -
  A0_Page.Bytes[ 31] =  32; // -
  A0_Page.Bytes[ 32] =  32; // -
  A0_Page.Bytes[ 33] =  32; // -
  A0_Page.Bytes[ 34] =  32; // -
  A0_Page.Bytes[ 35] =  32; // Vendor Name 35
  A0_Page.Bytes[ 36] =   2; // Transceiver
  A0_Page.Bytes[ 37] =   0; // Vendor OUI
  A0_Page.Bytes[ 38] =  28; // -
  A0_Page.Bytes[ 39] = 173; // -
  A0_Page.Bytes[ 40] =  82; // Vendor PN
  A0_Page.Bytes[ 41] =  84; // -
  A0_Page.Bytes[ 42] =  88; // -
  A0_Page.Bytes[ 43] =  77; // -
  A0_Page.Bytes[ 44] =  51; // -
  A0_Page.Bytes[ 45] =  51; // -
  A0_Page.Bytes[ 46] =  48; // -
  A0_Page.Bytes[ 47] =  45; // -
  A0_Page.Bytes[ 48] =  53; // -
  A0_Page.Bytes[ 49] =  53; // -
  A0_Page.Bytes[ 50] =  49; // -
  A0_Page.Bytes[ 51] =  32; // -
  A0_Page.Bytes[ 52] =  32; // -
  A0_Page.Bytes[ 53] =  32; // -
  A0_Page.Bytes[ 54] =  32; // -
  A0_Page.Bytes[ 55] =  32; // Vendor PN 55
  A0_Page.Bytes[ 56] =  49; // Vendor rev
  A0_Page.Bytes[ 57] =  46; // -
  A0_Page.Bytes[ 58] =  48; // -
  A0_Page.Bytes[ 59] =  32; // Vendor rev 59
  A0_Page.Bytes[ 60] =   3; // Wavelength 60
  A0_Page.Bytes[ 61] =  82; // Wavelength 61
  A0_Page.Bytes[ 62] =   0; // FC speed 2
  A0_Page.Bytes[ 63] = 200; // CC_BASE
  A0_Page.Bytes[ 64] =   8; // Options
  A0_Page.Bytes[ 65] =  26; // Options
  A0_Page.Bytes[ 66] = 103; // Sig Rate Max
  A0_Page.Bytes[ 67] =   0; // Sig Rate Min
  A0_Page.Bytes[ 68] =  72; // Vendor SN
  A0_Page.Bytes[ 69] =  66; // -
  A0_Page.Bytes[ 70] =  50; // -
  A0_Page.Bytes[ 71] =  50; // -
  A0_Page.Bytes[ 72] =  52; // -
  A0_Page.Bytes[ 73] =  48; // -
  A0_Page.Bytes[ 74] =  48; // -
  A0_Page.Bytes[ 75] =  48; // -
  A0_Page.Bytes[ 76] =  50; // -
  A0_Page.Bytes[ 77] =  49; // -
  A0_Page.Bytes[ 78] =  48; // -
  A0_Page.Bytes[ 79] =  53; // -
  A0_Page.Bytes[ 80] =  56; // -
  A0_Page.Bytes[ 81] =  48; // -
  A0_Page.Bytes[ 82] =  32; // -
  A0_Page.Bytes[ 83] =  32; // Vendor SN 83
  A0_Page.Bytes[ 84] =  50; // Date
  A0_Page.Bytes[ 85] =  50; // -
  A0_Page.Bytes[ 86] =  49; // -
  A0_Page.Bytes[ 87] =  48; // -
  A0_Page.Bytes[ 88] =  50; // -
  A0_Page.Bytes[ 89] =  54; // -
  A0_Page.Bytes[ 90] =  32; // -
  A0_Page.Bytes[ 91] =  32; // Date 91
  A0_Page.Bytes[ 92] = 104; // DM type
  A0_Page.Bytes[ 93] = 240; // Enh Options
  A0_Page.Bytes[ 94] =   8; // SFF Compl
  A0_Page.Bytes[ 95] = 120; // CC_EXT
  A0_Page.Bytes[ 96] =   0; // Vendor spec 96
  A0_Page.Bytes[ 97] =   0; // Vendor spec 97
  A0_Page.Bytes[ 98] =   0; // Vendor spec 98
  A0_Page.Bytes[ 99] =   0; // Vendor spec 99
  A0_Page.Bytes[100] =   0; // Vendor spec 100
  A0_Page.Bytes[101] =   0; // Vendor spec 101
  A0_Page.Bytes[102] =   0; // Vendor spec 102
  A0_Page.Bytes[103] =   0; // Vendor spec 103
  A0_Page.Bytes[104] =   0; // Vendor spec 104
  A0_Page.Bytes[105] =   0; // Vendor spec 105
  A0_Page.Bytes[106] =   0; // Vendor spec 106
  A0_Page.Bytes[107] =   0; // Vendor spec 107
  A0_Page.Bytes[108] =   0; // Vendor spec 108
  A0_Page.Bytes[109] =   0; // Vendor spec 109
  A0_Page.Bytes[110] =   0; // Vendor spec 110
  A0_Page.Bytes[111] =   0; // Vendor spec 111
  A0_Page.Bytes[112] =   0; // Vendor spec 112
  A0_Page.Bytes[113] =   0; // Vendor spec 113
  A0_Page.Bytes[114] =   0; // Vendor spec 114
  A0_Page.Bytes[115] =   0; // Vendor spec 115
  A0_Page.Bytes[116] =   0; // Vendor spec 116
  A0_Page.Bytes[117] =   0; // Vendor spec 117
  A0_Page.Bytes[118] =   0; // Vendor spec 118
  A0_Page.Bytes[119] =   0; // Vendor spec 119
  A0_Page.Bytes[120] =   0; // Vendor spec 120
  A0_Page.Bytes[121] =   0; // Vendor spec 121
  A0_Page.Bytes[122] =   0; // Vendor spec 122
  A0_Page.Bytes[123] =   0; // Vendor spec 123
  A0_Page.Bytes[124] =   0; // Vendor spec 124
  A0_Page.Bytes[125] =   0; // Vendor spec 125
  A0_Page.Bytes[126] =   0; // Vendor spec 126
  A0_Page.Bytes[127] =   0; // Vendor spec 127
  
  A2_Page.Bytes[128 - 128] = 247;  
  A2_Page.Bytes[129 - 128] = 200;  
  A2_Page.Bytes[130 - 128] = 253;  
  A2_Page.Bytes[131 - 128] = 234;  
  A2_Page.Bytes[132 - 128] =   2;  
  A2_Page.Bytes[133 - 128] = 231;  
  A2_Page.Bytes[134 - 128] = 192;  
  A2_Page.Bytes[135 - 128] =  15;  
  A2_Page.Bytes[136 - 128] = 176;  
  A2_Page.Bytes[137 - 128] = 191;  
  A2_Page.Bytes[138 - 128] =  64;  
  A2_Page.Bytes[139 - 128] =  10;  
  A2_Page.Bytes[140 - 128] = 186;  
  A2_Page.Bytes[141 - 128] = 128;  
  A2_Page.Bytes[142 - 128] =  71;  
  A2_Page.Bytes[143 - 128] =  78;  
  A2_Page.Bytes[144 - 128] = 255;  
  A2_Page.Bytes[145 - 128] =  72;  
  A2_Page.Bytes[146 - 128] = 222;  
  A2_Page.Bytes[147 - 128] = 255;  
  A2_Page.Bytes[148 - 128] = 161;  
  A2_Page.Bytes[149 - 128] = 119;  
  A2_Page.Bytes[150 - 128] =   2;  
  A2_Page.Bytes[151 - 128] = 142;  
  A2_Page.Bytes[152 - 128] =  30;  
  A2_Page.Bytes[153 - 128] = 236;  
  A2_Page.Bytes[154 - 128] =  77;  
  A2_Page.Bytes[155 - 128] =  40;  
  A2_Page.Bytes[156 - 128] = 177;  
  A2_Page.Bytes[157 - 128] =  19;  
  A2_Page.Bytes[158 - 128] = 255;  
  A2_Page.Bytes[159 - 128] =  52;  
  A2_Page.Bytes[160 - 128] =  73;  
  A2_Page.Bytes[161 - 128] =   0;  
  A2_Page.Bytes[162 - 128] = 207;  
  A2_Page.Bytes[163 - 128] = 123;  
  A2_Page.Bytes[164 - 128] =  32;  
  A2_Page.Bytes[165 - 128] = 246;  
  A2_Page.Bytes[166 - 128] =  82;  
  A2_Page.Bytes[167 - 128] = 241;  
  A2_Page.Bytes[168 - 128] =  32;  
  A2_Page.Bytes[169 - 128] = 251;  
  A2_Page.Bytes[170 - 128] =  68;  
  A2_Page.Bytes[171 - 128] =  71;  
  A2_Page.Bytes[172 - 128] = 203;  
  A2_Page.Bytes[173 - 128] =  35;  
  A2_Page.Bytes[174 - 128] = 118;  
  A2_Page.Bytes[175 - 128] =  64;  
  A2_Page.Bytes[176 - 128] = 152;  
  A2_Page.Bytes[177 - 128] = 160;  
  A2_Page.Bytes[178 - 128] = 255;  
  A2_Page.Bytes[179 - 128] = 111;  
  A2_Page.Bytes[180 - 128] = 199;  
  A2_Page.Bytes[181 - 128] = 212;  
  A2_Page.Bytes[182 - 128] = 132;  
  A2_Page.Bytes[183 - 128] = 215;  
  A2_Page.Bytes[184 - 128] = 109;  
  A2_Page.Bytes[185 - 128] = 255;  
  A2_Page.Bytes[186 - 128] =  65;  
  A2_Page.Bytes[187 - 128] =  24;  
  A2_Page.Bytes[188 - 128] = 191;  
  A2_Page.Bytes[189 - 128] =  16;  
  A2_Page.Bytes[190 - 128] = 249;  
  A2_Page.Bytes[191 - 128] = 128;  
  A2_Page.Bytes[192 - 128] = 247;  
  A2_Page.Bytes[193 - 128] = 200;  
  A2_Page.Bytes[194 - 128] = 253;  
  A2_Page.Bytes[195 - 128] = 234;  
  A2_Page.Bytes[196 - 128] =   2;  
  A2_Page.Bytes[197 - 128] = 231;  
  A2_Page.Bytes[198 - 128] = 192;  
  A2_Page.Bytes[199 - 128] =  15;  
  A2_Page.Bytes[200 - 128] = 176;  
  A2_Page.Bytes[201 - 128] = 191;  
  A2_Page.Bytes[202 - 128] =  64;  
  A2_Page.Bytes[203 - 128] =  10;  
  A2_Page.Bytes[204 - 128] = 186;  
  A2_Page.Bytes[205 - 128] = 128;  
  A2_Page.Bytes[206 - 128] =  71;  
  A2_Page.Bytes[207 - 128] =  78;  
  A2_Page.Bytes[208 - 128] = 255;  
  A2_Page.Bytes[209 - 128] =  72;  
  A2_Page.Bytes[210 - 128] = 222;  
  A2_Page.Bytes[211 - 128] = 255;  
  A2_Page.Bytes[212 - 128] = 161;  
  A2_Page.Bytes[213 - 128] = 119;  
  A2_Page.Bytes[214 - 128] =   2;  
  A2_Page.Bytes[215 - 128] = 142;  
  A2_Page.Bytes[216 - 128] =  30;  
  A2_Page.Bytes[217 - 128] = 236;  
  A2_Page.Bytes[218 - 128] =  77;  
  A2_Page.Bytes[219 - 128] =  40;  
  A2_Page.Bytes[220 - 128] = 177;  
  A2_Page.Bytes[221 - 128] =  19;  
  A2_Page.Bytes[222 - 128] = 255;  
  A2_Page.Bytes[223 - 128] =  52;  
  A2_Page.Bytes[224 - 128] =  73;  
  A2_Page.Bytes[225 - 128] =   0;  
  A2_Page.Bytes[226 - 128] = 207;  
  A2_Page.Bytes[227 - 128] = 123;  
  A2_Page.Bytes[228 - 128] =  32;  
  A2_Page.Bytes[229 - 128] = 246;  
  A2_Page.Bytes[230 - 128] =  82;  
  A2_Page.Bytes[231 - 128] = 241;  
  A2_Page.Bytes[232 - 128] =  32;  
  A2_Page.Bytes[233 - 128] = 251;  
  A2_Page.Bytes[234 - 128] =  68;  
  A2_Page.Bytes[235 - 128] =  71;  
  A2_Page.Bytes[236 - 128] = 203;  
  A2_Page.Bytes[237 - 128] =  35;  
  A2_Page.Bytes[238 - 128] = 118;  
  A2_Page.Bytes[239 - 128] =  64;  
  A2_Page.Bytes[240 - 128] = 152;  
  A2_Page.Bytes[241 - 128] = 160;  
  A2_Page.Bytes[242 - 128] = 255;  
  A2_Page.Bytes[243 - 128] = 111;  
  A2_Page.Bytes[244 - 128] = 199;  
  A2_Page.Bytes[245 - 128] = 212;  
  A2_Page.Bytes[246 - 128] = 132;  
  A2_Page.Bytes[247 - 128] = 215;  
  A2_Page.Bytes[248 - 128] = 109;  
  A2_Page.Bytes[249 - 128] = 255;  
  A2_Page.Bytes[250 - 128] =  65;  
  A2_Page.Bytes[251 - 128] =  24;  
  A2_Page.Bytes[252 - 128] = 191;  
  A2_Page.Bytes[253 - 128] =  16;  
  A2_Page.Bytes[254 - 128] = 249;  
  A2_Page.Bytes[255 - 128] = 128;  
  
  A2Up_Page.Bytes[128 - 128] =   0; // MATA CHIPID
  A2Up_Page.Bytes[129 - 128] =   0; // MATA REVID
  A2Up_Page.Bytes[130 - 128] =   0; // MATA RESET
  A2Up_Page.Bytes[131 - 128] =   0; // MONITORS
  A2Up_Page.Bytes[132 - 128] =   0; // CDRCTRL
  A2Up_Page.Bytes[133 - 128] =   0; // I2C_ADDRESS_MODE
  A2Up_Page.Bytes[134 - 128] =   0; // CHANNEL_MODE
  A2Up_Page.Bytes[135 - 128] =   0; // LOCKPHASE
  A2Up_Page.Bytes[136 - 128] =   0; // LOS_MODE
  A2Up_Page.Bytes[137 - 128] =   0; // LOS_LOL_STATUS
  A2Up_Page.Bytes[138 - 128] =   0; // LOS_LOL_ALARM
  A2Up_Page.Bytes[139 - 128] =   0; // LOS_CTRL
  A2Up_Page.Bytes[140 - 128] =   0; // SLA
  A2Up_Page.Bytes[141 - 128] =   0; // TIA_CTRL
  A2Up_Page.Bytes[142 - 128] =   0; // OUTPUT_CTRL
  A2Up_Page.Bytes[143 - 128] =   0; // OUTPUT_SWING
  A2Up_Page.Bytes[144 - 128] =  48; // OUTPUT_DEEMPH
  A2Up_Page.Bytes[145 - 128] =  50; // ADC_CONFIG0
  A2Up_Page.Bytes[146 - 128] =  51; // ADC_CONFIG2
  A2Up_Page.Bytes[147 - 128] =  49; // ADC_OUT0_MSBS
  A2Up_Page.Bytes[148 - 128] =  51; // ADC_OUT0_LSBS
  A2Up_Page.Bytes[149 - 128] =  66; // Global_TX_En
  A2Up_Page.Bytes[150 - 128] =  74; // TxPwr_calibration
  A2Up_Page.Bytes[151 - 128] =  75; // TxPwr_calibration
  A2Up_Page.Bytes[152 - 128] =   0; // MALD CHIPID
  A2Up_Page.Bytes[153 - 128] =   0; // MALD REVID
  A2Up_Page.Bytes[154 - 128] =   0; // MALD RESET
  A2Up_Page.Bytes[155 - 128] =   0; // IO_CTRL
  A2Up_Page.Bytes[156 - 128] =   0; // CDRCTRL
  A2Up_Page.Bytes[157 - 128] =   0; // I2C_ADDRESS_MODE
  A2Up_Page.Bytes[158 - 128] = 254; // CHANNEL_MODE
  A2Up_Page.Bytes[159 - 128] =  47; // LOCKPHASE
  A2Up_Page.Bytes[160 - 128] =   1; // LOS_LOL_TX_FAULT
  A2Up_Page.Bytes[161 - 128] =  64; // LOS_LOL_TX_ALARM
  A2Up_Page.Bytes[162 - 128] = 151; // IGNORE_TX_FAULT
  A2Up_Page.Bytes[163 - 128] = 137; // LOS_THRSH_AUTO_SQ
  A2Up_Page.Bytes[164 - 128] = 249; // CTLE_X
  A2Up_Page.Bytes[165 - 128] = 119; // OUTPUT_MUTE_SLEW
  A2Up_Page.Bytes[166 - 128] =  36; // LBIAS
  A2Up_Page.Bytes[167 - 128] =  49; // LMOD
  A2Up_Page.Bytes[168 - 128] = 242; // PREFALL
  A2Up_Page.Bytes[169 - 128] =  52; // TDE
  A2Up_Page.Bytes[170 - 128] = 189; // CROSSING_ADJ
  A2Up_Page.Bytes[171 - 128] = 128; // LBUMIN
  A2Up_Page.Bytes[172 - 128] =  48; // BUMIN_ENABLE
  A2Up_Page.Bytes[173 - 128] = 123; // ADC_CONFIG0
  A2Up_Page.Bytes[174 - 128] = 172; // ADC_CONFIG2
  A2Up_Page.Bytes[175 - 128] = 127; // ADC_OUT0_MSBS
  A2Up_Page.Bytes[176 - 128] = 222; // ADC_OUT0_LSBS
  A2Up_Page.Bytes[177 - 128] =   8; // ADC_TX_SELECT
  A2Up_Page.Bytes[178 - 128] = 156; // reserved
  A2Up_Page.Bytes[179 - 128] =  84; // Global_TX_En
  A2Up_Page.Bytes[180 - 128] =  82; // TxPwr_calibration
  A2Up_Page.Bytes[181 - 128] = 222; // TxPwr_calibration
  A2Up_Page.Bytes[182 - 128] = 190; // CSum
  A2Up_Page.Bytes[183 - 128] = 130; // CSum
  A2Up_Page.Bytes[184 - 128] = 150; // SW_ID
  A2Up_Page.Bytes[185 - 128] = 227; // SW_Version0
  A2Up_Page.Bytes[186 - 128] = 178; // SW_Version1
  A2Up_Page.Bytes[187 - 128] =  61; // MATA_status_flags
  A2Up_Page.Bytes[188 - 128] =   9; // MALD_status_flags
  A2Up_Page.Bytes[189 - 128] = 191; // MATA_LOS_LOL_state
  A2Up_Page.Bytes[190 - 128] = 170; // MALD_TxFault_state
  A2Up_Page.Bytes[191 - 128] = 182; // Reserved_state
  A2Up_Page.Bytes[192 - 128] = 206; // MATA_ADC_V33
  A2Up_Page.Bytes[193 - 128] =  52; // MATA_ADC_V33
  A2Up_Page.Bytes[194 - 128] = 225; // MATA_ADC_Temp
  A2Up_Page.Bytes[195 - 128] =  75; // MATA_ADC_Temp
  A2Up_Page.Bytes[196 - 128] =  49; // MATA_ADC_RSSI
  A2Up_Page.Bytes[197 - 128] =  75; // MATA_ADC_RSSI
  A2Up_Page.Bytes[198 - 128] =  50; // MALD_ADC_V33
  A2Up_Page.Bytes[199 - 128] =  39; // MALD_ADC_V33
  A2Up_Page.Bytes[200 - 128] = 102; // MALD_ADC_Temp
  A2Up_Page.Bytes[201 - 128] = 251; // MALD_ADC_Temp
  A2Up_Page.Bytes[202 - 128] = 117; // MALD_ADC_Temp
  A2Up_Page.Bytes[203 - 128] = 221; // MALD_ADC_Temp
  A2Up_Page.Bytes[204 - 128] = 221; // MALD_ADC_IBIAS_msrt
  A2Up_Page.Bytes[205 - 128] = 131; // MALD_ADC_IBIAS_msrt
  A2Up_Page.Bytes[206 - 128] = 146; // MALD_ADC_IMON
  A2Up_Page.Bytes[207 - 128] =  98; // MALD_ADC_IMON
  A2Up_Page.Bytes[208 - 128] = 216; // Reserved0
  A2Up_Page.Bytes[209 - 128] =  44; // Reserved1
  A2Up_Page.Bytes[210 - 128] = 207; // Reserved2
  A2Up_Page.Bytes[211 - 128] = 145; // Reserved3
  A2Up_Page.Bytes[212 - 128] =  36; // Reserved4
  A2Up_Page.Bytes[213 - 128] = 237; // Reserved5
  A2Up_Page.Bytes[214 - 128] = 115; // Reserved6
  A2Up_Page.Bytes[215 - 128] = 244; // Reserved7
  A2Up_Page.Bytes[216 - 128] =  99; // Reserved8
  A2Up_Page.Bytes[217 - 128] = 107; // Reserved9
  A2Up_Page.Bytes[218 - 128] = 241; // GrpCommand
  A2Up_Page.Bytes[219 - 128] = 234; // GrpAddress
  A2Up_Page.Bytes[220 - 128] =  65; // GrpSize
  A2Up_Page.Bytes[221 - 128] = 238; // GrpCmdResult
  A2Up_Page.Bytes[222 - 128] =  59; // GrpBuf_CRC_0
  A2Up_Page.Bytes[223 - 128] = 133; // GrpBuf_CRC_1
  A2Up_Page.Bytes[224 - 128] = 143; // GrpBuffer0
  A2Up_Page.Bytes[225 - 128] = 250; // GrpBuffer1
  A2Up_Page.Bytes[226 - 128] =   0; // GrpBuffer2
  A2Up_Page.Bytes[227 - 128] =   0; // GrpBuffer3
  A2Up_Page.Bytes[228 - 128] =   0; // GrpBuffer4
  A2Up_Page.Bytes[229 - 128] =   0; // GrpBuffer5
  A2Up_Page.Bytes[230 - 128] =   0; // GrpBuffer6
  A2Up_Page.Bytes[231 - 128] =   0; // GrpBuffer7
  A2Up_Page.Bytes[232 - 128] =   0; // GrpBuffer8
  A2Up_Page.Bytes[233 - 128] =   0; // GrpBuffer9
  A2Up_Page.Bytes[234 - 128] =   0; // GrpBuffer10
  A2Up_Page.Bytes[235 - 128] =   0; // GrpBuffer11
  A2Up_Page.Bytes[236 - 128] =   0; // GrpBuffer12
  A2Up_Page.Bytes[237 - 128] =   0; // GrpBuffer13
  A2Up_Page.Bytes[238 - 128] =   0; // GrpBuffer14
  A2Up_Page.Bytes[239 - 128] =   0; // GrpBuffer15
  A2Up_Page.Bytes[240 - 128] =   0; // GrpBuffer16
  A2Up_Page.Bytes[241 - 128] =   0; // GrpBuffer17
  A2Up_Page.Bytes[242 - 128] =   0; // GrpBuffer18
  A2Up_Page.Bytes[243 - 128] =   0; // GrpBuffer19
  A2Up_Page.Bytes[244 - 128] =   0; // GrpBuffer20
  A2Up_Page.Bytes[245 - 128] =   0; // GrpBuffer21
  A2Up_Page.Bytes[246 - 128] =   0; // GrpBuffer22
  A2Up_Page.Bytes[247 - 128] =   0; // GrpBuffer23
  A2Up_Page.Bytes[248 - 128] =   0; // GrpBuffer24
  A2Up_Page.Bytes[249 - 128] =   0; // GrpBuffer25
  A2Up_Page.Bytes[250 - 128] =   0; // GrpBuffer26
  A2Up_Page.Bytes[251 - 128] =   0; // GrpBuffer27
  A2Up_Page.Bytes[252 - 128] =   0; // GrpBuffer28
  A2Up_Page.Bytes[253 - 128] =   0; // GrpBuffer29
  A2Up_Page.Bytes[254 - 128] =   0; // GrpBuffer30
  A2Up_Page.Bytes[255 - 128] =   0; // GrpBuffer31
#endif // CHECK_COM_I2C
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
