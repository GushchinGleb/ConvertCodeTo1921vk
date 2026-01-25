#ifndef __MALD_37645_H__
#define __MALD_37645_H__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/** MALD -- TX, MATA -- RX **/

#include <stdbool.h>
#include <stdint.h>

#define MALD_CHIPID 0x8F // I2C address of the chip

// --- Registers address [MAld-37645_V3.pdf page 24]
#define MALD_RA_CHIPID             0x00 // always 0x8E
#define MALD_RA_REVID              0x01 // always 0x01
#define MALD_RA_RESET              0x02 // write -> 0xAA -> reset
#define MALD_RA_IO_CTRL            0x03 // [MAld-37645_V3.pdf page 26] and so on
#define MALD_RA_CDRCTRL            0x04 //
#define MALD_RA_I2C_ADDRESS_MODE   0x05 //
#define MALD_RA_CHANNEL_MODE       0x06 //
#define MALD_RA_LOCKPHASE          0x07 //
#define MALD_RA_LOS_LOL_TX_FAULT   0x0B //
#define MALD_RA_LOS_LOL_TX_ALARM   0x0C //
#define MALD_RA_IGNORE_TX_FAULT    0x0D //
#define MALD_RA_LOS_THRSH_AUTO_SQ  0x10 //
#define MALD_RA_CTLE_X             0x12 //
#define MALD_RA_OUTPUT_MUTE_SLEW   0x20 //
#define MALD_RA_LBIAS              0x21 //
#define MALD_RA_LMOD               0x22 //
#define MALD_RA_PREFALL            0x23 //
#define MALD_RA_TDE                0x24 //
#define MALD_RA_CROSSING_ADJ       0x25 //
#define MALD_RA_LBUMIN             0x27 //
#define MALD_RA_BUMIN_ENABLE       0x28 //
#define MALD_RA_ADC_CONFIG0        0x60 //
#define MALD_RA_ADC_CONFIG2        0x61 //
#define MALD_RA_ADC_OUT0_MSBS      0x65 //
#define MALD_RA_ADC_OUT0_LSBS      0x66 //
#define MALD_RA_ADC_TX_SELECT      0x67 //

// MASC_status_flags bits definitions
#define  ST_MALD_I2C_RW_ERR_FLAG   (1 << 0)
#define  ST_MALD_BAD_ID_FLAG       (1 << 1)
#define  ST_MALD_BAD_DEF_VAL_FLAG  (1 << 2)
#define  ST_MALD_CFG_INIT_ERR_FLAG (1 << 3)
#define  ST_MALD_37644_TYPE_FLAG   (1 << 4)

#pragma pack(push,1)
typedef struct {
  uint8_t CHIPID           ; // 152
  uint8_t REVID            ;
  uint8_t RESET            ;
  uint8_t IO_CTRL          ;
  uint8_t CDRCTRL          ;
  uint8_t I2C_ADDRESS_MODE ;
  uint8_t CHANNEL_MODE     ;
  uint8_t LOCKPHASE        ;
  uint8_t LOS_LOL_TX_FAULT ; // 160
  uint8_t LOS_LOL_TX_ALARM ;
  uint8_t IGNORE_TX_FAULT  ;
  uint8_t LOS_THRSH_AUTO_SQ;
  uint8_t CTLE_X           ;
  uint8_t OUTPUT_MUTE_SLEW ;
  uint8_t LBIAS            ;
  uint8_t LMOD             ;
  uint8_t PREFALL          ;
  uint8_t TDE              ;
  uint8_t CROSSING_ADJ     ; // 170
  uint8_t LBUMIN           ;
  uint8_t BUMIN_ENABLE     ;
  uint8_t ADC_CONFIG0      ; // 173
  uint8_t ADC_CONFIG2      ;
  uint8_t ADC_OUT0_MSBS    ;
  uint8_t ADC_OUT0_LSBS    ;
  uint8_t ADC_TX_SELECT    ; // 177
} MALD_37645_cfg_struct_t; // size 26 bytes

typedef struct {
  MALD_37645_cfg_struct_t MALD_cfg; // Config of MASC-37029
  uint8_t reserved[1];              // reserved
  uint8_t  Global_TX_En;            // Global Tx Enable
  uint16_t TxPwr_calibration;       // Constant for conversion from ADC value to Tx power
} MALD_cfg_t; // size 30 bytes
#pragma pack(pop)

void Init_MALD_37645(void);
void Init_MALD_Default_Cfg(void);
void Work_with_MALD_ADC(void);
void Read_MALD_state(void);

/**
 * @brief The function reads value from the MALD register. All registers have size of 1 byte.
 * @param addr[IN] address of the register. See [table:5-1 page 22]
 * @param value[out] the value of the register
 */
bool read_register_from_MALD(uint8_t addr, uint8_t *value);

/**
 * @brief The function writes value to the MALD register. All registers have size of 1 byte.
 * @param addr[IN] address of the register. See [table:5-1 page 22]
 * @param value[IN] a new value of the register
 */
bool write_register_to_MALD(uint8_t addr, uint8_t value);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MALD_37645_H__
