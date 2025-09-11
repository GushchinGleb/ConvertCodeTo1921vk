#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
	
/*
 * Hardware I2C driver for K1921VK035.
 * Uses the provided I2C_TypeDef and bitfield definitions.
 */

#include "K1921VK035.h"
#include <stdint.h>
#include <stdbool.h>

#include "../inc/i2c_master.h"

/* Timeout constant (loop iterations) */
static const uint32_t I2C_TIMEOUT = 100000UL;

static i2c_drv_status_t i2c_wait_for_mode(I2C_TypeDef *i2c,
                                          I2C_ST_MODE_Enum expected_mode);

static i2c_drv_status_t i2c_start(I2C_TypeDef *i2c);

static i2c_drv_status_t i2c_write_byte(I2C_TypeDef *i2c, uint8_t byte);

static i2c_drv_status_t i2c_read_byte(I2C_TypeDef *i2c,
                                      uint8_t *data,
                                      bool ack);

/* =========================
 * Low-level helpers
 * ========================= */

/* Wait until status register updates to desired mode or timeout */
static i2c_drv_status_t i2c_wait_for_mode(I2C_TypeDef *i2c,
                                          I2C_ST_MODE_Enum expected_mode)
{
    uint32_t count = I2C_TIMEOUT;
    while (count-- > 0) {
        if (i2c->ST_bit.MODE == expected_mode) {
            return I2C_DRV_OK;
        }
    }
    return I2C_DRV_ERR_TIMEOUT;
}

/* Send START condition */
static i2c_drv_status_t i2c_start(I2C_TypeDef *i2c)
{
    i2c->CTL0 |= I2C_CTL0_START_Msk;
    return i2c_wait_for_mode(i2c, I2C_ST_MODE_STDONE);
}

/* Send STOP condition */
static void i2c_stop(I2C_TypeDef *i2c)
{
    i2c->CTL0 |= I2C_CTL0_STOP_Msk;
}

/* Write one byte (address or data) */
static i2c_drv_status_t i2c_write_byte(I2C_TypeDef *i2c, uint8_t byte)
{
	i2c->SDA_bit.DATA = byte;
	/* Clear START if it was set */
	i2c->CTL0 &= ~I2C_CTL0_START_Msk;

	/* Wait for status: ACK or NACK */
	uint32_t count = I2C_TIMEOUT;
	while (count-- > 0) {
		switch (i2c->ST_bit.MODE) {
		case I2C_ST_MODE_MTADPA: /* Address sent, ACK */
		case I2C_ST_MODE_MTDAPA: /* Data sent, ACK */
			return I2C_DRV_OK;
		case I2C_ST_MODE_MTADNA: /* Address sent, NACK */
		case I2C_ST_MODE_MTDANA: /* Data sent, NACK */
			return I2C_DRV_ERR_NO_ACK;
		default:
			break;
		}
	}
	return I2C_DRV_ERR_TIMEOUT;
}

/* Read one byte, with ACK (ack=true) or NACK (ack=false) */
static i2c_drv_status_t i2c_read_byte(I2C_TypeDef *i2c,
                                      uint8_t *data,
                                      bool ack)
{
	if (ack) {
		i2c->CTL0 |= I2C_CTL0_ACK_Msk;
	} else {
		i2c->CTL0 &= ~I2C_CTL0_ACK_Msk;
	}

	uint32_t count = I2C_TIMEOUT;
	while (count-- > 0) {
		switch (i2c->ST_bit.MODE) {
		case I2C_ST_MODE_MRDAPA: /* Data received, ACK */
		case I2C_ST_MODE_MRDANA: /* Data received, NACK */
			*data = (uint8_t)(i2c->SDA_bit.DATA);
			return I2C_DRV_OK;
		default:
			break;
		}
	}
	return I2C_DRV_ERR_TIMEOUT;
}

/* =========================
 * High-level API
 * ========================= */

/* Initialize I2C peripheral */
void i2c_init(I2C_TypeDef *i2c,
              uint32_t Fpclk,         /* global frequency (Hz) */
              uint32_t scl_freq)      /* scl frequency (Hz) */
{
	uint32_t SCLFRQ = Fpclk / 4 / scl_freq; // [page 354]
	/* Configure prescaler */
	// i2c->TOPR_bit.SMBTOPR = (uint32_t)(scl_divider & I2C_TOPR_SMBTOPR_Msk);

	/* Configure SCL frequency */
	i2c->CTL1_bit.SCLFRQ = SCLFRQ << I2C_CTL1_SCLFRQ_Pos & I2C_CTL1_SCLFRQ_Msk; // low bits
	i2c->CTL3_bit.SCLFRQ = SCLFRQ >> (7 - I2C_CTL3_SCLFRQ_Pos) & I2C_CTL3_SCLFRQ_Msk; // higs bits

	/* Enable peripheral */
	i2c->CTL1_bit.ENABLE = 1u;
}

/* Write buffer to 7-bit slave */
i2c_drv_status_t i2c_write_buffer(I2C_TypeDef *i2c,
                                  uint8_t slave_addr,
                                  const uint8_t *buf,
                                  uint32_t len)
{
	i2c_drv_status_t st = i2c_start(i2c);
	if (st != I2C_DRV_OK) return st;

	/* Send address + write bit (0) */
	st = i2c_write_byte(i2c, (uint8_t)(slave_addr << 1));
	if (st != I2C_DRV_OK) {
		i2c_stop(i2c);
		return st;
	}

	/* Send data bytes */
	for (uint32_t i = 0; i < len; i++) {
		st = i2c_write_byte(i2c, buf[i]);
		if (st != I2C_DRV_OK) {
			i2c_stop(i2c);
			return st;
		}
	}

	i2c_stop(i2c);
	return I2C_DRV_OK;
}

/* Read buffer from 7-bit slave */
i2c_drv_status_t i2c_read_buffer(I2C_TypeDef *i2c,
                                 uint8_t slave_addr,
                                 uint8_t *buf,
                                 uint32_t len)
{
	if (len == 0) return I2C_DRV_OK;

	i2c_drv_status_t st = i2c_start(i2c);
	if (st != I2C_DRV_OK) return st;

	/* Send address + read bit (1) */
	st = i2c_write_byte(i2c, (uint8_t)((slave_addr << 1) | 1u));
	if (st != I2C_DRV_OK) {
		i2c_stop(i2c);
		return st;
	}

	/* Read bytes */
	for (uint32_t i = 0; i < len; i++) {
		bool ack = (i < (len - 1u));
		st = i2c_read_byte(i2c, &buf[i], ack);
		if (st != I2C_DRV_OK) {
			i2c_stop(i2c);
			return st;
		}
	}

	i2c_stop(i2c);
	return I2C_DRV_OK;
}

#ifdef __cplusplus
}
#endif // __cplusplus
