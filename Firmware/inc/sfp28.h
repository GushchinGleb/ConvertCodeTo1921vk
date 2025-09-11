//=========================================================
// inc/SFP28_System.h:
//=========================================================
#ifndef __SFP28_SYSTEM_H__
#define __SFP28_SYSTEM_H__

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

//-----------------------------------------------------------------------------
//Module constants
#define SFP28_MODULE_SW_ID		0xA3		// Constant for this software
#define SOFTWARE_VERSION		0x0001		// Soft version (0xABCD -> AB.CD)
#define PASS_CONST_B0			0xA3		// Constant for byte0 of password entry
#define PASS_CONST_B1			0x25		// Constant for byte1 of password entry
#define PASS_CONST_B2			0xA0		// Constant for byte2 of password entry
#define PASS_CONST_B3			0x6F		// Constant for byte3 of password entry
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Flash memory map (for F392)
//0x3E00 - 0x3FFF - Lock Byte page
//0x3C00 - 0x3EFF - temp page for work with flash memory
//0x3A00 - 0x3BFF - pages for storage of SFP28 memory blocks (1 page)
#define FLASH_A0_LOW_PAGE_ADDR		0x3A00L		// 128 bytes of A0 Low Page data
#define FLASH_A0_HI_PAGE_ADDR		0x3A80L		// 128 bytes of A0 Hi Page data
#define FLASH_A2_LOW_PAGE_ADDR		0x3B00L		// 128 bytes of A2 Low Page data
#define FLASH_A2_HI_PAGE_ADDR		0x3B80L		// 128 bytes of A2 Hi Page data

//-----------------------------------------------------------------------------
// Pin Definitions
//-----------------------------------------------------------------------------

// CONSTANTS
#define SYSCLK_FREQ			49000000	// SYSCLK = 24,5 MHz
#define SMB_FREQ			100000		// SMB frequency = 100kHz

#define I2C_MASC_ADDR			0x9E		// 1001111x - I2C address of MASC-37029/37028

// Status vector - top 4 bits only
//For slave
#define  SMB_SRADD      0x20           // (SR) slave address received (also could be a lost arbitration)
#define  SMB_SRSTO      0x10           // (SR) STOP detected while SR or ST, or lost arbitration
#define  SMB_SRDB       0x00           // (SR) data byte received, or lost arbitration
#define  SMB_STDB       0x40           // (ST) data byte transmitted
#define  SMB_STSTO      0x50           // (ST) STOP detected during a transaction; bus error
//For master
#define  SMB_MTSTA				0xE0 // (MT) start transmitted
#define  SMB_MTDB				0xC0 // (MT) data byte transmitted
#define  SMB_MRDB				0x80 // (MR) data byte received
// End status vector definition

#define  WRITE					0x00 // SMBus WRITE command
#define  READ					0x01 // SMBus READ command

#define  SMB_OUT_BUF_SIZE		16 // Size of SMB Tx buffer
#define  SMB_IN_BUF_SIZE		16 // Size of SMB Rx buffer

//I2C slave definitions
#define  I2C_STATUS_VECTOR_MASK  0x0F   // NACK, START, STOP, WR, RD
// I2C States
#define  I2C_ADDR_RD    0x09			// Valid Slave Address + Master Read Request
#define  I2C_ADDR_WR    0x0A			// Valid Slave Address + Master Write Request
#define  I2C_RD_DATA    0x01			// Transfer data from Slave (Also can check B4 to see what ACK we just received from master)
#define  I2C_WR_DATA    0x02			// Write data to Slave (Also can check B4 to see what ACK(ACK/NACK) we just sent)
#define  I2C_STA        0x08
#define  I2C_STO        0x04
#define  I2C_STOSTA     0x0C
#define  I2C_STOSTARD   0x0D

// Time_flags definitions
#define  TIME_100MS_FLAG		0x01 // bit0 - 100ms flag
#define  TIME_500MS_FLAG		0x02 // bit1 - 500ms flag
#define  TIME_1SEC_FLAG			0x04 // bit2 - 1 second flag

// MASC_status_flags bits definitions
#define  ST_MASC_I2C_RW_ERR_FLAG	0x01 // bit0
#define  ST_MASC_BAD_ID_FLAG		0x02 // bit1
#define  ST_MASC_BAD_DEF_VAL_FLAG	0x04 // bit2
#define  ST_MASC_CFG_INIT_ERR_FLAG	0x08 // bit3
#define  ST_MASC_37029_TYPE_FLAG	0x10 // bit4
#define  ST_MASC_37028_TYPE_FLAG	0x20 // bit5

// Stat_Control (from A2 page) bits definitions
#define  ST_DATA_NOT_READY_FLAG		0x01 // bit0
#define  ST_RX_LOS_STATE_FLAG		0x02 // bit1
#define  ST_TX_FAULT_STATE_FLAG		0x04 // bit2
#define  ST_SOFT_RS0_FLAG			0x08 // bit3
#define  ST_RS0_STATE_FLAG			0x10 // bit4
#define  ST_RS1_STATE_FLAG			0x20 // bit5
#define  ST_SOFT_TX_DISABLE_FLAG	0x40 // bit6
#define  ST_TX_DISABLE_STATE_FLAG	0x80 // bit7

//=========== Structure definitions ===========
typedef struct MASC_37029_cfg_struct_TypeDef {
	uint8_t RESET_REG;			//Reg Addr offset 0x02
	uint8_t LB_MISCL;			//Reg Addr offset 0x03
	uint8_t RX_MODES;			//Reg Addr offset 0x10
	uint8_t RX_PKNG_LOS_THRS;	//Reg Addr offset 0x11
	uint8_t RX_SLA;				//Reg Addr offset 0x12
	uint8_t RX_CDRLBW;			//Reg Addr offset 0x13
	uint8_t RX_CDR_MISCL;		//Reg Addr offset 0x14
	uint8_t RX_OP_SWING;		//Reg Addr offset 0x15
	uint8_t RX_OP_DEEMPH;		//Reg Addr offset 0x16

	uint8_t TX_MODES;			//Reg Addr offset 0x20
	uint8_t TX_ADAPT_EQ;		//Reg Addr offset 0x21
	uint8_t TX_LOS_THRS;		//Reg Addr offset 0x22
	uint8_t TX_CDRLBW;			//Reg Addr offset 0x24
	uint8_t TX_CDR_MISCL;		//Reg Addr offset 0x25
	uint8_t TX_OP_SWING;		//Reg Addr offset 0x26
	uint8_t TX_OP_DEEMPH;		//Reg Addr offset 0x27
	uint8_t TX_OP_EYESHAPE;		//Reg Addr offset 0x28
	uint8_t TX_OP_IBIAS;		//Reg Addr offset 0x29
	uint8_t TX_OP_PREDRV_SWING;	//Reg Addr offset 0x2A
	uint8_t TX_OP_FAULT_FSM;	//Reg Addr offset 0x2B

	uint8_t PRBS_GEN;			//Reg Addr offset 0x50
	uint8_t PRBSGEN_DAC;		//Reg Addr offset 0x51
	uint8_t PRBSCHK_ENBL;		//Reg Addr offset 0x52
	uint8_t PRBSCHK_BANK;		//Reg Addr offset 0x53
	uint8_t PRBSCHK_MODE;		//Reg Addr offset 0x54
	uint8_t PRBSCHK_EYE;		//Reg Addr offset 0x55
	uint8_t PRBSCHK_DELAY;		//Reg Addr offset 0x56

	uint8_t ADC_CFG0;			//Reg Addr offset 0x60
	uint8_t ADC_CFG1;			//Reg Addr offset 0x61
} MASC_37029_cfg_struct_t;

#define  CC_BASE_START				(0) //Position of first byte of CC_BASE
#define  CC_BASE_POS				(63) //Position of CC_BASE
#define  CC_EXT_START				(64) //Position of first byte of CC_EXT
#define  CC_EXT_POS					(95) //Position of CC_EXT

//--------------
//Bytes definition is from SFF-8472 Rev 12.4
typedef struct A0_Page_TypeDef {
	uint8_t ID;					//0
	uint8_t ExtID;				//1
	uint8_t Connector;			//2
	uint8_t TransceiverCod[8];	//3..10 - Code for electronic or optical compatibility
	uint8_t Encoding;			//11
	uint8_t SigRate_Nominal;	//12
	uint8_t RateID;				//13
	uint8_t LengthCodes[6];		//14..19 - different link length
	uint8_t VendorName[16];		//20..35 - SFP vendor name (ASCII)
	uint8_t Transceiver;		//36
	uint8_t VendorOUI[3];		//37..39 - SFP vendor IEEE company ID
	uint8_t VendorPN[16];		//40..55 - Part number provided by SFP vendor (ASCII)
	uint8_t VendorRev[4];		//56..59 - Revision level for part number provided by vendor (ASCII)
	uint8_t Wavelength[2];		//60..61 - Laser wavelength
	uint8_t FC_Speed_2;			//62
	uint8_t CC_BASE;			//63 - Check code for Base ID Fields (addresses 0 to 62)
		//Extended ID
	uint8_t Options[2];			//64..65
	uint8_t SigRate_max;		//66
	uint8_t SigRate_min;		//67
	uint8_t VendorSN[16];		//68..83 - Serial number provided by vendor (ASCII)
	uint8_t DateCode[8];		//84..91 -
	uint8_t DiagMon_Type;		//92
	uint8_t Enh_options;		//93
	uint8_t SFF_Compliance;		//94
	uint8_t CC_EXT;				//95 - Check code for the Extended ID Fields (addresses 64 to 94)
		//Vendor specific
	uint8_t VendorSpec[32];		//96..127 -
} A0_Page_TypeDef;

typedef union A0_Page_Un {
	A0_Page_TypeDef var;
} A0_Page_t; // 128 = 0x80

#define  CC_DMI_START				(0) //Position of first byte of CC_DMI
#define  CC_DMI_POS					(95) //Position of CC_DMI

//--------------
//Bytes definition is from SFF-8472 Rev 12.4
typedef struct A2_Page_TypeDef {
	uint8_t Al_Warn_Thr[40];	//0..39 - Diagnostic Flag Alarm and Warning Thresholds
	uint8_t Opt_AW_Thr[16];		//40..55 - Thresholds for optional Laser Temperature and TEC Current alarms and	warnings
	uint8_t CalibrConst[36];	//56..91 - Diagnostic calibration constants for optional External Calibration
	uint8_t Reserved[3];		//92..94 -
	uint8_t CC_DMI;				//95 - Check code for Base Diagnostic Fields (addresses 0 to 94)
	//96..105 - Diagnostics
	uint8_t Temperature[2];		//96..97 - Internally measured module temperature (1st - MSB, 2nd - LSB)
	uint8_t Vcc[2];				//98..99 - Internally measured supply voltage in transceiver (1st - MSB, 2nd - LSB)
	uint8_t TxBias[2];			//100..101 - Internally measured TX Bias Current (1st - MSB, 2nd - LSB)
	uint8_t TxPower[2];			//102..103 - Measured TX output power (1st - MSB, 2nd - LSB)
	uint8_t RxPower[2];			//104..105 - Measured RX input power (1st - MSB, 2nd - LSB)
	uint8_t Opt_Diag[4];		//106..109 - Optional diagnostic of Laser Temperature and TEC Current
	uint8_t Stat_Control;		//110
	uint8_t Reserved_1;			//111
	uint8_t AlarmFlags[2];		//112..113 - Diagnostic Alarm Flag Status Bits
	uint8_t TxIn_Eq_Ctrl;		//114
	uint8_t RxOut_Emph;			//115
	uint8_t WarningFlags[2];	//116..117 -
	uint8_t Ext_StatCtrl[2];	//118..119 -
	uint8_t VendorSpec[3];		//120..122 -
	uint8_t PassEntry[4];		//123..126 - Optional Password Entry
	uint8_t TableSelect;		//127 - page select
} A2_Page_TypeDef;

typedef union A2_Page_Un {
	A2_Page_TypeDef var;
} A2_Page_t; // 128 = 0x80

//--------------
//typedef struct UpPage03_TypeDef {
//	int16_t Temp_HiAlarm;		//128..129 - Temperature High Alarm (1st-MSB, 2nd-LSB)
//	int16_t Temp_LoAlarm;		//130..131 - Temperature Low Alarm (1st-MSB, 2nd-LSB)
//	int16_t Temp_HiWarn;		//132..133 - Temperature Hi Alarm (1st-MSB, 2nd-LSB)
//	int16_t Temp_LoWarn;		//134..135 - Temperature Hi Alarm (1st-MSB, 2nd-LSB)
//	uint8_t Reserved1[8];		//136..143 - reserved
//	uint16_t Vcc_HiAlarm;		//144..145 - Vcc High Alarm (1st-MSB, 2nd-LSB)
//	uint16_t Vcc_LoAlarm;		//146..147 - Vcc Low Alarm (1st-MSB, 2nd-LSB)
//	uint16_t Vcc_HiWarn;		//148..149 - Vcc Hi Alarm (1st-MSB, 2nd-LSB)
//	uint16_t Vcc_LoWarn;		//150..151 - Vcc Hi Alarm (1st-MSB, 2nd-LSB)
//	uint8_t Reserved2[8];		//152..159 - reserved
//	uint8_t VendorSpec1[16];	//160..175 - reserved (vendor specific)
//	uint16_t RxPwr_HiAlarm;		//176..177 - Rx Power High Alarm (1st-MSB, 2nd-LSB)
//	uint16_t RxPwr_LoAlarm;		//178..179 - Rx Power Low Alarm (1st-MSB, 2nd-LSB)
//	uint16_t RxPwr_HiWarn;		//180..181 - Rx Power Hi Alarm (1st-MSB, 2nd-LSB)
//	uint16_t RxPwr_LoWarn;		//182..183 - Rx Power Hi Alarm (1st-MSB, 2nd-LSB)
//	uint16_t TxBias_HiAlarm;	//184..185 - Tx Bias High Alarm (1st-MSB, 2nd-LSB)
//	uint16_t TxBias_LoAlarm;	//186..187 - Tx Bias Low Alarm (1st-MSB, 2nd-LSB)
//	uint16_t TxBias_HiWarn;		//188..189 - Tx Bias Hi Alarm (1st-MSB, 2nd-LSB)
//	uint16_t TxBias_LoWarn;		//190..191 - Tx Bias Hi Alarm (1st-MSB, 2nd-LSB)
//	uint16_t TxPwr_HiAlarm;		//192..193 - Tx Power High Alarm (1st-MSB, 2nd-LSB)
//	uint16_t TxPwr_LoAlarm;		//194..195 - Tx Power Low Alarm (1st-MSB, 2nd-LSB)
//	uint16_t TxPwr_HiWarn;		//196..197 - Tx Power Hi Alarm (1st-MSB, 2nd-LSB)
//	uint16_t TxPwr_LoWarn;		//198..199 - Tx Power Hi Alarm (1st-MSB, 2nd-LSB)
//	uint8_t Reserved3[8];		//200..207 - reserved
//	uint8_t Reserved4[8];		//208..215 - reserved
//	uint8_t VendorSpec2[8];		//216..223 - reserved (vendor specific)
//	uint8_t MaxTxEq_RxEmp;		//224 - bits7..4 - max Tx input equalization, bits3..0 - max Rx out emphasis
//	uint8_t RxOut_Cfg;			//225 - bits7..6 - reserv, bits5..4 - Rx out emp type, bits3..0 - Rx out amplitude support
//	uint8_t Reserved5;			//226 - reserved
//	uint8_t TxRx_Cfg;			//227 - bits7..6 - FEC control, bits5..4-reserv, bits3..1 - Tx and Rx cfg, bit0-reserv
//	uint8_t Max_TC_stab_time;	//228 - max TC stabilization time
//	uint8_t Max_CTLE_set_time;	//229 - max CTLE settling time
//	uint8_t FEC_en;				//230 - bits7..6 - FEC enable flags, bits5..0-reserv
//	uint8_t Tx_ForceSquelch;	//231 - bits7..4 - reserv, bits3..0 - Tx force squelch (bit3-ch4..,bit0-ch1)
//	uint8_t Reserved6;			//232 - reserved
//	uint8_t Tx_AEFreeze;		//233 - bits7..4 - reserv, bits3..0 - Tx adapt eq freeze (bit3-ch1..,bit0-ch4)
//	uint8_t TxIn_Eq_ctrl[2];	//234..235 - 234 - ch1 and ch2, 235 - ch3 and ch4 - Tx input equalizer control
//								//	bits7..4 - ch1(3), bits3..0 - ch2(4)
//	uint8_t RxOut_Emp_ctrl[2];	//236..237 - 236 - ch1 and ch2, 237 - ch3 and ch4 - Rx output emphasis control
//								//	bits7..4 - ch1(3), bits3..0 - ch2(4)
//	uint8_t RxOut_Ampl_ctrl[2];	//238..239 - 238 - ch1 and ch2, 239 - ch3 and ch4 - Rx output amplitude control
//								//	bits7..4 - ch1(3), bits3..0 - ch2(4)
//	uint8_t RxTx_Sq_Dis;		//240 - bits7..4 - Rx squelch disable (bit7-ch4..,bit4-ch1), bits3..0 - Tx squelch disable (bit3-ch4..,bit0-ch1)
//	uint8_t RxOut_Dis_Tx_AE;	//241 - bits7..4 - Rx output disable (bit7-ch4..,bit4-ch1), bits3..0 - Tx adapt eq en (bit3-ch4..,bit0-ch1)
//	uint8_t Mask_RxPwr[2];		//242..243 - mask for Rx Power Hi and Low alarms and warning
//	uint8_t Mask_TxBias[2];		//244..245 - mask for Tx Bias Hi and Low alarms and warning
//	uint8_t Mask_TxPwr[2];		//246..247 - mask for Tx Power Hi and Low alarms and warning
//	uint8_t Reserved7[4];		//248..251 - reserved
//	uint8_t Reserved8[4];		//252..255 - reserved
//} UpPage03_TypeDef;
//
//typedef union UpPage03_Un {
//	uint8_t Bytes[128];
//	UpPage03_TypeDef var;
//} UpPage03_t;


//--------------
typedef struct SFP28_cfg_t {
	MASC_37029_cfg_struct_t MASC_cfg;			//128..156 - Config of MASC-37029
	uint8_t Global_TX_En;						//157 - Global Tx Enable
	uint16_t TxPwr_calibration;					//158..159 - Constant for conversion from ADC value to Tx power
	uint16_t RxPwr_calibration;					//160..161 - Constant for conversion from ADC value to Rx power
	uint8_t Reserved_cfg[16];					//162..177 - reserved config
} SFP28_cfg_t;

typedef struct A2Up_Page_TypeDef {
	SFP28_cfg_t SFP28_cfg;						//128..177 - Whole Config of SFP28
	uint16_t CSum;								//178..179 - Check Sum for config data (sum of bytes 128..177)
	uint8_t SW_ID;								//180 - Constant of module software
	uint8_t SW_Version[2];						//181..182 - Software version
	uint8_t MASC_status_flags;					//183 - Flags of MASC init
	uint8_t MASC_LOS_LOL_state;					//184 - Flags of Tx and Rx LOS and LOL
	uint8_t MASC_TxFault_state;					//185 - Flags of Tx fault
	uint8_t Reserved_state[6];					//186..191 - reserved
	uint16_t ADC_V33;							//192..193 - ADC result for V33 (from MASC)
	uint16_t ADC_Temp;							//194..195 - ADC result for temperature (from MASC)
	uint16_t ADC_VCCR;							//196..197 - ADC result for VCCR (from MASC)
	uint16_t ADC_RSSI;							//198..199 - ADC result for RSSI (from MASC)
	uint16_t ADC_GPAD;							//200..201 - ADC result for GPAD (from MASC)
	uint16_t ADC_MDIN;							//202..203 - ADC result for MDIN MD current sink (from MASC)
	uint16_t CPU_Temp;							//204..205 - CPU temperature measurement
	uint8_t Reserved[12];						//206..217 - reserved
	uint8_t GrpCommand;							//218 - Group command, it will clear after action
	uint8_t GrpAddress;							//219 - Address for Group command
	uint8_t GrpSize;							//220 - Size for Group command
	uint8_t GrpCmdResult;						//221 - Group command execution result
	uint8_t GrpBuf_CRC[2];						//222..223 - CRC code for working with page
	uint8_t GrpBuffer[32];						//224..255 - Buffer for group commands handling
} A2Up_Page_TypeDef;

typedef union A2Up_Page_Un {
	A2Up_Page_TypeDef var;
} A2Up_Page_t; // 128 = 0x80

#define  GRP_CMD_MASC_DATA_RD			0x01 // command to read group of registers of MASC
#define  GRP_CMD_MASC_DATA_WR			0x02 // command to write group of registers of MASC
#define  GRP_CMD_WRITE_1ST_QUARTER		0x03 // command to write group of registers of channel 3 of GN1185
#define  GRP_CMD_WRITE_2ND_QUARTER		0x04 // command to write group of registers of channel 4 of GN1185
#define  GRP_CMD_WRITE_3RD_QUARTER		0x05 // command to read group of registers of all channels of GN1185
#define  GRP_CMD_WR_4TH_Q_AND_UPDATE	0x06 // command to execute macro for GN2104S
#define  GRP_CMD_TX_2104_DATA_RD	0x07 // command to read data of Tx GN2104S
#define  GRP_CMD_RX_2104_DATA_RD	0x08 // command to read data of Rx GN2104S
#define  GRP_CMD_TX_2104_CFG_WR		0x09 // command to write config data to Tx GN2104S
#define  GRP_CMD_RX_2104_CFG_WR		0x0A // command to write config data to Rx GN2104S
#define  GRP_CMD_DAC_VALUE_UPDATE	0x0B // command to update value of DAC
#define  GRP_CMD_GLOB_TX_EN_CHANGE	0x0C // command to change value of Global Tx Enable flag
#define  GRP_CMD_Tx_CALIBR_UPDATE	0x0D // command to update Tx calibration coefs
#define  GRP_CMD_Rx_CALIBR_UPDATE	0x0E // command to update Rx calibration coefs

#define  GRP_CMD_RESULT_OK				0x00 // command executed successfully
#define  GRP_CMD_RESULT_ERR				0x01 // command failed
#define  GRP_CMD_RESULT_CRC_FAIL		0x02 // Incorrect CRC for full page
#define  GRP_CMD_RESULT_CC_BASE_FAIL	0x03 // Incorrect CC_BASE
#define  GRP_CMD_RESULT_CC_EXT_FAIL		0x04 // Incorrect CC_EXT
#define  GRP_CMD_RESULT_CC_BOTH_FAIL	0x05 // Incorrect CC_BASE and CC_EXT
#define  GRP_CMD_RESULT_CC_DMI_FAIL		0x06 // Incorrect CC_DMI
#define  GRP_CMD_RESULT_CFG_CRC_FAIL	0x07 // Incorrect CSum for config page
#define  GRP_CMD_RESULT_BAD_CONST		0x08 // Bad constant

#define  FLASH_UPD_A0_LOW			0x01 // A0 low
#define  FLASH_UPD_A2_LOW			0x02 // A2 low
#define  FLASH_UPD_A2_HI			0x03 // A2 hi

// Variables
extern A0_Page_t A0_Page;
extern A2_Page_t A2_Page;
extern A2Up_Page_t A2Up_Page;

//I2C variables
extern uint8_t I2C_Current_Address;
extern uint8_t I2C_Current_Page;
extern uint8_t *I2C_Data_Pointer;
extern volatile bool I2C_Addr_write_flag;
//Timer variables
extern uint8_t Timer10ms_count;			// Counter for 10ms timer
extern uint8_t Timer100ms_count;		// Counter for 100ms timer
extern uint8_t Time_flags;					// Different flags of time intervals
//ADC variables
extern uint8_t ADC_stage;
//Status variables
extern uint8_t MASC_status_flags;
extern uint8_t Module_Selected;
extern uint8_t ModSel_counter;
extern uint8_t I2C_Slave_activated;

extern uint8_t Debug_buf[256];
extern uint8_t Debug_ptr;

// Functions
//from F392_SFP28_v0_0.c
void SiLabs_Startup (void);
void T0_Waitms(uint8_t ms);
uint8_t *I2C_Decode_page_address(uint8_t Address);
void I2C_Write_data(uint8_t Byte);
uint8_t I2C_Read_data(void);
void I2C_Check_IntFlags(void);

//from InitDevice.c
void Init_Peripherals(void);
void Start_temperature_sensor(void);
void Read_temperature_sensor(void);

//from MASC_3702x.c
void Init_MASC_37029(void);
void Init_Default_Cfg(void);
void UpdateCfg_MASC(void);
void Work_with_MASC_ADC(void);
void Read_MASC_state(void);
bool Read_bytes_from_MASC(uint8_t RegAddr, uint8_t Num, uint8_t *Pointer);
bool Write_bytes_to_MASC(uint8_t RegAddr, uint8_t Num, const uint8_t *Pointer);

#endif	//__SFP28_SYSTEM_H__
