/*==============================================================================
 * Перенаправление printf() в UART
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
#include "retarget_conf.h"
#include <stdio.h>

//-- Variables -----------------------------------------------------------------
extern uint32_t SystemCoreClock;

//-- Functions -----------------------------------------------------------------
void retarget_init()
{
#ifdef RETARGET
    uint32_t baud_icoef = SystemCoreClock / (16 * RETARGET_UART_BAUD);
    uint32_t baud_fcoef = ((SystemCoreClock / (16.0f * RETARGET_UART_BAUD) - baud_icoef) * 64 + 0.5f);

    RCU->HCLKCFG |= RETARGET_UART_PORT_EN;
    RCU->HRSTCFG |= RETARGET_UART_PORT_EN;
    RETARGET_UART_PORT->ALTFUNCSET = (1 << RETARGET_UART_PIN_TX_POS) | (1 << RETARGET_UART_PIN_RX_POS);
    RETARGET_UART_PORT->DENSET = (1 << RETARGET_UART_PIN_TX_POS) | (1 << RETARGET_UART_PIN_RX_POS);

    RCU->UARTCFG[RETARGET_UART_NUM].UARTCFG = (RCU_UARTCFG_UARTCFG_CLKSEL_PLLCLK << RCU_UARTCFG_UARTCFG_CLKSEL_Pos) |
                                              RCU_UARTCFG_UARTCFG_CLKEN_Msk |
                                              RCU_UARTCFG_UARTCFG_RSTDIS_Msk;
    RETARGET_UART->IBRD = baud_icoef;
    RETARGET_UART->FBRD = baud_fcoef;
    RETARGET_UART->LCRH = UART_LCRH_FEN_Msk | (3 << UART_LCRH_WLEN_Pos);
    RETARGET_UART->CR = UART_CR_TXE_Msk | UART_CR_RXE_Msk | UART_CR_UARTEN_Msk;
#endif //RETARGET
}

#ifdef RETARGET


static int retarget_get_char()
{
    while (RETARGET_UART->FR_bit.RXFE) {
    };
    return (int)RETARGET_UART->DR_bit.DATA;
}

static int retarget_put_char(int ch)
{
    while (RETARGET_UART->FR_bit.BUSY) {
    };
    RETARGET_UART->DR = ch;
    return 0;
}


#if defined(__GNUC__)

int _write(int fd, char* ptr, int len)
{
    int i = 0;

    while (ptr[i] && (i < len)) {
        retarget_put_char((int)ptr[i]);
        if (ptr[i] == '\n') {
            retarget_put_char((int)'\r');
        }
        i++;
    }

    return len;
}

void _ttywrch(int ch)
{
    retarget_put_char(ch);
}

int _read(int file, char* ptr, int len)
{
    int i = 0;

    for (/* Empty */; len > 0; --len) {
        char c = (char)retarget_get_char();
        *ptr++ = c;
        ++i;
        if (c == '\n')
            break;
    }

    return i;
}

#elif defined(__ICCARM__)

#include <yfuns.h>

size_t __write(int handle, const unsigned char* buffer, size_t size)
{
    size_t nChars = 0;

    if (buffer == 0) {
        return 0;
    }

    if (handle != _LLIO_STDOUT && handle != _LLIO_STDERR) {
        return _LLIO_ERROR;
    }

    for (; size != 0; --size) {
        if (retarget_put_char(*buffer++) < 0) {
            return _LLIO_ERROR;
        }

        ++nChars;
    }
    return nChars;
}

size_t __read(int handle, unsigned char* buffer, size_t size)
{
    int nChars = 0;

    if (handle != _LLIO_STDIN) {
        return _LLIO_ERROR;
    }

    for (; size > 0; --size) {
        int c = retarget_get_char();
        if (c < 0)
            break;

        *buffer++ = c;
        ++nChars;
    }

    return nChars;
}
#elif defined(__CC_ARM)

#include <stdio.h>
#include <rt_misc.h>

#pragma import(__use_no_semihosting_swi)

#ifdef __DBG_ITM
volatile int ITM_RxBuffer = ITM_RXBUFFER_EMPTY;  /*  CMSIS Debug Input        */
#endif


struct __FILE { int handle; /* Add whatever you need here */ };
FILE __stdout;
FILE __stdin;


int fputc(int c, FILE *f) {
#ifdef __DBG_ITM
    ITM_SendChar(c);
	  return 0;
#else	
  return (retarget_put_char(c));
#endif	
}


int fgetc(FILE *f) {
  return (retarget_get_char());
}


int ferror(FILE *f) {
  /* Your implementation of ferror */
  return EOF;
}


void _ttywrch(int c) {
#ifdef __DBG_ITM
    ITM_SendChar(c);
#else	
  retarget_put_char(c);
#endif	
}


void _sys_exit(int return_code) {
label:  goto label;  /* endless loop */
}

#endif  // __CC_ARM

#endif //RETARGET
