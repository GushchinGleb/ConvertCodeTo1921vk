#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "../inc/MALD_37645.h"

#include <stdbool.h>
#include <stdio.h>

#include "../inc/i2c_master.h"
#include "../inc/pages.h"

extern A2Up_Page_t A2Up_Page; // from eeprom_a0a2.c

const MALD_37645_cfg_struct_t MALD_37645_default_config;// = { };
//  .RESET_REG = 0 };

//==============================================================================
// Init Tx (MALD-37645)
//==============================================================================
void Init_MALD_37645(void) {
  uint8_t rv; // reg value
  // Read CHIP_ID of UX2291 and compare to constant
  if(read_register_from_MALD(MALD_RA_CHIPID, &rv)) {
    //Check default values of register
    if(rv == MALD_CHIPID) {
      A2Up_Page.var.MALD_status_flags |= ST_MALD_37644_TYPE_FLAG;
    }
    else {
      A2Up_Page.var.MALD_status_flags |= ST_MALD_BAD_ID_FLAG;
    }
  }
  else {
    A2Up_Page.var.MALD_status_flags |= ST_MALD_I2C_RW_ERR_FLAG;
  }
  
  //Soft Reset of MALD
  if(!write_register_to_MALD(MALD_RA_RESET, 0xAA)) {
    A2Up_Page.var.MALD_status_flags |= ST_MALD_I2C_RW_ERR_FLAG;
  }

  //TEST
  // Read CHIP_ID of UX2291 and compare to constant
  if(read_register_from_MALD(MALD_RA_CHANNEL_MODE, &rv)) {
    //Check default values of register
    if(rv != 0x40) { // 0x40 - cdr_rate_select is default value [MALD-37645_V3.pdf page 24]
      A2Up_Page.var.MALD_status_flags |= ST_MALD_BAD_DEF_VAL_FLAG;
    }
  }
  else {
    A2Up_Page.var.MALD_status_flags |= ST_MALD_I2C_RW_ERR_FLAG;
  }
  if(read_register_from_MALD(MALD_RA_ADC_CONFIG0, &rv)) {
    //Check default values of register
    if(rv == 0x12) { // 0x10 is default value [MALD-37645_V3.pdf page 24]
    }
  }
  else {
    A2Up_Page.var.MALD_status_flags |= ST_MALD_I2C_RW_ERR_FLAG;
  }
  //TEST

  //Init common part
  rv = A2Up_Page.var.MALD_cfg.MALD_cfg.IO_CTRL;
  if(!write_register_to_MALD(MALD_RA_IO_CTRL, rv)) {
      A2Up_Page.var.MALD_status_flags |= ST_MALD_I2C_RW_ERR_FLAG;
  }

  rv = A2Up_Page.var.MALD_cfg.MALD_cfg.CDRCTRL;
  if(!write_register_to_MALD(MALD_RA_CDRCTRL, rv)) {
      A2Up_Page.var.MALD_status_flags |= ST_MALD_I2C_RW_ERR_FLAG;
  }

  rv = A2Up_Page.var.MALD_cfg.MALD_cfg.I2C_ADDRESS_MODE;
  if(!write_register_to_MALD(MALD_RA_I2C_ADDRESS_MODE, rv)) {
      A2Up_Page.var.MALD_status_flags |= ST_MALD_I2C_RW_ERR_FLAG;
  }

  rv = A2Up_Page.var.MALD_cfg.MALD_cfg.CHANNEL_MODE;
  if(!write_register_to_MALD(MALD_RA_CHANNEL_MODE, rv)) {
      A2Up_Page.var.MALD_status_flags |= ST_MALD_I2C_RW_ERR_FLAG;
  }

  rv = A2Up_Page.var.MALD_cfg.MALD_cfg.LOCKPHASE;
  if(!write_register_to_MALD(MALD_RA_LOCKPHASE, rv)) {
      A2Up_Page.var.MALD_status_flags |= ST_MALD_I2C_RW_ERR_FLAG;
  }

  rv = A2Up_Page.var.MALD_cfg.MALD_cfg.LOS_LOL_TX_ALARM;
  if(!write_register_to_MALD(MALD_RA_LOS_LOL_TX_ALARM, rv)) {
      A2Up_Page.var.MALD_status_flags |= ST_MALD_I2C_RW_ERR_FLAG;
  }

  rv = A2Up_Page.var.MALD_cfg.MALD_cfg.IGNORE_TX_FAULT;
  if(!write_register_to_MALD(MALD_RA_IGNORE_TX_FAULT, rv)) {
      A2Up_Page.var.MALD_status_flags |= ST_MALD_I2C_RW_ERR_FLAG;
  }

  rv = A2Up_Page.var.MALD_cfg.MALD_cfg.LOS_THRSH_AUTO_SQ;
  if(!write_register_to_MALD(MALD_RA_LOS_THRSH_AUTO_SQ, rv)) {
      A2Up_Page.var.MALD_status_flags |= ST_MALD_I2C_RW_ERR_FLAG;
  }

  rv = A2Up_Page.var.MALD_cfg.MALD_cfg.CTLE_X;
  if(!write_register_to_MALD(MALD_RA_CTLE_X, rv)) {
      A2Up_Page.var.MALD_status_flags |= ST_MALD_I2C_RW_ERR_FLAG;
  }

  rv = A2Up_Page.var.MALD_cfg.MALD_cfg.OUTPUT_MUTE_SLEW;
  if(!write_register_to_MALD(MALD_RA_OUTPUT_MUTE_SLEW, rv)) {
      A2Up_Page.var.MALD_status_flags |= ST_MALD_I2C_RW_ERR_FLAG;
  }

  rv = A2Up_Page.var.MALD_cfg.MALD_cfg.LBIAS;
  if(!write_register_to_MALD(MALD_RA_LBIAS, rv)) {
      A2Up_Page.var.MALD_status_flags |= ST_MALD_I2C_RW_ERR_FLAG;
  }

  rv = A2Up_Page.var.MALD_cfg.MALD_cfg.LMOD;
  if(!write_register_to_MALD(MALD_RA_LMOD, rv)) {
      A2Up_Page.var.MALD_status_flags |= ST_MALD_I2C_RW_ERR_FLAG;
  }

  rv = A2Up_Page.var.MALD_cfg.MALD_cfg.PREFALL;
  if(!write_register_to_MALD(MALD_RA_PREFALL, rv)) {
      A2Up_Page.var.MALD_status_flags |= ST_MALD_I2C_RW_ERR_FLAG;
  }

  rv = A2Up_Page.var.MALD_cfg.MALD_cfg.TDE;
  if(!write_register_to_MALD(MALD_RA_TDE, rv)) {
      A2Up_Page.var.MALD_status_flags |= ST_MALD_I2C_RW_ERR_FLAG;
  }

  rv = A2Up_Page.var.MALD_cfg.MALD_cfg.CROSSING_ADJ;
  if(!write_register_to_MALD(MALD_RA_CROSSING_ADJ, rv)) {
      A2Up_Page.var.MALD_status_flags |= ST_MALD_I2C_RW_ERR_FLAG;
  }

  rv = A2Up_Page.var.MALD_cfg.MALD_cfg.LBUMIN;
  if(!write_register_to_MALD(MALD_RA_LBUMIN, rv)) {
      A2Up_Page.var.MALD_status_flags |= ST_MALD_I2C_RW_ERR_FLAG;
  }

  rv = A2Up_Page.var.MALD_cfg.MALD_cfg.ADC_CONFIG0;
  if(!write_register_to_MALD(MALD_RA_ADC_CONFIG0, rv)) {
      A2Up_Page.var.MALD_status_flags |= ST_MALD_I2C_RW_ERR_FLAG;
  }

  rv = A2Up_Page.var.MALD_cfg.MALD_cfg.ADC_CONFIG2;
  if(!write_register_to_MALD(MALD_RA_ADC_CONFIG2, rv)) {
      A2Up_Page.var.MALD_status_flags |= ST_MALD_I2C_RW_ERR_FLAG;
  }

  rv = A2Up_Page.var.MALD_cfg.MALD_cfg.ADC_TX_SELECT;
  if(!write_register_to_MALD(MALD_RA_ADC_TX_SELECT, rv)) {
      A2Up_Page.var.MALD_status_flags |= ST_MALD_I2C_RW_ERR_FLAG;
  }
}
//================================================================================

//==============================================================================
// Create default config for MASC-37029
//==============================================================================
void Init_MADL_Default_Cfg(void) {
  A2Up_Page.var.MALD_cfg.MALD_cfg.IO_CTRL           = 0x00;
  A2Up_Page.var.MALD_cfg.MALD_cfg.CDRCTRL           = 0x00;
  A2Up_Page.var.MALD_cfg.MALD_cfg.I2C_ADDRESS_MODE  = 0x00;
  A2Up_Page.var.MALD_cfg.MALD_cfg.CHANNEL_MODE      = 0x40;
  A2Up_Page.var.MALD_cfg.MALD_cfg.LOCKPHASE         = 0x00;

  A2Up_Page.var.MALD_cfg.MALD_cfg.LOS_LOL_TX_ALARM  = 0x00;
  A2Up_Page.var.MALD_cfg.MALD_cfg.IGNORE_TX_FAULT   = 0x0E;
  A2Up_Page.var.MALD_cfg.MALD_cfg.LOS_THRSH_AUTO_SQ = 0x01;
  A2Up_Page.var.MALD_cfg.MALD_cfg.CTLE_X            = 0x06;
  A2Up_Page.var.MALD_cfg.MALD_cfg.OUTPUT_MUTE_SLEW  = 0x02;
  A2Up_Page.var.MALD_cfg.MALD_cfg.LBIAS             = 0x00;
  A2Up_Page.var.MALD_cfg.MALD_cfg.LMOD              = 0x00;
  A2Up_Page.var.MALD_cfg.MALD_cfg.PREFALL           = 0x00;
  A2Up_Page.var.MALD_cfg.MALD_cfg.TDE               = 0x00;
  A2Up_Page.var.MALD_cfg.MALD_cfg.CROSSING_ADJ      = 0x10;
  A2Up_Page.var.MALD_cfg.MALD_cfg.LBUMIN            = 0x00;

  A2Up_Page.var.MALD_cfg.MALD_cfg.ADC_CONFIG0       = 0x00;
  A2Up_Page.var.MALD_cfg.MALD_cfg.ADC_CONFIG2       = 0x00;

  A2Up_Page.var.MALD_cfg.MALD_cfg.ADC_TX_SELECT     = 0x00;

  A2Up_Page.var.MALD_cfg.Global_TX_En = 0;    //Disable Tx by default
  A2Up_Page.var.MALD_cfg.TxPwr_calibration = 256;

  A2Up_Page.var.CSum = 0x0000;
}

/**
 * @brief Update config to MASC chip
 */
void UpdateCfg_MASC(void) {
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

/*
 * Work with ADC of MASC-37029 chip
 */
void Work_with_MALD_ADC(void) {
  uint8_t ADC_rvs[2]; // registers values
  read_register_from_MALD(MALD_RA_ADC_OUT0_LSBS, &ADC_rvs[0]); // bits: [ 3:0]
  read_register_from_MALD(MALD_RA_ADC_OUT0_MSBS, &ADC_rvs[1]); // bits: [11:4]
  uint16_t ADC_value = ((ADC_rvs[1] << 4) | (ADC_rvs[0] & 0xF));
  read_register_from_MALD(MALD_RA_ADC_CONFIG0, &A2Up_Page.var.MALD_cfg.MALD_cfg.ADC_CONFIG0);
  
  uint8_t config = (A2Up_Page.var.MALD_cfg.MALD_cfg.ADC_CONFIG0 & 0x0F) << 4;
  if (A2Up_Page.var.MALD_cfg.MALD_cfg.ADC_CONFIG0 == 0x0) {
    read_register_from_MALD(MALD_RA_ADC_TX_SELECT, &A2Up_Page.var.MALD_cfg.MALD_cfg.ADC_TX_SELECT);
    config |= A2Up_Page.var.MALD_cfg.MALD_cfg.ADC_TX_SELECT & 0x0F;
  }
  
  switch(config) {
  case 0x00: // VCC33
    A2Up_Page.var.MALD_ADC_V33 = ADC_value;
    config = 0x01;
    break;
  case 0x02: // IBIAS reference
    A2Up_Page.var.MALD_ADC_IBIAS_ref = ADC_value;
    config = 0x03;
    break;
  case 0x03: // IBIAS measurement
    A2Up_Page.var.MALD_ADC_IBIAS_msrt = ADC_value;
    config = 0x10;
    break;
  case 0x10: // temperature
    A2Up_Page.var.MALD_ADC_Temp = ADC_value;
    config = 0x20;
    break;
  case 0x20: // IMON
    A2Up_Page.var.MALD_ADC_IMON = ADC_value;
  default:
    config = 0x00;
    break;
  }

  //Write to ADC control (start new conversion) ans save new stage
  A2Up_Page.var.MALD_cfg.MALD_cfg.ADC_CONFIG0 = config >> 4;
  write_register_to_MATA(MALD_RA_ADC_CONFIG0, A2Up_Page.var.MALD_cfg.MALD_cfg.ADC_CONFIG0);

  A2Up_Page.var.MALD_cfg.MALD_cfg.ADC_TX_SELECT = config & 0xF;
  write_register_to_MATA(MALD_RA_ADC_TX_SELECT, A2Up_Page.var.MALD_cfg.MALD_cfg.ADC_TX_SELECT);
}

// Read state of MASC chip
void Read_MALD_state(void)
{
  uint8_t state;
  //Read state (2 bytes - MASC_LOS_LOL_STATE and MASC_TXFAULT_STATE)
  if (read_register_from_MALD(MALD_RA_LOS_LOL_TX_FAULT, &state)) {
    A2Up_Page.var.MALD_TxFault_state = state;
  }
}

//Read 'Num' bytes from MASC-37029 beginning from 'RegAddr' to buffer
bool read_register_from_MALD(uint8_t addr, uint8_t *value)
{
  if (i2c_write_buffer(I2C0, MALD_CHIPID, &addr, sizeof(addr)) != I2C_DRV_OK) {
    return false;
  }
  
  return i2c_read_buffer(I2C0, MALD_CHIPID, value, sizeof(value)) == I2C_DRV_OK; //add additional byte because of last byte always read as 0xFF
}

//Write 'Num' bytes to MASC-37029 beginning from 'RegAddr' from buffer
bool write_register_to_MALD(uint8_t addr, uint8_t value) {
  static uint8_t send_buff[2];
  send_buff[0] = addr;
  send_buff[1] = value;

  return i2c_write_buffer(I2C0, MALD_CHIPID, send_buff, sizeof(send_buff)) == I2C_DRV_OK;
}

#ifdef __cplusplus
}
#endif // __cplusplus
