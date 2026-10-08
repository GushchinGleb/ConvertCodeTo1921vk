#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

//=========================================================

#include <stdbool.h>
#include <stdio.h>

#include "../inc/MATA_37644.h"
#include "../inc/soft_master_i2c.h"
#include "../inc/sfp28.h"

extern A2Up_Page_t A2Up_Page; // from eeprom_a0a2.c

const MATA_37644_cfg_struct_t MATA_37644_default_config;// = { };
//  .RESET_REG = 0 };

//==============================================================================
// Init Rx (MATA-37644)
//==============================================================================
void Init_MATA_37644(void) {
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
  
  //Init common part
  
  if (A2Up_Page.var.MATA_cfg.MATA_cfg.CHIPID != MATA_RDV_CHIPID) {
    return; // Page is invalid. Skip update.
  }

  update_MATA_config();
}

// Work with ADC of MATA-37029 chip
void Work_with_MATA_ADC(void) {
  uint8_t config2 = 0xFF;
  if (!read_register_from_MATA(MATA_RA_ADC_CONFIG2, &config2)) {
     return;
  }
  if (config2) {
     write_register_to_MATA(MATA_RA_ADC_CONFIG2, 0x0);
    return;
  }

  uint8_t ADC_rvs[2] = {0xFF, 0xFF}; // registers values
  
  read_register_from_MATA(MATA_RA_ADC_OUT0_MSBS, &ADC_rvs[1]); // bits: [11:4]
  read_register_from_MATA(MATA_RA_ADC_OUT0_LSBS, &ADC_rvs[0]); // bits: [ 3:0]
  uint16_t value = (((uint16_t)ADC_rvs[1] << 4) | (ADC_rvs[0] & 0xF));
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
  uint8_t status;
  if (read_register_from_MATA(MATA_RA_LOS_LOL_STATUS, &status)) { // [MATA-37644_V3.pdf page 27]
    A2Up_Page.var.MATA_LOS_LOL_state = status;
    A2Up_Page.var.MATA_status_flags &= ~ST_MATA_I2C_RW_ERR_FLAG;
  }
  else {
    A2Up_Page.var.MATA_status_flags |= ST_MATA_I2C_RW_ERR_FLAG;
  }
  
  // Read only registers
  write_register_to_MATA(MATA_RA_CHIPID, A2Up_Page.var.MATA_cfg.MATA_cfg.CHIPID);
  write_register_to_MATA(MATA_RA_REVID, A2Up_Page.var.MATA_cfg.MATA_cfg.REVID);
  write_register_to_MATA(MATA_RA_LOS_LOL_STATUS, A2Up_Page.var.MATA_cfg.MATA_cfg.LOS_LOL_STATUS);
  
  // ADC registers
  write_register_to_MATA(MATA_RA_ADC_CONFIG0, A2Up_Page.var.MATA_cfg.MATA_cfg.ADC_CONFIG0);
  write_register_to_MATA(MATA_RA_ADC_CONFIG2, A2Up_Page.var.MATA_cfg.MATA_cfg.ADC_CONFIG2);
  write_register_to_MATA(MATA_RA_ADC_OUT0_MSBS, A2Up_Page.var.MATA_cfg.MATA_cfg.ADC_OUT0_MSBS);
  write_register_to_MATA(MATA_RA_ADC_OUT0_LSBS, A2Up_Page.var.MATA_cfg.MATA_cfg.ADC_OUT0_LSBS);
}

//Read 'Num' bytes from MATA-37029 beginning from 'RegAddr' to buffer
bool read_register_from_MATA(uint8_t addr, uint8_t *value) {
  uint8_t rx_data = 0x0;
	if(Read_soft_i2c(MATA_CHIPID, addr, &rx_data, 1) != 0) {
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
  
	if(Write_soft_i2c(MATA_CHIPID, send_buff, 2) !=0 ) {
		//Set flag of error
    return false;
	}
	return true;
}

void update_MATA_config(void) {
  MATA_37644_cfg_struct_t* MATA_cfg = &A2Up_Page.var.MATA_cfg.MATA_cfg;

//write_register_to_MATA(MATA_RA_CHIPID          , MATA_cfg->CHIPID          ); // read only
//write_register_to_MATA(MATA_RA_REVID           , MATA_cfg->REVID           ); // read only
  write_register_to_MATA(MATA_RA_RESET           , MATA_cfg->RESET           );
  write_register_to_MATA(MATA_RA_MONITORS        , MATA_cfg->MONITORS        );
  write_register_to_MATA(MATA_RA_CDRCTRL         , MATA_cfg->CDRCTRL         );
  write_register_to_MATA(MATA_RA_I2C_ADDRESS_MODE, MATA_cfg->I2C_ADDRESS_MODE);
  write_register_to_MATA(MATA_RA_CHANNEL_MODE    , MATA_cfg->CHANNEL_MODE    );
  write_register_to_MATA(MATA_RA_LOCKPHASE       , MATA_cfg->LOCKPHASE       );
  write_register_to_MATA(MATA_RA_LOS_MODE        , MATA_cfg->LOS_MODE        );
//write_register_to_MATA(MATA_RA_LOS_LOL_STATUS  , MATA_cfg->LOS_LOL_STATUS  ); // read only
  write_register_to_MATA(MATA_RA_LOS_LOL_ALARM   , MATA_cfg->LOS_LOL_ALARM   );
  write_register_to_MATA(MATA_RA_LOS_CTRL        , MATA_cfg->LOS_CTRL        );
  write_register_to_MATA(MATA_RA_SLA             , MATA_cfg->SLA             );
  write_register_to_MATA(MATA_RA_TIA_CTRL        , MATA_cfg->TIA_CTRL        );
  write_register_to_MATA(MATA_RA_OUTPUT_CTRL     , MATA_cfg->OUTPUT_CTRL     );
  write_register_to_MATA(MATA_RA_OUTPUT_SWING    , MATA_cfg->OUTPUT_SWING    );
  write_register_to_MATA(MATA_RA_OUTPUT_DEEMPH   , MATA_cfg->OUTPUT_DEEMPH   );
//write_register_to_MATA(MATA_RA_ADC_CONFIG0     , MATA_cfg->ADC_CONFIG0     ); // controled by Work_with_MATA_ADC
//write_register_to_MATA(MATA_RA_ADC_CONFIG2     , MATA_cfg->ADC_CONFIG2     ); // controled by Work_with_MATA_ADC
//write_register_to_MATA(MATA_RA_ADC_OUT0_MSBS   , MATA_cfg->ADC_OUT0_MSBS   ); // controled by Work_with_MATA_ADC
//write_register_to_MATA(MATA_RA_ADC_OUT0_LSBS   , MATA_cfg->ADC_OUT0_LSBS   ); // controled by Work_with_MATA_ADC
}

void cmd_write_MATA_config(void) {
  const int size = A2Up_Page.var.GrpSize;
  if (size < MATA_REGS_COUNT) {
    A2Up_Page.var.GrpCmdResult = GRP_CMD_RESULT_ERR;
    return;
  }

  const uint8_t* buff = A2Up_Page.var.GrpBuffer;
	
	memcpy(&A2Up_Page.var.MATA_cfg.MATA_cfg, buff, MATA_REGS_COUNT);
  
  A2Up_Page.var.GrpCmdResult = GRP_CMD_RESULT_OK;
}

#ifdef __cplusplus
}
#endif // __cplusplus
