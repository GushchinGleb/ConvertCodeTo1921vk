#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

//=========================================================

#include <stdbool.h>
#include <stdio.h>

#include "../inc/MATA_37644.h"
#include "../inc/soft_i2c.h"
#include "../inc/pages.h"

extern A2Up_Page_t A2Up_Page; // from eeprom_a0a2.c

const MATA_37644_cfg_struct_t MATA_37644_default_config;// = { };
//  .RESET_REG = 0 };

//==============================================================================
// Init Rx (MATA-37644)
//==============================================================================
void Init_MATA_37644(void) {
  A2Up_Page.var.MATA_status_flags = 0x0; // clear MATA flags
  uint8_t rv; // reg value
  // Read CHIP_ID of UX2291 and compare to constant
  if(read_register_from_MATA(MATA_RA_CHIPID, &rv)) {
    //Check default values of register
    if(rv == MATA_CHIPID) {
      A2Up_Page.var.MATA_status_flags |= ST_MATA_37645_TYPE_FLAG;
    }
    else {
      A2Up_Page.var.MATA_status_flags |= ST_MATA_BAD_ID_FLAG;
    }
  }
  else {
    A2Up_Page.var.MATA_status_flags |= ST_MATA_I2C_RW_ERR_FLAG;
    return; // error on the first writer, so srop the initialisation
  }
  
  //Soft Reset of MATA
  if(!write_register_to_MATA(MATA_RA_RESET, 0xAA)) {
    A2Up_Page.var.MATA_status_flags |= ST_MATA_I2C_RW_ERR_FLAG;
  }

  //TEST
  // Read CHIP_ID of UX2291 and compare to constant
  if(read_register_from_MATA(MATA_RA_CHANNEL_MODE, &rv)) {
    //Check default values of register
    if(rv != 0x40) { // 0x40 - cdr_rate_select is default value [MATA-37644_V3.pdf page 22]
      A2Up_Page.var.MATA_status_flags |= ST_MATA_BAD_DEF_VAL_FLAG;
    }
  }
  else {
    A2Up_Page.var.MATA_status_flags |= ST_MATA_I2C_RW_ERR_FLAG;
  }
  if(read_register_from_MATA(MATA_RA_ADC_CONFIG0, &rv)) {
    //Check default values of register
    if(rv == 0x12) { // 0x12 is default value [MATA-37644_V3.pdf page 22]
    }
  }
  else {
    A2Up_Page.var.MATA_status_flags |= ST_MATA_I2C_RW_ERR_FLAG;
  }
  //TEST

  rv = A2Up_Page.var.MATA_cfg.MATA_cfg.CHANNEL_MODE;
  if(!write_register_to_MATA(MATA_RA_CHANNEL_MODE, rv)) {
    A2Up_Page.var.MATA_status_flags |= ST_MATA_I2C_RW_ERR_FLAG;
  }

  // MONITORS
  rv = A2Up_Page.var.MATA_cfg.MATA_cfg.MONITORS;
  if(!write_register_to_MATA(MATA_RA_MONITORS, rv)) {
      A2Up_Page.var.MATA_status_flags |= ST_MATA_I2C_RW_ERR_FLAG;
  }

  rv = A2Up_Page.var.MATA_cfg.MATA_cfg.CDRCTRL;
  if(!write_register_to_MATA(MATA_RA_CDRCTRL, rv)) {
      A2Up_Page.var.MATA_status_flags |= ST_MATA_I2C_RW_ERR_FLAG;
  }

  rv = A2Up_Page.var.MATA_cfg.MATA_cfg.I2C_ADDRESS_MODE;
  if(!write_register_to_MATA(MATA_RA_I2C_ADDRESS_MODE, rv)) {
      A2Up_Page.var.MATA_status_flags |= ST_MATA_I2C_RW_ERR_FLAG;
  }

  rv = A2Up_Page.var.MATA_cfg.MATA_cfg.CHANNEL_MODE;
  if(!write_register_to_MATA(MATA_RA_CHANNEL_MODE, rv)) {
      A2Up_Page.var.MATA_status_flags |= ST_MATA_I2C_RW_ERR_FLAG;
  }

  rv = A2Up_Page.var.MATA_cfg.MATA_cfg.LOCKPHASE;
  if(!write_register_to_MATA(MATA_RA_LOCKPHASE, rv)) {
      A2Up_Page.var.MATA_status_flags |= ST_MATA_I2C_RW_ERR_FLAG;
  }

  rv = A2Up_Page.var.MATA_cfg.MATA_cfg.LOS_MODE;
  if(!write_register_to_MATA(MATA_RA_LOS_MODE, rv)) {
      A2Up_Page.var.MATA_status_flags |= ST_MATA_I2C_RW_ERR_FLAG;
  }

  rv = A2Up_Page.var.MATA_cfg.MATA_cfg.LOS_LOL_ALARM;
  if(!write_register_to_MATA(MATA_RA_LOS_LOL_ALARM, rv)) {
      A2Up_Page.var.MATA_status_flags |= ST_MATA_I2C_RW_ERR_FLAG;
  }

  rv = A2Up_Page.var.MATA_cfg.MATA_cfg.LOS_CTRL;
  if(!write_register_to_MATA(MATA_RA_LOS_CTRL, rv)) {
      A2Up_Page.var.MATA_status_flags |= ST_MATA_I2C_RW_ERR_FLAG;
  }

  rv = A2Up_Page.var.MATA_cfg.MATA_cfg.SLA;
  if(!write_register_to_MATA(MATA_RA_SLA, rv)) {
      A2Up_Page.var.MATA_status_flags |= ST_MATA_I2C_RW_ERR_FLAG;
  }

  rv = A2Up_Page.var.MATA_cfg.MATA_cfg.TIA_CTRL;
  if(!write_register_to_MATA(MATA_RA_TIA_CTRL, rv)) {
      A2Up_Page.var.MATA_status_flags |= ST_MATA_I2C_RW_ERR_FLAG;
  }

  rv = A2Up_Page.var.MATA_cfg.MATA_cfg.OUTPUT_CTRL;
  if(!write_register_to_MATA(MATA_RA_OUTPUT_CTRL, rv)) {
      A2Up_Page.var.MATA_status_flags |= ST_MATA_I2C_RW_ERR_FLAG;
  }

  rv = A2Up_Page.var.MATA_cfg.MATA_cfg.OUTPUT_SWING;
  if(!write_register_to_MATA(MATA_RA_OUTPUT_SWING, rv)) {
      A2Up_Page.var.MATA_status_flags |= ST_MATA_I2C_RW_ERR_FLAG;
  }

  rv = A2Up_Page.var.MATA_cfg.MATA_cfg.OUTPUT_DEEMPH;
  if(!write_register_to_MATA(MATA_RA_OUTPUT_DEEMPH, rv)) {
      A2Up_Page.var.MATA_status_flags |= ST_MATA_I2C_RW_ERR_FLAG;
  }

  rv = A2Up_Page.var.MATA_cfg.MATA_cfg.ADC_CONFIG0;
  if(!write_register_to_MATA(MATA_RA_ADC_CONFIG0, rv)) {
      A2Up_Page.var.MATA_status_flags |= ST_MATA_I2C_RW_ERR_FLAG;
  }

  rv = A2Up_Page.var.MATA_cfg.MATA_cfg.ADC_CONFIG2;
  if(!write_register_to_MATA(MATA_RA_ADC_CONFIG2, rv)) {
      A2Up_Page.var.MATA_status_flags |= ST_MATA_I2C_RW_ERR_FLAG;
  }
}

/**
 * @brief Create default config for MATA-37029
 */
void Init_MATA_Default_Cfg(void) { // [MATA-37644_V3.pdf page 22]
  A2Up_Page.var.MATA_cfg.MATA_cfg.MONITORS           = 0x00;
  A2Up_Page.var.MATA_cfg.MATA_cfg.CDRCTRL            = 0x00;
  A2Up_Page.var.MATA_cfg.MATA_cfg.I2C_ADDRESS_MODE   = 0x00;
  A2Up_Page.var.MATA_cfg.MATA_cfg.CHANNEL_MODE       = 0x40;
  A2Up_Page.var.MATA_cfg.MATA_cfg.LOCKPHASE          = 0x00;
  A2Up_Page.var.MATA_cfg.MATA_cfg.LOS_MODE           = 0x00;

  A2Up_Page.var.MATA_cfg.MATA_cfg.LOS_LOL_ALARM      = 0x00;
  A2Up_Page.var.MATA_cfg.MATA_cfg.LOS_CTRL           = 0x00;
  A2Up_Page.var.MATA_cfg.MATA_cfg.SLA                = 0x0F;
  A2Up_Page.var.MATA_cfg.MATA_cfg.TIA_CTRL           = 0x00;
  A2Up_Page.var.MATA_cfg.MATA_cfg.OUTPUT_CTRL        = 0x00;
  A2Up_Page.var.MATA_cfg.MATA_cfg.OUTPUT_SWING       = 0x32;
  A2Up_Page.var.MATA_cfg.MATA_cfg.OUTPUT_DEEMPH      = 0x00;
  A2Up_Page.var.MATA_cfg.MATA_cfg.ADC_CONFIG0        = 0x12;
  A2Up_Page.var.MATA_cfg.MATA_cfg.ADC_CONFIG2        = 0x00;

  A2Up_Page.var.MATA_cfg.Global_TX_En = 0;    //Disable Tx by default
  A2Up_Page.var.MATA_cfg.TxPwr_calibration = 256;

  A2Up_Page.var.CSum = 0x0000;
}

/**
 * @brief Update config to MATA chip
 */
void UpdateCfg_MATA(void)
{

  //Write config to chip
//  Temp_buffer[0] = 0x00;      //RegAddr is 1st byte of data
//  memcpy(&Temp_buffer[1], &TempBuf_128.u8[0], 64);
//  if(Write_soft_i2c(I2C_UX2291_ADDR, Temp_buffer, 65) !=0 ) {
//    //Set flag of error
//    UpPage05.var.Tx_UX_status_flags |= ST_TXRX_CFG_INIT_ERR_FLAG;
//  }
//  //Write 2nd part of config (up to UX2291_TX_SYS_CTRL) (101-64 = 37 bytes)
//  Temp_buffer[0] = 0x40;      //RegAddr is 1st byte of data
//  memcpy(&Temp_buffer[1], &TempBuf_128.u8[64], 37);
//  if(Write_soft_i2c(I2C_UX2291_ADDR, Temp_buffer, 38) !=0 ) {
//    //Set flag of error
//    UpPage05.var.Tx_UX_status_flags |= ST_TXRX_CFG_INIT_ERR_FLAG;
//  }
//
//  //Update value of UX2291_TX_SYS_CTRL (don't change AMUX_ADDR it is used for measurement)
//  Read_soft_i2c(I2C_UX2291_ADDR, UX2291_TX_SYS_CTRL, Temp_buffer, 1);
//  Temp_buffer[1] = Temp_buffer[0] & 0xF0;    //clear all bits except AMUX_ADDR
//  Temp_buffer[1] |= (UpPage04.var.TX_cfg.TX_SYS_CTRL & 0x0F);    //mask only config
//  Temp_buffer[0] = UX2291_TX_SYS_CTRL;      //RegAddr is 1st byte of data
//  Write_soft_i2c(I2C_UX2291_ADDR, Temp_buffer, 2);
}

// Work with ADC of MATA-37029 chip
void Work_with_MATA_ADC(void) {
  if (A2Up_Page.var.MATA_status_flags & ST_MATA_I2C_RW_ERR_FLAG) {
    A2Up_Page.var.MATA_ADC_V33 = 0xFFFF;
    A2Up_Page.var.MATA_ADC_Temp = 0xFFFF;
    A2Up_Page.var.MATA_ADC_RSSI = 0xFFFF;
    return; // return invalid state
  }
  uint8_t ADC_rvs[2]; // registers values
  read_register_from_MATA(MATA_RA_ADC_OUT0_LSBS, &ADC_rvs[0]); // bits: [ 3:0]
  read_register_from_MATA(MATA_RA_ADC_OUT0_MSBS, &ADC_rvs[1]); // bits: [11:4]
  uint16_t value = ((ADC_rvs[1] << 4) | (ADC_rvs[0] & 0xF));
  read_register_from_MATA(MATA_RA_ADC_CONFIG0, &A2Up_Page.var.MATA_cfg.MATA_cfg.ADC_CONFIG0);

  switch(A2Up_Page.var.MATA_cfg.MATA_cfg.ADC_CONFIG0) {
  case 0x0: // 000b -> V33
    A2Up_Page.var.MATA_ADC_V33 = value;
    break;
  case 0x1: // 001b -> TEMP
    A2Up_Page.var.MATA_ADC_Temp = value;
    break;
  case 0x2: // 010b -> RSSI
    A2Up_Page.var.MATA_ADC_RSSI = value;
    break;
  }
  
  // Increment ADC stage
  A2Up_Page.var.MATA_cfg.MATA_cfg.ADC_CONFIG0++;
  if (A2Up_Page.var.MATA_cfg.MATA_cfg.ADC_CONFIG0 > 2) {
    A2Up_Page.var.MATA_cfg.MATA_cfg.ADC_CONFIG0 = 0;
  }
  // Save new stage
  write_register_to_MATA(MATA_RA_ADC_CONFIG0, A2Up_Page.var.MATA_cfg.MATA_cfg.ADC_CONFIG0);
}

// Read state of MATA chip
void Read_MATA_state(void) {
  if (A2Up_Page.var.MATA_status_flags & ST_MATA_I2C_RW_ERR_FLAG) {
    A2Up_Page.var.MATA_LOS_LOL_state = 0xFF;
    return; // return invalid state
  }
  uint8_t status;
  read_register_from_MATA(MATA_RA_LOS_LOL_STATUS, &status); // [MATA-37644_V3.pdf page 27]
  A2Up_Page.var.MATA_LOS_LOL_state = status;
}

//Read 'Num' bytes from MATA-37029 beginning from 'RegAddr' to buffer
bool read_register_from_MATA(uint8_t addr, uint8_t *value) {
  uint8_t rx_data = 0x0;
  if (int_I2C_write(MATA_CHIPID, &addr, 1) != 0) {
    return false;
  }
  if (int_I2C_read(MATA_CHIPID, &rx_data, 1) != 0) {
    return false;
  }

  *value = rx_data;
  return true;
}

//Write 'Num' bytes to MATA-37029 beginning from 'RegAddr' from buffer
bool write_register_to_MATA(uint8_t addr, uint8_t value) {
  static uint8_t send_buff[2];
  send_buff[0] = addr;
  send_buff[1] = value;
  
  return int_I2C_write(MATA_CHIPID, send_buff, sizeof(send_buff)) == 0;
}

#ifdef __cplusplus
}
#endif // __cplusplus
