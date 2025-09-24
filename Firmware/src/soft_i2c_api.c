#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include <stdint.h>

#include "../inc/sfp28.h"

static uint8_t Mem_Pass_correct = 0;

uint8_t* I2C_Data_Pointer;

extern uint8_t Time_flags;
extern A0_Page_t A0_Page;
extern A2_Page_t A2_Page;
extern A2Up_Page_t A2Up_Page;

/**
 * @brief Write byte received from master it current address is allowed for writing
 * @param Byte[IN] - byte received from master
 * @param I2C_Current_Address[IN] the master send the byte to this address
 */
void I2C_Write_data(uint8_t Byte, uint8_t I2C_Current_Address) {
	// Check address for write capability
	if(I2C_Data_Pointer == (uint8_t *)&A0_Page) {
		//Work with A0 low page -> no available addresses

	} else if(I2C_Data_Pointer == (uint8_t *)&A2_Page) {
		//Work with A2 low page -> check writable address ranges
		if((I2C_Current_Address >= 120) && (I2C_Current_Address <= 127)) {
			A2_Page.Bytes[I2C_Current_Address] = Byte;
			//Create password value
			if((A2_Page.var.PassEntry[0] == PASS_CONST_B0) && (A2_Page.var.PassEntry[1] == PASS_CONST_B1) &&
					(A2_Page.var.PassEntry[2] == PASS_CONST_B2) && (A2_Page.var.PassEntry[3] == PASS_CONST_B3)) {
				Mem_Pass_correct = 1;
			} else {
				Mem_Pass_correct = 0;
			}
		}
	} else if(I2C_Data_Pointer == (uint8_t *)&A2Up_Page) {
		//Check password for writing
		if(Mem_Pass_correct == 1) {
			//Whole page is available for writing
			A2Up_Page.Bytes[I2C_Current_Address] = Byte;
		}
	}
}

/**
 * @brief Read byte from current address of selected page
 * @param I2C_Current_Address[IN] the master send the byte to this address
 */
uint8_t I2C_Read_data(uint8_t I2C_Current_Address) {
	uint8_t RdByte;
	// Check address for write capability
	if(I2C_Data_Pointer == (uint8_t *)&A2Up_Page) {
		//Check password for reading of Upper pages
		if(Mem_Pass_correct == 1) {
			//Pass is correct -> read byte
			RdByte = I2C_Data_Pointer[I2C_Current_Address];
		} else {
			//Pass is incorrect -> return zero
			RdByte = 0;
		}
	} else if(I2C_Data_Pointer == (uint8_t *)&A2_Page) {
		//A2 low page -> check password area
		if((I2C_Current_Address >= 123) && (I2C_Current_Address <= 126)) {
			//Password variables is write only -> return zero
			RdByte = 0;
		} else {
			RdByte = I2C_Data_Pointer[I2C_Current_Address];
		}
	} else {
		//Password is not used for other pages -> read data
		RdByte = I2C_Data_Pointer[I2C_Current_Address];
	}
	return RdByte;
}

uint8_t *I2C_Decode_page_address(uint8_t Address, uint8_t I2C_Current_Page) {
	//Default address is A0 page
	uint8_t *Pointer = (uint8_t *)&A0_Page;

	if(Address & 0x80) {
		//Upper address -> check current page and table select variable
		if((I2C_Current_Page == 0xA2) && (A2_Page.var.TableSelect == 0x80)) {
			//A2 page and table select is 0x80 -> select A2 Up page
			Pointer = (uint8_t *)&A2Up_Page;
		}
	} else {
		//Lower address -> check current page
		if(I2C_Current_Page == 0xA2)
			Pointer = (uint8_t *)&A2_Page;
	}

	return Pointer;
}

#ifdef __cplusplus
}
#endif // __cplusplus
