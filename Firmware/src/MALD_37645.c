#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "../inc/MALD_37645.h"

#include <stdbool.h>
#include <stdio.h>

#include "../inc/soft_i2c.h"
#include "../inc/pages.h"

extern A2Up_Page_t A2Up_Page; // from eeprom_a0a2.c

const MALD_37645_cfg_struct_t MALD_37645_default_config;// = { };
//  .RESET_REG = 0 };

//==============================================================================
// Init Tx (MALD-37645)
//==============================================================================
void Init_MALD_37645(void) {
  A2Up_Page.var.MALD_status_flags = 0x0; // clear MATA flags
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
    return; // error on the first writer, so srop the initialisation
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

/*
 * Work with ADC of MASC-37029 chip
 */
void Work_with_MALD_ADC(void) {
  if (A2Up_Page.var.MALD_status_flags & ST_MALD_I2C_RW_ERR_FLAG) {
    A2Up_Page.var.MALD_ADC_V33 = 0xFFFF;
    A2Up_Page.var.MALD_ADC_IBIAS_ref = 0xFFFF;
    A2Up_Page.var.MALD_ADC_IBIAS_msrt = 0xFFFF;
    A2Up_Page.var.MALD_ADC_Temp = 0xFFFF;
    A2Up_Page.var.MALD_ADC_IMON = 0xFFFF;
    return; // return invalid state
  }
    
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
  if (A2Up_Page.var.MALD_status_flags & ST_MALD_I2C_RW_ERR_FLAG) {
    A2Up_Page.var.MALD_TxFault_state = 0xFF;
    return; // invalid status
  }
  uint8_t state;
  //Read state (2 bytes - MASC_LOS_LOL_STATE and MASC_TXFAULT_STATE)
  if (read_register_from_MALD(MALD_RA_LOS_LOL_TX_FAULT, &state)) {
    A2Up_Page.var.MALD_TxFault_state = state;
  }
}

//Read 'Num' bytes from MASC-37029 beginning from 'RegAddr' to buffer
bool read_register_from_MALD(uint8_t addr, uint8_t *value) {
  uint8_t rx_data = 0x0;
  if (int_I2C_write(MALD_CHIPID, &addr, 1) != 0) {
    return false;
  }
  if (int_I2C_read(MALD_CHIPID, &rx_data, 1) != 0) {
    return false;
  }

  *value = rx_data;
  return true;
}

//Write 'Num' bytes to MASC-37029 beginning from 'RegAddr' from buffer
bool write_register_to_MALD(uint8_t addr, uint8_t value) {
  static uint8_t send_buff[2];
  send_buff[0] = addr;
  send_buff[1] = value;
  
  return int_I2C_write(MALD_CHIPID, send_buff, sizeof(send_buff)) == 0;
}

#ifdef __cplusplus
}
#endif // __cplusplus
