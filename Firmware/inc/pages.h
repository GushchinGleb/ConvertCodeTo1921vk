#ifndef __PAGES_H__
#define __PAGES_H__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include <stdint.h>

#include "MALD_37645.h"
#include "MATA_37644.h"

/** MALD -- TX, MATA -- RX **/

#pragma pack(push,1)
typedef struct A2Up_Page_TypeDef {
  MATA_cfg_t MATA_cfg;          //128..151 - Whole Config of MATA size: 24 bytes
  MALD_cfg_t MALD_cfg;          //152..181 - Whole Config of MALD size: 30 bytes
  uint16_t CSum;                //182..183 - Check Sum for config data (sum of bytes 128..181)
  uint8_t  SW_ID;               //184 - Constant of module software
  uint8_t  SW_Version[2];       //185..186 - Software version
  uint8_t  MATA_status_flags;   //187 - Flags of MATA init
  uint8_t  MALD_status_flags;   //188 - Flags of MALT init
  uint8_t  MATA_LOS_LOL_state;  //189 - Flags of Rx LOS and LOL
  uint8_t  MALD_TxFault_state;  //190 - Flags of Tx fault
  uint8_t  Reserved_state[1];   //191 - reserved
  uint16_t MATA_ADC_V33;        //192..193 - ADC result for V33 (from MATA)
  uint16_t MATA_ADC_Temp;       //194..195 - ADC result for temperature (from MATA)
  uint16_t MATA_ADC_RSSI;       //196..197 - ADC result for RSSI (from MATA)
  uint16_t MALD_ADC_V33;        //198..199 - ADC result for V33 (from MADL)
  uint16_t MALD_ADC_Temp;       //200..201 - ADC result for temperature (from MADL)
  uint16_t MALD_ADC_IBIAS_ref;  //202..203 - ADC result for IBIAS reference (from MADL)
  uint16_t MALD_ADC_IBIAS_msrt; //204..205 - ADC result for IBIAS measurement (from MADL)
  uint16_t MALD_ADC_IMON;       //206..207 - ADC result for MDIN MD current sink (from MADL)
  uint8_t  Reserved206[10];     //208..217 - reserved
  uint8_t  GrpCommand;          //218 - Group command, it will clear after action
  uint8_t  GrpAddress;          //219 - Address for Group command
  uint8_t  GrpSize;             //220 - Size for Group command
  uint8_t  GrpCmdResult;        //221 - Group command execution result
  uint8_t  GrpBuf_CRC[2];       //222..223 - CRC code for working with page
  uint8_t  GrpBuffer[32];       //224..255 - Buffer for group commands handling
} A2Up_Page_TypeDef;
#pragma pack(pop)

typedef union A2Up_Page_Un {
  uint8_t Bytes[128];
  A2Up_Page_TypeDef var;
} A2Up_Page_t; // 128 = 0x80

#ifdef __cplusplus
}
#endif // __cplusplus
	
#endif // __PAGES_H__
