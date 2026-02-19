//=========================================================
// inc/SFP28_System.h:
//=========================================================
#ifndef __SFP28_SYSTEM_H__
#define __SFP28_SYSTEM_H__

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "MALD_37645.h"
#include "MATA_37644.h"
#include "pages.h"

//-----------------------------------------------------------------------------
//Module constants
#define SFP28_MODULE_SW_ID 0xA3   // Constant for this software
#define SOFTWARE_VERSION   0x0001 // Soft version (0xABCD -> AB.CD)
#define PASS_CONST_B0      0xA3   // Constant for byte0 of password entry
#define PASS_CONST_B1      0x25   // Constant for byte1 of password entry
#define PASS_CONST_B2      0xA0   // Constant for byte2 of password entry
#define PASS_CONST_B3      0x6F   // Constant for byte3 of password entry
//-----------------------------------------------------------------------------


#define  SMB_OUT_BUF_SIZE 16 // Size of SMB Tx buffer
#define  SMB_IN_BUF_SIZE  16 // Size of SMB Rx buffer

// Time_flags definitions
#define  TIME_100MS_FLAG 0x01 // bit0 - 100ms flag
#define  TIME_500MS_FLAG 0x02 // bit1 - 500ms flag
#define  TIME_1SEC_FLAG  0x04 // bit2 - 1 second flag

// Stat_Control (from A2 page) bits definitions
#define  ST_DATA_NOT_READY_FLAG   0x01 // bit0
#define  ST_RX_LOS_STATE_FLAG     0x02 // bit1
#define  ST_TX_FAULT_STATE_FLAG   0x04 // bit2
#define  ST_SOFT_RS0_FLAG         0x08 // bit3
#define  ST_RS0_STATE_FLAG        0x10 // bit4
#define  ST_RS1_STATE_FLAG        0x20 // bit5
#define  ST_SOFT_TX_DISABLE_FLAG  0x40 // bit6
#define  ST_TX_DISABLE_STATE_FLAG 0x80 // bit7

//=========== Structure definitions ===========

#define  CC_BASE_START (0) //Position of first byte of CC_BASE
#define  CC_BASE_POS  (63) //Position of CC_BASE
#define  CC_EXT_START (64) //Position of first byte of CC_EXT
#define  CC_EXT_POS   (95) //Position of CC_EXT

//--------------
//Bytes definition is from SFF-8472 Rev 12.4
typedef struct A0_Page_TypeDef {
  uint8_t ID;                //0
  uint8_t ExtID;             //1
  uint8_t Connector;         //2
  uint8_t TransceiverCod[8]; //3..10 - Code for electronic or optical compatibility
  uint8_t Encoding;          //11
  uint8_t SigRate_Nominal;   //12
  uint8_t RateID;            //13
  uint8_t LengthCodes[6];    //14..19 - different link length
  uint8_t VendorName[16];    //20..35 - SFP vendor name (ASCII)
  uint8_t Transceiver;       //36
  uint8_t VendorOUI[3];      //37..39 - SFP vendor IEEE company ID
  uint8_t VendorPN[16];      //40..55 - Part number provided by SFP vendor (ASCII)
  uint8_t VendorRev[4];      //56..59 - Revision level for part number provided by vendor (ASCII)
  uint8_t Wavelength[2];     //60..61 - Laser wavelength
  uint8_t FC_Speed_2;        //62
  uint8_t CC_BASE;           //63 - Check code for Base ID Fields (addresses 0 to 62)
    //Extended ID
  uint8_t Options[2];     //64..65
  uint8_t SigRate_max;    //66
  uint8_t SigRate_min;    //67
  uint8_t VendorSN[16];   //68..83 - Serial number provided by vendor (ASCII)
  uint8_t DateCode[8];    //84..91 -
  uint8_t DiagMon_Type;   //92
  uint8_t Enh_options;    //93
  uint8_t SFF_Compliance; //94
  uint8_t CC_EXT;         //95 - Check code for the Extended ID Fields (addresses 64 to 94)
    //Vendor specific
  uint8_t VendorSpec[32]; //96..127 -
} A0_Page_TypeDef;

typedef union A0_Page_Un {
  uint8_t Bytes[128];
  A0_Page_TypeDef var;
} A0_Page_t; // 128 = 0x80

#define  CC_DMI_START        (0) //Position of first byte of CC_DMI
#define  CC_DMI_POS          (95) //Position of CC_DMI

//--------------
//Bytes definition is from SFF-8472 Rev 12.4
typedef struct A2_Page_TypeDef {
  uint8_t Al_Warn_Thr[40]; //0..39 - Diagnostic Flag Alarm and Warning Thresholds
  uint8_t Opt_AW_Thr[16];  //40..55 - Thresholds for optional Laser Temperature and TEC Current alarms and  warnings
  uint8_t CalibrConst[36]; //56..91 - Diagnostic calibration constants for optional External Calibration
  uint8_t Reserved[3];     //92..94 -
  uint8_t CC_DMI;          //95 - Check code for Base Diagnostic Fields (addresses 0 to 94)
  //96..105 - Diagnostics
  uint8_t Temperature[2];  //96..97 - Internally measured module temperature (1st - MSB, 2nd - LSB)
  uint8_t Vcc[2];          //98..99 - Internally measured supply voltage in transceiver (1st - MSB, 2nd - LSB)
  uint8_t TxBias[2];       //100..101 - Internally measured TX Bias Current (1st - MSB, 2nd - LSB)
  uint8_t TxPower[2];      //102..103 - Measured TX output power (1st - MSB, 2nd - LSB)
  uint8_t RxPower[2];      //104..105 - Measured RX input power (1st - MSB, 2nd - LSB)
  uint8_t Opt_Diag[4];     //106..109 - Optional diagnostic of Laser Temperature and TEC Current
  uint8_t Stat_Control;    //110
  uint8_t Reserved_1;      //111
  uint8_t AlarmFlags[2];   //112..113 - Diagnostic Alarm Flag Status Bits
  uint8_t TxIn_Eq_Ctrl;    //114
  uint8_t RxOut_Emph;      //115
  uint8_t WarningFlags[2]; //116..117 -
  uint8_t Ext_StatCtrl[2]; //118..119 -
  uint8_t VendorSpec[3];   //120..122 -
  uint8_t PassEntry[4];    //123..126 - Optional Password Entry
  uint8_t TableSelect;     //127 - page select
} A2_Page_TypeDef;

typedef union A2_Page_Un {
  uint8_t Bytes[128];
  A2_Page_TypeDef var;
} A2_Page_t; // 128 = 0x80

#define  GRP_CMD_MATA_DATA_RD        0x01 // command to read group of registers of MATA
#define  GRP_CMD_MATA_DATA_WR        0x02 // command to write group of registers of MATA
#define  GRP_CMD_UPD_TX_CFG          0x03 // command to update Tx part of config
#define  GRP_CMD_UPD_GLB_RX_CFG      0x04 // command to update Global and Rx part of config
#define  GRP_CMD_WRITE_1ST_QUARTER   0x05 // command to write 1st quarter of Page to write to flash
#define  GRP_CMD_WRITE_2ND_QUARTER   0x06 // command to write 2nd quarter of Page to write to flash
#define  GRP_CMD_WRITE_3RD_QUARTER   0x07 // command to write 3rd quarter of Page to write to flash
#define  GRP_CMD_WR_4TH_Q_AND_UPDATE 0x08 // command to write 4th quarter of Page and update page in flash
#define  GRP_CMD_Tx_CALIBR_UPDATE    0x09 // command to update Tx calibration coefs
#define  GRP_CMD_Rx_CALIBR_UPDATE    0x0A // command to update Rx calibration coefs

#define  GRP_CMD_RESULT_OK           0x00 // command executed successfully
#define  GRP_CMD_RESULT_ERR          0x01 // command failed
#define  GRP_CMD_RESULT_CRC_FAIL     0x02 // Incorrect CRC for full page
#define  GRP_CMD_RESULT_CC_BASE_FAIL 0x03 // Incorrect CC_BASE
#define  GRP_CMD_RESULT_CC_EXT_FAIL  0x04 // Incorrect CC_EXT
#define  GRP_CMD_RESULT_CC_BOTH_FAIL 0x05 // Incorrect CC_BASE and CC_EXT
#define  GRP_CMD_RESULT_CC_DMI_FAIL  0x06 // Incorrect CC_DMI
#define  GRP_CMD_RESULT_CFG_CRC_FAIL 0x07 // Incorrect CSum for config page
#define  GRP_CMD_RESULT_BAD_CONST    0x08 // Bad constant

#define  FLASH_UPD_A0_LOW 0x01 // A0 low
#define  FLASH_UPD_A2_LOW 0x02 // A2 low
#define  FLASH_UPD_A2_HI  0x03 // A2 hi

#endif  //__SFP28_SYSTEM_H__
