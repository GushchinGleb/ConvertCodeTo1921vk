#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include <stdint.h>

#include "K1921VK035.h"

#include "../inc/board.h"
#include "../inc/soft_master_i2c.h"
#include "../inc/sfp28.h"
#include "../inc/tick.h"

extern A2Up_Page_t A2Up_Page;

#if defined(__ARMCC_VERSION)
  #define ALWAYS_INLINE static __forceinline
#else
  #define ALWAYS_INLINE static __attribute__((always_inline)) inline
#endif

#define MAS_I2C_DELAY				10
#define MAS_I2C_DELAY_HALF	5
#define DELAY_SDA_TO_SCLHI	3

		/**
 * struct i2c_msg - an I2C transaction segment beginning with START
 * @addr: Slave address, either seven or ten bits.  When this is a ten
 *	bit address, I2C_M_TEN must be set in @flags and the adapter
 *	must support I2C_FUNC_10BIT_ADDR.
 * @flags: I2C_M_RD is handled by all adapters.  No other flags may be
 *	provided unless the adapter exported the relevant I2C_FUNC_*
 *	flags through i2c_check_functionality().
 * @len: Number of data bytes in @buf being read from or written to the
 *	I2C slave address.  For read transactions where I2C_M_RECV_LEN
 *	is set, the caller guarantees that this buffer can hold up to
 *	32 bytes in addition to the initial length byte sent by the
 *	slave (plus, if used, the SMBus PEC); and this value will be
 *	incremented by the number of block data bytes received.
 * @buf: The buffer into which data is read, or from which it's written.
 */
struct i2c_msg {
	uint8_t *buf;		/* pointer to msg data			*/
	uint8_t addr;	/* slave address			*/
	uint8_t flags;
#define I2C_M_RD		0x0001	/* read data, from slave to master */
					/* I2C_M_RD is guaranteed to be 0x0001! */
	uint8_t len;		/* msg length				*/
};
	
static uint8_t i2c_master_inited = 0;
static struct i2c_msg imsg;


/* --- setting states on the bus with the right timing: ---------------	*/

ALWAYS_INLINE void sdalo(void) {
  GPIO_DEV_I2C->DATAOUTCLR = DEV_SDA_MASK;
}

ALWAYS_INLINE void sdahi(void) {
  GPIO_DEV_I2C->DATAOUTSET = DEV_SDA_MASK;
}

ALWAYS_INLINE void scllo(void) {
  GPIO_DEV_I2C->DATAOUTCLR = DEV_SCL_MASK;
}

ALWAYS_INLINE void sclhi(void) {
  GPIO_DEV_I2C->DATAOUTSET = DEV_SCL_MASK;
}

/* --- other auxiliary functions --------------------------------------	*/
static void i2c_start(void) {
	/* assert: scl, sda are high */
	sdalo();
  delay_us(MAS_I2C_DELAY);
	scllo();
	delay_us(MAS_I2C_DELAY);
}

static void i2c_stop(void) {
	/* assert: scl is low */
	sdalo();
  delay_us(MAS_I2C_DELAY);
	sclhi();
  delay_us(MAS_I2C_DELAY);
	sdahi();
  delay_us(2*MAS_I2C_DELAY);
}

/* send a byte without start cond., look for arbitration,
 check ackn. from slave */
/* returns:
 * 1 if the device acknowledged
 * 0 if the device did not ack
 */
static int i2c_outb(uint8_t c) {
	int i;
	/* assert: scl is low */
	for (i = 7; i >= 0; i--) {
		if(((c >> i) & 0x01) != 0) 
			sdahi();
		else 
			sdalo();
		delay_us(DELAY_SDA_TO_SCLHI);
		sclhi();
		delay_us(MAS_I2C_DELAY_HALF);
		scllo();
		delay_us(MAS_I2C_DELAY_HALF);
	}
	sdahi();
	delay_us(DELAY_SDA_TO_SCLHI);
	sclhi();
	delay_us(MAS_I2C_DELAY_HALF);

	/* read ack: SDA should be pulled down by slave, or it may
	 * NAK (usually to report problems with the data we wrote).
	 */
	i = (GPIO_DEV_I2C->DATA & DEV_SDA_MASK) ? 0u : 1u; /* ack: sda is pulled low -> success */

	scllo();
	delay_us(MAS_I2C_DELAY_HALF);
	return i;
	/* assert: scl is low (sda undef) */
}

static uint8_t i2c_inb(void) {
	/* read byte via i2c port, without start/stop sequence	*/
	/* acknowledge is sent in i2c_read.			*/
	int i;
	uint8_t Temp_u8 = 0;

	/* assert: scl is low */
	sdahi();
	delay_us(MAS_I2C_DELAY_HALF);
	for (i = 0; i < 8; i++) {
		sclhi();
		delay_us(MAS_I2C_DELAY_HALF);
		Temp_u8 = (Temp_u8 << 1);
		if (GPIO_DEV_I2C->DATA & DEV_SDA_MASK)
			Temp_u8 |= 0x01;
		scllo();
		delay_us(MAS_I2C_DELAY_HALF);
//		udelay(i == 7 ? ADAP_DELAY / 2 : ADAP_DELAY);
	}
	/* assert: scl is low */
	return Temp_u8;
}

/*
 * Sanity check for the adapter hardware - check the reaction of
 * the bus lines only if it seems to be idle.
 */
static int test_bus(void) {

	//Testing bus SDA and SCL

	if ((GPIO_DEV_I2C->DATA & DEV_SDA_MASK) == 0) {
		//bus seems to be busy
		goto bailout;
	}

	sdalo();
	delay_us(MAS_I2C_DELAY_HALF);
	if (GPIO_DEV_I2C->DATA & DEV_SDA_MASK) {
		// SDA stuck high!
		goto bailout;
	}

	sdahi();
	delay_us(MAS_I2C_DELAY_HALF);
	if ((GPIO_DEV_I2C->DATA & DEV_SDA_MASK) == 0) {
		// SDA stuck low!
		goto bailout;
	}

	scllo();
	delay_us(MAS_I2C_DELAY_HALF);
	if ((GPIO_DEV_I2C->DATA & DEV_SDA_MASK) == 0) {
		// SDA unexpected low while pulling SCL low!
		goto bailout;
	}

	sclhi();
	delay_us(MAS_I2C_DELAY_HALF);
	if ((GPIO_DEV_I2C->DATA & DEV_SDA_MASK) == 0) {
		// SDA unexpected low while pulling SCL high!
		goto bailout;
	}

//	i2c_dbg("Test OK\n");
	return 0;

	bailout: //
	sclhi();
	delay_us(MAS_I2C_DELAY_HALF);
	sdahi();
	delay_us(MAS_I2C_DELAY_HALF);

	return -1;
}

/* ----- Utility functions
 */

/* try_address tries to contact a chip for a number of
 * times before it gives up.
 * return values:
 * 1 chip answered
 * 0 chip did not answer
 * -x transmission error
 */
static uint8_t try_address(uint8_t addr) {
	uint8_t Temp_count;
	uint8_t ret = 0;

	for (Temp_count = 0; Temp_count <= 3; Temp_count++) {
		ret = i2c_outb(addr);
		if (ret == 1 || Temp_count == 3)
			break;
		i2c_stop();
		delay_us(MAS_I2C_DELAY);
		i2c_start();
	}
	return ret;
}

static uint8_t sendbytes(struct i2c_msg *msg) {
	uint8_t Temp_count = 0;

	while (Temp_count < msg->len) {
		/* OK/ACK; or ignored NAK */
		if (i2c_outb(msg->buf[Temp_count]) > 0) {
			Temp_count++;

			/* A slave NAKing the master means the slave didn't like
			 * something about the data it saw.  For example, maybe
			 * the SMBus PEC was wrong.
			 */
		} else {
//			i2c_dbg("sendbytes: NAK bailout.\n");
			return 0;
		}
	}

	return msg->len;
}

static void acknak(int is_ack) {
	/* assert: sda is high */
	if (is_ack) { /* send ack */
		sdalo();
	}

	delay_us(MAS_I2C_DELAY_HALF);
	sclhi();
	delay_us(MAS_I2C_DELAY_HALF);
	scllo();
	delay_us(MAS_I2C_DELAY_HALF);
}

static uint8_t readbytes(struct i2c_msg *msg) {
	uint8_t Temp_count = 0;

	while (Temp_count < msg->len) {
		msg->buf[Temp_count] = i2c_inb();

		Temp_count++;

		acknak(msg->len-Temp_count);
	}
	return msg->len;
}

static uint8_t __i2c_xfer(void) {

	uint8_t Temp_u8;
	if (i2c_master_inited == 0) {
//		DRV_ERR("sfp i2c not inited");
		return 0;
	}

//	i2c_dbg("emitting start condition\n");
	i2c_start();
	Temp_u8 = imsg.addr & 0xFE;	//Clear bit0
	if (imsg.flags & I2C_M_RD)
		Temp_u8 |= 1;
	if (try_address(Temp_u8) != 1) {
		goto bailout;
	}
	if (imsg.flags & I2C_M_RD) {
		/* read bytes into buffer*/
		if (readbytes(&imsg) < imsg.len) {
			goto bailout;
		}
	} else {
		/* write bytes from buffer */
		if (sendbytes(&imsg) < imsg.len) {
			goto bailout;
		}
	}
	i2c_stop();
	return 1;

	bailout:
	i2c_stop();
	return 0;
}

//----------------------------------------------------------------------------
// Init: configure A0/A1 as GPIO open-drain with pullups
//----------------------------------------------------------------------------
int soft_i2c_master_init(void) {
	if (i2c_master_inited) {
		return -1;
	}

  // Take A0/A1 off the hardware-I2C alt function and back to plain GPIO.
  GPIO_DEV_I2C->ALTFUNCCLR = DEV_SCL_MASK | DEV_SDA_MASK;

  // Open-drain + pullup on both lines.
  GPIO_DEV_I2C->PULLMODE_bit.DEV_SCL_PIN = 0x1; // enable pullup [page 51] [page 212]
  GPIO_DEV_I2C->PULLMODE_bit.DEV_SDA_PIN = 0x1; // enable pullup [page 51] [page 212]
  GPIO_DEV_I2C->OUTMODE_bit.DEV_SCL_PIN = 0x1;  // open drain [page 51] [page 212]
  GPIO_DEV_I2C->OUTMODE_bit.DEV_SDA_PIN = 0x1 ; // open drain [page 51] [page 212]
  // SDA and SCL: OUTEN held set, DATAOUT high -> pin Hi-Z (released, line pulls high).
  GPIO_DEV_I2C->DATAOUTSET = DEV_SCL_MASK | DEV_SDA_MASK;       // SDA and SCL high
  GPIO_DEV_I2C->OUTENSET = DEV_SCL_MASK | DEV_SDA_MASK;   // allow to control port by DATAOUT [page 51] [page 213]
  GPIO_DEV_I2C->DENSET = DEV_SCL_MASK | DEV_SDA_MASK; // connect control to the physical port

	if (test_bus()) {
		//TODO set error
		return -1;
	}

	i2c_master_inited = 1;
	return 0;
}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
int Read_soft_i2c(uint8_t DevAddr, uint8_t RegAddr, uint8_t *buf, uint8_t size) {

	if(size > 128)
		size = 128;	//limit size of data
	memset(buf, 0, size);

	imsg.addr = DevAddr;
	imsg.buf = &RegAddr;
	imsg.len = 1;
	imsg.flags = 0;
	if (__i2c_xfer() != 1) {
		A2Up_Page.var.SMB_err_count++;
		return -1;
	}

	imsg.addr = DevAddr;
	imsg.buf = buf;
	imsg.len = size;
	imsg.flags = I2C_M_RD;

	if (__i2c_xfer() != 1) {
		A2Up_Page.var.SMB_err_count++;
		return -1;
	}

	return 0;
}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Reg address must be 1st byte of buffer
int Write_soft_i2c(uint8_t DevAddr, uint8_t *buf, uint8_t size) {

	if(size > 128)
		size = 128;	//limit size of data
	imsg.addr = DevAddr;
	imsg.buf = buf;
	imsg.len = size;
	imsg.flags = 0;

	if (__i2c_xfer() != 1) {
		A2Up_Page.var.SMB_err_count++;
		return -1;
	}

	return 0;
}
//-----------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif // __cplusplus
