#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

//=========================================================
// USER INCLUDES

#include <stdio.h>
#include "../inc/i2c_master.h"
#include "../inc/MASC_37029_defs.h"
#include "../inc/sfp28.h"

uint8_t ADC_stage;

const MASC_37029_cfg_struct_t MASC_37029_default_config;// = { };
//	.RESET_REG = 0 };

//==============================================================================
// Init Tx and Rx driver (MASC-37029)
//==============================================================================
void Init_MASC_37029(void)
{
	uint8_t Temp_buffer[12];
	// Read CHIP_ID of UX2291 and compare to constant
	if(Read_bytes_from_MASC(MASC_CHIPID, 2, Temp_buffer)) {
		//Check default values of register
		if(Temp_buffer[0] == MASC_37029_CHIPID_VALUE) {
			A2Up_Page.var.MASC_status_flags |= ST_MASC_37029_TYPE_FLAG;
		}
		else if(Temp_buffer[0] == MASC_37028_CHIPID_VALUE) {
			A2Up_Page.var.MASC_status_flags |= ST_MASC_37028_TYPE_FLAG;
		}
		else {
			A2Up_Page.var.MASC_status_flags |= ST_MASC_BAD_ID_FLAG;
		}
	}
	else {
		A2Up_Page.var.MASC_status_flags |= ST_MASC_I2C_RW_ERR_FLAG;
	}

	//TEST
	// Read CHIP_ID of UX2291 and compare to constant
	if(Read_bytes_from_MASC(MASC_RX_MODES, 7, Temp_buffer)) {
		//Check default values of register
		if(Temp_buffer[0] == MASC_37029_CHIPID_VALUE) {
		}
	}
	else {
		A2Up_Page.var.MASC_status_flags |= ST_MASC_I2C_RW_ERR_FLAG;
	}
	if(Read_bytes_from_MASC(MASC_TX_MODES, 12, Temp_buffer)) {
		//Check default values of register
		if(Temp_buffer[0] == MASC_37029_CHIPID_VALUE) {
		}
	}
	else {
		A2Up_Page.var.MASC_status_flags |= ST_MASC_I2C_RW_ERR_FLAG;
	}
	if(Read_bytes_from_MASC(MASC_ADC_CFG0, 2, Temp_buffer)) {
		//Check default values of register
		if(Temp_buffer[0] == MASC_37029_CHIPID_VALUE) {
		}
	}
	else {
		A2Up_Page.var.MASC_status_flags |= ST_MASC_I2C_RW_ERR_FLAG;
	}
	//TEST

	//Soft Reset of MASC
	uint8_t byte = 0xAA;
	if(!Write_bytes_to_MASC(MASC_RESET_REG, sizeof(byte), &byte)) {
		A2Up_Page.var.MASC_status_flags |= ST_MASC_I2C_RW_ERR_FLAG;
	}

	//Init common part
	byte = A2Up_Page.var.SFP28_cfg.MASC_cfg.LB_MISCL;
	if(!Write_bytes_to_MASC(MASC_LB_MISCL, sizeof(byte), &byte)) {
		A2Up_Page.var.MASC_status_flags |= ST_MASC_I2C_RW_ERR_FLAG;
	}

	//Init Rx part
	memcpy(&Temp_buffer[0], &A2Up_Page.var.SFP28_cfg.MASC_cfg.RX_MODES, 7);
	if(!Write_bytes_to_MASC(MASC_RX_MODES, 7, Temp_buffer)) {
		A2Up_Page.var.MASC_status_flags |= ST_MASC_I2C_RW_ERR_FLAG;
	}

	//Init Tx part
	//20-22
	memcpy(&Temp_buffer[0], &A2Up_Page.var.SFP28_cfg.MASC_cfg.TX_MODES, 3);
	if(!Write_bytes_to_MASC(MASC_TX_MODES, 3, Temp_buffer)) {
		A2Up_Page.var.MASC_status_flags |= ST_MASC_I2C_RW_ERR_FLAG;
	}
	//24-2B
	memcpy(&Temp_buffer[0], &A2Up_Page.var.SFP28_cfg.MASC_cfg.TX_CDRLBW, 8);
	if(!Write_bytes_to_MASC(MASC_TX_CDRLBW, 8, Temp_buffer)) {
		A2Up_Page.var.MASC_status_flags |= ST_MASC_I2C_RW_ERR_FLAG;
	}

}
//================================================================================

//==============================================================================
// Create default config for MASC-37029
//==============================================================================
void Init_Default_Cfg(void)
{
	A2Up_Page.var.SFP28_cfg.MASC_cfg.LB_MISCL = 0x00;

	A2Up_Page.var.SFP28_cfg.MASC_cfg.RX_MODES = 0x40;
	A2Up_Page.var.SFP28_cfg.MASC_cfg.RX_PKNG_LOS_THRS = 0x05;
	A2Up_Page.var.SFP28_cfg.MASC_cfg.RX_SLA = 0x1F;
	A2Up_Page.var.SFP28_cfg.MASC_cfg.RX_CDRLBW = 0x00;
	A2Up_Page.var.SFP28_cfg.MASC_cfg.RX_CDR_MISCL = 0x00;
	A2Up_Page.var.SFP28_cfg.MASC_cfg.RX_OP_SWING = 0x1E;
	A2Up_Page.var.SFP28_cfg.MASC_cfg.RX_OP_DEEMPH = 0x00;

	A2Up_Page.var.SFP28_cfg.MASC_cfg.TX_MODES = 0x40;
	A2Up_Page.var.SFP28_cfg.MASC_cfg.TX_ADAPT_EQ = 0x0C;
	A2Up_Page.var.SFP28_cfg.MASC_cfg.TX_LOS_THRS = 0x31;
	A2Up_Page.var.SFP28_cfg.MASC_cfg.TX_CDRLBW = 0x00;
	A2Up_Page.var.SFP28_cfg.MASC_cfg.TX_CDR_MISCL = 0x00;
	A2Up_Page.var.SFP28_cfg.MASC_cfg.TX_OP_SWING = 0x22;
	A2Up_Page.var.SFP28_cfg.MASC_cfg.TX_OP_DEEMPH = 0x00;
	A2Up_Page.var.SFP28_cfg.MASC_cfg.TX_OP_EYESHAPE = 0x00;
	A2Up_Page.var.SFP28_cfg.MASC_cfg.TX_OP_IBIAS = 0x00;
	A2Up_Page.var.SFP28_cfg.MASC_cfg.TX_OP_PREDRV_SWING = 0x15;
	A2Up_Page.var.SFP28_cfg.MASC_cfg.TX_OP_FAULT_FSM = 0xE7;

	A2Up_Page.var.SFP28_cfg.Global_TX_En = 0;		//Disable Tx by default
	A2Up_Page.var.SFP28_cfg.TxPwr_calibration = 256;
	A2Up_Page.var.SFP28_cfg.RxPwr_calibration = 256;

	A2Up_Page.var.CSum = 0x0000;
	uint8_t* A2Up_ptr = (uint8_t*)&A2Up_Page;
	for(uint16_t i = 0; i < sizeof(SFP28_cfg_t); i++) {
		A2Up_Page.var.CSum +=A2Up_ptr[i];
	}
}
//================================================================================

//==============================================================================
// Update config to MASC chip
//==============================================================================
void UpdateCfg_MASC(void)
{

	//Write config to chip
//	Temp_buffer[0] = 0x00;			//RegAddr is 1st byte of data
//	memcpy(&Temp_buffer[1], &TempBuf_128.u8[0], 64);
//	if(Write_soft_i2c(I2C_UX2291_ADDR, Temp_buffer, 65) !=0 ) {
//		//Set flag of error
//		UpPage05.var.Tx_UX_status_flags |= ST_TXRX_CFG_INIT_ERR_FLAG;
//	}
//	//Write 2nd part of config (up to UX2291_TX_SYS_CTRL) (101-64 = 37 bytes)
//	Temp_buffer[0] = 0x40;			//RegAddr is 1st byte of data
//	memcpy(&Temp_buffer[1], &TempBuf_128.u8[64], 37);
//	if(Write_soft_i2c(I2C_UX2291_ADDR, Temp_buffer, 38) !=0 ) {
//		//Set flag of error
//		UpPage05.var.Tx_UX_status_flags |= ST_TXRX_CFG_INIT_ERR_FLAG;
//	}
//
//	//Update value of UX2291_TX_SYS_CTRL (don't change AMUX_ADDR it is used for measurement)
//	Read_soft_i2c(I2C_UX2291_ADDR, UX2291_TX_SYS_CTRL, Temp_buffer, 1);
//	Temp_buffer[1] = Temp_buffer[0] & 0xF0;		//clear all bits except AMUX_ADDR
//	Temp_buffer[1] |= (UpPage04.var.TX_cfg.TX_SYS_CTRL & 0x0F);		//mask only config
//	Temp_buffer[0] = UX2291_TX_SYS_CTRL;			//RegAddr is 1st byte of data
//	Write_soft_i2c(I2C_UX2291_ADDR, Temp_buffer, 2);
}
//================================================================================

//==============================================================================
// Work with ADC of MASC-37029 chip
void Work_with_MASC_ADC(void)
{
	uint8_t buff[2];
	//Read result of ADC
	//MSB(7..0) - result(11..4), LSB(3..0) - result(3..0)
	Read_bytes_from_MASC(MASC_ADC_OUT_MSB, 2, buff);
	uint16_t value = (buff[0] << 4) | (buff[1] & 0x0F);
	switch(ADC_stage) {
	case 0:	//V33
		A2Up_Page.var.ADC_V33 = value;
		break;
	case 1:	//TEMP
		A2Up_Page.var.ADC_Temp = value;
		break;
	case 2:	//VCCR
		A2Up_Page.var.ADC_VCCR = value;
		break;
	case 3:	//RSSI
		A2Up_Page.var.ADC_RSSI = value;
		break;
	case 4:	//GPAD
		A2Up_Page.var.ADC_GPAD = value;
		break;
	case 5:	//MDIN
		A2Up_Page.var.ADC_MDIN = value;
		break;
	}
	//increment ADC stage
	ADC_stage += 1;
	if(ADC_stage > 5)
		ADC_stage = 0;

	//Write to ADC control (start new conversion)
	Read_bytes_from_MASC(MASC_ADC_CFG0, 1, buff);
	buff[0] = (buff[0] & 0xF8) | (ADC_stage & 0x07);
	Write_bytes_to_MASC(MASC_ADC_CFG0, 1, buff);
}
//================================================================================

//==============================================================================
// Read state of MASC chip
void Read_MASC_state(void)
{
	uint8_t buff[2];
	//Read state (2 bytes - MASC_LOS_LOL_STATE and MASC_TXFAULT_STATE)
	Read_bytes_from_MASC(MASC_LOS_LOL_STATE, 2, buff);
	A2Up_Page.var.MASC_LOS_LOL_state = buff[0];
	A2Up_Page.var.MASC_TxFault_state = buff[1];
}
//================================================================================

//==============================================================================
//Read 'Num' bytes from MASC-37029 beginning from 'RegAddr' to buffer
bool Read_bytes_from_MASC(uint8_t RegAddr, uint8_t Num, uint8_t *Pointer)
{
	if(Num > SMB_IN_BUF_SIZE)
		Num = SMB_IN_BUF_SIZE;

	if (i2c_write_buffer(I2C0, I2C_MASC_ADDR, &RegAddr, sizeof(RegAddr)) != I2C_DRV_OK) {
		return false;
	}
	
	uint8_t data[SMB_IN_BUF_SIZE + 1];
	return i2c_read_buffer(I2C0, I2C_MASC_ADDR, data, Num + 1) == I2C_DRV_OK; //add additional byte because of last byte always read as 0xFF
}
//================================================================================

//==============================================================================
//Write 'Num' bytes to MASC-37029 beginning from 'RegAddr' from buffer
bool Write_bytes_to_MASC(uint8_t RegAddr, uint8_t Num, const uint8_t *Pointer)
{
	if(Num > SMB_OUT_BUF_SIZE)
		Num = SMB_OUT_BUF_SIZE;
	
	uint8_t data[SMB_OUT_BUF_SIZE + 1];
	data[0] = RegAddr;
	memcpy(&data[1], Pointer, Num);
	
	return i2c_write_buffer(I2C0, I2C_MASC_ADDR, data, Num + 1) == I2C_DRV_OK;
}
//================================================================================

#ifdef __cplusplus
}
#endif // __cplusplus
