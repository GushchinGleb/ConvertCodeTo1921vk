#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
	
#include "K1921VK035.h"
#include "../inc/i2c_master.h"

static uint8_t i2c_buff[256];
static uint8_t* i2c_start = i2c_buff; // start off the data (the not empty sell)
static uint8_t* i2c_end = i2c_buff; // end off the data (the first empy byte)
static uint8_t i2c_mode = 0; // 0 - reseive, 1 - send
static uint8_t i2c_addr = 0x0; // destination address
static int8_t i2c_status = 0; // -1 - failed, 0 - complete, 1 - busy

static void send_addr();
static void send_byte(uint8_t data);

void i2cm_init(uint32_t pclk_hz, uint32_t scl_hz) {
	// f_scl  = t_sclh + t_scll             // [page 354]
	// t_sclh = t_scll                      // [page 354]
	// f_scl  = 1 / (t_sclh * 2)            // [page 354]
	// t_sclh = 2 * SCLFRQ * (1 / pclk_hz)  // [page 354]
	// f_scl  = 1 / (4 * SCLFRQ * (1 / pclk_hz))
  // f_scl  = pclk_hz / (4 * SCLFRQ)
	// SCLFRQ = pclk_hz / (4 * f_scl)       // this MUST be in the datasheet
	const uint32_t SCLFRQ_val = (pclk_hz / scl_hz) / 4; // min value is 2 [page 354]
	
	I2C->CTL0 = 1 << I2C_CTL0_INTEN_Pos;                                               // [page 118]
	I2C->CTL1 = 1 << I2C_CTL1_ENABLE_Pos | (SCLFRQ_val & 0x7F) << I2C_CTL1_SCLFRQ_Pos; // [page 354], [page 118]
	I2C->CTL3 = (SCLFRQ_val >> 7) << I2C_CTL3_SCLFRQ_Pos;                              // [page 355], [page 118]
	
	return;
}

uint16_t i2cm_read(uint8_t* addr7, uint8_t* data, uint8_t max_len) {
  return 0;
}

void i2cm_write(uint8_t addr7, const uint8_t* data, uint8_t len) {
  i2c_status = 1; // busy
	i2c_addr = addr7;
	i2c_mode = 1; // send
	memcpy(i2c_buff, data, len);
	
	i2c_start = i2c_buff;
	i2c_end = i2c_buff + len;
	
	send_addr();
	
	return;
}

void I2C_IRQHandler() {  // startup_K1921VK035.s:115
	switch (I2C->ST_bit.MODE) {
	case I2C_ST_MODE_IDLE:
		break;
	case I2C_ST_MODE_STDONE:
		break;
  case I2C_ST_MODE_RSDONE:
		break;
  case I2C_ST_MODE_IDLARL:
		break;
  case I2C_ST_MODE_MTADPA:
  case I2C_ST_MODE_MTADNA:
  case I2C_ST_MODE_MTDAPA:
  case I2C_ST_MODE_MTDANA:
		i2c_start++;
		if (i2c_start >= i2c_end) {
		  i2c_status = 0; // complete
			break;
		}
		send_byte(*i2c_start);
		break;
  case I2C_ST_MODE_MRADPA:
		break;
  case I2C_ST_MODE_MRADNA:
		break;
  case I2C_ST_MODE_MRDAPA:
		break;
  case I2C_ST_MODE_MRDANA:
		break;
  case I2C_ST_MODE_MTMCER:
		break;
  case I2C_ST_MODE_SRADPA:
		break;
  case I2C_ST_MODE_SRAAPA:
		break;
  case I2C_ST_MODE_SRDAPA:
		break;
  case I2C_ST_MODE_SRDANA:
		break;
  case I2C_ST_MODE_STADPA:
		break;
  case I2C_ST_MODE_STAAPA:
		break;
  case I2C_ST_MODE_STDAPA:
		break;
  case I2C_ST_MODE_STDANA:
		break;
  case I2C_ST_MODE_SATADP:
		break;
  case I2C_ST_MODE_SATAAP:
		break;
  case I2C_ST_MODE_SATDAP:
		break;
  case I2C_ST_MODE_SATDAN:
		break;
  case I2C_ST_MODE_SSTOP:
		break;
  case I2C_ST_MODE_SGADPA:
		break;
  case I2C_ST_MODE_SDAAPA:
		break;
  case I2C_ST_MODE_BERROR:
		break;
  case I2C_ST_MODE_HMTMCOK:
		break;
  case I2C_ST_MODE_HRSDONE:
		break;
  case I2C_ST_MODE_HIDLARL:
		break;
  case I2C_ST_MODE_HMTADPA:
		break;
  case I2C_ST_MODE_HMTADNA:
		break;
  case I2C_ST_MODE_HMTDAPA:
		break;
  case I2C_ST_MODE_HMTDANA:
		break;
  case I2C_ST_MODE_HMRADPA:
		break;
  case I2C_ST_MODE_HMRADNA:
		break;
  case I2C_ST_MODE_HMRDAPA:
		break;
  case I2C_ST_MODE_HMRDANA:
		break;
  case I2C_ST_MODE_HSRADPA:
		break;
  case I2C_ST_MODE_HSRDAPA:
		break;
  case I2C_ST_MODE_HSRDANA:
		break;
  case I2C_ST_MODE_HSTADPA:
		break;
  case I2C_ST_MODE_HSTDAPA:
		break;
  case I2C_ST_MODE_HSTDANA:
		break;
	default:
		break;
	}
}

static void send_addr() {
	I2C->SDA_bit.DATA = i2c_addr;
	//I2C->ST_bit.INT = 1;
}

static void send_byte(uint8_t data) {
	I2C->SDA_bit.DATA = data;
	//I2C->ST_bit.INT = 1;
}

#ifdef __cplusplus
}
#endif // __cplusplus
