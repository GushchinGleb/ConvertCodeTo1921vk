#ifndef RETARGET_CONF_H
#define RETARGET_CONF_H

#ifdef __cplusplus
extern "C" {
#endif

//-- Includes ------------------------------------------------------------------
#include <stdio.h>

//-- Defines -------------------------------------------------------------------
#define RETARGET_UART UART1
#define RETARGET_UART_NUM 1
#define RETARGET_UART_PORT GPIOB
#define RETARGET_UART_PORT_EN RCU_HCLKCFG_GPIOBEN_Msk
#define RETARGET_UART_PIN_TX_POS 8
#define RETARGET_UART_PIN_RX_POS 9
#define RETARGET_UART_RX_IRQHandler UART1_RX_IRQHandler
#define RETARGET_UART_RX_IRQn UART1_RX_IRQn

#ifndef RETARGET_UART_BAUD
#define RETARGET_UART_BAUD 115200
#endif

#ifndef RETARGET
#define printf(...) ((void)0)
#endif

//-- Functions -----------------------------------------------------------------
void retarget_init(void); 

#ifdef __cplusplus
}
#endif

#endif // RETARGET_CONF_H
