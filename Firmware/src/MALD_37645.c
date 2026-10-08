#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "../inc/MALD_37645.h"

#include <stdbool.h>
#include <stdio.h>

#include "../inc/soft_master_i2c.h"
#include "../inc/sfp28.h"

extern A2Up_Page_t A2Up_Page; // from eeprom_a0a2.c

//==============================================================================
// Init Tx (MALD-37645)
//==============================================================================
void Init_MALD_37645(void) {
  uint8_t rv; // reg value
   A2Up_Page.var.MALD_status_flags = 0x0;
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
  
  if (A2Up_Page.var.MALD_cfg.MALD_cfg.CHIPID != MALD_RDV_CHIPID) {
    return; // Page is invalid. Skip update.
  }
	
	update_MALD_config();
}
//================================================================================

/*
 * Work with ADC of MASC-37029 chip
 */
void Work_with_MALD_ADC(void) {
	if (!read_register_from_MALD(MALD_RA_ADC_CONFIG2, &A2Up_Page.var.MALD_cfg.MALD_cfg.ADC_CONFIG2)) {
		A2Up_Page.var.Reserved208[5] = 0xFF;
		return;
	}
	if (A2Up_Page.var.MALD_cfg.MALD_cfg.ADC_CONFIG2) {
		write_register_to_MALD(MALD_RA_ADC_CONFIG2, 0x0);
		return;
	}
	
  uint8_t ADC_rvs[2] = {0xFF, 0xFF}; // registers values
  read_register_from_MALD(MALD_RA_ADC_OUT0_MSBS, &ADC_rvs[1]); // bits: [11:4]
  read_register_from_MALD(MALD_RA_ADC_OUT0_LSBS, &ADC_rvs[0]); // bits: [ 3:0]
  uint16_t ADC_value = (((uint16_t)ADC_rvs[1] << 4) | (ADC_rvs[0] & 0xF));
  read_register_from_MALD(MALD_RA_ADC_CONFIG0, &A2Up_Page.var.MALD_cfg.MALD_cfg.ADC_CONFIG0);
  
  uint8_t config = (A2Up_Page.var.MALD_cfg.MALD_cfg.ADC_CONFIG0 & 0x0F) << 4;
  if (A2Up_Page.var.MALD_cfg.MALD_cfg.ADC_CONFIG0 == 0x0) {
    read_register_from_MALD(MALD_RA_ADC_TX_SELECT, &A2Up_Page.var.MALD_cfg.MALD_cfg.ADC_TX_SELECT);
    config |= A2Up_Page.var.MALD_cfg.MALD_cfg.ADC_TX_SELECT & 0x0F;
  }
  
  switch(config) {
  case 0x00: // VCC33
    A2Up_Page.var.MALD_ADC_V33 = ADC_value;
    config = 0x02;
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
  write_register_to_MALD(MALD_RA_ADC_CONFIG0, config >> 4);
  write_register_to_MALD(MALD_RA_ADC_TX_SELECT, config & 0xF);
}

// Read state of MALD chip
void Read_MALD_state(void) {
  uint8_t state;
  //Read state (2 bytes - MASC_LOS_LOL_STATE and MASC_TXFAULT_STATE)
  if (read_register_from_MALD(MALD_RA_LOS_LOL_TX_FAULT, &state)) {
    A2Up_Page.var.MALD_TxFault_state = state;
    A2Up_Page.var.MALD_status_flags &= ~ST_MALD_I2C_RW_ERR_FLAG;
  }
  else {
    A2Up_Page.var.MALD_status_flags |= ST_MALD_I2C_RW_ERR_FLAG;
  }

  // Read only registers
  read_register_from_MALD(MALD_RA_CHIPID, &A2Up_Page.var.MALD_cfg.MALD_cfg.CHIPID);
  read_register_from_MALD(MALD_RA_REVID, &A2Up_Page.var.MALD_cfg.MALD_cfg.REVID);
  read_register_from_MALD(MALD_RA_LOS_LOL_TX_FAULT, &A2Up_Page.var.MALD_cfg.MALD_cfg.LOS_LOL_TX_FAULT);
  read_register_from_MALD(MALD_RA_BUMIN_ENABLE, &A2Up_Page.var.MALD_cfg.MALD_cfg.BUMIN_ENABLE);

  // ADC registers
  read_register_from_MALD(MALD_RA_ADC_CONFIG0, &A2Up_Page.var.MALD_cfg.MALD_cfg.ADC_CONFIG0);
  read_register_from_MALD(MALD_RA_ADC_CONFIG2, &A2Up_Page.var.MALD_cfg.MALD_cfg.ADC_CONFIG2);
  read_register_from_MALD(MALD_RA_ADC_OUT0_MSBS, &A2Up_Page.var.MALD_cfg.MALD_cfg.ADC_OUT0_MSBS);
  read_register_from_MALD(MALD_RA_ADC_OUT0_LSBS, &A2Up_Page.var.MALD_cfg.MALD_cfg.ADC_OUT0_LSBS);
  read_register_from_MALD(MALD_RA_ADC_TX_SELECT, &A2Up_Page.var.MALD_cfg.MALD_cfg.ADC_TX_SELECT);
}

//Read 'Num' bytes from MASC-37029 beginning from 'RegAddr' to buffer
bool read_register_from_MALD(uint8_t addr, uint8_t *value) {
  uint8_t rx_data = 0x0;
	if(Read_soft_i2c(MALD_CHIPID, addr, &rx_data, 1) != 0) {
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
  
	if(Write_soft_i2c(MALD_CHIPID, send_buff, 2) !=0 ) {
		//Set flag of error
    return false;
	}
	return true;
}

void update_MALD_config(void) {
  MALD_37645_cfg_struct_t* MALD_cfg = &A2Up_Page.var.MALD_cfg.MALD_cfg;

//write_register_to_MALD(MALD_RA_CHIPID           , MALD_cfg->CHIPID           ); // read only
//write_register_to_MALD(MALD_RA_REVID            , MALD_cfg->REVID            ); // read only
  write_register_to_MALD(MALD_RA_RESET            , MALD_cfg->RESET            );
  write_register_to_MALD(MALD_RA_IO_CTRL          , MALD_cfg->IO_CTRL          );
  write_register_to_MALD(MALD_RA_CDRCTRL          , MALD_cfg->CDRCTRL          );
  write_register_to_MALD(MALD_RA_I2C_ADDRESS_MODE , MALD_cfg->I2C_ADDRESS_MODE );
  write_register_to_MALD(MALD_RA_CHANNEL_MODE     , MALD_cfg->CHANNEL_MODE     );
  write_register_to_MALD(MALD_RA_LOCKPHASE        , MALD_cfg->LOCKPHASE        );
//write_register_to_MALD(MALD_RA_LOS_LOL_TX_FAULT , MALD_cfg->LOS_LOL_TX_FAULT ); // read only
  write_register_to_MALD(MALD_RA_LOS_LOL_TX_ALARM , MALD_cfg->LOS_LOL_TX_ALARM );
  write_register_to_MALD(MALD_RA_IGNORE_TX_FAULT  , MALD_cfg->IGNORE_TX_FAULT  );
  write_register_to_MALD(MALD_RA_LOS_THRSH_AUTO_SQ, MALD_cfg->LOS_THRSH_AUTO_SQ);
  write_register_to_MALD(MALD_RA_CTLE_X           , MALD_cfg->CTLE_X           );
  write_register_to_MALD(MALD_RA_OUTPUT_MUTE_SLEW , MALD_cfg->OUTPUT_MUTE_SLEW );
  write_register_to_MALD(MALD_RA_LBIAS            , MALD_cfg->LBIAS            );
  write_register_to_MALD(MALD_RA_LMOD             , MALD_cfg->LMOD             );
  write_register_to_MALD(MALD_RA_PREFALL          , MALD_cfg->PREFALL          );
  write_register_to_MALD(MALD_RA_TDE              , MALD_cfg->TDE              );
  write_register_to_MALD(MALD_RA_CROSSING_ADJ     , MALD_cfg->CROSSING_ADJ     );
  write_register_to_MALD(MALD_RA_LBUMIN           , MALD_cfg->LBUMIN           );
//write_register_to_MALD(MALD_RA_BUMIN_ENABLE     , MALD_cfg->BUMIN_ENABLE     ); // read only
//write_register_to_MALD(MALD_RA_ADC_CONFIG0      , MALD_cfg->ADC_CONFIG0      ); // controled by Work_with_MALD_ADC
//write_register_to_MALD(MALD_RA_ADC_CONFIG2      , MALD_cfg->ADC_CONFIG2      ); // controled by Work_with_MALD_ADC
//write_register_to_MALD(MALD_RA_ADC_OUT0_MSBS    , MALD_cfg->ADC_OUT0_MSBS    ); // controled by Work_with_MALD_ADC
//write_register_to_MALD(MALD_RA_ADC_OUT0_LSBS    , MALD_cfg->ADC_OUT0_LSBS    ); // controled by Work_with_MALD_ADC
//write_register_to_MALD(MALD_RA_ADC_TX_SELECT    , MALD_cfg->ADC_TX_SELECT    ); // controled by Work_with_MALD_ADC
}

void cmd_write_MALD_config(void) {
  const int size = A2Up_Page.var.GrpSize;
  if (size < MALD_REGS_COUNT) {
    A2Up_Page.var.GrpCmdResult = GRP_CMD_RESULT_ERR;
    return;
  }

  const uint8_t* buff = A2Up_Page.var.GrpBuffer;
	
	memcpy(&A2Up_Page.var.MALD_cfg.MALD_cfg, buff, MALD_REGS_COUNT);
  
  A2Up_Page.var.GrpCmdResult = GRP_CMD_RESULT_OK;
}

#ifdef __cplusplus
}
#endif // __cplusplus
