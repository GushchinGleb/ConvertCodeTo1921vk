/*==============================================================================
 * Простой пример с моргающим светодиодом.
 *------------------------------------------------------------------------------
 * НИИЭТ, Богдан Колбов <kolbov@niiet.ru>
 *==============================================================================
 * ДАННОЕ ПРОГРАММНОЕ ОБЕСПЕЧЕНИЕ ПРЕДОСТАВЛЯЕТСЯ «КАК ЕСТЬ», БЕЗ КАКИХ-ЛИБО
 * ГАРАНТИЙ, ЯВНО ВЫРАЖЕННЫХ ИЛИ ПОДРАЗУМЕВАЕМЫХ, ВКЛЮЧАЯ ГАРАНТИИ ТОВАРНОЙ
 * ПРИГОДНОСТИ, СООТВЕТСТВИЯ ПО ЕГО КОНКРЕТНОМУ НАЗНАЧЕНИЮ И ОТСУТСТВИЯ
 * НАРУШЕНИЙ, НО НЕ ОГРАНИЧИВАЯСЬ ИМИ. ДАННОЕ ПРОГРАММНОЕ ОБЕСПЕЧЕНИЕ
 * ПРЕДНАЗНАЧЕНО ДЛЯ ОЗНАКОМИТЕЛЬНЫХ ЦЕЛЕЙ И НАПРАВЛЕНО ТОЛЬКО НА
 * ПРЕДОСТАВЛЕНИЕ ДОПОЛНИТЕЛЬНОЙ ИНФОРМАЦИИ О ПРОДУКТЕ, С ЦЕЛЬЮ СОХРАНИТЬ ВРЕМЯ
 * ПОТРЕБИТЕЛЮ. НИ В КАКОМ СЛУЧАЕ АВТОРЫ ИЛИ ПРАВООБЛАДАТЕЛИ НЕ НЕСУТ
 * ОТВЕТСТВЕННОСТИ ПО КАКИМ-ЛИБО ИСКАМ, ЗА ПРЯМОЙ ИЛИ КОСВЕННЫЙ УЩЕРБ, ИЛИ
 * ПО ИНЫМ ТРЕБОВАНИЯМ, ВОЗНИКШИМ ИЗ-ЗА ИСПОЛЬЗОВАНИЯ ПРОГРАММНОГО ОБЕСПЕЧЕНИЯ
 * ИЛИ ИНЫХ ДЕЙСТВИЙ С ПРОГРАММНЫМ ОБЕСПЕЧЕНИЕМ.
 *
 *                              2018 АО "НИИЭТ"
 *==============================================================================
 */

//-- Includes ------------------------------------------------------------------
#include "K1921VK035.h"
#include "InternalFlashUtils.h"
#include "retarget_conf.h"

//-----------------------------------------------------------------------------
// Global Variables
//-----------------------------------------------------------------------------
A0_Page_t xdata A0_Page _at_ 0x0000;
A2_Page_t xdata A2_Page _at_ 0x0080;
A2Up_Page_t xdata A2Up_Page _at_ 0x0100;
//UpPage00_t xdata UpPage00 _at_ 0x0080;
//UpPage03_t xdata UpPage03 _at_ 0x0100;
//UpPage04_t xdata UpPage04 _at_ 0x0180;

// SMB variables
// SMB Rx buffer
uint8_t xdata SMB_DataIn[SMB_IN_BUF_SIZE+1];	//add additional byte because of last byte always read as 0xFF
// SMB Tx buffer
uint8_t xdata SMB_DataOut[SMB_OUT_BUF_SIZE+1];

uint8_t SMB_SlaveAddr;			// Target SMBus slave address
uint8_t SMB_NumBytes=0;			// Number of bytes for current SMBus operation (Wr or Rd)
volatile uint8_t SMB_protect_counter;
uint16_t SMB_ErrCount;			// Counter for the number of errors.

// I2C variables (slave SMB)
uint8_t I2C_Current_Address = 0;
uint8_t I2C_Current_Page = 0;
uint8_t xdata *I2C_Data_Pointer;
volatile bool I2C_Addr_write_flag = 0;
bool Mem_Pass_correct = 0;

//Timer variables
uint8_t Timer10ms_count = 0;		// Counter for 10ms timer
uint8_t Timer100ms_count = 0;		// Counter for 100ms timer
uint8_t Time_flags;					// Different flags of time intervals

//ADC variables
uint8_t ADC_stage = 0;

//Temp variables
uint8_t xdata Temp_page_data[128] _at_ 0x0180;
uint8_t xdata Temp_buffer[64];
uint8_t Temp_u8;
uint16_t i, Temp_u16;

//-- Defines -------------------------------------------------------------------

void Check_timer_interval(void);
void Init_variables(void);
uint8_t Check_Cfg_data_CSum(A2Up_Page_t *A2UpPtr);
uint8_t Check_CC_BASE_and_CC_EXT(uint8_t xdata *A0Low_ptr);
uint8_t Check_CC_DMI(uint8_t xdata *A2Low_ptr);
void Load_memory_from_Flash(void);
void Read_In_pins(void);
void Check_register_action(void);

//-- Main ----------------------------------------------------------------------
int main()
{
	Init_Peripherals();
	Init_variables();
	Load_memory_from_flash();
	Enable_global_inrerupts();
	Init_MASC_37029();
	
	printf("K1921VK035> All periph inited\n");
	printf("K1921VK035> CPU frequency is %.3f MHz\n", SystemCoreClock / 1E6);
	printf("K1921VK035> Start LED toogle ...\n");
	SysTick_Config(10000000);
	
	while (1) {
		Check_timer_interval();
		
		Check_register_action();
	};
}

void Check_timer_interval()
{
	if(Time_flags & TIME_100MS_FLAG) {
		//100 ms interval
		Time_flags &= ~TIME_100MS_FLAG;

		//Read input pins state
		Read_In_pins();
		//Work with ADC
		Work_with_MASC_ADC();

		//TEST
		TEST_PIN = ~TEST_PIN;

	}
	if(Time_flags & TIME_500MS_FLAG) {
		//500 ms interval
		Time_flags &= ~TIME_500MS_FLAG;

		//Read state of MASC
		Read_MASC_state();

	}
	if(Time_flags & TIME_1SEC_FLAG) {
		//1 second interval
		Time_flags &= ~TIME_1SEC_FLAG;

		//Read CPU temperature
		Read_temperature_sensor();

	}
}

//-- IRQ handlers --------------------------------------------------------------
void SysTick_Handler()
{
	BSP_LED_Toggle();
}
