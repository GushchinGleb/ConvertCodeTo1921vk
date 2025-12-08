#ifndef __MATA_37644_H__
#define __MATA_37644_H__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/** MATA -- RX, MALD -- TX **/

#include <stdbool.h>
#include <stdint.h>

#define MATA_CHIPID 0x8E // I2C address of the chip

// Registers address: [MATA-37644_V3.pdf page 22]
#define MATA_RA_CHIPID             0x00 // always 0x8E
#define MATA_RA_REVID              0x01 // always 0x01
#define MATA_RA_RESET              0x02 // write -> 0xAA -> reset
#define MATA_RA_MONITORS           0x03 // [MATA-37644_V3.pdf page 23]
#define MATA_RA_CDRCTRL            0x04 // [MATA-37644_V3.pdf page 24]
#define MATA_RA_I2C_ADDRESS_MODE   0x05 // [MATA-37644_V3.pdf page 25]
#define MATA_RA_CHANNEL_MODE       0x06
#define MATA_RA_LOCKPHASE          0x07
#define MATA_RA_LOS_MODE           0x0A
#define MATA_RA_LOS_LOL_STATUS     0x0B
#define MATA_RA_LOS_LOL_ALARM      0x0C
#define MATA_RA_LOS_CTRL           0x10
#define MATA_RA_SLA                0x11
#define MATA_RA_TIA_CTRL           0x12
#define MATA_RA_OUTPUT_CTRL        0x20
#define MATA_RA_OUTPUT_SWING       0x21
#define MATA_RA_OUTPUT_DEEMPH      0x22
#define MATA_RA_ADC_CONFIG0        0x60
#define MATA_RA_ADC_CONFIG2        0x61
#define MATA_RA_ADC_OUT0_MSBS      0x65
#define MATA_RA_ADC_OUT0_LSBS      0x66

// MASC_status_flags bits definitions
#define  ST_MATA_I2C_RW_ERR_FLAG   (1 << 0)
#define  ST_MATA_BAD_ID_FLAG       (1 << 1)
#define  ST_MATA_BAD_DEF_VAL_FLAG  (1 << 2)
#define  ST_MATA_CFG_INIT_ERR_FLAG (1 << 3)
#define  ST_MATA_37645_TYPE_FLAG   (1 << 4)

#pragma pack(push,1)
typedef struct {
	uint8_t CHIPID            ; // 128
	uint8_t REVID             ;
	uint8_t RESET             ; // 130
	uint8_t MONITORS          ;
	uint8_t CDRCTRL           ;
	uint8_t I2C_ADDRESS_MODE  ;
	uint8_t CHANNEL_MODE      ;
	uint8_t LOCKPHASE         ;
	uint8_t LOS_MODE          ;
	uint8_t LOS_LOL_STATUS    ;
	uint8_t LOS_LOL_ALARM     ;
	uint8_t LOS_CTRL          ;
	uint8_t SLA               ; // 140
	uint8_t TIA_CTRL          ;
	uint8_t OUTPUT_CTRL       ;
	uint8_t OUTPUT_SWING      ;
	uint8_t OUTPUT_DEEMPH     ;
	uint8_t ADC_CONFIG0       ; // 145
	uint8_t ADC_CONFIG2       ;
	uint8_t ADC_OUT0_MSBS     ;
	uint8_t ADC_OUT0_LSBS     ; // 148
} MATA_37644_cfg_struct_t; // size 21 bytes

typedef struct {
  MATA_37644_cfg_struct_t MATA_cfg; // Config of MATA-37644
  uint8_t  Global_TX_En;            // Global Tx Enable
  uint16_t TxPwr_calibration;       // Constant for conversion from ADC value to Tx power
} MATA_cfg_t; // size 24 bytes
#pragma pack(pop)

void Init_MATA_37644(void);
void Init_MATA_Default_Cfg(void);
void Work_with_MATA_ADC(void);
void Read_MATA_state(void);

/**
 * @brief The function reads value from the MATA register. All registers have size of 1 byte.
 * @param addr[IN] address of the register. See [table:5-1 page 22]
 * @param value[out] the value of the register
 */
bool read_register_from_MATA(uint8_t addr, uint8_t *value);

/**
 * @brief The function writes value to the MATA register. All registers have size of 1 byte.
 * @param addr[IN] address of the register. See [table:5-1 page 22]
 * @param value[IN] a new value of the register
 */
bool write_register_to_MATA(uint8_t addr, uint8_t value);

#ifdef __cplusplus
}
#endif // __cplusplus
	
#endif  //__MATA_37644_H__
