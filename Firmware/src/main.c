#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
	
#include <stdint.h>

#include "K1921VK035.h"

#include "../inc/board.h"
#include "../inc/eeprom_a0a2.h"
#include "../inc/flash_if.h"
#include "../inc/masc37029.h"
#include "../inc/i2c_master.h"
#include "../inc/sfp28.h"
#include "../inc/tick.h"

extern uint8_t Time_flags;
extern eep_page_t g_a0_low, g_a0_hi, g_a2_low, g_a2_hi;

static void gpio_init(void);
static void Check_timer_interval(void);
static void i2c_check(void);
static void periph_init(void);

//-----------------------------------------------------------------------------
// main() Routine
// ----------------------------------------------------------------------------
// Note: the software watchdog timer is not disabled by default in this
// example, so a long-running program will reset periodically unless
// the timer is disabled or your program periodically writes to it.
//
// Review the "Watchdog Timer" section under the part family's datasheet
// for details. To find the datasheet, select your part in the
// Simplicity Launcher and click on "Data Sheet".
//-----------------------------------------------------------------------------
int main (void) {
	//Dummy call to shut up linker warning
  SystemInit();

	//Init peripheral modules
	periph_init();

	//Init variables
	//Init_variables();

	//Load SFP28 module memory blocks from flash
  eep_pages_init_from_flash();
	
	i2c_check();

	//Init MASC-37029
	init_MASC_37029();

	//Check Global TxDisable
//	Check_TxDisable();

	while (1) {
		//Check timer intervals
		Check_timer_interval();

		//Check register action
		//Check_register_action();

		//Check flash page update action
//		Check_flash_page_action();

		//Work with interrupt flags
//		Work_with_interrupts();

		//Check Global TxDisable
//		Check_TxDisable();

	}
}

static void gpio_init(){
	// Pin A8
	#define GPIO_LED GPIOB
	#define PIN_LED PIN8
	#define LED_EN GPIOAEN
	
	
	RCU->HCLKCFG_bit.LED_EN = 1;
  RCU->HRSTCFG_bit.LED_EN = 1;
	
	GPIO_LED->DENSET_bit.PIN_LED  = 0x0; // push pull [page 212]
	GPIO_LED->OUTENSET_bit.PIN_LED = 0x1; // [page 51], [page 9]
	GPIO_LED->DATAOUTCLR_bit.PIN_LED = 1; // [page 51]
}

void Check_timer_interval() {
	if(Time_flags & TIME_100MS_FLAG) {
		//100 ms interval
		Time_flags &= ~TIME_100MS_FLAG;

		//Read input pins state
		//Read_In_pins();
		//Work with ADC
		//Work_with_MASC_ADC();
	}
	if(Time_flags & TIME_500MS_FLAG) {
		//500 ms interval
		Time_flags &= ~TIME_500MS_FLAG;

		//Read state of MASC
		//Read_MASC_state();

	}
	if(Time_flags & TIME_1SEC_FLAG) {
		//1 second interval
		Time_flags &= ~TIME_1SEC_FLAG;

		//Read CPU temperature
		//Read_temperature_sensor();

		//TEST
		GPIO_LED->DATAOUTTGL_bit.PIN_LED = 1; // [page 51]
	}
}

static void i2c_check(void) {
	const uint8_t SLAVE_ADDR = 0x50u;
	uint8_t tx_data[2] = {0x00, 0xAB};
	uint8_t rx_data[4];

	/* Write example */
	if (i2c_write_buffer(I2C, SLAVE_ADDR, tx_data, 2u) != I2C_DRV_OK) {
		/* error handling */
		while (1) 
			GPIO_LED->DATAOUTTGL_bit.PIN_LED = 1; // [page 51];
	}

	/* Read example */
	if (i2c_read_buffer(I2C, SLAVE_ADDR, rx_data, 4u) != I2C_DRV_OK) {
		/* error handling */
		while (1)
			GPIO_LED->DATAOUTTGL_bit.PIN_LED = 1; // [page 51];
	}

	while (1) {
		/* main loop */
	}
}


static void periph_init() {
	SystemCoreClockUpdate(); 

  gpio_init();
  tick_init(SystemCoreClock); // periodic timers

  i2c_init(I2C, SystemCoreClock, 100000u);
}

#ifdef __cplusplus
}
#endif // __cplusplus
