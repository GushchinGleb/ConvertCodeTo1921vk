#ifndef _MASC37029_H
#define _MASC37029_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include <stdint.h>

//-----------------------------------------------------------------------------
// --- Registers address
#define MASC_CHIPID					0x00	//
#define MASC_REVID					0x01	//
#define MASC_RESET_REG				0x02	//
#define MASC_LB_MISCL				0x03	//
#define MASC_LOS_LOL_STATE			0x06	//
#define MASC_TXFAULT_STATE			0x07	//

#define MASC_RX_MODES				0x10	//
#define MASC_RX_PKNG_LOS_THRS		0x11	//
#define MASC_RX_SLA					0x12	//
#define MASC_RX_CDRLBW				0x13	//
#define MASC_RX_CDR_MISCL			0x14	//
#define MASC_RX_OP_SWING			0x15	//
#define MASC_RX_OP_DEEMPH			0x16	//

#define MASC_TX_MODES				0x20	//
#define MASC_TX_ADAPT_EQ			0x21	//
#define MASC_TX_LOS_THRS			0x22	//
#define MASC_TX_CDRLBW				0x24	//
#define MASC_TX_CDR_MISCL			0x25	//
#define MASC_TX_OP_SWING			0x26	//
#define MASC_TX_OP_DEEMPH			0x27	//
#define MASC_TX_OP_EYESHAPE			0x28	//
#define MASC_TX_OP_IBIAS			0x29	//
#define MASC_TX_OP_PREDRV_SWING		0x2A	//
#define MASC_TX_OP_FAULT_FSM		0x2B	//

#define MASC_PRBS_GEN				0x50	//
#define MASC_PRBSGEN_DAC			0x51	//
#define MASC_PRBSCHK_ENBL			0x52	//
#define MASC_PRBSCHK_BANK			0x53	//
#define MASC_PRBSCHK_MODE			0x54	//
#define MASC_PRBSCHK_EYE			0x55	//
#define MASC_PRBSCHK_DELAY			0x56	//
#define MASC_PRBSCHK_ERR1			0x57	//
#define MASC_PRBSCHK_ERR2			0x58	//

#define MASC_ADC_CFG0				0x60	//
#define MASC_ADC_CFG1				0x61	//
#define MASC_ADC_OUT_MSB			0x65	//
#define MASC_ADC_OUT_LSB			0x66	//

//CHIP ID values
#define MASC_37029_CHIPID_VALUE			0x87	//
#define MASC_37028_CHIPID_VALUE			0x8D	//

void init_MASC_37029(void);

#ifdef __cplusplus
}
#endif // __cplusplus
	
#endif // _MASC37029_H
