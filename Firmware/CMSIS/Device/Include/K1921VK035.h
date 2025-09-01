/*****************************************************************************
 * @file:    K1921VK035.h
 * @author   NIIET
 * @version: V1.4
 * @date:    15.03.2018
 * @brief:   K1921VK035 header file
 *****************************************************************************
 * <br><br>
 *
 * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
 * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
 * TIME. AS A RESULT, NIIET NOT BE HELD LIABLE FOR ANY DIRECT,
 * INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
 * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
 * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 *
 * <h2><center>&copy; COPYRIGHT 2018 NIIET </center></h2>
 *****************************************************************************
 * FILE K1921VK035.h
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __K1921VK035_H
#define __K1921VK035_H

#define __I     volatile const                /*!< defines 'read only' permissions      */
#define __O     volatile                      /*!< defines 'write only' permissions     */
#define __IO    volatile                      /*!< defines 'read / write' permissions   */

/* Start of section using anonymous unions */
#if defined (__CC_ARM)
  #pragma push
  #pragma anon_unions
#elif defined (__ICCARM__)
  #pragma language=extended
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic push
  #pragma clang diagnostic ignored "-Wc11-extensions"
  #pragma clang diagnostic ignored "-Wreserved-id-macro"
#elif defined (__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined (__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined (__TASKING__)
  #pragma warning 586
#elif defined (__CSMC__)
  /* anonymous unions are enabled by default */
#else
  #warning Not supported compiler type
#endif

/* Configuration of the Cortex-M4F Processor and Core Peripherals */
#define __CM4_REV            0x0001     /*!< Cortex-M4F Core Revision r0p1                */
#define __MPU_PRESENT             1     /*!< MPU present or not                           */
#define __NVIC_PRIO_BITS          3     /*!< Number of Bits used for Priority Levels      */
#define __Vendor_SysTickConfig    0     /*!< Set to 1 if different SysTick Config is used */
#define __FPU_PRESENT             1     /*!< FPU present or not                           */

#include "stdint.h"

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************/
/*                         Interrupt Number Definition                        */
/******************************************************************************/

typedef enum IRQn
{
/*-- Cortex-M4F Processor Exceptions Numbers ---------------------------------*/
  NonMaskableInt_IRQn     = -14,      /*!<  2 Non Maskable Interrupt          */
  HardFault_IRQn          = -13,      /*!<  3 Hard Fault Interrupt            */
  SVCall_IRQn             = -5,       /*!< 11 SV Call Interrupt               */
  PendSV_IRQn             = -2,       /*!< 14 Pend SV Interrupt               */
  SysTick_IRQn            = -1,       /*!< 15 System Tick Timer Interrupt     */
/*-- Device specific Interrupt Numbers ---------------------------------------*/
  WDT_IRQn                 =  0,      /*!< Watchdog timer interrupt           */
  RCU_IRQn                 =  1,      /*!< Reset and clock unit interrupt     */
  MFLASH_IRQn              =  2,      /*!< MFLASH interrupt                   */
  GPIOA_IRQn               =  3,      /*!< GPIO A interrupt                   */
  GPIOB_IRQn               =  4,      /*!< GPIO B interrupt                   */
  DMA_CH0_IRQn             =  5,      /*!< DMA channel 0 interrupt            */
  DMA_CH1_IRQn             =  6,      /*!< DMA channel 1 interrupt            */
  DMA_CH2_IRQn             =  7,      /*!< DMA channel 2 interrupt            */
  DMA_CH3_IRQn             =  8,      /*!< DMA channel 3 interrupt            */
  DMA_CH4_IRQn             =  9,      /*!< DMA channel 4 interrupt            */
  DMA_CH5_IRQn             =  10,     /*!< DMA channel 5 interrupt            */
  DMA_CH6_IRQn             =  11,     /*!< DMA channel 6 interrupt            */
  DMA_CH7_IRQn             =  12,     /*!< DMA channel 7 interrupt            */
  DMA_CH8_IRQn             =  13,     /*!< DMA channel 8 interrupt            */
  DMA_CH9_IRQn             =  14,     /*!< DMA channel 9 interrupt            */
  DMA_CH10_IRQn            =  15,     /*!< DMA channel 10 interrupt           */
  DMA_CH11_IRQn            =  16,     /*!< DMA channel 11 interrupt           */
  DMA_CH12_IRQn            =  17,     /*!< DMA channel 12 interrupt           */
  DMA_CH13_IRQn            =  18,     /*!< DMA channel 13 interrupt           */
  DMA_CH14_IRQn            =  19,     /*!< DMA channel 14 interrupt           */
  DMA_CH15_IRQn            =  20,     /*!< DMA channel 15 interrupt           */
  TMR0_IRQn                =  21,     /*!< Timer 0 interrupt                  */
  TMR1_IRQn                =  22,     /*!< Timer 1 interrupt                  */
  TMR2_IRQn                =  23,     /*!< Timer 2 interrupt                  */
  TMR3_IRQn                =  24,     /*!< Timer 3 interrupt                  */
  UART0_TD_IRQn            =  25,     /*!< UART0 Transmit Done interrupt      */
  UART0_RX_IRQn            =  26,     /*!< UART0 Recieve interrupt            */
  UART0_TX_IRQn            =  27,     /*!< UART0 Transmit interrupt           */
  UART0_IRQn               =  28,     /*!< UART0 interrupt                    */
  UART1_TD_IRQn            =  29,     /*!< UART1 Transmit Done interrupt      */
  UART1_RX_IRQn            =  30,     /*!< UART1 Recieve interrupt            */
  UART1_TX_IRQn            =  31,     /*!< UART1 Transmit interrupt           */
  UART1_IRQn               =  32,     /*!< UART1 interrupt                    */
  SPI_IRQn                 =  33,     /*!< SPI interrupt                      */
  SPI_RX_IRQn              =  34,     /*!< SPI Receive interrupt              */
  SPI_TX_IRQn              =  35,     /*!< SPI Transmit interrupt             */
  I2C_IRQn                 =  36,     /*!< I2C interrupt                      */
  ECAP0_IRQn               =  37,     /*!< ECAP0 interrupt                    */
  ECAP1_IRQn               =  38,     /*!< ECAP1 interrupt                    */
  ECAP2_IRQn               =  39,     /*!< ECAP2 interrupt                    */
  PWM0_IRQn                =  40,     /*!< PWM0 interrupt                     */
  PWM0_HD_IRQn             =  41,     /*!< PWM0 HD interrupt                  */
  PWM0_TZ_IRQn             =  42,     /*!< PWM0 TZ interrupt                  */
  PWM1_IRQn                =  43,     /*!< PWM1 interrupt                     */
  PWM1_HD_IRQn             =  44,     /*!< PWM1 HD interrupt                  */
  PWM1_TZ_IRQn             =  45,     /*!< PWM1 TZ interrupt                  */
  PWM2_IRQn                =  46,     /*!< PWM2 interrupt                     */
  PWM2_HD_IRQn             =  47,     /*!< PWM2 HD interrupt                  */
  PWM2_TZ_IRQn             =  48,     /*!< PWM2 TZ interrupt                  */
  QEP_IRQn                 =  49,     /*!< QEP interrupt                      */
  ADC_SEQ0_IRQn            =  50,     /*!< ADC Sequencer 0 interrupt          */
  ADC_SEQ1_IRQn            =  51,     /*!< ADC Sequencer 1 interrupt          */
  ADC_DC_IRQn              =  52,     /*!< ADC Digital Comparator interrupt   */
  CAN0_IRQn                =  53,     /*!< CAN0 interrupt                     */
  CAN1_IRQn                =  54,     /*!< CAN1 interrupt                     */
  CAN2_IRQn                =  55,     /*!< CAN2 interrupt                     */
  CAN3_IRQn                =  56,     /*!< CAN3 interrupt                     */
  CAN4_IRQn                =  57,     /*!< CAN4 interrupt                     */
  CAN5_IRQn                =  58,     /*!< CAN5 interrupt                     */
  CAN6_IRQn                =  59,     /*!< CAN6 interrupt                     */
  CAN7_IRQn                =  60,     /*!< CAN7 interrupt                     */
  CAN8_IRQn                =  61,     /*!< CAN8 interrupt                     */
  CAN9_IRQn                =  62,     /*!< CAN9 interrupt                     */
  CAN10_IRQn               =  63,     /*!< CAN10 interrupt                    */
  CAN11_IRQn               =  64,     /*!< CAN11 interrupt                    */
  CAN12_IRQn               =  65,     /*!< CAN12 interrupt                    */
  CAN13_IRQn               =  66,     /*!< CAN13 interrupt                    */
  CAN14_IRQn               =  67,     /*!< CAN14 interrupt                    */
  CAN15_IRQn               =  68,     /*!< CAN15 interrupt                    */
  FPU_IRQn                 =  69,     /*!< FPU exception interrupt            */
} IRQn_Type;

#include <core_cm4.h>                 /* Cortex-M4 processor and core peripherals */
#include <system_K1921VK035.h>        /* System initialization                    */

/******************************************************************************/
/*                         System Specific Defenitions                        */
/******************************************************************************/

/*--  CHANNEL_CFG: DMA channel configure word ------------------------------------------------------------*/
typedef struct {
    uint32_t CYCLE_CTRL           : 3;                               /*!< The operating mode of the DMA cycle */
    uint32_t NEXT_USEBURST        : 1;                               /*!< Controls if the DMA->USEBURSTSET bit is set to a 1 */
    uint32_t N_MINUS_1            : 10;                              /*!< The total number of DMA transfers that the DMA cycle contains */
    uint32_t R_POWER              : 4;                               /*!< Control how many DMA transfers can occur before the controller rearbitrates (2^R_POWER, 1024 max) */
    uint32_t SRC_PROT_PRIV        : 1;                               /*!< Bus protection when the controller reads the source data: privileged access */
    uint32_t SRC_PROT_BUFF        : 1;                               /*!< Bus protection when the controller reads the source data: bufferable access */
    uint32_t SRC_PROT_CACHE       : 1;                               /*!< Bus protection when the controller reads the source data: cacheable access */
    uint32_t DST_PROT_PRIV        : 1;                               /*!< Bus protection when the controller writes the destination data: privileged access */
    uint32_t DST_PROT_BUFF        : 1;                               /*!< Bus protection when the controller writes the destination data: bufferable access */
    uint32_t DST_PROT_CACHE       : 1;                               /*!< Bus protection when the controller writes the destination data: cacheable access */
    uint32_t SRC_SIZE             : 2;                               /*!< Size of the source data */
    uint32_t SRC_INC              : 2;                               /*!< Source address increment */
    uint32_t DST_SIZE             : 2;                               /*!< Destination data size */
    uint32_t DST_INC              : 2;                               /*!< Destination address increment */
} _CHANNEL_CFG_bits;

/* Bit field positions: */
#define DMA_CHANNEL_CFG_CYCLE_CTRL_Pos        0                      /*!< The operating mode of the DMA cycle */
#define DMA_CHANNEL_CFG_NEXT_USEBURST_Pos     3                      /*!< Controls if the DMA->USEBURSTSET bit is set to a 1 */
#define DMA_CHANNEL_CFG_N_MINUS_1_Pos         4                      /*!< The total number of DMA transfers that the DMA cycle contains */
#define DMA_CHANNEL_CFG_R_POWER_Pos           14                     /*!< Control how many DMA transfers can occur before the controller rearbitrates */
#define DMA_CHANNEL_CFG_SRC_PROT_PRIV_Pos     18                     /*!< Bus protection when the controller reads the source data: privileged access */
#define DMA_CHANNEL_CFG_SRC_PROT_BUFF_Pos     19                     /*!< Bus protection when the controller reads the source data: bufferable access */
#define DMA_CHANNEL_CFG_SRC_PROT_CACHE_Pos    20                     /*!< Bus protection when the controller reads the source data: cacheable access */
#define DMA_CHANNEL_CFG_DST_PROT_PRIV_Pos     21                     /*!< Bus protection when the controller writes the destination data: privileged access */
#define DMA_CHANNEL_CFG_DST_PROT_BUFF _Pos    22                     /*!< Bus protection when the controller writes the destination data: bufferable access */
#define DMA_CHANNEL_CFG_DST_PROT_CACHE_Pos    23                     /*!< Bus protection when the controller writes the destination data: cacheable access */
#define DMA_CHANNEL_CFG_SRC_SIZE_Pos          24                     /*!< Size of the source data */
#define DMA_CHANNEL_CFG_SRC_INC_Pos           26                     /*!< Source address increment */
#define DMA_CHANNEL_CFG_DST_SIZE_Pos          28                     /*!< Destination data size */
#define DMA_CHANNEL_CFG_DST_INC_Pos           30                     /*!< Destination address increment */

/* Bit field masks: */
#define DMA_CHANNEL_CFG_CYCLE_CTRL_Msk        0x00000007             /*!< The operating mode of the DMA cycle */
#define DMA_CHANNEL_CFG_NEXT_USEBURST_Msk     0x00000008             /*!< Controls if the DMA->USEBURSTSET bit is set to a 1 */
#define DMA_CHANNEL_CFG_N_MINUS_1_Msk         0x00003FF0             /*!< The total number of DMA transfers that the DMA cycle contains */
#define DMA_CHANNEL_CFG_R_POWER_Msk           0x0003C000             /*!< Control how many DMA transfers can occur before the controller rearbitrates */
#define DMA_CHANNEL_CFG_SRC_PROT_PRIV_Msk     0x00040000             /*!< Bus protection when the controller reads the source data: privileged access */
#define DMA_CHANNEL_CFG_SRC_PROT_BUFF_Msk     0x00080000             /*!< Bus protection when the controller reads the source data: bufferable access */
#define DMA_CHANNEL_CFG_SRC_PROT_CACHE_Msk    0x00100000             /*!< Bus protection when the controller reads the source data: cacheable access */
#define DMA_CHANNEL_CFG_DST_PROT_PRIV_Msk     0x00200000             /*!< Bus protection when the controller writes the destination data: privileged access */
#define DMA_CHANNEL_CFG_DST_PROT_BUFF_Msk     0x00400000             /*!< Bus protection when the controller writes the destination data: bufferable access */
#define DMA_CHANNEL_CFG_DST_PROT_CACHE_Msk    0x00800000             /*!< Bus protection when the controller writes the destination data: cacheable access */
#define DMA_CHANNEL_CFG_SRC_SIZE_Msk          0x03000000             /*!< Size of the source data */
#define DMA_CHANNEL_CFG_SRC_INC_Msk           0x0C000000             /*!< Source address increment */
#define DMA_CHANNEL_CFG_DST_SIZE_Msk          0x30000000             /*!< Destination data size */
#define DMA_CHANNEL_CFG_DST_INC_Msk           0xC0000000             /*!< Destination address increment */

/* Bit field enums: */
typedef enum {
  DMA_CHANNEL_CFG_CYCLE_CTRL_Stop                    = 0x0,          /*!< Stop */
  DMA_CHANNEL_CFG_CYCLE_CTRL_Basic                   = 0x1,          /*!< Basic */
  DMA_CHANNEL_CFG_CYCLE_CTRL_AutoReq                 = 0x2,          /*!< Auto-request */
  DMA_CHANNEL_CFG_CYCLE_CTRL_PingPong                = 0x3,          /*!< Ping-pong */
  DMA_CHANNEL_CFG_CYCLE_CTRL_MemScatGathPrim         = 0x4,          /*!< Memory scatter-gather for primary structure */
  DMA_CHANNEL_CFG_CYCLE_CTRL_MemScatGathAlt          = 0x5,          /*!< Memory scatter-gather for alternative structure */
  DMA_CHANNEL_CFG_CYCLE_CTRL_PeriphScatGathPrim      = 0x6,          /*!< Peripheral scatter-gather for primary structure */
  DMA_CHANNEL_CFG_CYCLE_CTRL_PeriphScatGathAlt       = 0x7,          /*!< Peripheral scatter-gather for alternative structure */
} DMA_CHANNEL_CFG_CYCLE_CTRL_Enum;

typedef enum {
  DMA_CHANNEL_CFG_SRC_SIZE_Byte                      = 0x0,          /*!< 8 bit */
  DMA_CHANNEL_CFG_SRC_SIZE_Halfword                  = 0x1,          /*!< 16 bit */
  DMA_CHANNEL_CFG_SRC_SIZE_Word                      = 0x2,          /*!< 32 bit */
} DMA_CHANNEL_CFG_SRC_SIZE_Enum;

typedef enum {
  DMA_CHANNEL_CFG_SRC_INC_Byte                       = 0x0,          /*!< 8 bit */
  DMA_CHANNEL_CFG_SRC_INC_Halfword                   = 0x1,          /*!< 16 bit */
  DMA_CHANNEL_CFG_SRC_INC_Word                       = 0x2,          /*!< 32 bit */
  DMA_CHANNEL_CFG_SRC_INC_None                       = 0x3,          /*!< No increment */
} DMA_CHANNEL_CFG_SRC_INC_Enum;

typedef enum {
  DMA_CHANNEL_CFG_DST_SIZE_Byte                      = 0x0,          /*!< 8 bit */
  DMA_CHANNEL_CFG_DST_SIZE_Halfword                  = 0x1,          /*!< 16 bit */
  DMA_CHANNEL_CFG_DST_SIZE_Word                      = 0x2,          /*!< 32 bit */
} DMA_CHANNEL_CFG_DST_SIZE_Enum;

typedef enum {
  DMA_CHANNEL_CFG_DST_INC_Byte                       = 0x0,          /*!< 8 bit */
  DMA_CHANNEL_CFG_DST_INC_Halfword                   = 0x1,          /*!< 16 bit */
  DMA_CHANNEL_CFG_DST_INC_Word                       = 0x2,          /*!< 32 bit */
  DMA_CHANNEL_CFG_DST_INC_None                       = 0x3,          /*!< No increment */
} DMA_CHANNEL_CFG_DST_INC_Enum;


/*--  DMA channel structure ------------------------------------------------------------------------------*/
typedef struct
{
    uint32_t SRC_DATA_END_PTR;                                       /*!< Source data end pointer */
    uint32_t DST_DATA_END_PTR;                                       /*!< Destination data end pointer */
    union {
        uint32_t CHANNEL_CFG;                                        /*!< Channel configure word */
        _CHANNEL_CFG_bits CHANNEL_CFG_bit;                           /*!< channel configure word: bit access */
    };
    uint32_t RESERVED;
} DMA_Channel_TypeDef;

/*--  DMA control structure ------------------------------------------------------------------------------*/
typedef struct
{
    DMA_Channel_TypeDef CH[16];                                      /*!< Control structure channels */
} DMA_CtrlStruct_TypeDef;

#define DMA_CH_UART0TX                        0                      /*!< UART0 TX DMA channel */
#define DMA_CH_UART1TX                        1                      /*!< UART1 TX DMA channel */
#define DMA_CH_UART0RX                        2                      /*!< UART0 RX DMA channel */
#define DMA_CH_UART1RX                        3                      /*!< UART1 RX DMA channel */
#define DMA_CH_ADCSEQ0                        4                      /*!< ADC sequencer 0 DMA channel */
#define DMA_CH_ADCSEQ1                        5                      /*!< ADC sequencer 1 DMA channel */
#define DMA_CH_SPITX                          6                      /*!< SPI TX DMA channel */
#define DMA_CH_SPIRX                          7                      /*!< SPI RX DMA channel */
#define DMA_CH_QEP                            8                      /*!< QEP DMA channel */
#define DMA_CH_GPIOA                          8                      /*!< GPIOA DMA channel */
#define DMA_CH_GPIOB                          9                      /*!< GPIOB DMA channel */
#define DMA_CH_TMR0                           9                      /*!< TMR0 DMA channel */
#define DMA_CH_TMR1                           10                     /*!< TMR1 DMA channel */
#define DMA_CH_TMR2                           11                     /*!< TMR2 DMA channel */
#define DMA_CH_TMR3                           12                     /*!< TMR3 DMA channel */
#define DMA_CH_PWM0B                          10                     /*!< PWM0B DMA channel */
#define DMA_CH_PWM1B                          11                     /*!< PWM1B DMA channel */
#define DMA_CH_PWM2B                          12                     /*!< PWM2B DMA channel */
#define DMA_CH_PWM0A                          13                     /*!< PWM0A DMA channel */
#define DMA_CH_PWM1A                          14                     /*!< PWM1A DMA channel */
#define DMA_CH_PWM2A                          15                     /*!< PWM2A DMA channel */

/*--  DMA control data summary ---------------------------------------------------------------------------*/
/*!< WARNING: struct should be 1024 byte aligned! Allowed addresses 0xXXXXX000, 0xXXXXX400, 0xXXXXX800, 0xXXXXXC00 */
typedef struct
{
    DMA_CtrlStruct_TypeDef PRM_DATA;                               /*!< Primary control structure */
    uint32_t RESERVED0[64];                                          /*!< RESERVED */
    DMA_CtrlStruct_TypeDef ALT_DATA;                               /*!< Alternative control structure */
    uint32_t RESERVED1[64];                                          /*!< RESERVED */
} DMA_CtrlData_TypeDef;

/******************************************************************************/
/*                         SIU registers                                      */
/******************************************************************************/

/*--  PWMSYNC: PWM syncronization control register ------------------------------------------------------------*/
typedef struct {
  uint32_t                        :2;                                /*!< RESERVED */
  uint32_t SWSYNC                 :1;                                /*!< SYNCI pulse software emulation  on PWM0 */
  uint32_t                        :5;                                /*!< RESERVED */
  uint32_t PRESCRST               :3;                                /*!< PWM prescalers reset control */
} _SIU_PWMSYNC_bits;

/* Bit field positions: */
#define SIU_PWMSYNC_SWSYNC_Pos                2                      /*!< SYNCI pulse software emulation  on PWM0 */
#define SIU_PWMSYNC_PRESCRST_Pos              8                      /*!< PWM prescalers reset control */

/* Bit field masks: */
#define SIU_PWMSYNC_SWSYNC_Msk                0x00000004             /*!< SYNCI pulse software emulation  on PWM0 */
#define SIU_PWMSYNC_PRESCRST_Msk              0x00000700             /*!< PWM prescalers reset control */

/*--  SERVCTL: Service mode control register ------------------------------------------------------------------*/
typedef struct {
  uint32_t CHIPCLR                :1;                                /*!< On-chip memories full clear task start */
  uint32_t DONE                   :1;                                /*!< Status of clear task */
  uint32_t                        :29;                               /*!< RESERVED */
  uint32_t SERVEN                 :1;                                /*!<  */
} _SIU_SERVCTL_bits;

/* Bit field positions: */
#define SIU_SERVCTL_CHIPCLR_Pos               0                      /*!< On-chip memories full clear task start */
#define SIU_SERVCTL_DONE_Pos                  1                      /*!< Status of clear task */
#define SIU_SERVCTL_SERVEN_Pos                31                     /*!<  */

/* Bit field masks: */
#define SIU_SERVCTL_CHIPCLR_Msk               0x00000001             /*!< On-chip memories full clear task start */
#define SIU_SERVCTL_DONE_Msk                  0x00000002             /*!< Status of clear task */
#define SIU_SERVCTL_SERVEN_Msk                0x80000000             /*!<  */

/*--  CLKOUTCTL: Clock out control register -------------------------------------------------------------------*/
typedef struct {
  uint32_t CLKOUTEN               :1;                                /*!< Enable clockout pin */
} _SIU_CLKOUTCTL_bits;

/* Bit field positions: */
#define SIU_CLKOUTCTL_CLKOUTEN_Pos            0                      /*!< Enable clockout pin */

/* Bit field masks: */
#define SIU_CLKOUTCTL_CLKOUTEN_Msk            0x00000001             /*!< Enable clockout pin */

/*--  REMAPAF: QEP altfunc control ----------------------------------------------------------------------------*/
typedef struct {
  uint32_t QEPEN                  :1;                                /*!< Enable QEP altfunc */
  uint32_t ECAP0EN                :1;                                /*!< Enable ECAP0 altfunc */
  uint32_t ECAP1EN                :1;                                /*!< Enable ECAP1 altfunc */
  uint32_t ECAP2EN                :1;                                /*!< Enable ECAP2 altfunc */
} _SIU_REMAPAF_bits;

/* Bit field positions: */
#define SIU_REMAPAF_QEPEN_Pos                 0                      /*!< Enable QEP altfunc */
#define SIU_REMAPAF_ECAP0EN_Pos               1                      /*!< Enable ECAP0 altfunc */
#define SIU_REMAPAF_ECAP1EN_Pos               2                      /*!< Enable ECAP1 altfunc */
#define SIU_REMAPAF_ECAP2EN_Pos               3                      /*!< Enable ECAP2 altfunc */

/* Bit field masks: */
#define SIU_REMAPAF_QEPEN_Msk                 0x00000001             /*!< Enable QEP altfunc */
#define SIU_REMAPAF_ECAP0EN_Msk               0x00000002             /*!< Enable ECAP0 altfunc */
#define SIU_REMAPAF_ECAP1EN_Msk               0x00000004             /*!< Enable ECAP1 altfunc */
#define SIU_REMAPAF_ECAP2EN_Msk               0x00000008             /*!< Enable ECAP2 altfunc */

/*--  DMAMUX: DMA external requests mux control register ------------------------------------------------------*/
typedef struct {
  uint32_t SRCSEL8                :1;                                /*!< Request source select for DMA channel 8 */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t SRCSEL9                :1;                                /*!< Request source select for DMA channel 9 */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t SRCSEL10               :1;                                /*!< Request source select for DMA channel 10 */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t SRCSEL11               :1;                                /*!< Request source select for DMA channel 11 */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t SRCSEL12               :1;                                /*!< Request source select for DMA channel 12 */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t SRCSEL13               :1;                                /*!< Request source select for DMA channel 13 */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t SRCSEL14               :1;                                /*!< Request source select for DMA channel 14 */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t SRCSEL15               :1;                                /*!< Request source select for DMA channel 15 */
} _SIU_DMAMUX_bits;

/* Bit field positions: */
#define SIU_DMAMUX_SRCSEL8_Pos                0                      /*!< Request source select for DMA channel 8 */
#define SIU_DMAMUX_SRCSEL9_Pos                4                      /*!< Request source select for DMA channel 9 */
#define SIU_DMAMUX_SRCSEL10_Pos               8                      /*!< Request source select for DMA channel 10 */
#define SIU_DMAMUX_SRCSEL11_Pos               12                     /*!< Request source select for DMA channel 11 */
#define SIU_DMAMUX_SRCSEL12_Pos               16                     /*!< Request source select for DMA channel 12 */
#define SIU_DMAMUX_SRCSEL13_Pos               20                     /*!< Request source select for DMA channel 13 */
#define SIU_DMAMUX_SRCSEL14_Pos               24                     /*!< Request source select for DMA channel 14 */
#define SIU_DMAMUX_SRCSEL15_Pos               28                     /*!< Request source select for DMA channel 15 */

/* Bit field masks: */
#define SIU_DMAMUX_SRCSEL8_Msk                0x00000001             /*!< Request source select for DMA channel 8 */
#define SIU_DMAMUX_SRCSEL9_Msk                0x00000010             /*!< Request source select for DMA channel 9 */
#define SIU_DMAMUX_SRCSEL10_Msk               0x00000100             /*!< Request source select for DMA channel 10 */
#define SIU_DMAMUX_SRCSEL11_Msk               0x00001000             /*!< Request source select for DMA channel 11 */
#define SIU_DMAMUX_SRCSEL12_Msk               0x00010000             /*!< Request source select for DMA channel 12 */
#define SIU_DMAMUX_SRCSEL13_Msk               0x00100000             /*!< Request source select for DMA channel 13 */
#define SIU_DMAMUX_SRCSEL14_Msk               0x01000000             /*!< Request source select for DMA channel 14 */
#define SIU_DMAMUX_SRCSEL15_Msk               0x10000000             /*!< Request source select for DMA channel 15 */

/* Bit field enums: */
typedef enum {
  SIU_DMAMUX_SRCSEL8_QEP                     = 0x0,                  /*!< request by QEP */
  SIU_DMAMUX_SRCSEL8_GPIOA                   = 0x1,                  /*!< request by GPIOA */
} SIU_DMAMUX_SRCSEL8_Enum;

typedef enum {
  SIU_DMAMUX_SRCSEL9_TMR0                    = 0x0,                  /*!< request by TMR0 */
  SIU_DMAMUX_SRCSEL9_GPIOB                   = 0x1,                  /*!< request by GPIOB */
} SIU_DMAMUX_SRCSEL9_Enum;

typedef enum {
  SIU_DMAMUX_SRCSEL10_TMR1                   = 0x0,                  /*!< request by TMR1 */
  SIU_DMAMUX_SRCSEL10_PWM0B                  = 0x1,                  /*!< request by PWM0B */
} SIU_DMAMUX_SRCSEL10_Enum;

typedef enum {
  SIU_DMAMUX_SRCSEL11_TMR2                   = 0x0,                  /*!< request by TMR2 */
  SIU_DMAMUX_SRCSEL11_PWM1B                  = 0x1,                  /*!< request by PWM1B */
} SIU_DMAMUX_SRCSEL11_Enum;

typedef enum {
  SIU_DMAMUX_SRCSEL12_TMR3                   = 0x0,                  /*!< request by TMR3 */
  SIU_DMAMUX_SRCSEL12_PWM2B                  = 0x1,                  /*!< request by PWM2B */
} SIU_DMAMUX_SRCSEL12_Enum;

typedef enum {
  SIU_DMAMUX_SRCSEL13_PWM0A                  = 0x0,                  /*!< request by PWM0A */
  SIU_DMAMUX_SRCSEL13_Reserved               = 0x1,                  /*!< no source */
} SIU_DMAMUX_SRCSEL13_Enum;

typedef enum {
  SIU_DMAMUX_SRCSEL14_PWM1A                  = 0x0,                  /*!< request by PWM1A */
  SIU_DMAMUX_SRCSEL14_Reserved               = 0x1,                  /*!< no source */
} SIU_DMAMUX_SRCSEL14_Enum;

typedef enum {
  SIU_DMAMUX_SRCSEL15_PWM2A                  = 0x0,                  /*!< request by PWM2A */
  SIU_DMAMUX_SRCSEL15_Reserved               = 0x1,                  /*!< no source */
} SIU_DMAMUX_SRCSEL15_Enum;

/*--  CHIPID: Chip identifier ---------------------------------------------------------------------------------*/
typedef struct {
  uint32_t REV                    :4;                                /*!< Revision number */
  uint32_t ID                     :28;                               /*!< Model ID */
} _SIU_CHIPID_bits;

/* Bit field positions: */
#define SIU_CHIPID_REV_Pos                    0                      /*!< Revision number */
#define SIU_CHIPID_ID_Pos                     4                      /*!< Model ID */

/* Bit field masks: */
#define SIU_CHIPID_REV_Msk                    0x0000000F             /*!< Revision number */
#define SIU_CHIPID_ID_Msk                     0xFFFFFFF0             /*!< Model ID */

typedef struct {
    __IO uint32_t Reserved0[4];
  union {                                                               /*!< PWM syncronization control register */
    __IO uint32_t PWMSYNC;                                           /*!< PWMSYNC    : type used for word access */
    __IO _SIU_PWMSYNC_bits  PWMSYNC_bit;                             /*!< PWMSYNC_bit: structure used for bit access */
  };
  union {                                                               /*!< Service mode control register */
    __IO uint32_t SERVCTL;                                           /*!< SERVCTL    : type used for word access */
    __IO _SIU_SERVCTL_bits  SERVCTL_bit;                             /*!< SERVCTL_bit: structure used for bit access */
  };
  union {                                                               /*!< Clock out control register */
    __IO uint32_t CLKOUTCTL;                                           /*!< CLKOUTCTL    : type used for word access */
    __IO _SIU_CLKOUTCTL_bits  CLKOUTCTL_bit;                         /*!< CLKOUTCTL_bit: structure used for bit access */
  };
  union {                                                               /*!< QEP altfunc control */
    __IO uint32_t REMAPAF;                                           /*!< REMAPAF    : type used for word access */
    __IO _SIU_REMAPAF_bits  REMAPAF_bit;                             /*!< REMAPAF_bit: structure used for bit access */
  };
  union {                                                               /*!< DMA external requests mux control register */
    __IO uint32_t DMAMUX;                                            /*!< DMAMUX    : type used for word access */
    __IO _SIU_DMAMUX_bits  DMAMUX_bit;                               /*!< DMAMUX_bit: structure used for bit access */
  };
    __IO uint32_t Reserved1[1014];
  union {                                                               /*!< Chip identifier */
    __I uint32_t CHIPID;                                             /*!< CHIPID    : type used for word access */
    __I _SIU_CHIPID_bits  CHIPID_bit;                                /*!< CHIPID_bit: structure used for bit access */
  };
} SIU_TypeDef;

/******************************************************************************/
/*                         RCU registers                                      */
/******************************************************************************/

/*--  OSICFG: Internal oscillator configuration register ------------------------------------------------------*/
typedef struct {
  uint32_t EN                     :1;                                /*!< Oscillator 8MHz enable */
  uint32_t                        :15;                               /*!< RESERVED */
  uint32_t CAL                    :10;                               /*!< Oscillator 8MHz calibration value */
} _RCU_OSICFG_bits;

/* Bit field positions: */
#define RCU_OSICFG_EN_Pos                     0                      /*!< Oscillator 8MHz enable */
#define RCU_OSICFG_CAL_Pos                    16                     /*!< Oscillator 8MHz calibration value */

/* Bit field masks: */
#define RCU_OSICFG_EN_Msk                     0x00000001             /*!< Oscillator 8MHz enable */
#define RCU_OSICFG_CAL_Msk                    0x03FF0000             /*!< Oscillator 8MHz calibration value */

/*--  OSECFG: External oscillator configuration register ------------------------------------------------------*/
typedef struct {
  uint32_t XOEN                   :1;                                /*!< Enable output XO_OSC from external oscillator */
  uint32_t EN                     :1;                                /*!< Enable external oscallator */
} _RCU_OSECFG_bits;

/* Bit field positions: */
#define RCU_OSECFG_XOEN_Pos                   0                      /*!< Enable output XO_OSC from external oscillator */
#define RCU_OSECFG_EN_Pos                     1                      /*!< Enable external oscallator */

/* Bit field masks: */
#define RCU_OSECFG_XOEN_Msk                   0x00000001             /*!< Enable output XO_OSC from external oscillator */
#define RCU_OSECFG_EN_Msk                     0x00000002             /*!< Enable external oscallator */

/*--  PLLCFG: PLL configuration register ----------------------------------------------------------------------*/
typedef struct {
  uint32_t M                      :6;                                /*!< PLL M Coefficient */
  uint32_t                        :2;                                /*!< RESERVED */
  uint32_t N                      :6;                                /*!< PLL N Coefficient */
  uint32_t                        :2;                                /*!< RESERVED */
  uint32_t OD                     :2;                                /*!< PLL OD Coefficient */
  uint32_t                        :2;                                /*!< RESERVED */
  uint32_t REFSRC                 :1;                                /*!< PLL Reference source select bit */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t BYPASS                 :1;                                /*!< PLL Bypass enable */
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t OUTEN                  :1;                                /*!< Enable PLL out */
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t LOCK                   :1;                                /*!< PLL status lock  */
} _RCU_PLLCFG_bits;

/* Bit field positions: */
#define RCU_PLLCFG_M_Pos                      0                      /*!< PLL M Coefficient */
#define RCU_PLLCFG_N_Pos                      8                      /*!< PLL N Coefficient */
#define RCU_PLLCFG_OD_Pos                     16                     /*!< PLL OD Coefficient */
#define RCU_PLLCFG_REFSRC_Pos                 20                     /*!< PLL Reference source select bit */
#define RCU_PLLCFG_BYPASS_Pos                 24                     /*!< PLL Bypass enable */
#define RCU_PLLCFG_OUTEN_Pos                  26                     /*!< Enable PLL out */
#define RCU_PLLCFG_LOCK_Pos                   28                     /*!< PLL status lock  */

/* Bit field masks: */
#define RCU_PLLCFG_M_Msk                      0x0000003F             /*!< PLL M Coefficient */
#define RCU_PLLCFG_N_Msk                      0x00003F00             /*!< PLL N Coefficient */
#define RCU_PLLCFG_OD_Msk                     0x00030000             /*!< PLL OD Coefficient */
#define RCU_PLLCFG_REFSRC_Msk                 0x00100000             /*!< PLL Reference source select bit */
#define RCU_PLLCFG_BYPASS_Msk                 0x01000000             /*!< PLL Bypass enable */
#define RCU_PLLCFG_OUTEN_Msk                  0x04000000             /*!< Enable PLL out */
#define RCU_PLLCFG_LOCK_Msk                   0x10000000             /*!< PLL status lock  */

/* Bit field enums: */
typedef enum {
  RCU_PLLCFG_REFSRC_OSECLK                   = 0x0,                  /*!< external oscillator */
  RCU_PLLCFG_REFSRC_OSICLK                   = 0x1,                  /*!< internal oscillator */
} RCU_PLLCFG_REFSRC_Enum;

/*--  PLLDIV: PLL divider register ----------------------------------------------------------------------------*/
typedef struct {
  uint32_t DIVEN                  :1;                                /*!< PLL Divider enable bit */
  uint32_t                        :7;                                /*!< RESERVED */
  uint32_t DIV                    :6;                                /*!< PLL divider coefficent */
} _RCU_PLLDIV_bits;

/* Bit field positions: */
#define RCU_PLLDIV_DIVEN_Pos                  0                      /*!< PLL Divider enable bit */
#define RCU_PLLDIV_DIV_Pos                    8                      /*!< PLL divider coefficent */

/* Bit field masks: */
#define RCU_PLLDIV_DIVEN_Msk                  0x00000001             /*!< PLL Divider enable bit */
#define RCU_PLLDIV_DIV_Msk                    0x00003F00             /*!< PLL divider coefficent */

/*--  SYSCLKCFG: System clock configuration register ----------------------------------------------------------*/
typedef struct {
  uint32_t SYSSEL                 :2;                                /*!< System clock source selection */
  uint32_t                        :14;                               /*!< RESERVED */
  uint32_t SECEN                  :1;                                /*!< Enable clock security system */
} _RCU_SYSCLKCFG_bits;

/* Bit field positions: */
#define RCU_SYSCLKCFG_SYSSEL_Pos              0                      /*!< System clock source selection */
#define RCU_SYSCLKCFG_SECEN_Pos               16                     /*!< Enable clock security system */

/* Bit field masks: */
#define RCU_SYSCLKCFG_SYSSEL_Msk              0x00000003             /*!< System clock source selection */
#define RCU_SYSCLKCFG_SECEN_Msk               0x00010000             /*!< Enable clock security system */

/* Bit field enums: */
typedef enum {
  RCU_SYSCLKCFG_SYSSEL_OSICLK                = 0x0,                  /*!< internal oscillator */
  RCU_SYSCLKCFG_SYSSEL_OSECLK                = 0x1,                  /*!< external oscillator */
  RCU_SYSCLKCFG_SYSSEL_PLLCLK                = 0x2,                  /*!< PLL output clock */
  RCU_SYSCLKCFG_SYSSEL_PLLDIVCLK             = 0x3,                  /*!< PLL divided clock */
} RCU_SYSCLKCFG_SYSSEL_Enum;

/*--  SYSCLKSTAT: System clock status register ----------------------------------------------------------------*/
typedef struct {
  uint32_t SYSSTAT                :2;                                /*!< Current system source clock */
  uint32_t                        :2;                                /*!< RESERVED */
  uint32_t BUSY                   :1;                                /*!< Clock manager is busy, for example, when change clock source */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t SYSFAIL                :1;                                /*!< Error in current clock was detected */
  uint32_t                        :8;                                /*!< RESERVED */
  uint32_t OSECLKFAIL             :1;                                /*!< External oscillator clock fail */
  uint32_t PLLCLKFAIL             :1;                                /*!< PLL source clock fail */
  uint32_t PLLDIVCLKFAIL          :1;                                /*!< PLL divided clock fail */
  uint32_t                        :5;                                /*!< RESERVED */
  uint32_t OSECLKGOOD             :1;                                /*!< External oscillator clock good */
  uint32_t PLLCLKGOOD             :1;                                /*!< PLL clock good */
  uint32_t PLLDIVCLKGOOD          :1;                                /*!< PLL divided clock good */
} _RCU_SYSCLKSTAT_bits;

/* Bit field positions: */
#define RCU_SYSCLKSTAT_SYSSTAT_Pos            0                      /*!< Current system source clock */
#define RCU_SYSCLKSTAT_BUSY_Pos               4                      /*!< Clock manager is busy, for example, when change clock source */
#define RCU_SYSCLKSTAT_SYSFAIL_Pos            8                      /*!< Error in current clock was detected */
#define RCU_SYSCLKSTAT_OSECLKFAIL_Pos         17                     /*!< External oscillator clock fail */
#define RCU_SYSCLKSTAT_PLLCLKFAIL_Pos         18                     /*!< PLL source clock fail */
#define RCU_SYSCLKSTAT_PLLDIVCLKFAIL_Pos       19                    /*!< PLL divided clock fail */
#define RCU_SYSCLKSTAT_OSECLKGOOD_Pos         25                     /*!< External oscillator clock good */
#define RCU_SYSCLKSTAT_PLLCLKGOOD_Pos         26                     /*!< PLL clock good */
#define RCU_SYSCLKSTAT_PLLDIVCLKGOOD_Pos       27                    /*!< PLL divided clock good */

/* Bit field masks: */
#define RCU_SYSCLKSTAT_SYSSTAT_Msk            0x00000003             /*!< Current system source clock */
#define RCU_SYSCLKSTAT_BUSY_Msk               0x00000010             /*!< Clock manager is busy, for example, when change clock source */
#define RCU_SYSCLKSTAT_SYSFAIL_Msk            0x00000100             /*!< Error in current clock was detected */
#define RCU_SYSCLKSTAT_OSECLKFAIL_Msk         0x00020000             /*!< External oscillator clock fail */
#define RCU_SYSCLKSTAT_PLLCLKFAIL_Msk         0x00040000             /*!< PLL source clock fail */
#define RCU_SYSCLKSTAT_PLLDIVCLKFAIL_Msk       0x00080000            /*!< PLL divided clock fail */
#define RCU_SYSCLKSTAT_OSECLKGOOD_Msk         0x02000000             /*!< External oscillator clock good */
#define RCU_SYSCLKSTAT_PLLCLKGOOD_Msk         0x04000000             /*!< PLL clock good */
#define RCU_SYSCLKSTAT_PLLDIVCLKGOOD_Msk       0x08000000            /*!< PLL divided clock good */

/* Bit field enums: */
typedef enum {
  RCU_SYSCLKSTAT_SYSSTAT_OSICLK              = 0x0,                  /*!< internal oscillator */
  RCU_SYSCLKSTAT_SYSSTAT_OSECLK              = 0x1,                  /*!< external oscillator */
  RCU_SYSCLKSTAT_SYSSTAT_PLLCLK              = 0x2,                  /*!< PLL output clock */
  RCU_SYSCLKSTAT_SYSSTAT_PLLDIVCLK           = 0x3,                  /*!< PLL divided clock */
} RCU_SYSCLKSTAT_SYSSTAT_Enum;

/*--  SECPRD: Security sysytem clock period register ----------------------------------------------------------*/
typedef struct {
  uint32_t                        :8;                                /*!< RESERVED */
  uint32_t OSECLK                 :8;                                /*!< Max counter value for external oscillator clock fail detection */
  uint32_t PLLCLK                 :8;                                /*!< Max counter value for PLL clock fail detection */
  uint32_t PLLDIVCLK              :8;                                /*!< Max counter value for PLL clock fail detection */
} _RCU_SECPRD_bits;

/* Bit field positions: */
#define RCU_SECPRD_OSECLK_Pos                 8                      /*!< Max counter value for external oscillator clock fail detection */
#define RCU_SECPRD_PLLCLK_Pos                 16                     /*!< Max counter value for PLL clock fail detection */
#define RCU_SECPRD_PLLDIVCLK_Pos              24                     /*!< Max counter value for PLL clock fail detection */

/* Bit field masks: */
#define RCU_SECPRD_OSECLK_Msk                 0x0000FF00             /*!< Max counter value for external oscillator clock fail detection */
#define RCU_SECPRD_PLLCLK_Msk                 0x00FF0000             /*!< Max counter value for PLL clock fail detection */
#define RCU_SECPRD_PLLDIVCLK_Msk              0xFF000000             /*!< Max counter value for PLL clock fail detection */

/*--  SYSRSTCFG: System reset configuration register ----------------------------------------------------------*/
typedef struct {
  uint32_t LOCKUPEN               :1;                                /*!< Enable reset when processor in LOCKUP state */
} _RCU_SYSRSTCFG_bits;

/* Bit field positions: */
#define RCU_SYSRSTCFG_LOCKUPEN_Pos            0                      /*!< Enable reset when processor in LOCKUP state */

/* Bit field masks: */
#define RCU_SYSRSTCFG_LOCKUPEN_Msk            0x00000001             /*!< Enable reset when processor in LOCKUP state */

/*--  SYSRSTSTAT: Reset status register -----------------------------------------------------------------------*/
typedef struct {
  uint32_t POR                    :1;                                /*!< PowerOn Reset status */
  uint32_t WDOG                   :1;                                /*!< WatchDog Reset status */
  uint32_t SYSRST                 :1;                                /*!< System Reset Status */
  uint32_t LOCKUP                 :1;                                /*!< Lockup Reset Status */
} _RCU_SYSRSTSTAT_bits;

/* Bit field positions: */
#define RCU_SYSRSTSTAT_POR_Pos                0                      /*!< PowerOn Reset status */
#define RCU_SYSRSTSTAT_WDOG_Pos               1                      /*!< WatchDog Reset status */
#define RCU_SYSRSTSTAT_SYSRST_Pos             2                      /*!< System Reset Status */
#define RCU_SYSRSTSTAT_LOCKUP_Pos             3                      /*!< Lockup Reset Status */

/* Bit field masks: */
#define RCU_SYSRSTSTAT_POR_Msk                0x00000001             /*!< PowerOn Reset status */
#define RCU_SYSRSTSTAT_WDOG_Msk               0x00000002             /*!< WatchDog Reset status */
#define RCU_SYSRSTSTAT_SYSRST_Msk             0x00000004             /*!< System Reset Status */
#define RCU_SYSRSTSTAT_LOCKUP_Msk             0x00000008             /*!< Lockup Reset Status */

/*--  INTEN: Interrupt enable register ------------------------------------------------------------------------*/
typedef struct {
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t OSECLKFAIL             :1;                                /*!< Enable OSECLK fail interrupt  */
  uint32_t PLLCLKFAIL             :1;                                /*!< Enable PLLCLK fail interrupt  */
  uint32_t PLLDIVCLKFAIL          :1;                                /*!< Enable PLLDIVCLK fail interrupt  */
  uint32_t                        :5;                                /*!< RESERVED */
  uint32_t OSECLKGOOD             :1;                                /*!< Enable OSECLK good interrupt  */
  uint32_t PLLCLKGOOD             :1;                                /*!< Enable PLLCLK good interrupt  */
  uint32_t PLLDIVCLKGOOD          :1;                                /*!< Enable PLLDIVCLK good interrupt  */
  uint32_t                        :4;                                /*!< RESERVED */
  uint32_t PLLLOCK                :1;                                /*!< Enable int from pll lock signal */
} _RCU_INTEN_bits;

/* Bit field positions: */
#define RCU_INTEN_OSECLKFAIL_Pos              1                      /*!< Enable OSECLK fail interrupt  */
#define RCU_INTEN_PLLCLKFAIL_Pos              2                      /*!< Enable PLLCLK fail interrupt  */
#define RCU_INTEN_PLLDIVCLKFAIL_Pos           3                      /*!< Enable PLLDIVCLK fail interrupt  */
#define RCU_INTEN_OSECLKGOOD_Pos              9                      /*!< Enable OSECLK good interrupt  */
#define RCU_INTEN_PLLCLKGOOD_Pos              10                     /*!< Enable PLLCLK good interrupt  */
#define RCU_INTEN_PLLDIVCLKGOOD_Pos           11                     /*!< Enable PLLDIVCLK good interrupt  */
#define RCU_INTEN_PLLLOCK_Pos                 16                     /*!< Enable int from pll lock signal */

/* Bit field masks: */
#define RCU_INTEN_OSECLKFAIL_Msk              0x00000002             /*!< Enable OSECLK fail interrupt  */
#define RCU_INTEN_PLLCLKFAIL_Msk              0x00000004             /*!< Enable PLLCLK fail interrupt  */
#define RCU_INTEN_PLLDIVCLKFAIL_Msk           0x00000008             /*!< Enable PLLDIVCLK fail interrupt  */
#define RCU_INTEN_OSECLKGOOD_Msk              0x00000200             /*!< Enable OSECLK good interrupt  */
#define RCU_INTEN_PLLCLKGOOD_Msk              0x00000400             /*!< Enable PLLCLK good interrupt  */
#define RCU_INTEN_PLLDIVCLKGOOD_Msk           0x00000800             /*!< Enable PLLDIVCLK good interrupt  */
#define RCU_INTEN_PLLLOCK_Msk                 0x00010000             /*!< Enable int from pll lock signal */

/*--  INTSTAT: Interrupt status register ----------------------------------------------------------------------*/
typedef struct {
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t OSECLKFAIL             :1;                                /*!< Status external oscillator clock fail signal */
  uint32_t PLLCLKFAIL             :1;                                /*!< Status PLL clock fail signal */
  uint32_t PLLDIVCLKFAIL          :1;                                /*!< Status PLLDIV clock fail signal */
  uint32_t                        :5;                                /*!< RESERVED */
  uint32_t OSECLKGOOD             :1;                                /*!< Status external oscillator clock good signal */
  uint32_t PLLCLKGOOD             :1;                                /*!< Status PLL clock good signal */
  uint32_t PLLDIVCLKGOOD          :1;                                /*!< Status PLLDIV clock good signal */
  uint32_t                        :4;                                /*!< RESERVED */
  uint32_t PLLLOCK                :1;                                /*!< Status pll lock signal */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t SYSFAIL                :1;                                /*!< Current clock failed status */
} _RCU_INTSTAT_bits;

/* Bit field positions: */
#define RCU_INTSTAT_OSECLKFAIL_Pos            1                      /*!< Status external oscillator clock fail signal */
#define RCU_INTSTAT_PLLCLKFAIL_Pos            2                      /*!< Status PLL clock fail signal */
#define RCU_INTSTAT_PLLDIVCLKFAIL_Pos         3                      /*!< Status PLLDIV clock fail signal */
#define RCU_INTSTAT_OSECLKGOOD_Pos            9                      /*!< Status external oscillator clock good signal */
#define RCU_INTSTAT_PLLCLKGOOD_Pos            10                     /*!< Status PLL clock good signal */
#define RCU_INTSTAT_PLLDIVCLKGOOD_Pos         11                     /*!< Status PLLDIV clock good signal */
#define RCU_INTSTAT_PLLLOCK_Pos               16                     /*!< Status pll lock signal */
#define RCU_INTSTAT_SYSFAIL_Pos               20                     /*!< Current clock failed status */

/* Bit field masks: */
#define RCU_INTSTAT_OSECLKFAIL_Msk            0x00000002             /*!< Status external oscillator clock fail signal */
#define RCU_INTSTAT_PLLCLKFAIL_Msk            0x00000004             /*!< Status PLL clock fail signal */
#define RCU_INTSTAT_PLLDIVCLKFAIL_Msk         0x00000008             /*!< Status PLLDIV clock fail signal */
#define RCU_INTSTAT_OSECLKGOOD_Msk            0x00000200             /*!< Status external oscillator clock good signal */
#define RCU_INTSTAT_PLLCLKGOOD_Msk            0x00000400             /*!< Status PLL clock good signal */
#define RCU_INTSTAT_PLLDIVCLKGOOD_Msk         0x00000800             /*!< Status PLLDIV clock good signal */
#define RCU_INTSTAT_PLLLOCK_Msk               0x00010000             /*!< Status pll lock signal */
#define RCU_INTSTAT_SYSFAIL_Msk               0x00100000             /*!< Current clock failed status */

/*--  TRACECFG: Trace clock configuration register ------------------------------------------------------------*/
typedef struct {
  uint32_t CLKEN                  :1;                                /*!< Clock enable */
  uint32_t                        :7;                                /*!< RESERVED */
  uint32_t CLKSEL                 :2;                                /*!< Clock source select */
  uint32_t                        :6;                                /*!< RESERVED */
  uint32_t DIVEN                  :1;                                /*!< Enable divider */
  uint32_t                        :7;                                /*!< RESERVED */
  uint32_t DIVN                   :6;                                /*!< Divider coefficient */
} _RCU_TRACECFG_bits;

/* Bit field positions: */
#define RCU_TRACECFG_CLKEN_Pos                0                      /*!< Clock enable */
#define RCU_TRACECFG_CLKSEL_Pos               8                      /*!< Clock source select */
#define RCU_TRACECFG_DIVEN_Pos                16                     /*!< Enable divider */
#define RCU_TRACECFG_DIVN_Pos                 24                     /*!< Divider coefficient */

/* Bit field masks: */
#define RCU_TRACECFG_CLKEN_Msk                0x00000001             /*!< Clock enable */
#define RCU_TRACECFG_CLKSEL_Msk               0x00000300             /*!< Clock source select */
#define RCU_TRACECFG_DIVEN_Msk                0x00010000             /*!< Enable divider */
#define RCU_TRACECFG_DIVN_Msk                 0x3F000000             /*!< Divider coefficient */

/* Bit field enums: */
typedef enum {
  RCU_TRACECFG_CLKSEL_OSICLK                 = 0x0,                  /*!< internal oscillator */
  RCU_TRACECFG_CLKSEL_OSECLK                 = 0x1,                  /*!< external oscillator */
  RCU_TRACECFG_CLKSEL_PLLCLK                 = 0x2,                  /*!< PLL output clock */
  RCU_TRACECFG_CLKSEL_PLLDIVCLK              = 0x3,                  /*!< PLL divided clock */
} RCU_TRACECFG_CLKSEL_Enum;

/*--  CLKOUTCFG: Clockout configuration register --------------------------------------------------------------*/
typedef struct {
  uint32_t CLKEN                  :1;                                /*!< Clock enable */
  uint32_t                        :7;                                /*!< RESERVED */
  uint32_t CLKSEL                 :2;                                /*!< Clock source select */
  uint32_t                        :6;                                /*!< RESERVED */
  uint32_t DIVEN                  :1;                                /*!< Enable divider */
  uint32_t                        :7;                                /*!< RESERVED */
  uint32_t DIVN                   :3;                                /*!< Divider coefficient */
} _RCU_CLKOUTCFG_bits;

/* Bit field positions: */
#define RCU_CLKOUTCFG_CLKEN_Pos               0                      /*!< Clock enable */
#define RCU_CLKOUTCFG_CLKSEL_Pos              8                      /*!< Clock source select */
#define RCU_CLKOUTCFG_DIVEN_Pos               16                     /*!< Enable divider */
#define RCU_CLKOUTCFG_DIVN_Pos                24                     /*!< Divider coefficient */

/* Bit field masks: */
#define RCU_CLKOUTCFG_CLKEN_Msk               0x00000001             /*!< Clock enable */
#define RCU_CLKOUTCFG_CLKSEL_Msk              0x00000300             /*!< Clock source select */
#define RCU_CLKOUTCFG_DIVEN_Msk               0x00010000             /*!< Enable divider */
#define RCU_CLKOUTCFG_DIVN_Msk                0x07000000             /*!< Divider coefficient */

/* Bit field enums: */
typedef enum {
  RCU_CLKOUTCFG_CLKSEL_OSICLK                = 0x0,                  /*!< internal oscillator */
  RCU_CLKOUTCFG_CLKSEL_OSECLK                = 0x1,                  /*!< external oscillator */
  RCU_CLKOUTCFG_CLKSEL_PLLCLK                = 0x2,                  /*!< PLL output clock */
  RCU_CLKOUTCFG_CLKSEL_PLLDIVCLK             = 0x3,                  /*!< PLL divided clock */
} RCU_CLKOUTCFG_CLKSEL_Enum;

/*--  WDTCFG: WatchDog configuration register -----------------------------------------------------------------*/
typedef struct {
  uint32_t CLKEN                  :1;                                /*!< Clock enable */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t RSTDIS                 :1;                                /*!< Reset disable */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t CLKSEL                 :2;                                /*!< Clock source select */
  uint32_t                        :6;                                /*!< RESERVED */
  uint32_t DIVEN                  :1;                                /*!< Enable divider */
  uint32_t                        :7;                                /*!< RESERVED */
  uint32_t DIVN                   :6;                                /*!< Divider coefficient */
} _RCU_WDTCFG_bits;

/* Bit field positions: */
#define RCU_WDTCFG_CLKEN_Pos                  0                      /*!< Clock enable */
#define RCU_WDTCFG_RSTDIS_Pos                 4                      /*!< Reset disable */
#define RCU_WDTCFG_CLKSEL_Pos                 8                      /*!< Clock source select */
#define RCU_WDTCFG_DIVEN_Pos                  16                     /*!< Enable divider */
#define RCU_WDTCFG_DIVN_Pos                   24                     /*!< Divider coefficient */

/* Bit field masks: */
#define RCU_WDTCFG_CLKEN_Msk                  0x00000001             /*!< Clock enable */
#define RCU_WDTCFG_RSTDIS_Msk                 0x00000010             /*!< Reset disable */
#define RCU_WDTCFG_CLKSEL_Msk                 0x00000300             /*!< Clock source select */
#define RCU_WDTCFG_DIVEN_Msk                  0x00010000             /*!< Enable divider */
#define RCU_WDTCFG_DIVN_Msk                   0x3F000000             /*!< Divider coefficient */

/* Bit field enums: */
typedef enum {
  RCU_WDTCFG_CLKSEL_OSICLK                   = 0x0,                  /*!< internal oscillator */
  RCU_WDTCFG_CLKSEL_OSECLK                   = 0x1,                  /*!< external oscillator */
  RCU_WDTCFG_CLKSEL_PLLCLK                   = 0x2,                  /*!< PLL output clock */
  RCU_WDTCFG_CLKSEL_PLLDIVCLK                = 0x3,                  /*!< PLL divided clock */
} RCU_WDTCFG_CLKSEL_Enum;

/*-- UARTCFG: UARTCFG: UART clock and reset configuration register --------------------------------------------*/
typedef struct {
  uint32_t CLKEN                  :1;                                /*!< Clock enable */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t RSTDIS                 :1;                                /*!< Reset disable */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t CLKSEL                 :2;                                /*!< Clock source select */
  uint32_t                        :6;                                /*!< RESERVED */
  uint32_t DIVEN                  :1;                                /*!< Enable divider */
  uint32_t                        :7;                                /*!< RESERVED */
  uint32_t DIVN                   :6;                                /*!< Divider coefficient */
} _RCU_UARTCFG_UARTCFG_bits;

/* Bit field positions: */
#define RCU_UARTCFG_UARTCFG_CLKEN_Pos         0                      /*!< Clock enable */
#define RCU_UARTCFG_UARTCFG_RSTDIS_Pos        4                      /*!< Reset disable */
#define RCU_UARTCFG_UARTCFG_CLKSEL_Pos        8                      /*!< Clock source select */
#define RCU_UARTCFG_UARTCFG_DIVEN_Pos         16                     /*!< Enable divider */
#define RCU_UARTCFG_UARTCFG_DIVN_Pos          24                     /*!< Divider coefficient */

/* Bit field masks: */
#define RCU_UARTCFG_UARTCFG_CLKEN_Msk         0x00000001             /*!< Clock enable */
#define RCU_UARTCFG_UARTCFG_RSTDIS_Msk        0x00000010             /*!< Reset disable */
#define RCU_UARTCFG_UARTCFG_CLKSEL_Msk        0x00000300             /*!< Clock source select */
#define RCU_UARTCFG_UARTCFG_DIVEN_Msk         0x00010000             /*!< Enable divider */
#define RCU_UARTCFG_UARTCFG_DIVN_Msk          0x3F000000             /*!< Divider coefficient */

/* Bit field enums: */
typedef enum {
  RCU_UARTCFG_UARTCFG_CLKSEL_OSECLK          = 0x0,                  /*!< external oscillator */
  RCU_UARTCFG_UARTCFG_CLKSEL_PLLCLK          = 0x1,                  /*!< PLL output clock */
  RCU_UARTCFG_UARTCFG_CLKSEL_PLLDIVCLK       = 0x2,                  /*!< PLL divided clock */
  RCU_UARTCFG_UARTCFG_CLKSEL_OSICLK          = 0x3,                  /*!< internal oscillator */
} RCU_UARTCFG_UARTCFG_CLKSEL_Enum;

/*--  SPICFG: SPI clock and reset configuration register ------------------------------------------------------*/
typedef struct {
  uint32_t CLKEN                  :1;                                /*!< Clock enable */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t RSTDIS                 :1;                                /*!< Reset disable */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t CLKSEL                 :2;                                /*!< Clock source select */
  uint32_t                        :6;                                /*!< RESERVED */
  uint32_t DIVEN                  :1;                                /*!< Enable divider */
  uint32_t                        :7;                                /*!< RESERVED */
  uint32_t DIVN                   :6;                                /*!< Divider coefficient */
} _RCU_SPICFG_bits;

/* Bit field positions: */
#define RCU_SPICFG_CLKEN_Pos                  0                      /*!< Clock enable */
#define RCU_SPICFG_RSTDIS_Pos                 4                      /*!< Reset disable */
#define RCU_SPICFG_CLKSEL_Pos                 8                      /*!< Clock source select */
#define RCU_SPICFG_DIVEN_Pos                  16                     /*!< Enable divider */
#define RCU_SPICFG_DIVN_Pos                   24                     /*!< Divider coefficient */

/* Bit field masks: */
#define RCU_SPICFG_CLKEN_Msk                  0x00000001             /*!< Clock enable */
#define RCU_SPICFG_RSTDIS_Msk                 0x00000010             /*!< Reset disable */
#define RCU_SPICFG_CLKSEL_Msk                 0x00000300             /*!< Clock source select */
#define RCU_SPICFG_DIVEN_Msk                  0x00010000             /*!< Enable divider */
#define RCU_SPICFG_DIVN_Msk                   0x3F000000             /*!< Divider coefficient */

/* Bit field enums: */
typedef enum {
  RCU_SPICFG_CLKSEL_OSECLK                   = 0x0,                  /*!< external oscillator */
  RCU_SPICFG_CLKSEL_PLLCLK                   = 0x1,                  /*!< PLL output clock */
  RCU_SPICFG_CLKSEL_PLLDIVCLK                = 0x2,                  /*!< PLL divided clock */
  RCU_SPICFG_CLKSEL_OSICLK                   = 0x3,                  /*!< internal oscillator */
} RCU_SPICFG_CLKSEL_Enum;

/*--  ADCCFG: ADC clock and reset configuration register ------------------------------------------------------*/
typedef struct {
  uint32_t CLKEN                  :1;                                /*!< Clock enable */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t RSTDIS                 :1;                                /*!< Reset disable */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t CLKSEL                 :2;                                /*!< Clock source select */
  uint32_t                        :6;                                /*!< RESERVED */
  uint32_t DIVEN                  :1;                                /*!< Enable divider */
  uint32_t                        :7;                                /*!< RESERVED */
  uint32_t DIVN                   :6;                                /*!< Divider coefficient */
} _RCU_ADCCFG_bits;

/* Bit field positions: */
#define RCU_ADCCFG_CLKEN_Pos                  0                      /*!< Clock enable */
#define RCU_ADCCFG_RSTDIS_Pos                 4                      /*!< Reset disable */
#define RCU_ADCCFG_CLKSEL_Pos                 8                      /*!< Clock source select */
#define RCU_ADCCFG_DIVEN_Pos                  16                     /*!< Enable divider */
#define RCU_ADCCFG_DIVN_Pos                   24                     /*!< Divider coefficient */

/* Bit field masks: */
#define RCU_ADCCFG_CLKEN_Msk                  0x00000001             /*!< Clock enable */
#define RCU_ADCCFG_RSTDIS_Msk                 0x00000010             /*!< Reset disable */
#define RCU_ADCCFG_CLKSEL_Msk                 0x00000300             /*!< Clock source select */
#define RCU_ADCCFG_DIVEN_Msk                  0x00010000             /*!< Enable divider */
#define RCU_ADCCFG_DIVN_Msk                   0x3F000000             /*!< Divider coefficient */

/* Bit field enums: */
typedef enum {
  RCU_ADCCFG_CLKSEL_OSECLK                   = 0x0,                  /*!< external oscillator */
  RCU_ADCCFG_CLKSEL_PLLCLK                   = 0x1,                  /*!< PLL output clock */
  RCU_ADCCFG_CLKSEL_PLLDIVCLK                = 0x2,                  /*!< PLL divided clock */
  RCU_ADCCFG_CLKSEL_OSICLK                   = 0x3,                  /*!< internal oscillator */
} RCU_ADCCFG_CLKSEL_Enum;

/*--  PCLKCFG: APB clock configuration register ---------------------------------------------------------------*/
typedef struct {
  uint32_t TMR0EN                 :1;                                /*!< Enable clock for TMR0 */
  uint32_t TMR1EN                 :1;                                /*!< Enable clock for TMR1 */
  uint32_t TMR2EN                 :1;                                /*!< Enable clock for TMR2 */
  uint32_t TMR3EN                 :1;                                /*!< Enable clock for TMR3 */
  uint32_t PWM0EN                 :1;                                /*!< Enable clock for PWM0 */
  uint32_t PWM1EN                 :1;                                /*!< Enable clock for PWM1 */
  uint32_t PWM2EN                 :1;                                /*!< Enable clock for PWM2 */
  uint32_t I2CEN                  :1;                                /*!< Enable clock for I2C */
  uint32_t QEPEN                  :1;                                /*!< Enable clock for QEP */
  uint32_t ECAP0EN                :1;                                /*!< Enable clock for ECAP0 */
  uint32_t ECAP1EN                :1;                                /*!< Enable clock for ECAP1 */
  uint32_t ECAP2EN                :1;                                /*!< Enable clock for ECAP2 */
} _RCU_PCLKCFG_bits;

/* Bit field positions: */
#define RCU_PCLKCFG_TMR0EN_Pos                0                      /*!< Enable clock for TMR0 */
#define RCU_PCLKCFG_TMR1EN_Pos                1                      /*!< Enable clock for TMR1 */
#define RCU_PCLKCFG_TMR2EN_Pos                2                      /*!< Enable clock for TMR2 */
#define RCU_PCLKCFG_TMR3EN_Pos                3                      /*!< Enable clock for TMR3 */
#define RCU_PCLKCFG_PWM0EN_Pos                4                      /*!< Enable clock for PWM0 */
#define RCU_PCLKCFG_PWM1EN_Pos                5                      /*!< Enable clock for PWM1 */
#define RCU_PCLKCFG_PWM2EN_Pos                6                      /*!< Enable clock for PWM2 */
#define RCU_PCLKCFG_I2CEN_Pos                 7                      /*!< Enable clock for I2C */
#define RCU_PCLKCFG_QEPEN_Pos                 8                      /*!< Enable clock for QEP */
#define RCU_PCLKCFG_ECAP0EN_Pos               9                      /*!< Enable clock for ECAP0 */
#define RCU_PCLKCFG_ECAP1EN_Pos               10                     /*!< Enable clock for ECAP1 */
#define RCU_PCLKCFG_ECAP2EN_Pos               11                     /*!< Enable clock for ECAP2 */

/* Bit field masks: */
#define RCU_PCLKCFG_TMR0EN_Msk                0x00000001             /*!< Enable clock for TMR0 */
#define RCU_PCLKCFG_TMR1EN_Msk                0x00000002             /*!< Enable clock for TMR1 */
#define RCU_PCLKCFG_TMR2EN_Msk                0x00000004             /*!< Enable clock for TMR2 */
#define RCU_PCLKCFG_TMR3EN_Msk                0x00000008             /*!< Enable clock for TMR3 */
#define RCU_PCLKCFG_PWM0EN_Msk                0x00000010             /*!< Enable clock for PWM0 */
#define RCU_PCLKCFG_PWM1EN_Msk                0x00000020             /*!< Enable clock for PWM1 */
#define RCU_PCLKCFG_PWM2EN_Msk                0x00000040             /*!< Enable clock for PWM2 */
#define RCU_PCLKCFG_I2CEN_Msk                 0x00000080             /*!< Enable clock for I2C */
#define RCU_PCLKCFG_QEPEN_Msk                 0x00000100             /*!< Enable clock for QEP */
#define RCU_PCLKCFG_ECAP0EN_Msk               0x00000200             /*!< Enable clock for ECAP0 */
#define RCU_PCLKCFG_ECAP1EN_Msk               0x00000400             /*!< Enable clock for ECAP1 */
#define RCU_PCLKCFG_ECAP2EN_Msk               0x00000800             /*!< Enable clock for ECAP2 */

/*--  PRSTCFG: APB reset configuration register ---------------------------------------------------------------*/
typedef struct {
  uint32_t TMR0EN                 :1;                                /*!< Disable reset from TMR0 */
  uint32_t TMR1EN                 :1;                                /*!< Disable reset from TMR1 */
  uint32_t TMR2EN                 :1;                                /*!< Disable reset from TMR2 */
  uint32_t TMR3EN                 :1;                                /*!< Disable reset from TMR3 */
  uint32_t PWM0EN                 :1;                                /*!< Disable reset from PWM0 */
  uint32_t PWM1EN                 :1;                                /*!< Disable reset from PWM1 */
  uint32_t PWM2EN                 :1;                                /*!< Disable reset from PWM2 */
  uint32_t I2CEN                  :1;                                /*!< Disable reset from I2C */
  uint32_t QEPEN                  :1;                                /*!< Disable reset from QEP */
  uint32_t ECAP0EN                :1;                                /*!< Disable reset from ECAP0 */
  uint32_t ECAP1EN                :1;                                /*!< Disable reset from ECAP1 */
  uint32_t ECAP2EN                :1;                                /*!< Disable reset from ECAP2 */
} _RCU_PRSTCFG_bits;

/* Bit field positions: */
#define RCU_PRSTCFG_TMR0EN_Pos                0                      /*!< Disable reset from TMR0 */
#define RCU_PRSTCFG_TMR1EN_Pos                1                      /*!< Disable reset from TMR1 */
#define RCU_PRSTCFG_TMR2EN_Pos                2                      /*!< Disable reset from TMR2 */
#define RCU_PRSTCFG_TMR3EN_Pos                3                      /*!< Disable reset from TMR3 */
#define RCU_PRSTCFG_PWM0EN_Pos                4                      /*!< Disable reset from PWM0 */
#define RCU_PRSTCFG_PWM1EN_Pos                5                      /*!< Disable reset from PWM1 */
#define RCU_PRSTCFG_PWM2EN_Pos                6                      /*!< Disable reset from PWM2 */
#define RCU_PRSTCFG_I2CEN_Pos                 7                      /*!< Disable reset from I2C */
#define RCU_PRSTCFG_QEPEN_Pos                 8                      /*!< Disable reset from QEP */
#define RCU_PRSTCFG_ECAP0EN_Pos               9                      /*!< Disable reset from ECAP0 */
#define RCU_PRSTCFG_ECAP1EN_Pos               10                     /*!< Disable reset from ECAP1 */
#define RCU_PRSTCFG_ECAP2EN_Pos               11                     /*!< Disable reset from ECAP2 */

/* Bit field masks: */
#define RCU_PRSTCFG_TMR0EN_Msk                0x00000001             /*!< Disable reset from TMR0 */
#define RCU_PRSTCFG_TMR1EN_Msk                0x00000002             /*!< Disable reset from TMR1 */
#define RCU_PRSTCFG_TMR2EN_Msk                0x00000004             /*!< Disable reset from TMR2 */
#define RCU_PRSTCFG_TMR3EN_Msk                0x00000008             /*!< Disable reset from TMR3 */
#define RCU_PRSTCFG_PWM0EN_Msk                0x00000010             /*!< Disable reset from PWM0 */
#define RCU_PRSTCFG_PWM1EN_Msk                0x00000020             /*!< Disable reset from PWM1 */
#define RCU_PRSTCFG_PWM2EN_Msk                0x00000040             /*!< Disable reset from PWM2 */
#define RCU_PRSTCFG_I2CEN_Msk                 0x00000080             /*!< Disable reset from I2C */
#define RCU_PRSTCFG_QEPEN_Msk                 0x00000100             /*!< Disable reset from QEP */
#define RCU_PRSTCFG_ECAP0EN_Msk               0x00000200             /*!< Disable reset from ECAP0 */
#define RCU_PRSTCFG_ECAP1EN_Msk               0x00000400             /*!< Disable reset from ECAP1 */
#define RCU_PRSTCFG_ECAP2EN_Msk               0x00000800             /*!< Disable reset from ECAP2 */

/*--  HCLKCFG: AHB clock configuration register ---------------------------------------------------------------*/
typedef struct {
  uint32_t GPIOAEN                :1;                                /*!< Enable clock for GPIOA port */
  uint32_t GPIOBEN                :1;                                /*!< Enable clock for GPIOB port */
  uint32_t CANEN                  :1;                                /*!< Enable clock for CAN  */
} _RCU_HCLKCFG_bits;

/* Bit field positions: */
#define RCU_HCLKCFG_GPIOAEN_Pos               0                      /*!< Enable clock for GPIOA port */
#define RCU_HCLKCFG_GPIOBEN_Pos               1                      /*!< Enable clock for GPIOB port */
#define RCU_HCLKCFG_CANEN_Pos                 2                      /*!< Enable clock for CAN  */

/* Bit field masks: */
#define RCU_HCLKCFG_GPIOAEN_Msk               0x00000001             /*!< Enable clock for GPIOA port */
#define RCU_HCLKCFG_GPIOBEN_Msk               0x00000002             /*!< Enable clock for GPIOB port */
#define RCU_HCLKCFG_CANEN_Msk                 0x00000004             /*!< Enable clock for CAN  */

/*--  HRSTCFG: AHB reset configuration register ---------------------------------------------------------------*/
typedef struct {
  uint32_t GPIOAEN                :1;                                /*!< Disable reset from GPIOA port */
  uint32_t GPIOBEN                :1;                                /*!< Disable reset from GPIOB port */
  uint32_t CANEN                  :1;                                /*!< Disable reset from CAN */
} _RCU_HRSTCFG_bits;

/* Bit field positions: */
#define RCU_HRSTCFG_GPIOAEN_Pos               0                      /*!< Disable reset from GPIOA port */
#define RCU_HRSTCFG_GPIOBEN_Pos               1                      /*!< Disable reset from GPIOB port */
#define RCU_HRSTCFG_CANEN_Pos                 2                      /*!< Disable reset from CAN */

/* Bit field masks: */
#define RCU_HRSTCFG_GPIOAEN_Msk               0x00000001             /*!< Disable reset from GPIOA port */
#define RCU_HRSTCFG_GPIOBEN_Msk               0x00000002             /*!< Disable reset from GPIOB port */
#define RCU_HRSTCFG_CANEN_Msk                 0x00000004             /*!< Disable reset from CAN */

//Cluster UARTCFG:
typedef struct {
  union { 
  /*!< UART clock and reset configuration register */
    __IO uint32_t UARTCFG;                                           /*!< UARTCFG : type used for word access */
    __IO _RCU_UARTCFG_UARTCFG_bits UARTCFG_bit;                      /*!< UARTCFG_bit: structure used for bit access */
  };
} _RCU_UARTCFG_TypeDef;
typedef struct {
  union {                                                               /*!< Internal oscillator configuration register */
    __IO uint32_t OSICFG;                                            /*!< OSICFG    : type used for word access */
    __IO _RCU_OSICFG_bits  OSICFG_bit;                               /*!< OSICFG_bit: structure used for bit access */
  };
  union {                                                               /*!< External oscillator configuration register */
    __IO uint32_t OSECFG;                                            /*!< OSECFG    : type used for word access */
    __IO _RCU_OSECFG_bits  OSECFG_bit;                               /*!< OSECFG_bit: structure used for bit access */
  };
  union {                                                               /*!< PLL configuration register */
    __IO uint32_t PLLCFG;                                            /*!< PLLCFG    : type used for word access */
    __IO _RCU_PLLCFG_bits  PLLCFG_bit;                               /*!< PLLCFG_bit: structure used for bit access */
  };
  union {                                                               /*!< PLL divider register */
    __IO uint32_t PLLDIV;                                            /*!< PLLDIV    : type used for word access */
    __IO _RCU_PLLDIV_bits  PLLDIV_bit;                               /*!< PLLDIV_bit: structure used for bit access */
  };
  union {                                                               /*!< System clock configuration register */
    __IO uint32_t SYSCLKCFG;                                           /*!< SYSCLKCFG    : type used for word access */
    __IO _RCU_SYSCLKCFG_bits  SYSCLKCFG_bit;                         /*!< SYSCLKCFG_bit: structure used for bit access */
  };
  union {                                                               /*!< System clock status register */
    __I uint32_t SYSCLKSTAT;                                           /*!< SYSCLKSTAT    : type used for word access */
    __I _RCU_SYSCLKSTAT_bits  SYSCLKSTAT_bit;                        /*!< SYSCLKSTAT_bit: structure used for bit access */
  };
  union {                                                               /*!< Security sysytem clock period register */
    __IO uint32_t SECPRD;                                            /*!< SECPRD    : type used for word access */
    __IO _RCU_SECPRD_bits  SECPRD_bit;                               /*!< SECPRD_bit: structure used for bit access */
  };
  union {                                                               /*!< System reset configuration register */
    __IO uint32_t SYSRSTCFG;                                           /*!< SYSRSTCFG    : type used for word access */
    __IO _RCU_SYSRSTCFG_bits  SYSRSTCFG_bit;                         /*!< SYSRSTCFG_bit: structure used for bit access */
  };
  union {                                                               /*!< Reset status register */
    __IO uint32_t SYSRSTSTAT;                                           /*!< SYSRSTSTAT    : type used for word access */
    __IO _RCU_SYSRSTSTAT_bits  SYSRSTSTAT_bit;                       /*!< SYSRSTSTAT_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt enable register */
    __IO uint32_t INTEN;                                             /*!< INTEN    : type used for word access */
    __IO _RCU_INTEN_bits  INTEN_bit;                                 /*!< INTEN_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt status register */
    __IO uint32_t INTSTAT;                                           /*!< INTSTAT    : type used for word access */
    __IO _RCU_INTSTAT_bits  INTSTAT_bit;                             /*!< INTSTAT_bit: structure used for bit access */
  };
  union {                                                               /*!< Trace clock configuration register */
    __IO uint32_t TRACECFG;                                           /*!< TRACECFG    : type used for word access */
    __IO _RCU_TRACECFG_bits  TRACECFG_bit;                           /*!< TRACECFG_bit: structure used for bit access */
  };
  union {                                                               /*!< Clockout configuration register */
    __IO uint32_t CLKOUTCFG;                                           /*!< CLKOUTCFG    : type used for word access */
    __IO _RCU_CLKOUTCFG_bits  CLKOUTCFG_bit;                         /*!< CLKOUTCFG_bit: structure used for bit access */
  };
  union {                                                               /*!< WatchDog configuration register */
    __IO uint32_t WDTCFG;                                            /*!< WDTCFG    : type used for word access */
    __IO _RCU_WDTCFG_bits  WDTCFG_bit;                               /*!< WDTCFG_bit: structure used for bit access */
  };
    __IO uint32_t Reserved0[10];
  _RCU_UARTCFG_TypeDef UARTCFG[2];
    __IO uint32_t Reserved1[6];
  union {                                                               /*!< SPI clock and reset configuration register */
    __IO uint32_t SPICFG;                                            /*!< SPICFG    : type used for word access */
    __IO _RCU_SPICFG_bits  SPICFG_bit;                               /*!< SPICFG_bit: structure used for bit access */
  };
    __IO uint32_t Reserved2[7];
  union {                                                               /*!< ADC clock and reset configuration register */
    __IO uint32_t ADCCFG;                                            /*!< ADCCFG    : type used for word access */
    __IO _RCU_ADCCFG_bits  ADCCFG_bit;                               /*!< ADCCFG_bit: structure used for bit access */
  };
    __IO uint32_t Reserved3[15];
  union {                                                               /*!< APB clock configuration register */
    __IO uint32_t PCLKCFG;                                           /*!< PCLKCFG    : type used for word access */
    __IO _RCU_PCLKCFG_bits  PCLKCFG_bit;                             /*!< PCLKCFG_bit: structure used for bit access */
  };
    __IO uint32_t Reserved4[3];
  union {                                                               /*!< APB reset configuration register */
    __IO uint32_t PRSTCFG;                                           /*!< PRSTCFG    : type used for word access */
    __IO _RCU_PRSTCFG_bits  PRSTCFG_bit;                             /*!< PRSTCFG_bit: structure used for bit access */
  };
    __IO uint32_t Reserved5[3];
  union {                                                               /*!< AHB clock configuration register */
    __IO uint32_t HCLKCFG;                                           /*!< HCLKCFG    : type used for word access */
    __IO _RCU_HCLKCFG_bits  HCLKCFG_bit;                             /*!< HCLKCFG_bit: structure used for bit access */
  };
  union {                                                               /*!< AHB reset configuration register */
    __IO uint32_t HRSTCFG;                                           /*!< HRSTCFG    : type used for word access */
    __IO _RCU_HRSTCFG_bits  HRSTCFG_bit;                             /*!< HRSTCFG_bit: structure used for bit access */
  };
} RCU_TypeDef;

/******************************************************************************/
/*                         PMU registers                                      */
/******************************************************************************/

/*--  CFG: PMU Configuration Register -------------------------------------------------------------------------*/
typedef struct {
  uint32_t EN                     :1;                                /*!< Enable PMU  */
} _PMU_CFG_bits;

/* Bit field positions: */
#define PMU_CFG_EN_Pos                        0                      /*!< Enable PMU  */

/* Bit field masks: */
#define PMU_CFG_EN_Msk                        0x00000001             /*!< Enable PMU  */

/*--  PUDEL: PMU Powerup Delay Value --------------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :16;                               /*!< Delay value for powerup peripheral blocks (in REFCLK ticks) */
} _PMU_PUDEL_bits;

/* Bit field positions: */
#define PMU_PUDEL_VAL_Pos                     0                      /*!< Delay value for powerup peripheral blocks (in REFCLK ticks) */

/* Bit field masks: */
#define PMU_PUDEL_VAL_Msk                     0x0000FFFF             /*!< Delay value for powerup peripheral blocks (in REFCLK ticks) */

/*--  PDEN: PMU Enable Powerdown for peripheral ---------------------------------------------------------------*/
typedef struct {
  uint32_t PLLPD                  :1;                                /*!< Enable powerdown for PLL */
  uint32_t MFLASHPD               :1;                                /*!< Enable powerdown for MFLASH */
  uint32_t OSEPD                  :1;                                /*!< Enable powerdown for external oscillator */
} _PMU_PDEN_bits;

/* Bit field positions: */
#define PMU_PDEN_PLLPD_Pos                    0                      /*!< Enable powerdown for PLL */
#define PMU_PDEN_MFLASHPD_Pos                 1                      /*!< Enable powerdown for MFLASH */
#define PMU_PDEN_OSEPD_Pos                    2                      /*!< Enable powerdown for external oscillator */

/* Bit field masks: */
#define PMU_PDEN_PLLPD_Msk                    0x00000001             /*!< Enable powerdown for PLL */
#define PMU_PDEN_MFLASHPD_Msk                 0x00000002             /*!< Enable powerdown for MFLASH */
#define PMU_PDEN_OSEPD_Msk                    0x00000004             /*!< Enable powerdown for external oscillator */

/*--  RXEVEN: PMU RX Event generation enable register ---------------------------------------------------------*/
typedef struct {
  uint32_t GPIOAEV                :1;                                /*!< Enable RX event from GPIOA pins */
  uint32_t GPIOBEV                :1;                                /*!< Enable RX event from GPIOB pins */
} _PMU_RXEVEN_bits;

/* Bit field positions: */
#define PMU_RXEVEN_GPIOAEV_Pos                0                      /*!< Enable RX event from GPIOA pins */
#define PMU_RXEVEN_GPIOBEV_Pos                1                      /*!< Enable RX event from GPIOB pins */

/* Bit field masks: */
#define PMU_RXEVEN_GPIOAEV_Msk                0x00000001             /*!< Enable RX event from GPIOA pins */
#define PMU_RXEVEN_GPIOBEV_Msk                0x00000002             /*!< Enable RX event from GPIOB pins */

typedef struct {
  union {                                                               /*!< PMU Configuration Register */
    __IO uint32_t CFG;                                               /*!< CFG    : type used for word access */
    __IO _PMU_CFG_bits  CFG_bit;                                     /*!< CFG_bit: structure used for bit access */
  };
  union {                                                               /*!< PMU Powerup Delay Value */
    __IO uint32_t PUDEL;                                             /*!< PUDEL    : type used for word access */
    __IO _PMU_PUDEL_bits  PUDEL_bit;                                 /*!< PUDEL_bit: structure used for bit access */
  };
  union {                                                               /*!< PMU Enable Powerdown for peripheral */
    __IO uint32_t PDEN;                                              /*!< PDEN    : type used for word access */
    __IO _PMU_PDEN_bits  PDEN_bit;                                   /*!< PDEN_bit: structure used for bit access */
  };
  union {                                                               /*!< PMU RX Event generation enable register */
    __IO uint32_t RXEVEN;                                            /*!< RXEVEN    : type used for word access */
    __IO _PMU_RXEVEN_bits  RXEVEN_bit;                               /*!< RXEVEN_bit: structure used for bit access */
  };
} PMU_TypeDef;

/******************************************************************************/
/*                         WDT registers                                      */
/******************************************************************************/

/*--  LOAD: Watchdog Load Register ----------------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!< Begin value counter */
} _WDT_LOAD_bits;

/* Bit field positions: */
#define WDT_LOAD_VAL_Pos                      0                      /*!< Begin value counter */

/* Bit field masks: */
#define WDT_LOAD_VAL_Msk                      0xFFFFFFFF             /*!< Begin value counter */

/*--  VALUE: Watchdog Value Register --------------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!< Current value counter */
} _WDT_VALUE_bits;

/* Bit field positions: */
#define WDT_VALUE_VAL_Pos                     0                      /*!< Current value counter */

/* Bit field masks: */
#define WDT_VALUE_VAL_Msk                     0xFFFFFFFF             /*!< Current value counter */

/*--  CTRL: Watchdog Control Register -------------------------------------------------------------------------*/
typedef struct {
  uint32_t INTEN                  :1;                                /*!< Enable the interrupt event */
  uint32_t RESEN                  :1;                                /*!< Enable watchdog reset output */
} _WDT_CTRL_bits;

/* Bit field positions: */
#define WDT_CTRL_INTEN_Pos                    0                      /*!< Enable the interrupt event */
#define WDT_CTRL_RESEN_Pos                    1                      /*!< Enable watchdog reset output */

/* Bit field masks: */
#define WDT_CTRL_INTEN_Msk                    0x00000001             /*!< Enable the interrupt event */
#define WDT_CTRL_RESEN_Msk                    0x00000002             /*!< Enable watchdog reset output */

/*--  INTCLR: Watchdog Clear Interrupt Register ---------------------------------------------------------------*/
typedef struct {
  uint32_t WDTCLR                 :32;                               /*!< Reset interrupt WDT */
} _WDT_INTCLR_bits;

/* Bit field positions: */
#define WDT_INTCLR_WDTCLR_Pos                 0                      /*!< Reset interrupt WDT */

/* Bit field masks: */
#define WDT_INTCLR_WDTCLR_Msk                 0xFFFFFFFF             /*!< Reset interrupt WDT */

/*--  RIS: Watchdog Raw Interrupt Status Register -------------------------------------------------------------*/
typedef struct {
  uint32_t RAWWDTINT              :1;                                /*!< Raw interrupt status from the counter */
} _WDT_RIS_bits;

/* Bit field positions: */
#define WDT_RIS_RAWWDTINT_Pos                 0                      /*!< Raw interrupt status from the counter */

/* Bit field masks: */
#define WDT_RIS_RAWWDTINT_Msk                 0x00000001             /*!< Raw interrupt status from the counter */

/*--  MIS: Watchdog Interrupt Status Register -----------------------------------------------------------------*/
typedef struct {
  uint32_t WDTINT                 :1;                                /*!< Enabled interrupt status from the counter */
} _WDT_MIS_bits;

/* Bit field positions: */
#define WDT_MIS_WDTINT_Pos                    0                      /*!< Enabled interrupt status from the counter */

/* Bit field masks: */
#define WDT_MIS_WDTINT_Msk                    0x00000001             /*!< Enabled interrupt status from the counter */

/*--  LOCK: Watchdog Lock Register ----------------------------------------------------------------------------*/
typedef struct {
  uint32_t REGWRDIS               :1;                                /*!< Disable write to all registers Watchdog */
} _WDT_LOCK_bits;

/* Bit field positions: */
#define WDT_LOCK_REGWRDIS_Pos                 0                      /*!< Disable write to all registers Watchdog */

/* Bit field masks: */
#define WDT_LOCK_REGWRDIS_Msk                 0x00000001             /*!< Disable write to all registers Watchdog */

typedef struct {
  union {                                                               /*!< Watchdog Load Register */
    __IO uint32_t LOAD;                                              /*!< LOAD    : type used for word access */
    __IO _WDT_LOAD_bits  LOAD_bit;                                   /*!< LOAD_bit: structure used for bit access */
  };
  union {                                                               /*!< Watchdog Value Register */
    __I uint32_t VALUE;                                              /*!< VALUE    : type used for word access */
    __I _WDT_VALUE_bits  VALUE_bit;                                  /*!< VALUE_bit: structure used for bit access */
  };
  union {                                                               /*!< Watchdog Control Register */
    __IO uint32_t CTRL;                                              /*!< CTRL    : type used for word access */
    __IO _WDT_CTRL_bits  CTRL_bit;                                   /*!< CTRL_bit: structure used for bit access */
  };
  union {                                                               /*!< Watchdog Clear Interrupt Register */
    __O uint32_t INTCLR;                                             /*!< INTCLR    : type used for word access */
    __O _WDT_INTCLR_bits  INTCLR_bit;                                /*!< INTCLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Watchdog Raw Interrupt Status Register */
    __I uint32_t RIS;                                                /*!< RIS    : type used for word access */
    __I _WDT_RIS_bits  RIS_bit;                                      /*!< RIS_bit: structure used for bit access */
  };
  union {                                                               /*!< Watchdog Interrupt Status Register */
    __I uint32_t MIS;                                                /*!< MIS    : type used for word access */
    __I _WDT_MIS_bits  MIS_bit;                                      /*!< MIS_bit: structure used for bit access */
  };
    __IO uint32_t Reserved0[762];
  union {                                                               /*!< Watchdog Lock Register */
    __O uint32_t LOCK;                                               /*!< LOCK    : type used for word access */
    __O _WDT_LOCK_bits  LOCK_bit;                                    /*!< LOCK_bit: structure used for bit access */
  };
} WDT_TypeDef;

/******************************************************************************/
/*                         TMR registers                                      */
/******************************************************************************/

/*--  CTRL: Control Timer register ----------------------------------------------------------------------------*/
typedef struct {
  uint32_t ON                     :1;                                /*!< Enable Timer */
  uint32_t EXTINEN                :1;                                /*!< Enable external input as ENABLE */
  uint32_t EXTINCLK               :1;                                /*!< Enable external input as CLK */
  uint32_t INTEN                  :1;                                /*!< Enable Timer interrupt */
} _TMR_CTRL_bits;

/* Bit field positions: */
#define TMR_CTRL_ON_Pos                       0                      /*!< Enable Timer */
#define TMR_CTRL_EXTINEN_Pos                  1                      /*!< Enable external input as ENABLE */
#define TMR_CTRL_EXTINCLK_Pos                 2                      /*!< Enable external input as CLK */
#define TMR_CTRL_INTEN_Pos                    3                      /*!< Enable Timer interrupt */

/* Bit field masks: */
#define TMR_CTRL_ON_Msk                       0x00000001             /*!< Enable Timer */
#define TMR_CTRL_EXTINEN_Msk                  0x00000002             /*!< Enable external input as ENABLE */
#define TMR_CTRL_EXTINCLK_Msk                 0x00000004             /*!< Enable external input as CLK */
#define TMR_CTRL_INTEN_Msk                    0x00000008             /*!< Enable Timer interrupt */

/*--  VALUE: Current value timer register ---------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!< Current value timer */
} _TMR_VALUE_bits;

/* Bit field positions: */
#define TMR_VALUE_VAL_Pos                     0                      /*!< Current value timer */

/* Bit field masks: */
#define TMR_VALUE_VAL_Msk                     0xFFFFFFFF             /*!< Current value timer */

/*--  LOAD: Reload value timer register -----------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!< Reload value. A write to this register sets the current value */
} _TMR_LOAD_bits;

/* Bit field positions: */
#define TMR_LOAD_VAL_Pos                      0                      /*!< Reload value. A write to this register sets the current value */

/* Bit field masks: */
#define TMR_LOAD_VAL_Msk                      0xFFFFFFFF             /*!< Reload value. A write to this register sets the current value */

/*--  INTSTATUS: Interrupt status register --------------------------------------------------------------------*/
typedef struct {
  uint32_t INT                    :1;                                /*!< Timer interrupt flag */
} _TMR_INTSTATUS_bits;

/* Bit field positions: */
#define TMR_INTSTATUS_INT_Pos                 0                      /*!< Timer interrupt flag */

/* Bit field masks: */
#define TMR_INTSTATUS_INT_Msk                 0x00000001             /*!< Timer interrupt flag */

/*--  DMAREQ: DMA request register ----------------------------------------------------------------------------*/
typedef struct {
  uint32_t EN                     :1;                                /*!<  */
} _TMR_DMAREQ_bits;

/* Bit field positions: */
#define TMR_DMAREQ_EN_Pos                     0                      /*!<  */

/* Bit field masks: */
#define TMR_DMAREQ_EN_Msk                     0x00000001             /*!<  */

/*--  ADCSOC: ADC start of conversion register ----------------------------------------------------------------*/
typedef struct {
  uint32_t EN                     :1;                                /*!<  */
} _TMR_ADCSOC_bits;

/* Bit field positions: */
#define TMR_ADCSOC_EN_Pos                     0                      /*!<  */

/* Bit field masks: */
#define TMR_ADCSOC_EN_Msk                     0x00000001             /*!<  */

typedef struct {
  union {                                                               /*!< Control Timer register */
    __IO uint32_t CTRL;                                              /*!< CTRL    : type used for word access */
    __IO _TMR_CTRL_bits  CTRL_bit;                                   /*!< CTRL_bit: structure used for bit access */
  };
  union {                                                               /*!< Current value timer register */
    __IO uint32_t VALUE;                                             /*!< VALUE    : type used for word access */
    __IO _TMR_VALUE_bits  VALUE_bit;                                 /*!< VALUE_bit: structure used for bit access */
  };
  union {                                                               /*!< Reload value timer register */
    __IO uint32_t LOAD;                                              /*!< LOAD    : type used for word access */
    __IO _TMR_LOAD_bits  LOAD_bit;                                   /*!< LOAD_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt status register */
    __IO uint32_t INTSTATUS;                                           /*!< INTSTATUS    : type used for word access */
    __IO _TMR_INTSTATUS_bits  INTSTATUS_bit;                         /*!< INTSTATUS_bit: structure used for bit access */
  };
  union {                                                               /*!< DMA request register */
    __IO uint32_t DMAREQ;                                            /*!< DMAREQ    : type used for word access */
    __IO _TMR_DMAREQ_bits  DMAREQ_bit;                               /*!< DMAREQ_bit: structure used for bit access */
  };
  union {                                                               /*!< ADC start of conversion register */
    __IO uint32_t ADCSOC;                                            /*!< ADCSOC    : type used for word access */
    __IO _TMR_ADCSOC_bits  ADCSOC_bit;                               /*!< ADCSOC_bit: structure used for bit access */
  };
} TMR_TypeDef;

/******************************************************************************/
/*                         ADC registers                                      */
/******************************************************************************/

/*--  SEQEN: Enable sequencer register ------------------------------------------------------------------------*/
typedef struct {
  uint32_t SEQEN0                 :1;                                /*!< Enable sequencer 0 */
  uint32_t SEQEN1                 :1;                                /*!< Enable sequencer 1 */
} _ADC_SEQEN_bits;

/* Bit field positions: */
#define ADC_SEQEN_SEQEN0_Pos                  0                      /*!< Enable sequencer 0 */
#define ADC_SEQEN_SEQEN1_Pos                  1                      /*!< Enable sequencer 1 */

/* Bit field masks: */
#define ADC_SEQEN_SEQEN0_Msk                  0x00000001             /*!< Enable sequencer 0 */
#define ADC_SEQEN_SEQEN1_Msk                  0x00000002             /*!< Enable sequencer 1 */

/*--  SEQSYNC: Sequencer sync register ------------------------------------------------------------------------*/
typedef struct {
  uint32_t SYNC0                  :1;                                /*!< Enable sequencer 0 software sync */
  uint32_t SYNC1                  :1;                                /*!< Enable sequencer 1 software sync */
  uint32_t                        :29;                               /*!< RESERVED */
  uint32_t GSYNC                  :1;                                /*!< Sync all sequencers */
} _ADC_SEQSYNC_bits;

/* Bit field positions: */
#define ADC_SEQSYNC_SYNC0_Pos                 0                      /*!< Enable sequencer 0 software sync */
#define ADC_SEQSYNC_SYNC1_Pos                 1                      /*!< Enable sequencer 1 software sync */
#define ADC_SEQSYNC_GSYNC_Pos                 31                     /*!< Sync all sequencers */

/* Bit field masks: */
#define ADC_SEQSYNC_SYNC0_Msk                 0x00000001             /*!< Enable sequencer 0 software sync */
#define ADC_SEQSYNC_SYNC1_Msk                 0x00000002             /*!< Enable sequencer 1 software sync */
#define ADC_SEQSYNC_GSYNC_Msk                 0x80000000             /*!< Sync all sequencers */

/*--  FSTAT: FIFO overflow status register --------------------------------------------------------------------*/
typedef struct {
  uint32_t OV0                    :1;                                /*!< Sequencer 0 FIFO overflow */
  uint32_t OV1                    :1;                                /*!< Sequencer 1 FIFO overflow */
  uint32_t                        :6;                                /*!< RESERVED */
  uint32_t UN0                    :1;                                /*!< Sequencer 0 FIFO underflow */
  uint32_t UN1                    :1;                                /*!< Sequencer 1 FIFO underflow */
  uint32_t                        :6;                                /*!< RESERVED */
  uint32_t DOV0                   :1;                                /*!< Sequencer 0 FIFO DMA request overflow */
  uint32_t DOV1                   :1;                                /*!< Sequencer 1 FIFO DMA request overflow */
} _ADC_FSTAT_bits;

/* Bit field positions: */
#define ADC_FSTAT_OV0_Pos                     0                      /*!< Sequencer 0 FIFO overflow */
#define ADC_FSTAT_OV1_Pos                     1                      /*!< Sequencer 1 FIFO overflow */
#define ADC_FSTAT_UN0_Pos                     8                      /*!< Sequencer 0 FIFO underflow */
#define ADC_FSTAT_UN1_Pos                     9                      /*!< Sequencer 1 FIFO underflow */
#define ADC_FSTAT_DOV0_Pos                    16                     /*!< Sequencer 0 FIFO DMA request overflow */
#define ADC_FSTAT_DOV1_Pos                    17                     /*!< Sequencer 1 FIFO DMA request overflow */

/* Bit field masks: */
#define ADC_FSTAT_OV0_Msk                     0x00000001             /*!< Sequencer 0 FIFO overflow */
#define ADC_FSTAT_OV1_Msk                     0x00000002             /*!< Sequencer 1 FIFO overflow */
#define ADC_FSTAT_UN0_Msk                     0x00000100             /*!< Sequencer 0 FIFO underflow */
#define ADC_FSTAT_UN1_Msk                     0x00000200             /*!< Sequencer 1 FIFO underflow */
#define ADC_FSTAT_DOV0_Msk                    0x00010000             /*!< Sequencer 0 FIFO DMA request overflow */
#define ADC_FSTAT_DOV1_Msk                    0x00020000             /*!< Sequencer 1 FIFO DMA request overflow */

/*--  BSTAT: Busy status register -----------------------------------------------------------------------------*/
typedef struct {
  uint32_t SEQBUSY0               :1;                                /*!< Sequencer 0 busy */
  uint32_t SEQBUSY1               :1;                                /*!< Sequencer 1 busy */
  uint32_t                        :14;                               /*!< RESERVED */
  uint32_t ADCBUSY                :1;                                /*!< ADC module conversion busy */
} _ADC_BSTAT_bits;

/* Bit field positions: */
#define ADC_BSTAT_SEQBUSY0_Pos                0                      /*!< Sequencer 0 busy */
#define ADC_BSTAT_SEQBUSY1_Pos                1                      /*!< Sequencer 1 busy */
#define ADC_BSTAT_ADCBUSY_Pos                 16                     /*!< ADC module conversion busy */

/* Bit field masks: */
#define ADC_BSTAT_SEQBUSY0_Msk                0x00000001             /*!< Sequencer 0 busy */
#define ADC_BSTAT_SEQBUSY1_Msk                0x00000002             /*!< Sequencer 1 busy */
#define ADC_BSTAT_ADCBUSY_Msk                 0x00010000             /*!< ADC module conversion busy */

/*--  DCTRIG: Digital comparator output trigger status register -----------------------------------------------*/
typedef struct {
  uint32_t TOS0                   :1;                                /*!< DC 0 output trigger status */
  uint32_t TOS1                   :1;                                /*!< DC 1 output trigger status */
  uint32_t TOS2                   :1;                                /*!< DC 2 output trigger status */
  uint32_t TOS3                   :1;                                /*!< DC 3 output trigger status */
  uint32_t                        :12;                               /*!< RESERVED */
  uint32_t DCEV0                  :1;                                /*!< Digital compare event 0 */
  uint32_t DCEV1                  :1;                                /*!< Digital compare event 1 */
  uint32_t DCEV2                  :1;                                /*!< Digital compare event 2 */
  uint32_t DCEV3                  :1;                                /*!< Digital compare event 3 */
} _ADC_DCTRIG_bits;

/* Bit field positions: */
#define ADC_DCTRIG_TOS0_Pos                   0                      /*!< DC 0 output trigger status */
#define ADC_DCTRIG_TOS1_Pos                   1                      /*!< DC 1 output trigger status */
#define ADC_DCTRIG_TOS2_Pos                   2                      /*!< DC 2 output trigger status */
#define ADC_DCTRIG_TOS3_Pos                   3                      /*!< DC 3 output trigger status */
#define ADC_DCTRIG_DCEV0_Pos                  16                     /*!< Digital compare event 0 */
#define ADC_DCTRIG_DCEV1_Pos                  17                     /*!< Digital compare event 1 */
#define ADC_DCTRIG_DCEV2_Pos                  18                     /*!< Digital compare event 2 */
#define ADC_DCTRIG_DCEV3_Pos                  19                     /*!< Digital compare event 3 */

/* Bit field masks: */
#define ADC_DCTRIG_TOS0_Msk                   0x00000001             /*!< DC 0 output trigger status */
#define ADC_DCTRIG_TOS1_Msk                   0x00000002             /*!< DC 1 output trigger status */
#define ADC_DCTRIG_TOS2_Msk                   0x00000004             /*!< DC 2 output trigger status */
#define ADC_DCTRIG_TOS3_Msk                   0x00000008             /*!< DC 3 output trigger status */
#define ADC_DCTRIG_DCEV0_Msk                  0x00010000             /*!< Digital compare event 0 */
#define ADC_DCTRIG_DCEV1_Msk                  0x00020000             /*!< Digital compare event 1 */
#define ADC_DCTRIG_DCEV2_Msk                  0x00040000             /*!< Digital compare event 2 */
#define ADC_DCTRIG_DCEV3_Msk                  0x00080000             /*!< Digital compare event 3 */

/*--  CICNT: Interrupt counter clear control ------------------------------------------------------------------*/
typedef struct {
  uint32_t ICNT0                  :1;                                /*!< Clear interrupt counter on sequencer 0 start */
  uint32_t ICNT1                  :1;                                /*!< Clear interrupt counter on sequencer 1 start */
} _ADC_CICNT_bits;

/* Bit field positions: */
#define ADC_CICNT_ICNT0_Pos                   0                      /*!< Clear interrupt counter on sequencer 0 start */
#define ADC_CICNT_ICNT1_Pos                   1                      /*!< Clear interrupt counter on sequencer 1 start */

/* Bit field masks: */
#define ADC_CICNT_ICNT0_Msk                   0x00000001             /*!< Clear interrupt counter on sequencer 0 start */
#define ADC_CICNT_ICNT1_Msk                   0x00000002             /*!< Clear interrupt counter on sequencer 1 start */

/*--  EMUX: Sequencer start event selection register ----------------------------------------------------------*/
typedef struct {
  uint32_t EM0                    :4;                                /*!< Select start event for sequencer 0 */
  uint32_t EM1                    :4;                                /*!< Select start event for sequencer 1 */
} _ADC_EMUX_bits;

/* Bit field positions: */
#define ADC_EMUX_EM0_Pos                      0                      /*!< Select start event for sequencer 0 */
#define ADC_EMUX_EM1_Pos                      4                      /*!< Select start event for sequencer 1 */

/* Bit field masks: */
#define ADC_EMUX_EM0_Msk                      0x0000000F             /*!< Select start event for sequencer 0 */
#define ADC_EMUX_EM1_Msk                      0x000000F0             /*!< Select start event for sequencer 1 */

/* Bit field enums: */
typedef enum {
  ADC_EMUX_EM0_SwReq                         = 0x0,                  /*!< software request by GSYNC bit */
  ADC_EMUX_EM0_GPIOA                         = 0x1,                  /*!<  GPIOA interrupt */
  ADC_EMUX_EM0_GPIOB                         = 0x2,                  /*!<  GPIOB interrupt */
  ADC_EMUX_EM0_TMR0                          = 0x3,                  /*!< Timer 0 request */
  ADC_EMUX_EM0_TMR1                          = 0x4,                  /*!< Timer 1 request */
  ADC_EMUX_EM0_TMR2                          = 0x5,                  /*!< Timer 2 request */
  ADC_EMUX_EM0_TMR3                          = 0x6,                  /*!< Timer 3 request */
  ADC_EMUX_EM0_PWM012A                       = 0x7,                  /*!< PWM0,1,2 A channel request */
  ADC_EMUX_EM0_PWM012B                       = 0x8,                  /*!< PWM0,1,2 B channel request */
  ADC_EMUX_EM0_Cycle                         = 0xF,                  /*!< Cycle mode */
} ADC_EMUX_EM0_Enum;

typedef enum {
  ADC_EMUX_EM1_SwReq                         = 0x0,                  /*!< software request by GSYNC bit */
  ADC_EMUX_EM1_GPIOA                         = 0x1,                  /*!<  GPIOA interrupt */
  ADC_EMUX_EM1_GPIOB                         = 0x2,                  /*!<  GPIOB interrupt */
  ADC_EMUX_EM1_TMR0                          = 0x3,                  /*!< Timer 0 request */
  ADC_EMUX_EM1_TMR1                          = 0x4,                  /*!< Timer 1 request */
  ADC_EMUX_EM1_TMR2                          = 0x5,                  /*!< Timer 2 request */
  ADC_EMUX_EM1_TMR3                          = 0x6,                  /*!< Timer 3 request */
  ADC_EMUX_EM1_PWM012A                       = 0x7,                  /*!< PWM0,1,2 A channel request */
  ADC_EMUX_EM1_PWM012B                       = 0x8,                  /*!< PWM0,1,2 B channel request */
  ADC_EMUX_EM1_Cycle                         = 0xF,                  /*!< Cycle mode */
} ADC_EMUX_EM1_Enum;

/*--  RIS: Raw interrupt status register ----------------------------------------------------------------------*/
typedef struct {
  uint32_t SEQRIS0                :1;                                /*!< Sequencer 0 raw interrupt status */
  uint32_t SEQRIS1                :1;                                /*!< Sequencer 1 raw interrupt status */
  uint32_t                        :6;                                /*!< RESERVED */
  uint32_t DCRIS0                 :1;                                /*!< Raw interrupt status of Digital Comparator 0 */
  uint32_t DCRIS1                 :1;                                /*!< Raw interrupt status of Digital Comparator 1 */
  uint32_t DCRIS2                 :1;                                /*!< Raw interrupt status of Digital Comparator 2 */
  uint32_t DCRIS3                 :1;                                /*!< Raw interrupt status of Digital Comparator 3 */
} _ADC_RIS_bits;

/* Bit field positions: */
#define ADC_RIS_SEQRIS0_Pos                   0                      /*!< Sequencer 0 raw interrupt status */
#define ADC_RIS_SEQRIS1_Pos                   1                      /*!< Sequencer 1 raw interrupt status */
#define ADC_RIS_DCRIS0_Pos                    8                      /*!< Raw interrupt status of Digital Comparator 0 */
#define ADC_RIS_DCRIS1_Pos                    9                      /*!< Raw interrupt status of Digital Comparator 1 */
#define ADC_RIS_DCRIS2_Pos                    10                     /*!< Raw interrupt status of Digital Comparator 2 */
#define ADC_RIS_DCRIS3_Pos                    11                     /*!< Raw interrupt status of Digital Comparator 3 */

/* Bit field masks: */
#define ADC_RIS_SEQRIS0_Msk                   0x00000001             /*!< Sequencer 0 raw interrupt status */
#define ADC_RIS_SEQRIS1_Msk                   0x00000002             /*!< Sequencer 1 raw interrupt status */
#define ADC_RIS_DCRIS0_Msk                    0x00000100             /*!< Raw interrupt status of Digital Comparator 0 */
#define ADC_RIS_DCRIS1_Msk                    0x00000200             /*!< Raw interrupt status of Digital Comparator 1 */
#define ADC_RIS_DCRIS2_Msk                    0x00000400             /*!< Raw interrupt status of Digital Comparator 2 */
#define ADC_RIS_DCRIS3_Msk                    0x00000800             /*!< Raw interrupt status of Digital Comparator 3 */

/*--  IM: Interrupt mask register -----------------------------------------------------------------------------*/
typedef struct {
  uint32_t SEQIM0                 :1;                                /*!< Sequencer 0 interrupt mask */
  uint32_t SEQIM1                 :1;                                /*!< Sequencer 1 interrupt mask */
  uint32_t                        :6;                                /*!< RESERVED */
  uint32_t DCIM0                  :1;                                /*!< Interrupt mask of Digital Comparator 0 */
  uint32_t DCIM1                  :1;                                /*!< Interrupt mask of Digital Comparator 1 */
  uint32_t DCIM2                  :1;                                /*!< Interrupt mask of Digital Comparator 2 */
  uint32_t DCIM3                  :1;                                /*!< Interrupt mask of Digital Comparator 3 */
} _ADC_IM_bits;

/* Bit field positions: */
#define ADC_IM_SEQIM0_Pos                     0                      /*!< Sequencer 0 interrupt mask */
#define ADC_IM_SEQIM1_Pos                     1                      /*!< Sequencer 1 interrupt mask */
#define ADC_IM_DCIM0_Pos                      8                      /*!< Interrupt mask of Digital Comparator 0 */
#define ADC_IM_DCIM1_Pos                      9                      /*!< Interrupt mask of Digital Comparator 1 */
#define ADC_IM_DCIM2_Pos                      10                     /*!< Interrupt mask of Digital Comparator 2 */
#define ADC_IM_DCIM3_Pos                      11                     /*!< Interrupt mask of Digital Comparator 3 */

/* Bit field masks: */
#define ADC_IM_SEQIM0_Msk                     0x00000001             /*!< Sequencer 0 interrupt mask */
#define ADC_IM_SEQIM1_Msk                     0x00000002             /*!< Sequencer 1 interrupt mask */
#define ADC_IM_DCIM0_Msk                      0x00000100             /*!< Interrupt mask of Digital Comparator 0 */
#define ADC_IM_DCIM1_Msk                      0x00000200             /*!< Interrupt mask of Digital Comparator 1 */
#define ADC_IM_DCIM2_Msk                      0x00000400             /*!< Interrupt mask of Digital Comparator 2 */
#define ADC_IM_DCIM3_Msk                      0x00000800             /*!< Interrupt mask of Digital Comparator 3 */

/*--  MIS: Masked interrupt status and clear register ---------------------------------------------------------*/
typedef struct {
  uint32_t SEQMIS0                :1;                                /*!< Sequencer 0 masked interrupt status */
  uint32_t SEQMIS1                :1;                                /*!< Sequencer 1 masked interrupt status  */
  uint32_t                        :6;                                /*!< RESERVED */
  uint32_t DCMIS0                 :1;                                /*!< DC 0 masked interrupt status  */
  uint32_t DCMIS1                 :1;                                /*!< DC 1 masked interrupt status  */
  uint32_t DCMIS2                 :1;                                /*!< DC 2 masked interrupt status  */
  uint32_t DCMIS3                 :1;                                /*!< DC 3 masked interrupt status  */
} _ADC_MIS_bits;

/* Bit field positions: */
#define ADC_MIS_SEQMIS0_Pos                   0                      /*!< Sequencer 0 masked interrupt status */
#define ADC_MIS_SEQMIS1_Pos                   1                      /*!< Sequencer 1 masked interrupt status  */
#define ADC_MIS_DCMIS0_Pos                    8                      /*!< DC 0 masked interrupt status  */
#define ADC_MIS_DCMIS1_Pos                    9                      /*!< DC 1 masked interrupt status  */
#define ADC_MIS_DCMIS2_Pos                    10                     /*!< DC 2 masked interrupt status  */
#define ADC_MIS_DCMIS3_Pos                    11                     /*!< DC 3 masked interrupt status  */

/* Bit field masks: */
#define ADC_MIS_SEQMIS0_Msk                   0x00000001             /*!< Sequencer 0 masked interrupt status */
#define ADC_MIS_SEQMIS1_Msk                   0x00000002             /*!< Sequencer 1 masked interrupt status  */
#define ADC_MIS_DCMIS0_Msk                    0x00000100             /*!< DC 0 masked interrupt status  */
#define ADC_MIS_DCMIS1_Msk                    0x00000200             /*!< DC 1 masked interrupt status  */
#define ADC_MIS_DCMIS2_Msk                    0x00000400             /*!< DC 2 masked interrupt status  */
#define ADC_MIS_DCMIS3_Msk                    0x00000800             /*!< DC 3 masked interrupt status  */

/*--  IC: Interrupt clear register ----------------------------------------------------------------------------*/
typedef struct {
  uint32_t SEQIC0                 :1;                                /*!< Sequencer 0 interrupt status clear */
  uint32_t SEQIC1                 :1;                                /*!< Sequencer 1 interrupt status clear */
  uint32_t                        :6;                                /*!< RESERVED */
  uint32_t DCIC0                  :1;                                /*!< DC 0 interrupt status clear */
  uint32_t DCIC1                  :1;                                /*!< DC 1 interrupt status clear */
  uint32_t DCIC2                  :1;                                /*!< DC 2 interrupt status clear */
  uint32_t DCIC3                  :1;                                /*!< DC 3 interrupt status clear */
} _ADC_IC_bits;

/* Bit field positions: */
#define ADC_IC_SEQIC0_Pos                     0                      /*!< Sequencer 0 interrupt status clear */
#define ADC_IC_SEQIC1_Pos                     1                      /*!< Sequencer 1 interrupt status clear */
#define ADC_IC_DCIC0_Pos                      8                      /*!< DC 0 interrupt status clear */
#define ADC_IC_DCIC1_Pos                      9                      /*!< DC 1 interrupt status clear */
#define ADC_IC_DCIC2_Pos                      10                     /*!< DC 2 interrupt status clear */
#define ADC_IC_DCIC3_Pos                      11                     /*!< DC 3 interrupt status clear */

/* Bit field masks: */
#define ADC_IC_SEQIC0_Msk                     0x00000001             /*!< Sequencer 0 interrupt status clear */
#define ADC_IC_SEQIC1_Msk                     0x00000002             /*!< Sequencer 1 interrupt status clear */
#define ADC_IC_DCIC0_Msk                      0x00000100             /*!< DC 0 interrupt status clear */
#define ADC_IC_DCIC1_Msk                      0x00000200             /*!< DC 1 interrupt status clear */
#define ADC_IC_DCIC2_Msk                      0x00000400             /*!< DC 2 interrupt status clear */
#define ADC_IC_DCIC3_Msk                      0x00000800             /*!< DC 3 interrupt status clear */

/*-- SEQ: RQSEL: Sequencer request ADC channels selection register --------------------------------------------*/
typedef struct {
  uint32_t RQ0                    :2;                                /*!< Select ADC channel for request 0 */
  uint32_t                        :2;                                /*!< RESERVED */
  uint32_t RQ1                    :2;                                /*!< Select ADC channel for request 1 */
  uint32_t                        :2;                                /*!< RESERVED */
  uint32_t RQ2                    :2;                                /*!< Select ADC channel for request 2 */
  uint32_t                        :2;                                /*!< RESERVED */
  uint32_t RQ3                    :2;                                /*!< Select ADC channel for request 3 */
} _ADC_SEQ_RQSEL_bits;

/* Bit field positions: */
#define ADC_SEQ_RQSEL_RQ0_Pos                 0                      /*!< Select ADC channel for request 0 */
#define ADC_SEQ_RQSEL_RQ1_Pos                 4                      /*!< Select ADC channel for request 1 */
#define ADC_SEQ_RQSEL_RQ2_Pos                 8                      /*!< Select ADC channel for request 2 */
#define ADC_SEQ_RQSEL_RQ3_Pos                 12                     /*!< Select ADC channel for request 3 */

/* Bit field masks: */
#define ADC_SEQ_RQSEL_RQ0_Msk                 0x00000003             /*!< Select ADC channel for request 0 */
#define ADC_SEQ_RQSEL_RQ1_Msk                 0x00000030             /*!< Select ADC channel for request 1 */
#define ADC_SEQ_RQSEL_RQ2_Msk                 0x00000300             /*!< Select ADC channel for request 2 */
#define ADC_SEQ_RQSEL_RQ3_Msk                 0x00003000             /*!< Select ADC channel for request 3 */

/*-- SEQ: RQCTL: Sequencer request control register -----------------------------------------------------------*/
typedef struct {
  uint32_t RQMAX                  :2;                                /*!< Request queue max depth */
  uint32_t                        :6;                                /*!< RESERVED */
  uint32_t QAVGEN                 :1;                                /*!< Queue avearage (scanning) enable */
  uint32_t QAVGVAL                :3;                                /*!< Queue average value */
} _ADC_SEQ_RQCTL_bits;

/* Bit field positions: */
#define ADC_SEQ_RQCTL_RQMAX_Pos               0                      /*!< Request queue max depth */
#define ADC_SEQ_RQCTL_QAVGEN_Pos              8                      /*!< Queue avearage (scanning) enable */
#define ADC_SEQ_RQCTL_QAVGVAL_Pos             9                      /*!< Queue average value */

/* Bit field masks: */
#define ADC_SEQ_RQCTL_RQMAX_Msk               0x00000003             /*!< Request queue max depth */
#define ADC_SEQ_RQCTL_QAVGEN_Msk              0x00000100             /*!< Queue avearage (scanning) enable */
#define ADC_SEQ_RQCTL_QAVGVAL_Msk             0x00000E00             /*!< Queue average value */

/* Bit field enums: */
typedef enum {
  ADC_SEQ_RQCTL_QAVGVAL_Disable              = 0x0,                  /*!< Average disabled */
  ADC_SEQ_RQCTL_QAVGVAL_Average2             = 0x1,                  /*!< Average with 2 measures */
  ADC_SEQ_RQCTL_QAVGVAL_Average4             = 0x2,                  /*!< Average with 4 measures */
  ADC_SEQ_RQCTL_QAVGVAL_Average8             = 0x3,                  /*!< Average with 8 measures */
  ADC_SEQ_RQCTL_QAVGVAL_Average16            = 0x4,                  /*!< Average with 16 measures */
  ADC_SEQ_RQCTL_QAVGVAL_Average32            = 0x5,                  /*!< Average with 32 measures */
  ADC_SEQ_RQCTL_QAVGVAL_Average64            = 0x6,                  /*!< Average with 64 measures */
} ADC_SEQ_RQCTL_QAVGVAL_Enum;

/*-- SEQ: RQSTAT: Sequencer request status register -----------------------------------------------------------*/
typedef struct {
  uint32_t RQPTR                  :2;                                /*!< Pointer to queue current request */
  uint32_t                        :6;                                /*!< RESERVED */
  uint32_t RQBUSY                 :1;                                /*!< Active request status */
} _ADC_SEQ_RQSTAT_bits;

/* Bit field positions: */
#define ADC_SEQ_RQSTAT_RQPTR_Pos              0                      /*!< Pointer to queue current request */
#define ADC_SEQ_RQSTAT_RQBUSY_Pos             8                      /*!< Active request status */

/* Bit field masks: */
#define ADC_SEQ_RQSTAT_RQPTR_Msk              0x00000003             /*!< Pointer to queue current request */
#define ADC_SEQ_RQSTAT_RQBUSY_Msk             0x00000100             /*!< Active request status */

/*-- SEQ: DMACTL: Sequencer DMA control register --------------------------------------------------------------*/
typedef struct {
  uint32_t DMAEN                  :1;                                /*!< Enable DMA use */
  uint32_t                        :7;                                /*!< RESERVED */
  uint32_t WMARK                  :3;                                /*!< FIFO load threshold for DMA request generation */
} _ADC_SEQ_DMACTL_bits;

/* Bit field positions: */
#define ADC_SEQ_DMACTL_DMAEN_Pos              0                      /*!< Enable DMA use */
#define ADC_SEQ_DMACTL_WMARK_Pos              8                      /*!< FIFO load threshold for DMA request generation */

/* Bit field masks: */
#define ADC_SEQ_DMACTL_DMAEN_Msk              0x00000001             /*!< Enable DMA use */
#define ADC_SEQ_DMACTL_WMARK_Msk              0x00000700             /*!< FIFO load threshold for DMA request generation */

/* Bit field enums: */
typedef enum {
  ADC_SEQ_DMACTL_WMARK_Level1                = 0x1,                  /*!< 1 measure for dma request */
  ADC_SEQ_DMACTL_WMARK_Level2                = 0x2,                  /*!< 2 measures for dma request */
  ADC_SEQ_DMACTL_WMARK_Level4                = 0x3,                  /*!< 4 measures for dma request */
  ADC_SEQ_DMACTL_WMARK_Level8                = 0x4,                  /*!< 8 measures for dma request */
  ADC_SEQ_DMACTL_WMARK_Level16               = 0x5,                  /*!< 16 measures for dma request */
  ADC_SEQ_DMACTL_WMARK_Level32               = 0x6,                  /*!< 32 measures for dma request */
} ADC_SEQ_DMACTL_WMARK_Enum;

/*-- SEQ: CCTL: Sequencer ADC interrupt and restart counter control register ----------------------------------*/
typedef struct {
  uint32_t RCNT                   :8;                                /*!< Current number of ADC restarts by sequencer */
  uint32_t RAVGEN                 :1;                                /*!< Average of ADC restarts enable */
  uint32_t                        :7;                                /*!< RESERVED */
  uint32_t ICNT                   :8;                                /*!< Number of ADC requests for interrupt generation */
} _ADC_SEQ_CCTL_bits;

/* Bit field positions: */
#define ADC_SEQ_CCTL_RCNT_Pos                 0                      /*!< Current number of ADC restarts by sequencer */
#define ADC_SEQ_CCTL_RAVGEN_Pos               8                      /*!< Average of ADC restarts enable */
#define ADC_SEQ_CCTL_ICNT_Pos                 16                     /*!< Number of ADC requests for interrupt generation */

/* Bit field masks: */
#define ADC_SEQ_CCTL_RCNT_Msk                 0x000000FF             /*!< Current number of ADC restarts by sequencer */
#define ADC_SEQ_CCTL_RAVGEN_Msk               0x00000100             /*!< Average of ADC restarts enable */
#define ADC_SEQ_CCTL_ICNT_Msk                 0x00FF0000             /*!< Number of ADC requests for interrupt generation */

/*-- SEQ: CVAL: Sequencer ADC interrupt and restart counter current value register --------------------------------*/
typedef struct {
  uint32_t RCNT                   :8;                                /*!< Current number of ADC restarts by sequencer */
  uint32_t                        :8;                                /*!< RESERVED */
  uint32_t ICNT                   :8;                                /*!< Current number of ADC requests for interrupt generation */
  uint32_t ICLR                   :1;                                /*!< Clear interrupt counter */
} _ADC_SEQ_CVAL_bits;

/* Bit field positions: */
#define ADC_SEQ_CVAL_RCNT_Pos                 0                      /*!< Current number of ADC restarts by sequencer */
#define ADC_SEQ_CVAL_ICNT_Pos                 16                     /*!< Current number of ADC requests for interrupt generation */
#define ADC_SEQ_CVAL_ICLR_Pos                 24                     /*!< Clear interrupt counter */

/* Bit field masks: */
#define ADC_SEQ_CVAL_RCNT_Msk                 0x000000FF             /*!< Current number of ADC restarts by sequencer */
#define ADC_SEQ_CVAL_ICNT_Msk                 0x00FF0000             /*!< Current number of ADC requests for interrupt generation */
#define ADC_SEQ_CVAL_ICLR_Msk                 0x01000000             /*!< Clear interrupt counter */

/*-- SEQ: DC: Sequencer digital comparator selection register -------------------------------------------------*/
typedef struct {
  uint32_t DC0                    :1;                                /*!< Enable DC 0 */
  uint32_t DC1                    :1;                                /*!< Enable DC 1 */
  uint32_t DC2                    :1;                                /*!< Enable DC 2 */
  uint32_t DC3                    :1;                                /*!< Enable DC 3 */
} _ADC_SEQ_DC_bits;

/* Bit field positions: */
#define ADC_SEQ_DC_DC0_Pos                    0                      /*!< Enable DC 0 */
#define ADC_SEQ_DC_DC1_Pos                    1                      /*!< Enable DC 1 */
#define ADC_SEQ_DC_DC2_Pos                    2                      /*!< Enable DC 2 */
#define ADC_SEQ_DC_DC3_Pos                    3                      /*!< Enable DC 3 */

/* Bit field masks: */
#define ADC_SEQ_DC_DC0_Msk                    0x00000001             /*!< Enable DC 0 */
#define ADC_SEQ_DC_DC1_Msk                    0x00000002             /*!< Enable DC 1 */
#define ADC_SEQ_DC_DC2_Msk                    0x00000004             /*!< Enable DC 2 */
#define ADC_SEQ_DC_DC3_Msk                    0x00000008             /*!< Enable DC 3 */

/*-- SEQ: RTMR: Sequencer ADC restart timer register ----------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :24;                               /*!< Sequencer ADC restart timer value */
  uint32_t                        :7;                                /*!< RESERVED */
  uint32_t NOWAIT                 :1;                                /*!< Timer update with no waiting the end of current seq task */
} _ADC_SEQ_RTMR_bits;

/* Bit field positions: */
#define ADC_SEQ_RTMR_VAL_Pos                  0                      /*!< Sequencer ADC restart timer value */
#define ADC_SEQ_RTMR_NOWAIT_Pos               31                     /*!< Timer update with no waiting the end of current seq task */

/* Bit field masks: */
#define ADC_SEQ_RTMR_VAL_Msk                  0x00FFFFFF             /*!< Sequencer ADC restart timer value */
#define ADC_SEQ_RTMR_NOWAIT_Msk               0x80000000             /*!< Timer update with no waiting the end of current seq task */

/*-- SEQ: FLOAD: Sequencer FIFO load status register ----------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :6;                                /*!< Sequencer FIFO current load value */
} _ADC_SEQ_FLOAD_bits;

/* Bit field positions: */
#define ADC_SEQ_FLOAD_VAL_Pos                 0                      /*!< Sequencer FIFO current load value */

/* Bit field masks: */
#define ADC_SEQ_FLOAD_VAL_Msk                 0x0000003F             /*!< Sequencer FIFO current load value */

/*-- SEQ: FIFO: Sequencer FIFO register -----------------------------------------------------------------------*/
typedef struct {
  uint32_t DATA                   :12;                               /*!< AD conversion value */
} _ADC_SEQ_FIFO_bits;

/* Bit field positions: */
#define ADC_SEQ_FIFO_DATA_Pos                 0                      /*!< AD conversion value */

/* Bit field masks: */
#define ADC_SEQ_FIFO_DATA_Msk                 0x00000FFF             /*!< AD conversion value */

/*-- DC: CTL: Digital comparator control register -------------------------------------------------------------*/
typedef struct {
  uint32_t CIM                    :2;                                /*!< DC interrupt generation mode */
  uint32_t CIC                    :2;                                /*!< DC interrupt generation compare conditions */
  uint32_t CIE                    :1;                                /*!< Enable DC interrupt generation */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t CTM                    :2;                                /*!< DC output trigger mode */
  uint32_t CTC                    :2;                                /*!< DC output trigger compare conditions */
  uint32_t CTE                    :1;                                /*!< Enable DC output trigger */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t CHNL                   :2;                                /*!< ADC channel selection */
  uint32_t                        :6;                                /*!< RESERVED */
  uint32_t SRC                    :1;                                /*!< Select data source for comparation: ADC module (0) or sequencer(1) */
} _ADC_DC_CTL_bits;

/* Bit field positions: */
#define ADC_DC_CTL_CIM_Pos                    0                      /*!< DC interrupt generation mode */
#define ADC_DC_CTL_CIC_Pos                    2                      /*!< DC interrupt generation compare conditions */
#define ADC_DC_CTL_CIE_Pos                    4                      /*!< Enable DC interrupt generation */
#define ADC_DC_CTL_CTM_Pos                    8                      /*!< DC output trigger mode */
#define ADC_DC_CTL_CTC_Pos                    10                     /*!< DC output trigger compare conditions */
#define ADC_DC_CTL_CTE_Pos                    12                     /*!< Enable DC output trigger */
#define ADC_DC_CTL_CHNL_Pos                   16                     /*!< ADC channel selection */
#define ADC_DC_CTL_SRC_Pos                    24                     /*!< Select data source for comparation: ADC module (0) or sequencer(1) */

/* Bit field masks: */
#define ADC_DC_CTL_CIM_Msk                    0x00000003             /*!< DC interrupt generation mode */
#define ADC_DC_CTL_CIC_Msk                    0x0000000C             /*!< DC interrupt generation compare conditions */
#define ADC_DC_CTL_CIE_Msk                    0x00000010             /*!< Enable DC interrupt generation */
#define ADC_DC_CTL_CTM_Msk                    0x00000300             /*!< DC output trigger mode */
#define ADC_DC_CTL_CTC_Msk                    0x00000C00             /*!< DC output trigger compare conditions */
#define ADC_DC_CTL_CTE_Msk                    0x00001000             /*!< Enable DC output trigger */
#define ADC_DC_CTL_CHNL_Msk                   0x00030000             /*!< ADC channel selection */
#define ADC_DC_CTL_SRC_Msk                    0x01000000             /*!< Select data source for comparation: ADC module (0) or sequencer(1) */

/* Bit field enums: */
typedef enum {
  ADC_DC_CTL_CIM_Multiple                    = 0x0,                  /*!< multiple trigger mode */
  ADC_DC_CTL_CIM_Single                      = 0x1,                  /*!< single trigger mode */
  ADC_DC_CTL_CIM_MultipleHyst                = 0x2,                  /*!< multiple trigger mode with hysteresis */
  ADC_DC_CTL_CIM_SingleHyst                  = 0x3,                  /*!< single trigger mode with hysteresis */
} ADC_DC_CTL_CIM_Enum;

typedef enum {
  ADC_DC_CTL_CIC_Low                         = 0x0,                  /*!< result lower or equal COMP0 */
  ADC_DC_CTL_CIC_Window                      = 0x1,                  /*!< result between COMP0 and COMP1 or equal any of them */
  ADC_DC_CTL_CIC_High                        = 0x2,                  /*!< result higher or equal COMP1 */
} ADC_DC_CTL_CIC_Enum;

typedef enum {
  ADC_DC_CTL_CTM_Multiple                    = 0x0,                  /*!< multiple trigger mode */
  ADC_DC_CTL_CTM_Single                      = 0x1,                  /*!< single trigger mode */
  ADC_DC_CTL_CTM_MultipleHyst                = 0x2,                  /*!< multiple trigger mode with hysteresis */
  ADC_DC_CTL_CTM_SingleHyst                  = 0x3,                  /*!< single trigger mode with hysteresis */
} ADC_DC_CTL_CTM_Enum;

typedef enum {
  ADC_DC_CTL_CTC_Low                         = 0x0,                  /*!< result lower or equal COMP0 */
  ADC_DC_CTL_CTC_Window                      = 0x1,                  /*!< result between COMP0 and COMP1 or equal any of them */
  ADC_DC_CTL_CTC_High                        = 0x2,                  /*!< result higher or equal COMP1 */
} ADC_DC_CTL_CTC_Enum;

/*-- DC: CMP: Digital comparator range register ---------------------------------------------------------------*/
typedef struct {
  uint32_t CMPL                   :12;                               /*!< Low threshold compare value */
  uint32_t                        :4;                                /*!< RESERVED */
  uint32_t CMPH                   :12;                               /*!< High threshold compare value */
} _ADC_DC_CMP_bits;

/* Bit field positions: */
#define ADC_DC_CMP_CMPL_Pos                   0                      /*!< Low threshold compare value */
#define ADC_DC_CMP_CMPH_Pos                   16                     /*!< High threshold compare value */

/* Bit field masks: */
#define ADC_DC_CMP_CMPL_Msk                   0x00000FFF             /*!< Low threshold compare value */
#define ADC_DC_CMP_CMPH_Msk                   0x0FFF0000             /*!< High threshold compare value */

/*-- DC: DATA: Digital comparator last compared data register -------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :12;                               /*!< Value of last compared AD conversion result */
} _ADC_DC_DATA_bits;

/* Bit field positions: */
#define ADC_DC_DATA_VAL_Pos                   0                      /*!< Value of last compared AD conversion result */

/* Bit field masks: */
#define ADC_DC_DATA_VAL_Msk                   0x00000FFF             /*!< Value of last compared AD conversion result */

/*--  ADCCTL: ADC module control register ---------------------------------------------------------------------*/
typedef struct {
  uint32_t ADCEN                  :1;                                /*!< Enable ADC module */
  uint32_t ADCRDY                 :1;                                /*!< ADC ready for conversions */
} _ADC_ADCCTL_bits;

/* Bit field positions: */
#define ADC_ADCCTL_ADCEN_Pos                  0                      /*!< Enable ADC module */
#define ADC_ADCCTL_ADCRDY_Pos                 1                      /*!< ADC ready for conversions */

/* Bit field masks: */
#define ADC_ADCCTL_ADCEN_Msk                  0x00000001             /*!< Enable ADC module */
#define ADC_ADCCTL_ADCRDY_Msk                 0x00000002             /*!< ADC ready for conversions */

/*-- CHCTL: CHCTL: ADC channel control register ---------------------------------------------------------------*/
typedef struct {
  uint32_t OFFTRIM                :9;                                /*!< ADC channel offset trimm value */
  uint32_t                        :7;                                /*!< RESERVED */
  uint32_t GAINTRIM               :9;                                /*!< ADC channel gain trimm value */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t PRIORITY               :1;                                /*!< ADC channel priority level */
} _ADC_CHCTL_CHCTL_bits;

/* Bit field positions: */
#define ADC_CHCTL_CHCTL_OFFTRIM_Pos           0                      /*!< ADC channel offset trimm value */
#define ADC_CHCTL_CHCTL_GAINTRIM_Pos          16                     /*!< ADC channel gain trimm value */
#define ADC_CHCTL_CHCTL_PRIORITY_Pos          28                     /*!< ADC channel priority level */

/* Bit field masks: */
#define ADC_CHCTL_CHCTL_OFFTRIM_Msk           0x000001FF             /*!< ADC channel offset trimm value */
#define ADC_CHCTL_CHCTL_GAINTRIM_Msk          0x01FF0000             /*!< ADC channel gain trimm value */
#define ADC_CHCTL_CHCTL_PRIORITY_Msk          0x10000000             /*!< ADC channel priority level */

//Cluster SEQ:
typedef struct {
  union { 
  /*!< Sequencer request ADC channels selection register */
    __IO uint32_t RQSEL;                                             /*!< RQSEL : type used for word access */
    __IO _ADC_SEQ_RQSEL_bits RQSEL_bit;                              /*!< RQSEL_bit: structure used for bit access */
  };
    __IO uint32_t Reserved0[3];
  union { 
  /*!< Sequencer request control register */
    __IO uint32_t RQCTL;                                             /*!< RQCTL : type used for word access */
    __IO _ADC_SEQ_RQCTL_bits RQCTL_bit;                              /*!< RQCTL_bit: structure used for bit access */
  };
  union { 
  /*!< Sequencer request status register */
    __I uint32_t RQSTAT;                                             /*!< RQSTAT : type used for word access */
    __I _ADC_SEQ_RQSTAT_bits RQSTAT_bit;                             /*!< RQSTAT_bit: structure used for bit access */
  };
  union { 
  /*!< Sequencer DMA control register */
    __IO uint32_t DMACTL;                                            /*!< DMACTL : type used for word access */
    __IO _ADC_SEQ_DMACTL_bits DMACTL_bit;                            /*!< DMACTL_bit: structure used for bit access */
  };
  union { 
  /*!< Sequencer ADC interrupt and restart counter control register */
    __IO uint32_t CCTL;                                              /*!< CCTL : type used for word access */
    __IO _ADC_SEQ_CCTL_bits CCTL_bit;                                /*!< CCTL_bit: structure used for bit access */
  };
  union { 
  /*!< Sequencer ADC interrupt and restart counter current value register */
    __O uint32_t CVAL;                                               /*!< CVAL : type used for word access */
    __O _ADC_SEQ_CVAL_bits CVAL_bit;                                 /*!< CVAL_bit: structure used for bit access */
  };
  union { 
  /*!< Sequencer digital comparator selection register */
    __IO uint32_t DC;                                                /*!< DC : type used for word access */
    __IO _ADC_SEQ_DC_bits DC_bit;                                    /*!< DC_bit: structure used for bit access */
  };
  union { 
  /*!< Sequencer ADC restart timer register */
    __IO uint32_t RTMR;                                              /*!< RTMR : type used for word access */
    __IO _ADC_SEQ_RTMR_bits RTMR_bit;                                /*!< RTMR_bit: structure used for bit access */
  };
  union { 
  /*!< Sequencer FIFO load status register */
    __I uint32_t FLOAD;                                              /*!< FLOAD : type used for word access */
    __I _ADC_SEQ_FLOAD_bits FLOAD_bit;                               /*!< FLOAD_bit: structure used for bit access */
  };
  union { 
  /*!< Sequencer FIFO register */
    __I uint32_t FIFO;                                               /*!< FIFO : type used for word access */
    __I _ADC_SEQ_FIFO_bits FIFO_bit;                                 /*!< FIFO_bit: structure used for bit access */
  };
} _ADC_SEQ_TypeDef;
//Cluster DC:
typedef struct {
  union { 
  /*!< Digital comparator control register */
    __IO uint32_t CTL;                                               /*!< CTL : type used for word access */
    __IO _ADC_DC_CTL_bits CTL_bit;                                   /*!< CTL_bit: structure used for bit access */
  };
  union { 
  /*!< Digital comparator range register */
    __IO uint32_t CMP;                                               /*!< CMP : type used for word access */
    __IO _ADC_DC_CMP_bits CMP_bit;                                   /*!< CMP_bit: structure used for bit access */
  };
  union { 
  /*!< Digital comparator last compared data register */
    __I uint32_t DATA;                                               /*!< DATA : type used for word access */
    __I _ADC_DC_DATA_bits DATA_bit;                                  /*!< DATA_bit: structure used for bit access */
  };
} _ADC_DC_TypeDef;
//Cluster CHCTL:
typedef struct {
  union { 
  /*!< ADC channel control register */
    __IO uint32_t CHCTL;                                             /*!< CHCTL : type used for word access */
    __IO _ADC_CHCTL_CHCTL_bits CHCTL_bit;                            /*!< CHCTL_bit: structure used for bit access */
  };
} _ADC_CHCTL_TypeDef;
typedef struct {
  union {                                                               /*!< Enable sequencer register */
    __IO uint32_t SEQEN;                                             /*!< SEQEN    : type used for word access */
    __IO _ADC_SEQEN_bits  SEQEN_bit;                                 /*!< SEQEN_bit: structure used for bit access */
  };
  union {                                                               /*!< Sequencer sync register */
    __IO uint32_t SEQSYNC;                                           /*!< SEQSYNC    : type used for word access */
    __IO _ADC_SEQSYNC_bits  SEQSYNC_bit;                             /*!< SEQSYNC_bit: structure used for bit access */
  };
  union {                                                               /*!< FIFO overflow status register */
    __IO uint32_t FSTAT;                                             /*!< FSTAT    : type used for word access */
    __IO _ADC_FSTAT_bits  FSTAT_bit;                                 /*!< FSTAT_bit: structure used for bit access */
  };
  union {                                                               /*!< Busy status register */
    __I uint32_t BSTAT;                                              /*!< BSTAT    : type used for word access */
    __I _ADC_BSTAT_bits  BSTAT_bit;                                  /*!< BSTAT_bit: structure used for bit access */
  };
  union {                                                               /*!< Digital comparator output trigger status register */
    __IO uint32_t DCTRIG;                                            /*!< DCTRIG    : type used for word access */
    __IO _ADC_DCTRIG_bits  DCTRIG_bit;                               /*!< DCTRIG_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt counter clear control */
    __IO uint32_t CICNT;                                             /*!< CICNT    : type used for word access */
    __IO _ADC_CICNT_bits  CICNT_bit;                                 /*!< CICNT_bit: structure used for bit access */
  };
  union {                                                               /*!< Sequencer start event selection register */
    __IO uint32_t EMUX;                                              /*!< EMUX    : type used for word access */
    __IO _ADC_EMUX_bits  EMUX_bit;                                   /*!< EMUX_bit: structure used for bit access */
  };
  union {                                                               /*!< Raw interrupt status register */
    __I uint32_t RIS;                                                /*!< RIS    : type used for word access */
    __I _ADC_RIS_bits  RIS_bit;                                      /*!< RIS_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt mask register */
    __IO uint32_t IM;                                                /*!< IM    : type used for word access */
    __IO _ADC_IM_bits  IM_bit;                                       /*!< IM_bit: structure used for bit access */
  };
  union {                                                               /*!< Masked interrupt status and clear register */
    __I uint32_t MIS;                                                /*!< MIS    : type used for word access */
    __I _ADC_MIS_bits  MIS_bit;                                      /*!< MIS_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt clear register */
    __O uint32_t IC;                                                 /*!< IC    : type used for word access */
    __O _ADC_IC_bits  IC_bit;                                        /*!< IC_bit: structure used for bit access */
  };
    __IO uint32_t Reserved0[5];
  _ADC_SEQ_TypeDef SEQ[2];
    __IO uint32_t Reserved1[86];
  _ADC_DC_TypeDef DC[4];
    __IO uint32_t Reserved2[116];
  union {                                                               /*!< ADC module control register */
    __IO uint32_t ADCCTL;                                            /*!< ADCCTL    : type used for word access */
    __IO _ADC_ADCCTL_bits  ADCCTL_bit;                               /*!< ADCCTL_bit: structure used for bit access */
  };
    __IO uint32_t Reserved3[63];
  _ADC_CHCTL_TypeDef CHCTL[4];
} ADC_TypeDef;

/******************************************************************************/
/*                         GPIO registers                                     */
/******************************************************************************/

/*--  DATA: Data Input register -------------------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :16;                               /*!< Data input */
} _GPIO_DATA_bits;

/* Bit field positions: */
#define GPIO_DATA_VAL_Pos                     0                      /*!< Data input */

/* Bit field masks: */
#define GPIO_DATA_VAL_Msk                     0x0000FFFF             /*!< Data input */

/*--  DATAOUT: Data output register ---------------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :16;                               /*!< Data output */
} _GPIO_DATAOUT_bits;

/* Bit field positions: */
#define GPIO_DATAOUT_VAL_Pos                  0                      /*!< Data output */

/* Bit field masks: */
#define GPIO_DATAOUT_VAL_Msk                  0x0000FFFF             /*!< Data output */

/*--  DATAOUTSET: Data output set bits register ---------------------------------------------------------------*/
typedef struct {
  uint32_t PIN0                   :1;                                /*!< Data output set bit 0 */
  uint32_t PIN1                   :1;                                /*!< Data output set bit 1 */
  uint32_t PIN2                   :1;                                /*!< Data output set bit 2 */
  uint32_t PIN3                   :1;                                /*!< Data output set bit 3 */
  uint32_t PIN4                   :1;                                /*!< Data output set bit 4 */
  uint32_t PIN5                   :1;                                /*!< Data output set bit 5 */
  uint32_t PIN6                   :1;                                /*!< Data output set bit 6 */
  uint32_t PIN7                   :1;                                /*!< Data output set bit 7 */
  uint32_t PIN8                   :1;                                /*!< Data output set bit 8 */
  uint32_t PIN9                   :1;                                /*!< Data output set bit 9 */
  uint32_t PIN10                  :1;                                /*!< Data output set bit 10 */
  uint32_t PIN11                  :1;                                /*!< Data output set bit 11 */
  uint32_t PIN12                  :1;                                /*!< Data output set bit 12 */
  uint32_t PIN13                  :1;                                /*!< Data output set bit 13 */
  uint32_t PIN14                  :1;                                /*!< Data output set bit 14 */
  uint32_t PIN15                  :1;                                /*!< Data output set bit 15 */
} _GPIO_DATAOUTSET_bits;

/* Bit field positions: */
#define GPIO_DATAOUTSET_PIN0_Pos              0                      /*!< Data output set bit 0 */
#define GPIO_DATAOUTSET_PIN1_Pos              1                      /*!< Data output set bit 1 */
#define GPIO_DATAOUTSET_PIN2_Pos              2                      /*!< Data output set bit 2 */
#define GPIO_DATAOUTSET_PIN3_Pos              3                      /*!< Data output set bit 3 */
#define GPIO_DATAOUTSET_PIN4_Pos              4                      /*!< Data output set bit 4 */
#define GPIO_DATAOUTSET_PIN5_Pos              5                      /*!< Data output set bit 5 */
#define GPIO_DATAOUTSET_PIN6_Pos              6                      /*!< Data output set bit 6 */
#define GPIO_DATAOUTSET_PIN7_Pos              7                      /*!< Data output set bit 7 */
#define GPIO_DATAOUTSET_PIN8_Pos              8                      /*!< Data output set bit 8 */
#define GPIO_DATAOUTSET_PIN9_Pos              9                      /*!< Data output set bit 9 */
#define GPIO_DATAOUTSET_PIN10_Pos             10                     /*!< Data output set bit 10 */
#define GPIO_DATAOUTSET_PIN11_Pos             11                     /*!< Data output set bit 11 */
#define GPIO_DATAOUTSET_PIN12_Pos             12                     /*!< Data output set bit 12 */
#define GPIO_DATAOUTSET_PIN13_Pos             13                     /*!< Data output set bit 13 */
#define GPIO_DATAOUTSET_PIN14_Pos             14                     /*!< Data output set bit 14 */
#define GPIO_DATAOUTSET_PIN15_Pos             15                     /*!< Data output set bit 15 */

/* Bit field masks: */
#define GPIO_DATAOUTSET_PIN0_Msk              0x00000001             /*!< Data output set bit 0 */
#define GPIO_DATAOUTSET_PIN1_Msk              0x00000002             /*!< Data output set bit 1 */
#define GPIO_DATAOUTSET_PIN2_Msk              0x00000004             /*!< Data output set bit 2 */
#define GPIO_DATAOUTSET_PIN3_Msk              0x00000008             /*!< Data output set bit 3 */
#define GPIO_DATAOUTSET_PIN4_Msk              0x00000010             /*!< Data output set bit 4 */
#define GPIO_DATAOUTSET_PIN5_Msk              0x00000020             /*!< Data output set bit 5 */
#define GPIO_DATAOUTSET_PIN6_Msk              0x00000040             /*!< Data output set bit 6 */
#define GPIO_DATAOUTSET_PIN7_Msk              0x00000080             /*!< Data output set bit 7 */
#define GPIO_DATAOUTSET_PIN8_Msk              0x00000100             /*!< Data output set bit 8 */
#define GPIO_DATAOUTSET_PIN9_Msk              0x00000200             /*!< Data output set bit 9 */
#define GPIO_DATAOUTSET_PIN10_Msk             0x00000400             /*!< Data output set bit 10 */
#define GPIO_DATAOUTSET_PIN11_Msk             0x00000800             /*!< Data output set bit 11 */
#define GPIO_DATAOUTSET_PIN12_Msk             0x00001000             /*!< Data output set bit 12 */
#define GPIO_DATAOUTSET_PIN13_Msk             0x00002000             /*!< Data output set bit 13 */
#define GPIO_DATAOUTSET_PIN14_Msk             0x00004000             /*!< Data output set bit 14 */
#define GPIO_DATAOUTSET_PIN15_Msk             0x00008000             /*!< Data output set bit 15 */

/*--  DATAOUTCLR: Data output clear bits register -------------------------------------------------------------*/
typedef struct {
  uint32_t PIN0                   :1;                                /*!< Data output clear bit 0 */
  uint32_t PIN1                   :1;                                /*!< Data output clear bit 1 */
  uint32_t PIN2                   :1;                                /*!< Data output clear bit 2 */
  uint32_t PIN3                   :1;                                /*!< Data output clear bit 3 */
  uint32_t PIN4                   :1;                                /*!< Data output clear bit 4 */
  uint32_t PIN5                   :1;                                /*!< Data output clear bit 5 */
  uint32_t PIN6                   :1;                                /*!< Data output clear bit 6 */
  uint32_t PIN7                   :1;                                /*!< Data output clear bit 7 */
  uint32_t PIN8                   :1;                                /*!< Data output clear bit 8 */
  uint32_t PIN9                   :1;                                /*!< Data output clear bit 9 */
  uint32_t PIN10                  :1;                                /*!< Data output clear bit 10 */
  uint32_t PIN11                  :1;                                /*!< Data output clear bit 11 */
  uint32_t PIN12                  :1;                                /*!< Data output clear bit 12 */
  uint32_t PIN13                  :1;                                /*!< Data output clear bit 13 */
  uint32_t PIN14                  :1;                                /*!< Data output clear bit 14 */
  uint32_t PIN15                  :1;                                /*!< Data output clear bit 15 */
} _GPIO_DATAOUTCLR_bits;

/* Bit field positions: */
#define GPIO_DATAOUTCLR_PIN0_Pos              0                      /*!< Data output clear bit 0 */
#define GPIO_DATAOUTCLR_PIN1_Pos              1                      /*!< Data output clear bit 1 */
#define GPIO_DATAOUTCLR_PIN2_Pos              2                      /*!< Data output clear bit 2 */
#define GPIO_DATAOUTCLR_PIN3_Pos              3                      /*!< Data output clear bit 3 */
#define GPIO_DATAOUTCLR_PIN4_Pos              4                      /*!< Data output clear bit 4 */
#define GPIO_DATAOUTCLR_PIN5_Pos              5                      /*!< Data output clear bit 5 */
#define GPIO_DATAOUTCLR_PIN6_Pos              6                      /*!< Data output clear bit 6 */
#define GPIO_DATAOUTCLR_PIN7_Pos              7                      /*!< Data output clear bit 7 */
#define GPIO_DATAOUTCLR_PIN8_Pos              8                      /*!< Data output clear bit 8 */
#define GPIO_DATAOUTCLR_PIN9_Pos              9                      /*!< Data output clear bit 9 */
#define GPIO_DATAOUTCLR_PIN10_Pos             10                     /*!< Data output clear bit 10 */
#define GPIO_DATAOUTCLR_PIN11_Pos             11                     /*!< Data output clear bit 11 */
#define GPIO_DATAOUTCLR_PIN12_Pos             12                     /*!< Data output clear bit 12 */
#define GPIO_DATAOUTCLR_PIN13_Pos             13                     /*!< Data output clear bit 13 */
#define GPIO_DATAOUTCLR_PIN14_Pos             14                     /*!< Data output clear bit 14 */
#define GPIO_DATAOUTCLR_PIN15_Pos             15                     /*!< Data output clear bit 15 */

/* Bit field masks: */
#define GPIO_DATAOUTCLR_PIN0_Msk              0x00000001             /*!< Data output clear bit 0 */
#define GPIO_DATAOUTCLR_PIN1_Msk              0x00000002             /*!< Data output clear bit 1 */
#define GPIO_DATAOUTCLR_PIN2_Msk              0x00000004             /*!< Data output clear bit 2 */
#define GPIO_DATAOUTCLR_PIN3_Msk              0x00000008             /*!< Data output clear bit 3 */
#define GPIO_DATAOUTCLR_PIN4_Msk              0x00000010             /*!< Data output clear bit 4 */
#define GPIO_DATAOUTCLR_PIN5_Msk              0x00000020             /*!< Data output clear bit 5 */
#define GPIO_DATAOUTCLR_PIN6_Msk              0x00000040             /*!< Data output clear bit 6 */
#define GPIO_DATAOUTCLR_PIN7_Msk              0x00000080             /*!< Data output clear bit 7 */
#define GPIO_DATAOUTCLR_PIN8_Msk              0x00000100             /*!< Data output clear bit 8 */
#define GPIO_DATAOUTCLR_PIN9_Msk              0x00000200             /*!< Data output clear bit 9 */
#define GPIO_DATAOUTCLR_PIN10_Msk             0x00000400             /*!< Data output clear bit 10 */
#define GPIO_DATAOUTCLR_PIN11_Msk             0x00000800             /*!< Data output clear bit 11 */
#define GPIO_DATAOUTCLR_PIN12_Msk             0x00001000             /*!< Data output clear bit 12 */
#define GPIO_DATAOUTCLR_PIN13_Msk             0x00002000             /*!< Data output clear bit 13 */
#define GPIO_DATAOUTCLR_PIN14_Msk             0x00004000             /*!< Data output clear bit 14 */
#define GPIO_DATAOUTCLR_PIN15_Msk             0x00008000             /*!< Data output clear bit 15 */

/*--  DATAOUTTGL: Data output toogle bits register ------------------------------------------------------------*/
typedef struct {
  uint32_t PIN0                   :1;                                /*!< Data output toogle bit 0 */
  uint32_t PIN1                   :1;                                /*!< Data output toogle bit 1 */
  uint32_t PIN2                   :1;                                /*!< Data output toogle bit 2 */
  uint32_t PIN3                   :1;                                /*!< Data output toogle bit 3 */
  uint32_t PIN4                   :1;                                /*!< Data output toogle bit 4 */
  uint32_t PIN5                   :1;                                /*!< Data output toogle bit 5 */
  uint32_t PIN6                   :1;                                /*!< Data output toogle bit 6 */
  uint32_t PIN7                   :1;                                /*!< Data output toogle bit 7 */
  uint32_t PIN8                   :1;                                /*!< Data output toogle bit 8 */
  uint32_t PIN9                   :1;                                /*!< Data output toogle bit 9 */
  uint32_t PIN10                  :1;                                /*!< Data output toogle bit 10 */
  uint32_t PIN11                  :1;                                /*!< Data output toogle bit 11 */
  uint32_t PIN12                  :1;                                /*!< Data output toogle bit 12 */
  uint32_t PIN13                  :1;                                /*!< Data output toogle bit 13 */
  uint32_t PIN14                  :1;                                /*!< Data output toogle bit 14 */
  uint32_t PIN15                  :1;                                /*!< Data output toogle bit 15 */
} _GPIO_DATAOUTTGL_bits;

/* Bit field positions: */
#define GPIO_DATAOUTTGL_PIN0_Pos              0                      /*!< Data output toogle bit 0 */
#define GPIO_DATAOUTTGL_PIN1_Pos              1                      /*!< Data output toogle bit 1 */
#define GPIO_DATAOUTTGL_PIN2_Pos              2                      /*!< Data output toogle bit 2 */
#define GPIO_DATAOUTTGL_PIN3_Pos              3                      /*!< Data output toogle bit 3 */
#define GPIO_DATAOUTTGL_PIN4_Pos              4                      /*!< Data output toogle bit 4 */
#define GPIO_DATAOUTTGL_PIN5_Pos              5                      /*!< Data output toogle bit 5 */
#define GPIO_DATAOUTTGL_PIN6_Pos              6                      /*!< Data output toogle bit 6 */
#define GPIO_DATAOUTTGL_PIN7_Pos              7                      /*!< Data output toogle bit 7 */
#define GPIO_DATAOUTTGL_PIN8_Pos              8                      /*!< Data output toogle bit 8 */
#define GPIO_DATAOUTTGL_PIN9_Pos              9                      /*!< Data output toogle bit 9 */
#define GPIO_DATAOUTTGL_PIN10_Pos             10                     /*!< Data output toogle bit 10 */
#define GPIO_DATAOUTTGL_PIN11_Pos             11                     /*!< Data output toogle bit 11 */
#define GPIO_DATAOUTTGL_PIN12_Pos             12                     /*!< Data output toogle bit 12 */
#define GPIO_DATAOUTTGL_PIN13_Pos             13                     /*!< Data output toogle bit 13 */
#define GPIO_DATAOUTTGL_PIN14_Pos             14                     /*!< Data output toogle bit 14 */
#define GPIO_DATAOUTTGL_PIN15_Pos             15                     /*!< Data output toogle bit 15 */

/* Bit field masks: */
#define GPIO_DATAOUTTGL_PIN0_Msk              0x00000001             /*!< Data output toogle bit 0 */
#define GPIO_DATAOUTTGL_PIN1_Msk              0x00000002             /*!< Data output toogle bit 1 */
#define GPIO_DATAOUTTGL_PIN2_Msk              0x00000004             /*!< Data output toogle bit 2 */
#define GPIO_DATAOUTTGL_PIN3_Msk              0x00000008             /*!< Data output toogle bit 3 */
#define GPIO_DATAOUTTGL_PIN4_Msk              0x00000010             /*!< Data output toogle bit 4 */
#define GPIO_DATAOUTTGL_PIN5_Msk              0x00000020             /*!< Data output toogle bit 5 */
#define GPIO_DATAOUTTGL_PIN6_Msk              0x00000040             /*!< Data output toogle bit 6 */
#define GPIO_DATAOUTTGL_PIN7_Msk              0x00000080             /*!< Data output toogle bit 7 */
#define GPIO_DATAOUTTGL_PIN8_Msk              0x00000100             /*!< Data output toogle bit 8 */
#define GPIO_DATAOUTTGL_PIN9_Msk              0x00000200             /*!< Data output toogle bit 9 */
#define GPIO_DATAOUTTGL_PIN10_Msk             0x00000400             /*!< Data output toogle bit 10 */
#define GPIO_DATAOUTTGL_PIN11_Msk             0x00000800             /*!< Data output toogle bit 11 */
#define GPIO_DATAOUTTGL_PIN12_Msk             0x00001000             /*!< Data output toogle bit 12 */
#define GPIO_DATAOUTTGL_PIN13_Msk             0x00002000             /*!< Data output toogle bit 13 */
#define GPIO_DATAOUTTGL_PIN14_Msk             0x00004000             /*!< Data output toogle bit 14 */
#define GPIO_DATAOUTTGL_PIN15_Msk             0x00008000             /*!< Data output toogle bit 15 */

/*--  DENSET: Digital function (PAD) enable register ----------------------------------------------------------*/
typedef struct {
  uint32_t PIN0                   :1;                                /*!< Digital function (PAD) enable on pin 0 */
  uint32_t PIN1                   :1;                                /*!< Digital function (PAD) enable on pin 1 */
  uint32_t PIN2                   :1;                                /*!< Digital function (PAD) enable on pin 2 */
  uint32_t PIN3                   :1;                                /*!< Digital function (PAD) enable on pin 3 */
  uint32_t PIN4                   :1;                                /*!< Digital function (PAD) enable on pin 4 */
  uint32_t PIN5                   :1;                                /*!< Digital function (PAD) enable on pin 5 */
  uint32_t PIN6                   :1;                                /*!< Digital function (PAD) enable on pin 6 */
  uint32_t PIN7                   :1;                                /*!< Digital function (PAD) enable on pin 7 */
  uint32_t PIN8                   :1;                                /*!< Digital function (PAD) enable on pin 8 */
  uint32_t PIN9                   :1;                                /*!< Digital function (PAD) enable on pin 9 */
  uint32_t PIN10                  :1;                                /*!< Digital function (PAD) enable on pin 10 */
  uint32_t PIN11                  :1;                                /*!< Digital function (PAD) enable on pin 11 */
  uint32_t PIN12                  :1;                                /*!< Digital function (PAD) enable on pin 12 */
  uint32_t PIN13                  :1;                                /*!< Digital function (PAD) enable on pin 13 */
  uint32_t PIN14                  :1;                                /*!< Digital function (PAD) enable on pin 14 */
  uint32_t PIN15                  :1;                                /*!< Digital function (PAD) enable on pin 15 */
} _GPIO_DENSET_bits;

/* Bit field positions: */
#define GPIO_DENSET_PIN0_Pos                  0                      /*!< Digital function (PAD) enable on pin 0 */
#define GPIO_DENSET_PIN1_Pos                  1                      /*!< Digital function (PAD) enable on pin 1 */
#define GPIO_DENSET_PIN2_Pos                  2                      /*!< Digital function (PAD) enable on pin 2 */
#define GPIO_DENSET_PIN3_Pos                  3                      /*!< Digital function (PAD) enable on pin 3 */
#define GPIO_DENSET_PIN4_Pos                  4                      /*!< Digital function (PAD) enable on pin 4 */
#define GPIO_DENSET_PIN5_Pos                  5                      /*!< Digital function (PAD) enable on pin 5 */
#define GPIO_DENSET_PIN6_Pos                  6                      /*!< Digital function (PAD) enable on pin 6 */
#define GPIO_DENSET_PIN7_Pos                  7                      /*!< Digital function (PAD) enable on pin 7 */
#define GPIO_DENSET_PIN8_Pos                  8                      /*!< Digital function (PAD) enable on pin 8 */
#define GPIO_DENSET_PIN9_Pos                  9                      /*!< Digital function (PAD) enable on pin 9 */
#define GPIO_DENSET_PIN10_Pos                 10                     /*!< Digital function (PAD) enable on pin 10 */
#define GPIO_DENSET_PIN11_Pos                 11                     /*!< Digital function (PAD) enable on pin 11 */
#define GPIO_DENSET_PIN12_Pos                 12                     /*!< Digital function (PAD) enable on pin 12 */
#define GPIO_DENSET_PIN13_Pos                 13                     /*!< Digital function (PAD) enable on pin 13 */
#define GPIO_DENSET_PIN14_Pos                 14                     /*!< Digital function (PAD) enable on pin 14 */
#define GPIO_DENSET_PIN15_Pos                 15                     /*!< Digital function (PAD) enable on pin 15 */

/* Bit field masks: */
#define GPIO_DENSET_PIN0_Msk                  0x00000001             /*!< Digital function (PAD) enable on pin 0 */
#define GPIO_DENSET_PIN1_Msk                  0x00000002             /*!< Digital function (PAD) enable on pin 1 */
#define GPIO_DENSET_PIN2_Msk                  0x00000004             /*!< Digital function (PAD) enable on pin 2 */
#define GPIO_DENSET_PIN3_Msk                  0x00000008             /*!< Digital function (PAD) enable on pin 3 */
#define GPIO_DENSET_PIN4_Msk                  0x00000010             /*!< Digital function (PAD) enable on pin 4 */
#define GPIO_DENSET_PIN5_Msk                  0x00000020             /*!< Digital function (PAD) enable on pin 5 */
#define GPIO_DENSET_PIN6_Msk                  0x00000040             /*!< Digital function (PAD) enable on pin 6 */
#define GPIO_DENSET_PIN7_Msk                  0x00000080             /*!< Digital function (PAD) enable on pin 7 */
#define GPIO_DENSET_PIN8_Msk                  0x00000100             /*!< Digital function (PAD) enable on pin 8 */
#define GPIO_DENSET_PIN9_Msk                  0x00000200             /*!< Digital function (PAD) enable on pin 9 */
#define GPIO_DENSET_PIN10_Msk                 0x00000400             /*!< Digital function (PAD) enable on pin 10 */
#define GPIO_DENSET_PIN11_Msk                 0x00000800             /*!< Digital function (PAD) enable on pin 11 */
#define GPIO_DENSET_PIN12_Msk                 0x00001000             /*!< Digital function (PAD) enable on pin 12 */
#define GPIO_DENSET_PIN13_Msk                 0x00002000             /*!< Digital function (PAD) enable on pin 13 */
#define GPIO_DENSET_PIN14_Msk                 0x00004000             /*!< Digital function (PAD) enable on pin 14 */
#define GPIO_DENSET_PIN15_Msk                 0x00008000             /*!< Digital function (PAD) enable on pin 15 */

/*--  DENCLR: Digital function (PAD) disable register ---------------------------------------------------------*/
typedef struct {
  uint32_t PIN0                   :1;                                /*!< Digital function (PAD) disable on pin 0 */
  uint32_t PIN1                   :1;                                /*!< Digital function (PAD) disable on pin 1 */
  uint32_t PIN2                   :1;                                /*!< Digital function (PAD) disable on pin 2 */
  uint32_t PIN3                   :1;                                /*!< Digital function (PAD) disable on pin 3 */
  uint32_t PIN4                   :1;                                /*!< Digital function (PAD) disable on pin 4 */
  uint32_t PIN5                   :1;                                /*!< Digital function (PAD) disable on pin 5 */
  uint32_t PIN6                   :1;                                /*!< Digital function (PAD) disable on pin 6 */
  uint32_t PIN7                   :1;                                /*!< Digital function (PAD) disable on pin 7 */
  uint32_t PIN8                   :1;                                /*!< Digital function (PAD) disable on pin 8 */
  uint32_t PIN9                   :1;                                /*!< Digital function (PAD) disable on pin 9 */
  uint32_t PIN10                  :1;                                /*!< Digital function (PAD) disable on pin 10 */
  uint32_t PIN11                  :1;                                /*!< Digital function (PAD) disable on pin 11 */
  uint32_t PIN12                  :1;                                /*!< Digital function (PAD) disable on pin 12 */
  uint32_t PIN13                  :1;                                /*!< Digital function (PAD) disable on pin 13 */
  uint32_t PIN14                  :1;                                /*!< Digital function (PAD) disable on pin 14 */
  uint32_t PIN15                  :1;                                /*!< Digital function (PAD) disable on pin 15 */
} _GPIO_DENCLR_bits;

/* Bit field positions: */
#define GPIO_DENCLR_PIN0_Pos                  0                      /*!< Digital function (PAD) disable on pin 0 */
#define GPIO_DENCLR_PIN1_Pos                  1                      /*!< Digital function (PAD) disable on pin 1 */
#define GPIO_DENCLR_PIN2_Pos                  2                      /*!< Digital function (PAD) disable on pin 2 */
#define GPIO_DENCLR_PIN3_Pos                  3                      /*!< Digital function (PAD) disable on pin 3 */
#define GPIO_DENCLR_PIN4_Pos                  4                      /*!< Digital function (PAD) disable on pin 4 */
#define GPIO_DENCLR_PIN5_Pos                  5                      /*!< Digital function (PAD) disable on pin 5 */
#define GPIO_DENCLR_PIN6_Pos                  6                      /*!< Digital function (PAD) disable on pin 6 */
#define GPIO_DENCLR_PIN7_Pos                  7                      /*!< Digital function (PAD) disable on pin 7 */
#define GPIO_DENCLR_PIN8_Pos                  8                      /*!< Digital function (PAD) disable on pin 8 */
#define GPIO_DENCLR_PIN9_Pos                  9                      /*!< Digital function (PAD) disable on pin 9 */
#define GPIO_DENCLR_PIN10_Pos                 10                     /*!< Digital function (PAD) disable on pin 10 */
#define GPIO_DENCLR_PIN11_Pos                 11                     /*!< Digital function (PAD) disable on pin 11 */
#define GPIO_DENCLR_PIN12_Pos                 12                     /*!< Digital function (PAD) disable on pin 12 */
#define GPIO_DENCLR_PIN13_Pos                 13                     /*!< Digital function (PAD) disable on pin 13 */
#define GPIO_DENCLR_PIN14_Pos                 14                     /*!< Digital function (PAD) disable on pin 14 */
#define GPIO_DENCLR_PIN15_Pos                 15                     /*!< Digital function (PAD) disable on pin 15 */

/* Bit field masks: */
#define GPIO_DENCLR_PIN0_Msk                  0x00000001             /*!< Digital function (PAD) disable on pin 0 */
#define GPIO_DENCLR_PIN1_Msk                  0x00000002             /*!< Digital function (PAD) disable on pin 1 */
#define GPIO_DENCLR_PIN2_Msk                  0x00000004             /*!< Digital function (PAD) disable on pin 2 */
#define GPIO_DENCLR_PIN3_Msk                  0x00000008             /*!< Digital function (PAD) disable on pin 3 */
#define GPIO_DENCLR_PIN4_Msk                  0x00000010             /*!< Digital function (PAD) disable on pin 4 */
#define GPIO_DENCLR_PIN5_Msk                  0x00000020             /*!< Digital function (PAD) disable on pin 5 */
#define GPIO_DENCLR_PIN6_Msk                  0x00000040             /*!< Digital function (PAD) disable on pin 6 */
#define GPIO_DENCLR_PIN7_Msk                  0x00000080             /*!< Digital function (PAD) disable on pin 7 */
#define GPIO_DENCLR_PIN8_Msk                  0x00000100             /*!< Digital function (PAD) disable on pin 8 */
#define GPIO_DENCLR_PIN9_Msk                  0x00000200             /*!< Digital function (PAD) disable on pin 9 */
#define GPIO_DENCLR_PIN10_Msk                 0x00000400             /*!< Digital function (PAD) disable on pin 10 */
#define GPIO_DENCLR_PIN11_Msk                 0x00000800             /*!< Digital function (PAD) disable on pin 11 */
#define GPIO_DENCLR_PIN12_Msk                 0x00001000             /*!< Digital function (PAD) disable on pin 12 */
#define GPIO_DENCLR_PIN13_Msk                 0x00002000             /*!< Digital function (PAD) disable on pin 13 */
#define GPIO_DENCLR_PIN14_Msk                 0x00004000             /*!< Digital function (PAD) disable on pin 14 */
#define GPIO_DENCLR_PIN15_Msk                 0x00008000             /*!< Digital function (PAD) disable on pin 15 */

/*--  INMODE: Select input mode register ----------------------------------------------------------------------*/
typedef struct {
  uint32_t PIN0                   :2;                                /*!< Select input mode for pin 0 */
  uint32_t PIN1                   :2;                                /*!< Select input mode for pin 1 */
  uint32_t PIN2                   :2;                                /*!< Select input mode for pin 2 */
  uint32_t PIN3                   :2;                                /*!< Select input mode for pin 3 */
  uint32_t PIN4                   :2;                                /*!< Select input mode for pin 4 */
  uint32_t PIN5                   :2;                                /*!< Select input mode for pin 5 */
  uint32_t PIN6                   :2;                                /*!< Select input mode for pin 6 */
  uint32_t PIN7                   :2;                                /*!< Select input mode for pin 7 */
  uint32_t PIN8                   :2;                                /*!< Select input mode for pin 8 */
  uint32_t PIN9                   :2;                                /*!< Select input mode for pin 9 */
  uint32_t PIN10                  :2;                                /*!< Select input mode for pin 10 */
  uint32_t PIN11                  :2;                                /*!< Select input mode for pin 11 */
  uint32_t PIN12                  :2;                                /*!< Select input mode for pin 12 */
  uint32_t PIN13                  :2;                                /*!< Select input mode for pin 13 */
  uint32_t PIN14                  :2;                                /*!< Select input mode for pin 14 */
  uint32_t PIN15                  :2;                                /*!< Select input mode for pin 15 */
} _GPIO_INMODE_bits;

/* Bit field positions: */
#define GPIO_INMODE_PIN0_Pos                  0                      /*!< Select input mode for pin 0 */
#define GPIO_INMODE_PIN1_Pos                  2                      /*!< Select input mode for pin 1 */
#define GPIO_INMODE_PIN2_Pos                  4                      /*!< Select input mode for pin 2 */
#define GPIO_INMODE_PIN3_Pos                  6                      /*!< Select input mode for pin 3 */
#define GPIO_INMODE_PIN4_Pos                  8                      /*!< Select input mode for pin 4 */
#define GPIO_INMODE_PIN5_Pos                  10                     /*!< Select input mode for pin 5 */
#define GPIO_INMODE_PIN6_Pos                  12                     /*!< Select input mode for pin 6 */
#define GPIO_INMODE_PIN7_Pos                  14                     /*!< Select input mode for pin 7 */
#define GPIO_INMODE_PIN8_Pos                  16                     /*!< Select input mode for pin 8 */
#define GPIO_INMODE_PIN9_Pos                  18                     /*!< Select input mode for pin 9 */
#define GPIO_INMODE_PIN10_Pos                 20                     /*!< Select input mode for pin 10 */
#define GPIO_INMODE_PIN11_Pos                 22                     /*!< Select input mode for pin 11 */
#define GPIO_INMODE_PIN12_Pos                 24                     /*!< Select input mode for pin 12 */
#define GPIO_INMODE_PIN13_Pos                 26                     /*!< Select input mode for pin 13 */
#define GPIO_INMODE_PIN14_Pos                 28                     /*!< Select input mode for pin 14 */
#define GPIO_INMODE_PIN15_Pos                 30                     /*!< Select input mode for pin 15 */

/* Bit field masks: */
#define GPIO_INMODE_PIN0_Msk                  0x00000003             /*!< Select input mode for pin 0 */
#define GPIO_INMODE_PIN1_Msk                  0x0000000C             /*!< Select input mode for pin 1 */
#define GPIO_INMODE_PIN2_Msk                  0x00000030             /*!< Select input mode for pin 2 */
#define GPIO_INMODE_PIN3_Msk                  0x000000C0             /*!< Select input mode for pin 3 */
#define GPIO_INMODE_PIN4_Msk                  0x00000300             /*!< Select input mode for pin 4 */
#define GPIO_INMODE_PIN5_Msk                  0x00000C00             /*!< Select input mode for pin 5 */
#define GPIO_INMODE_PIN6_Msk                  0x00003000             /*!< Select input mode for pin 6 */
#define GPIO_INMODE_PIN7_Msk                  0x0000C000             /*!< Select input mode for pin 7 */
#define GPIO_INMODE_PIN8_Msk                  0x00030000             /*!< Select input mode for pin 8 */
#define GPIO_INMODE_PIN9_Msk                  0x000C0000             /*!< Select input mode for pin 9 */
#define GPIO_INMODE_PIN10_Msk                 0x00300000             /*!< Select input mode for pin 10 */
#define GPIO_INMODE_PIN11_Msk                 0x00C00000             /*!< Select input mode for pin 11 */
#define GPIO_INMODE_PIN12_Msk                 0x03000000             /*!< Select input mode for pin 12 */
#define GPIO_INMODE_PIN13_Msk                 0x0C000000             /*!< Select input mode for pin 13 */
#define GPIO_INMODE_PIN14_Msk                 0x30000000             /*!< Select input mode for pin 14 */
#define GPIO_INMODE_PIN15_Msk                 0xC0000000             /*!< Select input mode for pin 15 */

/* Bit field enums: */
typedef enum {
  GPIO_INMODE_PIN0_Schmitt                   = 0x0,                  /*!< Scmitt buffer */
  GPIO_INMODE_PIN0_CMOS                      = 0x1,                  /*!< CMOS buffer */
  GPIO_INMODE_PIN0_Disable                   = 0x3,                  /*!< Input buffer disabled */
} GPIO_INMODE_PIN0_Enum;

typedef enum {
  GPIO_INMODE_PIN1_Schmitt                   = 0x0,                  /*!< Scmitt buffer */
  GPIO_INMODE_PIN1_CMOS                      = 0x1,                  /*!< CMOS buffer */
  GPIO_INMODE_PIN1_Disable                   = 0x3,                  /*!< Input buffer disabled */
} GPIO_INMODE_PIN1_Enum;

typedef enum {
  GPIO_INMODE_PIN2_Schmitt                   = 0x0,                  /*!< Scmitt buffer */
  GPIO_INMODE_PIN2_CMOS                      = 0x1,                  /*!< CMOS buffer */
  GPIO_INMODE_PIN2_Disable                   = 0x3,                  /*!< Input buffer disabled */
} GPIO_INMODE_PIN2_Enum;

typedef enum {
  GPIO_INMODE_PIN3_Schmitt                   = 0x0,                  /*!< Scmitt buffer */
  GPIO_INMODE_PIN3_CMOS                      = 0x1,                  /*!< CMOS buffer */
  GPIO_INMODE_PIN3_Disable                   = 0x3,                  /*!< Input buffer disabled */
} GPIO_INMODE_PIN3_Enum;

typedef enum {
  GPIO_INMODE_PIN4_Schmitt                   = 0x0,                  /*!< Scmitt buffer */
  GPIO_INMODE_PIN4_CMOS                      = 0x1,                  /*!< CMOS buffer */
  GPIO_INMODE_PIN4_Disable                   = 0x3,                  /*!< Input buffer disabled */
} GPIO_INMODE_PIN4_Enum;

typedef enum {
  GPIO_INMODE_PIN5_Schmitt                   = 0x0,                  /*!< Scmitt buffer */
  GPIO_INMODE_PIN5_CMOS                      = 0x1,                  /*!< CMOS buffer */
  GPIO_INMODE_PIN5_Disable                   = 0x3,                  /*!< Input buffer disabled */
} GPIO_INMODE_PIN5_Enum;

typedef enum {
  GPIO_INMODE_PIN6_Schmitt                   = 0x0,                  /*!< Scmitt buffer */
  GPIO_INMODE_PIN6_CMOS                      = 0x1,                  /*!< CMOS buffer */
  GPIO_INMODE_PIN6_Disable                   = 0x3,                  /*!< Input buffer disabled */
} GPIO_INMODE_PIN6_Enum;

typedef enum {
  GPIO_INMODE_PIN7_Schmitt                   = 0x0,                  /*!< Scmitt buffer */
  GPIO_INMODE_PIN7_CMOS                      = 0x1,                  /*!< CMOS buffer */
  GPIO_INMODE_PIN7_Disable                   = 0x3,                  /*!< Input buffer disabled */
} GPIO_INMODE_PIN7_Enum;

typedef enum {
  GPIO_INMODE_PIN8_Schmitt                   = 0x0,                  /*!< Scmitt buffer */
  GPIO_INMODE_PIN8_CMOS                      = 0x1,                  /*!< CMOS buffer */
  GPIO_INMODE_PIN8_Disable                   = 0x3,                  /*!< Input buffer disabled */
} GPIO_INMODE_PIN8_Enum;

typedef enum {
  GPIO_INMODE_PIN9_Schmitt                   = 0x0,                  /*!< Scmitt buffer */
  GPIO_INMODE_PIN9_CMOS                      = 0x1,                  /*!< CMOS buffer */
  GPIO_INMODE_PIN9_Disable                   = 0x3,                  /*!< Input buffer disabled */
} GPIO_INMODE_PIN9_Enum;

typedef enum {
  GPIO_INMODE_PIN10_Schmitt                  = 0x0,                  /*!< Scmitt buffer */
  GPIO_INMODE_PIN10_CMOS                     = 0x1,                  /*!< CMOS buffer */
  GPIO_INMODE_PIN10_Disable                  = 0x3,                  /*!< Input buffer disabled */
} GPIO_INMODE_PIN10_Enum;

typedef enum {
  GPIO_INMODE_PIN11_Schmitt                  = 0x0,                  /*!< Scmitt buffer */
  GPIO_INMODE_PIN11_CMOS                     = 0x1,                  /*!< CMOS buffer */
  GPIO_INMODE_PIN11_Disable                  = 0x3,                  /*!< Input buffer disabled */
} GPIO_INMODE_PIN11_Enum;

typedef enum {
  GPIO_INMODE_PIN12_Schmitt                  = 0x0,                  /*!< Scmitt buffer */
  GPIO_INMODE_PIN12_CMOS                     = 0x1,                  /*!< CMOS buffer */
  GPIO_INMODE_PIN12_Disable                  = 0x3,                  /*!< Input buffer disabled */
} GPIO_INMODE_PIN12_Enum;

typedef enum {
  GPIO_INMODE_PIN13_Schmitt                  = 0x0,                  /*!< Scmitt buffer */
  GPIO_INMODE_PIN13_CMOS                     = 0x1,                  /*!< CMOS buffer */
  GPIO_INMODE_PIN13_Disable                  = 0x3,                  /*!< Input buffer disabled */
} GPIO_INMODE_PIN13_Enum;

typedef enum {
  GPIO_INMODE_PIN14_Schmitt                  = 0x0,                  /*!< Scmitt buffer */
  GPIO_INMODE_PIN14_CMOS                     = 0x1,                  /*!< CMOS buffer */
  GPIO_INMODE_PIN14_Disable                  = 0x3,                  /*!< Input buffer disabled */
} GPIO_INMODE_PIN14_Enum;

typedef enum {
  GPIO_INMODE_PIN15_Schmitt                  = 0x0,                  /*!< Scmitt buffer */
  GPIO_INMODE_PIN15_CMOS                     = 0x1,                  /*!< CMOS buffer */
  GPIO_INMODE_PIN15_Disable                  = 0x3,                  /*!< Input buffer disabled */
} GPIO_INMODE_PIN15_Enum;

/*--  PULLMODE: Select pull mode register ---------------------------------------------------------------------*/
typedef struct {
  uint32_t PIN0                   :2;                                /*!< Select pull mode for pin 0 */
  uint32_t PIN1                   :2;                                /*!< Select pull mode for pin 1 */
  uint32_t PIN2                   :2;                                /*!< Select pull mode for pin 2 */
  uint32_t PIN3                   :2;                                /*!< Select pull mode for pin 3 */
  uint32_t PIN4                   :2;                                /*!< Select pull mode for pin 4 */
  uint32_t PIN5                   :2;                                /*!< Select pull mode for pin 5 */
  uint32_t PIN6                   :2;                                /*!< Select pull mode for pin 6 */
  uint32_t PIN7                   :2;                                /*!< Select pull mode for pin 7 */
  uint32_t PIN8                   :2;                                /*!< Select pull mode for pin 8 */
  uint32_t PIN9                   :2;                                /*!< Select pull mode for pin 9 */
  uint32_t PIN10                  :2;                                /*!< Select pull mode for pin 10 */
  uint32_t PIN11                  :2;                                /*!< Select pull mode for pin 11 */
  uint32_t PIN12                  :2;                                /*!< Select pull mode for pin 12 */
  uint32_t PIN13                  :2;                                /*!< Select pull mode for pin 13 */
  uint32_t PIN14                  :2;                                /*!< Select pull mode for pin 14 */
  uint32_t PIN15                  :2;                                /*!< Select pull mode for pin 15 */
} _GPIO_PULLMODE_bits;

/* Bit field positions: */
#define GPIO_PULLMODE_PIN0_Pos                0                      /*!< Select pull mode for pin 0 */
#define GPIO_PULLMODE_PIN1_Pos                2                      /*!< Select pull mode for pin 1 */
#define GPIO_PULLMODE_PIN2_Pos                4                      /*!< Select pull mode for pin 2 */
#define GPIO_PULLMODE_PIN3_Pos                6                      /*!< Select pull mode for pin 3 */
#define GPIO_PULLMODE_PIN4_Pos                8                      /*!< Select pull mode for pin 4 */
#define GPIO_PULLMODE_PIN5_Pos                10                     /*!< Select pull mode for pin 5 */
#define GPIO_PULLMODE_PIN6_Pos                12                     /*!< Select pull mode for pin 6 */
#define GPIO_PULLMODE_PIN7_Pos                14                     /*!< Select pull mode for pin 7 */
#define GPIO_PULLMODE_PIN8_Pos                16                     /*!< Select pull mode for pin 8 */
#define GPIO_PULLMODE_PIN9_Pos                18                     /*!< Select pull mode for pin 9 */
#define GPIO_PULLMODE_PIN10_Pos               20                     /*!< Select pull mode for pin 10 */
#define GPIO_PULLMODE_PIN11_Pos               22                     /*!< Select pull mode for pin 11 */
#define GPIO_PULLMODE_PIN12_Pos               24                     /*!< Select pull mode for pin 12 */
#define GPIO_PULLMODE_PIN13_Pos               26                     /*!< Select pull mode for pin 13 */
#define GPIO_PULLMODE_PIN14_Pos               28                     /*!< Select pull mode for pin 14 */
#define GPIO_PULLMODE_PIN15_Pos               30                     /*!< Select pull mode for pin 15 */

/* Bit field masks: */
#define GPIO_PULLMODE_PIN0_Msk                0x00000003             /*!< Select pull mode for pin 0 */
#define GPIO_PULLMODE_PIN1_Msk                0x0000000C             /*!< Select pull mode for pin 1 */
#define GPIO_PULLMODE_PIN2_Msk                0x00000030             /*!< Select pull mode for pin 2 */
#define GPIO_PULLMODE_PIN3_Msk                0x000000C0             /*!< Select pull mode for pin 3 */
#define GPIO_PULLMODE_PIN4_Msk                0x00000300             /*!< Select pull mode for pin 4 */
#define GPIO_PULLMODE_PIN5_Msk                0x00000C00             /*!< Select pull mode for pin 5 */
#define GPIO_PULLMODE_PIN6_Msk                0x00003000             /*!< Select pull mode for pin 6 */
#define GPIO_PULLMODE_PIN7_Msk                0x0000C000             /*!< Select pull mode for pin 7 */
#define GPIO_PULLMODE_PIN8_Msk                0x00030000             /*!< Select pull mode for pin 8 */
#define GPIO_PULLMODE_PIN9_Msk                0x000C0000             /*!< Select pull mode for pin 9 */
#define GPIO_PULLMODE_PIN10_Msk               0x00300000             /*!< Select pull mode for pin 10 */
#define GPIO_PULLMODE_PIN11_Msk               0x00C00000             /*!< Select pull mode for pin 11 */
#define GPIO_PULLMODE_PIN12_Msk               0x03000000             /*!< Select pull mode for pin 12 */
#define GPIO_PULLMODE_PIN13_Msk               0x0C000000             /*!< Select pull mode for pin 13 */
#define GPIO_PULLMODE_PIN14_Msk               0x30000000             /*!< Select pull mode for pin 14 */
#define GPIO_PULLMODE_PIN15_Msk               0xC0000000             /*!< Select pull mode for pin 15 */

/* Bit field enums: */
typedef enum {
  GPIO_PULLMODE_PIN0_Disable                 = 0x0,                  /*!< Pull disabled */
  GPIO_PULLMODE_PIN0_PU                      = 0x1,                  /*!< Pull-up */
  GPIO_PULLMODE_PIN0_PD                      = 0x2,                  /*!< Pull-down */
} GPIO_PULLMODE_PIN0_Enum;

typedef enum {
  GPIO_PULLMODE_PIN1_Disable                 = 0x0,                  /*!< Pull disabled */
  GPIO_PULLMODE_PIN1_PU                      = 0x1,                  /*!< Pull-up */
  GPIO_PULLMODE_PIN1_PD                      = 0x2,                  /*!< Pull-down */
} GPIO_PULLMODE_PIN1_Enum;

typedef enum {
  GPIO_PULLMODE_PIN2_Disable                 = 0x0,                  /*!< Pull disabled */
  GPIO_PULLMODE_PIN2_PU                      = 0x1,                  /*!< Pull-up */
  GPIO_PULLMODE_PIN2_PD                      = 0x2,                  /*!< Pull-down */
} GPIO_PULLMODE_PIN2_Enum;

typedef enum {
  GPIO_PULLMODE_PIN3_Disable                 = 0x0,                  /*!< Pull disabled */
  GPIO_PULLMODE_PIN3_PU                      = 0x1,                  /*!< Pull-up */
  GPIO_PULLMODE_PIN3_PD                      = 0x2,                  /*!< Pull-down */
} GPIO_PULLMODE_PIN3_Enum;

typedef enum {
  GPIO_PULLMODE_PIN4_Disable                 = 0x0,                  /*!< Pull disabled */
  GPIO_PULLMODE_PIN4_PU                      = 0x1,                  /*!< Pull-up */
  GPIO_PULLMODE_PIN4_PD                      = 0x2,                  /*!< Pull-down */
} GPIO_PULLMODE_PIN4_Enum;

typedef enum {
  GPIO_PULLMODE_PIN5_Disable                 = 0x0,                  /*!< Pull disabled */
  GPIO_PULLMODE_PIN5_PU                      = 0x1,                  /*!< Pull-up */
  GPIO_PULLMODE_PIN5_PD                      = 0x2,                  /*!< Pull-down */
} GPIO_PULLMODE_PIN5_Enum;

typedef enum {
  GPIO_PULLMODE_PIN6_Disable                 = 0x0,                  /*!< Pull disabled */
  GPIO_PULLMODE_PIN6_PU                      = 0x1,                  /*!< Pull-up */
  GPIO_PULLMODE_PIN6_PD                      = 0x2,                  /*!< Pull-down */
} GPIO_PULLMODE_PIN6_Enum;

typedef enum {
  GPIO_PULLMODE_PIN7_Disable                 = 0x0,                  /*!< Pull disabled */
  GPIO_PULLMODE_PIN7_PU                      = 0x1,                  /*!< Pull-up */
  GPIO_PULLMODE_PIN7_PD                      = 0x2,                  /*!< Pull-down */
} GPIO_PULLMODE_PIN7_Enum;

typedef enum {
  GPIO_PULLMODE_PIN8_Disable                 = 0x0,                  /*!< Pull disabled */
  GPIO_PULLMODE_PIN8_PU                      = 0x1,                  /*!< Pull-up */
  GPIO_PULLMODE_PIN8_PD                      = 0x2,                  /*!< Pull-down */
} GPIO_PULLMODE_PIN8_Enum;

typedef enum {
  GPIO_PULLMODE_PIN9_Disable                 = 0x0,                  /*!< Pull disabled */
  GPIO_PULLMODE_PIN9_PU                      = 0x1,                  /*!< Pull-up */
  GPIO_PULLMODE_PIN9_PD                      = 0x2,                  /*!< Pull-down */
} GPIO_PULLMODE_PIN9_Enum;

typedef enum {
  GPIO_PULLMODE_PIN10_Disable                = 0x0,                  /*!< Pull disabled */
  GPIO_PULLMODE_PIN10_PU                     = 0x1,                  /*!< Pull-up */
  GPIO_PULLMODE_PIN10_PD                     = 0x2,                  /*!< Pull-down */
} GPIO_PULLMODE_PIN10_Enum;

typedef enum {
  GPIO_PULLMODE_PIN11_Disable                = 0x0,                  /*!< Pull disabled */
  GPIO_PULLMODE_PIN11_PU                     = 0x1,                  /*!< Pull-up */
  GPIO_PULLMODE_PIN11_PD                     = 0x2,                  /*!< Pull-down */
} GPIO_PULLMODE_PIN11_Enum;

typedef enum {
  GPIO_PULLMODE_PIN12_Disable                = 0x0,                  /*!< Pull disabled */
  GPIO_PULLMODE_PIN12_PU                     = 0x1,                  /*!< Pull-up */
  GPIO_PULLMODE_PIN12_PD                     = 0x2,                  /*!< Pull-down */
} GPIO_PULLMODE_PIN12_Enum;

typedef enum {
  GPIO_PULLMODE_PIN13_Disable                = 0x0,                  /*!< Pull disabled */
  GPIO_PULLMODE_PIN13_PU                     = 0x1,                  /*!< Pull-up */
  GPIO_PULLMODE_PIN13_PD                     = 0x2,                  /*!< Pull-down */
} GPIO_PULLMODE_PIN13_Enum;

typedef enum {
  GPIO_PULLMODE_PIN14_Disable                = 0x0,                  /*!< Pull disabled */
  GPIO_PULLMODE_PIN14_PU                     = 0x1,                  /*!< Pull-up */
  GPIO_PULLMODE_PIN14_PD                     = 0x2,                  /*!< Pull-down */
} GPIO_PULLMODE_PIN14_Enum;

typedef enum {
  GPIO_PULLMODE_PIN15_Disable                = 0x0,                  /*!< Pull disabled */
  GPIO_PULLMODE_PIN15_PU                     = 0x1,                  /*!< Pull-up */
  GPIO_PULLMODE_PIN15_PD                     = 0x2,                  /*!< Pull-down */
} GPIO_PULLMODE_PIN15_Enum;

/*--  OUTMODE: Select output mode register --------------------------------------------------------------------*/
typedef struct {
  uint32_t PIN0                   :2;                                /*!< Select output mode for pin 0 */
  uint32_t PIN1                   :2;                                /*!< Select output mode for pin 1 */
  uint32_t PIN2                   :2;                                /*!< Select output mode for pin 2 */
  uint32_t PIN3                   :2;                                /*!< Select output mode for pin 3 */
  uint32_t PIN4                   :2;                                /*!< Select output mode for pin 4 */
  uint32_t PIN5                   :2;                                /*!< Select output mode for pin 5 */
  uint32_t PIN6                   :2;                                /*!< Select output mode for pin 6 */
  uint32_t PIN7                   :2;                                /*!< Select output mode for pin 7 */
  uint32_t PIN8                   :2;                                /*!< Select output mode for pin 8 */
  uint32_t PIN9                   :2;                                /*!< Select output mode for pin 9 */
  uint32_t PIN10                  :2;                                /*!< Select output mode for pin 10 */
  uint32_t PIN11                  :2;                                /*!< Select output mode for pin 11 */
  uint32_t PIN12                  :2;                                /*!< Select output mode for pin 12 */
  uint32_t PIN13                  :2;                                /*!< Select output mode for pin 13 */
  uint32_t PIN14                  :2;                                /*!< Select output mode for pin 14 */
  uint32_t PIN15                  :2;                                /*!< Select output mode for pin 15 */
} _GPIO_OUTMODE_bits;

/* Bit field positions: */
#define GPIO_OUTMODE_PIN0_Pos                 0                      /*!< Select output mode for pin 0 */
#define GPIO_OUTMODE_PIN1_Pos                 2                      /*!< Select output mode for pin 1 */
#define GPIO_OUTMODE_PIN2_Pos                 4                      /*!< Select output mode for pin 2 */
#define GPIO_OUTMODE_PIN3_Pos                 6                      /*!< Select output mode for pin 3 */
#define GPIO_OUTMODE_PIN4_Pos                 8                      /*!< Select output mode for pin 4 */
#define GPIO_OUTMODE_PIN5_Pos                 10                     /*!< Select output mode for pin 5 */
#define GPIO_OUTMODE_PIN6_Pos                 12                     /*!< Select output mode for pin 6 */
#define GPIO_OUTMODE_PIN7_Pos                 14                     /*!< Select output mode for pin 7 */
#define GPIO_OUTMODE_PIN8_Pos                 16                     /*!< Select output mode for pin 8 */
#define GPIO_OUTMODE_PIN9_Pos                 18                     /*!< Select output mode for pin 9 */
#define GPIO_OUTMODE_PIN10_Pos                20                     /*!< Select output mode for pin 10 */
#define GPIO_OUTMODE_PIN11_Pos                22                     /*!< Select output mode for pin 11 */
#define GPIO_OUTMODE_PIN12_Pos                24                     /*!< Select output mode for pin 12 */
#define GPIO_OUTMODE_PIN13_Pos                26                     /*!< Select output mode for pin 13 */
#define GPIO_OUTMODE_PIN14_Pos                28                     /*!< Select output mode for pin 14 */
#define GPIO_OUTMODE_PIN15_Pos                30                     /*!< Select output mode for pin 15 */

/* Bit field masks: */
#define GPIO_OUTMODE_PIN0_Msk                 0x00000003             /*!< Select output mode for pin 0 */
#define GPIO_OUTMODE_PIN1_Msk                 0x0000000C             /*!< Select output mode for pin 1 */
#define GPIO_OUTMODE_PIN2_Msk                 0x00000030             /*!< Select output mode for pin 2 */
#define GPIO_OUTMODE_PIN3_Msk                 0x000000C0             /*!< Select output mode for pin 3 */
#define GPIO_OUTMODE_PIN4_Msk                 0x00000300             /*!< Select output mode for pin 4 */
#define GPIO_OUTMODE_PIN5_Msk                 0x00000C00             /*!< Select output mode for pin 5 */
#define GPIO_OUTMODE_PIN6_Msk                 0x00003000             /*!< Select output mode for pin 6 */
#define GPIO_OUTMODE_PIN7_Msk                 0x0000C000             /*!< Select output mode for pin 7 */
#define GPIO_OUTMODE_PIN8_Msk                 0x00030000             /*!< Select output mode for pin 8 */
#define GPIO_OUTMODE_PIN9_Msk                 0x000C0000             /*!< Select output mode for pin 9 */
#define GPIO_OUTMODE_PIN10_Msk                0x00300000             /*!< Select output mode for pin 10 */
#define GPIO_OUTMODE_PIN11_Msk                0x00C00000             /*!< Select output mode for pin 11 */
#define GPIO_OUTMODE_PIN12_Msk                0x03000000             /*!< Select output mode for pin 12 */
#define GPIO_OUTMODE_PIN13_Msk                0x0C000000             /*!< Select output mode for pin 13 */
#define GPIO_OUTMODE_PIN14_Msk                0x30000000             /*!< Select output mode for pin 14 */
#define GPIO_OUTMODE_PIN15_Msk                0xC0000000             /*!< Select output mode for pin 15 */

/* Bit field enums: */
typedef enum {
  GPIO_OUTMODE_PIN0_PP                       = 0x0,                  /*!< Push-pull output */
  GPIO_OUTMODE_PIN0_OD                       = 0x1,                  /*!< Open drain output */
  GPIO_OUTMODE_PIN0_OS                       = 0x2,                  /*!< Open source output */
} GPIO_OUTMODE_PIN0_Enum;

typedef enum {
  GPIO_OUTMODE_PIN1_PP                       = 0x0,                  /*!< Push-pull output */
  GPIO_OUTMODE_PIN1_OD                       = 0x1,                  /*!< Open drain output */
  GPIO_OUTMODE_PIN1_OS                       = 0x2,                  /*!< Open source output */
} GPIO_OUTMODE_PIN1_Enum;

typedef enum {
  GPIO_OUTMODE_PIN2_PP                       = 0x0,                  /*!< Push-pull output */
  GPIO_OUTMODE_PIN2_OD                       = 0x1,                  /*!< Open drain output */
  GPIO_OUTMODE_PIN2_OS                       = 0x2,                  /*!< Open source output */
} GPIO_OUTMODE_PIN2_Enum;

typedef enum {
  GPIO_OUTMODE_PIN3_PP                       = 0x0,                  /*!< Push-pull output */
  GPIO_OUTMODE_PIN3_OD                       = 0x1,                  /*!< Open drain output */
  GPIO_OUTMODE_PIN3_OS                       = 0x2,                  /*!< Open source output */
} GPIO_OUTMODE_PIN3_Enum;

typedef enum {
  GPIO_OUTMODE_PIN4_PP                       = 0x0,                  /*!< Push-pull output */
  GPIO_OUTMODE_PIN4_OD                       = 0x1,                  /*!< Open drain output */
  GPIO_OUTMODE_PIN4_OS                       = 0x2,                  /*!< Open source output */
} GPIO_OUTMODE_PIN4_Enum;

typedef enum {
  GPIO_OUTMODE_PIN5_PP                       = 0x0,                  /*!< Push-pull output */
  GPIO_OUTMODE_PIN5_OD                       = 0x1,                  /*!< Open drain output */
  GPIO_OUTMODE_PIN5_OS                       = 0x2,                  /*!< Open source output */
} GPIO_OUTMODE_PIN5_Enum;

typedef enum {
  GPIO_OUTMODE_PIN6_PP                       = 0x0,                  /*!< Push-pull output */
  GPIO_OUTMODE_PIN6_OD                       = 0x1,                  /*!< Open drain output */
  GPIO_OUTMODE_PIN6_OS                       = 0x2,                  /*!< Open source output */
} GPIO_OUTMODE_PIN6_Enum;

typedef enum {
  GPIO_OUTMODE_PIN7_PP                       = 0x0,                  /*!< Push-pull output */
  GPIO_OUTMODE_PIN7_OD                       = 0x1,                  /*!< Open drain output */
  GPIO_OUTMODE_PIN7_OS                       = 0x2,                  /*!< Open source output */
} GPIO_OUTMODE_PIN7_Enum;

typedef enum {
  GPIO_OUTMODE_PIN8_PP                       = 0x0,                  /*!< Push-pull output */
  GPIO_OUTMODE_PIN8_OD                       = 0x1,                  /*!< Open drain output */
  GPIO_OUTMODE_PIN8_OS                       = 0x2,                  /*!< Open source output */
} GPIO_OUTMODE_PIN8_Enum;

typedef enum {
  GPIO_OUTMODE_PIN9_PP                       = 0x0,                  /*!< Push-pull output */
  GPIO_OUTMODE_PIN9_OD                       = 0x1,                  /*!< Open drain output */
  GPIO_OUTMODE_PIN9_OS                       = 0x2,                  /*!< Open source output */
} GPIO_OUTMODE_PIN9_Enum;

typedef enum {
  GPIO_OUTMODE_PIN10_PP                      = 0x0,                  /*!< Push-pull output */
  GPIO_OUTMODE_PIN10_OD                      = 0x1,                  /*!< Open drain output */
  GPIO_OUTMODE_PIN10_OS                      = 0x2,                  /*!< Open source output */
} GPIO_OUTMODE_PIN10_Enum;

typedef enum {
  GPIO_OUTMODE_PIN11_PP                      = 0x0,                  /*!< Push-pull output */
  GPIO_OUTMODE_PIN11_OD                      = 0x1,                  /*!< Open drain output */
  GPIO_OUTMODE_PIN11_OS                      = 0x2,                  /*!< Open source output */
} GPIO_OUTMODE_PIN11_Enum;

typedef enum {
  GPIO_OUTMODE_PIN12_PP                      = 0x0,                  /*!< Push-pull output */
  GPIO_OUTMODE_PIN12_OD                      = 0x1,                  /*!< Open drain output */
  GPIO_OUTMODE_PIN12_OS                      = 0x2,                  /*!< Open source output */
} GPIO_OUTMODE_PIN12_Enum;

typedef enum {
  GPIO_OUTMODE_PIN13_PP                      = 0x0,                  /*!< Push-pull output */
  GPIO_OUTMODE_PIN13_OD                      = 0x1,                  /*!< Open drain output */
  GPIO_OUTMODE_PIN13_OS                      = 0x2,                  /*!< Open source output */
} GPIO_OUTMODE_PIN13_Enum;

typedef enum {
  GPIO_OUTMODE_PIN14_PP                      = 0x0,                  /*!< Push-pull output */
  GPIO_OUTMODE_PIN14_OD                      = 0x1,                  /*!< Open drain output */
  GPIO_OUTMODE_PIN14_OS                      = 0x2,                  /*!< Open source output */
} GPIO_OUTMODE_PIN14_Enum;

typedef enum {
  GPIO_OUTMODE_PIN15_PP                      = 0x0,                  /*!< Push-pull output */
  GPIO_OUTMODE_PIN15_OD                      = 0x1,                  /*!< Open drain output */
  GPIO_OUTMODE_PIN15_OS                      = 0x2,                  /*!< Open source output */
} GPIO_OUTMODE_PIN15_Enum;

/*--  DRIVEMODE: Select drive mode register -------------------------------------------------------------------*/
typedef struct {
  uint32_t PIN0                   :2;                                /*!< Select drive mode for pin 0 */
  uint32_t PIN1                   :2;                                /*!< Select drive mode for pin 1 */
  uint32_t PIN2                   :2;                                /*!< Select drive mode for pin 2 */
  uint32_t PIN3                   :2;                                /*!< Select drive mode for pin 3 */
  uint32_t PIN4                   :2;                                /*!< Select drive mode for pin 4 */
  uint32_t PIN5                   :2;                                /*!< Select drive mode for pin 5 */
  uint32_t PIN6                   :2;                                /*!< Select drive mode for pin 6 */
  uint32_t PIN7                   :2;                                /*!< Select drive mode for pin 7 */
  uint32_t PIN8                   :2;                                /*!< Select drive mode for pin 8 */
  uint32_t PIN9                   :2;                                /*!< Select drive mode for pin 9 */
  uint32_t PIN10                  :2;                                /*!< Select drive mode for pin 10 */
  uint32_t PIN11                  :2;                                /*!< Select drive mode for pin 11 */
  uint32_t PIN12                  :2;                                /*!< Select drive mode for pin 12 */
  uint32_t PIN13                  :2;                                /*!< Select drive mode for pin 13 */
  uint32_t PIN14                  :2;                                /*!< Select drive mode for pin 14 */
  uint32_t PIN15                  :2;                                /*!< Select drive mode for pin 15 */
} _GPIO_DRIVEMODE_bits;

/* Bit field positions: */
#define GPIO_DRIVEMODE_PIN0_Pos               0                      /*!< Select drive mode for pin 0 */
#define GPIO_DRIVEMODE_PIN1_Pos               2                      /*!< Select drive mode for pin 1 */
#define GPIO_DRIVEMODE_PIN2_Pos               4                      /*!< Select drive mode for pin 2 */
#define GPIO_DRIVEMODE_PIN3_Pos               6                      /*!< Select drive mode for pin 3 */
#define GPIO_DRIVEMODE_PIN4_Pos               8                      /*!< Select drive mode for pin 4 */
#define GPIO_DRIVEMODE_PIN5_Pos               10                     /*!< Select drive mode for pin 5 */
#define GPIO_DRIVEMODE_PIN6_Pos               12                     /*!< Select drive mode for pin 6 */
#define GPIO_DRIVEMODE_PIN7_Pos               14                     /*!< Select drive mode for pin 7 */
#define GPIO_DRIVEMODE_PIN8_Pos               16                     /*!< Select drive mode for pin 8 */
#define GPIO_DRIVEMODE_PIN9_Pos               18                     /*!< Select drive mode for pin 9 */
#define GPIO_DRIVEMODE_PIN10_Pos              20                     /*!< Select drive mode for pin 10 */
#define GPIO_DRIVEMODE_PIN11_Pos              22                     /*!< Select drive mode for pin 11 */
#define GPIO_DRIVEMODE_PIN12_Pos              24                     /*!< Select drive mode for pin 12 */
#define GPIO_DRIVEMODE_PIN13_Pos              26                     /*!< Select drive mode for pin 13 */
#define GPIO_DRIVEMODE_PIN14_Pos              28                     /*!< Select drive mode for pin 14 */
#define GPIO_DRIVEMODE_PIN15_Pos              30                     /*!< Select drive mode for pin 15 */

/* Bit field masks: */
#define GPIO_DRIVEMODE_PIN0_Msk               0x00000003             /*!< Select drive mode for pin 0 */
#define GPIO_DRIVEMODE_PIN1_Msk               0x0000000C             /*!< Select drive mode for pin 1 */
#define GPIO_DRIVEMODE_PIN2_Msk               0x00000030             /*!< Select drive mode for pin 2 */
#define GPIO_DRIVEMODE_PIN3_Msk               0x000000C0             /*!< Select drive mode for pin 3 */
#define GPIO_DRIVEMODE_PIN4_Msk               0x00000300             /*!< Select drive mode for pin 4 */
#define GPIO_DRIVEMODE_PIN5_Msk               0x00000C00             /*!< Select drive mode for pin 5 */
#define GPIO_DRIVEMODE_PIN6_Msk               0x00003000             /*!< Select drive mode for pin 6 */
#define GPIO_DRIVEMODE_PIN7_Msk               0x0000C000             /*!< Select drive mode for pin 7 */
#define GPIO_DRIVEMODE_PIN8_Msk               0x00030000             /*!< Select drive mode for pin 8 */
#define GPIO_DRIVEMODE_PIN9_Msk               0x000C0000             /*!< Select drive mode for pin 9 */
#define GPIO_DRIVEMODE_PIN10_Msk              0x00300000             /*!< Select drive mode for pin 10 */
#define GPIO_DRIVEMODE_PIN11_Msk              0x00C00000             /*!< Select drive mode for pin 11 */
#define GPIO_DRIVEMODE_PIN12_Msk              0x03000000             /*!< Select drive mode for pin 12 */
#define GPIO_DRIVEMODE_PIN13_Msk              0x0C000000             /*!< Select drive mode for pin 13 */
#define GPIO_DRIVEMODE_PIN14_Msk              0x30000000             /*!< Select drive mode for pin 14 */
#define GPIO_DRIVEMODE_PIN15_Msk              0xC0000000             /*!< Select drive mode for pin 15 */

/* Bit field enums: */
typedef enum {
  GPIO_DRIVEMODE_PIN0_HF                     = 0x0,                  /*!< High strength and Fast rate */
  GPIO_DRIVEMODE_PIN0_HS                     = 0x1,                  /*!< High strength and Slow rate */
  GPIO_DRIVEMODE_PIN0_LF                     = 0x2,                  /*!< Low strength and Fast rate */
  GPIO_DRIVEMODE_PIN0_LS                     = 0x3,                  /*!< Low strength and Slow rate */
} GPIO_DRIVEMODE_PIN0_Enum;

typedef enum {
  GPIO_DRIVEMODE_PIN1_HF                     = 0x0,                  /*!< High strength and Fast rate */
  GPIO_DRIVEMODE_PIN1_HS                     = 0x1,                  /*!< High strength and Slow rate */
  GPIO_DRIVEMODE_PIN1_LF                     = 0x2,                  /*!< Low strength and Fast rate */
  GPIO_DRIVEMODE_PIN1_LS                     = 0x3,                  /*!< Low strength and Slow rate */
} GPIO_DRIVEMODE_PIN1_Enum;

typedef enum {
  GPIO_DRIVEMODE_PIN2_HF                     = 0x0,                  /*!< High strength and Fast rate */
  GPIO_DRIVEMODE_PIN2_HS                     = 0x1,                  /*!< High strength and Slow rate */
  GPIO_DRIVEMODE_PIN2_LF                     = 0x2,                  /*!< Low strength and Fast rate */
  GPIO_DRIVEMODE_PIN2_LS                     = 0x3,                  /*!< Low strength and Slow rate */
} GPIO_DRIVEMODE_PIN2_Enum;

typedef enum {
  GPIO_DRIVEMODE_PIN3_HF                     = 0x0,                  /*!< High strength and Fast rate */
  GPIO_DRIVEMODE_PIN3_HS                     = 0x1,                  /*!< High strength and Slow rate */
  GPIO_DRIVEMODE_PIN3_LF                     = 0x2,                  /*!< Low strength and Fast rate */
  GPIO_DRIVEMODE_PIN3_LS                     = 0x3,                  /*!< Low strength and Slow rate */
} GPIO_DRIVEMODE_PIN3_Enum;

typedef enum {
  GPIO_DRIVEMODE_PIN4_HF                     = 0x0,                  /*!< High strength and Fast rate */
  GPIO_DRIVEMODE_PIN4_HS                     = 0x1,                  /*!< High strength and Slow rate */
  GPIO_DRIVEMODE_PIN4_LF                     = 0x2,                  /*!< Low strength and Fast rate */
  GPIO_DRIVEMODE_PIN4_LS                     = 0x3,                  /*!< Low strength and Slow rate */
} GPIO_DRIVEMODE_PIN4_Enum;

typedef enum {
  GPIO_DRIVEMODE_PIN5_HF                     = 0x0,                  /*!< High strength and Fast rate */
  GPIO_DRIVEMODE_PIN5_HS                     = 0x1,                  /*!< High strength and Slow rate */
  GPIO_DRIVEMODE_PIN5_LF                     = 0x2,                  /*!< Low strength and Fast rate */
  GPIO_DRIVEMODE_PIN5_LS                     = 0x3,                  /*!< Low strength and Slow rate */
} GPIO_DRIVEMODE_PIN5_Enum;

typedef enum {
  GPIO_DRIVEMODE_PIN6_HF                     = 0x0,                  /*!< High strength and Fast rate */
  GPIO_DRIVEMODE_PIN6_HS                     = 0x1,                  /*!< High strength and Slow rate */
  GPIO_DRIVEMODE_PIN6_LF                     = 0x2,                  /*!< Low strength and Fast rate */
  GPIO_DRIVEMODE_PIN6_LS                     = 0x3,                  /*!< Low strength and Slow rate */
} GPIO_DRIVEMODE_PIN6_Enum;

typedef enum {
  GPIO_DRIVEMODE_PIN7_HF                     = 0x0,                  /*!< High strength and Fast rate */
  GPIO_DRIVEMODE_PIN7_HS                     = 0x1,                  /*!< High strength and Slow rate */
  GPIO_DRIVEMODE_PIN7_LF                     = 0x2,                  /*!< Low strength and Fast rate */
  GPIO_DRIVEMODE_PIN7_LS                     = 0x3,                  /*!< Low strength and Slow rate */
} GPIO_DRIVEMODE_PIN7_Enum;

typedef enum {
  GPIO_DRIVEMODE_PIN8_HF                     = 0x0,                  /*!< High strength and Fast rate */
  GPIO_DRIVEMODE_PIN8_HS                     = 0x1,                  /*!< High strength and Slow rate */
  GPIO_DRIVEMODE_PIN8_LF                     = 0x2,                  /*!< Low strength and Fast rate */
  GPIO_DRIVEMODE_PIN8_LS                     = 0x3,                  /*!< Low strength and Slow rate */
} GPIO_DRIVEMODE_PIN8_Enum;

typedef enum {
  GPIO_DRIVEMODE_PIN9_HF                     = 0x0,                  /*!< High strength and Fast rate */
  GPIO_DRIVEMODE_PIN9_HS                     = 0x1,                  /*!< High strength and Slow rate */
  GPIO_DRIVEMODE_PIN9_LF                     = 0x2,                  /*!< Low strength and Fast rate */
  GPIO_DRIVEMODE_PIN9_LS                     = 0x3,                  /*!< Low strength and Slow rate */
} GPIO_DRIVEMODE_PIN9_Enum;

typedef enum {
  GPIO_DRIVEMODE_PIN10_HF                    = 0x0,                  /*!< High strength and Fast rate */
  GPIO_DRIVEMODE_PIN10_HS                    = 0x1,                  /*!< High strength and Slow rate */
  GPIO_DRIVEMODE_PIN10_LF                    = 0x2,                  /*!< Low strength and Fast rate */
  GPIO_DRIVEMODE_PIN10_LS                    = 0x3,                  /*!< Low strength and Slow rate */
} GPIO_DRIVEMODE_PIN10_Enum;

typedef enum {
  GPIO_DRIVEMODE_PIN11_HF                    = 0x0,                  /*!< High strength and Fast rate */
  GPIO_DRIVEMODE_PIN11_HS                    = 0x1,                  /*!< High strength and Slow rate */
  GPIO_DRIVEMODE_PIN11_LF                    = 0x2,                  /*!< Low strength and Fast rate */
  GPIO_DRIVEMODE_PIN11_LS                    = 0x3,                  /*!< Low strength and Slow rate */
} GPIO_DRIVEMODE_PIN11_Enum;

typedef enum {
  GPIO_DRIVEMODE_PIN12_HF                    = 0x0,                  /*!< High strength and Fast rate */
  GPIO_DRIVEMODE_PIN12_HS                    = 0x1,                  /*!< High strength and Slow rate */
  GPIO_DRIVEMODE_PIN12_LF                    = 0x2,                  /*!< Low strength and Fast rate */
  GPIO_DRIVEMODE_PIN12_LS                    = 0x3,                  /*!< Low strength and Slow rate */
} GPIO_DRIVEMODE_PIN12_Enum;

typedef enum {
  GPIO_DRIVEMODE_PIN13_HF                    = 0x0,                  /*!< High strength and Fast rate */
  GPIO_DRIVEMODE_PIN13_HS                    = 0x1,                  /*!< High strength and Slow rate */
  GPIO_DRIVEMODE_PIN13_LF                    = 0x2,                  /*!< Low strength and Fast rate */
  GPIO_DRIVEMODE_PIN13_LS                    = 0x3,                  /*!< Low strength and Slow rate */
} GPIO_DRIVEMODE_PIN13_Enum;

typedef enum {
  GPIO_DRIVEMODE_PIN14_HF                    = 0x0,                  /*!< High strength and Fast rate */
  GPIO_DRIVEMODE_PIN14_HS                    = 0x1,                  /*!< High strength and Slow rate */
  GPIO_DRIVEMODE_PIN14_LF                    = 0x2,                  /*!< Low strength and Fast rate */
  GPIO_DRIVEMODE_PIN14_LS                    = 0x3,                  /*!< Low strength and Slow rate */
} GPIO_DRIVEMODE_PIN14_Enum;

typedef enum {
  GPIO_DRIVEMODE_PIN15_HF                    = 0x0,                  /*!< High strength and Fast rate */
  GPIO_DRIVEMODE_PIN15_HS                    = 0x1,                  /*!< High strength and Slow rate */
  GPIO_DRIVEMODE_PIN15_LF                    = 0x2,                  /*!< Low strength and Fast rate */
  GPIO_DRIVEMODE_PIN15_LS                    = 0x3,                  /*!< Low strength and Slow rate */
} GPIO_DRIVEMODE_PIN15_Enum;

/*--  OUTENSET: Output enable register ------------------------------------------------------------------------*/
typedef struct {
  uint32_t PIN0                   :1;                                /*!< Output enable for pin 0 */
  uint32_t PIN1                   :1;                                /*!< Output enable for pin 1 */
  uint32_t PIN2                   :1;                                /*!< Output enable for pin 2 */
  uint32_t PIN3                   :1;                                /*!< Output enable for pin 3 */
  uint32_t PIN4                   :1;                                /*!< Output enable for pin 4 */
  uint32_t PIN5                   :1;                                /*!< Output enable for pin 5 */
  uint32_t PIN6                   :1;                                /*!< Output enable for pin 6 */
  uint32_t PIN7                   :1;                                /*!< Output enable for pin 7 */
  uint32_t PIN8                   :1;                                /*!< Output enable for pin 8 */
  uint32_t PIN9                   :1;                                /*!< Output enable for pin 9 */
  uint32_t PIN10                  :1;                                /*!< Output enable for pin 10 */
  uint32_t PIN11                  :1;                                /*!< Output enable for pin 11 */
  uint32_t PIN12                  :1;                                /*!< Output enable for pin 12 */
  uint32_t PIN13                  :1;                                /*!< Output enable for pin 13 */
  uint32_t PIN14                  :1;                                /*!< Output enable for pin 14 */
  uint32_t PIN15                  :1;                                /*!< Output enable for pin 15 */
} _GPIO_OUTENSET_bits;

/* Bit field positions: */
#define GPIO_OUTENSET_PIN0_Pos                0                      /*!< Output enable for pin 0 */
#define GPIO_OUTENSET_PIN1_Pos                1                      /*!< Output enable for pin 1 */
#define GPIO_OUTENSET_PIN2_Pos                2                      /*!< Output enable for pin 2 */
#define GPIO_OUTENSET_PIN3_Pos                3                      /*!< Output enable for pin 3 */
#define GPIO_OUTENSET_PIN4_Pos                4                      /*!< Output enable for pin 4 */
#define GPIO_OUTENSET_PIN5_Pos                5                      /*!< Output enable for pin 5 */
#define GPIO_OUTENSET_PIN6_Pos                6                      /*!< Output enable for pin 6 */
#define GPIO_OUTENSET_PIN7_Pos                7                      /*!< Output enable for pin 7 */
#define GPIO_OUTENSET_PIN8_Pos                8                      /*!< Output enable for pin 8 */
#define GPIO_OUTENSET_PIN9_Pos                9                      /*!< Output enable for pin 9 */
#define GPIO_OUTENSET_PIN10_Pos               10                     /*!< Output enable for pin 10 */
#define GPIO_OUTENSET_PIN11_Pos               11                     /*!< Output enable for pin 11 */
#define GPIO_OUTENSET_PIN12_Pos               12                     /*!< Output enable for pin 12 */
#define GPIO_OUTENSET_PIN13_Pos               13                     /*!< Output enable for pin 13 */
#define GPIO_OUTENSET_PIN14_Pos               14                     /*!< Output enable for pin 14 */
#define GPIO_OUTENSET_PIN15_Pos               15                     /*!< Output enable for pin 15 */

/* Bit field masks: */
#define GPIO_OUTENSET_PIN0_Msk                0x00000001             /*!< Output enable for pin 0 */
#define GPIO_OUTENSET_PIN1_Msk                0x00000002             /*!< Output enable for pin 1 */
#define GPIO_OUTENSET_PIN2_Msk                0x00000004             /*!< Output enable for pin 2 */
#define GPIO_OUTENSET_PIN3_Msk                0x00000008             /*!< Output enable for pin 3 */
#define GPIO_OUTENSET_PIN4_Msk                0x00000010             /*!< Output enable for pin 4 */
#define GPIO_OUTENSET_PIN5_Msk                0x00000020             /*!< Output enable for pin 5 */
#define GPIO_OUTENSET_PIN6_Msk                0x00000040             /*!< Output enable for pin 6 */
#define GPIO_OUTENSET_PIN7_Msk                0x00000080             /*!< Output enable for pin 7 */
#define GPIO_OUTENSET_PIN8_Msk                0x00000100             /*!< Output enable for pin 8 */
#define GPIO_OUTENSET_PIN9_Msk                0x00000200             /*!< Output enable for pin 9 */
#define GPIO_OUTENSET_PIN10_Msk               0x00000400             /*!< Output enable for pin 10 */
#define GPIO_OUTENSET_PIN11_Msk               0x00000800             /*!< Output enable for pin 11 */
#define GPIO_OUTENSET_PIN12_Msk               0x00001000             /*!< Output enable for pin 12 */
#define GPIO_OUTENSET_PIN13_Msk               0x00002000             /*!< Output enable for pin 13 */
#define GPIO_OUTENSET_PIN14_Msk               0x00004000             /*!< Output enable for pin 14 */
#define GPIO_OUTENSET_PIN15_Msk               0x00008000             /*!< Output enable for pin 15 */

/*--  OUTENCLR: Output disable register -----------------------------------------------------------------------*/
typedef struct {
  uint32_t PIN0                   :1;                                /*!< Output disable for pin 0 */
  uint32_t PIN1                   :1;                                /*!< Output disable for pin 1 */
  uint32_t PIN2                   :1;                                /*!< Output disable for pin 2 */
  uint32_t PIN3                   :1;                                /*!< Output disable for pin 3 */
  uint32_t PIN4                   :1;                                /*!< Output disable for pin 4 */
  uint32_t PIN5                   :1;                                /*!< Output disable for pin 5 */
  uint32_t PIN6                   :1;                                /*!< Output disable for pin 6 */
  uint32_t PIN7                   :1;                                /*!< Output disable for pin 7 */
  uint32_t PIN8                   :1;                                /*!< Output disable for pin 8 */
  uint32_t PIN9                   :1;                                /*!< Output disable for pin 9 */
  uint32_t PIN10                  :1;                                /*!< Output disable for pin 10 */
  uint32_t PIN11                  :1;                                /*!< Output disable for pin 11 */
  uint32_t PIN12                  :1;                                /*!< Output disable for pin 12 */
  uint32_t PIN13                  :1;                                /*!< Output disable for pin 13 */
  uint32_t PIN14                  :1;                                /*!< Output disable for pin 14 */
  uint32_t PIN15                  :1;                                /*!< Output disable for pin 15 */
} _GPIO_OUTENCLR_bits;

/* Bit field positions: */
#define GPIO_OUTENCLR_PIN0_Pos                0                      /*!< Output disable for pin 0 */
#define GPIO_OUTENCLR_PIN1_Pos                1                      /*!< Output disable for pin 1 */
#define GPIO_OUTENCLR_PIN2_Pos                2                      /*!< Output disable for pin 2 */
#define GPIO_OUTENCLR_PIN3_Pos                3                      /*!< Output disable for pin 3 */
#define GPIO_OUTENCLR_PIN4_Pos                4                      /*!< Output disable for pin 4 */
#define GPIO_OUTENCLR_PIN5_Pos                5                      /*!< Output disable for pin 5 */
#define GPIO_OUTENCLR_PIN6_Pos                6                      /*!< Output disable for pin 6 */
#define GPIO_OUTENCLR_PIN7_Pos                7                      /*!< Output disable for pin 7 */
#define GPIO_OUTENCLR_PIN8_Pos                8                      /*!< Output disable for pin 8 */
#define GPIO_OUTENCLR_PIN9_Pos                9                      /*!< Output disable for pin 9 */
#define GPIO_OUTENCLR_PIN10_Pos               10                     /*!< Output disable for pin 10 */
#define GPIO_OUTENCLR_PIN11_Pos               11                     /*!< Output disable for pin 11 */
#define GPIO_OUTENCLR_PIN12_Pos               12                     /*!< Output disable for pin 12 */
#define GPIO_OUTENCLR_PIN13_Pos               13                     /*!< Output disable for pin 13 */
#define GPIO_OUTENCLR_PIN14_Pos               14                     /*!< Output disable for pin 14 */
#define GPIO_OUTENCLR_PIN15_Pos               15                     /*!< Output disable for pin 15 */

/* Bit field masks: */
#define GPIO_OUTENCLR_PIN0_Msk                0x00000001             /*!< Output disable for pin 0 */
#define GPIO_OUTENCLR_PIN1_Msk                0x00000002             /*!< Output disable for pin 1 */
#define GPIO_OUTENCLR_PIN2_Msk                0x00000004             /*!< Output disable for pin 2 */
#define GPIO_OUTENCLR_PIN3_Msk                0x00000008             /*!< Output disable for pin 3 */
#define GPIO_OUTENCLR_PIN4_Msk                0x00000010             /*!< Output disable for pin 4 */
#define GPIO_OUTENCLR_PIN5_Msk                0x00000020             /*!< Output disable for pin 5 */
#define GPIO_OUTENCLR_PIN6_Msk                0x00000040             /*!< Output disable for pin 6 */
#define GPIO_OUTENCLR_PIN7_Msk                0x00000080             /*!< Output disable for pin 7 */
#define GPIO_OUTENCLR_PIN8_Msk                0x00000100             /*!< Output disable for pin 8 */
#define GPIO_OUTENCLR_PIN9_Msk                0x00000200             /*!< Output disable for pin 9 */
#define GPIO_OUTENCLR_PIN10_Msk               0x00000400             /*!< Output disable for pin 10 */
#define GPIO_OUTENCLR_PIN11_Msk               0x00000800             /*!< Output disable for pin 11 */
#define GPIO_OUTENCLR_PIN12_Msk               0x00001000             /*!< Output disable for pin 12 */
#define GPIO_OUTENCLR_PIN13_Msk               0x00002000             /*!< Output disable for pin 13 */
#define GPIO_OUTENCLR_PIN14_Msk               0x00004000             /*!< Output disable for pin 14 */
#define GPIO_OUTENCLR_PIN15_Msk               0x00008000             /*!< Output disable for pin 15 */

/*--  ALTFUNCSET: Alternative function enable register --------------------------------------------------------*/
typedef struct {
  uint32_t PIN0                   :1;                                /*!< Alternative function enable for pin 0 */
  uint32_t PIN1                   :1;                                /*!< Alternative function enable for pin 1 */
  uint32_t PIN2                   :1;                                /*!< Alternative function enable for pin 2 */
  uint32_t PIN3                   :1;                                /*!< Alternative function enable for pin 3 */
  uint32_t PIN4                   :1;                                /*!< Alternative function enable for pin 4 */
  uint32_t PIN5                   :1;                                /*!< Alternative function enable for pin 5 */
  uint32_t PIN6                   :1;                                /*!< Alternative function enable for pin 6 */
  uint32_t PIN7                   :1;                                /*!< Alternative function enable for pin 7 */
  uint32_t PIN8                   :1;                                /*!< Alternative function enable for pin 8 */
  uint32_t PIN9                   :1;                                /*!< Alternative function enable for pin 9 */
  uint32_t PIN10                  :1;                                /*!< Alternative function enable for pin 10 */
  uint32_t PIN11                  :1;                                /*!< Alternative function enable for pin 11 */
  uint32_t PIN12                  :1;                                /*!< Alternative function enable for pin 12 */
  uint32_t PIN13                  :1;                                /*!< Alternative function enable for pin 13 */
  uint32_t PIN14                  :1;                                /*!< Alternative function enable for pin 14 */
  uint32_t PIN15                  :1;                                /*!< Alternative function enable for pin 15 */
} _GPIO_ALTFUNCSET_bits;

/* Bit field positions: */
#define GPIO_ALTFUNCSET_PIN0_Pos              0                      /*!< Alternative function enable for pin 0 */
#define GPIO_ALTFUNCSET_PIN1_Pos              1                      /*!< Alternative function enable for pin 1 */
#define GPIO_ALTFUNCSET_PIN2_Pos              2                      /*!< Alternative function enable for pin 2 */
#define GPIO_ALTFUNCSET_PIN3_Pos              3                      /*!< Alternative function enable for pin 3 */
#define GPIO_ALTFUNCSET_PIN4_Pos              4                      /*!< Alternative function enable for pin 4 */
#define GPIO_ALTFUNCSET_PIN5_Pos              5                      /*!< Alternative function enable for pin 5 */
#define GPIO_ALTFUNCSET_PIN6_Pos              6                      /*!< Alternative function enable for pin 6 */
#define GPIO_ALTFUNCSET_PIN7_Pos              7                      /*!< Alternative function enable for pin 7 */
#define GPIO_ALTFUNCSET_PIN8_Pos              8                      /*!< Alternative function enable for pin 8 */
#define GPIO_ALTFUNCSET_PIN9_Pos              9                      /*!< Alternative function enable for pin 9 */
#define GPIO_ALTFUNCSET_PIN10_Pos             10                     /*!< Alternative function enable for pin 10 */
#define GPIO_ALTFUNCSET_PIN11_Pos             11                     /*!< Alternative function enable for pin 11 */
#define GPIO_ALTFUNCSET_PIN12_Pos             12                     /*!< Alternative function enable for pin 12 */
#define GPIO_ALTFUNCSET_PIN13_Pos             13                     /*!< Alternative function enable for pin 13 */
#define GPIO_ALTFUNCSET_PIN14_Pos             14                     /*!< Alternative function enable for pin 14 */
#define GPIO_ALTFUNCSET_PIN15_Pos             15                     /*!< Alternative function enable for pin 15 */

/* Bit field masks: */
#define GPIO_ALTFUNCSET_PIN0_Msk              0x00000001             /*!< Alternative function enable for pin 0 */
#define GPIO_ALTFUNCSET_PIN1_Msk              0x00000002             /*!< Alternative function enable for pin 1 */
#define GPIO_ALTFUNCSET_PIN2_Msk              0x00000004             /*!< Alternative function enable for pin 2 */
#define GPIO_ALTFUNCSET_PIN3_Msk              0x00000008             /*!< Alternative function enable for pin 3 */
#define GPIO_ALTFUNCSET_PIN4_Msk              0x00000010             /*!< Alternative function enable for pin 4 */
#define GPIO_ALTFUNCSET_PIN5_Msk              0x00000020             /*!< Alternative function enable for pin 5 */
#define GPIO_ALTFUNCSET_PIN6_Msk              0x00000040             /*!< Alternative function enable for pin 6 */
#define GPIO_ALTFUNCSET_PIN7_Msk              0x00000080             /*!< Alternative function enable for pin 7 */
#define GPIO_ALTFUNCSET_PIN8_Msk              0x00000100             /*!< Alternative function enable for pin 8 */
#define GPIO_ALTFUNCSET_PIN9_Msk              0x00000200             /*!< Alternative function enable for pin 9 */
#define GPIO_ALTFUNCSET_PIN10_Msk             0x00000400             /*!< Alternative function enable for pin 10 */
#define GPIO_ALTFUNCSET_PIN11_Msk             0x00000800             /*!< Alternative function enable for pin 11 */
#define GPIO_ALTFUNCSET_PIN12_Msk             0x00001000             /*!< Alternative function enable for pin 12 */
#define GPIO_ALTFUNCSET_PIN13_Msk             0x00002000             /*!< Alternative function enable for pin 13 */
#define GPIO_ALTFUNCSET_PIN14_Msk             0x00004000             /*!< Alternative function enable for pin 14 */
#define GPIO_ALTFUNCSET_PIN15_Msk             0x00008000             /*!< Alternative function enable for pin 15 */

/*--  ALTFUNCCLR: Alternative function disable register -------------------------------------------------------*/
typedef struct {
  uint32_t PIN0                   :1;                                /*!< Alternative function disable for pin 0 */
  uint32_t PIN1                   :1;                                /*!< Alternative function disable for pin 1 */
  uint32_t PIN2                   :1;                                /*!< Alternative function disable for pin 2 */
  uint32_t PIN3                   :1;                                /*!< Alternative function disable for pin 3 */
  uint32_t PIN4                   :1;                                /*!< Alternative function disable for pin 4 */
  uint32_t PIN5                   :1;                                /*!< Alternative function disable for pin 5 */
  uint32_t PIN6                   :1;                                /*!< Alternative function disable for pin 6 */
  uint32_t PIN7                   :1;                                /*!< Alternative function disable for pin 7 */
  uint32_t PIN8                   :1;                                /*!< Alternative function disable for pin 8 */
  uint32_t PIN9                   :1;                                /*!< Alternative function disable for pin 9 */
  uint32_t PIN10                  :1;                                /*!< Alternative function disable for pin 10 */
  uint32_t PIN11                  :1;                                /*!< Alternative function disable for pin 11 */
  uint32_t PIN12                  :1;                                /*!< Alternative function disable for pin 12 */
  uint32_t PIN13                  :1;                                /*!< Alternative function disable for pin 13 */
  uint32_t PIN14                  :1;                                /*!< Alternative function disable for pin 14 */
  uint32_t PIN15                  :1;                                /*!< Alternative function disable for pin 15 */
} _GPIO_ALTFUNCCLR_bits;

/* Bit field positions: */
#define GPIO_ALTFUNCCLR_PIN0_Pos              0                      /*!< Alternative function disable for pin 0 */
#define GPIO_ALTFUNCCLR_PIN1_Pos              1                      /*!< Alternative function disable for pin 1 */
#define GPIO_ALTFUNCCLR_PIN2_Pos              2                      /*!< Alternative function disable for pin 2 */
#define GPIO_ALTFUNCCLR_PIN3_Pos              3                      /*!< Alternative function disable for pin 3 */
#define GPIO_ALTFUNCCLR_PIN4_Pos              4                      /*!< Alternative function disable for pin 4 */
#define GPIO_ALTFUNCCLR_PIN5_Pos              5                      /*!< Alternative function disable for pin 5 */
#define GPIO_ALTFUNCCLR_PIN6_Pos              6                      /*!< Alternative function disable for pin 6 */
#define GPIO_ALTFUNCCLR_PIN7_Pos              7                      /*!< Alternative function disable for pin 7 */
#define GPIO_ALTFUNCCLR_PIN8_Pos              8                      /*!< Alternative function disable for pin 8 */
#define GPIO_ALTFUNCCLR_PIN9_Pos              9                      /*!< Alternative function disable for pin 9 */
#define GPIO_ALTFUNCCLR_PIN10_Pos             10                     /*!< Alternative function disable for pin 10 */
#define GPIO_ALTFUNCCLR_PIN11_Pos             11                     /*!< Alternative function disable for pin 11 */
#define GPIO_ALTFUNCCLR_PIN12_Pos             12                     /*!< Alternative function disable for pin 12 */
#define GPIO_ALTFUNCCLR_PIN13_Pos             13                     /*!< Alternative function disable for pin 13 */
#define GPIO_ALTFUNCCLR_PIN14_Pos             14                     /*!< Alternative function disable for pin 14 */
#define GPIO_ALTFUNCCLR_PIN15_Pos             15                     /*!< Alternative function disable for pin 15 */

/* Bit field masks: */
#define GPIO_ALTFUNCCLR_PIN0_Msk              0x00000001             /*!< Alternative function disable for pin 0 */
#define GPIO_ALTFUNCCLR_PIN1_Msk              0x00000002             /*!< Alternative function disable for pin 1 */
#define GPIO_ALTFUNCCLR_PIN2_Msk              0x00000004             /*!< Alternative function disable for pin 2 */
#define GPIO_ALTFUNCCLR_PIN3_Msk              0x00000008             /*!< Alternative function disable for pin 3 */
#define GPIO_ALTFUNCCLR_PIN4_Msk              0x00000010             /*!< Alternative function disable for pin 4 */
#define GPIO_ALTFUNCCLR_PIN5_Msk              0x00000020             /*!< Alternative function disable for pin 5 */
#define GPIO_ALTFUNCCLR_PIN6_Msk              0x00000040             /*!< Alternative function disable for pin 6 */
#define GPIO_ALTFUNCCLR_PIN7_Msk              0x00000080             /*!< Alternative function disable for pin 7 */
#define GPIO_ALTFUNCCLR_PIN8_Msk              0x00000100             /*!< Alternative function disable for pin 8 */
#define GPIO_ALTFUNCCLR_PIN9_Msk              0x00000200             /*!< Alternative function disable for pin 9 */
#define GPIO_ALTFUNCCLR_PIN10_Msk             0x00000400             /*!< Alternative function disable for pin 10 */
#define GPIO_ALTFUNCCLR_PIN11_Msk             0x00000800             /*!< Alternative function disable for pin 11 */
#define GPIO_ALTFUNCCLR_PIN12_Msk             0x00001000             /*!< Alternative function disable for pin 12 */
#define GPIO_ALTFUNCCLR_PIN13_Msk             0x00002000             /*!< Alternative function disable for pin 13 */
#define GPIO_ALTFUNCCLR_PIN14_Msk             0x00004000             /*!< Alternative function disable for pin 14 */
#define GPIO_ALTFUNCCLR_PIN15_Msk             0x00008000             /*!< Alternative function disable for pin 15 */

/*--  SYNCSET: Additional double flip-flop syncronization enable register -------------------------------------*/
typedef struct {
  uint32_t PIN0                   :1;                                /*!< Additional double flip-flop syncronization buffer enable for pin 0 */
  uint32_t PIN1                   :1;                                /*!< Additional double flip-flop syncronization buffer enable for pin 1 */
  uint32_t PIN2                   :1;                                /*!< Additional double flip-flop syncronization buffer enable for pin 2 */
  uint32_t PIN3                   :1;                                /*!< Additional double flip-flop syncronization buffer enable for pin 3 */
  uint32_t PIN4                   :1;                                /*!< Additional double flip-flop syncronization buffer enable for pin 4 */
  uint32_t PIN5                   :1;                                /*!< Additional double flip-flop syncronization buffer enable for pin 5 */
  uint32_t PIN6                   :1;                                /*!< Additional double flip-flop syncronization buffer enable for pin 6 */
  uint32_t PIN7                   :1;                                /*!< Additional double flip-flop syncronization buffer enable for pin 7 */
  uint32_t PIN8                   :1;                                /*!< Additional double flip-flop syncronization buffer enable for pin 8 */
  uint32_t PIN9                   :1;                                /*!< Additional double flip-flop syncronization buffer enable for pin 9 */
  uint32_t PIN10                  :1;                                /*!< Additional double flip-flop syncronization buffer enable for pin 10 */
  uint32_t PIN11                  :1;                                /*!< Additional double flip-flop syncronization buffer enable for pin 11 */
  uint32_t PIN12                  :1;                                /*!< Additional double flip-flop syncronization buffer enable for pin 12 */
  uint32_t PIN13                  :1;                                /*!< Additional double flip-flop syncronization buffer enable for pin 13 */
  uint32_t PIN14                  :1;                                /*!< Additional double flip-flop syncronization buffer enable for pin 14 */
  uint32_t PIN15                  :1;                                /*!< Additional double flip-flop syncronization buffer enable for pin 15 */
} _GPIO_SYNCSET_bits;

/* Bit field positions: */
#define GPIO_SYNCSET_PIN0_Pos                 0                      /*!< Additional double flip-flop syncronization buffer enable for pin 0 */
#define GPIO_SYNCSET_PIN1_Pos                 1                      /*!< Additional double flip-flop syncronization buffer enable for pin 1 */
#define GPIO_SYNCSET_PIN2_Pos                 2                      /*!< Additional double flip-flop syncronization buffer enable for pin 2 */
#define GPIO_SYNCSET_PIN3_Pos                 3                      /*!< Additional double flip-flop syncronization buffer enable for pin 3 */
#define GPIO_SYNCSET_PIN4_Pos                 4                      /*!< Additional double flip-flop syncronization buffer enable for pin 4 */
#define GPIO_SYNCSET_PIN5_Pos                 5                      /*!< Additional double flip-flop syncronization buffer enable for pin 5 */
#define GPIO_SYNCSET_PIN6_Pos                 6                      /*!< Additional double flip-flop syncronization buffer enable for pin 6 */
#define GPIO_SYNCSET_PIN7_Pos                 7                      /*!< Additional double flip-flop syncronization buffer enable for pin 7 */
#define GPIO_SYNCSET_PIN8_Pos                 8                      /*!< Additional double flip-flop syncronization buffer enable for pin 8 */
#define GPIO_SYNCSET_PIN9_Pos                 9                      /*!< Additional double flip-flop syncronization buffer enable for pin 9 */
#define GPIO_SYNCSET_PIN10_Pos                10                     /*!< Additional double flip-flop syncronization buffer enable for pin 10 */
#define GPIO_SYNCSET_PIN11_Pos                11                     /*!< Additional double flip-flop syncronization buffer enable for pin 11 */
#define GPIO_SYNCSET_PIN12_Pos                12                     /*!< Additional double flip-flop syncronization buffer enable for pin 12 */
#define GPIO_SYNCSET_PIN13_Pos                13                     /*!< Additional double flip-flop syncronization buffer enable for pin 13 */
#define GPIO_SYNCSET_PIN14_Pos                14                     /*!< Additional double flip-flop syncronization buffer enable for pin 14 */
#define GPIO_SYNCSET_PIN15_Pos                15                     /*!< Additional double flip-flop syncronization buffer enable for pin 15 */

/* Bit field masks: */
#define GPIO_SYNCSET_PIN0_Msk                 0x00000001             /*!< Additional double flip-flop syncronization buffer enable for pin 0 */
#define GPIO_SYNCSET_PIN1_Msk                 0x00000002             /*!< Additional double flip-flop syncronization buffer enable for pin 1 */
#define GPIO_SYNCSET_PIN2_Msk                 0x00000004             /*!< Additional double flip-flop syncronization buffer enable for pin 2 */
#define GPIO_SYNCSET_PIN3_Msk                 0x00000008             /*!< Additional double flip-flop syncronization buffer enable for pin 3 */
#define GPIO_SYNCSET_PIN4_Msk                 0x00000010             /*!< Additional double flip-flop syncronization buffer enable for pin 4 */
#define GPIO_SYNCSET_PIN5_Msk                 0x00000020             /*!< Additional double flip-flop syncronization buffer enable for pin 5 */
#define GPIO_SYNCSET_PIN6_Msk                 0x00000040             /*!< Additional double flip-flop syncronization buffer enable for pin 6 */
#define GPIO_SYNCSET_PIN7_Msk                 0x00000080             /*!< Additional double flip-flop syncronization buffer enable for pin 7 */
#define GPIO_SYNCSET_PIN8_Msk                 0x00000100             /*!< Additional double flip-flop syncronization buffer enable for pin 8 */
#define GPIO_SYNCSET_PIN9_Msk                 0x00000200             /*!< Additional double flip-flop syncronization buffer enable for pin 9 */
#define GPIO_SYNCSET_PIN10_Msk                0x00000400             /*!< Additional double flip-flop syncronization buffer enable for pin 10 */
#define GPIO_SYNCSET_PIN11_Msk                0x00000800             /*!< Additional double flip-flop syncronization buffer enable for pin 11 */
#define GPIO_SYNCSET_PIN12_Msk                0x00001000             /*!< Additional double flip-flop syncronization buffer enable for pin 12 */
#define GPIO_SYNCSET_PIN13_Msk                0x00002000             /*!< Additional double flip-flop syncronization buffer enable for pin 13 */
#define GPIO_SYNCSET_PIN14_Msk                0x00004000             /*!< Additional double flip-flop syncronization buffer enable for pin 14 */
#define GPIO_SYNCSET_PIN15_Msk                0x00008000             /*!< Additional double flip-flop syncronization buffer enable for pin 15 */

/*--  SYNCCLR: Additional double flip-flop syncronization disable register ------------------------------------*/
typedef struct {
  uint32_t PIN0                   :1;                                /*!< Additional double flip-flop syncronization disable for pin 0 */
  uint32_t PIN1                   :1;                                /*!< Additional double flip-flop syncronization disable for pin 1 */
  uint32_t PIN2                   :1;                                /*!< Additional double flip-flop syncronization disable for pin 2 */
  uint32_t PIN3                   :1;                                /*!< Additional double flip-flop syncronization disable for pin 3 */
  uint32_t PIN4                   :1;                                /*!< Additional double flip-flop syncronization disable for pin 4 */
  uint32_t PIN5                   :1;                                /*!< Additional double flip-flop syncronization disable for pin 5 */
  uint32_t PIN6                   :1;                                /*!< Additional double flip-flop syncronization disable for pin 6 */
  uint32_t PIN7                   :1;                                /*!< Additional double flip-flop syncronization disable for pin 7 */
  uint32_t PIN8                   :1;                                /*!< Additional double flip-flop syncronization disable for pin 8 */
  uint32_t PIN9                   :1;                                /*!< Additional double flip-flop syncronization disable for pin 9 */
  uint32_t PIN10                  :1;                                /*!< Additional double flip-flop syncronization disable for pin 10 */
  uint32_t PIN11                  :1;                                /*!< Additional double flip-flop syncronization disable for pin 11 */
  uint32_t PIN12                  :1;                                /*!< Additional double flip-flop syncronization disable for pin 12 */
  uint32_t PIN13                  :1;                                /*!< Additional double flip-flop syncronization disable for pin 13 */
  uint32_t PIN14                  :1;                                /*!< Additional double flip-flop syncronization disable for pin 14 */
  uint32_t PIN15                  :1;                                /*!< Additional double flip-flop syncronization disable for pin 15 */
} _GPIO_SYNCCLR_bits;

/* Bit field positions: */
#define GPIO_SYNCCLR_PIN0_Pos                 0                      /*!< Additional double flip-flop syncronization disable for pin 0 */
#define GPIO_SYNCCLR_PIN1_Pos                 1                      /*!< Additional double flip-flop syncronization disable for pin 1 */
#define GPIO_SYNCCLR_PIN2_Pos                 2                      /*!< Additional double flip-flop syncronization disable for pin 2 */
#define GPIO_SYNCCLR_PIN3_Pos                 3                      /*!< Additional double flip-flop syncronization disable for pin 3 */
#define GPIO_SYNCCLR_PIN4_Pos                 4                      /*!< Additional double flip-flop syncronization disable for pin 4 */
#define GPIO_SYNCCLR_PIN5_Pos                 5                      /*!< Additional double flip-flop syncronization disable for pin 5 */
#define GPIO_SYNCCLR_PIN6_Pos                 6                      /*!< Additional double flip-flop syncronization disable for pin 6 */
#define GPIO_SYNCCLR_PIN7_Pos                 7                      /*!< Additional double flip-flop syncronization disable for pin 7 */
#define GPIO_SYNCCLR_PIN8_Pos                 8                      /*!< Additional double flip-flop syncronization disable for pin 8 */
#define GPIO_SYNCCLR_PIN9_Pos                 9                      /*!< Additional double flip-flop syncronization disable for pin 9 */
#define GPIO_SYNCCLR_PIN10_Pos                10                     /*!< Additional double flip-flop syncronization disable for pin 10 */
#define GPIO_SYNCCLR_PIN11_Pos                11                     /*!< Additional double flip-flop syncronization disable for pin 11 */
#define GPIO_SYNCCLR_PIN12_Pos                12                     /*!< Additional double flip-flop syncronization disable for pin 12 */
#define GPIO_SYNCCLR_PIN13_Pos                13                     /*!< Additional double flip-flop syncronization disable for pin 13 */
#define GPIO_SYNCCLR_PIN14_Pos                14                     /*!< Additional double flip-flop syncronization disable for pin 14 */
#define GPIO_SYNCCLR_PIN15_Pos                15                     /*!< Additional double flip-flop syncronization disable for pin 15 */

/* Bit field masks: */
#define GPIO_SYNCCLR_PIN0_Msk                 0x00000001             /*!< Additional double flip-flop syncronization disable for pin 0 */
#define GPIO_SYNCCLR_PIN1_Msk                 0x00000002             /*!< Additional double flip-flop syncronization disable for pin 1 */
#define GPIO_SYNCCLR_PIN2_Msk                 0x00000004             /*!< Additional double flip-flop syncronization disable for pin 2 */
#define GPIO_SYNCCLR_PIN3_Msk                 0x00000008             /*!< Additional double flip-flop syncronization disable for pin 3 */
#define GPIO_SYNCCLR_PIN4_Msk                 0x00000010             /*!< Additional double flip-flop syncronization disable for pin 4 */
#define GPIO_SYNCCLR_PIN5_Msk                 0x00000020             /*!< Additional double flip-flop syncronization disable for pin 5 */
#define GPIO_SYNCCLR_PIN6_Msk                 0x00000040             /*!< Additional double flip-flop syncronization disable for pin 6 */
#define GPIO_SYNCCLR_PIN7_Msk                 0x00000080             /*!< Additional double flip-flop syncronization disable for pin 7 */
#define GPIO_SYNCCLR_PIN8_Msk                 0x00000100             /*!< Additional double flip-flop syncronization disable for pin 8 */
#define GPIO_SYNCCLR_PIN9_Msk                 0x00000200             /*!< Additional double flip-flop syncronization disable for pin 9 */
#define GPIO_SYNCCLR_PIN10_Msk                0x00000400             /*!< Additional double flip-flop syncronization disable for pin 10 */
#define GPIO_SYNCCLR_PIN11_Msk                0x00000800             /*!< Additional double flip-flop syncronization disable for pin 11 */
#define GPIO_SYNCCLR_PIN12_Msk                0x00001000             /*!< Additional double flip-flop syncronization disable for pin 12 */
#define GPIO_SYNCCLR_PIN13_Msk                0x00002000             /*!< Additional double flip-flop syncronization disable for pin 13 */
#define GPIO_SYNCCLR_PIN14_Msk                0x00004000             /*!< Additional double flip-flop syncronization disable for pin 14 */
#define GPIO_SYNCCLR_PIN15_Msk                0x00008000             /*!< Additional double flip-flop syncronization disable for pin 15 */

/*--  QUALSET: Qualifier enable register ----------------------------------------------------------------------*/
typedef struct {
  uint32_t PIN0                   :1;                                /*!< Qualifier enable for pin 0 */
  uint32_t PIN1                   :1;                                /*!< Qualifier enable for pin 1 */
  uint32_t PIN2                   :1;                                /*!< Qualifier enable for pin 2 */
  uint32_t PIN3                   :1;                                /*!< Qualifier enable for pin 3 */
  uint32_t PIN4                   :1;                                /*!< Qualifier enable for pin 4 */
  uint32_t PIN5                   :1;                                /*!< Qualifier enable for pin 5 */
  uint32_t PIN6                   :1;                                /*!< Qualifier enable for pin 6 */
  uint32_t PIN7                   :1;                                /*!< Qualifier enable for pin 7 */
  uint32_t PIN8                   :1;                                /*!< Qualifier enable for pin 8 */
  uint32_t PIN9                   :1;                                /*!< Qualifier enable for pin 9 */
  uint32_t PIN10                  :1;                                /*!< Qualifier enable for pin 10 */
  uint32_t PIN11                  :1;                                /*!< Qualifier enable for pin 11 */
  uint32_t PIN12                  :1;                                /*!< Qualifier enable for pin 12 */
  uint32_t PIN13                  :1;                                /*!< Qualifier enable for pin 13 */
  uint32_t PIN14                  :1;                                /*!< Qualifier enable for pin 14 */
  uint32_t PIN15                  :1;                                /*!< Qualifier enable for pin 15 */
} _GPIO_QUALSET_bits;

/* Bit field positions: */
#define GPIO_QUALSET_PIN0_Pos                 0                      /*!< Qualifier enable for pin 0 */
#define GPIO_QUALSET_PIN1_Pos                 1                      /*!< Qualifier enable for pin 1 */
#define GPIO_QUALSET_PIN2_Pos                 2                      /*!< Qualifier enable for pin 2 */
#define GPIO_QUALSET_PIN3_Pos                 3                      /*!< Qualifier enable for pin 3 */
#define GPIO_QUALSET_PIN4_Pos                 4                      /*!< Qualifier enable for pin 4 */
#define GPIO_QUALSET_PIN5_Pos                 5                      /*!< Qualifier enable for pin 5 */
#define GPIO_QUALSET_PIN6_Pos                 6                      /*!< Qualifier enable for pin 6 */
#define GPIO_QUALSET_PIN7_Pos                 7                      /*!< Qualifier enable for pin 7 */
#define GPIO_QUALSET_PIN8_Pos                 8                      /*!< Qualifier enable for pin 8 */
#define GPIO_QUALSET_PIN9_Pos                 9                      /*!< Qualifier enable for pin 9 */
#define GPIO_QUALSET_PIN10_Pos                10                     /*!< Qualifier enable for pin 10 */
#define GPIO_QUALSET_PIN11_Pos                11                     /*!< Qualifier enable for pin 11 */
#define GPIO_QUALSET_PIN12_Pos                12                     /*!< Qualifier enable for pin 12 */
#define GPIO_QUALSET_PIN13_Pos                13                     /*!< Qualifier enable for pin 13 */
#define GPIO_QUALSET_PIN14_Pos                14                     /*!< Qualifier enable for pin 14 */
#define GPIO_QUALSET_PIN15_Pos                15                     /*!< Qualifier enable for pin 15 */

/* Bit field masks: */
#define GPIO_QUALSET_PIN0_Msk                 0x00000001             /*!< Qualifier enable for pin 0 */
#define GPIO_QUALSET_PIN1_Msk                 0x00000002             /*!< Qualifier enable for pin 1 */
#define GPIO_QUALSET_PIN2_Msk                 0x00000004             /*!< Qualifier enable for pin 2 */
#define GPIO_QUALSET_PIN3_Msk                 0x00000008             /*!< Qualifier enable for pin 3 */
#define GPIO_QUALSET_PIN4_Msk                 0x00000010             /*!< Qualifier enable for pin 4 */
#define GPIO_QUALSET_PIN5_Msk                 0x00000020             /*!< Qualifier enable for pin 5 */
#define GPIO_QUALSET_PIN6_Msk                 0x00000040             /*!< Qualifier enable for pin 6 */
#define GPIO_QUALSET_PIN7_Msk                 0x00000080             /*!< Qualifier enable for pin 7 */
#define GPIO_QUALSET_PIN8_Msk                 0x00000100             /*!< Qualifier enable for pin 8 */
#define GPIO_QUALSET_PIN9_Msk                 0x00000200             /*!< Qualifier enable for pin 9 */
#define GPIO_QUALSET_PIN10_Msk                0x00000400             /*!< Qualifier enable for pin 10 */
#define GPIO_QUALSET_PIN11_Msk                0x00000800             /*!< Qualifier enable for pin 11 */
#define GPIO_QUALSET_PIN12_Msk                0x00001000             /*!< Qualifier enable for pin 12 */
#define GPIO_QUALSET_PIN13_Msk                0x00002000             /*!< Qualifier enable for pin 13 */
#define GPIO_QUALSET_PIN14_Msk                0x00004000             /*!< Qualifier enable for pin 14 */
#define GPIO_QUALSET_PIN15_Msk                0x00008000             /*!< Qualifier enable for pin 15 */

/*--  QUALCLR: Qualifier disable register ---------------------------------------------------------------------*/
typedef struct {
  uint32_t PIN0                   :1;                                /*!< Qualifier disable for pin 0 */
  uint32_t PIN1                   :1;                                /*!< Qualifier disable for pin 1 */
  uint32_t PIN2                   :1;                                /*!< Qualifier disable for pin 2 */
  uint32_t PIN3                   :1;                                /*!< Qualifier disable for pin 3 */
  uint32_t PIN4                   :1;                                /*!< Qualifier disable for pin 4 */
  uint32_t PIN5                   :1;                                /*!< Qualifier disable for pin 5 */
  uint32_t PIN6                   :1;                                /*!< Qualifier disable for pin 6 */
  uint32_t PIN7                   :1;                                /*!< Qualifier disable for pin 7 */
  uint32_t PIN8                   :1;                                /*!< Qualifier disable for pin 8 */
  uint32_t PIN9                   :1;                                /*!< Qualifier disable for pin 9 */
  uint32_t PIN10                  :1;                                /*!< Qualifier disable for pin 10 */
  uint32_t PIN11                  :1;                                /*!< Qualifier disable for pin 11 */
  uint32_t PIN12                  :1;                                /*!< Qualifier disable for pin 12 */
  uint32_t PIN13                  :1;                                /*!< Qualifier disable for pin 13 */
  uint32_t PIN14                  :1;                                /*!< Qualifier disable for pin 14 */
  uint32_t PIN15                  :1;                                /*!< Qualifier disable for pin 15 */
} _GPIO_QUALCLR_bits;

/* Bit field positions: */
#define GPIO_QUALCLR_PIN0_Pos                 0                      /*!< Qualifier disable for pin 0 */
#define GPIO_QUALCLR_PIN1_Pos                 1                      /*!< Qualifier disable for pin 1 */
#define GPIO_QUALCLR_PIN2_Pos                 2                      /*!< Qualifier disable for pin 2 */
#define GPIO_QUALCLR_PIN3_Pos                 3                      /*!< Qualifier disable for pin 3 */
#define GPIO_QUALCLR_PIN4_Pos                 4                      /*!< Qualifier disable for pin 4 */
#define GPIO_QUALCLR_PIN5_Pos                 5                      /*!< Qualifier disable for pin 5 */
#define GPIO_QUALCLR_PIN6_Pos                 6                      /*!< Qualifier disable for pin 6 */
#define GPIO_QUALCLR_PIN7_Pos                 7                      /*!< Qualifier disable for pin 7 */
#define GPIO_QUALCLR_PIN8_Pos                 8                      /*!< Qualifier disable for pin 8 */
#define GPIO_QUALCLR_PIN9_Pos                 9                      /*!< Qualifier disable for pin 9 */
#define GPIO_QUALCLR_PIN10_Pos                10                     /*!< Qualifier disable for pin 10 */
#define GPIO_QUALCLR_PIN11_Pos                11                     /*!< Qualifier disable for pin 11 */
#define GPIO_QUALCLR_PIN12_Pos                12                     /*!< Qualifier disable for pin 12 */
#define GPIO_QUALCLR_PIN13_Pos                13                     /*!< Qualifier disable for pin 13 */
#define GPIO_QUALCLR_PIN14_Pos                14                     /*!< Qualifier disable for pin 14 */
#define GPIO_QUALCLR_PIN15_Pos                15                     /*!< Qualifier disable for pin 15 */

/* Bit field masks: */
#define GPIO_QUALCLR_PIN0_Msk                 0x00000001             /*!< Qualifier disable for pin 0 */
#define GPIO_QUALCLR_PIN1_Msk                 0x00000002             /*!< Qualifier disable for pin 1 */
#define GPIO_QUALCLR_PIN2_Msk                 0x00000004             /*!< Qualifier disable for pin 2 */
#define GPIO_QUALCLR_PIN3_Msk                 0x00000008             /*!< Qualifier disable for pin 3 */
#define GPIO_QUALCLR_PIN4_Msk                 0x00000010             /*!< Qualifier disable for pin 4 */
#define GPIO_QUALCLR_PIN5_Msk                 0x00000020             /*!< Qualifier disable for pin 5 */
#define GPIO_QUALCLR_PIN6_Msk                 0x00000040             /*!< Qualifier disable for pin 6 */
#define GPIO_QUALCLR_PIN7_Msk                 0x00000080             /*!< Qualifier disable for pin 7 */
#define GPIO_QUALCLR_PIN8_Msk                 0x00000100             /*!< Qualifier disable for pin 8 */
#define GPIO_QUALCLR_PIN9_Msk                 0x00000200             /*!< Qualifier disable for pin 9 */
#define GPIO_QUALCLR_PIN10_Msk                0x00000400             /*!< Qualifier disable for pin 10 */
#define GPIO_QUALCLR_PIN11_Msk                0x00000800             /*!< Qualifier disable for pin 11 */
#define GPIO_QUALCLR_PIN12_Msk                0x00001000             /*!< Qualifier disable for pin 12 */
#define GPIO_QUALCLR_PIN13_Msk                0x00002000             /*!< Qualifier disable for pin 13 */
#define GPIO_QUALCLR_PIN14_Msk                0x00004000             /*!< Qualifier disable for pin 14 */
#define GPIO_QUALCLR_PIN15_Msk                0x00008000             /*!< Qualifier disable for pin 15 */

/*--  QUALMODESET: Qualifier mode set register ----------------------------------------------------------------*/
typedef struct {
  uint32_t PIN0                   :1;                                /*!< Qualifier mode set for pin 0 */
  uint32_t PIN1                   :1;                                /*!< Qualifier mode set for pin 1 */
  uint32_t PIN2                   :1;                                /*!< Qualifier mode set for pin 2 */
  uint32_t PIN3                   :1;                                /*!< Qualifier mode set for pin 3 */
  uint32_t PIN4                   :1;                                /*!< Qualifier mode set for pin 4 */
  uint32_t PIN5                   :1;                                /*!< Qualifier mode set for pin 5 */
  uint32_t PIN6                   :1;                                /*!< Qualifier mode set for pin 6 */
  uint32_t PIN7                   :1;                                /*!< Qualifier mode set for pin 7 */
  uint32_t PIN8                   :1;                                /*!< Qualifier mode set for pin 8 */
  uint32_t PIN9                   :1;                                /*!< Qualifier mode set for pin 9 */
  uint32_t PIN10                  :1;                                /*!< Qualifier mode set for pin 10 */
  uint32_t PIN11                  :1;                                /*!< Qualifier mode set for pin 11 */
  uint32_t PIN12                  :1;                                /*!< Qualifier mode set for pin 12 */
  uint32_t PIN13                  :1;                                /*!< Qualifier mode set for pin 13 */
  uint32_t PIN14                  :1;                                /*!< Qualifier mode set for pin 14 */
  uint32_t PIN15                  :1;                                /*!< Qualifier mode set for pin 15 */
} _GPIO_QUALMODESET_bits;

/* Bit field positions: */
#define GPIO_QUALMODESET_PIN0_Pos             0                      /*!< Qualifier mode set for pin 0 */
#define GPIO_QUALMODESET_PIN1_Pos             1                      /*!< Qualifier mode set for pin 1 */
#define GPIO_QUALMODESET_PIN2_Pos             2                      /*!< Qualifier mode set for pin 2 */
#define GPIO_QUALMODESET_PIN3_Pos             3                      /*!< Qualifier mode set for pin 3 */
#define GPIO_QUALMODESET_PIN4_Pos             4                      /*!< Qualifier mode set for pin 4 */
#define GPIO_QUALMODESET_PIN5_Pos             5                      /*!< Qualifier mode set for pin 5 */
#define GPIO_QUALMODESET_PIN6_Pos             6                      /*!< Qualifier mode set for pin 6 */
#define GPIO_QUALMODESET_PIN7_Pos             7                      /*!< Qualifier mode set for pin 7 */
#define GPIO_QUALMODESET_PIN8_Pos             8                      /*!< Qualifier mode set for pin 8 */
#define GPIO_QUALMODESET_PIN9_Pos             9                      /*!< Qualifier mode set for pin 9 */
#define GPIO_QUALMODESET_PIN10_Pos            10                     /*!< Qualifier mode set for pin 10 */
#define GPIO_QUALMODESET_PIN11_Pos            11                     /*!< Qualifier mode set for pin 11 */
#define GPIO_QUALMODESET_PIN12_Pos            12                     /*!< Qualifier mode set for pin 12 */
#define GPIO_QUALMODESET_PIN13_Pos            13                     /*!< Qualifier mode set for pin 13 */
#define GPIO_QUALMODESET_PIN14_Pos            14                     /*!< Qualifier mode set for pin 14 */
#define GPIO_QUALMODESET_PIN15_Pos            15                     /*!< Qualifier mode set for pin 15 */

/* Bit field masks: */
#define GPIO_QUALMODESET_PIN0_Msk             0x00000001             /*!< Qualifier mode set for pin 0 */
#define GPIO_QUALMODESET_PIN1_Msk             0x00000002             /*!< Qualifier mode set for pin 1 */
#define GPIO_QUALMODESET_PIN2_Msk             0x00000004             /*!< Qualifier mode set for pin 2 */
#define GPIO_QUALMODESET_PIN3_Msk             0x00000008             /*!< Qualifier mode set for pin 3 */
#define GPIO_QUALMODESET_PIN4_Msk             0x00000010             /*!< Qualifier mode set for pin 4 */
#define GPIO_QUALMODESET_PIN5_Msk             0x00000020             /*!< Qualifier mode set for pin 5 */
#define GPIO_QUALMODESET_PIN6_Msk             0x00000040             /*!< Qualifier mode set for pin 6 */
#define GPIO_QUALMODESET_PIN7_Msk             0x00000080             /*!< Qualifier mode set for pin 7 */
#define GPIO_QUALMODESET_PIN8_Msk             0x00000100             /*!< Qualifier mode set for pin 8 */
#define GPIO_QUALMODESET_PIN9_Msk             0x00000200             /*!< Qualifier mode set for pin 9 */
#define GPIO_QUALMODESET_PIN10_Msk            0x00000400             /*!< Qualifier mode set for pin 10 */
#define GPIO_QUALMODESET_PIN11_Msk            0x00000800             /*!< Qualifier mode set for pin 11 */
#define GPIO_QUALMODESET_PIN12_Msk            0x00001000             /*!< Qualifier mode set for pin 12 */
#define GPIO_QUALMODESET_PIN13_Msk            0x00002000             /*!< Qualifier mode set for pin 13 */
#define GPIO_QUALMODESET_PIN14_Msk            0x00004000             /*!< Qualifier mode set for pin 14 */
#define GPIO_QUALMODESET_PIN15_Msk            0x00008000             /*!< Qualifier mode set for pin 15 */

/*--  QUALMODECLR: Qualifier mode clear register --------------------------------------------------------------*/
typedef struct {
  uint32_t PIN0                   :1;                                /*!< Qualifier mode clear for pin 0 */
  uint32_t PIN1                   :1;                                /*!< Qualifier mode clear for pin 1 */
  uint32_t PIN2                   :1;                                /*!< Qualifier mode clear for pin 2 */
  uint32_t PIN3                   :1;                                /*!< Qualifier mode clear for pin 3 */
  uint32_t PIN4                   :1;                                /*!< Qualifier mode clear for pin 4 */
  uint32_t PIN5                   :1;                                /*!< Qualifier mode clear for pin 5 */
  uint32_t PIN6                   :1;                                /*!< Qualifier mode clear for pin 6 */
  uint32_t PIN7                   :1;                                /*!< Qualifier mode clear for pin 7 */
  uint32_t PIN8                   :1;                                /*!< Qualifier mode clear for pin 8 */
  uint32_t PIN9                   :1;                                /*!< Qualifier mode clear for pin 9 */
  uint32_t PIN10                  :1;                                /*!< Qualifier mode clear for pin 10 */
  uint32_t PIN11                  :1;                                /*!< Qualifier mode clear for pin 11 */
  uint32_t PIN12                  :1;                                /*!< Qualifier mode clear for pin 12 */
  uint32_t PIN13                  :1;                                /*!< Qualifier mode clear for pin 13 */
  uint32_t PIN14                  :1;                                /*!< Qualifier mode clear for pin 14 */
  uint32_t PIN15                  :1;                                /*!< Qualifier mode clear for pin 15 */
} _GPIO_QUALMODECLR_bits;

/* Bit field positions: */
#define GPIO_QUALMODECLR_PIN0_Pos             0                      /*!< Qualifier mode clear for pin 0 */
#define GPIO_QUALMODECLR_PIN1_Pos             1                      /*!< Qualifier mode clear for pin 1 */
#define GPIO_QUALMODECLR_PIN2_Pos             2                      /*!< Qualifier mode clear for pin 2 */
#define GPIO_QUALMODECLR_PIN3_Pos             3                      /*!< Qualifier mode clear for pin 3 */
#define GPIO_QUALMODECLR_PIN4_Pos             4                      /*!< Qualifier mode clear for pin 4 */
#define GPIO_QUALMODECLR_PIN5_Pos             5                      /*!< Qualifier mode clear for pin 5 */
#define GPIO_QUALMODECLR_PIN6_Pos             6                      /*!< Qualifier mode clear for pin 6 */
#define GPIO_QUALMODECLR_PIN7_Pos             7                      /*!< Qualifier mode clear for pin 7 */
#define GPIO_QUALMODECLR_PIN8_Pos             8                      /*!< Qualifier mode clear for pin 8 */
#define GPIO_QUALMODECLR_PIN9_Pos             9                      /*!< Qualifier mode clear for pin 9 */
#define GPIO_QUALMODECLR_PIN10_Pos            10                     /*!< Qualifier mode clear for pin 10 */
#define GPIO_QUALMODECLR_PIN11_Pos            11                     /*!< Qualifier mode clear for pin 11 */
#define GPIO_QUALMODECLR_PIN12_Pos            12                     /*!< Qualifier mode clear for pin 12 */
#define GPIO_QUALMODECLR_PIN13_Pos            13                     /*!< Qualifier mode clear for pin 13 */
#define GPIO_QUALMODECLR_PIN14_Pos            14                     /*!< Qualifier mode clear for pin 14 */
#define GPIO_QUALMODECLR_PIN15_Pos            15                     /*!< Qualifier mode clear for pin 15 */

/* Bit field masks: */
#define GPIO_QUALMODECLR_PIN0_Msk             0x00000001             /*!< Qualifier mode clear for pin 0 */
#define GPIO_QUALMODECLR_PIN1_Msk             0x00000002             /*!< Qualifier mode clear for pin 1 */
#define GPIO_QUALMODECLR_PIN2_Msk             0x00000004             /*!< Qualifier mode clear for pin 2 */
#define GPIO_QUALMODECLR_PIN3_Msk             0x00000008             /*!< Qualifier mode clear for pin 3 */
#define GPIO_QUALMODECLR_PIN4_Msk             0x00000010             /*!< Qualifier mode clear for pin 4 */
#define GPIO_QUALMODECLR_PIN5_Msk             0x00000020             /*!< Qualifier mode clear for pin 5 */
#define GPIO_QUALMODECLR_PIN6_Msk             0x00000040             /*!< Qualifier mode clear for pin 6 */
#define GPIO_QUALMODECLR_PIN7_Msk             0x00000080             /*!< Qualifier mode clear for pin 7 */
#define GPIO_QUALMODECLR_PIN8_Msk             0x00000100             /*!< Qualifier mode clear for pin 8 */
#define GPIO_QUALMODECLR_PIN9_Msk             0x00000200             /*!< Qualifier mode clear for pin 9 */
#define GPIO_QUALMODECLR_PIN10_Msk            0x00000400             /*!< Qualifier mode clear for pin 10 */
#define GPIO_QUALMODECLR_PIN11_Msk            0x00000800             /*!< Qualifier mode clear for pin 11 */
#define GPIO_QUALMODECLR_PIN12_Msk            0x00001000             /*!< Qualifier mode clear for pin 12 */
#define GPIO_QUALMODECLR_PIN13_Msk            0x00002000             /*!< Qualifier mode clear for pin 13 */
#define GPIO_QUALMODECLR_PIN14_Msk            0x00004000             /*!< Qualifier mode clear for pin 14 */
#define GPIO_QUALMODECLR_PIN15_Msk            0x00008000             /*!< Qualifier mode clear for pin 15 */

/*--  QUALSAMPLE: Qualifier sample period register ------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :8;                                /*!< Qualifier sample period */
} _GPIO_QUALSAMPLE_bits;

/* Bit field positions: */
#define GPIO_QUALSAMPLE_VAL_Pos               0                      /*!< Qualifier sample period */

/* Bit field masks: */
#define GPIO_QUALSAMPLE_VAL_Msk               0x000000FF             /*!< Qualifier sample period */

/*--  INTENSET: Interrupt enable register ---------------------------------------------------------------------*/
typedef struct {
  uint32_t PIN0                   :1;                                /*!< Interrupt enable for pin 0 */
  uint32_t PIN1                   :1;                                /*!< Interrupt enable for pin 1 */
  uint32_t PIN2                   :1;                                /*!< Interrupt enable for pin 2 */
  uint32_t PIN3                   :1;                                /*!< Interrupt enable for pin 3 */
  uint32_t PIN4                   :1;                                /*!< Interrupt enable for pin 4 */
  uint32_t PIN5                   :1;                                /*!< Interrupt enable for pin 5 */
  uint32_t PIN6                   :1;                                /*!< Interrupt enable for pin 6 */
  uint32_t PIN7                   :1;                                /*!< Interrupt enable for pin 7 */
  uint32_t PIN8                   :1;                                /*!< Interrupt enable for pin 8 */
  uint32_t PIN9                   :1;                                /*!< Interrupt enable for pin 9 */
  uint32_t PIN10                  :1;                                /*!< Interrupt enable for pin 10 */
  uint32_t PIN11                  :1;                                /*!< Interrupt enable for pin 11 */
  uint32_t PIN12                  :1;                                /*!< Interrupt enable for pin 12 */
  uint32_t PIN13                  :1;                                /*!< Interrupt enable for pin 13 */
  uint32_t PIN14                  :1;                                /*!< Interrupt enable for pin 14 */
  uint32_t PIN15                  :1;                                /*!< Interrupt enable for pin 15 */
} _GPIO_INTENSET_bits;

/* Bit field positions: */
#define GPIO_INTENSET_PIN0_Pos                0                      /*!< Interrupt enable for pin 0 */
#define GPIO_INTENSET_PIN1_Pos                1                      /*!< Interrupt enable for pin 1 */
#define GPIO_INTENSET_PIN2_Pos                2                      /*!< Interrupt enable for pin 2 */
#define GPIO_INTENSET_PIN3_Pos                3                      /*!< Interrupt enable for pin 3 */
#define GPIO_INTENSET_PIN4_Pos                4                      /*!< Interrupt enable for pin 4 */
#define GPIO_INTENSET_PIN5_Pos                5                      /*!< Interrupt enable for pin 5 */
#define GPIO_INTENSET_PIN6_Pos                6                      /*!< Interrupt enable for pin 6 */
#define GPIO_INTENSET_PIN7_Pos                7                      /*!< Interrupt enable for pin 7 */
#define GPIO_INTENSET_PIN8_Pos                8                      /*!< Interrupt enable for pin 8 */
#define GPIO_INTENSET_PIN9_Pos                9                      /*!< Interrupt enable for pin 9 */
#define GPIO_INTENSET_PIN10_Pos               10                     /*!< Interrupt enable for pin 10 */
#define GPIO_INTENSET_PIN11_Pos               11                     /*!< Interrupt enable for pin 11 */
#define GPIO_INTENSET_PIN12_Pos               12                     /*!< Interrupt enable for pin 12 */
#define GPIO_INTENSET_PIN13_Pos               13                     /*!< Interrupt enable for pin 13 */
#define GPIO_INTENSET_PIN14_Pos               14                     /*!< Interrupt enable for pin 14 */
#define GPIO_INTENSET_PIN15_Pos               15                     /*!< Interrupt enable for pin 15 */

/* Bit field masks: */
#define GPIO_INTENSET_PIN0_Msk                0x00000001             /*!< Interrupt enable for pin 0 */
#define GPIO_INTENSET_PIN1_Msk                0x00000002             /*!< Interrupt enable for pin 1 */
#define GPIO_INTENSET_PIN2_Msk                0x00000004             /*!< Interrupt enable for pin 2 */
#define GPIO_INTENSET_PIN3_Msk                0x00000008             /*!< Interrupt enable for pin 3 */
#define GPIO_INTENSET_PIN4_Msk                0x00000010             /*!< Interrupt enable for pin 4 */
#define GPIO_INTENSET_PIN5_Msk                0x00000020             /*!< Interrupt enable for pin 5 */
#define GPIO_INTENSET_PIN6_Msk                0x00000040             /*!< Interrupt enable for pin 6 */
#define GPIO_INTENSET_PIN7_Msk                0x00000080             /*!< Interrupt enable for pin 7 */
#define GPIO_INTENSET_PIN8_Msk                0x00000100             /*!< Interrupt enable for pin 8 */
#define GPIO_INTENSET_PIN9_Msk                0x00000200             /*!< Interrupt enable for pin 9 */
#define GPIO_INTENSET_PIN10_Msk               0x00000400             /*!< Interrupt enable for pin 10 */
#define GPIO_INTENSET_PIN11_Msk               0x00000800             /*!< Interrupt enable for pin 11 */
#define GPIO_INTENSET_PIN12_Msk               0x00001000             /*!< Interrupt enable for pin 12 */
#define GPIO_INTENSET_PIN13_Msk               0x00002000             /*!< Interrupt enable for pin 13 */
#define GPIO_INTENSET_PIN14_Msk               0x00004000             /*!< Interrupt enable for pin 14 */
#define GPIO_INTENSET_PIN15_Msk               0x00008000             /*!< Interrupt enable for pin 15 */

/*--  INTENCLR: Interrupt disable register --------------------------------------------------------------------*/
typedef struct {
  uint32_t PIN0                   :1;                                /*!< Interrupt disable for pin 0 */
  uint32_t PIN1                   :1;                                /*!< Interrupt disable for pin 1 */
  uint32_t PIN2                   :1;                                /*!< Interrupt disable for pin 2 */
  uint32_t PIN3                   :1;                                /*!< Interrupt disable for pin 3 */
  uint32_t PIN4                   :1;                                /*!< Interrupt disable for pin 4 */
  uint32_t PIN5                   :1;                                /*!< Interrupt disable for pin 5 */
  uint32_t PIN6                   :1;                                /*!< Interrupt disable for pin 6 */
  uint32_t PIN7                   :1;                                /*!< Interrupt disable for pin 7 */
  uint32_t PIN8                   :1;                                /*!< Interrupt disable for pin 8 */
  uint32_t PIN9                   :1;                                /*!< Interrupt disable for pin 9 */
  uint32_t PIN10                  :1;                                /*!< Interrupt disable for pin 10 */
  uint32_t PIN11                  :1;                                /*!< Interrupt disable for pin 11 */
  uint32_t PIN12                  :1;                                /*!< Interrupt disable for pin 12 */
  uint32_t PIN13                  :1;                                /*!< Interrupt disable for pin 13 */
  uint32_t PIN14                  :1;                                /*!< Interrupt disable for pin 14 */
  uint32_t PIN15                  :1;                                /*!< Interrupt disable for pin 15 */
} _GPIO_INTENCLR_bits;

/* Bit field positions: */
#define GPIO_INTENCLR_PIN0_Pos                0                      /*!< Interrupt disable for pin 0 */
#define GPIO_INTENCLR_PIN1_Pos                1                      /*!< Interrupt disable for pin 1 */
#define GPIO_INTENCLR_PIN2_Pos                2                      /*!< Interrupt disable for pin 2 */
#define GPIO_INTENCLR_PIN3_Pos                3                      /*!< Interrupt disable for pin 3 */
#define GPIO_INTENCLR_PIN4_Pos                4                      /*!< Interrupt disable for pin 4 */
#define GPIO_INTENCLR_PIN5_Pos                5                      /*!< Interrupt disable for pin 5 */
#define GPIO_INTENCLR_PIN6_Pos                6                      /*!< Interrupt disable for pin 6 */
#define GPIO_INTENCLR_PIN7_Pos                7                      /*!< Interrupt disable for pin 7 */
#define GPIO_INTENCLR_PIN8_Pos                8                      /*!< Interrupt disable for pin 8 */
#define GPIO_INTENCLR_PIN9_Pos                9                      /*!< Interrupt disable for pin 9 */
#define GPIO_INTENCLR_PIN10_Pos               10                     /*!< Interrupt disable for pin 10 */
#define GPIO_INTENCLR_PIN11_Pos               11                     /*!< Interrupt disable for pin 11 */
#define GPIO_INTENCLR_PIN12_Pos               12                     /*!< Interrupt disable for pin 12 */
#define GPIO_INTENCLR_PIN13_Pos               13                     /*!< Interrupt disable for pin 13 */
#define GPIO_INTENCLR_PIN14_Pos               14                     /*!< Interrupt disable for pin 14 */
#define GPIO_INTENCLR_PIN15_Pos               15                     /*!< Interrupt disable for pin 15 */

/* Bit field masks: */
#define GPIO_INTENCLR_PIN0_Msk                0x00000001             /*!< Interrupt disable for pin 0 */
#define GPIO_INTENCLR_PIN1_Msk                0x00000002             /*!< Interrupt disable for pin 1 */
#define GPIO_INTENCLR_PIN2_Msk                0x00000004             /*!< Interrupt disable for pin 2 */
#define GPIO_INTENCLR_PIN3_Msk                0x00000008             /*!< Interrupt disable for pin 3 */
#define GPIO_INTENCLR_PIN4_Msk                0x00000010             /*!< Interrupt disable for pin 4 */
#define GPIO_INTENCLR_PIN5_Msk                0x00000020             /*!< Interrupt disable for pin 5 */
#define GPIO_INTENCLR_PIN6_Msk                0x00000040             /*!< Interrupt disable for pin 6 */
#define GPIO_INTENCLR_PIN7_Msk                0x00000080             /*!< Interrupt disable for pin 7 */
#define GPIO_INTENCLR_PIN8_Msk                0x00000100             /*!< Interrupt disable for pin 8 */
#define GPIO_INTENCLR_PIN9_Msk                0x00000200             /*!< Interrupt disable for pin 9 */
#define GPIO_INTENCLR_PIN10_Msk               0x00000400             /*!< Interrupt disable for pin 10 */
#define GPIO_INTENCLR_PIN11_Msk               0x00000800             /*!< Interrupt disable for pin 11 */
#define GPIO_INTENCLR_PIN12_Msk               0x00001000             /*!< Interrupt disable for pin 12 */
#define GPIO_INTENCLR_PIN13_Msk               0x00002000             /*!< Interrupt disable for pin 13 */
#define GPIO_INTENCLR_PIN14_Msk               0x00004000             /*!< Interrupt disable for pin 14 */
#define GPIO_INTENCLR_PIN15_Msk               0x00008000             /*!< Interrupt disable for pin 15 */

/*--  INTTYPESET: Interrupt type set register -----------------------------------------------------------------*/
typedef struct {
  uint32_t PIN0                   :1;                                /*!< Interrupt type set for pin 0 */
  uint32_t PIN1                   :1;                                /*!< Interrupt type set for pin 1 */
  uint32_t PIN2                   :1;                                /*!< Interrupt type set for pin 2 */
  uint32_t PIN3                   :1;                                /*!< Interrupt type set for pin 3 */
  uint32_t PIN4                   :1;                                /*!< Interrupt type set for pin 4 */
  uint32_t PIN5                   :1;                                /*!< Interrupt type set for pin 5 */
  uint32_t PIN6                   :1;                                /*!< Interrupt type set for pin 6 */
  uint32_t PIN7                   :1;                                /*!< Interrupt type set for pin 7 */
  uint32_t PIN8                   :1;                                /*!< Interrupt type set for pin 8 */
  uint32_t PIN9                   :1;                                /*!< Interrupt type set for pin 9 */
  uint32_t PIN10                  :1;                                /*!< Interrupt type set for pin 10 */
  uint32_t PIN11                  :1;                                /*!< Interrupt type set for pin 11 */
  uint32_t PIN12                  :1;                                /*!< Interrupt type set for pin 12 */
  uint32_t PIN13                  :1;                                /*!< Interrupt type set for pin 13 */
  uint32_t PIN14                  :1;                                /*!< Interrupt type set for pin 14 */
  uint32_t PIN15                  :1;                                /*!< Interrupt type set for pin 15 */
} _GPIO_INTTYPESET_bits;

/* Bit field positions: */
#define GPIO_INTTYPESET_PIN0_Pos              0                      /*!< Interrupt type set for pin 0 */
#define GPIO_INTTYPESET_PIN1_Pos              1                      /*!< Interrupt type set for pin 1 */
#define GPIO_INTTYPESET_PIN2_Pos              2                      /*!< Interrupt type set for pin 2 */
#define GPIO_INTTYPESET_PIN3_Pos              3                      /*!< Interrupt type set for pin 3 */
#define GPIO_INTTYPESET_PIN4_Pos              4                      /*!< Interrupt type set for pin 4 */
#define GPIO_INTTYPESET_PIN5_Pos              5                      /*!< Interrupt type set for pin 5 */
#define GPIO_INTTYPESET_PIN6_Pos              6                      /*!< Interrupt type set for pin 6 */
#define GPIO_INTTYPESET_PIN7_Pos              7                      /*!< Interrupt type set for pin 7 */
#define GPIO_INTTYPESET_PIN8_Pos              8                      /*!< Interrupt type set for pin 8 */
#define GPIO_INTTYPESET_PIN9_Pos              9                      /*!< Interrupt type set for pin 9 */
#define GPIO_INTTYPESET_PIN10_Pos             10                     /*!< Interrupt type set for pin 10 */
#define GPIO_INTTYPESET_PIN11_Pos             11                     /*!< Interrupt type set for pin 11 */
#define GPIO_INTTYPESET_PIN12_Pos             12                     /*!< Interrupt type set for pin 12 */
#define GPIO_INTTYPESET_PIN13_Pos             13                     /*!< Interrupt type set for pin 13 */
#define GPIO_INTTYPESET_PIN14_Pos             14                     /*!< Interrupt type set for pin 14 */
#define GPIO_INTTYPESET_PIN15_Pos             15                     /*!< Interrupt type set for pin 15 */

/* Bit field masks: */
#define GPIO_INTTYPESET_PIN0_Msk              0x00000001             /*!< Interrupt type set for pin 0 */
#define GPIO_INTTYPESET_PIN1_Msk              0x00000002             /*!< Interrupt type set for pin 1 */
#define GPIO_INTTYPESET_PIN2_Msk              0x00000004             /*!< Interrupt type set for pin 2 */
#define GPIO_INTTYPESET_PIN3_Msk              0x00000008             /*!< Interrupt type set for pin 3 */
#define GPIO_INTTYPESET_PIN4_Msk              0x00000010             /*!< Interrupt type set for pin 4 */
#define GPIO_INTTYPESET_PIN5_Msk              0x00000020             /*!< Interrupt type set for pin 5 */
#define GPIO_INTTYPESET_PIN6_Msk              0x00000040             /*!< Interrupt type set for pin 6 */
#define GPIO_INTTYPESET_PIN7_Msk              0x00000080             /*!< Interrupt type set for pin 7 */
#define GPIO_INTTYPESET_PIN8_Msk              0x00000100             /*!< Interrupt type set for pin 8 */
#define GPIO_INTTYPESET_PIN9_Msk              0x00000200             /*!< Interrupt type set for pin 9 */
#define GPIO_INTTYPESET_PIN10_Msk             0x00000400             /*!< Interrupt type set for pin 10 */
#define GPIO_INTTYPESET_PIN11_Msk             0x00000800             /*!< Interrupt type set for pin 11 */
#define GPIO_INTTYPESET_PIN12_Msk             0x00001000             /*!< Interrupt type set for pin 12 */
#define GPIO_INTTYPESET_PIN13_Msk             0x00002000             /*!< Interrupt type set for pin 13 */
#define GPIO_INTTYPESET_PIN14_Msk             0x00004000             /*!< Interrupt type set for pin 14 */
#define GPIO_INTTYPESET_PIN15_Msk             0x00008000             /*!< Interrupt type set for pin 15 */

/*--  INTTYPECLR: Interrupt type clear register ---------------------------------------------------------------*/
typedef struct {
  uint32_t PIN0                   :1;                                /*!< Interrupt type clear for pin 0 */
  uint32_t PIN1                   :1;                                /*!< Interrupt type clear for pin 1 */
  uint32_t PIN2                   :1;                                /*!< Interrupt type clear for pin 2 */
  uint32_t PIN3                   :1;                                /*!< Interrupt type clear for pin 3 */
  uint32_t PIN4                   :1;                                /*!< Interrupt type clear for pin 4 */
  uint32_t PIN5                   :1;                                /*!< Interrupt type clear for pin 5 */
  uint32_t PIN6                   :1;                                /*!< Interrupt type clear for pin 6 */
  uint32_t PIN7                   :1;                                /*!< Interrupt type clear for pin 7 */
  uint32_t PIN8                   :1;                                /*!< Interrupt type clear for pin 8 */
  uint32_t PIN9                   :1;                                /*!< Interrupt type clear for pin 9 */
  uint32_t PIN10                  :1;                                /*!< Interrupt type clear for pin 10 */
  uint32_t PIN11                  :1;                                /*!< Interrupt type clear for pin 11 */
  uint32_t PIN12                  :1;                                /*!< Interrupt type clear for pin 12 */
  uint32_t PIN13                  :1;                                /*!< Interrupt type clear for pin 13 */
  uint32_t PIN14                  :1;                                /*!< Interrupt type clear for pin 14 */
  uint32_t PIN15                  :1;                                /*!< Interrupt type clear for pin 15 */
} _GPIO_INTTYPECLR_bits;

/* Bit field positions: */
#define GPIO_INTTYPECLR_PIN0_Pos              0                      /*!< Interrupt type clear for pin 0 */
#define GPIO_INTTYPECLR_PIN1_Pos              1                      /*!< Interrupt type clear for pin 1 */
#define GPIO_INTTYPECLR_PIN2_Pos              2                      /*!< Interrupt type clear for pin 2 */
#define GPIO_INTTYPECLR_PIN3_Pos              3                      /*!< Interrupt type clear for pin 3 */
#define GPIO_INTTYPECLR_PIN4_Pos              4                      /*!< Interrupt type clear for pin 4 */
#define GPIO_INTTYPECLR_PIN5_Pos              5                      /*!< Interrupt type clear for pin 5 */
#define GPIO_INTTYPECLR_PIN6_Pos              6                      /*!< Interrupt type clear for pin 6 */
#define GPIO_INTTYPECLR_PIN7_Pos              7                      /*!< Interrupt type clear for pin 7 */
#define GPIO_INTTYPECLR_PIN8_Pos              8                      /*!< Interrupt type clear for pin 8 */
#define GPIO_INTTYPECLR_PIN9_Pos              9                      /*!< Interrupt type clear for pin 9 */
#define GPIO_INTTYPECLR_PIN10_Pos             10                     /*!< Interrupt type clear for pin 10 */
#define GPIO_INTTYPECLR_PIN11_Pos             11                     /*!< Interrupt type clear for pin 11 */
#define GPIO_INTTYPECLR_PIN12_Pos             12                     /*!< Interrupt type clear for pin 12 */
#define GPIO_INTTYPECLR_PIN13_Pos             13                     /*!< Interrupt type clear for pin 13 */
#define GPIO_INTTYPECLR_PIN14_Pos             14                     /*!< Interrupt type clear for pin 14 */
#define GPIO_INTTYPECLR_PIN15_Pos             15                     /*!< Interrupt type clear for pin 15 */

/* Bit field masks: */
#define GPIO_INTTYPECLR_PIN0_Msk              0x00000001             /*!< Interrupt type clear for pin 0 */
#define GPIO_INTTYPECLR_PIN1_Msk              0x00000002             /*!< Interrupt type clear for pin 1 */
#define GPIO_INTTYPECLR_PIN2_Msk              0x00000004             /*!< Interrupt type clear for pin 2 */
#define GPIO_INTTYPECLR_PIN3_Msk              0x00000008             /*!< Interrupt type clear for pin 3 */
#define GPIO_INTTYPECLR_PIN4_Msk              0x00000010             /*!< Interrupt type clear for pin 4 */
#define GPIO_INTTYPECLR_PIN5_Msk              0x00000020             /*!< Interrupt type clear for pin 5 */
#define GPIO_INTTYPECLR_PIN6_Msk              0x00000040             /*!< Interrupt type clear for pin 6 */
#define GPIO_INTTYPECLR_PIN7_Msk              0x00000080             /*!< Interrupt type clear for pin 7 */
#define GPIO_INTTYPECLR_PIN8_Msk              0x00000100             /*!< Interrupt type clear for pin 8 */
#define GPIO_INTTYPECLR_PIN9_Msk              0x00000200             /*!< Interrupt type clear for pin 9 */
#define GPIO_INTTYPECLR_PIN10_Msk             0x00000400             /*!< Interrupt type clear for pin 10 */
#define GPIO_INTTYPECLR_PIN11_Msk             0x00000800             /*!< Interrupt type clear for pin 11 */
#define GPIO_INTTYPECLR_PIN12_Msk             0x00001000             /*!< Interrupt type clear for pin 12 */
#define GPIO_INTTYPECLR_PIN13_Msk             0x00002000             /*!< Interrupt type clear for pin 13 */
#define GPIO_INTTYPECLR_PIN14_Msk             0x00004000             /*!< Interrupt type clear for pin 14 */
#define GPIO_INTTYPECLR_PIN15_Msk             0x00008000             /*!< Interrupt type clear for pin 15 */

/*--  INTPOLSET: Interrupt polarity set register --------------------------------------------------------------*/
typedef struct {
  uint32_t PIN0                   :1;                                /*!< Interrupt polarity set for pin 0 */
  uint32_t PIN1                   :1;                                /*!< Interrupt polarity set for pin 1 */
  uint32_t PIN2                   :1;                                /*!< Interrupt polarity set for pin 2 */
  uint32_t PIN3                   :1;                                /*!< Interrupt polarity set for pin 3 */
  uint32_t PIN4                   :1;                                /*!< Interrupt polarity set for pin 4 */
  uint32_t PIN5                   :1;                                /*!< Interrupt polarity set for pin 5 */
  uint32_t PIN6                   :1;                                /*!< Interrupt polarity set for pin 6 */
  uint32_t PIN7                   :1;                                /*!< Interrupt polarity set for pin 7 */
  uint32_t PIN8                   :1;                                /*!< Interrupt polarity set for pin 8 */
  uint32_t PIN9                   :1;                                /*!< Interrupt polarity set for pin 9 */
  uint32_t PIN10                  :1;                                /*!< Interrupt polarity set for pin 10 */
  uint32_t PIN11                  :1;                                /*!< Interrupt polarity set for pin 11 */
  uint32_t PIN12                  :1;                                /*!< Interrupt polarity set for pin 12 */
  uint32_t PIN13                  :1;                                /*!< Interrupt polarity set for pin 13 */
  uint32_t PIN14                  :1;                                /*!< Interrupt polarity set for pin 14 */
  uint32_t PIN15                  :1;                                /*!< Interrupt polarity set for pin 15 */
} _GPIO_INTPOLSET_bits;

/* Bit field positions: */
#define GPIO_INTPOLSET_PIN0_Pos               0                      /*!< Interrupt polarity set for pin 0 */
#define GPIO_INTPOLSET_PIN1_Pos               1                      /*!< Interrupt polarity set for pin 1 */
#define GPIO_INTPOLSET_PIN2_Pos               2                      /*!< Interrupt polarity set for pin 2 */
#define GPIO_INTPOLSET_PIN3_Pos               3                      /*!< Interrupt polarity set for pin 3 */
#define GPIO_INTPOLSET_PIN4_Pos               4                      /*!< Interrupt polarity set for pin 4 */
#define GPIO_INTPOLSET_PIN5_Pos               5                      /*!< Interrupt polarity set for pin 5 */
#define GPIO_INTPOLSET_PIN6_Pos               6                      /*!< Interrupt polarity set for pin 6 */
#define GPIO_INTPOLSET_PIN7_Pos               7                      /*!< Interrupt polarity set for pin 7 */
#define GPIO_INTPOLSET_PIN8_Pos               8                      /*!< Interrupt polarity set for pin 8 */
#define GPIO_INTPOLSET_PIN9_Pos               9                      /*!< Interrupt polarity set for pin 9 */
#define GPIO_INTPOLSET_PIN10_Pos              10                     /*!< Interrupt polarity set for pin 10 */
#define GPIO_INTPOLSET_PIN11_Pos              11                     /*!< Interrupt polarity set for pin 11 */
#define GPIO_INTPOLSET_PIN12_Pos              12                     /*!< Interrupt polarity set for pin 12 */
#define GPIO_INTPOLSET_PIN13_Pos              13                     /*!< Interrupt polarity set for pin 13 */
#define GPIO_INTPOLSET_PIN14_Pos              14                     /*!< Interrupt polarity set for pin 14 */
#define GPIO_INTPOLSET_PIN15_Pos              15                     /*!< Interrupt polarity set for pin 15 */

/* Bit field masks: */
#define GPIO_INTPOLSET_PIN0_Msk               0x00000001             /*!< Interrupt polarity set for pin 0 */
#define GPIO_INTPOLSET_PIN1_Msk               0x00000002             /*!< Interrupt polarity set for pin 1 */
#define GPIO_INTPOLSET_PIN2_Msk               0x00000004             /*!< Interrupt polarity set for pin 2 */
#define GPIO_INTPOLSET_PIN3_Msk               0x00000008             /*!< Interrupt polarity set for pin 3 */
#define GPIO_INTPOLSET_PIN4_Msk               0x00000010             /*!< Interrupt polarity set for pin 4 */
#define GPIO_INTPOLSET_PIN5_Msk               0x00000020             /*!< Interrupt polarity set for pin 5 */
#define GPIO_INTPOLSET_PIN6_Msk               0x00000040             /*!< Interrupt polarity set for pin 6 */
#define GPIO_INTPOLSET_PIN7_Msk               0x00000080             /*!< Interrupt polarity set for pin 7 */
#define GPIO_INTPOLSET_PIN8_Msk               0x00000100             /*!< Interrupt polarity set for pin 8 */
#define GPIO_INTPOLSET_PIN9_Msk               0x00000200             /*!< Interrupt polarity set for pin 9 */
#define GPIO_INTPOLSET_PIN10_Msk              0x00000400             /*!< Interrupt polarity set for pin 10 */
#define GPIO_INTPOLSET_PIN11_Msk              0x00000800             /*!< Interrupt polarity set for pin 11 */
#define GPIO_INTPOLSET_PIN12_Msk              0x00001000             /*!< Interrupt polarity set for pin 12 */
#define GPIO_INTPOLSET_PIN13_Msk              0x00002000             /*!< Interrupt polarity set for pin 13 */
#define GPIO_INTPOLSET_PIN14_Msk              0x00004000             /*!< Interrupt polarity set for pin 14 */
#define GPIO_INTPOLSET_PIN15_Msk              0x00008000             /*!< Interrupt polarity set for pin 15 */

/*--  INTPOLCLR: Interrupt polarity clear register ------------------------------------------------------------*/
typedef struct {
  uint32_t PIN0                   :1;                                /*!< Interrupt polarity clear for pin 0 */
  uint32_t PIN1                   :1;                                /*!< Interrupt polarity clear for pin 1 */
  uint32_t PIN2                   :1;                                /*!< Interrupt polarity clear for pin 2 */
  uint32_t PIN3                   :1;                                /*!< Interrupt polarity clear for pin 3 */
  uint32_t PIN4                   :1;                                /*!< Interrupt polarity clear for pin 4 */
  uint32_t PIN5                   :1;                                /*!< Interrupt polarity clear for pin 5 */
  uint32_t PIN6                   :1;                                /*!< Interrupt polarity clear for pin 6 */
  uint32_t PIN7                   :1;                                /*!< Interrupt polarity clear for pin 7 */
  uint32_t PIN8                   :1;                                /*!< Interrupt polarity clear for pin 8 */
  uint32_t PIN9                   :1;                                /*!< Interrupt polarity clear for pin 9 */
  uint32_t PIN10                  :1;                                /*!< Interrupt polarity clear for pin 10 */
  uint32_t PIN11                  :1;                                /*!< Interrupt polarity clear for pin 11 */
  uint32_t PIN12                  :1;                                /*!< Interrupt polarity clear for pin 12 */
  uint32_t PIN13                  :1;                                /*!< Interrupt polarity clear for pin 13 */
  uint32_t PIN14                  :1;                                /*!< Interrupt polarity clear for pin 14 */
  uint32_t PIN15                  :1;                                /*!< Interrupt polarity clear for pin 15 */
} _GPIO_INTPOLCLR_bits;

/* Bit field positions: */
#define GPIO_INTPOLCLR_PIN0_Pos               0                      /*!< Interrupt polarity clear for pin 0 */
#define GPIO_INTPOLCLR_PIN1_Pos               1                      /*!< Interrupt polarity clear for pin 1 */
#define GPIO_INTPOLCLR_PIN2_Pos               2                      /*!< Interrupt polarity clear for pin 2 */
#define GPIO_INTPOLCLR_PIN3_Pos               3                      /*!< Interrupt polarity clear for pin 3 */
#define GPIO_INTPOLCLR_PIN4_Pos               4                      /*!< Interrupt polarity clear for pin 4 */
#define GPIO_INTPOLCLR_PIN5_Pos               5                      /*!< Interrupt polarity clear for pin 5 */
#define GPIO_INTPOLCLR_PIN6_Pos               6                      /*!< Interrupt polarity clear for pin 6 */
#define GPIO_INTPOLCLR_PIN7_Pos               7                      /*!< Interrupt polarity clear for pin 7 */
#define GPIO_INTPOLCLR_PIN8_Pos               8                      /*!< Interrupt polarity clear for pin 8 */
#define GPIO_INTPOLCLR_PIN9_Pos               9                      /*!< Interrupt polarity clear for pin 9 */
#define GPIO_INTPOLCLR_PIN10_Pos              10                     /*!< Interrupt polarity clear for pin 10 */
#define GPIO_INTPOLCLR_PIN11_Pos              11                     /*!< Interrupt polarity clear for pin 11 */
#define GPIO_INTPOLCLR_PIN12_Pos              12                     /*!< Interrupt polarity clear for pin 12 */
#define GPIO_INTPOLCLR_PIN13_Pos              13                     /*!< Interrupt polarity clear for pin 13 */
#define GPIO_INTPOLCLR_PIN14_Pos              14                     /*!< Interrupt polarity clear for pin 14 */
#define GPIO_INTPOLCLR_PIN15_Pos              15                     /*!< Interrupt polarity clear for pin 15 */

/* Bit field masks: */
#define GPIO_INTPOLCLR_PIN0_Msk               0x00000001             /*!< Interrupt polarity clear for pin 0 */
#define GPIO_INTPOLCLR_PIN1_Msk               0x00000002             /*!< Interrupt polarity clear for pin 1 */
#define GPIO_INTPOLCLR_PIN2_Msk               0x00000004             /*!< Interrupt polarity clear for pin 2 */
#define GPIO_INTPOLCLR_PIN3_Msk               0x00000008             /*!< Interrupt polarity clear for pin 3 */
#define GPIO_INTPOLCLR_PIN4_Msk               0x00000010             /*!< Interrupt polarity clear for pin 4 */
#define GPIO_INTPOLCLR_PIN5_Msk               0x00000020             /*!< Interrupt polarity clear for pin 5 */
#define GPIO_INTPOLCLR_PIN6_Msk               0x00000040             /*!< Interrupt polarity clear for pin 6 */
#define GPIO_INTPOLCLR_PIN7_Msk               0x00000080             /*!< Interrupt polarity clear for pin 7 */
#define GPIO_INTPOLCLR_PIN8_Msk               0x00000100             /*!< Interrupt polarity clear for pin 8 */
#define GPIO_INTPOLCLR_PIN9_Msk               0x00000200             /*!< Interrupt polarity clear for pin 9 */
#define GPIO_INTPOLCLR_PIN10_Msk              0x00000400             /*!< Interrupt polarity clear for pin 10 */
#define GPIO_INTPOLCLR_PIN11_Msk              0x00000800             /*!< Interrupt polarity clear for pin 11 */
#define GPIO_INTPOLCLR_PIN12_Msk              0x00001000             /*!< Interrupt polarity clear for pin 12 */
#define GPIO_INTPOLCLR_PIN13_Msk              0x00002000             /*!< Interrupt polarity clear for pin 13 */
#define GPIO_INTPOLCLR_PIN14_Msk              0x00004000             /*!< Interrupt polarity clear for pin 14 */
#define GPIO_INTPOLCLR_PIN15_Msk              0x00008000             /*!< Interrupt polarity clear for pin 15 */

/*--  INTEDGESET: Interrupt every edge set register -----------------------------------------------------------*/
typedef struct {
  uint32_t PIN0                   :1;                                /*!< Interrupt every edge set for pin 0 */
  uint32_t PIN1                   :1;                                /*!< Interrupt every edge set for pin 1 */
  uint32_t PIN2                   :1;                                /*!< Interrupt every edge set for pin 2 */
  uint32_t PIN3                   :1;                                /*!< Interrupt every edge set for pin 3 */
  uint32_t PIN4                   :1;                                /*!< Interrupt every edge set for pin 4 */
  uint32_t PIN5                   :1;                                /*!< Interrupt every edge set for pin 5 */
  uint32_t PIN6                   :1;                                /*!< Interrupt every edge set for pin 6 */
  uint32_t PIN7                   :1;                                /*!< Interrupt every edge set for pin 7 */
  uint32_t PIN8                   :1;                                /*!< Interrupt every edge set for pin 8 */
  uint32_t PIN9                   :1;                                /*!< Interrupt every edge set for pin 9 */
  uint32_t PIN10                  :1;                                /*!< Interrupt every edge set for pin 10 */
  uint32_t PIN11                  :1;                                /*!< Interrupt every edge set for pin 11 */
  uint32_t PIN12                  :1;                                /*!< Interrupt every edge set for pin 12 */
  uint32_t PIN13                  :1;                                /*!< Interrupt every edge set for pin 13 */
  uint32_t PIN14                  :1;                                /*!< Interrupt every edge set for pin 14 */
  uint32_t PIN15                  :1;                                /*!< Interrupt every edge set for pin 15 */
} _GPIO_INTEDGESET_bits;

/* Bit field positions: */
#define GPIO_INTEDGESET_PIN0_Pos              0                      /*!< Interrupt every edge set for pin 0 */
#define GPIO_INTEDGESET_PIN1_Pos              1                      /*!< Interrupt every edge set for pin 1 */
#define GPIO_INTEDGESET_PIN2_Pos              2                      /*!< Interrupt every edge set for pin 2 */
#define GPIO_INTEDGESET_PIN3_Pos              3                      /*!< Interrupt every edge set for pin 3 */
#define GPIO_INTEDGESET_PIN4_Pos              4                      /*!< Interrupt every edge set for pin 4 */
#define GPIO_INTEDGESET_PIN5_Pos              5                      /*!< Interrupt every edge set for pin 5 */
#define GPIO_INTEDGESET_PIN6_Pos              6                      /*!< Interrupt every edge set for pin 6 */
#define GPIO_INTEDGESET_PIN7_Pos              7                      /*!< Interrupt every edge set for pin 7 */
#define GPIO_INTEDGESET_PIN8_Pos              8                      /*!< Interrupt every edge set for pin 8 */
#define GPIO_INTEDGESET_PIN9_Pos              9                      /*!< Interrupt every edge set for pin 9 */
#define GPIO_INTEDGESET_PIN10_Pos             10                     /*!< Interrupt every edge set for pin 10 */
#define GPIO_INTEDGESET_PIN11_Pos             11                     /*!< Interrupt every edge set for pin 11 */
#define GPIO_INTEDGESET_PIN12_Pos             12                     /*!< Interrupt every edge set for pin 12 */
#define GPIO_INTEDGESET_PIN13_Pos             13                     /*!< Interrupt every edge set for pin 13 */
#define GPIO_INTEDGESET_PIN14_Pos             14                     /*!< Interrupt every edge set for pin 14 */
#define GPIO_INTEDGESET_PIN15_Pos             15                     /*!< Interrupt every edge set for pin 15 */

/* Bit field masks: */
#define GPIO_INTEDGESET_PIN0_Msk              0x00000001             /*!< Interrupt every edge set for pin 0 */
#define GPIO_INTEDGESET_PIN1_Msk              0x00000002             /*!< Interrupt every edge set for pin 1 */
#define GPIO_INTEDGESET_PIN2_Msk              0x00000004             /*!< Interrupt every edge set for pin 2 */
#define GPIO_INTEDGESET_PIN3_Msk              0x00000008             /*!< Interrupt every edge set for pin 3 */
#define GPIO_INTEDGESET_PIN4_Msk              0x00000010             /*!< Interrupt every edge set for pin 4 */
#define GPIO_INTEDGESET_PIN5_Msk              0x00000020             /*!< Interrupt every edge set for pin 5 */
#define GPIO_INTEDGESET_PIN6_Msk              0x00000040             /*!< Interrupt every edge set for pin 6 */
#define GPIO_INTEDGESET_PIN7_Msk              0x00000080             /*!< Interrupt every edge set for pin 7 */
#define GPIO_INTEDGESET_PIN8_Msk              0x00000100             /*!< Interrupt every edge set for pin 8 */
#define GPIO_INTEDGESET_PIN9_Msk              0x00000200             /*!< Interrupt every edge set for pin 9 */
#define GPIO_INTEDGESET_PIN10_Msk             0x00000400             /*!< Interrupt every edge set for pin 10 */
#define GPIO_INTEDGESET_PIN11_Msk             0x00000800             /*!< Interrupt every edge set for pin 11 */
#define GPIO_INTEDGESET_PIN12_Msk             0x00001000             /*!< Interrupt every edge set for pin 12 */
#define GPIO_INTEDGESET_PIN13_Msk             0x00002000             /*!< Interrupt every edge set for pin 13 */
#define GPIO_INTEDGESET_PIN14_Msk             0x00004000             /*!< Interrupt every edge set for pin 14 */
#define GPIO_INTEDGESET_PIN15_Msk             0x00008000             /*!< Interrupt every edge set for pin 15 */

/*--  INTEDGECLR: Interrupt every edge clear register ---------------------------------------------------------*/
typedef struct {
  uint32_t PIN0                   :1;                                /*!< Interrupt every edge clear for pin 0 */
  uint32_t PIN1                   :1;                                /*!< Interrupt every edge clear for pin 1 */
  uint32_t PIN2                   :1;                                /*!< Interrupt every edge clear for pin 2 */
  uint32_t PIN3                   :1;                                /*!< Interrupt every edge clear for pin 3 */
  uint32_t PIN4                   :1;                                /*!< Interrupt every edge clear for pin 4 */
  uint32_t PIN5                   :1;                                /*!< Interrupt every edge clear for pin 5 */
  uint32_t PIN6                   :1;                                /*!< Interrupt every edge clear for pin 6 */
  uint32_t PIN7                   :1;                                /*!< Interrupt every edge clear for pin 7 */
  uint32_t PIN8                   :1;                                /*!< Interrupt every edge clear for pin 8 */
  uint32_t PIN9                   :1;                                /*!< Interrupt every edge clear for pin 9 */
  uint32_t PIN10                  :1;                                /*!< Interrupt every edge clear for pin 10 */
  uint32_t PIN11                  :1;                                /*!< Interrupt every edge clear for pin 11 */
  uint32_t PIN12                  :1;                                /*!< Interrupt every edge clear for pin 12 */
  uint32_t PIN13                  :1;                                /*!< Interrupt every edge clear for pin 13 */
  uint32_t PIN14                  :1;                                /*!< Interrupt every edge clear for pin 14 */
  uint32_t PIN15                  :1;                                /*!< Interrupt every edge clear for pin 15 */
} _GPIO_INTEDGECLR_bits;

/* Bit field positions: */
#define GPIO_INTEDGECLR_PIN0_Pos              0                      /*!< Interrupt every edge clear for pin 0 */
#define GPIO_INTEDGECLR_PIN1_Pos              1                      /*!< Interrupt every edge clear for pin 1 */
#define GPIO_INTEDGECLR_PIN2_Pos              2                      /*!< Interrupt every edge clear for pin 2 */
#define GPIO_INTEDGECLR_PIN3_Pos              3                      /*!< Interrupt every edge clear for pin 3 */
#define GPIO_INTEDGECLR_PIN4_Pos              4                      /*!< Interrupt every edge clear for pin 4 */
#define GPIO_INTEDGECLR_PIN5_Pos              5                      /*!< Interrupt every edge clear for pin 5 */
#define GPIO_INTEDGECLR_PIN6_Pos              6                      /*!< Interrupt every edge clear for pin 6 */
#define GPIO_INTEDGECLR_PIN7_Pos              7                      /*!< Interrupt every edge clear for pin 7 */
#define GPIO_INTEDGECLR_PIN8_Pos              8                      /*!< Interrupt every edge clear for pin 8 */
#define GPIO_INTEDGECLR_PIN9_Pos              9                      /*!< Interrupt every edge clear for pin 9 */
#define GPIO_INTEDGECLR_PIN10_Pos             10                     /*!< Interrupt every edge clear for pin 10 */
#define GPIO_INTEDGECLR_PIN11_Pos             11                     /*!< Interrupt every edge clear for pin 11 */
#define GPIO_INTEDGECLR_PIN12_Pos             12                     /*!< Interrupt every edge clear for pin 12 */
#define GPIO_INTEDGECLR_PIN13_Pos             13                     /*!< Interrupt every edge clear for pin 13 */
#define GPIO_INTEDGECLR_PIN14_Pos             14                     /*!< Interrupt every edge clear for pin 14 */
#define GPIO_INTEDGECLR_PIN15_Pos             15                     /*!< Interrupt every edge clear for pin 15 */

/* Bit field masks: */
#define GPIO_INTEDGECLR_PIN0_Msk              0x00000001             /*!< Interrupt every edge clear for pin 0 */
#define GPIO_INTEDGECLR_PIN1_Msk              0x00000002             /*!< Interrupt every edge clear for pin 1 */
#define GPIO_INTEDGECLR_PIN2_Msk              0x00000004             /*!< Interrupt every edge clear for pin 2 */
#define GPIO_INTEDGECLR_PIN3_Msk              0x00000008             /*!< Interrupt every edge clear for pin 3 */
#define GPIO_INTEDGECLR_PIN4_Msk              0x00000010             /*!< Interrupt every edge clear for pin 4 */
#define GPIO_INTEDGECLR_PIN5_Msk              0x00000020             /*!< Interrupt every edge clear for pin 5 */
#define GPIO_INTEDGECLR_PIN6_Msk              0x00000040             /*!< Interrupt every edge clear for pin 6 */
#define GPIO_INTEDGECLR_PIN7_Msk              0x00000080             /*!< Interrupt every edge clear for pin 7 */
#define GPIO_INTEDGECLR_PIN8_Msk              0x00000100             /*!< Interrupt every edge clear for pin 8 */
#define GPIO_INTEDGECLR_PIN9_Msk              0x00000200             /*!< Interrupt every edge clear for pin 9 */
#define GPIO_INTEDGECLR_PIN10_Msk             0x00000400             /*!< Interrupt every edge clear for pin 10 */
#define GPIO_INTEDGECLR_PIN11_Msk             0x00000800             /*!< Interrupt every edge clear for pin 11 */
#define GPIO_INTEDGECLR_PIN12_Msk             0x00001000             /*!< Interrupt every edge clear for pin 12 */
#define GPIO_INTEDGECLR_PIN13_Msk             0x00002000             /*!< Interrupt every edge clear for pin 13 */
#define GPIO_INTEDGECLR_PIN14_Msk             0x00004000             /*!< Interrupt every edge clear for pin 14 */
#define GPIO_INTEDGECLR_PIN15_Msk             0x00008000             /*!< Interrupt every edge clear for pin 15 */

/*--  INTSTATUS: Interrupt status -----------------------------------------------------------------------------*/
typedef struct {
  uint32_t PIN0                   :1;                                /*!< Interrupt status of pin 0 */
  uint32_t PIN1                   :1;                                /*!< Interrupt status of pin 1 */
  uint32_t PIN2                   :1;                                /*!< Interrupt status of pin 2 */
  uint32_t PIN3                   :1;                                /*!< Interrupt status of pin 3 */
  uint32_t PIN4                   :1;                                /*!< Interrupt status of pin 4 */
  uint32_t PIN5                   :1;                                /*!< Interrupt status of pin 5 */
  uint32_t PIN6                   :1;                                /*!< Interrupt status of pin 6 */
  uint32_t PIN7                   :1;                                /*!< Interrupt status of pin 7 */
  uint32_t PIN8                   :1;                                /*!< Interrupt status of pin 8 */
  uint32_t PIN9                   :1;                                /*!< Interrupt status of pin 9 */
  uint32_t PIN10                  :1;                                /*!< Interrupt status of pin 10 */
  uint32_t PIN11                  :1;                                /*!< Interrupt status of pin 11 */
  uint32_t PIN12                  :1;                                /*!< Interrupt status of pin 12 */
  uint32_t PIN13                  :1;                                /*!< Interrupt status of pin 13 */
  uint32_t PIN14                  :1;                                /*!< Interrupt status of pin 14 */
  uint32_t PIN15                  :1;                                /*!< Interrupt status of pin 15 */
} _GPIO_INTSTATUS_bits;

/* Bit field positions: */
#define GPIO_INTSTATUS_PIN0_Pos               0                      /*!< Interrupt status of pin 0 */
#define GPIO_INTSTATUS_PIN1_Pos               1                      /*!< Interrupt status of pin 1 */
#define GPIO_INTSTATUS_PIN2_Pos               2                      /*!< Interrupt status of pin 2 */
#define GPIO_INTSTATUS_PIN3_Pos               3                      /*!< Interrupt status of pin 3 */
#define GPIO_INTSTATUS_PIN4_Pos               4                      /*!< Interrupt status of pin 4 */
#define GPIO_INTSTATUS_PIN5_Pos               5                      /*!< Interrupt status of pin 5 */
#define GPIO_INTSTATUS_PIN6_Pos               6                      /*!< Interrupt status of pin 6 */
#define GPIO_INTSTATUS_PIN7_Pos               7                      /*!< Interrupt status of pin 7 */
#define GPIO_INTSTATUS_PIN8_Pos               8                      /*!< Interrupt status of pin 8 */
#define GPIO_INTSTATUS_PIN9_Pos               9                      /*!< Interrupt status of pin 9 */
#define GPIO_INTSTATUS_PIN10_Pos              10                     /*!< Interrupt status of pin 10 */
#define GPIO_INTSTATUS_PIN11_Pos              11                     /*!< Interrupt status of pin 11 */
#define GPIO_INTSTATUS_PIN12_Pos              12                     /*!< Interrupt status of pin 12 */
#define GPIO_INTSTATUS_PIN13_Pos              13                     /*!< Interrupt status of pin 13 */
#define GPIO_INTSTATUS_PIN14_Pos              14                     /*!< Interrupt status of pin 14 */
#define GPIO_INTSTATUS_PIN15_Pos              15                     /*!< Interrupt status of pin 15 */

/* Bit field masks: */
#define GPIO_INTSTATUS_PIN0_Msk               0x00000001             /*!< Interrupt status of pin 0 */
#define GPIO_INTSTATUS_PIN1_Msk               0x00000002             /*!< Interrupt status of pin 1 */
#define GPIO_INTSTATUS_PIN2_Msk               0x00000004             /*!< Interrupt status of pin 2 */
#define GPIO_INTSTATUS_PIN3_Msk               0x00000008             /*!< Interrupt status of pin 3 */
#define GPIO_INTSTATUS_PIN4_Msk               0x00000010             /*!< Interrupt status of pin 4 */
#define GPIO_INTSTATUS_PIN5_Msk               0x00000020             /*!< Interrupt status of pin 5 */
#define GPIO_INTSTATUS_PIN6_Msk               0x00000040             /*!< Interrupt status of pin 6 */
#define GPIO_INTSTATUS_PIN7_Msk               0x00000080             /*!< Interrupt status of pin 7 */
#define GPIO_INTSTATUS_PIN8_Msk               0x00000100             /*!< Interrupt status of pin 8 */
#define GPIO_INTSTATUS_PIN9_Msk               0x00000200             /*!< Interrupt status of pin 9 */
#define GPIO_INTSTATUS_PIN10_Msk              0x00000400             /*!< Interrupt status of pin 10 */
#define GPIO_INTSTATUS_PIN11_Msk              0x00000800             /*!< Interrupt status of pin 11 */
#define GPIO_INTSTATUS_PIN12_Msk              0x00001000             /*!< Interrupt status of pin 12 */
#define GPIO_INTSTATUS_PIN13_Msk              0x00002000             /*!< Interrupt status of pin 13 */
#define GPIO_INTSTATUS_PIN14_Msk              0x00004000             /*!< Interrupt status of pin 14 */
#define GPIO_INTSTATUS_PIN15_Msk              0x00008000             /*!< Interrupt status of pin 15 */

/*--  DMAREQSET: DMA request enable register ------------------------------------------------------------------*/
typedef struct {
  uint32_t PIN0                   :1;                                /*!< DMA request enable for pin 0 */
  uint32_t PIN1                   :1;                                /*!< DMA request enable for pin 1 */
  uint32_t PIN2                   :1;                                /*!< DMA request enable for pin 2 */
  uint32_t PIN3                   :1;                                /*!< DMA request enable for pin 3 */
  uint32_t PIN4                   :1;                                /*!< DMA request enable for pin 4 */
  uint32_t PIN5                   :1;                                /*!< DMA request enable for pin 5 */
  uint32_t PIN6                   :1;                                /*!< DMA request enable for pin 6 */
  uint32_t PIN7                   :1;                                /*!< DMA request enable for pin 7 */
  uint32_t PIN8                   :1;                                /*!< DMA request enable for pin 8 */
  uint32_t PIN9                   :1;                                /*!< DMA request enable for pin 9 */
  uint32_t PIN10                  :1;                                /*!< DMA request enable for pin 10 */
  uint32_t PIN11                  :1;                                /*!< DMA request enable for pin 11 */
  uint32_t PIN12                  :1;                                /*!< DMA request enable for pin 12 */
  uint32_t PIN13                  :1;                                /*!< DMA request enable for pin 13 */
  uint32_t PIN14                  :1;                                /*!< DMA request enable for pin 14 */
  uint32_t PIN15                  :1;                                /*!< DMA request enable for pin 15 */
} _GPIO_DMAREQSET_bits;

/* Bit field positions: */
#define GPIO_DMAREQSET_PIN0_Pos               0                      /*!< DMA request enable for pin 0 */
#define GPIO_DMAREQSET_PIN1_Pos               1                      /*!< DMA request enable for pin 1 */
#define GPIO_DMAREQSET_PIN2_Pos               2                      /*!< DMA request enable for pin 2 */
#define GPIO_DMAREQSET_PIN3_Pos               3                      /*!< DMA request enable for pin 3 */
#define GPIO_DMAREQSET_PIN4_Pos               4                      /*!< DMA request enable for pin 4 */
#define GPIO_DMAREQSET_PIN5_Pos               5                      /*!< DMA request enable for pin 5 */
#define GPIO_DMAREQSET_PIN6_Pos               6                      /*!< DMA request enable for pin 6 */
#define GPIO_DMAREQSET_PIN7_Pos               7                      /*!< DMA request enable for pin 7 */
#define GPIO_DMAREQSET_PIN8_Pos               8                      /*!< DMA request enable for pin 8 */
#define GPIO_DMAREQSET_PIN9_Pos               9                      /*!< DMA request enable for pin 9 */
#define GPIO_DMAREQSET_PIN10_Pos              10                     /*!< DMA request enable for pin 10 */
#define GPIO_DMAREQSET_PIN11_Pos              11                     /*!< DMA request enable for pin 11 */
#define GPIO_DMAREQSET_PIN12_Pos              12                     /*!< DMA request enable for pin 12 */
#define GPIO_DMAREQSET_PIN13_Pos              13                     /*!< DMA request enable for pin 13 */
#define GPIO_DMAREQSET_PIN14_Pos              14                     /*!< DMA request enable for pin 14 */
#define GPIO_DMAREQSET_PIN15_Pos              15                     /*!< DMA request enable for pin 15 */

/* Bit field masks: */
#define GPIO_DMAREQSET_PIN0_Msk               0x00000001             /*!< DMA request enable for pin 0 */
#define GPIO_DMAREQSET_PIN1_Msk               0x00000002             /*!< DMA request enable for pin 1 */
#define GPIO_DMAREQSET_PIN2_Msk               0x00000004             /*!< DMA request enable for pin 2 */
#define GPIO_DMAREQSET_PIN3_Msk               0x00000008             /*!< DMA request enable for pin 3 */
#define GPIO_DMAREQSET_PIN4_Msk               0x00000010             /*!< DMA request enable for pin 4 */
#define GPIO_DMAREQSET_PIN5_Msk               0x00000020             /*!< DMA request enable for pin 5 */
#define GPIO_DMAREQSET_PIN6_Msk               0x00000040             /*!< DMA request enable for pin 6 */
#define GPIO_DMAREQSET_PIN7_Msk               0x00000080             /*!< DMA request enable for pin 7 */
#define GPIO_DMAREQSET_PIN8_Msk               0x00000100             /*!< DMA request enable for pin 8 */
#define GPIO_DMAREQSET_PIN9_Msk               0x00000200             /*!< DMA request enable for pin 9 */
#define GPIO_DMAREQSET_PIN10_Msk              0x00000400             /*!< DMA request enable for pin 10 */
#define GPIO_DMAREQSET_PIN11_Msk              0x00000800             /*!< DMA request enable for pin 11 */
#define GPIO_DMAREQSET_PIN12_Msk              0x00001000             /*!< DMA request enable for pin 12 */
#define GPIO_DMAREQSET_PIN13_Msk              0x00002000             /*!< DMA request enable for pin 13 */
#define GPIO_DMAREQSET_PIN14_Msk              0x00004000             /*!< DMA request enable for pin 14 */
#define GPIO_DMAREQSET_PIN15_Msk              0x00008000             /*!< DMA request enable for pin 15 */

/*--  DMAREQCLR: DMA request disable register -----------------------------------------------------------------*/
typedef struct {
  uint32_t PIN0                   :1;                                /*!< DMA request disable for pin 0 */
  uint32_t PIN1                   :1;                                /*!< DMA request disable for pin 1 */
  uint32_t PIN2                   :1;                                /*!< DMA request disable for pin 2 */
  uint32_t PIN3                   :1;                                /*!< DMA request disable for pin 3 */
  uint32_t PIN4                   :1;                                /*!< DMA request disable for pin 4 */
  uint32_t PIN5                   :1;                                /*!< DMA request disable for pin 5 */
  uint32_t PIN6                   :1;                                /*!< DMA request disable for pin 6 */
  uint32_t PIN7                   :1;                                /*!< DMA request disable for pin 7 */
  uint32_t PIN8                   :1;                                /*!< DMA request disable for pin 8 */
  uint32_t PIN9                   :1;                                /*!< DMA request disable for pin 9 */
  uint32_t PIN10                  :1;                                /*!< DMA request disable for pin 10 */
  uint32_t PIN11                  :1;                                /*!< DMA request disable for pin 11 */
  uint32_t PIN12                  :1;                                /*!< DMA request disable for pin 12 */
  uint32_t PIN13                  :1;                                /*!< DMA request disable for pin 13 */
  uint32_t PIN14                  :1;                                /*!< DMA request disable for pin 14 */
  uint32_t PIN15                  :1;                                /*!< DMA request disable for pin 15 */
} _GPIO_DMAREQCLR_bits;

/* Bit field positions: */
#define GPIO_DMAREQCLR_PIN0_Pos               0                      /*!< DMA request disable for pin 0 */
#define GPIO_DMAREQCLR_PIN1_Pos               1                      /*!< DMA request disable for pin 1 */
#define GPIO_DMAREQCLR_PIN2_Pos               2                      /*!< DMA request disable for pin 2 */
#define GPIO_DMAREQCLR_PIN3_Pos               3                      /*!< DMA request disable for pin 3 */
#define GPIO_DMAREQCLR_PIN4_Pos               4                      /*!< DMA request disable for pin 4 */
#define GPIO_DMAREQCLR_PIN5_Pos               5                      /*!< DMA request disable for pin 5 */
#define GPIO_DMAREQCLR_PIN6_Pos               6                      /*!< DMA request disable for pin 6 */
#define GPIO_DMAREQCLR_PIN7_Pos               7                      /*!< DMA request disable for pin 7 */
#define GPIO_DMAREQCLR_PIN8_Pos               8                      /*!< DMA request disable for pin 8 */
#define GPIO_DMAREQCLR_PIN9_Pos               9                      /*!< DMA request disable for pin 9 */
#define GPIO_DMAREQCLR_PIN10_Pos              10                     /*!< DMA request disable for pin 10 */
#define GPIO_DMAREQCLR_PIN11_Pos              11                     /*!< DMA request disable for pin 11 */
#define GPIO_DMAREQCLR_PIN12_Pos              12                     /*!< DMA request disable for pin 12 */
#define GPIO_DMAREQCLR_PIN13_Pos              13                     /*!< DMA request disable for pin 13 */
#define GPIO_DMAREQCLR_PIN14_Pos              14                     /*!< DMA request disable for pin 14 */
#define GPIO_DMAREQCLR_PIN15_Pos              15                     /*!< DMA request disable for pin 15 */

/* Bit field masks: */
#define GPIO_DMAREQCLR_PIN0_Msk               0x00000001             /*!< DMA request disable for pin 0 */
#define GPIO_DMAREQCLR_PIN1_Msk               0x00000002             /*!< DMA request disable for pin 1 */
#define GPIO_DMAREQCLR_PIN2_Msk               0x00000004             /*!< DMA request disable for pin 2 */
#define GPIO_DMAREQCLR_PIN3_Msk               0x00000008             /*!< DMA request disable for pin 3 */
#define GPIO_DMAREQCLR_PIN4_Msk               0x00000010             /*!< DMA request disable for pin 4 */
#define GPIO_DMAREQCLR_PIN5_Msk               0x00000020             /*!< DMA request disable for pin 5 */
#define GPIO_DMAREQCLR_PIN6_Msk               0x00000040             /*!< DMA request disable for pin 6 */
#define GPIO_DMAREQCLR_PIN7_Msk               0x00000080             /*!< DMA request disable for pin 7 */
#define GPIO_DMAREQCLR_PIN8_Msk               0x00000100             /*!< DMA request disable for pin 8 */
#define GPIO_DMAREQCLR_PIN9_Msk               0x00000200             /*!< DMA request disable for pin 9 */
#define GPIO_DMAREQCLR_PIN10_Msk              0x00000400             /*!< DMA request disable for pin 10 */
#define GPIO_DMAREQCLR_PIN11_Msk              0x00000800             /*!< DMA request disable for pin 11 */
#define GPIO_DMAREQCLR_PIN12_Msk              0x00001000             /*!< DMA request disable for pin 12 */
#define GPIO_DMAREQCLR_PIN13_Msk              0x00002000             /*!< DMA request disable for pin 13 */
#define GPIO_DMAREQCLR_PIN14_Msk              0x00004000             /*!< DMA request disable for pin 14 */
#define GPIO_DMAREQCLR_PIN15_Msk              0x00008000             /*!< DMA request disable for pin 15 */

/*--  ADCSOCSET: ADC Start Of Conversion enable register ------------------------------------------------------*/
typedef struct {
  uint32_t PIN0                   :1;                                /*!< ADC SOC enable for pin 0 */
  uint32_t PIN1                   :1;                                /*!< ADC SOC enable for pin 1 */
  uint32_t PIN2                   :1;                                /*!< ADC SOC enable for pin 2 */
  uint32_t PIN3                   :1;                                /*!< ADC SOC enable for pin 3 */
  uint32_t PIN4                   :1;                                /*!< ADC SOC enable for pin 4 */
  uint32_t PIN5                   :1;                                /*!< ADC SOC enable for pin 5 */
  uint32_t PIN6                   :1;                                /*!< ADC SOC enable for pin 6 */
  uint32_t PIN7                   :1;                                /*!< ADC SOC enable for pin 7 */
  uint32_t PIN8                   :1;                                /*!< ADC SOC enable for pin 8 */
  uint32_t PIN9                   :1;                                /*!< ADC SOC enable for pin 9 */
  uint32_t PIN10                  :1;                                /*!< ADC SOC enable for pin 10 */
  uint32_t PIN11                  :1;                                /*!< ADC SOC enable for pin 11 */
  uint32_t PIN12                  :1;                                /*!< ADC SOC enable for pin 12 */
  uint32_t PIN13                  :1;                                /*!< ADC SOC enable for pin 13 */
  uint32_t PIN14                  :1;                                /*!< ADC SOC enable for pin 14 */
  uint32_t PIN15                  :1;                                /*!< ADC SOC enable for pin 15 */
} _GPIO_ADCSOCSET_bits;

/* Bit field positions: */
#define GPIO_ADCSOCSET_PIN0_Pos               0                      /*!< ADC SOC enable for pin 0 */
#define GPIO_ADCSOCSET_PIN1_Pos               1                      /*!< ADC SOC enable for pin 1 */
#define GPIO_ADCSOCSET_PIN2_Pos               2                      /*!< ADC SOC enable for pin 2 */
#define GPIO_ADCSOCSET_PIN3_Pos               3                      /*!< ADC SOC enable for pin 3 */
#define GPIO_ADCSOCSET_PIN4_Pos               4                      /*!< ADC SOC enable for pin 4 */
#define GPIO_ADCSOCSET_PIN5_Pos               5                      /*!< ADC SOC enable for pin 5 */
#define GPIO_ADCSOCSET_PIN6_Pos               6                      /*!< ADC SOC enable for pin 6 */
#define GPIO_ADCSOCSET_PIN7_Pos               7                      /*!< ADC SOC enable for pin 7 */
#define GPIO_ADCSOCSET_PIN8_Pos               8                      /*!< ADC SOC enable for pin 8 */
#define GPIO_ADCSOCSET_PIN9_Pos               9                      /*!< ADC SOC enable for pin 9 */
#define GPIO_ADCSOCSET_PIN10_Pos              10                     /*!< ADC SOC enable for pin 10 */
#define GPIO_ADCSOCSET_PIN11_Pos              11                     /*!< ADC SOC enable for pin 11 */
#define GPIO_ADCSOCSET_PIN12_Pos              12                     /*!< ADC SOC enable for pin 12 */
#define GPIO_ADCSOCSET_PIN13_Pos              13                     /*!< ADC SOC enable for pin 13 */
#define GPIO_ADCSOCSET_PIN14_Pos              14                     /*!< ADC SOC enable for pin 14 */
#define GPIO_ADCSOCSET_PIN15_Pos              15                     /*!< ADC SOC enable for pin 15 */

/* Bit field masks: */
#define GPIO_ADCSOCSET_PIN0_Msk               0x00000001             /*!< ADC SOC enable for pin 0 */
#define GPIO_ADCSOCSET_PIN1_Msk               0x00000002             /*!< ADC SOC enable for pin 1 */
#define GPIO_ADCSOCSET_PIN2_Msk               0x00000004             /*!< ADC SOC enable for pin 2 */
#define GPIO_ADCSOCSET_PIN3_Msk               0x00000008             /*!< ADC SOC enable for pin 3 */
#define GPIO_ADCSOCSET_PIN4_Msk               0x00000010             /*!< ADC SOC enable for pin 4 */
#define GPIO_ADCSOCSET_PIN5_Msk               0x00000020             /*!< ADC SOC enable for pin 5 */
#define GPIO_ADCSOCSET_PIN6_Msk               0x00000040             /*!< ADC SOC enable for pin 6 */
#define GPIO_ADCSOCSET_PIN7_Msk               0x00000080             /*!< ADC SOC enable for pin 7 */
#define GPIO_ADCSOCSET_PIN8_Msk               0x00000100             /*!< ADC SOC enable for pin 8 */
#define GPIO_ADCSOCSET_PIN9_Msk               0x00000200             /*!< ADC SOC enable for pin 9 */
#define GPIO_ADCSOCSET_PIN10_Msk              0x00000400             /*!< ADC SOC enable for pin 10 */
#define GPIO_ADCSOCSET_PIN11_Msk              0x00000800             /*!< ADC SOC enable for pin 11 */
#define GPIO_ADCSOCSET_PIN12_Msk              0x00001000             /*!< ADC SOC enable for pin 12 */
#define GPIO_ADCSOCSET_PIN13_Msk              0x00002000             /*!< ADC SOC enable for pin 13 */
#define GPIO_ADCSOCSET_PIN14_Msk              0x00004000             /*!< ADC SOC enable for pin 14 */
#define GPIO_ADCSOCSET_PIN15_Msk              0x00008000             /*!< ADC SOC enable for pin 15 */

/*--  ADCSOCCLR: ADC Start Of Conversion disable register -----------------------------------------------------*/
typedef struct {
  uint32_t PIN0                   :1;                                /*!< ADC SOC disable for pin 0 */
  uint32_t PIN1                   :1;                                /*!< ADC SOC disable for pin 1 */
  uint32_t PIN2                   :1;                                /*!< ADC SOC disable for pin 2 */
  uint32_t PIN3                   :1;                                /*!< ADC SOC disable for pin 3 */
  uint32_t PIN4                   :1;                                /*!< ADC SOC disable for pin 4 */
  uint32_t PIN5                   :1;                                /*!< ADC SOC disable for pin 5 */
  uint32_t PIN6                   :1;                                /*!< ADC SOC disable for pin 6 */
  uint32_t PIN7                   :1;                                /*!< ADC SOC disable for pin 7 */
  uint32_t PIN8                   :1;                                /*!< ADC SOC disable for pin 8 */
  uint32_t PIN9                   :1;                                /*!< ADC SOC disable for pin 9 */
  uint32_t PIN10                  :1;                                /*!< ADC SOC disable for pin 10 */
  uint32_t PIN11                  :1;                                /*!< ADC SOC disable for pin 11 */
  uint32_t PIN12                  :1;                                /*!< ADC SOC disable for pin 12 */
  uint32_t PIN13                  :1;                                /*!< ADC SOC disable for pin 13 */
  uint32_t PIN14                  :1;                                /*!< ADC SOC disable for pin 14 */
  uint32_t PIN15                  :1;                                /*!< ADC SOC disable for pin 15 */
} _GPIO_ADCSOCCLR_bits;

/* Bit field positions: */
#define GPIO_ADCSOCCLR_PIN0_Pos               0                      /*!< ADC SOC disable for pin 0 */
#define GPIO_ADCSOCCLR_PIN1_Pos               1                      /*!< ADC SOC disable for pin 1 */
#define GPIO_ADCSOCCLR_PIN2_Pos               2                      /*!< ADC SOC disable for pin 2 */
#define GPIO_ADCSOCCLR_PIN3_Pos               3                      /*!< ADC SOC disable for pin 3 */
#define GPIO_ADCSOCCLR_PIN4_Pos               4                      /*!< ADC SOC disable for pin 4 */
#define GPIO_ADCSOCCLR_PIN5_Pos               5                      /*!< ADC SOC disable for pin 5 */
#define GPIO_ADCSOCCLR_PIN6_Pos               6                      /*!< ADC SOC disable for pin 6 */
#define GPIO_ADCSOCCLR_PIN7_Pos               7                      /*!< ADC SOC disable for pin 7 */
#define GPIO_ADCSOCCLR_PIN8_Pos               8                      /*!< ADC SOC disable for pin 8 */
#define GPIO_ADCSOCCLR_PIN9_Pos               9                      /*!< ADC SOC disable for pin 9 */
#define GPIO_ADCSOCCLR_PIN10_Pos              10                     /*!< ADC SOC disable for pin 10 */
#define GPIO_ADCSOCCLR_PIN11_Pos              11                     /*!< ADC SOC disable for pin 11 */
#define GPIO_ADCSOCCLR_PIN12_Pos              12                     /*!< ADC SOC disable for pin 12 */
#define GPIO_ADCSOCCLR_PIN13_Pos              13                     /*!< ADC SOC disable for pin 13 */
#define GPIO_ADCSOCCLR_PIN14_Pos              14                     /*!< ADC SOC disable for pin 14 */
#define GPIO_ADCSOCCLR_PIN15_Pos              15                     /*!< ADC SOC disable for pin 15 */

/* Bit field masks: */
#define GPIO_ADCSOCCLR_PIN0_Msk               0x00000001             /*!< ADC SOC disable for pin 0 */
#define GPIO_ADCSOCCLR_PIN1_Msk               0x00000002             /*!< ADC SOC disable for pin 1 */
#define GPIO_ADCSOCCLR_PIN2_Msk               0x00000004             /*!< ADC SOC disable for pin 2 */
#define GPIO_ADCSOCCLR_PIN3_Msk               0x00000008             /*!< ADC SOC disable for pin 3 */
#define GPIO_ADCSOCCLR_PIN4_Msk               0x00000010             /*!< ADC SOC disable for pin 4 */
#define GPIO_ADCSOCCLR_PIN5_Msk               0x00000020             /*!< ADC SOC disable for pin 5 */
#define GPIO_ADCSOCCLR_PIN6_Msk               0x00000040             /*!< ADC SOC disable for pin 6 */
#define GPIO_ADCSOCCLR_PIN7_Msk               0x00000080             /*!< ADC SOC disable for pin 7 */
#define GPIO_ADCSOCCLR_PIN8_Msk               0x00000100             /*!< ADC SOC disable for pin 8 */
#define GPIO_ADCSOCCLR_PIN9_Msk               0x00000200             /*!< ADC SOC disable for pin 9 */
#define GPIO_ADCSOCCLR_PIN10_Msk              0x00000400             /*!< ADC SOC disable for pin 10 */
#define GPIO_ADCSOCCLR_PIN11_Msk              0x00000800             /*!< ADC SOC disable for pin 11 */
#define GPIO_ADCSOCCLR_PIN12_Msk              0x00001000             /*!< ADC SOC disable for pin 12 */
#define GPIO_ADCSOCCLR_PIN13_Msk              0x00002000             /*!< ADC SOC disable for pin 13 */
#define GPIO_ADCSOCCLR_PIN14_Msk              0x00004000             /*!< ADC SOC disable for pin 14 */
#define GPIO_ADCSOCCLR_PIN15_Msk              0x00008000             /*!< ADC SOC disable for pin 15 */

/*--  RXEVSET: Core RXEV request enable register --------------------------------------------------------------*/
typedef struct {
  uint32_t PIN0                   :1;                                /*!< RXEV enable for pin 0 */
  uint32_t PIN1                   :1;                                /*!< RXEV enable for pin 1 */
  uint32_t PIN2                   :1;                                /*!< RXEV enable for pin 2 */
  uint32_t PIN3                   :1;                                /*!< RXEV enable for pin 3 */
  uint32_t PIN4                   :1;                                /*!< RXEV enable for pin 4 */
  uint32_t PIN5                   :1;                                /*!< RXEV enable for pin 5 */
  uint32_t PIN6                   :1;                                /*!< RXEV enable for pin 6 */
  uint32_t PIN7                   :1;                                /*!< RXEV enable for pin 7 */
  uint32_t PIN8                   :1;                                /*!< RXEV enable for pin 8 */
  uint32_t PIN9                   :1;                                /*!< RXEV enable for pin 9 */
  uint32_t PIN10                  :1;                                /*!< RXEV enable for pin 10 */
  uint32_t PIN11                  :1;                                /*!< RXEV enable for pin 11 */
  uint32_t PIN12                  :1;                                /*!< RXEV enable for pin 12 */
  uint32_t PIN13                  :1;                                /*!< RXEV enable for pin 13 */
  uint32_t PIN14                  :1;                                /*!< RXEV enable for pin 14 */
  uint32_t PIN15                  :1;                                /*!< RXEV enable for pin 15 */
} _GPIO_RXEVSET_bits;

/* Bit field positions: */
#define GPIO_RXEVSET_PIN0_Pos                 0                      /*!< RXEV enable for pin 0 */
#define GPIO_RXEVSET_PIN1_Pos                 1                      /*!< RXEV enable for pin 1 */
#define GPIO_RXEVSET_PIN2_Pos                 2                      /*!< RXEV enable for pin 2 */
#define GPIO_RXEVSET_PIN3_Pos                 3                      /*!< RXEV enable for pin 3 */
#define GPIO_RXEVSET_PIN4_Pos                 4                      /*!< RXEV enable for pin 4 */
#define GPIO_RXEVSET_PIN5_Pos                 5                      /*!< RXEV enable for pin 5 */
#define GPIO_RXEVSET_PIN6_Pos                 6                      /*!< RXEV enable for pin 6 */
#define GPIO_RXEVSET_PIN7_Pos                 7                      /*!< RXEV enable for pin 7 */
#define GPIO_RXEVSET_PIN8_Pos                 8                      /*!< RXEV enable for pin 8 */
#define GPIO_RXEVSET_PIN9_Pos                 9                      /*!< RXEV enable for pin 9 */
#define GPIO_RXEVSET_PIN10_Pos                10                     /*!< RXEV enable for pin 10 */
#define GPIO_RXEVSET_PIN11_Pos                11                     /*!< RXEV enable for pin 11 */
#define GPIO_RXEVSET_PIN12_Pos                12                     /*!< RXEV enable for pin 12 */
#define GPIO_RXEVSET_PIN13_Pos                13                     /*!< RXEV enable for pin 13 */
#define GPIO_RXEVSET_PIN14_Pos                14                     /*!< RXEV enable for pin 14 */
#define GPIO_RXEVSET_PIN15_Pos                15                     /*!< RXEV enable for pin 15 */

/* Bit field masks: */
#define GPIO_RXEVSET_PIN0_Msk                 0x00000001             /*!< RXEV enable for pin 0 */
#define GPIO_RXEVSET_PIN1_Msk                 0x00000002             /*!< RXEV enable for pin 1 */
#define GPIO_RXEVSET_PIN2_Msk                 0x00000004             /*!< RXEV enable for pin 2 */
#define GPIO_RXEVSET_PIN3_Msk                 0x00000008             /*!< RXEV enable for pin 3 */
#define GPIO_RXEVSET_PIN4_Msk                 0x00000010             /*!< RXEV enable for pin 4 */
#define GPIO_RXEVSET_PIN5_Msk                 0x00000020             /*!< RXEV enable for pin 5 */
#define GPIO_RXEVSET_PIN6_Msk                 0x00000040             /*!< RXEV enable for pin 6 */
#define GPIO_RXEVSET_PIN7_Msk                 0x00000080             /*!< RXEV enable for pin 7 */
#define GPIO_RXEVSET_PIN8_Msk                 0x00000100             /*!< RXEV enable for pin 8 */
#define GPIO_RXEVSET_PIN9_Msk                 0x00000200             /*!< RXEV enable for pin 9 */
#define GPIO_RXEVSET_PIN10_Msk                0x00000400             /*!< RXEV enable for pin 10 */
#define GPIO_RXEVSET_PIN11_Msk                0x00000800             /*!< RXEV enable for pin 11 */
#define GPIO_RXEVSET_PIN12_Msk                0x00001000             /*!< RXEV enable for pin 12 */
#define GPIO_RXEVSET_PIN13_Msk                0x00002000             /*!< RXEV enable for pin 13 */
#define GPIO_RXEVSET_PIN14_Msk                0x00004000             /*!< RXEV enable for pin 14 */
#define GPIO_RXEVSET_PIN15_Msk                0x00008000             /*!< RXEV enable for pin 15 */

/*--  RXEVCLR: Core RXEV request disable register -------------------------------------------------------------*/
typedef struct {
  uint32_t PIN0                   :1;                                /*!< RXEV disable for pin 0 */
  uint32_t PIN1                   :1;                                /*!< RXEV disable for pin 1 */
  uint32_t PIN2                   :1;                                /*!< RXEV disable for pin 2 */
  uint32_t PIN3                   :1;                                /*!< RXEV disable for pin 3 */
  uint32_t PIN4                   :1;                                /*!< RXEV disable for pin 4 */
  uint32_t PIN5                   :1;                                /*!< RXEV disable for pin 5 */
  uint32_t PIN6                   :1;                                /*!< RXEV disable for pin 6 */
  uint32_t PIN7                   :1;                                /*!< RXEV disable for pin 7 */
  uint32_t PIN8                   :1;                                /*!< RXEV disable for pin 8 */
  uint32_t PIN9                   :1;                                /*!< RXEV disable for pin 9 */
  uint32_t PIN10                  :1;                                /*!< RXEV disable for pin 10 */
  uint32_t PIN11                  :1;                                /*!< RXEV disable for pin 11 */
  uint32_t PIN12                  :1;                                /*!< RXEV disable for pin 12 */
  uint32_t PIN13                  :1;                                /*!< RXEV disable for pin 13 */
  uint32_t PIN14                  :1;                                /*!< RXEV disable for pin 14 */
  uint32_t PIN15                  :1;                                /*!< RXEV disable for pin 15 */
} _GPIO_RXEVCLR_bits;

/* Bit field positions: */
#define GPIO_RXEVCLR_PIN0_Pos                 0                      /*!< RXEV disable for pin 0 */
#define GPIO_RXEVCLR_PIN1_Pos                 1                      /*!< RXEV disable for pin 1 */
#define GPIO_RXEVCLR_PIN2_Pos                 2                      /*!< RXEV disable for pin 2 */
#define GPIO_RXEVCLR_PIN3_Pos                 3                      /*!< RXEV disable for pin 3 */
#define GPIO_RXEVCLR_PIN4_Pos                 4                      /*!< RXEV disable for pin 4 */
#define GPIO_RXEVCLR_PIN5_Pos                 5                      /*!< RXEV disable for pin 5 */
#define GPIO_RXEVCLR_PIN6_Pos                 6                      /*!< RXEV disable for pin 6 */
#define GPIO_RXEVCLR_PIN7_Pos                 7                      /*!< RXEV disable for pin 7 */
#define GPIO_RXEVCLR_PIN8_Pos                 8                      /*!< RXEV disable for pin 8 */
#define GPIO_RXEVCLR_PIN9_Pos                 9                      /*!< RXEV disable for pin 9 */
#define GPIO_RXEVCLR_PIN10_Pos                10                     /*!< RXEV disable for pin 10 */
#define GPIO_RXEVCLR_PIN11_Pos                11                     /*!< RXEV disable for pin 11 */
#define GPIO_RXEVCLR_PIN12_Pos                12                     /*!< RXEV disable for pin 12 */
#define GPIO_RXEVCLR_PIN13_Pos                13                     /*!< RXEV disable for pin 13 */
#define GPIO_RXEVCLR_PIN14_Pos                14                     /*!< RXEV disable for pin 14 */
#define GPIO_RXEVCLR_PIN15_Pos                15                     /*!< RXEV disable for pin 15 */

/* Bit field masks: */
#define GPIO_RXEVCLR_PIN0_Msk                 0x00000001             /*!< RXEV disable for pin 0 */
#define GPIO_RXEVCLR_PIN1_Msk                 0x00000002             /*!< RXEV disable for pin 1 */
#define GPIO_RXEVCLR_PIN2_Msk                 0x00000004             /*!< RXEV disable for pin 2 */
#define GPIO_RXEVCLR_PIN3_Msk                 0x00000008             /*!< RXEV disable for pin 3 */
#define GPIO_RXEVCLR_PIN4_Msk                 0x00000010             /*!< RXEV disable for pin 4 */
#define GPIO_RXEVCLR_PIN5_Msk                 0x00000020             /*!< RXEV disable for pin 5 */
#define GPIO_RXEVCLR_PIN6_Msk                 0x00000040             /*!< RXEV disable for pin 6 */
#define GPIO_RXEVCLR_PIN7_Msk                 0x00000080             /*!< RXEV disable for pin 7 */
#define GPIO_RXEVCLR_PIN8_Msk                 0x00000100             /*!< RXEV disable for pin 8 */
#define GPIO_RXEVCLR_PIN9_Msk                 0x00000200             /*!< RXEV disable for pin 9 */
#define GPIO_RXEVCLR_PIN10_Msk                0x00000400             /*!< RXEV disable for pin 10 */
#define GPIO_RXEVCLR_PIN11_Msk                0x00000800             /*!< RXEV disable for pin 11 */
#define GPIO_RXEVCLR_PIN12_Msk                0x00001000             /*!< RXEV disable for pin 12 */
#define GPIO_RXEVCLR_PIN13_Msk                0x00002000             /*!< RXEV disable for pin 13 */
#define GPIO_RXEVCLR_PIN14_Msk                0x00004000             /*!< RXEV disable for pin 14 */
#define GPIO_RXEVCLR_PIN15_Msk                0x00008000             /*!< RXEV disable for pin 15 */

/*--  LOCKKEY: Key register to unlock LOCKSET/LOCKCLR registers for write (KEY=0xADEADBEE) --------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!<  Key to unlock LOCKSET/LOCKCLR registers for write (KEY=0xADEADBEE) */
} _GPIO_LOCKKEY_bits;

/* Bit field positions: */
#define GPIO_LOCKKEY_VAL_Pos                  0                      /*!<  Key to unlock LOCKSET/LOCKCLR registers for write (KEY=0xADEADBEE) */

/* Bit field masks: */
#define GPIO_LOCKKEY_VAL_Msk                  0xFFFFFFFF             /*!<  Key to unlock LOCKSET/LOCKCLR registers for write (KEY=0xADEADBEE) */

/* Bit field enums: */
typedef enum {
  GPIO_LOCKKEY_VAL_LOCK                      = -286331154,  			   /*!< 0xEEEEEEEE, key to lock registers */
  GPIO_LOCKKEY_VAL_UNLOCK                    = -1377117202, 			   /*!< 0xADEADBEE, key to unlock registers */
} GPIO_LOCKKEY_VAL_Enum;

/*--  LOCKSTAT: LOCKSET/LOCKCLR write enable status register --------------------------------------------------*/
typedef struct {
  uint32_t WREN                   :1;                                /*!< LOCKSET/LOCKCLR write enable  status */
} _GPIO_LOCKSTAT_bits;

/* Bit field positions: */
#define GPIO_LOCKSTAT_WREN_Pos                0                      /*!< LOCKSET/LOCKCLR write enable  status */

/* Bit field masks: */
#define GPIO_LOCKSTAT_WREN_Msk                0x00000001             /*!< LOCKSET/LOCKCLR write enable  status */

/*--  LOCKSET: Lock pins configuration enable register --------------------------------------------------------*/
typedef struct {
  uint32_t PIN0                   :1;                                /*!< Lock configuration enable for pin 0 */
  uint32_t PIN1                   :1;                                /*!< Lock configuration enable for pin 1 */
  uint32_t PIN2                   :1;                                /*!< Lock configuration enable for pin 2 */
  uint32_t PIN3                   :1;                                /*!< Lock configuration enable for pin 3 */
  uint32_t PIN4                   :1;                                /*!< Lock configuration enable for pin 4 */
  uint32_t PIN5                   :1;                                /*!< Lock configuration enable for pin 5 */
  uint32_t PIN6                   :1;                                /*!< Lock configuration enable for pin 6 */
  uint32_t PIN7                   :1;                                /*!< Lock configuration enable for pin 7 */
  uint32_t PIN8                   :1;                                /*!< Lock configuration enable for pin 8 */
  uint32_t PIN9                   :1;                                /*!< Lock configuration enable for pin 9 */
  uint32_t PIN10                  :1;                                /*!< Lock configuration enable for pin 10 */
  uint32_t PIN11                  :1;                                /*!< Lock configuration enable for pin 11 */
  uint32_t PIN12                  :1;                                /*!< Lock configuration enable for pin 12 */
  uint32_t PIN13                  :1;                                /*!< Lock configuration enable for pin 13 */
  uint32_t PIN14                  :1;                                /*!< Lock configuration enable for pin 14 */
  uint32_t PIN15                  :1;                                /*!< Lock configuration enable for pin 15 */
} _GPIO_LOCKSET_bits;

/* Bit field positions: */
#define GPIO_LOCKSET_PIN0_Pos                 0                      /*!< Lock configuration enable for pin 0 */
#define GPIO_LOCKSET_PIN1_Pos                 1                      /*!< Lock configuration enable for pin 1 */
#define GPIO_LOCKSET_PIN2_Pos                 2                      /*!< Lock configuration enable for pin 2 */
#define GPIO_LOCKSET_PIN3_Pos                 3                      /*!< Lock configuration enable for pin 3 */
#define GPIO_LOCKSET_PIN4_Pos                 4                      /*!< Lock configuration enable for pin 4 */
#define GPIO_LOCKSET_PIN5_Pos                 5                      /*!< Lock configuration enable for pin 5 */
#define GPIO_LOCKSET_PIN6_Pos                 6                      /*!< Lock configuration enable for pin 6 */
#define GPIO_LOCKSET_PIN7_Pos                 7                      /*!< Lock configuration enable for pin 7 */
#define GPIO_LOCKSET_PIN8_Pos                 8                      /*!< Lock configuration enable for pin 8 */
#define GPIO_LOCKSET_PIN9_Pos                 9                      /*!< Lock configuration enable for pin 9 */
#define GPIO_LOCKSET_PIN10_Pos                10                     /*!< Lock configuration enable for pin 10 */
#define GPIO_LOCKSET_PIN11_Pos                11                     /*!< Lock configuration enable for pin 11 */
#define GPIO_LOCKSET_PIN12_Pos                12                     /*!< Lock configuration enable for pin 12 */
#define GPIO_LOCKSET_PIN13_Pos                13                     /*!< Lock configuration enable for pin 13 */
#define GPIO_LOCKSET_PIN14_Pos                14                     /*!< Lock configuration enable for pin 14 */
#define GPIO_LOCKSET_PIN15_Pos                15                     /*!< Lock configuration enable for pin 15 */

/* Bit field masks: */
#define GPIO_LOCKSET_PIN0_Msk                 0x00000001             /*!< Lock configuration enable for pin 0 */
#define GPIO_LOCKSET_PIN1_Msk                 0x00000002             /*!< Lock configuration enable for pin 1 */
#define GPIO_LOCKSET_PIN2_Msk                 0x00000004             /*!< Lock configuration enable for pin 2 */
#define GPIO_LOCKSET_PIN3_Msk                 0x00000008             /*!< Lock configuration enable for pin 3 */
#define GPIO_LOCKSET_PIN4_Msk                 0x00000010             /*!< Lock configuration enable for pin 4 */
#define GPIO_LOCKSET_PIN5_Msk                 0x00000020             /*!< Lock configuration enable for pin 5 */
#define GPIO_LOCKSET_PIN6_Msk                 0x00000040             /*!< Lock configuration enable for pin 6 */
#define GPIO_LOCKSET_PIN7_Msk                 0x00000080             /*!< Lock configuration enable for pin 7 */
#define GPIO_LOCKSET_PIN8_Msk                 0x00000100             /*!< Lock configuration enable for pin 8 */
#define GPIO_LOCKSET_PIN9_Msk                 0x00000200             /*!< Lock configuration enable for pin 9 */
#define GPIO_LOCKSET_PIN10_Msk                0x00000400             /*!< Lock configuration enable for pin 10 */
#define GPIO_LOCKSET_PIN11_Msk                0x00000800             /*!< Lock configuration enable for pin 11 */
#define GPIO_LOCKSET_PIN12_Msk                0x00001000             /*!< Lock configuration enable for pin 12 */
#define GPIO_LOCKSET_PIN13_Msk                0x00002000             /*!< Lock configuration enable for pin 13 */
#define GPIO_LOCKSET_PIN14_Msk                0x00004000             /*!< Lock configuration enable for pin 14 */
#define GPIO_LOCKSET_PIN15_Msk                0x00008000             /*!< Lock configuration enable for pin 15 */

/*--  LOCKCLR: Lock pins configuration disable register -------------------------------------------------------*/
typedef struct {
  uint32_t PIN0                   :1;                                /*!< Lock configuration disable for pin 0 */
  uint32_t PIN1                   :1;                                /*!< Lock configuration disable for pin 1 */
  uint32_t PIN2                   :1;                                /*!< Lock configuration disable for pin 2 */
  uint32_t PIN3                   :1;                                /*!< Lock configuration disable for pin 3 */
  uint32_t PIN4                   :1;                                /*!< Lock configuration disable for pin 4 */
  uint32_t PIN5                   :1;                                /*!< Lock configuration disable for pin 5 */
  uint32_t PIN6                   :1;                                /*!< Lock configuration disable for pin 6 */
  uint32_t PIN7                   :1;                                /*!< Lock configuration disable for pin 7 */
  uint32_t PIN8                   :1;                                /*!< Lock configuration disable for pin 8 */
  uint32_t PIN9                   :1;                                /*!< Lock configuration disable for pin 9 */
  uint32_t PIN10                  :1;                                /*!< Lock configuration disable for pin 10 */
  uint32_t PIN11                  :1;                                /*!< Lock configuration disable for pin 11 */
  uint32_t PIN12                  :1;                                /*!< Lock configuration disable for pin 12 */
  uint32_t PIN13                  :1;                                /*!< Lock configuration disable for pin 13 */
  uint32_t PIN14                  :1;                                /*!< Lock configuration disable for pin 14 */
  uint32_t PIN15                  :1;                                /*!< Lock configuration disable for pin 15 */
} _GPIO_LOCKCLR_bits;

/* Bit field positions: */
#define GPIO_LOCKCLR_PIN0_Pos                 0                      /*!< Lock configuration disable for pin 0 */
#define GPIO_LOCKCLR_PIN1_Pos                 1                      /*!< Lock configuration disable for pin 1 */
#define GPIO_LOCKCLR_PIN2_Pos                 2                      /*!< Lock configuration disable for pin 2 */
#define GPIO_LOCKCLR_PIN3_Pos                 3                      /*!< Lock configuration disable for pin 3 */
#define GPIO_LOCKCLR_PIN4_Pos                 4                      /*!< Lock configuration disable for pin 4 */
#define GPIO_LOCKCLR_PIN5_Pos                 5                      /*!< Lock configuration disable for pin 5 */
#define GPIO_LOCKCLR_PIN6_Pos                 6                      /*!< Lock configuration disable for pin 6 */
#define GPIO_LOCKCLR_PIN7_Pos                 7                      /*!< Lock configuration disable for pin 7 */
#define GPIO_LOCKCLR_PIN8_Pos                 8                      /*!< Lock configuration disable for pin 8 */
#define GPIO_LOCKCLR_PIN9_Pos                 9                      /*!< Lock configuration disable for pin 9 */
#define GPIO_LOCKCLR_PIN10_Pos                10                     /*!< Lock configuration disable for pin 10 */
#define GPIO_LOCKCLR_PIN11_Pos                11                     /*!< Lock configuration disable for pin 11 */
#define GPIO_LOCKCLR_PIN12_Pos                12                     /*!< Lock configuration disable for pin 12 */
#define GPIO_LOCKCLR_PIN13_Pos                13                     /*!< Lock configuration disable for pin 13 */
#define GPIO_LOCKCLR_PIN14_Pos                14                     /*!< Lock configuration disable for pin 14 */
#define GPIO_LOCKCLR_PIN15_Pos                15                     /*!< Lock configuration disable for pin 15 */

/* Bit field masks: */
#define GPIO_LOCKCLR_PIN0_Msk                 0x00000001             /*!< Lock configuration disable for pin 0 */
#define GPIO_LOCKCLR_PIN1_Msk                 0x00000002             /*!< Lock configuration disable for pin 1 */
#define GPIO_LOCKCLR_PIN2_Msk                 0x00000004             /*!< Lock configuration disable for pin 2 */
#define GPIO_LOCKCLR_PIN3_Msk                 0x00000008             /*!< Lock configuration disable for pin 3 */
#define GPIO_LOCKCLR_PIN4_Msk                 0x00000010             /*!< Lock configuration disable for pin 4 */
#define GPIO_LOCKCLR_PIN5_Msk                 0x00000020             /*!< Lock configuration disable for pin 5 */
#define GPIO_LOCKCLR_PIN6_Msk                 0x00000040             /*!< Lock configuration disable for pin 6 */
#define GPIO_LOCKCLR_PIN7_Msk                 0x00000080             /*!< Lock configuration disable for pin 7 */
#define GPIO_LOCKCLR_PIN8_Msk                 0x00000100             /*!< Lock configuration disable for pin 8 */
#define GPIO_LOCKCLR_PIN9_Msk                 0x00000200             /*!< Lock configuration disable for pin 9 */
#define GPIO_LOCKCLR_PIN10_Msk                0x00000400             /*!< Lock configuration disable for pin 10 */
#define GPIO_LOCKCLR_PIN11_Msk                0x00000800             /*!< Lock configuration disable for pin 11 */
#define GPIO_LOCKCLR_PIN12_Msk                0x00001000             /*!< Lock configuration disable for pin 12 */
#define GPIO_LOCKCLR_PIN13_Msk                0x00002000             /*!< Lock configuration disable for pin 13 */
#define GPIO_LOCKCLR_PIN14_Msk                0x00004000             /*!< Lock configuration disable for pin 14 */
#define GPIO_LOCKCLR_PIN15_Msk                0x00008000             /*!< Lock configuration disable for pin 15 */

/*-- MASKLB: MASKLB: Mask register low byte of port -----------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :8;                                /*!< Mask low byte */
} _GPIO_MASKLB_MASKLB_bits;

/* Bit field positions: */
#define GPIO_MASKLB_MASKLB_VAL_Pos            0                      /*!< Mask low byte */

/* Bit field masks: */
#define GPIO_MASKLB_MASKLB_VAL_Msk            0x000000FF             /*!< Mask low byte */

/*-- MASKHB: MASKHB: Mask register High byte of port ----------------------------------------------------------*/
typedef struct {
  uint32_t                        :8;                                /*!< RESERVED */
  uint32_t VAL                    :8;                                /*!< Mask high byte */
} _GPIO_MASKHB_MASKHB_bits;

/* Bit field positions: */
#define GPIO_MASKHB_MASKHB_VAL_Pos            8                      /*!< Mask high byte */

/* Bit field masks: */
#define GPIO_MASKHB_MASKHB_VAL_Msk            0x0000FF00             /*!< Mask high byte */

//Cluster MASKLB:
typedef struct {
  union { 
  /*!< Mask register low byte of port */
    __IO uint32_t MASKLB;                                            /*!< MASKLB : type used for word access */
    __IO _GPIO_MASKLB_MASKLB_bits MASKLB_bit;                        /*!< MASKLB_bit: structure used for bit access */
  };
} _GPIO_MASKLB_TypeDef;
//Cluster MASKHB:
typedef struct {
  union { 
  /*!< Mask register High byte of port */
    __IO uint32_t MASKHB;                                            /*!< MASKHB : type used for word access */
    __IO _GPIO_MASKHB_MASKHB_bits MASKHB_bit;                        /*!< MASKHB_bit: structure used for bit access */
  };
} _GPIO_MASKHB_TypeDef;
typedef struct {
  union {                                                               /*!< Data Input register */
    __IO uint32_t DATA;                                              /*!< DATA    : type used for word access */
    __IO _GPIO_DATA_bits  DATA_bit;                                  /*!< DATA_bit: structure used for bit access */
  };
  union {                                                               /*!< Data output register */
    __IO uint32_t DATAOUT;                                           /*!< DATAOUT    : type used for word access */
    __IO _GPIO_DATAOUT_bits  DATAOUT_bit;                            /*!< DATAOUT_bit: structure used for bit access */
  };
  union {                                                               /*!< Data output set bits register */
    __IO uint32_t DATAOUTSET;                                           /*!< DATAOUTSET    : type used for word access */
    __IO _GPIO_DATAOUTSET_bits  DATAOUTSET_bit;                      /*!< DATAOUTSET_bit: structure used for bit access */
  };
  union {                                                               /*!< Data output clear bits register */
    __IO uint32_t DATAOUTCLR;                                           /*!< DATAOUTCLR    : type used for word access */
    __IO _GPIO_DATAOUTCLR_bits  DATAOUTCLR_bit;                      /*!< DATAOUTCLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Data output toogle bits register */
    __IO uint32_t DATAOUTTGL;                                           /*!< DATAOUTTGL    : type used for word access */
    __IO _GPIO_DATAOUTTGL_bits  DATAOUTTGL_bit;                      /*!< DATAOUTTGL_bit: structure used for bit access */
  };
  union {                                                               /*!< Digital function (PAD) enable register */
    __IO uint32_t DENSET;                                            /*!< DENSET    : type used for word access */
    __IO _GPIO_DENSET_bits  DENSET_bit;                              /*!< DENSET_bit: structure used for bit access */
  };
  union {                                                               /*!< Digital function (PAD) disable register */
    __IO uint32_t DENCLR;                                            /*!< DENCLR    : type used for word access */
    __IO _GPIO_DENCLR_bits  DENCLR_bit;                              /*!< DENCLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Select input mode register */
    __IO uint32_t INMODE;                                            /*!< INMODE    : type used for word access */
    __IO _GPIO_INMODE_bits  INMODE_bit;                              /*!< INMODE_bit: structure used for bit access */
  };
  union {                                                               /*!< Select pull mode register */
    __IO uint32_t PULLMODE;                                           /*!< PULLMODE    : type used for word access */
    __IO _GPIO_PULLMODE_bits  PULLMODE_bit;                          /*!< PULLMODE_bit: structure used for bit access */
  };
  union {                                                               /*!< Select output mode register */
    __IO uint32_t OUTMODE;                                           /*!< OUTMODE    : type used for word access */
    __IO _GPIO_OUTMODE_bits  OUTMODE_bit;                            /*!< OUTMODE_bit: structure used for bit access */
  };
  union {                                                               /*!< Select drive mode register */
    __IO uint32_t DRIVEMODE;                                           /*!< DRIVEMODE    : type used for word access */
    __IO _GPIO_DRIVEMODE_bits  DRIVEMODE_bit;                        /*!< DRIVEMODE_bit: structure used for bit access */
  };
  union {                                                               /*!< Output enable register */
    __IO uint32_t OUTENSET;                                           /*!< OUTENSET    : type used for word access */
    __IO _GPIO_OUTENSET_bits  OUTENSET_bit;                          /*!< OUTENSET_bit: structure used for bit access */
  };
  union {                                                               /*!< Output disable register */
    __IO uint32_t OUTENCLR;                                           /*!< OUTENCLR    : type used for word access */
    __IO _GPIO_OUTENCLR_bits  OUTENCLR_bit;                          /*!< OUTENCLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Alternative function enable register */
    __IO uint32_t ALTFUNCSET;                                           /*!< ALTFUNCSET    : type used for word access */
    __IO _GPIO_ALTFUNCSET_bits  ALTFUNCSET_bit;                      /*!< ALTFUNCSET_bit: structure used for bit access */
  };
  union {                                                               /*!< Alternative function disable register */
    __IO uint32_t ALTFUNCCLR;                                           /*!< ALTFUNCCLR    : type used for word access */
    __IO _GPIO_ALTFUNCCLR_bits  ALTFUNCCLR_bit;                      /*!< ALTFUNCCLR_bit: structure used for bit access */
  };
    __IO uint32_t Reserved0[2];
  union {                                                               /*!< Additional double flip-flop syncronization enable register */
    __IO uint32_t SYNCSET;                                           /*!< SYNCSET    : type used for word access */
    __IO _GPIO_SYNCSET_bits  SYNCSET_bit;                            /*!< SYNCSET_bit: structure used for bit access */
  };
  union {                                                               /*!< Additional double flip-flop syncronization disable register */
    __IO uint32_t SYNCCLR;                                           /*!< SYNCCLR    : type used for word access */
    __IO _GPIO_SYNCCLR_bits  SYNCCLR_bit;                            /*!< SYNCCLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Qualifier enable register */
    __IO uint32_t QUALSET;                                           /*!< QUALSET    : type used for word access */
    __IO _GPIO_QUALSET_bits  QUALSET_bit;                            /*!< QUALSET_bit: structure used for bit access */
  };
  union {                                                               /*!< Qualifier disable register */
    __IO uint32_t QUALCLR;                                           /*!< QUALCLR    : type used for word access */
    __IO _GPIO_QUALCLR_bits  QUALCLR_bit;                            /*!< QUALCLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Qualifier mode set register */
    __IO uint32_t QUALMODESET;                                           /*!< QUALMODESET    : type used for word access */
    __IO _GPIO_QUALMODESET_bits  QUALMODESET_bit;                    /*!< QUALMODESET_bit: structure used for bit access */
  };
  union {                                                               /*!< Qualifier mode clear register */
    __IO uint32_t QUALMODECLR;                                           /*!< QUALMODECLR    : type used for word access */
    __IO _GPIO_QUALMODECLR_bits  QUALMODECLR_bit;                    /*!< QUALMODECLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Qualifier sample period register */
    __IO uint32_t QUALSAMPLE;                                           /*!< QUALSAMPLE    : type used for word access */
    __IO _GPIO_QUALSAMPLE_bits  QUALSAMPLE_bit;                      /*!< QUALSAMPLE_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt enable register */
    __IO uint32_t INTENSET;                                           /*!< INTENSET    : type used for word access */
    __IO _GPIO_INTENSET_bits  INTENSET_bit;                          /*!< INTENSET_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt disable register */
    __IO uint32_t INTENCLR;                                           /*!< INTENCLR    : type used for word access */
    __IO _GPIO_INTENCLR_bits  INTENCLR_bit;                          /*!< INTENCLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt type set register */
    __IO uint32_t INTTYPESET;                                           /*!< INTTYPESET    : type used for word access */
    __IO _GPIO_INTTYPESET_bits  INTTYPESET_bit;                      /*!< INTTYPESET_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt type clear register */
    __IO uint32_t INTTYPECLR;                                           /*!< INTTYPECLR    : type used for word access */
    __IO _GPIO_INTTYPECLR_bits  INTTYPECLR_bit;                      /*!< INTTYPECLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt polarity set register */
    __IO uint32_t INTPOLSET;                                           /*!< INTPOLSET    : type used for word access */
    __IO _GPIO_INTPOLSET_bits  INTPOLSET_bit;                        /*!< INTPOLSET_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt polarity clear register */
    __IO uint32_t INTPOLCLR;                                           /*!< INTPOLCLR    : type used for word access */
    __IO _GPIO_INTPOLCLR_bits  INTPOLCLR_bit;                        /*!< INTPOLCLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt every edge set register */
    __IO uint32_t INTEDGESET;                                           /*!< INTEDGESET    : type used for word access */
    __IO _GPIO_INTEDGESET_bits  INTEDGESET_bit;                      /*!< INTEDGESET_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt every edge clear register */
    __IO uint32_t INTEDGECLR;                                           /*!< INTEDGECLR    : type used for word access */
    __IO _GPIO_INTEDGECLR_bits  INTEDGECLR_bit;                      /*!< INTEDGECLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt status */
    __IO uint32_t INTSTATUS;                                           /*!< INTSTATUS    : type used for word access */
    __IO _GPIO_INTSTATUS_bits  INTSTATUS_bit;                        /*!< INTSTATUS_bit: structure used for bit access */
  };
  union {                                                               /*!< DMA request enable register */
    __IO uint32_t DMAREQSET;                                           /*!< DMAREQSET    : type used for word access */
    __IO _GPIO_DMAREQSET_bits  DMAREQSET_bit;                        /*!< DMAREQSET_bit: structure used for bit access */
  };
  union {                                                               /*!< DMA request disable register */
    __IO uint32_t DMAREQCLR;                                           /*!< DMAREQCLR    : type used for word access */
    __IO _GPIO_DMAREQCLR_bits  DMAREQCLR_bit;                        /*!< DMAREQCLR_bit: structure used for bit access */
  };
  union {                                                               /*!< ADC Start Of Conversion enable register */
    __IO uint32_t ADCSOCSET;                                           /*!< ADCSOCSET    : type used for word access */
    __IO _GPIO_ADCSOCSET_bits  ADCSOCSET_bit;                        /*!< ADCSOCSET_bit: structure used for bit access */
  };
  union {                                                               /*!< ADC Start Of Conversion disable register */
    __IO uint32_t ADCSOCCLR;                                           /*!< ADCSOCCLR    : type used for word access */
    __IO _GPIO_ADCSOCCLR_bits  ADCSOCCLR_bit;                        /*!< ADCSOCCLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Core RXEV request enable register */
    __IO uint32_t RXEVSET;                                           /*!< RXEVSET    : type used for word access */
    __IO _GPIO_RXEVSET_bits  RXEVSET_bit;                            /*!< RXEVSET_bit: structure used for bit access */
  };
  union {                                                               /*!< Core RXEV request disable register */
    __IO uint32_t RXEVCLR;                                           /*!< RXEVCLR    : type used for word access */
    __IO _GPIO_RXEVCLR_bits  RXEVCLR_bit;                            /*!< RXEVCLR_bit: structure used for bit access */
  };
  union {
    union {                                                               /*!< Key register to unlock LOCKSET/LOCKCLR registers for write (KEY=0xADEADBEE) */
      __O uint32_t LOCKKEY;                                           /*!< LOCKKEY    : type used for word access */
      __O _GPIO_LOCKKEY_bits  LOCKKEY_bit;                           /*!< LOCKKEY_bit: structure used for bit access */
    };
    union {                                                               /*!< LOCKSET/LOCKCLR write enable status register */
      __I uint32_t LOCKSTAT;                                           /*!< LOCKSTAT    : type used for word access */
      __I _GPIO_LOCKSTAT_bits  LOCKSTAT_bit;                         /*!< LOCKSTAT_bit: structure used for bit access */
    };
  };
  union {                                                               /*!< Lock pins configuration enable register */
    __IO uint32_t LOCKSET;                                           /*!< LOCKSET    : type used for word access */
    __IO _GPIO_LOCKSET_bits  LOCKSET_bit;                            /*!< LOCKSET_bit: structure used for bit access */
  };
  union {                                                               /*!< Lock pins configuration disable register */
    __IO uint32_t LOCKCLR;                                           /*!< LOCKCLR    : type used for word access */
    __IO _GPIO_LOCKCLR_bits  LOCKCLR_bit;                            /*!< LOCKCLR_bit: structure used for bit access */
  };
    __IO uint32_t Reserved1[214];
  _GPIO_MASKLB_TypeDef MASKLB[256];
  _GPIO_MASKHB_TypeDef MASKHB[256];
} GPIO_TypeDef;

/******************************************************************************/
/*                         UART registers                                     */
/******************************************************************************/

/*--  DR: Data Register ---------------------------------------------------------------------------------------*/
typedef struct {
  uint32_t DATA                   :8;                                /*!< Received/Transmitted data character */
  uint32_t FE                     :1;                                /*!< Framing error */
  uint32_t PE                     :1;                                /*!< Parity error */
  uint32_t BE                     :1;                                /*!< Break error */
  uint32_t OE                     :1;                                /*!< Overrun error */
} _UART_DR_bits;

/* Bit field positions: */
#define UART_DR_DATA_Pos                      0                      /*!< Received/Transmitted data character */
#define UART_DR_FE_Pos                        8                      /*!< Framing error */
#define UART_DR_PE_Pos                        9                      /*!< Parity error */
#define UART_DR_BE_Pos                        10                     /*!< Break error */
#define UART_DR_OE_Pos                        11                     /*!< Overrun error */

/* Bit field masks: */
#define UART_DR_DATA_Msk                      0x000000FF             /*!< Received/Transmitted data character */
#define UART_DR_FE_Msk                        0x00000100             /*!< Framing error */
#define UART_DR_PE_Msk                        0x00000200             /*!< Parity error */
#define UART_DR_BE_Msk                        0x00000400             /*!< Break error */
#define UART_DR_OE_Msk                        0x00000800             /*!< Overrun error */

/*--  RSR: Receive Status Register/Error Clear Register -------------------------------------------------------*/
typedef struct {
  uint32_t FE                     :1;                                /*!< Framing error */
  uint32_t PE                     :1;                                /*!< Parity error */
  uint32_t BE                     :1;                                /*!< Break error */
  uint32_t OE                     :1;                                /*!< Overrun error */
} _UART_RSR_bits;

/* Bit field positions: */
#define UART_RSR_FE_Pos                       0                      /*!< Framing error */
#define UART_RSR_PE_Pos                       1                      /*!< Parity error */
#define UART_RSR_BE_Pos                       2                      /*!< Break error */
#define UART_RSR_OE_Pos                       3                      /*!< Overrun error */

/* Bit field masks: */
#define UART_RSR_FE_Msk                       0x00000001             /*!< Framing error */
#define UART_RSR_PE_Msk                       0x00000002             /*!< Parity error */
#define UART_RSR_BE_Msk                       0x00000004             /*!< Break error */
#define UART_RSR_OE_Msk                       0x00000008             /*!< Overrun error */

/*--  FR: Flag Register ---------------------------------------------------------------------------------------*/
typedef struct {
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t BUSY                   :1;                                /*!< UART busy */
  uint32_t RXFE                   :1;                                /*!< Receive FIFO empty */
  uint32_t TXFF                   :1;                                /*!< Transmit FIFO full */
  uint32_t RXFF                   :1;                                /*!< Receive FIFO full */
  uint32_t TXFE                   :1;                                /*!< Transmit FIFO empty */
  uint32_t RI                     :1;                                /*!< Ring indicator */
} _UART_FR_bits;

/* Bit field positions: */
#define UART_FR_BUSY_Pos                      3                      /*!< UART busy */
#define UART_FR_RXFE_Pos                      4                      /*!< Receive FIFO empty */
#define UART_FR_TXFF_Pos                      5                      /*!< Transmit FIFO full */
#define UART_FR_RXFF_Pos                      6                      /*!< Receive FIFO full */
#define UART_FR_TXFE_Pos                      7                      /*!< Transmit FIFO empty */
#define UART_FR_RI_Pos                        8                      /*!< Ring indicator */

/* Bit field masks: */
#define UART_FR_BUSY_Msk                      0x00000008             /*!< UART busy */
#define UART_FR_RXFE_Msk                      0x00000010             /*!< Receive FIFO empty */
#define UART_FR_TXFF_Msk                      0x00000020             /*!< Transmit FIFO full */
#define UART_FR_RXFF_Msk                      0x00000040             /*!< Receive FIFO full */
#define UART_FR_TXFE_Msk                      0x00000080             /*!< Transmit FIFO empty */
#define UART_FR_RI_Msk                        0x00000100             /*!< Ring indicator */

/*--  IBRD: Integer Baud Rate Register ------------------------------------------------------------------------*/
typedef struct {
  uint32_t DIVINT                 :16;                               /*!< The integer baud rate divisor */
} _UART_IBRD_bits;

/* Bit field positions: */
#define UART_IBRD_DIVINT_Pos                  0                      /*!< The integer baud rate divisor */

/* Bit field masks: */
#define UART_IBRD_DIVINT_Msk                  0x0000FFFF             /*!< The integer baud rate divisor */

/*--  FBRD: Fractional Baud Rate Register ---------------------------------------------------------------------*/
typedef struct {
  uint32_t DIVFRAC                :6;                                /*!< The fractional baud rate divisor */
} _UART_FBRD_bits;

/* Bit field positions: */
#define UART_FBRD_DIVFRAC_Pos                 0                      /*!< The fractional baud rate divisor */

/* Bit field masks: */
#define UART_FBRD_DIVFRAC_Msk                 0x0000003F             /*!< The fractional baud rate divisor */

/*--  LCRH: Line Control Register -----------------------------------------------------------------------------*/
typedef struct {
  uint32_t BRK                    :1;                                /*!< Send break */
  uint32_t PEN                    :1;                                /*!< Parity enable */
  uint32_t EPS                    :1;                                /*!< Even parity select */
  uint32_t STP2                   :1;                                /*!< Two stop bits select */
  uint32_t FEN                    :1;                                /*!< Enable FIFOs */
  uint32_t WLEN                   :2;                                /*!< Word length */
  uint32_t SPS                    :1;                                /*!< Stick parity select */
} _UART_LCRH_bits;

/* Bit field positions: */
#define UART_LCRH_BRK_Pos                     0                      /*!< Send break */
#define UART_LCRH_PEN_Pos                     1                      /*!< Parity enable */
#define UART_LCRH_EPS_Pos                     2                      /*!< Even parity select */
#define UART_LCRH_STP2_Pos                    3                      /*!< Two stop bits select */
#define UART_LCRH_FEN_Pos                     4                      /*!< Enable FIFOs */
#define UART_LCRH_WLEN_Pos                    5                      /*!< Word length */
#define UART_LCRH_SPS_Pos                     7                      /*!< Stick parity select */

/* Bit field masks: */
#define UART_LCRH_BRK_Msk                     0x00000001             /*!< Send break */
#define UART_LCRH_PEN_Msk                     0x00000002             /*!< Parity enable */
#define UART_LCRH_EPS_Msk                     0x00000004             /*!< Even parity select */
#define UART_LCRH_STP2_Msk                    0x00000008             /*!< Two stop bits select */
#define UART_LCRH_FEN_Msk                     0x00000010             /*!< Enable FIFOs */
#define UART_LCRH_WLEN_Msk                    0x00000060             /*!< Word length */
#define UART_LCRH_SPS_Msk                     0x00000080             /*!< Stick parity select */

/* Bit field enums: */
typedef enum {
  UART_LCRH_WLEN_5bit                        = 0x0,                  /*!< 5 bit in informational word */
  UART_LCRH_WLEN_6bit                        = 0x1,                  /*!< 6 bit in informational word */
  UART_LCRH_WLEN_7bit                        = 0x2,                  /*!< 7 bit in informational word */
  UART_LCRH_WLEN_8bit                        = 0x3,                  /*!< 8 bit in informational word */
} UART_LCRH_WLEN_Enum;

/*--  CR: Control Register ------------------------------------------------------------------------------------*/
typedef struct {
  uint32_t UARTEN                 :1;                                /*!< UART enable */
  uint32_t                        :7;                                /*!< RESERVED */
  uint32_t TXE                    :1;                                /*!< Transmit enable */
  uint32_t RXE                    :1;                                /*!< Receive enable */
} _UART_CR_bits;

/* Bit field positions: */
#define UART_CR_UARTEN_Pos                    0                      /*!< UART enable */
#define UART_CR_TXE_Pos                       8                      /*!< Transmit enable */
#define UART_CR_RXE_Pos                       9                      /*!< Receive enable */

/* Bit field masks: */
#define UART_CR_UARTEN_Msk                    0x00000001             /*!< UART enable */
#define UART_CR_TXE_Msk                       0x00000100             /*!< Transmit enable */
#define UART_CR_RXE_Msk                       0x00000200             /*!< Receive enable */

/*--  IFLS: Interrupt FIFO Level Select Register --------------------------------------------------------------*/
typedef struct {
  uint32_t TXIFLSEL               :3;                                /*!< Transmit interrupt FIFO level select */
  uint32_t RXIFLSEL               :3;                                /*!< Receive interrupt FIFO level select */
} _UART_IFLS_bits;

/* Bit field positions: */
#define UART_IFLS_TXIFLSEL_Pos                0                      /*!< Transmit interrupt FIFO level select */
#define UART_IFLS_RXIFLSEL_Pos                3                      /*!< Receive interrupt FIFO level select */

/* Bit field masks: */
#define UART_IFLS_TXIFLSEL_Msk                0x00000007             /*!< Transmit interrupt FIFO level select */
#define UART_IFLS_RXIFLSEL_Msk                0x00000038             /*!< Receive interrupt FIFO level select */

/* Bit field enums: */
typedef enum {
  UART_IFLS_TXIFLSEL_Lvl18                   = 0x0,                  /*!< interrupt on 1/8 */
  UART_IFLS_TXIFLSEL_Lvl14                   = 0x1,                  /*!< interrupt on 1/4 */
  UART_IFLS_TXIFLSEL_Lvl12                   = 0x2,                  /*!< interrupt on 1/2 */
  UART_IFLS_TXIFLSEL_Lvl34                   = 0x3,                  /*!< interrupt on 3/4 */
  UART_IFLS_TXIFLSEL_Lvl78                   = 0x4,                  /*!< interrupt on 7/8 */
} UART_IFLS_TXIFLSEL_Enum;

typedef enum {
  UART_IFLS_RXIFLSEL_Lvl18                   = 0x0,                  /*!< interrupt on 1/8 */
  UART_IFLS_RXIFLSEL_Lvl14                   = 0x1,                  /*!< interrupt on 1/4 */
  UART_IFLS_RXIFLSEL_Lvl12                   = 0x2,                  /*!< interrupt on 1/2 */
  UART_IFLS_RXIFLSEL_Lvl34                   = 0x3,                  /*!< interrupt on 3/4 */
  UART_IFLS_RXIFLSEL_Lvl78                   = 0x4,                  /*!< interrupt on 7/8 */
} UART_IFLS_RXIFLSEL_Enum;

/*--  IMSC: Interrupt Mask Set/Clear Register -----------------------------------------------------------------*/
typedef struct {
  uint32_t                        :4;                                /*!< RESERVED */
  uint32_t RXIM                   :1;                                /*!< Receive interrupt mask */
  uint32_t TXIM                   :1;                                /*!< Transmit interrupt mask */
  uint32_t RTIM                   :1;                                /*!< Receive timeout interrupt mask */
  uint32_t FERIM                  :1;                                /*!< Framing error interrupt mask */
  uint32_t PERIM                  :1;                                /*!< Parity error interrupt mask */
  uint32_t BERIM                  :1;                                /*!< Break error interrupt mask */
  uint32_t OERIM                  :1;                                /*!< Overrun error interrupt mask */
  uint32_t TDIM                   :1;                                /*!< Transmit done interrupt mask */
} _UART_IMSC_bits;

/* Bit field positions: */
#define UART_IMSC_RXIM_Pos                    4                      /*!< Receive interrupt mask */
#define UART_IMSC_TXIM_Pos                    5                      /*!< Transmit interrupt mask */
#define UART_IMSC_RTIM_Pos                    6                      /*!< Receive timeout interrupt mask */
#define UART_IMSC_FERIM_Pos                   7                      /*!< Framing error interrupt mask */
#define UART_IMSC_PERIM_Pos                   8                      /*!< Parity error interrupt mask */
#define UART_IMSC_BERIM_Pos                   9                      /*!< Break error interrupt mask */
#define UART_IMSC_OERIM_Pos                   10                     /*!< Overrun error interrupt mask */
#define UART_IMSC_TDIM_Pos                    11                     /*!< Transmit done interrupt mask */

/* Bit field masks: */
#define UART_IMSC_RXIM_Msk                    0x00000010             /*!< Receive interrupt mask */
#define UART_IMSC_TXIM_Msk                    0x00000020             /*!< Transmit interrupt mask */
#define UART_IMSC_RTIM_Msk                    0x00000040             /*!< Receive timeout interrupt mask */
#define UART_IMSC_FERIM_Msk                   0x00000080             /*!< Framing error interrupt mask */
#define UART_IMSC_PERIM_Msk                   0x00000100             /*!< Parity error interrupt mask */
#define UART_IMSC_BERIM_Msk                   0x00000200             /*!< Break error interrupt mask */
#define UART_IMSC_OERIM_Msk                   0x00000400             /*!< Overrun error interrupt mask */
#define UART_IMSC_TDIM_Msk                    0x00000800             /*!< Transmit done interrupt mask */

/*--  RIS: Raw Interrupt Status Register ----------------------------------------------------------------------*/
typedef struct {
  uint32_t                        :4;                                /*!< RESERVED */
  uint32_t RXRIS                  :1;                                /*!< Receive interrupt status */
  uint32_t TXRIS                  :1;                                /*!< Transmit interrupt status */
  uint32_t RTRIS                  :1;                                /*!< Receive timeout interrupt status */
  uint32_t FERIS                  :1;                                /*!< Framing error interrupt status */
  uint32_t PERIS                  :1;                                /*!< Parity error interrupt status */
  uint32_t BERIS                  :1;                                /*!< Break error interrupt status */
  uint32_t OERIS                  :1;                                /*!< Overrun error interrupt status */
  uint32_t TDRIS                  :1;                                /*!< Transmit done raw interrupt status */
} _UART_RIS_bits;

/* Bit field positions: */
#define UART_RIS_RXRIS_Pos                    4                      /*!< Receive interrupt status */
#define UART_RIS_TXRIS_Pos                    5                      /*!< Transmit interrupt status */
#define UART_RIS_RTRIS_Pos                    6                      /*!< Receive timeout interrupt status */
#define UART_RIS_FERIS_Pos                    7                      /*!< Framing error interrupt status */
#define UART_RIS_PERIS_Pos                    8                      /*!< Parity error interrupt status */
#define UART_RIS_BERIS_Pos                    9                      /*!< Break error interrupt status */
#define UART_RIS_OERIS_Pos                    10                     /*!< Overrun error interrupt status */
#define UART_RIS_TDRIS_Pos                    11                     /*!< Transmit done raw interrupt status */

/* Bit field masks: */
#define UART_RIS_RXRIS_Msk                    0x00000010             /*!< Receive interrupt status */
#define UART_RIS_TXRIS_Msk                    0x00000020             /*!< Transmit interrupt status */
#define UART_RIS_RTRIS_Msk                    0x00000040             /*!< Receive timeout interrupt status */
#define UART_RIS_FERIS_Msk                    0x00000080             /*!< Framing error interrupt status */
#define UART_RIS_PERIS_Msk                    0x00000100             /*!< Parity error interrupt status */
#define UART_RIS_BERIS_Msk                    0x00000200             /*!< Break error interrupt status */
#define UART_RIS_OERIS_Msk                    0x00000400             /*!< Overrun error interrupt status */
#define UART_RIS_TDRIS_Msk                    0x00000800             /*!< Transmit done raw interrupt status */

/*--  MIS: Masked Interrupt Status Register -------------------------------------------------------------------*/
typedef struct {
  uint32_t                        :4;                                /*!< RESERVED */
  uint32_t RXMIS                  :1;                                /*!< Receive masked interrupt status */
  uint32_t TXMIS                  :1;                                /*!< Transmit masked interrupt status */
  uint32_t RTMIS                  :1;                                /*!< Receive timeout masked interrupt status */
  uint32_t FEMIS                  :1;                                /*!< Framing error masked interrupt status */
  uint32_t PEMIS                  :1;                                /*!< Parity error masked interrupt status */
  uint32_t BEMIS                  :1;                                /*!< Break error masked interrupt status */
  uint32_t OEMIS                  :1;                                /*!< Overrun error masked interrupt status */
  uint32_t TDMIS                  :1;                                /*!< Transmit done masked interrupt status */
} _UART_MIS_bits;

/* Bit field positions: */
#define UART_MIS_RXMIS_Pos                    4                      /*!< Receive masked interrupt status */
#define UART_MIS_TXMIS_Pos                    5                      /*!< Transmit masked interrupt status */
#define UART_MIS_RTMIS_Pos                    6                      /*!< Receive timeout masked interrupt status */
#define UART_MIS_FEMIS_Pos                    7                      /*!< Framing error masked interrupt status */
#define UART_MIS_PEMIS_Pos                    8                      /*!< Parity error masked interrupt status */
#define UART_MIS_BEMIS_Pos                    9                      /*!< Break error masked interrupt status */
#define UART_MIS_OEMIS_Pos                    10                     /*!< Overrun error masked interrupt status */
#define UART_MIS_TDMIS_Pos                    11                     /*!< Transmit done masked interrupt status */

/* Bit field masks: */
#define UART_MIS_RXMIS_Msk                    0x00000010             /*!< Receive masked interrupt status */
#define UART_MIS_TXMIS_Msk                    0x00000020             /*!< Transmit masked interrupt status */
#define UART_MIS_RTMIS_Msk                    0x00000040             /*!< Receive timeout masked interrupt status */
#define UART_MIS_FEMIS_Msk                    0x00000080             /*!< Framing error masked interrupt status */
#define UART_MIS_PEMIS_Msk                    0x00000100             /*!< Parity error masked interrupt status */
#define UART_MIS_BEMIS_Msk                    0x00000200             /*!< Break error masked interrupt status */
#define UART_MIS_OEMIS_Msk                    0x00000400             /*!< Overrun error masked interrupt status */
#define UART_MIS_TDMIS_Msk                    0x00000800             /*!< Transmit done masked interrupt status */

/*--  ICR: Interrupt Clear Register ---------------------------------------------------------------------------*/
typedef struct {
  uint32_t                        :4;                                /*!< RESERVED */
  uint32_t RXIC                   :1;                                /*!< Receive interrupt clear */
  uint32_t TXIC                   :1;                                /*!< Transmit interrupt clear */
  uint32_t RTIC                   :1;                                /*!< Receive timeout interrupt clear */
  uint32_t FEIC                   :1;                                /*!< Framing error interrupt clear */
  uint32_t PEIC                   :1;                                /*!< Parity error interrupt clear */
  uint32_t BEIC                   :1;                                /*!< Break error interrupt clear */
  uint32_t OEIC                   :1;                                /*!< Overrun error interrupt clear */
  uint32_t TDIC                   :1;                                /*!< Transmit done interrupt clear */
} _UART_ICR_bits;

/* Bit field positions: */
#define UART_ICR_RXIC_Pos                     4                      /*!< Receive interrupt clear */
#define UART_ICR_TXIC_Pos                     5                      /*!< Transmit interrupt clear */
#define UART_ICR_RTIC_Pos                     6                      /*!< Receive timeout interrupt clear */
#define UART_ICR_FEIC_Pos                     7                      /*!< Framing error interrupt clear */
#define UART_ICR_PEIC_Pos                     8                      /*!< Parity error interrupt clear */
#define UART_ICR_BEIC_Pos                     9                      /*!< Break error interrupt clear */
#define UART_ICR_OEIC_Pos                     10                     /*!< Overrun error interrupt clear */
#define UART_ICR_TDIC_Pos                     11                     /*!< Transmit done interrupt clear */

/* Bit field masks: */
#define UART_ICR_RXIC_Msk                     0x00000010             /*!< Receive interrupt clear */
#define UART_ICR_TXIC_Msk                     0x00000020             /*!< Transmit interrupt clear */
#define UART_ICR_RTIC_Msk                     0x00000040             /*!< Receive timeout interrupt clear */
#define UART_ICR_FEIC_Msk                     0x00000080             /*!< Framing error interrupt clear */
#define UART_ICR_PEIC_Msk                     0x00000100             /*!< Parity error interrupt clear */
#define UART_ICR_BEIC_Msk                     0x00000200             /*!< Break error interrupt clear */
#define UART_ICR_OEIC_Msk                     0x00000400             /*!< Overrun error interrupt clear */
#define UART_ICR_TDIC_Msk                     0x00000800             /*!< Transmit done interrupt clear */

/*--  DMACR: DMA Control Register -----------------------------------------------------------------------------*/
typedef struct {
  uint32_t RXDMAE                 :1;                                /*!< Receive DMA enable */
  uint32_t TXDMAE                 :1;                                /*!< Transmit DMA enable */
  uint32_t DMAONERR               :1;                                /*!< DMA on error */
} _UART_DMACR_bits;

/* Bit field positions: */
#define UART_DMACR_RXDMAE_Pos                 0                      /*!< Receive DMA enable */
#define UART_DMACR_TXDMAE_Pos                 1                      /*!< Transmit DMA enable */
#define UART_DMACR_DMAONERR_Pos               2                      /*!< DMA on error */

/* Bit field masks: */
#define UART_DMACR_RXDMAE_Msk                 0x00000001             /*!< Receive DMA enable */
#define UART_DMACR_TXDMAE_Msk                 0x00000002             /*!< Transmit DMA enable */
#define UART_DMACR_DMAONERR_Msk               0x00000004             /*!< DMA on error */

typedef struct {
  union {                                                               /*!< Data Register */
    __IO uint32_t DR;                                                /*!< DR    : type used for word access */
    __IO _UART_DR_bits  DR_bit;                                      /*!< DR_bit: structure used for bit access */
  };
  union {                                                               /*!< Receive Status Register/Error Clear Register */
    __IO uint32_t RSR;                                               /*!< RSR    : type used for word access */
    __IO _UART_RSR_bits  RSR_bit;                                    /*!< RSR_bit: structure used for bit access */
  };
    __IO uint32_t Reserved0[4];
  union {                                                               /*!< Flag Register */
    __I uint32_t FR;                                                 /*!< FR    : type used for word access */
    __I _UART_FR_bits  FR_bit;                                       /*!< FR_bit: structure used for bit access */
  };
    __IO uint32_t Reserved1[2];
  union {                                                               /*!< Integer Baud Rate Register */
    __IO uint32_t IBRD;                                              /*!< IBRD    : type used for word access */
    __IO _UART_IBRD_bits  IBRD_bit;                                  /*!< IBRD_bit: structure used for bit access */
  };
  union {                                                               /*!< Fractional Baud Rate Register */
    __IO uint32_t FBRD;                                              /*!< FBRD    : type used for word access */
    __IO _UART_FBRD_bits  FBRD_bit;                                  /*!< FBRD_bit: structure used for bit access */
  };
  union {                                                               /*!< Line Control Register */
    __IO uint32_t LCRH;                                              /*!< LCRH    : type used for word access */
    __IO _UART_LCRH_bits  LCRH_bit;                                  /*!< LCRH_bit: structure used for bit access */
  };
  union {                                                               /*!< Control Register */
    __IO uint32_t CR;                                                /*!< CR    : type used for word access */
    __IO _UART_CR_bits  CR_bit;                                      /*!< CR_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt FIFO Level Select Register */
    __IO uint32_t IFLS;                                              /*!< IFLS    : type used for word access */
    __IO _UART_IFLS_bits  IFLS_bit;                                  /*!< IFLS_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt Mask Set/Clear Register */
    __IO uint32_t IMSC;                                              /*!< IMSC    : type used for word access */
    __IO _UART_IMSC_bits  IMSC_bit;                                  /*!< IMSC_bit: structure used for bit access */
  };
  union {                                                               /*!< Raw Interrupt Status Register */
    __IO uint32_t RIS;                                               /*!< RIS    : type used for word access */
    __IO _UART_RIS_bits  RIS_bit;                                    /*!< RIS_bit: structure used for bit access */
  };
  union {                                                               /*!< Masked Interrupt Status Register */
    __IO uint32_t MIS;                                               /*!< MIS    : type used for word access */
    __IO _UART_MIS_bits  MIS_bit;                                    /*!< MIS_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt Clear Register */
    __IO uint32_t ICR;                                               /*!< ICR    : type used for word access */
    __IO _UART_ICR_bits  ICR_bit;                                    /*!< ICR_bit: structure used for bit access */
  };
  union {                                                               /*!< DMA Control Register */
    __IO uint32_t DMACR;                                             /*!< DMACR    : type used for word access */
    __IO _UART_DMACR_bits  DMACR_bit;                                /*!< DMACR_bit: structure used for bit access */
  };
} UART_TypeDef;

/******************************************************************************/
/*                         DMA registers                                      */
/******************************************************************************/

/*--  STATUS: Status DMA register -----------------------------------------------------------------------------*/
typedef struct {
  uint32_t MASTEREN               :1;                                /*!< Indicate enable DMA */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t STATE                  :4;                                /*!< State of DMA */
  uint32_t                        :8;                                /*!< RESERVED */
  uint32_t CHNLS                  :5;                                /*!< Number channel DMA (write: N-1) */
} _DMA_STATUS_bits;

/* Bit field positions: */
#define DMA_STATUS_MASTEREN_Pos               0                      /*!< Indicate enable DMA */
#define DMA_STATUS_STATE_Pos                  4                      /*!< State of DMA */
#define DMA_STATUS_CHNLS_Pos                  16                     /*!< Number channel DMA (write: N-1) */

/* Bit field masks: */
#define DMA_STATUS_MASTEREN_Msk               0x00000001             /*!< Indicate enable DMA */
#define DMA_STATUS_STATE_Msk                  0x000000F0             /*!< State of DMA */
#define DMA_STATUS_CHNLS_Msk                  0x001F0000             /*!< Number channel DMA (write: N-1) */

/* Bit field enums: */
typedef enum {
  DMA_STATUS_STATE_Free                      = 0x0,                  /*!< At rest */
  DMA_STATUS_STATE_ReadConfigData            = 0x1,                  /*!< Reading the config data structure */
  DMA_STATUS_STATE_ReadSrcDataEndPtr         = 0x2,                  /*!< Reading sourse data end pointer */
  DMA_STATUS_STATE_ReadDstDataEndPtr         = 0x3,                  /*!< Reading destination data end pointer */
  DMA_STATUS_STATE_ReadSrcData               = 0x4,                  /*!< Reading source data */
  DMA_STATUS_STATE_WrireDstData              = 0x5,                  /*!< Writing data to the destination */
  DMA_STATUS_STATE_WaitReq                   = 0x6,                  /*!< Waiting for a request */
  DMA_STATUS_STATE_WriteConfigData           = 0x7,                  /*!< Write config structure of the channel */
  DMA_STATUS_STATE_Pause                     = 0x8,                  /*!< Suspended */
  DMA_STATUS_STATE_Done                      = 0x9,                  /*!< Executed */
  DMA_STATUS_STATE_PeriphScatGath            = 0xA,                  /*!< mode "peripheral scather-gather" */
} DMA_STATUS_STATE_Enum;

/*--  CFG: DMA configuration register -------------------------------------------------------------------------*/
typedef struct {
  uint32_t MASTEREN               :1;                                /*!< Enable DMA */
  uint32_t                        :4;                                /*!< RESERVED */
  uint32_t CHPROT                 :3;                                /*!< Sets the AHB-Lite protection */
} _DMA_CFG_bits;

/* Bit field positions: */
#define DMA_CFG_MASTEREN_Pos                  0                      /*!< Enable DMA */
#define DMA_CFG_CHPROT_Pos                    5                      /*!< Sets the AHB-Lite protection */

/* Bit field masks: */
#define DMA_CFG_MASTEREN_Msk                  0x00000001             /*!< Enable DMA */
#define DMA_CFG_CHPROT_Msk                    0x000000E0             /*!< Sets the AHB-Lite protection */

/*--  BASEPTR: Channel control data base pointer --------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!< Base address of the primary control data */
} _DMA_BASEPTR_bits;

/* Bit field positions: */
#define DMA_BASEPTR_VAL_Pos                   0                      /*!< Base address of the primary control data */

/* Bit field masks: */
#define DMA_BASEPTR_VAL_Msk                   0xFFFFFFFF             /*!< Base address of the primary control data */

/*--  ALTBASEPTR: Channel alternate control data base pointer -------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!< Base address of alternative control data */
} _DMA_ALTBASEPTR_bits;

/* Bit field positions: */
#define DMA_ALTBASEPTR_VAL_Pos                0                      /*!< Base address of alternative control data */

/* Bit field masks: */
#define DMA_ALTBASEPTR_VAL_Msk                0xFFFFFFFF             /*!< Base address of alternative control data */

/*--  WAITONREQ: Channel wait on request status ---------------------------------------------------------------*/
typedef struct {
  uint32_t CH0                    :1;                                /*!< Returns the status of the DMA request signals */
  uint32_t CH1                    :1;                                /*!< Returns the status of the DMA request signals */
  uint32_t CH2                    :1;                                /*!< Returns the status of the DMA request signals */
  uint32_t CH3                    :1;                                /*!< Returns the status of the DMA request signals */
  uint32_t CH4                    :1;                                /*!< Returns the status of the DMA request signals */
  uint32_t CH5                    :1;                                /*!< Returns the status of the DMA request signals */
  uint32_t CH6                    :1;                                /*!< Returns the status of the DMA request signals */
  uint32_t CH7                    :1;                                /*!< Returns the status of the DMA request signals */
  uint32_t CH8                    :1;                                /*!< Returns the status of the DMA request signals */
  uint32_t CH9                    :1;                                /*!< Returns the status of the DMA request signals */
  uint32_t CH10                   :1;                                /*!< Returns the status of the DMA request signals */
  uint32_t CH11                   :1;                                /*!< Returns the status of the DMA request signals */
  uint32_t CH12                   :1;                                /*!< Returns the status of the DMA request signals */
  uint32_t CH13                   :1;                                /*!< Returns the status of the DMA request signals */
  uint32_t CH14                   :1;                                /*!< Returns the status of the DMA request signals */
  uint32_t CH15                   :1;                                /*!< Returns the status of the DMA request signals */
} _DMA_WAITONREQ_bits;

/* Bit field positions: */
#define DMA_WAITONREQ_CH0_Pos                 0                      /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_CH1_Pos                 1                      /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_CH2_Pos                 2                      /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_CH3_Pos                 3                      /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_CH4_Pos                 4                      /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_CH5_Pos                 5                      /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_CH6_Pos                 6                      /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_CH7_Pos                 7                      /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_CH8_Pos                 8                      /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_CH9_Pos                 9                      /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_CH10_Pos                10                     /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_CH11_Pos                11                     /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_CH12_Pos                12                     /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_CH13_Pos                13                     /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_CH14_Pos                14                     /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_CH15_Pos                15                     /*!< Returns the status of the DMA request signals */

/* Bit field masks: */
#define DMA_WAITONREQ_CH0_Msk                 0x00000001             /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_CH1_Msk                 0x00000002             /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_CH2_Msk                 0x00000004             /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_CH3_Msk                 0x00000008             /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_CH4_Msk                 0x00000010             /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_CH5_Msk                 0x00000020             /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_CH6_Msk                 0x00000040             /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_CH7_Msk                 0x00000080             /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_CH8_Msk                 0x00000100             /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_CH9_Msk                 0x00000200             /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_CH10_Msk                0x00000400             /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_CH11_Msk                0x00000800             /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_CH12_Msk                0x00001000             /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_CH13_Msk                0x00002000             /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_CH14_Msk                0x00004000             /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_CH15_Msk                0x00008000             /*!< Returns the status of the DMA request signals */

/*--  SWREQ: Channel software request -------------------------------------------------------------------------*/
typedef struct {
  uint32_t CH0                    :1;                                /*!< Set software request on channel */
  uint32_t CH1                    :1;                                /*!< Set software request on channel */
  uint32_t CH2                    :1;                                /*!< Set software request on channel */
  uint32_t CH3                    :1;                                /*!< Set software request on channel */
  uint32_t CH4                    :1;                                /*!< Set software request on channel */
  uint32_t CH5                    :1;                                /*!< Set software request on channel */
  uint32_t CH6                    :1;                                /*!< Set software request on channel */
  uint32_t CH7                    :1;                                /*!< Set software request on channel */
  uint32_t CH8                    :1;                                /*!< Set software request on channel */
  uint32_t CH9                    :1;                                /*!< Set software request on channel */
  uint32_t CH10                   :1;                                /*!< Set software request on channel */
  uint32_t CH11                   :1;                                /*!< Set software request on channel */
  uint32_t CH12                   :1;                                /*!< Set software request on channel */
  uint32_t CH13                   :1;                                /*!< Set software request on channel */
  uint32_t CH14                   :1;                                /*!< Set software request on channel */
  uint32_t CH15                   :1;                                /*!< Set software request on channel */
} _DMA_SWREQ_bits;

/* Bit field positions: */
#define DMA_SWREQ_CH0_Pos                     0                      /*!< Set software request on channel */
#define DMA_SWREQ_CH1_Pos                     1                      /*!< Set software request on channel */
#define DMA_SWREQ_CH2_Pos                     2                      /*!< Set software request on channel */
#define DMA_SWREQ_CH3_Pos                     3                      /*!< Set software request on channel */
#define DMA_SWREQ_CH4_Pos                     4                      /*!< Set software request on channel */
#define DMA_SWREQ_CH5_Pos                     5                      /*!< Set software request on channel */
#define DMA_SWREQ_CH6_Pos                     6                      /*!< Set software request on channel */
#define DMA_SWREQ_CH7_Pos                     7                      /*!< Set software request on channel */
#define DMA_SWREQ_CH8_Pos                     8                      /*!< Set software request on channel */
#define DMA_SWREQ_CH9_Pos                     9                      /*!< Set software request on channel */
#define DMA_SWREQ_CH10_Pos                    10                     /*!< Set software request on channel */
#define DMA_SWREQ_CH11_Pos                    11                     /*!< Set software request on channel */
#define DMA_SWREQ_CH12_Pos                    12                     /*!< Set software request on channel */
#define DMA_SWREQ_CH13_Pos                    13                     /*!< Set software request on channel */
#define DMA_SWREQ_CH14_Pos                    14                     /*!< Set software request on channel */
#define DMA_SWREQ_CH15_Pos                    15                     /*!< Set software request on channel */

/* Bit field masks: */
#define DMA_SWREQ_CH0_Msk                     0x00000001             /*!< Set software request on channel */
#define DMA_SWREQ_CH1_Msk                     0x00000002             /*!< Set software request on channel */
#define DMA_SWREQ_CH2_Msk                     0x00000004             /*!< Set software request on channel */
#define DMA_SWREQ_CH3_Msk                     0x00000008             /*!< Set software request on channel */
#define DMA_SWREQ_CH4_Msk                     0x00000010             /*!< Set software request on channel */
#define DMA_SWREQ_CH5_Msk                     0x00000020             /*!< Set software request on channel */
#define DMA_SWREQ_CH6_Msk                     0x00000040             /*!< Set software request on channel */
#define DMA_SWREQ_CH7_Msk                     0x00000080             /*!< Set software request on channel */
#define DMA_SWREQ_CH8_Msk                     0x00000100             /*!< Set software request on channel */
#define DMA_SWREQ_CH9_Msk                     0x00000200             /*!< Set software request on channel */
#define DMA_SWREQ_CH10_Msk                    0x00000400             /*!< Set software request on channel */
#define DMA_SWREQ_CH11_Msk                    0x00000800             /*!< Set software request on channel */
#define DMA_SWREQ_CH12_Msk                    0x00001000             /*!< Set software request on channel */
#define DMA_SWREQ_CH13_Msk                    0x00002000             /*!< Set software request on channel */
#define DMA_SWREQ_CH14_Msk                    0x00004000             /*!< Set software request on channel */
#define DMA_SWREQ_CH15_Msk                    0x00008000             /*!< Set software request on channel */

/*--  USEBURSTSET: Channel useburst set -----------------------------------------------------------------------*/
typedef struct {
  uint32_t CH0                    :1;                                /*!< Enable single requests */
  uint32_t CH1                    :1;                                /*!< Enable single requests */
  uint32_t CH2                    :1;                                /*!< Enable single requests */
  uint32_t CH3                    :1;                                /*!< Enable single requests */
  uint32_t CH4                    :1;                                /*!< Enable single requests */
  uint32_t CH5                    :1;                                /*!< Enable single requests */
  uint32_t CH6                    :1;                                /*!< Enable single requests */
  uint32_t CH7                    :1;                                /*!< Enable single requests */
  uint32_t CH8                    :1;                                /*!< Enable single requests */
  uint32_t CH9                    :1;                                /*!< Enable single requests */
  uint32_t CH10                   :1;                                /*!< Enable single requests */
  uint32_t CH11                   :1;                                /*!< Enable single requests */
  uint32_t CH12                   :1;                                /*!< Enable single requests */
  uint32_t CH13                   :1;                                /*!< Enable single requests */
  uint32_t CH14                   :1;                                /*!< Enable single requests */
  uint32_t CH15                   :1;                                /*!< Enable single requests */
} _DMA_USEBURSTSET_bits;

/* Bit field positions: */
#define DMA_USEBURSTSET_CH0_Pos               0                      /*!< Enable single requests */
#define DMA_USEBURSTSET_CH1_Pos               1                      /*!< Enable single requests */
#define DMA_USEBURSTSET_CH2_Pos               2                      /*!< Enable single requests */
#define DMA_USEBURSTSET_CH3_Pos               3                      /*!< Enable single requests */
#define DMA_USEBURSTSET_CH4_Pos               4                      /*!< Enable single requests */
#define DMA_USEBURSTSET_CH5_Pos               5                      /*!< Enable single requests */
#define DMA_USEBURSTSET_CH6_Pos               6                      /*!< Enable single requests */
#define DMA_USEBURSTSET_CH7_Pos               7                      /*!< Enable single requests */
#define DMA_USEBURSTSET_CH8_Pos               8                      /*!< Enable single requests */
#define DMA_USEBURSTSET_CH9_Pos               9                      /*!< Enable single requests */
#define DMA_USEBURSTSET_CH10_Pos              10                     /*!< Enable single requests */
#define DMA_USEBURSTSET_CH11_Pos              11                     /*!< Enable single requests */
#define DMA_USEBURSTSET_CH12_Pos              12                     /*!< Enable single requests */
#define DMA_USEBURSTSET_CH13_Pos              13                     /*!< Enable single requests */
#define DMA_USEBURSTSET_CH14_Pos              14                     /*!< Enable single requests */
#define DMA_USEBURSTSET_CH15_Pos              15                     /*!< Enable single requests */

/* Bit field masks: */
#define DMA_USEBURSTSET_CH0_Msk               0x00000001             /*!< Enable single requests */
#define DMA_USEBURSTSET_CH1_Msk               0x00000002             /*!< Enable single requests */
#define DMA_USEBURSTSET_CH2_Msk               0x00000004             /*!< Enable single requests */
#define DMA_USEBURSTSET_CH3_Msk               0x00000008             /*!< Enable single requests */
#define DMA_USEBURSTSET_CH4_Msk               0x00000010             /*!< Enable single requests */
#define DMA_USEBURSTSET_CH5_Msk               0x00000020             /*!< Enable single requests */
#define DMA_USEBURSTSET_CH6_Msk               0x00000040             /*!< Enable single requests */
#define DMA_USEBURSTSET_CH7_Msk               0x00000080             /*!< Enable single requests */
#define DMA_USEBURSTSET_CH8_Msk               0x00000100             /*!< Enable single requests */
#define DMA_USEBURSTSET_CH9_Msk               0x00000200             /*!< Enable single requests */
#define DMA_USEBURSTSET_CH10_Msk              0x00000400             /*!< Enable single requests */
#define DMA_USEBURSTSET_CH11_Msk              0x00000800             /*!< Enable single requests */
#define DMA_USEBURSTSET_CH12_Msk              0x00001000             /*!< Enable single requests */
#define DMA_USEBURSTSET_CH13_Msk              0x00002000             /*!< Enable single requests */
#define DMA_USEBURSTSET_CH14_Msk              0x00004000             /*!< Enable single requests */
#define DMA_USEBURSTSET_CH15_Msk              0x00008000             /*!< Enable single requests */

/*--  USEBURSTCLR: Channel useburst clear ---------------------------------------------------------------------*/
typedef struct {
  uint32_t CH0                    :1;                                /*!< Disable single requests */
  uint32_t CH1                    :1;                                /*!< Disable single requests */
  uint32_t CH2                    :1;                                /*!< Disable single requests */
  uint32_t CH3                    :1;                                /*!< Disable single requests */
  uint32_t CH4                    :1;                                /*!< Disable single requests */
  uint32_t CH5                    :1;                                /*!< Disable single requests */
  uint32_t CH6                    :1;                                /*!< Disable single requests */
  uint32_t CH7                    :1;                                /*!< Disable single requests */
  uint32_t CH8                    :1;                                /*!< Disable single requests */
  uint32_t CH9                    :1;                                /*!< Disable single requests */
  uint32_t CH10                   :1;                                /*!< Disable single requests */
  uint32_t CH11                   :1;                                /*!< Disable single requests */
  uint32_t CH12                   :1;                                /*!< Disable single requests */
  uint32_t CH13                   :1;                                /*!< Disable single requests */
  uint32_t CH14                   :1;                                /*!< Disable single requests */
  uint32_t CH15                   :1;                                /*!< Disable single requests */
} _DMA_USEBURSTCLR_bits;

/* Bit field positions: */
#define DMA_USEBURSTCLR_CH0_Pos               0                      /*!< Disable single requests */
#define DMA_USEBURSTCLR_CH1_Pos               1                      /*!< Disable single requests */
#define DMA_USEBURSTCLR_CH2_Pos               2                      /*!< Disable single requests */
#define DMA_USEBURSTCLR_CH3_Pos               3                      /*!< Disable single requests */
#define DMA_USEBURSTCLR_CH4_Pos               4                      /*!< Disable single requests */
#define DMA_USEBURSTCLR_CH5_Pos               5                      /*!< Disable single requests */
#define DMA_USEBURSTCLR_CH6_Pos               6                      /*!< Disable single requests */
#define DMA_USEBURSTCLR_CH7_Pos               7                      /*!< Disable single requests */
#define DMA_USEBURSTCLR_CH8_Pos               8                      /*!< Disable single requests */
#define DMA_USEBURSTCLR_CH9_Pos               9                      /*!< Disable single requests */
#define DMA_USEBURSTCLR_CH10_Pos              10                     /*!< Disable single requests */
#define DMA_USEBURSTCLR_CH11_Pos              11                     /*!< Disable single requests */
#define DMA_USEBURSTCLR_CH12_Pos              12                     /*!< Disable single requests */
#define DMA_USEBURSTCLR_CH13_Pos              13                     /*!< Disable single requests */
#define DMA_USEBURSTCLR_CH14_Pos              14                     /*!< Disable single requests */
#define DMA_USEBURSTCLR_CH15_Pos              15                     /*!< Disable single requests */

/* Bit field masks: */
#define DMA_USEBURSTCLR_CH0_Msk               0x00000001             /*!< Disable single requests */
#define DMA_USEBURSTCLR_CH1_Msk               0x00000002             /*!< Disable single requests */
#define DMA_USEBURSTCLR_CH2_Msk               0x00000004             /*!< Disable single requests */
#define DMA_USEBURSTCLR_CH3_Msk               0x00000008             /*!< Disable single requests */
#define DMA_USEBURSTCLR_CH4_Msk               0x00000010             /*!< Disable single requests */
#define DMA_USEBURSTCLR_CH5_Msk               0x00000020             /*!< Disable single requests */
#define DMA_USEBURSTCLR_CH6_Msk               0x00000040             /*!< Disable single requests */
#define DMA_USEBURSTCLR_CH7_Msk               0x00000080             /*!< Disable single requests */
#define DMA_USEBURSTCLR_CH8_Msk               0x00000100             /*!< Disable single requests */
#define DMA_USEBURSTCLR_CH9_Msk               0x00000200             /*!< Disable single requests */
#define DMA_USEBURSTCLR_CH10_Msk              0x00000400             /*!< Disable single requests */
#define DMA_USEBURSTCLR_CH11_Msk              0x00000800             /*!< Disable single requests */
#define DMA_USEBURSTCLR_CH12_Msk              0x00001000             /*!< Disable single requests */
#define DMA_USEBURSTCLR_CH13_Msk              0x00002000             /*!< Disable single requests */
#define DMA_USEBURSTCLR_CH14_Msk              0x00004000             /*!< Disable single requests */
#define DMA_USEBURSTCLR_CH15_Msk              0x00008000             /*!< Disable single requests */

/*--  REQMASKSET: Channel request mask set --------------------------------------------------------------------*/
typedef struct {
  uint32_t CH0                    :1;                                /*!< External requests are enabled for channel */
  uint32_t CH1                    :1;                                /*!< External requests are enabled for channel */
  uint32_t CH2                    :1;                                /*!< External requests are enabled for channel */
  uint32_t CH3                    :1;                                /*!< External requests are enabled for channel */
  uint32_t CH4                    :1;                                /*!< External requests are enabled for channel */
  uint32_t CH5                    :1;                                /*!< External requests are enabled for channel */
  uint32_t CH6                    :1;                                /*!< External requests are enabled for channel */
  uint32_t CH7                    :1;                                /*!< External requests are enabled for channel */
  uint32_t CH8                    :1;                                /*!< External requests are enabled for channel */
  uint32_t CH9                    :1;                                /*!< External requests are enabled for channel */
  uint32_t CH10                   :1;                                /*!< External requests are enabled for channel */
  uint32_t CH11                   :1;                                /*!< External requests are enabled for channel */
  uint32_t CH12                   :1;                                /*!< External requests are enabled for channel */
  uint32_t CH13                   :1;                                /*!< External requests are enabled for channel */
  uint32_t CH14                   :1;                                /*!< External requests are enabled for channel */
  uint32_t CH15                   :1;                                /*!< External requests are enabled for channel */
} _DMA_REQMASKSET_bits;

/* Bit field positions: */
#define DMA_REQMASKSET_CH0_Pos                0                      /*!< External requests are enabled for channel */
#define DMA_REQMASKSET_CH1_Pos                1                      /*!< External requests are enabled for channel */
#define DMA_REQMASKSET_CH2_Pos                2                      /*!< External requests are enabled for channel */
#define DMA_REQMASKSET_CH3_Pos                3                      /*!< External requests are enabled for channel */
#define DMA_REQMASKSET_CH4_Pos                4                      /*!< External requests are enabled for channel */
#define DMA_REQMASKSET_CH5_Pos                5                      /*!< External requests are enabled for channel */
#define DMA_REQMASKSET_CH6_Pos                6                      /*!< External requests are enabled for channel */
#define DMA_REQMASKSET_CH7_Pos                7                      /*!< External requests are enabled for channel */
#define DMA_REQMASKSET_CH8_Pos                8                      /*!< External requests are enabled for channel */
#define DMA_REQMASKSET_CH9_Pos                9                      /*!< External requests are enabled for channel */
#define DMA_REQMASKSET_CH10_Pos               10                     /*!< External requests are enabled for channel */
#define DMA_REQMASKSET_CH11_Pos               11                     /*!< External requests are enabled for channel */
#define DMA_REQMASKSET_CH12_Pos               12                     /*!< External requests are enabled for channel */
#define DMA_REQMASKSET_CH13_Pos               13                     /*!< External requests are enabled for channel */
#define DMA_REQMASKSET_CH14_Pos               14                     /*!< External requests are enabled for channel */
#define DMA_REQMASKSET_CH15_Pos               15                     /*!< External requests are enabled for channel */

/* Bit field masks: */
#define DMA_REQMASKSET_CH0_Msk                0x00000001             /*!< External requests are enabled for channel */
#define DMA_REQMASKSET_CH1_Msk                0x00000002             /*!< External requests are enabled for channel */
#define DMA_REQMASKSET_CH2_Msk                0x00000004             /*!< External requests are enabled for channel */
#define DMA_REQMASKSET_CH3_Msk                0x00000008             /*!< External requests are enabled for channel */
#define DMA_REQMASKSET_CH4_Msk                0x00000010             /*!< External requests are enabled for channel */
#define DMA_REQMASKSET_CH5_Msk                0x00000020             /*!< External requests are enabled for channel */
#define DMA_REQMASKSET_CH6_Msk                0x00000040             /*!< External requests are enabled for channel */
#define DMA_REQMASKSET_CH7_Msk                0x00000080             /*!< External requests are enabled for channel */
#define DMA_REQMASKSET_CH8_Msk                0x00000100             /*!< External requests are enabled for channel */
#define DMA_REQMASKSET_CH9_Msk                0x00000200             /*!< External requests are enabled for channel */
#define DMA_REQMASKSET_CH10_Msk               0x00000400             /*!< External requests are enabled for channel */
#define DMA_REQMASKSET_CH11_Msk               0x00000800             /*!< External requests are enabled for channel */
#define DMA_REQMASKSET_CH12_Msk               0x00001000             /*!< External requests are enabled for channel */
#define DMA_REQMASKSET_CH13_Msk               0x00002000             /*!< External requests are enabled for channel */
#define DMA_REQMASKSET_CH14_Msk               0x00004000             /*!< External requests are enabled for channel */
#define DMA_REQMASKSET_CH15_Msk               0x00008000             /*!< External requests are enabled for channel */

/*--  REQMASKCLR: Channel request mask clear ------------------------------------------------------------------*/
typedef struct {
  uint32_t CH0                    :1;                                /*!< External requests are disabled for channel */
  uint32_t CH1                    :1;                                /*!< External requests are disabled for channel */
  uint32_t CH2                    :1;                                /*!< External requests are disabled for channel */
  uint32_t CH3                    :1;                                /*!< External requests are disabled for channel */
  uint32_t CH4                    :1;                                /*!< External requests are disabled for channel */
  uint32_t CH5                    :1;                                /*!< External requests are disabled for channel */
  uint32_t CH6                    :1;                                /*!< External requests are disabled for channel */
  uint32_t CH7                    :1;                                /*!< External requests are disabled for channel */
  uint32_t CH8                    :1;                                /*!< External requests are disabled for channel */
  uint32_t CH9                    :1;                                /*!< External requests are disabled for channel */
  uint32_t CH10                   :1;                                /*!< External requests are disabled for channel */
  uint32_t CH11                   :1;                                /*!< External requests are disabled for channel */
  uint32_t CH12                   :1;                                /*!< External requests are disabled for channel */
  uint32_t CH13                   :1;                                /*!< External requests are disabled for channel */
  uint32_t CH14                   :1;                                /*!< External requests are disabled for channel */
  uint32_t CH15                   :1;                                /*!< External requests are disabled for channel */
} _DMA_REQMASKCLR_bits;

/* Bit field positions: */
#define DMA_REQMASKCLR_CH0_Pos                0                      /*!< External requests are disabled for channel */
#define DMA_REQMASKCLR_CH1_Pos                1                      /*!< External requests are disabled for channel */
#define DMA_REQMASKCLR_CH2_Pos                2                      /*!< External requests are disabled for channel */
#define DMA_REQMASKCLR_CH3_Pos                3                      /*!< External requests are disabled for channel */
#define DMA_REQMASKCLR_CH4_Pos                4                      /*!< External requests are disabled for channel */
#define DMA_REQMASKCLR_CH5_Pos                5                      /*!< External requests are disabled for channel */
#define DMA_REQMASKCLR_CH6_Pos                6                      /*!< External requests are disabled for channel */
#define DMA_REQMASKCLR_CH7_Pos                7                      /*!< External requests are disabled for channel */
#define DMA_REQMASKCLR_CH8_Pos                8                      /*!< External requests are disabled for channel */
#define DMA_REQMASKCLR_CH9_Pos                9                      /*!< External requests are disabled for channel */
#define DMA_REQMASKCLR_CH10_Pos               10                     /*!< External requests are disabled for channel */
#define DMA_REQMASKCLR_CH11_Pos               11                     /*!< External requests are disabled for channel */
#define DMA_REQMASKCLR_CH12_Pos               12                     /*!< External requests are disabled for channel */
#define DMA_REQMASKCLR_CH13_Pos               13                     /*!< External requests are disabled for channel */
#define DMA_REQMASKCLR_CH14_Pos               14                     /*!< External requests are disabled for channel */
#define DMA_REQMASKCLR_CH15_Pos               15                     /*!< External requests are disabled for channel */

/* Bit field masks: */
#define DMA_REQMASKCLR_CH0_Msk                0x00000001             /*!< External requests are disabled for channel */
#define DMA_REQMASKCLR_CH1_Msk                0x00000002             /*!< External requests are disabled for channel */
#define DMA_REQMASKCLR_CH2_Msk                0x00000004             /*!< External requests are disabled for channel */
#define DMA_REQMASKCLR_CH3_Msk                0x00000008             /*!< External requests are disabled for channel */
#define DMA_REQMASKCLR_CH4_Msk                0x00000010             /*!< External requests are disabled for channel */
#define DMA_REQMASKCLR_CH5_Msk                0x00000020             /*!< External requests are disabled for channel */
#define DMA_REQMASKCLR_CH6_Msk                0x00000040             /*!< External requests are disabled for channel */
#define DMA_REQMASKCLR_CH7_Msk                0x00000080             /*!< External requests are disabled for channel */
#define DMA_REQMASKCLR_CH8_Msk                0x00000100             /*!< External requests are disabled for channel */
#define DMA_REQMASKCLR_CH9_Msk                0x00000200             /*!< External requests are disabled for channel */
#define DMA_REQMASKCLR_CH10_Msk               0x00000400             /*!< External requests are disabled for channel */
#define DMA_REQMASKCLR_CH11_Msk               0x00000800             /*!< External requests are disabled for channel */
#define DMA_REQMASKCLR_CH12_Msk               0x00001000             /*!< External requests are disabled for channel */
#define DMA_REQMASKCLR_CH13_Msk               0x00002000             /*!< External requests are disabled for channel */
#define DMA_REQMASKCLR_CH14_Msk               0x00004000             /*!< External requests are disabled for channel */
#define DMA_REQMASKCLR_CH15_Msk               0x00008000             /*!< External requests are disabled for channel */

/*--  ENSET: Channel enable set -------------------------------------------------------------------------------*/
typedef struct {
  uint32_t CH0                    :1;                                /*!< Enable channel */
  uint32_t CH1                    :1;                                /*!< Enable channel */
  uint32_t CH2                    :1;                                /*!< Enable channel */
  uint32_t CH3                    :1;                                /*!< Enable channel */
  uint32_t CH4                    :1;                                /*!< Enable channel */
  uint32_t CH5                    :1;                                /*!< Enable channel */
  uint32_t CH6                    :1;                                /*!< Enable channel */
  uint32_t CH7                    :1;                                /*!< Enable channel */
  uint32_t CH8                    :1;                                /*!< Enable channel */
  uint32_t CH9                    :1;                                /*!< Enable channel */
  uint32_t CH10                   :1;                                /*!< Enable channel */
  uint32_t CH11                   :1;                                /*!< Enable channel */
  uint32_t CH12                   :1;                                /*!< Enable channel */
  uint32_t CH13                   :1;                                /*!< Enable channel */
  uint32_t CH14                   :1;                                /*!< Enable channel */
  uint32_t CH15                   :1;                                /*!< Enable channel */
} _DMA_ENSET_bits;

/* Bit field positions: */
#define DMA_ENSET_CH0_Pos                     0                      /*!< Enable channel */
#define DMA_ENSET_CH1_Pos                     1                      /*!< Enable channel */
#define DMA_ENSET_CH2_Pos                     2                      /*!< Enable channel */
#define DMA_ENSET_CH3_Pos                     3                      /*!< Enable channel */
#define DMA_ENSET_CH4_Pos                     4                      /*!< Enable channel */
#define DMA_ENSET_CH5_Pos                     5                      /*!< Enable channel */
#define DMA_ENSET_CH6_Pos                     6                      /*!< Enable channel */
#define DMA_ENSET_CH7_Pos                     7                      /*!< Enable channel */
#define DMA_ENSET_CH8_Pos                     8                      /*!< Enable channel */
#define DMA_ENSET_CH9_Pos                     9                      /*!< Enable channel */
#define DMA_ENSET_CH10_Pos                    10                     /*!< Enable channel */
#define DMA_ENSET_CH11_Pos                    11                     /*!< Enable channel */
#define DMA_ENSET_CH12_Pos                    12                     /*!< Enable channel */
#define DMA_ENSET_CH13_Pos                    13                     /*!< Enable channel */
#define DMA_ENSET_CH14_Pos                    14                     /*!< Enable channel */
#define DMA_ENSET_CH15_Pos                    15                     /*!< Enable channel */

/* Bit field masks: */
#define DMA_ENSET_CH0_Msk                     0x00000001             /*!< Enable channel */
#define DMA_ENSET_CH1_Msk                     0x00000002             /*!< Enable channel */
#define DMA_ENSET_CH2_Msk                     0x00000004             /*!< Enable channel */
#define DMA_ENSET_CH3_Msk                     0x00000008             /*!< Enable channel */
#define DMA_ENSET_CH4_Msk                     0x00000010             /*!< Enable channel */
#define DMA_ENSET_CH5_Msk                     0x00000020             /*!< Enable channel */
#define DMA_ENSET_CH6_Msk                     0x00000040             /*!< Enable channel */
#define DMA_ENSET_CH7_Msk                     0x00000080             /*!< Enable channel */
#define DMA_ENSET_CH8_Msk                     0x00000100             /*!< Enable channel */
#define DMA_ENSET_CH9_Msk                     0x00000200             /*!< Enable channel */
#define DMA_ENSET_CH10_Msk                    0x00000400             /*!< Enable channel */
#define DMA_ENSET_CH11_Msk                    0x00000800             /*!< Enable channel */
#define DMA_ENSET_CH12_Msk                    0x00001000             /*!< Enable channel */
#define DMA_ENSET_CH13_Msk                    0x00002000             /*!< Enable channel */
#define DMA_ENSET_CH14_Msk                    0x00004000             /*!< Enable channel */
#define DMA_ENSET_CH15_Msk                    0x00008000             /*!< Enable channel */

/*--  ENCLR: Channel enable clear -----------------------------------------------------------------------------*/
typedef struct {
  uint32_t CH0                    :1;                                /*!< Disable channel */
  uint32_t CH1                    :1;                                /*!< Disable channel */
  uint32_t CH2                    :1;                                /*!< Disable channel */
  uint32_t CH3                    :1;                                /*!< Disable channel */
  uint32_t CH4                    :1;                                /*!< Disable channel */
  uint32_t CH5                    :1;                                /*!< Disable channel */
  uint32_t CH6                    :1;                                /*!< Disable channel */
  uint32_t CH7                    :1;                                /*!< Disable channel */
  uint32_t CH8                    :1;                                /*!< Disable channel */
  uint32_t CH9                    :1;                                /*!< Disable channel */
  uint32_t CH10                   :1;                                /*!< Disable channel */
  uint32_t CH11                   :1;                                /*!< Disable channel */
  uint32_t CH12                   :1;                                /*!< Disable channel */
  uint32_t CH13                   :1;                                /*!< Disable channel */
  uint32_t CH14                   :1;                                /*!< Disable channel */
  uint32_t CH15                   :1;                                /*!< Disable channel */
} _DMA_ENCLR_bits;

/* Bit field positions: */
#define DMA_ENCLR_CH0_Pos                     0                      /*!< Disable channel */
#define DMA_ENCLR_CH1_Pos                     1                      /*!< Disable channel */
#define DMA_ENCLR_CH2_Pos                     2                      /*!< Disable channel */
#define DMA_ENCLR_CH3_Pos                     3                      /*!< Disable channel */
#define DMA_ENCLR_CH4_Pos                     4                      /*!< Disable channel */
#define DMA_ENCLR_CH5_Pos                     5                      /*!< Disable channel */
#define DMA_ENCLR_CH6_Pos                     6                      /*!< Disable channel */
#define DMA_ENCLR_CH7_Pos                     7                      /*!< Disable channel */
#define DMA_ENCLR_CH8_Pos                     8                      /*!< Disable channel */
#define DMA_ENCLR_CH9_Pos                     9                      /*!< Disable channel */
#define DMA_ENCLR_CH10_Pos                    10                     /*!< Disable channel */
#define DMA_ENCLR_CH11_Pos                    11                     /*!< Disable channel */
#define DMA_ENCLR_CH12_Pos                    12                     /*!< Disable channel */
#define DMA_ENCLR_CH13_Pos                    13                     /*!< Disable channel */
#define DMA_ENCLR_CH14_Pos                    14                     /*!< Disable channel */
#define DMA_ENCLR_CH15_Pos                    15                     /*!< Disable channel */

/* Bit field masks: */
#define DMA_ENCLR_CH0_Msk                     0x00000001             /*!< Disable channel */
#define DMA_ENCLR_CH1_Msk                     0x00000002             /*!< Disable channel */
#define DMA_ENCLR_CH2_Msk                     0x00000004             /*!< Disable channel */
#define DMA_ENCLR_CH3_Msk                     0x00000008             /*!< Disable channel */
#define DMA_ENCLR_CH4_Msk                     0x00000010             /*!< Disable channel */
#define DMA_ENCLR_CH5_Msk                     0x00000020             /*!< Disable channel */
#define DMA_ENCLR_CH6_Msk                     0x00000040             /*!< Disable channel */
#define DMA_ENCLR_CH7_Msk                     0x00000080             /*!< Disable channel */
#define DMA_ENCLR_CH8_Msk                     0x00000100             /*!< Disable channel */
#define DMA_ENCLR_CH9_Msk                     0x00000200             /*!< Disable channel */
#define DMA_ENCLR_CH10_Msk                    0x00000400             /*!< Disable channel */
#define DMA_ENCLR_CH11_Msk                    0x00000800             /*!< Disable channel */
#define DMA_ENCLR_CH12_Msk                    0x00001000             /*!< Disable channel */
#define DMA_ENCLR_CH13_Msk                    0x00002000             /*!< Disable channel */
#define DMA_ENCLR_CH14_Msk                    0x00004000             /*!< Disable channel */
#define DMA_ENCLR_CH15_Msk                    0x00008000             /*!< Disable channel */

/*--  PRIALTSET: Channel primary-alternate set ----------------------------------------------------------------*/
typedef struct {
  uint32_t CH0                    :1;                                /*!< Set primary / alternate channel control data structure */
  uint32_t CH1                    :1;                                /*!< Set primary / alternate channel control data structure */
  uint32_t CH2                    :1;                                /*!< Set primary / alternate channel control data structure */
  uint32_t CH3                    :1;                                /*!< Set primary / alternate channel control data structure */
  uint32_t CH4                    :1;                                /*!< Set primary / alternate channel control data structure */
  uint32_t CH5                    :1;                                /*!< Set primary / alternate channel control data structure */
  uint32_t CH6                    :1;                                /*!< Set primary / alternate channel control data structure */
  uint32_t CH7                    :1;                                /*!< Set primary / alternate channel control data structure */
  uint32_t CH8                    :1;                                /*!< Set primary / alternate channel control data structure */
  uint32_t CH9                    :1;                                /*!< Set primary / alternate channel control data structure */
  uint32_t CH10                   :1;                                /*!< Set primary / alternate channel control data structure */
  uint32_t CH11                   :1;                                /*!< Set primary / alternate channel control data structure */
  uint32_t CH12                   :1;                                /*!< Set primary / alternate channel control data structure */
  uint32_t CH13                   :1;                                /*!< Set primary / alternate channel control data structure */
  uint32_t CH14                   :1;                                /*!< Set primary / alternate channel control data structure */
  uint32_t CH15                   :1;                                /*!< Set primary / alternate channel control data structure */
} _DMA_PRIALTSET_bits;

/* Bit field positions: */
#define DMA_PRIALTSET_CH0_Pos                 0                      /*!< Set primary / alternate channel control data structure */
#define DMA_PRIALTSET_CH1_Pos                 1                      /*!< Set primary / alternate channel control data structure */
#define DMA_PRIALTSET_CH2_Pos                 2                      /*!< Set primary / alternate channel control data structure */
#define DMA_PRIALTSET_CH3_Pos                 3                      /*!< Set primary / alternate channel control data structure */
#define DMA_PRIALTSET_CH4_Pos                 4                      /*!< Set primary / alternate channel control data structure */
#define DMA_PRIALTSET_CH5_Pos                 5                      /*!< Set primary / alternate channel control data structure */
#define DMA_PRIALTSET_CH6_Pos                 6                      /*!< Set primary / alternate channel control data structure */
#define DMA_PRIALTSET_CH7_Pos                 7                      /*!< Set primary / alternate channel control data structure */
#define DMA_PRIALTSET_CH8_Pos                 8                      /*!< Set primary / alternate channel control data structure */
#define DMA_PRIALTSET_CH9_Pos                 9                      /*!< Set primary / alternate channel control data structure */
#define DMA_PRIALTSET_CH10_Pos                10                     /*!< Set primary / alternate channel control data structure */
#define DMA_PRIALTSET_CH11_Pos                11                     /*!< Set primary / alternate channel control data structure */
#define DMA_PRIALTSET_CH12_Pos                12                     /*!< Set primary / alternate channel control data structure */
#define DMA_PRIALTSET_CH13_Pos                13                     /*!< Set primary / alternate channel control data structure */
#define DMA_PRIALTSET_CH14_Pos                14                     /*!< Set primary / alternate channel control data structure */
#define DMA_PRIALTSET_CH15_Pos                15                     /*!< Set primary / alternate channel control data structure */

/* Bit field masks: */
#define DMA_PRIALTSET_CH0_Msk                 0x00000001             /*!< Set primary / alternate channel control data structure */
#define DMA_PRIALTSET_CH1_Msk                 0x00000002             /*!< Set primary / alternate channel control data structure */
#define DMA_PRIALTSET_CH2_Msk                 0x00000004             /*!< Set primary / alternate channel control data structure */
#define DMA_PRIALTSET_CH3_Msk                 0x00000008             /*!< Set primary / alternate channel control data structure */
#define DMA_PRIALTSET_CH4_Msk                 0x00000010             /*!< Set primary / alternate channel control data structure */
#define DMA_PRIALTSET_CH5_Msk                 0x00000020             /*!< Set primary / alternate channel control data structure */
#define DMA_PRIALTSET_CH6_Msk                 0x00000040             /*!< Set primary / alternate channel control data structure */
#define DMA_PRIALTSET_CH7_Msk                 0x00000080             /*!< Set primary / alternate channel control data structure */
#define DMA_PRIALTSET_CH8_Msk                 0x00000100             /*!< Set primary / alternate channel control data structure */
#define DMA_PRIALTSET_CH9_Msk                 0x00000200             /*!< Set primary / alternate channel control data structure */
#define DMA_PRIALTSET_CH10_Msk                0x00000400             /*!< Set primary / alternate channel control data structure */
#define DMA_PRIALTSET_CH11_Msk                0x00000800             /*!< Set primary / alternate channel control data structure */
#define DMA_PRIALTSET_CH12_Msk                0x00001000             /*!< Set primary / alternate channel control data structure */
#define DMA_PRIALTSET_CH13_Msk                0x00002000             /*!< Set primary / alternate channel control data structure */
#define DMA_PRIALTSET_CH14_Msk                0x00004000             /*!< Set primary / alternate channel control data structure */
#define DMA_PRIALTSET_CH15_Msk                0x00008000             /*!< Set primary / alternate channel control data structure */

/*--  PRIALTCLR: Channel primary-alternate clear --------------------------------------------------------------*/
typedef struct {
  uint32_t CH0                    :1;                                /*!< Clear primary / alternate channel control data structure */
  uint32_t CH1                    :1;                                /*!< Clear primary / alternate channel control data structure */
  uint32_t CH2                    :1;                                /*!< Clear primary / alternate channel control data structure */
  uint32_t CH3                    :1;                                /*!< Clear primary / alternate channel control data structure */
  uint32_t CH4                    :1;                                /*!< Clear primary / alternate channel control data structure */
  uint32_t CH5                    :1;                                /*!< Clear primary / alternate channel control data structure */
  uint32_t CH6                    :1;                                /*!< Clear primary / alternate channel control data structure */
  uint32_t CH7                    :1;                                /*!< Clear primary / alternate channel control data structure */
  uint32_t CH8                    :1;                                /*!< Clear primary / alternate channel control data structure */
  uint32_t CH9                    :1;                                /*!< Clear primary / alternate channel control data structure */
  uint32_t CH10                   :1;                                /*!< Clear primary / alternate channel control data structure */
  uint32_t CH11                   :1;                                /*!< Clear primary / alternate channel control data structure */
  uint32_t CH12                   :1;                                /*!< Clear primary / alternate channel control data structure */
  uint32_t CH13                   :1;                                /*!< Clear primary / alternate channel control data structure */
  uint32_t CH14                   :1;                                /*!< Clear primary / alternate channel control data structure */
  uint32_t CH15                   :1;                                /*!< Clear primary / alternate channel control data structure */
} _DMA_PRIALTCLR_bits;

/* Bit field positions: */
#define DMA_PRIALTCLR_CH0_Pos                 0                      /*!< Clear primary / alternate channel control data structure */
#define DMA_PRIALTCLR_CH1_Pos                 1                      /*!< Clear primary / alternate channel control data structure */
#define DMA_PRIALTCLR_CH2_Pos                 2                      /*!< Clear primary / alternate channel control data structure */
#define DMA_PRIALTCLR_CH3_Pos                 3                      /*!< Clear primary / alternate channel control data structure */
#define DMA_PRIALTCLR_CH4_Pos                 4                      /*!< Clear primary / alternate channel control data structure */
#define DMA_PRIALTCLR_CH5_Pos                 5                      /*!< Clear primary / alternate channel control data structure */
#define DMA_PRIALTCLR_CH6_Pos                 6                      /*!< Clear primary / alternate channel control data structure */
#define DMA_PRIALTCLR_CH7_Pos                 7                      /*!< Clear primary / alternate channel control data structure */
#define DMA_PRIALTCLR_CH8_Pos                 8                      /*!< Clear primary / alternate channel control data structure */
#define DMA_PRIALTCLR_CH9_Pos                 9                      /*!< Clear primary / alternate channel control data structure */
#define DMA_PRIALTCLR_CH10_Pos                10                     /*!< Clear primary / alternate channel control data structure */
#define DMA_PRIALTCLR_CH11_Pos                11                     /*!< Clear primary / alternate channel control data structure */
#define DMA_PRIALTCLR_CH12_Pos                12                     /*!< Clear primary / alternate channel control data structure */
#define DMA_PRIALTCLR_CH13_Pos                13                     /*!< Clear primary / alternate channel control data structure */
#define DMA_PRIALTCLR_CH14_Pos                14                     /*!< Clear primary / alternate channel control data structure */
#define DMA_PRIALTCLR_CH15_Pos                15                     /*!< Clear primary / alternate channel control data structure */

/* Bit field masks: */
#define DMA_PRIALTCLR_CH0_Msk                 0x00000001             /*!< Clear primary / alternate channel control data structure */
#define DMA_PRIALTCLR_CH1_Msk                 0x00000002             /*!< Clear primary / alternate channel control data structure */
#define DMA_PRIALTCLR_CH2_Msk                 0x00000004             /*!< Clear primary / alternate channel control data structure */
#define DMA_PRIALTCLR_CH3_Msk                 0x00000008             /*!< Clear primary / alternate channel control data structure */
#define DMA_PRIALTCLR_CH4_Msk                 0x00000010             /*!< Clear primary / alternate channel control data structure */
#define DMA_PRIALTCLR_CH5_Msk                 0x00000020             /*!< Clear primary / alternate channel control data structure */
#define DMA_PRIALTCLR_CH6_Msk                 0x00000040             /*!< Clear primary / alternate channel control data structure */
#define DMA_PRIALTCLR_CH7_Msk                 0x00000080             /*!< Clear primary / alternate channel control data structure */
#define DMA_PRIALTCLR_CH8_Msk                 0x00000100             /*!< Clear primary / alternate channel control data structure */
#define DMA_PRIALTCLR_CH9_Msk                 0x00000200             /*!< Clear primary / alternate channel control data structure */
#define DMA_PRIALTCLR_CH10_Msk                0x00000400             /*!< Clear primary / alternate channel control data structure */
#define DMA_PRIALTCLR_CH11_Msk                0x00000800             /*!< Clear primary / alternate channel control data structure */
#define DMA_PRIALTCLR_CH12_Msk                0x00001000             /*!< Clear primary / alternate channel control data structure */
#define DMA_PRIALTCLR_CH13_Msk                0x00002000             /*!< Clear primary / alternate channel control data structure */
#define DMA_PRIALTCLR_CH14_Msk                0x00004000             /*!< Clear primary / alternate channel control data structure */
#define DMA_PRIALTCLR_CH15_Msk                0x00008000             /*!< Clear primary / alternate channel control data structure */

/*--  PRIORITYSET: Channel priority set -----------------------------------------------------------------------*/
typedef struct {
  uint32_t CH0                    :1;                                /*!< Set the priority of channel */
  uint32_t CH1                    :1;                                /*!< Set the priority of channel */
  uint32_t CH2                    :1;                                /*!< Set the priority of channel */
  uint32_t CH3                    :1;                                /*!< Set the priority of channel */
  uint32_t CH4                    :1;                                /*!< Set the priority of channel */
  uint32_t CH5                    :1;                                /*!< Set the priority of channel */
  uint32_t CH6                    :1;                                /*!< Set the priority of channel */
  uint32_t CH7                    :1;                                /*!< Set the priority of channel */
  uint32_t CH8                    :1;                                /*!< Set the priority of channel */
  uint32_t CH9                    :1;                                /*!< Set the priority of channel */
  uint32_t CH10                   :1;                                /*!< Set the priority of channel */
  uint32_t CH11                   :1;                                /*!< Set the priority of channel */
  uint32_t CH12                   :1;                                /*!< Set the priority of channel */
  uint32_t CH13                   :1;                                /*!< Set the priority of channel */
  uint32_t CH14                   :1;                                /*!< Set the priority of channel */
  uint32_t CH15                   :1;                                /*!< Set the priority of channel */
} _DMA_PRIORITYSET_bits;

/* Bit field positions: */
#define DMA_PRIORITYSET_CH0_Pos               0                      /*!< Set the priority of channel */
#define DMA_PRIORITYSET_CH1_Pos               1                      /*!< Set the priority of channel */
#define DMA_PRIORITYSET_CH2_Pos               2                      /*!< Set the priority of channel */
#define DMA_PRIORITYSET_CH3_Pos               3                      /*!< Set the priority of channel */
#define DMA_PRIORITYSET_CH4_Pos               4                      /*!< Set the priority of channel */
#define DMA_PRIORITYSET_CH5_Pos               5                      /*!< Set the priority of channel */
#define DMA_PRIORITYSET_CH6_Pos               6                      /*!< Set the priority of channel */
#define DMA_PRIORITYSET_CH7_Pos               7                      /*!< Set the priority of channel */
#define DMA_PRIORITYSET_CH8_Pos               8                      /*!< Set the priority of channel */
#define DMA_PRIORITYSET_CH9_Pos               9                      /*!< Set the priority of channel */
#define DMA_PRIORITYSET_CH10_Pos              10                     /*!< Set the priority of channel */
#define DMA_PRIORITYSET_CH11_Pos              11                     /*!< Set the priority of channel */
#define DMA_PRIORITYSET_CH12_Pos              12                     /*!< Set the priority of channel */
#define DMA_PRIORITYSET_CH13_Pos              13                     /*!< Set the priority of channel */
#define DMA_PRIORITYSET_CH14_Pos              14                     /*!< Set the priority of channel */
#define DMA_PRIORITYSET_CH15_Pos              15                     /*!< Set the priority of channel */

/* Bit field masks: */
#define DMA_PRIORITYSET_CH0_Msk               0x00000001             /*!< Set the priority of channel */
#define DMA_PRIORITYSET_CH1_Msk               0x00000002             /*!< Set the priority of channel */
#define DMA_PRIORITYSET_CH2_Msk               0x00000004             /*!< Set the priority of channel */
#define DMA_PRIORITYSET_CH3_Msk               0x00000008             /*!< Set the priority of channel */
#define DMA_PRIORITYSET_CH4_Msk               0x00000010             /*!< Set the priority of channel */
#define DMA_PRIORITYSET_CH5_Msk               0x00000020             /*!< Set the priority of channel */
#define DMA_PRIORITYSET_CH6_Msk               0x00000040             /*!< Set the priority of channel */
#define DMA_PRIORITYSET_CH7_Msk               0x00000080             /*!< Set the priority of channel */
#define DMA_PRIORITYSET_CH8_Msk               0x00000100             /*!< Set the priority of channel */
#define DMA_PRIORITYSET_CH9_Msk               0x00000200             /*!< Set the priority of channel */
#define DMA_PRIORITYSET_CH10_Msk              0x00000400             /*!< Set the priority of channel */
#define DMA_PRIORITYSET_CH11_Msk              0x00000800             /*!< Set the priority of channel */
#define DMA_PRIORITYSET_CH12_Msk              0x00001000             /*!< Set the priority of channel */
#define DMA_PRIORITYSET_CH13_Msk              0x00002000             /*!< Set the priority of channel */
#define DMA_PRIORITYSET_CH14_Msk              0x00004000             /*!< Set the priority of channel */
#define DMA_PRIORITYSET_CH15_Msk              0x00008000             /*!< Set the priority of channel */

/*--  PRIORITYCLR: Channel priority clear ---------------------------------------------------------------------*/
typedef struct {
  uint32_t CH0                    :1;                                /*!< Clear the priority */
  uint32_t CH1                    :1;                                /*!< Clear the priority */
  uint32_t CH2                    :1;                                /*!< Clear the priority */
  uint32_t CH3                    :1;                                /*!< Clear the priority */
  uint32_t CH4                    :1;                                /*!< Clear the priority */
  uint32_t CH5                    :1;                                /*!< Clear the priority */
  uint32_t CH6                    :1;                                /*!< Clear the priority */
  uint32_t CH7                    :1;                                /*!< Clear the priority */
  uint32_t CH8                    :1;                                /*!< Clear the priority */
  uint32_t CH9                    :1;                                /*!< Clear the priority */
  uint32_t CH10                   :1;                                /*!< Clear the priority */
  uint32_t CH11                   :1;                                /*!< Clear the priority */
  uint32_t CH12                   :1;                                /*!< Clear the priority */
  uint32_t CH13                   :1;                                /*!< Clear the priority */
  uint32_t CH14                   :1;                                /*!< Clear the priority */
  uint32_t CH15                   :1;                                /*!< Clear the priority */
} _DMA_PRIORITYCLR_bits;

/* Bit field positions: */
#define DMA_PRIORITYCLR_CH0_Pos               0                      /*!< Clear the priority */
#define DMA_PRIORITYCLR_CH1_Pos               1                      /*!< Clear the priority */
#define DMA_PRIORITYCLR_CH2_Pos               2                      /*!< Clear the priority */
#define DMA_PRIORITYCLR_CH3_Pos               3                      /*!< Clear the priority */
#define DMA_PRIORITYCLR_CH4_Pos               4                      /*!< Clear the priority */
#define DMA_PRIORITYCLR_CH5_Pos               5                      /*!< Clear the priority */
#define DMA_PRIORITYCLR_CH6_Pos               6                      /*!< Clear the priority */
#define DMA_PRIORITYCLR_CH7_Pos               7                      /*!< Clear the priority */
#define DMA_PRIORITYCLR_CH8_Pos               8                      /*!< Clear the priority */
#define DMA_PRIORITYCLR_CH9_Pos               9                      /*!< Clear the priority */
#define DMA_PRIORITYCLR_CH10_Pos              10                     /*!< Clear the priority */
#define DMA_PRIORITYCLR_CH11_Pos              11                     /*!< Clear the priority */
#define DMA_PRIORITYCLR_CH12_Pos              12                     /*!< Clear the priority */
#define DMA_PRIORITYCLR_CH13_Pos              13                     /*!< Clear the priority */
#define DMA_PRIORITYCLR_CH14_Pos              14                     /*!< Clear the priority */
#define DMA_PRIORITYCLR_CH15_Pos              15                     /*!< Clear the priority */

/* Bit field masks: */
#define DMA_PRIORITYCLR_CH0_Msk               0x00000001             /*!< Clear the priority */
#define DMA_PRIORITYCLR_CH1_Msk               0x00000002             /*!< Clear the priority */
#define DMA_PRIORITYCLR_CH2_Msk               0x00000004             /*!< Clear the priority */
#define DMA_PRIORITYCLR_CH3_Msk               0x00000008             /*!< Clear the priority */
#define DMA_PRIORITYCLR_CH4_Msk               0x00000010             /*!< Clear the priority */
#define DMA_PRIORITYCLR_CH5_Msk               0x00000020             /*!< Clear the priority */
#define DMA_PRIORITYCLR_CH6_Msk               0x00000040             /*!< Clear the priority */
#define DMA_PRIORITYCLR_CH7_Msk               0x00000080             /*!< Clear the priority */
#define DMA_PRIORITYCLR_CH8_Msk               0x00000100             /*!< Clear the priority */
#define DMA_PRIORITYCLR_CH9_Msk               0x00000200             /*!< Clear the priority */
#define DMA_PRIORITYCLR_CH10_Msk              0x00000400             /*!< Clear the priority */
#define DMA_PRIORITYCLR_CH11_Msk              0x00000800             /*!< Clear the priority */
#define DMA_PRIORITYCLR_CH12_Msk              0x00001000             /*!< Clear the priority */
#define DMA_PRIORITYCLR_CH13_Msk              0x00002000             /*!< Clear the priority */
#define DMA_PRIORITYCLR_CH14_Msk              0x00004000             /*!< Clear the priority */
#define DMA_PRIORITYCLR_CH15_Msk              0x00008000             /*!< Clear the priority */

/*--  ERRCLR: Bus error register ------------------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :1;                                /*!< Indicate Error on bus AHB-Lite */
} _DMA_ERRCLR_bits;

/* Bit field positions: */
#define DMA_ERRCLR_VAL_Pos                    0                      /*!< Indicate Error on bus AHB-Lite */

/* Bit field masks: */
#define DMA_ERRCLR_VAL_Msk                    0x00000001             /*!< Indicate Error on bus AHB-Lite */

typedef struct {
  union {                                                               /*!< Status DMA register */
    __I uint32_t STATUS;                                             /*!< STATUS    : type used for word access */
    __I _DMA_STATUS_bits  STATUS_bit;                                /*!< STATUS_bit: structure used for bit access */
  };
  union {                                                               /*!< DMA configuration register */
    __O uint32_t CFG;                                                /*!< CFG    : type used for word access */
    __O _DMA_CFG_bits  CFG_bit;                                      /*!< CFG_bit: structure used for bit access */
  };
  union {                                                               /*!< Channel control data base pointer */
    __IO uint32_t BASEPTR;                                           /*!< BASEPTR    : type used for word access */
    __IO _DMA_BASEPTR_bits  BASEPTR_bit;                             /*!< BASEPTR_bit: structure used for bit access */
  };
  union {                                                               /*!< Channel alternate control data base pointer */
    __I uint32_t ALTBASEPTR;                                           /*!< ALTBASEPTR    : type used for word access */
    __I _DMA_ALTBASEPTR_bits  ALTBASEPTR_bit;                        /*!< ALTBASEPTR_bit: structure used for bit access */
  };
  union {                                                               /*!< Channel wait on request status */
    __I uint32_t WAITONREQ;                                           /*!< WAITONREQ    : type used for word access */
    __I _DMA_WAITONREQ_bits  WAITONREQ_bit;                          /*!< WAITONREQ_bit: structure used for bit access */
  };
  union {                                                               /*!< Channel software request */
    __O uint32_t SWREQ;                                              /*!< SWREQ    : type used for word access */
    __O _DMA_SWREQ_bits  SWREQ_bit;                                  /*!< SWREQ_bit: structure used for bit access */
  };
  union {                                                               /*!< Channel useburst set */
    __IO uint32_t USEBURSTSET;                                           /*!< USEBURSTSET    : type used for word access */
    __IO _DMA_USEBURSTSET_bits  USEBURSTSET_bit;                     /*!< USEBURSTSET_bit: structure used for bit access */
  };
  union {                                                               /*!< Channel useburst clear */
    __O uint32_t USEBURSTCLR;                                           /*!< USEBURSTCLR    : type used for word access */
    __O _DMA_USEBURSTCLR_bits  USEBURSTCLR_bit;                      /*!< USEBURSTCLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Channel request mask set */
    __IO uint32_t REQMASKSET;                                           /*!< REQMASKSET    : type used for word access */
    __IO _DMA_REQMASKSET_bits  REQMASKSET_bit;                       /*!< REQMASKSET_bit: structure used for bit access */
  };
  union {                                                               /*!< Channel request mask clear */
    __O uint32_t REQMASKCLR;                                           /*!< REQMASKCLR    : type used for word access */
    __O _DMA_REQMASKCLR_bits  REQMASKCLR_bit;                        /*!< REQMASKCLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Channel enable set */
    __IO uint32_t ENSET;                                             /*!< ENSET    : type used for word access */
    __IO _DMA_ENSET_bits  ENSET_bit;                                 /*!< ENSET_bit: structure used for bit access */
  };
  union {                                                               /*!< Channel enable clear */
    __O uint32_t ENCLR;                                              /*!< ENCLR    : type used for word access */
    __O _DMA_ENCLR_bits  ENCLR_bit;                                  /*!< ENCLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Channel primary-alternate set */
    __IO uint32_t PRIALTSET;                                           /*!< PRIALTSET    : type used for word access */
    __IO _DMA_PRIALTSET_bits  PRIALTSET_bit;                         /*!< PRIALTSET_bit: structure used for bit access */
  };
  union {                                                               /*!< Channel primary-alternate clear */
    __O uint32_t PRIALTCLR;                                           /*!< PRIALTCLR    : type used for word access */
    __O _DMA_PRIALTCLR_bits  PRIALTCLR_bit;                          /*!< PRIALTCLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Channel priority set */
    __IO uint32_t PRIORITYSET;                                           /*!< PRIORITYSET    : type used for word access */
    __IO _DMA_PRIORITYSET_bits  PRIORITYSET_bit;                     /*!< PRIORITYSET_bit: structure used for bit access */
  };
  union {                                                               /*!< Channel priority clear */
    __O uint32_t PRIORITYCLR;                                           /*!< PRIORITYCLR    : type used for word access */
    __O _DMA_PRIORITYCLR_bits  PRIORITYCLR_bit;                      /*!< PRIORITYCLR_bit: structure used for bit access */
  };
    __IO uint32_t Reserved0[3];
  union {                                                               /*!< Bus error register */
    __IO uint32_t ERRCLR;                                            /*!< ERRCLR    : type used for word access */
    __IO _DMA_ERRCLR_bits  ERRCLR_bit;                               /*!< ERRCLR_bit: structure used for bit access */
  };
} DMA_TypeDef;

/******************************************************************************/
/*                         MFLASH registers                                   */
/******************************************************************************/

/*--  ADDR: Address Register ----------------------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!< Address value for flash operations */
} _MFLASH_ADDR_bits;

/* Bit field positions: */
#define MFLASH_ADDR_VAL_Pos                   0                      /*!< Address value for flash operations */

/* Bit field masks: */
#define MFLASH_ADDR_VAL_Msk                   0xFFFFFFFF             /*!< Address value for flash operations */

/*-- DATA: DATA: Data Register --------------------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!< Data register value for flash operations */
} _MFLASH_DATA_DATA_bits;

/* Bit field positions: */
#define MFLASH_DATA_DATA_VAL_Pos              0                      /*!< Data register value for flash operations */

/* Bit field masks: */
#define MFLASH_DATA_DATA_VAL_Msk              0xFFFFFFFF             /*!< Data register value for flash operations */

/*--  CMD: Command Register -----------------------------------------------------------------------------------*/
typedef struct {
  uint32_t RD                     :1;                                /*!< Read enable command */
  uint32_t WR                     :1;                                /*!< Write enable command */
  uint32_t ERSEC                  :1;                                /*!< Erase sector enable command */
  uint32_t ERALL                  :1;                                /*!< Erase all enable command */
  uint32_t                        :4;                                /*!< RESERVED */
  uint32_t NVRON                  :1;                                /*!< NVR access bit */
  uint32_t                        :7;                                /*!< RESERVED */
  uint32_t KEY                    :16;                               /*!< Magic Key for flash access "C0DE" */
} _MFLASH_CMD_bits;

/* Bit field positions: */
#define MFLASH_CMD_RD_Pos                     0                      /*!< Read enable command */
#define MFLASH_CMD_WR_Pos                     1                      /*!< Write enable command */
#define MFLASH_CMD_ERSEC_Pos                  2                      /*!< Erase sector enable command */
#define MFLASH_CMD_ERALL_Pos                  3                      /*!< Erase all enable command */
#define MFLASH_CMD_NVRON_Pos                  8                      /*!< NVR access bit */
#define MFLASH_CMD_KEY_Pos                    16                     /*!< Magic Key for flash access "C0DE" */

/* Bit field masks: */
#define MFLASH_CMD_RD_Msk                     0x00000001             /*!< Read enable command */
#define MFLASH_CMD_WR_Msk                     0x00000002             /*!< Write enable command */
#define MFLASH_CMD_ERSEC_Msk                  0x00000004             /*!< Erase sector enable command */
#define MFLASH_CMD_ERALL_Msk                  0x00000008             /*!< Erase all enable command */
#define MFLASH_CMD_NVRON_Msk                  0x00000100             /*!< NVR access bit */
#define MFLASH_CMD_KEY_Msk                    0xFFFF0000             /*!< Magic Key for flash access "C0DE" */

/* Bit field enums: */
typedef enum {
  MFLASH_CMD_KEY_Access                      = 0xC0DE,               /*!< magic Key for flash access */
} MFLASH_CMD_KEY_Enum;

/*--  STAT: Status Register -----------------------------------------------------------------------------------*/
typedef struct {
  uint32_t BUSY                   :1;                                /*!< Busy status bit when command is processing */
  uint32_t IRQF                   :1;                                /*!< IRQ Flag set when command done. Set by hardware only if IRQEN bit is set. */
} _MFLASH_STAT_bits;

/* Bit field positions: */
#define MFLASH_STAT_BUSY_Pos                  0                      /*!< Busy status bit when command is processing */
#define MFLASH_STAT_IRQF_Pos                  1                      /*!< IRQ Flag set when command done. Set by hardware only if IRQEN bit is set. */

/* Bit field masks: */
#define MFLASH_STAT_BUSY_Msk                  0x00000001             /*!< Busy status bit when command is processing */
#define MFLASH_STAT_IRQF_Msk                  0x00000002             /*!< IRQ Flag set when command done. Set by hardware only if IRQEN bit is set. */

/*--  CTRL: Control Register ----------------------------------------------------------------------------------*/
typedef struct {
  uint32_t PEN                    :1;                                /*!< Prefetch enable bit */
  uint32_t ICEN                   :1;                                /*!< I-Cache enable bit */
  uint32_t DCEN                   :1;                                /*!< D-Cache enable bit */
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t IRQEN                  :1;                                /*!< Interrupt enable bit */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t IFLUSH                 :1;                                /*!< Flush I-Cache request bit */
  uint32_t DFLUSH                 :1;                                /*!< Flush D-Cache request bit */
  uint32_t                        :6;                                /*!< RESERVED */
  uint32_t LAT                    :4;                                /*!< Flash latency */
} _MFLASH_CTRL_bits;

/* Bit field positions: */
#define MFLASH_CTRL_PEN_Pos                   0                      /*!< Prefetch enable bit */
#define MFLASH_CTRL_ICEN_Pos                  1                      /*!< I-Cache enable bit */
#define MFLASH_CTRL_DCEN_Pos                  2                      /*!< D-Cache enable bit */
#define MFLASH_CTRL_IRQEN_Pos                 4                      /*!< Interrupt enable bit */
#define MFLASH_CTRL_IFLUSH_Pos                8                      /*!< Flush I-Cache request bit */
#define MFLASH_CTRL_DFLUSH_Pos                9                      /*!< Flush D-Cache request bit */
#define MFLASH_CTRL_LAT_Pos                   16                     /*!< Flash latency */

/* Bit field masks: */
#define MFLASH_CTRL_PEN_Msk                   0x00000001             /*!< Prefetch enable bit */
#define MFLASH_CTRL_ICEN_Msk                  0x00000002             /*!< I-Cache enable bit */
#define MFLASH_CTRL_DCEN_Msk                  0x00000004             /*!< D-Cache enable bit */
#define MFLASH_CTRL_IRQEN_Msk                 0x00000010             /*!< Interrupt enable bit */
#define MFLASH_CTRL_IFLUSH_Msk                0x00000100             /*!< Flush I-Cache request bit */
#define MFLASH_CTRL_DFLUSH_Msk                0x00000200             /*!< Flush D-Cache request bit */
#define MFLASH_CTRL_LAT_Msk                   0x000F0000             /*!< Flash latency */

/*--  CTEST: Cache Test Register ------------------------------------------------------------------------------*/
typedef struct {
  uint32_t ICTEN                  :1;                                /*!< I-Cache test enable bit */
  uint32_t DCTEN                  :1;                                /*!< D-Cache test enable bit */
} _MFLASH_CTEST_bits;

/* Bit field positions: */
#define MFLASH_CTEST_ICTEN_Pos                0                      /*!< I-Cache test enable bit */
#define MFLASH_CTEST_DCTEN_Pos                1                      /*!< D-Cache test enable bit */

/* Bit field masks: */
#define MFLASH_CTEST_ICTEN_Msk                0x00000001             /*!< I-Cache test enable bit */
#define MFLASH_CTEST_DCTEN_Msk                0x00000002             /*!< D-Cache test enable bit */

/*--  ICSTAT: ICACHE Status Register --------------------------------------------------------------------------*/
typedef struct {
  uint32_t BUSY                   :1;                                /*!< Busy flag for I-Cache flush/test system */
  uint32_t OK                     :1;                                /*!< OK status for I-Cache test system */
  uint32_t FAIL                   :1;                                /*!< FAIL status for I-Cache test system */
} _MFLASH_ICSTAT_bits;

/* Bit field positions: */
#define MFLASH_ICSTAT_BUSY_Pos                0                      /*!< Busy flag for I-Cache flush/test system */
#define MFLASH_ICSTAT_OK_Pos                  1                      /*!< OK status for I-Cache test system */
#define MFLASH_ICSTAT_FAIL_Pos                2                      /*!< FAIL status for I-Cache test system */

/* Bit field masks: */
#define MFLASH_ICSTAT_BUSY_Msk                0x00000001             /*!< Busy flag for I-Cache flush/test system */
#define MFLASH_ICSTAT_OK_Msk                  0x00000002             /*!< OK status for I-Cache test system */
#define MFLASH_ICSTAT_FAIL_Msk                0x00000004             /*!< FAIL status for I-Cache test system */

/*--  DCSTAT: DCACHE Status Register --------------------------------------------------------------------------*/
typedef struct {
  uint32_t BUSY                   :1;                                /*!< Busy flag for D-Cache flush/test system */
  uint32_t OK                     :1;                                /*!< OK status for D-Cache test system */
  uint32_t FAIL                   :1;                                /*!< FAIL status for D-Cache test system */
} _MFLASH_DCSTAT_bits;

/* Bit field positions: */
#define MFLASH_DCSTAT_BUSY_Pos                0                      /*!< Busy flag for D-Cache flush/test system */
#define MFLASH_DCSTAT_OK_Pos                  1                      /*!< OK status for D-Cache test system */
#define MFLASH_DCSTAT_FAIL_Pos                2                      /*!< FAIL status for D-Cache test system */

/* Bit field masks: */
#define MFLASH_DCSTAT_BUSY_Msk                0x00000001             /*!< Busy flag for D-Cache flush/test system */
#define MFLASH_DCSTAT_OK_Msk                  0x00000002             /*!< OK status for D-Cache test system */
#define MFLASH_DCSTAT_FAIL_Msk                0x00000004             /*!< FAIL status for D-Cache test system */

/*--  TRH: Read hold time register ----------------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!< Read hold time value in cycles */
} _MFLASH_TRH_bits;

/* Bit field positions: */
#define MFLASH_TRH_VAL_Pos                    0                      /*!< Read hold time value in cycles */

/* Bit field masks: */
#define MFLASH_TRH_VAL_Msk                    0xFFFFFFFF             /*!< Read hold time value in cycles */

/*--  TNVS: Time to WEn register ------------------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!< Time to WEn value in cycles */
} _MFLASH_TNVS_bits;

/* Bit field positions: */
#define MFLASH_TNVS_VAL_Pos                   0                      /*!< Time to WEn value in cycles */

/* Bit field masks: */
#define MFLASH_TNVS_VAL_Msk                   0xFFFFFFFF             /*!< Time to WEn value in cycles */

/*--  TPGS: Time from Wen low to PROG2 high register ----------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!< Timefrom Wen low to PROG2 high value in cycles */
} _MFLASH_TPGS_bits;

/* Bit field positions: */
#define MFLASH_TPGS_VAL_Pos                   0                      /*!< Timefrom Wen low to PROG2 high value in cycles */

/* Bit field masks: */
#define MFLASH_TPGS_VAL_Msk                   0xFFFFFFFF             /*!< Timefrom Wen low to PROG2 high value in cycles */

/*--  TPROG: Program byte time register -----------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!< Program byte time value in cycles */
} _MFLASH_TPROG_bits;

/* Bit field positions: */
#define MFLASH_TPROG_VAL_Pos                  0                      /*!< Program byte time value in cycles */

/* Bit field masks: */
#define MFLASH_TPROG_VAL_Msk                  0xFFFFFFFF             /*!< Program byte time value in cycles */

/*--  TADHS: Address/data setup/hold time register ------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!< Address/data setup/hold time in cycles */
} _MFLASH_TADHS_bits;

/* Bit field positions: */
#define MFLASH_TADHS_VAL_Pos                  0                      /*!< Address/data setup/hold time in cycles */

/* Bit field masks: */
#define MFLASH_TADHS_VAL_Msk                  0xFFFFFFFF             /*!< Address/data setup/hold time in cycles */

/*--  TPGH: PROG 2 Low to WEb high Hold time register ---------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!< PROG 2 Low to WEb high Hold time value in cycles */
} _MFLASH_TPGH_bits;

/* Bit field positions: */
#define MFLASH_TPGH_VAL_Pos                   0                      /*!< PROG 2 Low to WEb high Hold time value in cycles */

/* Bit field masks: */
#define MFLASH_TPGH_VAL_Msk                   0xFFFFFFFF             /*!< PROG 2 Low to WEb high Hold time value in cycles */

/*--  TRW: Recovery time after write register -----------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!< Recovery time after write value in cycles */
} _MFLASH_TRW_bits;

/* Bit field positions: */
#define MFLASH_TRW_VAL_Pos                    0                      /*!< Recovery time after write value in cycles */

/* Bit field masks: */
#define MFLASH_TRW_VAL_Msk                    0xFFFFFFFF             /*!< Recovery time after write value in cycles */

/*--  TRE: Recovery time after erase register -----------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!< Recovery time after erase value in cycles */
} _MFLASH_TRE_bits;

/* Bit field positions: */
#define MFLASH_TRE_VAL_Pos                    0                      /*!< Recovery time after erase value in cycles */

/* Bit field masks: */
#define MFLASH_TRE_VAL_Msk                    0xFFFFFFFF             /*!< Recovery time after erase value in cycles */

/*--  TES: Erase sector time register -------------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!< Erase sector time value in cycles */
} _MFLASH_TES_bits;

/* Bit field positions: */
#define MFLASH_TES_VAL_Pos                    0                      /*!< Erase sector time value in cycles */

/* Bit field masks: */
#define MFLASH_TES_VAL_Msk                    0xFFFFFFFF             /*!< Erase sector time value in cycles */

/*--  TEA: Erase all flash time register ----------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!< Erase all flash time value in cycles */
} _MFLASH_TEA_bits;

/* Bit field positions: */
#define MFLASH_TEA_VAL_Pos                    0                      /*!< Erase all flash time value in cycles */

/* Bit field masks: */
#define MFLASH_TEA_VAL_Msk                    0xFFFFFFFF             /*!< Erase all flash time value in cycles */

/*--  BDIS: Boot Mode Disable register ------------------------------------------------------------------------*/
typedef struct {
  uint32_t BMDIS                  :1;                                /*!< Disable boot mode after system reset command */
} _MFLASH_BDIS_bits;

/* Bit field positions: */
#define MFLASH_BDIS_BMDIS_Pos                 0                      /*!< Disable boot mode after system reset command */

/* Bit field masks: */
#define MFLASH_BDIS_BMDIS_Msk                 0x00000001             /*!< Disable boot mode after system reset command */

//Cluster DATA:
typedef struct {
  union { 
  /*!< Data Register */
    __IO uint32_t DATA;                                              /*!< DATA : type used for word access */
    __IO _MFLASH_DATA_DATA_bits DATA_bit;                            /*!< DATA_bit: structure used for bit access */
  };
} _MFLASH_DATA_TypeDef;
typedef struct {
  union {                                                               /*!< Address Register */
    __IO uint32_t ADDR;                                              /*!< ADDR    : type used for word access */
    __IO _MFLASH_ADDR_bits  ADDR_bit;                                /*!< ADDR_bit: structure used for bit access */
  };
  _MFLASH_DATA_TypeDef DATA[2];
    __IO uint32_t Reserved0[6];
  union {                                                               /*!< Command Register */
    __IO uint32_t CMD;                                               /*!< CMD    : type used for word access */
    __IO _MFLASH_CMD_bits  CMD_bit;                                  /*!< CMD_bit: structure used for bit access */
  };
  union {                                                               /*!< Status Register */
    __IO uint32_t STAT;                                              /*!< STAT    : type used for word access */
    __IO _MFLASH_STAT_bits  STAT_bit;                                /*!< STAT_bit: structure used for bit access */
  };
  union {                                                               /*!< Control Register */
    __IO uint32_t CTRL;                                              /*!< CTRL    : type used for word access */
    __IO _MFLASH_CTRL_bits  CTRL_bit;                                /*!< CTRL_bit: structure used for bit access */
  };
  union {                                                               /*!< Cache Test Register */
    __O uint32_t CTEST;                                              /*!< CTEST    : type used for word access */
    __O _MFLASH_CTEST_bits  CTEST_bit;                               /*!< CTEST_bit: structure used for bit access */
  };
  union {                                                               /*!< ICACHE Status Register */
    __I uint32_t ICSTAT;                                             /*!< ICSTAT    : type used for word access */
    __I _MFLASH_ICSTAT_bits  ICSTAT_bit;                             /*!< ICSTAT_bit: structure used for bit access */
  };
  union {                                                               /*!< DCACHE Status Register */
    __I uint32_t DCSTAT;                                             /*!< DCSTAT    : type used for word access */
    __I _MFLASH_DCSTAT_bits  DCSTAT_bit;                             /*!< DCSTAT_bit: structure used for bit access */
  };
    __IO uint32_t Reserved1[5];
  union {                                                               /*!< Read hold time register */
    __IO uint32_t TRH;                                               /*!< TRH    : type used for word access */
    __IO _MFLASH_TRH_bits  TRH_bit;                                  /*!< TRH_bit: structure used for bit access */
  };
  union {                                                               /*!< Time to WEn register */
    __IO uint32_t TNVS;                                              /*!< TNVS    : type used for word access */
    __IO _MFLASH_TNVS_bits  TNVS_bit;                                /*!< TNVS_bit: structure used for bit access */
  };
  union {                                                               /*!< Time from Wen low to PROG2 high register */
    __IO uint32_t TPGS;                                              /*!< TPGS    : type used for word access */
    __IO _MFLASH_TPGS_bits  TPGS_bit;                                /*!< TPGS_bit: structure used for bit access */
  };
  union {                                                               /*!< Program byte time register */
    __IO uint32_t TPROG;                                             /*!< TPROG    : type used for word access */
    __IO _MFLASH_TPROG_bits  TPROG_bit;                              /*!< TPROG_bit: structure used for bit access */
  };
  union {                                                               /*!< Address/data setup/hold time register */
    __IO uint32_t TADHS;                                             /*!< TADHS    : type used for word access */
    __IO _MFLASH_TADHS_bits  TADHS_bit;                              /*!< TADHS_bit: structure used for bit access */
  };
  union {                                                               /*!< PROG 2 Low to WEb high Hold time register */
    __IO uint32_t TPGH;                                              /*!< TPGH    : type used for word access */
    __IO _MFLASH_TPGH_bits  TPGH_bit;                                /*!< TPGH_bit: structure used for bit access */
  };
  union {                                                               /*!< Recovery time after write register */
    __IO uint32_t TRW;                                               /*!< TRW    : type used for word access */
    __IO _MFLASH_TRW_bits  TRW_bit;                                  /*!< TRW_bit: structure used for bit access */
  };
  union {                                                               /*!< Recovery time after erase register */
    __IO uint32_t TRE;                                               /*!< TRE    : type used for word access */
    __IO _MFLASH_TRE_bits  TRE_bit;                                  /*!< TRE_bit: structure used for bit access */
  };
  union {                                                               /*!< Erase sector time register */
    __IO uint32_t TES;                                               /*!< TES    : type used for word access */
    __IO _MFLASH_TES_bits  TES_bit;                                  /*!< TES_bit: structure used for bit access */
  };
  union {                                                               /*!< Erase all flash time register */
    __IO uint32_t TEA;                                               /*!< TEA    : type used for word access */
    __IO _MFLASH_TEA_bits  TEA_bit;                                  /*!< TEA_bit: structure used for bit access */
  };
  union {                                                               /*!< Boot Mode Disable register */
    __IO uint32_t BDIS;                                              /*!< BDIS    : type used for word access */
    __IO _MFLASH_BDIS_bits  BDIS_bit;                                /*!< BDIS_bit: structure used for bit access */
  };
} MFLASH_TypeDef;

/******************************************************************************/
/*                         QEP registers                                      */
/******************************************************************************/

/*--  QPOSCNT: Position Counter register ----------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!<  */
} _QEP_QPOSCNT_bits;

/* Bit field positions: */
#define QEP_QPOSCNT_VAL_Pos                   0                      /*!<  */

/* Bit field masks: */
#define QEP_QPOSCNT_VAL_Msk                   0xFFFFFFFF             /*!<  */

/*--  QPOSINIT: Position Counter Initialization register ------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!<  */
} _QEP_QPOSINIT_bits;

/* Bit field positions: */
#define QEP_QPOSINIT_VAL_Pos                  0                      /*!<  */

/* Bit field masks: */
#define QEP_QPOSINIT_VAL_Msk                  0xFFFFFFFF             /*!<  */

/*--  QPOSMAX: Maximum Position Count register ----------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!<  */
} _QEP_QPOSMAX_bits;

/* Bit field positions: */
#define QEP_QPOSMAX_VAL_Pos                   0                      /*!<  */

/* Bit field masks: */
#define QEP_QPOSMAX_VAL_Msk                   0xFFFFFFFF             /*!<  */

/*--  QPOSCMP: Position-compare register ----------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!<  */
} _QEP_QPOSCMP_bits;

/* Bit field positions: */
#define QEP_QPOSCMP_VAL_Pos                   0                      /*!<  */

/* Bit field masks: */
#define QEP_QPOSCMP_VAL_Msk                   0xFFFFFFFF             /*!<  */

/*--  QPOSILAT: Index Position Latch register -----------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!<  */
} _QEP_QPOSILAT_bits;

/* Bit field positions: */
#define QEP_QPOSILAT_VAL_Pos                  0                      /*!<  */

/* Bit field masks: */
#define QEP_QPOSILAT_VAL_Msk                  0xFFFFFFFF             /*!<  */

/*--  QPOSSLAT: Strobe Position Latch register ----------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!<  */
} _QEP_QPOSSLAT_bits;

/* Bit field positions: */
#define QEP_QPOSSLAT_VAL_Pos                  0                      /*!<  */

/* Bit field masks: */
#define QEP_QPOSSLAT_VAL_Msk                  0xFFFFFFFF             /*!<  */

/*--  QPOSLAT: Position Counter Latch register ----------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!<  */
} _QEP_QPOSLAT_bits;

/* Bit field positions: */
#define QEP_QPOSLAT_VAL_Pos                   0                      /*!<  */

/* Bit field masks: */
#define QEP_QPOSLAT_VAL_Msk                   0xFFFFFFFF             /*!<  */

/*--  QUTMR: Unit Timer register ------------------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!<  */
} _QEP_QUTMR_bits;

/* Bit field positions: */
#define QEP_QUTMR_VAL_Pos                     0                      /*!<  */

/* Bit field masks: */
#define QEP_QUTMR_VAL_Msk                     0xFFFFFFFF             /*!<  */

/*--  QUPRD: Unit Period register -----------------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!<  */
} _QEP_QUPRD_bits;

/* Bit field positions: */
#define QEP_QUPRD_VAL_Pos                     0                      /*!<  */

/* Bit field masks: */
#define QEP_QUPRD_VAL_Msk                     0xFFFFFFFF             /*!<  */

/*--  QWDTMR: Watchdog Timer register -------------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!<  */
} _QEP_QWDTMR_bits;

/* Bit field positions: */
#define QEP_QWDTMR_VAL_Pos                    0                      /*!<  */

/* Bit field masks: */
#define QEP_QWDTMR_VAL_Msk                    0xFFFFFFFF             /*!<  */

/*--  QWDPRD: Watchdog Period register ------------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!<  */
} _QEP_QWDPRD_bits;

/* Bit field positions: */
#define QEP_QWDPRD_VAL_Pos                    0                      /*!<  */

/* Bit field masks: */
#define QEP_QWDPRD_VAL_Msk                    0xFFFFFFFF             /*!<  */

/*--  QDECCTL: Decoder Control register -----------------------------------------------------------------------*/
typedef struct {
  uint32_t                        :5;                                /*!< RESERVED */
  uint32_t QSP                    :1;                                /*!< QEPS input polarity */
  uint32_t QIP                    :1;                                /*!< QEPI input polarity */
  uint32_t QBP                    :1;                                /*!< QEPB input polarity */
  uint32_t QAP                    :1;                                /*!< QEPA input polarity */
  uint32_t IGATE                  :1;                                /*!< Index pulse gating option */
  uint32_t SWAP                   :1;                                /*!< Swap quadrature clock inputs */
  uint32_t XCR                    :1;                                /*!< External clock rate */
  uint32_t SPSEL                  :1;                                /*!< Sync output pin selection */
  uint32_t SOEN                   :1;                                /*!< Sync output-enable */
  uint32_t QSRC                   :2;                                /*!< Position-counter source selection */
} _QEP_QDECCTL_bits;

/* Bit field positions: */
#define QEP_QDECCTL_QSP_Pos                   5                      /*!< QEPS input polarity */
#define QEP_QDECCTL_QIP_Pos                   6                      /*!< QEPI input polarity */
#define QEP_QDECCTL_QBP_Pos                   7                      /*!< QEPB input polarity */
#define QEP_QDECCTL_QAP_Pos                   8                      /*!< QEPA input polarity */
#define QEP_QDECCTL_IGATE_Pos                 9                      /*!< Index pulse gating option */
#define QEP_QDECCTL_SWAP_Pos                  10                     /*!< Swap quadrature clock inputs */
#define QEP_QDECCTL_XCR_Pos                   11                     /*!< External clock rate */
#define QEP_QDECCTL_SPSEL_Pos                 12                     /*!< Sync output pin selection */
#define QEP_QDECCTL_SOEN_Pos                  13                     /*!< Sync output-enable */
#define QEP_QDECCTL_QSRC_Pos                  14                     /*!< Position-counter source selection */

/* Bit field masks: */
#define QEP_QDECCTL_QSP_Msk                   0x00000020             /*!< QEPS input polarity */
#define QEP_QDECCTL_QIP_Msk                   0x00000040             /*!< QEPI input polarity */
#define QEP_QDECCTL_QBP_Msk                   0x00000080             /*!< QEPB input polarity */
#define QEP_QDECCTL_QAP_Msk                   0x00000100             /*!< QEPA input polarity */
#define QEP_QDECCTL_IGATE_Msk                 0x00000200             /*!< Index pulse gating option */
#define QEP_QDECCTL_SWAP_Msk                  0x00000400             /*!< Swap quadrature clock inputs */
#define QEP_QDECCTL_XCR_Msk                   0x00000800             /*!< External clock rate */
#define QEP_QDECCTL_SPSEL_Msk                 0x00001000             /*!< Sync output pin selection */
#define QEP_QDECCTL_SOEN_Msk                  0x00002000             /*!< Sync output-enable */
#define QEP_QDECCTL_QSRC_Msk                  0x0000C000             /*!< Position-counter source selection */

/* Bit field enums: */
typedef enum {
  QEP_QDECCTL_QSRC_Quad                      = 0x0,                  /*!< quadrature mode */
  QEP_QDECCTL_QSRC_CountDir                  = 0x1,                  /*!< count/direction mode */
  QEP_QDECCTL_QSRC_Up                        = 0x2,                  /*!< count up */
  QEP_QDECCTL_QSRC_Down                      = 0x3,                  /*!< count down */
} QEP_QDECCTL_QSRC_Enum;

/*--  QEPCTL: Control register --------------------------------------------------------------------------------*/
typedef struct {
  uint32_t WDE                    :1;                                /*!< QEP watchdog enable */
  uint32_t UTE                    :1;                                /*!< QEP unit timer enable */
  uint32_t QCLM                   :1;                                /*!< QEP capture latch mode */
  uint32_t QPEN                   :1;                                /*!< Quadrature position counter enable/software reset */
  uint32_t IEL                    :2;                                /*!< Index event latch of position counter (software index marker) */
  uint32_t SEL                    :1;                                /*!< Strobe event latch of position counter */
  uint32_t SWI                    :1;                                /*!< Software initialization of position counter */
  uint32_t IEI                    :2;                                /*!< Index event initialization of position counter */
  uint32_t SEI                    :2;                                /*!< Strobe event initialization of position counter */
  uint32_t PCRM                   :2;                                /*!< Position counter reset mode */
  uint32_t FREESOFT               :2;                                /*!< Emulation Control Bits */
} _QEP_QEPCTL_bits;

/* Bit field positions: */
#define QEP_QEPCTL_WDE_Pos                    0                      /*!< QEP watchdog enable */
#define QEP_QEPCTL_UTE_Pos                    1                      /*!< QEP unit timer enable */
#define QEP_QEPCTL_QCLM_Pos                   2                      /*!< QEP capture latch mode */
#define QEP_QEPCTL_QPEN_Pos                   3                      /*!< Quadrature position counter enable/software reset */
#define QEP_QEPCTL_IEL_Pos                    4                      /*!< Index event latch of position counter (software index marker) */
#define QEP_QEPCTL_SEL_Pos                    6                      /*!< Strobe event latch of position counter */
#define QEP_QEPCTL_SWI_Pos                    7                      /*!< Software initialization of position counter */
#define QEP_QEPCTL_IEI_Pos                    8                      /*!< Index event initialization of position counter */
#define QEP_QEPCTL_SEI_Pos                    10                     /*!< Strobe event initialization of position counter */
#define QEP_QEPCTL_PCRM_Pos                   12                     /*!< Position counter reset mode */
#define QEP_QEPCTL_FREESOFT_Pos               14                     /*!< Emulation Control Bits */

/* Bit field masks: */
#define QEP_QEPCTL_WDE_Msk                    0x00000001             /*!< QEP watchdog enable */
#define QEP_QEPCTL_UTE_Msk                    0x00000002             /*!< QEP unit timer enable */
#define QEP_QEPCTL_QCLM_Msk                   0x00000004             /*!< QEP capture latch mode */
#define QEP_QEPCTL_QPEN_Msk                   0x00000008             /*!< Quadrature position counter enable/software reset */
#define QEP_QEPCTL_IEL_Msk                    0x00000030             /*!< Index event latch of position counter (software index marker) */
#define QEP_QEPCTL_SEL_Msk                    0x00000040             /*!< Strobe event latch of position counter */
#define QEP_QEPCTL_SWI_Msk                    0x00000080             /*!< Software initialization of position counter */
#define QEP_QEPCTL_IEI_Msk                    0x00000300             /*!< Index event initialization of position counter */
#define QEP_QEPCTL_SEI_Msk                    0x00000C00             /*!< Strobe event initialization of position counter */
#define QEP_QEPCTL_PCRM_Msk                   0x00003000             /*!< Position counter reset mode */
#define QEP_QEPCTL_FREESOFT_Msk               0x0000C000             /*!< Emulation Control Bits */

/* Bit field enums: */
typedef enum {
  QEP_QEPCTL_IEL_NoLatch                     = 0x0,                  /*!< no position counter latch */
  QEP_QEPCTL_IEL_IndPos                      = 0x1,                  /*!< latch on index signal posedge */
  QEP_QEPCTL_IEL_IndNeg                      = 0x2,                  /*!< latch on index signal negedge */
  QEP_QEPCTL_IEL_IndMark                     = 0x3,                  /*!< latch on index marker */
} QEP_QEPCTL_IEL_Enum;

typedef enum {
  QEP_QEPCTL_IEI_NoInit                      = 0x0,                  /*!< no initialization */
  QEP_QEPCTL_IEI_QEPIPos                     = 0x2,                  /*!< init on posedge QEPI */
  QEP_QEPCTL_IEI_QEPINeg                     = 0x3,                  /*!< init on negedge QEPI */
} QEP_QEPCTL_IEI_Enum;

typedef enum {
  QEP_QEPCTL_SEI_NoInit                      = 0x0,                  /*!< no initialization */
  QEP_QEPCTL_SEI_QEPSPos                     = 0x2,                  /*!< init on posedge QEPI */
  QEP_QEPCTL_SEI_QEPSDir                     = 0x3,                  /*!< init depends on direction - on posedge if direction is up, on negedge if direction is down */
} QEP_QEPCTL_SEI_Enum;

typedef enum {
  QEP_QEPCTL_PCRM_Ind                        = 0x0,                  /*!< reset on index */
  QEP_QEPCTL_PCRM_PosMax                     = 0x1,                  /*!< reset on max position count */
  QEP_QEPCTL_PCRM_FirstInd                   = 0x2,                  /*!< reset on the first index */
  QEP_QEPCTL_PCRM_Time                       = 0x3,                  /*!< reset on time counter */
} QEP_QEPCTL_PCRM_Enum;

typedef enum {
  QEP_QEPCTL_FREESOFT_Stop                   = 0x0,                  /*!< counters are blocked */
  QEP_QEPCTL_FREESOFT_StopAtOvf              = 0x1,                  /*!< stop after overflow */
  QEP_QEPCTL_FREESOFT_Free                   = 0x2,                  /*!< no count stop in debug mode */
} QEP_QEPCTL_FREESOFT_Enum;

/*--  QCAPCTL: Capture Control register -----------------------------------------------------------------------*/
typedef struct {
  uint32_t UPPS                   :4;                                /*!< Unit position event prescaler */
  uint32_t CCPS                   :3;                                /*!< QEP capture timer clock prescaler */
  uint32_t SELEVENT               :1;                                /*!< Reset timer control */
  uint32_t                        :7;                                /*!< RESERVED */
  uint32_t CEN                    :1;                                /*!< Enable eQEP capture */
  uint32_t EPSLD                  :1;                                /*!< Enhanced prescalers load */
} _QEP_QCAPCTL_bits;

/* Bit field positions: */
#define QEP_QCAPCTL_UPPS_Pos                  0                      /*!< Unit position event prescaler */
#define QEP_QCAPCTL_CCPS_Pos                  4                      /*!< QEP capture timer clock prescaler */
#define QEP_QCAPCTL_SELEVENT_Pos              7                      /*!< Reset timer control */
#define QEP_QCAPCTL_CEN_Pos                   15                     /*!< Enable eQEP capture */
#define QEP_QCAPCTL_EPSLD_Pos                 16                     /*!< Enhanced prescalers load */

/* Bit field masks: */
#define QEP_QCAPCTL_UPPS_Msk                  0x0000000F             /*!< Unit position event prescaler */
#define QEP_QCAPCTL_CCPS_Msk                  0x00000070             /*!< QEP capture timer clock prescaler */
#define QEP_QCAPCTL_SELEVENT_Msk              0x00000080             /*!< Reset timer control */
#define QEP_QCAPCTL_CEN_Msk                   0x00008000             /*!< Enable eQEP capture */
#define QEP_QCAPCTL_EPSLD_Msk                 0x00010000             /*!< Enhanced prescalers load */

/* Bit field enums: */
typedef enum {
  QEP_QCAPCTL_UPPS_Disable                   = 0x0,                  /*!< quad signal not divided */
  QEP_QCAPCTL_UPPS_Div2                      = 0x1,                  /*!< quad signal divided by 2 */
  QEP_QCAPCTL_UPPS_Div4                      = 0x2,                  /*!< quad signal divided by 4 */
  QEP_QCAPCTL_UPPS_Div8                      = 0x3,                  /*!< quad signal divided by 8 */
  QEP_QCAPCTL_UPPS_Div16                     = 0x4,                  /*!< quad signal divided by 16 */
  QEP_QCAPCTL_UPPS_Div32                     = 0x5,                  /*!< quad signal divided by 32 */
  QEP_QCAPCTL_UPPS_Div64                     = 0x6,                  /*!< quad signal divided by 64 */
  QEP_QCAPCTL_UPPS_Div128                    = 0x7,                  /*!< quad signal divided by 128 */
  QEP_QCAPCTL_UPPS_Div256                    = 0x8,                  /*!< quad signal divided by 256 */
  QEP_QCAPCTL_UPPS_Div512                    = 0x9,                  /*!< quad signal divided by 512 */
  QEP_QCAPCTL_UPPS_Div1024                   = 0xA,                  /*!< quad signal divided by 1024 */
  QEP_QCAPCTL_UPPS_Div2048                   = 0xB,                  /*!< quad signal divided by 2048 */
} QEP_QCAPCTL_UPPS_Enum;

typedef enum {
  QEP_QCAPCTL_CCPS_Disable                   = 0x0,                  /*!< no divider */
  QEP_QCAPCTL_CCPS_Div2                      = 0x1,                  /*!< sysclk divided by 2 */
  QEP_QCAPCTL_CCPS_Div4                      = 0x2,                  /*!< sysclk divided by 4 */
  QEP_QCAPCTL_CCPS_Div8                      = 0x3,                  /*!< sysclk divided by 8 */
  QEP_QCAPCTL_CCPS_Div16                     = 0x4,                  /*!< sysclk divided by 16 */
  QEP_QCAPCTL_CCPS_Div32                     = 0x5,                  /*!< sysclk divided by 32 */
  QEP_QCAPCTL_CCPS_Div64                     = 0x6,                  /*!< sysclk divided by 64 */
  QEP_QCAPCTL_CCPS_Div128                    = 0x7,                  /*!< sysclk divided by 128 */
} QEP_QCAPCTL_CCPS_Enum;

/*--  QPOSCTL: Position-compare Control register --------------------------------------------------------------*/
typedef struct {
  uint32_t PCSPW                  :12;                               /*!< Select-position-compare sync output pulse width */
  uint32_t PCE                    :1;                                /*!< Position-compare enable/disable */
  uint32_t PCPOL                  :1;                                /*!< Polarity of sync output */
  uint32_t PCLOAD                 :1;                                /*!< Position-compare shadow load mode */
  uint32_t PCSHDW                 :1;                                /*!< Position-compare shadow enable */
} _QEP_QPOSCTL_bits;

/* Bit field positions: */
#define QEP_QPOSCTL_PCSPW_Pos                 0                      /*!< Select-position-compare sync output pulse width */
#define QEP_QPOSCTL_PCE_Pos                   12                     /*!< Position-compare enable/disable */
#define QEP_QPOSCTL_PCPOL_Pos                 13                     /*!< Polarity of sync output */
#define QEP_QPOSCTL_PCLOAD_Pos                14                     /*!< Position-compare shadow load mode */
#define QEP_QPOSCTL_PCSHDW_Pos                15                     /*!< Position-compare shadow enable */

/* Bit field masks: */
#define QEP_QPOSCTL_PCSPW_Msk                 0x00000FFF             /*!< Select-position-compare sync output pulse width */
#define QEP_QPOSCTL_PCE_Msk                   0x00001000             /*!< Position-compare enable/disable */
#define QEP_QPOSCTL_PCPOL_Msk                 0x00002000             /*!< Polarity of sync output */
#define QEP_QPOSCTL_PCLOAD_Msk                0x00004000             /*!< Position-compare shadow load mode */
#define QEP_QPOSCTL_PCSHDW_Msk                0x00008000             /*!< Position-compare shadow enable */

/*--  QEINT: Interrupt Enable register ------------------------------------------------------------------------*/
typedef struct {
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t PCE                    :1;                                /*!< Position counter error interrupt enable */
  uint32_t QPE                    :1;                                /*!< Quadrature phase error interrupt enable */
  uint32_t QDC                    :1;                                /*!< Quadrature direction change interrupt enable */
  uint32_t WTO                    :1;                                /*!< Watchdog time out interrupt enable */
  uint32_t PCU                    :1;                                /*!< Position counter underflow interrupt enable */
  uint32_t PCO                    :1;                                /*!< Position counter overflow interrupt enable */
  uint32_t PCR                    :1;                                /*!< Position-compare ready interrupt enable */
  uint32_t PCM                    :1;                                /*!< Position-compare match interrupt enable */
  uint32_t SEL                    :1;                                /*!< Strobe event latch interrupt enable */
  uint32_t IEL                    :1;                                /*!< Index event latch interrupt enable */
  uint32_t UTO                    :1;                                /*!< Unit time out interrupt enable */
} _QEP_QEINT_bits;

/* Bit field positions: */
#define QEP_QEINT_PCE_Pos                     1                      /*!< Position counter error interrupt enable */
#define QEP_QEINT_QPE_Pos                     2                      /*!< Quadrature phase error interrupt enable */
#define QEP_QEINT_QDC_Pos                     3                      /*!< Quadrature direction change interrupt enable */
#define QEP_QEINT_WTO_Pos                     4                      /*!< Watchdog time out interrupt enable */
#define QEP_QEINT_PCU_Pos                     5                      /*!< Position counter underflow interrupt enable */
#define QEP_QEINT_PCO_Pos                     6                      /*!< Position counter overflow interrupt enable */
#define QEP_QEINT_PCR_Pos                     7                      /*!< Position-compare ready interrupt enable */
#define QEP_QEINT_PCM_Pos                     8                      /*!< Position-compare match interrupt enable */
#define QEP_QEINT_SEL_Pos                     9                      /*!< Strobe event latch interrupt enable */
#define QEP_QEINT_IEL_Pos                     10                     /*!< Index event latch interrupt enable */
#define QEP_QEINT_UTO_Pos                     11                     /*!< Unit time out interrupt enable */

/* Bit field masks: */
#define QEP_QEINT_PCE_Msk                     0x00000002             /*!< Position counter error interrupt enable */
#define QEP_QEINT_QPE_Msk                     0x00000004             /*!< Quadrature phase error interrupt enable */
#define QEP_QEINT_QDC_Msk                     0x00000008             /*!< Quadrature direction change interrupt enable */
#define QEP_QEINT_WTO_Msk                     0x00000010             /*!< Watchdog time out interrupt enable */
#define QEP_QEINT_PCU_Msk                     0x00000020             /*!< Position counter underflow interrupt enable */
#define QEP_QEINT_PCO_Msk                     0x00000040             /*!< Position counter overflow interrupt enable */
#define QEP_QEINT_PCR_Msk                     0x00000080             /*!< Position-compare ready interrupt enable */
#define QEP_QEINT_PCM_Msk                     0x00000100             /*!< Position-compare match interrupt enable */
#define QEP_QEINT_SEL_Msk                     0x00000200             /*!< Strobe event latch interrupt enable */
#define QEP_QEINT_IEL_Msk                     0x00000400             /*!< Index event latch interrupt enable */
#define QEP_QEINT_UTO_Msk                     0x00000800             /*!< Unit time out interrupt enable */

/*--  QFLG: Interrupt Flag register ---------------------------------------------------------------------------*/
typedef struct {
  uint32_t INT                    :1;                                /*!< Global interrupt status flag */
  uint32_t PCE                    :1;                                /*!< Position counter error interrupt flag */
  uint32_t QPE                    :1;                                /*!< Quadrature phase error interrupt flag */
  uint32_t QDC                    :1;                                /*!< Quadrature direction change interrupt flag */
  uint32_t WTO                    :1;                                /*!< Watchdog timeout interrupt flag */
  uint32_t PCU                    :1;                                /*!< Position counter underflow interrupt flag */
  uint32_t PCO                    :1;                                /*!< Position counter overflow interrupt flag */
  uint32_t PCR                    :1;                                /*!< Position-compare ready interrupt flag */
  uint32_t PCM                    :1;                                /*!< QEP compare match event interrupt flag */
  uint32_t SEL                    :1;                                /*!< Strobe event latch interrupt flag
 */
  uint32_t IEL                    :1;                                /*!< Index event latch interrupt flag */
  uint32_t UTO                    :1;                                /*!< Unit time out interrupt flag */
} _QEP_QFLG_bits;

/* Bit field positions: */
#define QEP_QFLG_INT_Pos                      0                      /*!< Global interrupt status flag */
#define QEP_QFLG_PCE_Pos                      1                      /*!< Position counter error interrupt flag */
#define QEP_QFLG_QPE_Pos                      2                      /*!< Quadrature phase error interrupt flag */
#define QEP_QFLG_QDC_Pos                      3                      /*!< Quadrature direction change interrupt flag */
#define QEP_QFLG_WTO_Pos                      4                      /*!< Watchdog timeout interrupt flag */
#define QEP_QFLG_PCU_Pos                      5                      /*!< Position counter underflow interrupt flag */
#define QEP_QFLG_PCO_Pos                      6                      /*!< Position counter overflow interrupt flag */
#define QEP_QFLG_PCR_Pos                      7                      /*!< Position-compare ready interrupt flag */
#define QEP_QFLG_PCM_Pos                      8                      /*!< QEP compare match event interrupt flag */
#define QEP_QFLG_SEL_Pos                      9                      /*!< Strobe event latch interrupt flag
 */
#define QEP_QFLG_IEL_Pos                      10                     /*!< Index event latch interrupt flag */
#define QEP_QFLG_UTO_Pos                      11                     /*!< Unit time out interrupt flag */

/* Bit field masks: */
#define QEP_QFLG_INT_Msk                      0x00000001             /*!< Global interrupt status flag */
#define QEP_QFLG_PCE_Msk                      0x00000002             /*!< Position counter error interrupt flag */
#define QEP_QFLG_QPE_Msk                      0x00000004             /*!< Quadrature phase error interrupt flag */
#define QEP_QFLG_QDC_Msk                      0x00000008             /*!< Quadrature direction change interrupt flag */
#define QEP_QFLG_WTO_Msk                      0x00000010             /*!< Watchdog timeout interrupt flag */
#define QEP_QFLG_PCU_Msk                      0x00000020             /*!< Position counter underflow interrupt flag */
#define QEP_QFLG_PCO_Msk                      0x00000040             /*!< Position counter overflow interrupt flag */
#define QEP_QFLG_PCR_Msk                      0x00000080             /*!< Position-compare ready interrupt flag */
#define QEP_QFLG_PCM_Msk                      0x00000100             /*!< QEP compare match event interrupt flag */
#define QEP_QFLG_SEL_Msk                      0x00000200             /*!< Strobe event latch interrupt flag
 */
#define QEP_QFLG_IEL_Msk                      0x00000400             /*!< Index event latch interrupt flag */
#define QEP_QFLG_UTO_Msk                      0x00000800             /*!< Unit time out interrupt flag */

/*--  QCLR: Interrupt Clear register --------------------------------------------------------------------------*/
typedef struct {
  uint32_t INT                    :1;                                /*!< Global interrupt clear flag */
  uint32_t PCE                    :1;                                /*!< Clear position counter error interrupt flag */
  uint32_t QPE                    :1;                                /*!< Clear quadrature phase error interrupt flag */
  uint32_t QDC                    :1;                                /*!< Clear quadrature direction change interrupt flag */
  uint32_t WTO                    :1;                                /*!< Clear watchdog timeout interrupt flag */
  uint32_t PCU                    :1;                                /*!< Clear position counter underflow interrupt flag */
  uint32_t PCO                    :1;                                /*!< Clear position counter overflow interrupt flag */
  uint32_t PCR                    :1;                                /*!< Clear position-compare ready interrupt flag */
  uint32_t PCM                    :1;                                /*!< Clear eQEP compare match event interrupt flag */
  uint32_t SEL                    :1;                                /*!< Clear strobe event latch interrupt flag */
  uint32_t IEL                    :1;                                /*!< Clear index event latch interrupt flag */
  uint32_t UTO                    :1;                                /*!< Clear unit time out interrupt flag */
} _QEP_QCLR_bits;

/* Bit field positions: */
#define QEP_QCLR_INT_Pos                      0                      /*!< Global interrupt clear flag */
#define QEP_QCLR_PCE_Pos                      1                      /*!< Clear position counter error interrupt flag */
#define QEP_QCLR_QPE_Pos                      2                      /*!< Clear quadrature phase error interrupt flag */
#define QEP_QCLR_QDC_Pos                      3                      /*!< Clear quadrature direction change interrupt flag */
#define QEP_QCLR_WTO_Pos                      4                      /*!< Clear watchdog timeout interrupt flag */
#define QEP_QCLR_PCU_Pos                      5                      /*!< Clear position counter underflow interrupt flag */
#define QEP_QCLR_PCO_Pos                      6                      /*!< Clear position counter overflow interrupt flag */
#define QEP_QCLR_PCR_Pos                      7                      /*!< Clear position-compare ready interrupt flag */
#define QEP_QCLR_PCM_Pos                      8                      /*!< Clear eQEP compare match event interrupt flag */
#define QEP_QCLR_SEL_Pos                      9                      /*!< Clear strobe event latch interrupt flag */
#define QEP_QCLR_IEL_Pos                      10                     /*!< Clear index event latch interrupt flag */
#define QEP_QCLR_UTO_Pos                      11                     /*!< Clear unit time out interrupt flag */

/* Bit field masks: */
#define QEP_QCLR_INT_Msk                      0x00000001             /*!< Global interrupt clear flag */
#define QEP_QCLR_PCE_Msk                      0x00000002             /*!< Clear position counter error interrupt flag */
#define QEP_QCLR_QPE_Msk                      0x00000004             /*!< Clear quadrature phase error interrupt flag */
#define QEP_QCLR_QDC_Msk                      0x00000008             /*!< Clear quadrature direction change interrupt flag */
#define QEP_QCLR_WTO_Msk                      0x00000010             /*!< Clear watchdog timeout interrupt flag */
#define QEP_QCLR_PCU_Msk                      0x00000020             /*!< Clear position counter underflow interrupt flag */
#define QEP_QCLR_PCO_Msk                      0x00000040             /*!< Clear position counter overflow interrupt flag */
#define QEP_QCLR_PCR_Msk                      0x00000080             /*!< Clear position-compare ready interrupt flag */
#define QEP_QCLR_PCM_Msk                      0x00000100             /*!< Clear eQEP compare match event interrupt flag */
#define QEP_QCLR_SEL_Msk                      0x00000200             /*!< Clear strobe event latch interrupt flag */
#define QEP_QCLR_IEL_Msk                      0x00000400             /*!< Clear index event latch interrupt flag */
#define QEP_QCLR_UTO_Msk                      0x00000800             /*!< Clear unit time out interrupt flag */

/*--  QFRC: Interrupt Force register --------------------------------------------------------------------------*/
typedef struct {
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t PCE                    :1;                                /*!< Force position counter error interrupt */
  uint32_t QPE                    :1;                                /*!< Force quadrature phase error interrupt */
  uint32_t QDC                    :1;                                /*!< Force quadrature direction change interrupt */
  uint32_t WTO                    :1;                                /*!< Force watchdog time out interrupt */
  uint32_t PCU                    :1;                                /*!< Force position counter underflow interrupt */
  uint32_t PCO                    :1;                                /*!< Force position counter overflow interrupt */
  uint32_t PCR                    :1;                                /*!< Force position-compare ready interrupt */
  uint32_t PCM                    :1;                                /*!< Force position-compare match interrupt */
  uint32_t SEL                    :1;                                /*!< Force strobe event latch interrupt */
  uint32_t IEL                    :1;                                /*!< Force index event latch interrupt */
  uint32_t UTO                    :1;                                /*!< Force unit time out interrupt */
} _QEP_QFRC_bits;

/* Bit field positions: */
#define QEP_QFRC_PCE_Pos                      1                      /*!< Force position counter error interrupt */
#define QEP_QFRC_QPE_Pos                      2                      /*!< Force quadrature phase error interrupt */
#define QEP_QFRC_QDC_Pos                      3                      /*!< Force quadrature direction change interrupt */
#define QEP_QFRC_WTO_Pos                      4                      /*!< Force watchdog time out interrupt */
#define QEP_QFRC_PCU_Pos                      5                      /*!< Force position counter underflow interrupt */
#define QEP_QFRC_PCO_Pos                      6                      /*!< Force position counter overflow interrupt */
#define QEP_QFRC_PCR_Pos                      7                      /*!< Force position-compare ready interrupt */
#define QEP_QFRC_PCM_Pos                      8                      /*!< Force position-compare match interrupt */
#define QEP_QFRC_SEL_Pos                      9                      /*!< Force strobe event latch interrupt */
#define QEP_QFRC_IEL_Pos                      10                     /*!< Force index event latch interrupt */
#define QEP_QFRC_UTO_Pos                      11                     /*!< Force unit time out interrupt */

/* Bit field masks: */
#define QEP_QFRC_PCE_Msk                      0x00000002             /*!< Force position counter error interrupt */
#define QEP_QFRC_QPE_Msk                      0x00000004             /*!< Force quadrature phase error interrupt */
#define QEP_QFRC_QDC_Msk                      0x00000008             /*!< Force quadrature direction change interrupt */
#define QEP_QFRC_WTO_Msk                      0x00000010             /*!< Force watchdog time out interrupt */
#define QEP_QFRC_PCU_Msk                      0x00000020             /*!< Force position counter underflow interrupt */
#define QEP_QFRC_PCO_Msk                      0x00000040             /*!< Force position counter overflow interrupt */
#define QEP_QFRC_PCR_Msk                      0x00000080             /*!< Force position-compare ready interrupt */
#define QEP_QFRC_PCM_Msk                      0x00000100             /*!< Force position-compare match interrupt */
#define QEP_QFRC_SEL_Msk                      0x00000200             /*!< Force strobe event latch interrupt */
#define QEP_QFRC_IEL_Msk                      0x00000400             /*!< Force index event latch interrupt */
#define QEP_QFRC_UTO_Msk                      0x00000800             /*!< Force unit time out interrupt */

/*--  QEPSTS: Status register ---------------------------------------------------------------------------------*/
typedef struct {
  uint32_t PCEF                   :1;                                /*!< Position counter error flag */
  uint32_t FIMF                   :1;                                /*!< First index marker flag */
  uint32_t CDEF                   :1;                                /*!< Capture direction error flag */
  uint32_t COEF                   :1;                                /*!< Capture overflow error flag */
  uint32_t QDLF                   :1;                                /*!< QEP direction latch flag */
  uint32_t QDF                    :1;                                /*!< Quadrature direction flag */
  uint32_t FIDF                   :1;                                /*!< Direction on the first index marker */
  uint32_t UPEVNT                 :1;                                /*!< Unit position event flag */
  uint32_t DCF                    :1;                                /*!< Direction change flag */
} _QEP_QEPSTS_bits;

/* Bit field positions: */
#define QEP_QEPSTS_PCEF_Pos                   0                      /*!< Position counter error flag */
#define QEP_QEPSTS_FIMF_Pos                   1                      /*!< First index marker flag */
#define QEP_QEPSTS_CDEF_Pos                   2                      /*!< Capture direction error flag */
#define QEP_QEPSTS_COEF_Pos                   3                      /*!< Capture overflow error flag */
#define QEP_QEPSTS_QDLF_Pos                   4                      /*!< QEP direction latch flag */
#define QEP_QEPSTS_QDF_Pos                    5                      /*!< Quadrature direction flag */
#define QEP_QEPSTS_FIDF_Pos                   6                      /*!< Direction on the first index marker */
#define QEP_QEPSTS_UPEVNT_Pos                 7                      /*!< Unit position event flag */
#define QEP_QEPSTS_DCF_Pos                    8                      /*!< Direction change flag */

/* Bit field masks: */
#define QEP_QEPSTS_PCEF_Msk                   0x00000001             /*!< Position counter error flag */
#define QEP_QEPSTS_FIMF_Msk                   0x00000002             /*!< First index marker flag */
#define QEP_QEPSTS_CDEF_Msk                   0x00000004             /*!< Capture direction error flag */
#define QEP_QEPSTS_COEF_Msk                   0x00000008             /*!< Capture overflow error flag */
#define QEP_QEPSTS_QDLF_Msk                   0x00000010             /*!< QEP direction latch flag */
#define QEP_QEPSTS_QDF_Msk                    0x00000020             /*!< Quadrature direction flag */
#define QEP_QEPSTS_FIDF_Msk                   0x00000040             /*!< Direction on the first index marker */
#define QEP_QEPSTS_UPEVNT_Msk                 0x00000080             /*!< Unit position event flag */
#define QEP_QEPSTS_DCF_Msk                    0x00000100             /*!< Direction change flag */

/*--  QCTMR: Capture Timer register ---------------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!<  */
} _QEP_QCTMR_bits;

/* Bit field positions: */
#define QEP_QCTMR_VAL_Pos                     0                      /*!<  */

/* Bit field masks: */
#define QEP_QCTMR_VAL_Msk                     0xFFFFFFFF             /*!<  */

/*--  QCPRD: Capture Period register --------------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!<  */
} _QEP_QCPRD_bits;

/* Bit field positions: */
#define QEP_QCPRD_VAL_Pos                     0                      /*!<  */

/* Bit field masks: */
#define QEP_QCPRD_VAL_Msk                     0xFFFFFFFF             /*!<  */

/*--  QCTMRLAT: Capture Timer Latch register ------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!<  */
} _QEP_QCTMRLAT_bits;

/* Bit field positions: */
#define QEP_QCTMRLAT_VAL_Pos                  0                      /*!<  */

/* Bit field masks: */
#define QEP_QCTMRLAT_VAL_Msk                  0xFFFFFFFF             /*!<  */

/*--  QCPRDLAT: Capture Period Latch register -----------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!<  */
} _QEP_QCPRDLAT_bits;

/* Bit field positions: */
#define QEP_QCPRDLAT_VAL_Pos                  0                      /*!<  */

/* Bit field masks: */
#define QEP_QCPRDLAT_VAL_Msk                  0xFFFFFFFF             /*!<  */

/*--  DMAREQ: DMA request register ----------------------------------------------------------------------------*/
typedef struct {
  uint32_t DMAEN                  :1;                                /*!< DMA request enable */
} _QEP_DMAREQ_bits;

/* Bit field positions: */
#define QEP_DMAREQ_DMAEN_Pos                  0                      /*!< DMA request enable */

/* Bit field masks: */
#define QEP_DMAREQ_DMAEN_Msk                  0x00000001             /*!< DMA request enable */

/*--  INTCLR: Clear active interrupt register -----------------------------------------------------------------*/
typedef struct {
  uint32_t INT                    :1;                                /*!< Active interrupt by read, write 1 to clear interrupt */
} _QEP_INTCLR_bits;

/* Bit field positions: */
#define QEP_INTCLR_INT_Pos                    0                      /*!< Active interrupt by read, write 1 to clear interrupt */

/* Bit field masks: */
#define QEP_INTCLR_INT_Msk                    0x00000001             /*!< Active interrupt by read, write 1 to clear interrupt */

typedef struct {
  union {                                                               /*!< Position Counter register */
    __IO uint32_t QPOSCNT;                                           /*!< QPOSCNT    : type used for word access */
    __IO _QEP_QPOSCNT_bits  QPOSCNT_bit;                             /*!< QPOSCNT_bit: structure used for bit access */
  };
  union {                                                               /*!< Position Counter Initialization register */
    __IO uint32_t QPOSINIT;                                           /*!< QPOSINIT    : type used for word access */
    __IO _QEP_QPOSINIT_bits  QPOSINIT_bit;                           /*!< QPOSINIT_bit: structure used for bit access */
  };
  union {                                                               /*!< Maximum Position Count register */
    __IO uint32_t QPOSMAX;                                           /*!< QPOSMAX    : type used for word access */
    __IO _QEP_QPOSMAX_bits  QPOSMAX_bit;                             /*!< QPOSMAX_bit: structure used for bit access */
  };
  union {                                                               /*!< Position-compare register */
    __IO uint32_t QPOSCMP;                                           /*!< QPOSCMP    : type used for word access */
    __IO _QEP_QPOSCMP_bits  QPOSCMP_bit;                             /*!< QPOSCMP_bit: structure used for bit access */
  };
  union {                                                               /*!< Index Position Latch register */
    __I uint32_t QPOSILAT;                                           /*!< QPOSILAT    : type used for word access */
    __I _QEP_QPOSILAT_bits  QPOSILAT_bit;                            /*!< QPOSILAT_bit: structure used for bit access */
  };
  union {                                                               /*!< Strobe Position Latch register */
    __I uint32_t QPOSSLAT;                                           /*!< QPOSSLAT    : type used for word access */
    __I _QEP_QPOSSLAT_bits  QPOSSLAT_bit;                            /*!< QPOSSLAT_bit: structure used for bit access */
  };
  union {                                                               /*!< Position Counter Latch register */
    __I uint32_t QPOSLAT;                                            /*!< QPOSLAT    : type used for word access */
    __I _QEP_QPOSLAT_bits  QPOSLAT_bit;                              /*!< QPOSLAT_bit: structure used for bit access */
  };
  union {                                                               /*!< Unit Timer register */
    __IO uint32_t QUTMR;                                             /*!< QUTMR    : type used for word access */
    __IO _QEP_QUTMR_bits  QUTMR_bit;                                 /*!< QUTMR_bit: structure used for bit access */
  };
  union {                                                               /*!< Unit Period register */
    __IO uint32_t QUPRD;                                             /*!< QUPRD    : type used for word access */
    __IO _QEP_QUPRD_bits  QUPRD_bit;                                 /*!< QUPRD_bit: structure used for bit access */
  };
  union {                                                               /*!< Watchdog Timer register */
    __IO uint32_t QWDTMR;                                            /*!< QWDTMR    : type used for word access */
    __IO _QEP_QWDTMR_bits  QWDTMR_bit;                               /*!< QWDTMR_bit: structure used for bit access */
  };
  union {                                                               /*!< Watchdog Period register */
    __IO uint32_t QWDPRD;                                            /*!< QWDPRD    : type used for word access */
    __IO _QEP_QWDPRD_bits  QWDPRD_bit;                               /*!< QWDPRD_bit: structure used for bit access */
  };
  union {                                                               /*!< Decoder Control register */
    __IO uint32_t QDECCTL;                                           /*!< QDECCTL    : type used for word access */
    __IO _QEP_QDECCTL_bits  QDECCTL_bit;                             /*!< QDECCTL_bit: structure used for bit access */
  };
  union {                                                               /*!< Control register */
    __IO uint32_t QEPCTL;                                            /*!< QEPCTL    : type used for word access */
    __IO _QEP_QEPCTL_bits  QEPCTL_bit;                               /*!< QEPCTL_bit: structure used for bit access */
  };
  union {                                                               /*!< Capture Control register */
    __IO uint32_t QCAPCTL;                                           /*!< QCAPCTL    : type used for word access */
    __IO _QEP_QCAPCTL_bits  QCAPCTL_bit;                             /*!< QCAPCTL_bit: structure used for bit access */
  };
  union {                                                               /*!< Position-compare Control register */
    __IO uint32_t QPOSCTL;                                           /*!< QPOSCTL    : type used for word access */
    __IO _QEP_QPOSCTL_bits  QPOSCTL_bit;                             /*!< QPOSCTL_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt Enable register */
    __IO uint32_t QEINT;                                             /*!< QEINT    : type used for word access */
    __IO _QEP_QEINT_bits  QEINT_bit;                                 /*!< QEINT_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt Flag register */
    __I uint32_t QFLG;                                               /*!< QFLG    : type used for word access */
    __I _QEP_QFLG_bits  QFLG_bit;                                    /*!< QFLG_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt Clear register */
    __IO uint32_t QCLR;                                              /*!< QCLR    : type used for word access */
    __IO _QEP_QCLR_bits  QCLR_bit;                                   /*!< QCLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt Force register */
    __IO uint32_t QFRC;                                              /*!< QFRC    : type used for word access */
    __IO _QEP_QFRC_bits  QFRC_bit;                                   /*!< QFRC_bit: structure used for bit access */
  };
  union {                                                               /*!< Status register */
    __IO uint32_t QEPSTS;                                            /*!< QEPSTS    : type used for word access */
    __IO _QEP_QEPSTS_bits  QEPSTS_bit;                               /*!< QEPSTS_bit: structure used for bit access */
  };
  union {                                                               /*!< Capture Timer register */
    __IO uint32_t QCTMR;                                             /*!< QCTMR    : type used for word access */
    __IO _QEP_QCTMR_bits  QCTMR_bit;                                 /*!< QCTMR_bit: structure used for bit access */
  };
  union {                                                               /*!< Capture Period register */
    __IO uint32_t QCPRD;                                             /*!< QCPRD    : type used for word access */
    __IO _QEP_QCPRD_bits  QCPRD_bit;                                 /*!< QCPRD_bit: structure used for bit access */
  };
  union {                                                               /*!< Capture Timer Latch register */
    __I uint32_t QCTMRLAT;                                           /*!< QCTMRLAT    : type used for word access */
    __I _QEP_QCTMRLAT_bits  QCTMRLAT_bit;                            /*!< QCTMRLAT_bit: structure used for bit access */
  };
  union {                                                               /*!< Capture Period Latch register */
    __IO uint32_t QCPRDLAT;                                           /*!< QCPRDLAT    : type used for word access */
    __IO _QEP_QCPRDLAT_bits  QCPRDLAT_bit;                           /*!< QCPRDLAT_bit: structure used for bit access */
  };
  union {                                                               /*!< DMA request register */
    __IO uint32_t DMAREQ;                                            /*!< DMAREQ    : type used for word access */
    __IO _QEP_DMAREQ_bits  DMAREQ_bit;                               /*!< DMAREQ_bit: structure used for bit access */
  };
    __IO uint32_t Reserved0[3];
  union {                                                               /*!< Clear active interrupt register */
    __IO uint32_t INTCLR;                                            /*!< INTCLR    : type used for word access */
    __IO _QEP_INTCLR_bits  INTCLR_bit;                               /*!< INTCLR_bit: structure used for bit access */
  };
} QEP_TypeDef;

/******************************************************************************/
/*                         ECAP registers                                     */
/******************************************************************************/

/*--  TSCTR: Counter register ---------------------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!< Counter value */
} _ECAP_TSCTR_bits;

/* Bit field positions: */
#define ECAP_TSCTR_VAL_Pos                    0                      /*!< Counter value */

/* Bit field masks: */
#define ECAP_TSCTR_VAL_Msk                    0xFFFFFFFF             /*!< Counter value */

/*--  CTRPHS: Counter Phase Sync register ---------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!<  */
} _ECAP_CTRPHS_bits;

/* Bit field positions: */
#define ECAP_CTRPHS_VAL_Pos                   0                      /*!<  */

/* Bit field masks: */
#define ECAP_CTRPHS_VAL_Msk                   0xFFFFFFFF             /*!<  */

/*--  CAP0: Capture register 0 --------------------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!< Capture 0 value */
} _ECAP_CAP0_bits;

/* Bit field positions: */
#define ECAP_CAP0_VAL_Pos                     0                      /*!< Capture 0 value */

/* Bit field masks: */
#define ECAP_CAP0_VAL_Msk                     0xFFFFFFFF             /*!< Capture 0 value */

/*--  CAP1: Capture register 1 --------------------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!< Capture 1 value */
} _ECAP_CAP1_bits;

/* Bit field positions: */
#define ECAP_CAP1_VAL_Pos                     0                      /*!< Capture 1 value */

/* Bit field masks: */
#define ECAP_CAP1_VAL_Msk                     0xFFFFFFFF             /*!< Capture 1 value */

/*--  CAP2: Capture register 2 --------------------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!< Capture 2 value */
} _ECAP_CAP2_bits;

/* Bit field positions: */
#define ECAP_CAP2_VAL_Pos                     0                      /*!< Capture 2 value */

/* Bit field masks: */
#define ECAP_CAP2_VAL_Msk                     0xFFFFFFFF             /*!< Capture 2 value */

/*--  CAP3: Capture register 3 --------------------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!< Capture 3 value */
} _ECAP_CAP3_bits;

/* Bit field positions: */
#define ECAP_CAP3_VAL_Pos                     0                      /*!< Capture 3 value */

/* Bit field masks: */
#define ECAP_CAP3_VAL_Msk                     0xFFFFFFFF             /*!< Capture 3 value */

/*--  ECCTL0: Capture control  register 0 ---------------------------------------------------------------------*/
typedef struct {
  uint32_t CAP0POL                :1;                                /*!< Polarity select for capture 0 */
  uint32_t CTRRST0                :1;                                /*!< Reset counter after event 0 */
  uint32_t CAP1POL                :1;                                /*!< Polarity select for capture 1 */
  uint32_t CTRRST1                :1;                                /*!< Reset counter after event 1 */
  uint32_t CAP2POL                :1;                                /*!< Polarity select for capture 2 */
  uint32_t CTRRST2                :1;                                /*!< Reset counter after event 2 */
  uint32_t CAP3POL                :1;                                /*!< Polarity select for capture 3 */
  uint32_t CTRRST3                :1;                                /*!< Reset counter after event 3 */
  uint32_t CAPLDEN                :1;                                /*!< enable capture */
  uint32_t PRESCALE               :5;                                /*!< Prescaler value */
  uint32_t FREESOFT               :2;                                /*!< Emulation mode control */
} _ECAP_ECCTL0_bits;

/* Bit field positions: */
#define ECAP_ECCTL0_CAP0POL_Pos               0                      /*!< Polarity select for capture 0 */
#define ECAP_ECCTL0_CTRRST0_Pos               1                      /*!< Reset counter after event 0 */
#define ECAP_ECCTL0_CAP1POL_Pos               2                      /*!< Polarity select for capture 1 */
#define ECAP_ECCTL0_CTRRST1_Pos               3                      /*!< Reset counter after event 1 */
#define ECAP_ECCTL0_CAP2POL_Pos               4                      /*!< Polarity select for capture 2 */
#define ECAP_ECCTL0_CTRRST2_Pos               5                      /*!< Reset counter after event 2 */
#define ECAP_ECCTL0_CAP3POL_Pos               6                      /*!< Polarity select for capture 3 */
#define ECAP_ECCTL0_CTRRST3_Pos               7                      /*!< Reset counter after event 3 */
#define ECAP_ECCTL0_CAPLDEN_Pos               8                      /*!< enable capture */
#define ECAP_ECCTL0_PRESCALE_Pos              9                      /*!< Prescaler value */
#define ECAP_ECCTL0_FREESOFT_Pos              14                     /*!< Emulation mode control */

/* Bit field masks: */
#define ECAP_ECCTL0_CAP0POL_Msk               0x00000001             /*!< Polarity select for capture 0 */
#define ECAP_ECCTL0_CTRRST0_Msk               0x00000002             /*!< Reset counter after event 0 */
#define ECAP_ECCTL0_CAP1POL_Msk               0x00000004             /*!< Polarity select for capture 1 */
#define ECAP_ECCTL0_CTRRST1_Msk               0x00000008             /*!< Reset counter after event 1 */
#define ECAP_ECCTL0_CAP2POL_Msk               0x00000010             /*!< Polarity select for capture 2 */
#define ECAP_ECCTL0_CTRRST2_Msk               0x00000020             /*!< Reset counter after event 2 */
#define ECAP_ECCTL0_CAP3POL_Msk               0x00000040             /*!< Polarity select for capture 3 */
#define ECAP_ECCTL0_CTRRST3_Msk               0x00000080             /*!< Reset counter after event 3 */
#define ECAP_ECCTL0_CAPLDEN_Msk               0x00000100             /*!< enable capture */
#define ECAP_ECCTL0_PRESCALE_Msk              0x00003E00             /*!< Prescaler value */
#define ECAP_ECCTL0_FREESOFT_Msk              0x0000C000             /*!< Emulation mode control */

/* Bit field enums: */
typedef enum {
  ECAP_ECCTL0_FREESOFT_Stop                  = 0x0,                  /*!< stop timer immedeatelly */
  ECAP_ECCTL0_FREESOFT_StopAtZero            = 0x1,                  /*!< stop timer when reach zero */
} ECAP_ECCTL0_FREESOFT_Enum;

/*--  ECCTL1: Capture control register 1 ----------------------------------------------------------------------*/
typedef struct {
  uint32_t CONTOST                :1;                                /*!< Capture mode */
  uint32_t STOPWRAP               :2;                                /*!< Stop compare value */
  uint32_t REARM                  :1;                                /*!< Reset and enable controller, capture reg load */
  uint32_t TSCTRSTOP              :1;                                /*!< Enable Timer */
  uint32_t SYNCIEN                :1;                                /*!< Sync in enable */
  uint32_t SYNCOSEL               :2;                                /*!< SYNCO source selection */
  uint32_t SWSYNC                 :1;                                /*!< Software timers sync */
  uint32_t CAPAPWM                :1;                                /*!< Capture mode or APWM mode */
  uint32_t APWMPOL                :1;                                /*!< High/low level APWM */
} _ECAP_ECCTL1_bits;

/* Bit field positions: */
#define ECAP_ECCTL1_CONTOST_Pos               0                      /*!< Capture mode */
#define ECAP_ECCTL1_STOPWRAP_Pos              1                      /*!< Stop compare value */
#define ECAP_ECCTL1_REARM_Pos                 3                      /*!< Reset and enable controller, capture reg load */
#define ECAP_ECCTL1_TSCTRSTOP_Pos             4                      /*!< Enable Timer */
#define ECAP_ECCTL1_SYNCIEN_Pos               5                      /*!< Sync in enable */
#define ECAP_ECCTL1_SYNCOSEL_Pos              6                      /*!< SYNCO source selection */
#define ECAP_ECCTL1_SWSYNC_Pos                8                      /*!< Software timers sync */
#define ECAP_ECCTL1_CAPAPWM_Pos               9                      /*!< Capture mode or APWM mode */
#define ECAP_ECCTL1_APWMPOL_Pos               10                     /*!< High/low level APWM */

/* Bit field masks: */
#define ECAP_ECCTL1_CONTOST_Msk               0x00000001             /*!< Capture mode */
#define ECAP_ECCTL1_STOPWRAP_Msk              0x00000006             /*!< Stop compare value */
#define ECAP_ECCTL1_REARM_Msk                 0x00000008             /*!< Reset and enable controller, capture reg load */
#define ECAP_ECCTL1_TSCTRSTOP_Msk             0x00000010             /*!< Enable Timer */
#define ECAP_ECCTL1_SYNCIEN_Msk               0x00000020             /*!< Sync in enable */
#define ECAP_ECCTL1_SYNCOSEL_Msk              0x000000C0             /*!< SYNCO source selection */
#define ECAP_ECCTL1_SWSYNC_Msk                0x00000100             /*!< Software timers sync */
#define ECAP_ECCTL1_CAPAPWM_Msk               0x00000200             /*!< Capture mode or APWM mode */
#define ECAP_ECCTL1_APWMPOL_Msk               0x00000400             /*!< High/low level APWM */

/* Bit field enums: */
typedef enum {
  ECAP_ECCTL1_SYNCOSEL_Bypass                = 0x0,                  /*!< sync in connected with sync out */
  ECAP_ECCTL1_SYNCOSEL_CTREqPrd              = 0x1,                  /*!<  sync out generated when CTR = PRD */
  ECAP_ECCTL1_SYNCOSEL_Disable               = 0x2,                  /*!<  sync out generate disabled */
} ECAP_ECCTL1_SYNCOSEL_Enum;

/*--  ECEINT: Interrupt mask register -------------------------------------------------------------------------*/
typedef struct {
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t CEVT0                  :1;                                /*!< enable int CEVT0 */
  uint32_t CEVT1                  :1;                                /*!< enable int CEVT1 */
  uint32_t CEVT2                  :1;                                /*!< enable int CEVT2 */
  uint32_t CEVT3                  :1;                                /*!< enable int CEVT3 */
  uint32_t CTROVF                 :1;                                /*!< enable int CTR_OVF */
  uint32_t CTRPRD                 :1;                                /*!< enable int CTR=PRD */
  uint32_t CTRCMP                 :1;                                /*!< enable int CTR=CMP */
} _ECAP_ECEINT_bits;

/* Bit field positions: */
#define ECAP_ECEINT_CEVT0_Pos                 1                      /*!< enable int CEVT0 */
#define ECAP_ECEINT_CEVT1_Pos                 2                      /*!< enable int CEVT1 */
#define ECAP_ECEINT_CEVT2_Pos                 3                      /*!< enable int CEVT2 */
#define ECAP_ECEINT_CEVT3_Pos                 4                      /*!< enable int CEVT3 */
#define ECAP_ECEINT_CTROVF_Pos                5                      /*!< enable int CTR_OVF */
#define ECAP_ECEINT_CTRPRD_Pos                6                      /*!< enable int CTR=PRD */
#define ECAP_ECEINT_CTRCMP_Pos                7                      /*!< enable int CTR=CMP */

/* Bit field masks: */
#define ECAP_ECEINT_CEVT0_Msk                 0x00000002             /*!< enable int CEVT0 */
#define ECAP_ECEINT_CEVT1_Msk                 0x00000004             /*!< enable int CEVT1 */
#define ECAP_ECEINT_CEVT2_Msk                 0x00000008             /*!< enable int CEVT2 */
#define ECAP_ECEINT_CEVT3_Msk                 0x00000010             /*!< enable int CEVT3 */
#define ECAP_ECEINT_CTROVF_Msk                0x00000020             /*!< enable int CTR_OVF */
#define ECAP_ECEINT_CTRPRD_Msk                0x00000040             /*!< enable int CTR=PRD */
#define ECAP_ECEINT_CTRCMP_Msk                0x00000080             /*!< enable int CTR=CMP */

/*--  ECFLG: Interrupt status register ------------------------------------------------------------------------*/
typedef struct {
  uint32_t INT                    :1;                                /*!< indicate global interrupt */
  uint32_t CEVT0                  :1;                                /*!< Hap interrupt CEVT0 */
  uint32_t CEVT1                  :1;                                /*!< Hap interrupt CEVT1 */
  uint32_t CEVT2                  :1;                                /*!< Hap interrupt CEVT2 */
  uint32_t CEVT3                  :1;                                /*!< Hap interrupt CEVT3 */
  uint32_t CTROVF                 :1;                                /*!< Hap interrupt CTROVF */
  uint32_t CTRPRD                 :1;                                /*!< Hap interrupt CTR=PRD */
  uint32_t CTRCMP                 :1;                                /*!< Hap interrupt CTR=CMP */
} _ECAP_ECFLG_bits;

/* Bit field positions: */
#define ECAP_ECFLG_INT_Pos                    0                      /*!< indicate global interrupt */
#define ECAP_ECFLG_CEVT0_Pos                  1                      /*!< Hap interrupt CEVT0 */
#define ECAP_ECFLG_CEVT1_Pos                  2                      /*!< Hap interrupt CEVT1 */
#define ECAP_ECFLG_CEVT2_Pos                  3                      /*!< Hap interrupt CEVT2 */
#define ECAP_ECFLG_CEVT3_Pos                  4                      /*!< Hap interrupt CEVT3 */
#define ECAP_ECFLG_CTROVF_Pos                 5                      /*!< Hap interrupt CTROVF */
#define ECAP_ECFLG_CTRPRD_Pos                 6                      /*!< Hap interrupt CTR=PRD */
#define ECAP_ECFLG_CTRCMP_Pos                 7                      /*!< Hap interrupt CTR=CMP */

/* Bit field masks: */
#define ECAP_ECFLG_INT_Msk                    0x00000001             /*!< indicate global interrupt */
#define ECAP_ECFLG_CEVT0_Msk                  0x00000002             /*!< Hap interrupt CEVT0 */
#define ECAP_ECFLG_CEVT1_Msk                  0x00000004             /*!< Hap interrupt CEVT1 */
#define ECAP_ECFLG_CEVT2_Msk                  0x00000008             /*!< Hap interrupt CEVT2 */
#define ECAP_ECFLG_CEVT3_Msk                  0x00000010             /*!< Hap interrupt CEVT3 */
#define ECAP_ECFLG_CTROVF_Msk                 0x00000020             /*!< Hap interrupt CTROVF */
#define ECAP_ECFLG_CTRPRD_Msk                 0x00000040             /*!< Hap interrupt CTR=PRD */
#define ECAP_ECFLG_CTRCMP_Msk                 0x00000080             /*!< Hap interrupt CTR=CMP */

/*--  ECCLR: Clear interrupt register -------------------------------------------------------------------------*/
typedef struct {
  uint32_t INT                    :1;                                /*!< reset global interrupt */
  uint32_t CEVT0                  :1;                                /*!< reset intstatus */
  uint32_t CEVT1                  :1;                                /*!< reset intstatus */
  uint32_t CEVT2                  :1;                                /*!< reset intstatus */
  uint32_t CEVT3                  :1;                                /*!< reset intstatus */
  uint32_t CTROVF                 :1;                                /*!< reset intstatus */
  uint32_t CTRPRD                 :1;                                /*!< reset intstatus */
  uint32_t CTRCMP                 :1;                                /*!< reset intstatus */
} _ECAP_ECCLR_bits;

/* Bit field positions: */
#define ECAP_ECCLR_INT_Pos                    0                      /*!< reset global interrupt */
#define ECAP_ECCLR_CEVT0_Pos                  1                      /*!< reset intstatus */
#define ECAP_ECCLR_CEVT1_Pos                  2                      /*!< reset intstatus */
#define ECAP_ECCLR_CEVT2_Pos                  3                      /*!< reset intstatus */
#define ECAP_ECCLR_CEVT3_Pos                  4                      /*!< reset intstatus */
#define ECAP_ECCLR_CTROVF_Pos                 5                      /*!< reset intstatus */
#define ECAP_ECCLR_CTRPRD_Pos                 6                      /*!< reset intstatus */
#define ECAP_ECCLR_CTRCMP_Pos                 7                      /*!< reset intstatus */

/* Bit field masks: */
#define ECAP_ECCLR_INT_Msk                    0x00000001             /*!< reset global interrupt */
#define ECAP_ECCLR_CEVT0_Msk                  0x00000002             /*!< reset intstatus */
#define ECAP_ECCLR_CEVT1_Msk                  0x00000004             /*!< reset intstatus */
#define ECAP_ECCLR_CEVT2_Msk                  0x00000008             /*!< reset intstatus */
#define ECAP_ECCLR_CEVT3_Msk                  0x00000010             /*!< reset intstatus */
#define ECAP_ECCLR_CTROVF_Msk                 0x00000020             /*!< reset intstatus */
#define ECAP_ECCLR_CTRPRD_Msk                 0x00000040             /*!< reset intstatus */
#define ECAP_ECCLR_CTRCMP_Msk                 0x00000080             /*!< reset intstatus */

/*--  ECFRC: Force interrupt register -------------------------------------------------------------------------*/
typedef struct {
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t CEVT0                  :1;                                /*!< gen test interrupt */
  uint32_t CEVT1                  :1;                                /*!< gen test interrupt */
  uint32_t CEVT2                  :1;                                /*!< gen test interrupt */
  uint32_t CEVT3                  :1;                                /*!< gen test interrupt */
  uint32_t CTROVF                 :1;                                /*!< gen test interrupt */
  uint32_t CTRPRD                 :1;                                /*!< gen test interrupt */
  uint32_t CTRCMP                 :1;                                /*!< gen test interrupt */
} _ECAP_ECFRC_bits;

/* Bit field positions: */
#define ECAP_ECFRC_CEVT0_Pos                  1                      /*!< gen test interrupt */
#define ECAP_ECFRC_CEVT1_Pos                  2                      /*!< gen test interrupt */
#define ECAP_ECFRC_CEVT2_Pos                  3                      /*!< gen test interrupt */
#define ECAP_ECFRC_CEVT3_Pos                  4                      /*!< gen test interrupt */
#define ECAP_ECFRC_CTROVF_Pos                 5                      /*!< gen test interrupt */
#define ECAP_ECFRC_CTRPRD_Pos                 6                      /*!< gen test interrupt */
#define ECAP_ECFRC_CTRCMP_Pos                 7                      /*!< gen test interrupt */

/* Bit field masks: */
#define ECAP_ECFRC_CEVT0_Msk                  0x00000002             /*!< gen test interrupt */
#define ECAP_ECFRC_CEVT1_Msk                  0x00000004             /*!< gen test interrupt */
#define ECAP_ECFRC_CEVT2_Msk                  0x00000008             /*!< gen test interrupt */
#define ECAP_ECFRC_CEVT3_Msk                  0x00000010             /*!< gen test interrupt */
#define ECAP_ECFRC_CTROVF_Msk                 0x00000020             /*!< gen test interrupt */
#define ECAP_ECFRC_CTRPRD_Msk                 0x00000040             /*!< gen test interrupt */
#define ECAP_ECFRC_CTRCMP_Msk                 0x00000080             /*!< gen test interrupt */

/*--  PEINT: Active interrupt status register -----------------------------------------------------------------*/
typedef struct {
  uint32_t PEINT                  :1;                                /*!< active interrupt flag */
} _ECAP_PEINT_bits;

/* Bit field positions: */
#define ECAP_PEINT_PEINT_Pos                  0                      /*!< active interrupt flag */

/* Bit field masks: */
#define ECAP_PEINT_PEINT_Msk                  0x00000001             /*!< active interrupt flag */

typedef struct {
  union {                                                               /*!< Counter register */
    __IO uint32_t TSCTR;                                             /*!< TSCTR    : type used for word access */
    __IO _ECAP_TSCTR_bits  TSCTR_bit;                                /*!< TSCTR_bit: structure used for bit access */
  };
  union {                                                               /*!< Counter Phase Sync register */
    __IO uint32_t CTRPHS;                                            /*!< CTRPHS    : type used for word access */
    __IO _ECAP_CTRPHS_bits  CTRPHS_bit;                              /*!< CTRPHS_bit: structure used for bit access */
  };
  union {                                                               /*!< Capture register 0 */
    __IO uint32_t CAP0;                                              /*!< CAP0    : type used for word access */
    __IO _ECAP_CAP0_bits  CAP0_bit;                                  /*!< CAP0_bit: structure used for bit access */
  };
  union {                                                               /*!< Capture register 1 */
    __IO uint32_t CAP1;                                              /*!< CAP1    : type used for word access */
    __IO _ECAP_CAP1_bits  CAP1_bit;                                  /*!< CAP1_bit: structure used for bit access */
  };
  union {                                                               /*!< Capture register 2 */
    __IO uint32_t CAP2;                                              /*!< CAP2    : type used for word access */
    __IO _ECAP_CAP2_bits  CAP2_bit;                                  /*!< CAP2_bit: structure used for bit access */
  };
  union {                                                               /*!< Capture register 3 */
    __IO uint32_t CAP3;                                              /*!< CAP3    : type used for word access */
    __IO _ECAP_CAP3_bits  CAP3_bit;                                  /*!< CAP3_bit: structure used for bit access */
  };
    __IO uint32_t Reserved0[4];
  union {                                                               /*!< Capture control  register 0 */
    __IO uint32_t ECCTL0;                                            /*!< ECCTL0    : type used for word access */
    __IO _ECAP_ECCTL0_bits  ECCTL0_bit;                              /*!< ECCTL0_bit: structure used for bit access */
  };
  union {                                                               /*!< Capture control register 1 */
    __IO uint32_t ECCTL1;                                            /*!< ECCTL1    : type used for word access */
    __IO _ECAP_ECCTL1_bits  ECCTL1_bit;                              /*!< ECCTL1_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt mask register */
    __IO uint32_t ECEINT;                                            /*!< ECEINT    : type used for word access */
    __IO _ECAP_ECEINT_bits  ECEINT_bit;                              /*!< ECEINT_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt status register */
    __I uint32_t ECFLG;                                              /*!< ECFLG    : type used for word access */
    __I _ECAP_ECFLG_bits  ECFLG_bit;                                 /*!< ECFLG_bit: structure used for bit access */
  };
  union {                                                               /*!< Clear interrupt register */
    __IO uint32_t ECCLR;                                             /*!< ECCLR    : type used for word access */
    __IO _ECAP_ECCLR_bits  ECCLR_bit;                                /*!< ECCLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Force interrupt register */
    __IO uint32_t ECFRC;                                             /*!< ECFRC    : type used for word access */
    __IO _ECAP_ECFRC_bits  ECFRC_bit;                                /*!< ECFRC_bit: structure used for bit access */
  };
  union {                                                               /*!< Active interrupt status register */
    __IO uint32_t PEINT;                                             /*!< PEINT    : type used for word access */
    __IO _ECAP_PEINT_bits  PEINT_bit;                                /*!< PEINT_bit: structure used for bit access */
  };
} ECAP_TypeDef;

/******************************************************************************/
/*                         PWM registers                                      */
/******************************************************************************/

/*--  TBCTL: Time-Base Control Register -----------------------------------------------------------------------*/
typedef struct {
  uint32_t CTRMODE                :2;                                /*!< Counter mode */
  uint32_t PHSEN                  :1;                                /*!< Counter register load from phase register enable */
  uint32_t PRDLD                  :1;                                /*!< Active period register load from shadow register select */
  uint32_t SYNCOSEL               :2;                                /*!< Synchronization Output Select. These bits select the source of the PWM_SYNCO signal. */
  uint32_t SWFSYNC                :1;                                /*!< Software forced synchronization pulse */
  uint32_t HSPCLKDIV              :3;                                /*!< High speed time-base clock prescale bits */
  uint32_t CLKDIV                 :3;                                /*!< Time-base clock prescale bits */
  uint32_t PHSDIR                 :1;                                /*!< Phase direction bit */
  uint32_t FREESOFT               :2;                                /*!< Emulation mode bits - select the behavior of the time-base counter during emulation events */
  uint32_t SHDWGLOB               :1;                                /*!< Global enable for all shadow loads */
} _PWM_TBCTL_bits;

/* Bit field positions: */
#define PWM_TBCTL_CTRMODE_Pos                 0                      /*!< Counter mode */
#define PWM_TBCTL_PHSEN_Pos                   2                      /*!< Counter register load from phase register enable */
#define PWM_TBCTL_PRDLD_Pos                   3                      /*!< Active period register load from shadow register select */
#define PWM_TBCTL_SYNCOSEL_Pos                4                      /*!< Synchronization Output Select. These bits select the source of the PWM_SYNCO signal. */
#define PWM_TBCTL_SWFSYNC_Pos                 6                      /*!< Software forced synchronization pulse */
#define PWM_TBCTL_HSPCLKDIV_Pos               7                      /*!< High speed time-base clock prescale bits */
#define PWM_TBCTL_CLKDIV_Pos                  10                     /*!< Time-base clock prescale bits */
#define PWM_TBCTL_PHSDIR_Pos                  13                     /*!< Phase direction bit */
#define PWM_TBCTL_FREESOFT_Pos                14                     /*!< Emulation mode bits - select the behavior of the time-base counter during emulation events */
#define PWM_TBCTL_SHDWGLOB_Pos                16                     /*!< Global enable for all shadow loads */

/* Bit field masks: */
#define PWM_TBCTL_CTRMODE_Msk                 0x00000003             /*!< Counter mode */
#define PWM_TBCTL_PHSEN_Msk                   0x00000004             /*!< Counter register load from phase register enable */
#define PWM_TBCTL_PRDLD_Msk                   0x00000008             /*!< Active period register load from shadow register select */
#define PWM_TBCTL_SYNCOSEL_Msk                0x00000030             /*!< Synchronization Output Select. These bits select the source of the PWM_SYNCO signal. */
#define PWM_TBCTL_SWFSYNC_Msk                 0x00000040             /*!< Software forced synchronization pulse */
#define PWM_TBCTL_HSPCLKDIV_Msk               0x00000380             /*!< High speed time-base clock prescale bits */
#define PWM_TBCTL_CLKDIV_Msk                  0x00001C00             /*!< Time-base clock prescale bits */
#define PWM_TBCTL_PHSDIR_Msk                  0x00002000             /*!< Phase direction bit */
#define PWM_TBCTL_FREESOFT_Msk                0x0000C000             /*!< Emulation mode bits - select the behavior of the time-base counter during emulation events */
#define PWM_TBCTL_SHDWGLOB_Msk                0x00010000             /*!< Global enable for all shadow loads */

/* Bit field enums: */
typedef enum {
  PWM_TBCTL_SYNCOSEL_SYNCI                   = 0x0,                  /*!< PWM_SYNCI is source for PWM_SYNCO */
  PWM_TBCTL_SYNCOSEL_CTREqZero               = 0x1,                  /*!<  CTR = 0000h is source for PWM_SYNCO */
  PWM_TBCTL_SYNCOSEL_CTREqCMPB               = 0x2,                  /*!< CTR = CMPB is source for PWM_SYNCO */
  PWM_TBCTL_SYNCOSEL_Disable                 = 0x3,                  /*!< PWM_SYNCO generation disabled */
} PWM_TBCTL_SYNCOSEL_Enum;

typedef enum {
  PWM_TBCTL_HSPCLKDIV_Div1                   = 0x0,                  /*!< clock not divided */
  PWM_TBCTL_HSPCLKDIV_Div2                   = 0x1,                  /*!< clock divided by 2 */
  PWM_TBCTL_HSPCLKDIV_Div4                   = 0x2,                  /*!< clock divided by 4 */
  PWM_TBCTL_HSPCLKDIV_Div6                   = 0x3,                  /*!< clock divided by 6 */
  PWM_TBCTL_HSPCLKDIV_Div8                   = 0x4,                  /*!< clock divided by 8 */
  PWM_TBCTL_HSPCLKDIV_Div10                  = 0x5,                  /*!< clock divided by 10 */
  PWM_TBCTL_HSPCLKDIV_Div12                  = 0x6,                  /*!< clock divided by 12 */
  PWM_TBCTL_HSPCLKDIV_Div14                  = 0x7,                  /*!< clock divided by 14 */
} PWM_TBCTL_HSPCLKDIV_Enum;

typedef enum {
  PWM_TBCTL_CLKDIV_Div1                      = 0x0,                  /*!< clock not divided */
  PWM_TBCTL_CLKDIV_Div2                      = 0x1,                  /*!< clock divided by 2 */
  PWM_TBCTL_CLKDIV_Div4                      = 0x2,                  /*!< clock divided by 4 */
  PWM_TBCTL_CLKDIV_Div8                      = 0x3,                  /*!< clock divided by 8 */
  PWM_TBCTL_CLKDIV_Div16                     = 0x4,                  /*!< clock divided by 16 */
  PWM_TBCTL_CLKDIV_Div32                     = 0x5,                  /*!< clock divided by 32 */
  PWM_TBCTL_CLKDIV_Div64                     = 0x6,                  /*!< clock divided by 64 */
  PWM_TBCTL_CLKDIV_Div128                    = 0x7,                  /*!< clock divided by 128 */
} PWM_TBCTL_CLKDIV_Enum;

typedef enum {
  PWM_TBCTL_FREESOFT_StopAtTBCLK             = 0x0,                  /*!< stop timer at next TBCLK tact */
  PWM_TBCTL_FREESOFT_StopAtPeriod            = 0x1,                  /*!< stop timer when period ends */
  PWM_TBCTL_FREESOFT_FreeRun                 = 0x2,                  /*!< free run mode */
} PWM_TBCTL_FREESOFT_Enum;

/*--  TBSTS: Time-Base Status Register ------------------------------------------------------------------------*/
typedef struct {
  uint32_t CTRDIR                 :1;                                /*!< Time-Base counter direction status bit */
  uint32_t SYNCI                  :1;                                /*!< Input synchronization latched status bit */
  uint32_t CTRMAX                 :1;                                /*!< Time-Base counter max latched status bit */
} _PWM_TBSTS_bits;

/* Bit field positions: */
#define PWM_TBSTS_CTRDIR_Pos                  0                      /*!< Time-Base counter direction status bit */
#define PWM_TBSTS_SYNCI_Pos                   1                      /*!< Input synchronization latched status bit */
#define PWM_TBSTS_CTRMAX_Pos                  2                      /*!< Time-Base counter max latched status bit */

/* Bit field masks: */
#define PWM_TBSTS_CTRDIR_Msk                  0x00000001             /*!< Time-Base counter direction status bit */
#define PWM_TBSTS_SYNCI_Msk                   0x00000002             /*!< Input synchronization latched status bit */
#define PWM_TBSTS_CTRMAX_Msk                  0x00000004             /*!< Time-Base counter max latched status bit */

/*--  TBPHS: Time-Base Phase Register -------------------------------------------------------------------------*/
typedef struct {
  uint32_t                        :8;                                /*!< RESERVED */
  uint32_t TBPHSHR                :8;                                /*!< Time-base counter phase in High-Resolution mode */
  uint32_t TBPHS                  :16;                               /*!< Time-base counter phase */
} _PWM_TBPHS_bits;

/* Bit field positions: */
#define PWM_TBPHS_TBPHSHR_Pos                 8                      /*!< Time-base counter phase in High-Resolution mode */
#define PWM_TBPHS_TBPHS_Pos                   16                     /*!< Time-base counter phase */

/* Bit field masks: */
#define PWM_TBPHS_TBPHSHR_Msk                 0x0000FF00             /*!< Time-base counter phase in High-Resolution mode */
#define PWM_TBPHS_TBPHS_Msk                   0xFFFF0000             /*!< Time-base counter phase */

/*--  TBCTR: Time-Base Counter Register -----------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :16;                               /*!< Current time-base counter value */
} _PWM_TBCTR_bits;

/* Bit field positions: */
#define PWM_TBCTR_VAL_Pos                     0                      /*!< Current time-base counter value */

/* Bit field masks: */
#define PWM_TBCTR_VAL_Msk                     0x0000FFFF             /*!< Current time-base counter value */

/*--  TBPRD: Time-Base Period Register ------------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :16;                               /*!< Period of the time-base counter */
} _PWM_TBPRD_bits;

/* Bit field positions: */
#define PWM_TBPRD_VAL_Pos                     0                      /*!< Period of the time-base counter */

/* Bit field masks: */
#define PWM_TBPRD_VAL_Msk                     0x0000FFFF             /*!< Period of the time-base counter */

/*--  CMPCTL: Counter-Compare Control Register ----------------------------------------------------------------*/
typedef struct {
  uint32_t LOADAMODE              :2;                                /*!< Active CMPA load from shadow select mode */
  uint32_t LOADBMODE              :2;                                /*!< Active CMPB load from shadow select mode */
  uint32_t SHDWAMODE              :1;                                /*!< CMPA register operating mode */
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t SHDWBMODE              :1;                                /*!< CMPB register operating mode */
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t SHDWAFULL              :1;                                /*!< CMPA shadow register full status flag */
  uint32_t SHDWBFULL              :1;                                /*!< CMPB shadow register full status flag */
} _PWM_CMPCTL_bits;

/* Bit field positions: */
#define PWM_CMPCTL_LOADAMODE_Pos              0                      /*!< Active CMPA load from shadow select mode */
#define PWM_CMPCTL_LOADBMODE_Pos              2                      /*!< Active CMPB load from shadow select mode */
#define PWM_CMPCTL_SHDWAMODE_Pos              4                      /*!< CMPA register operating mode */
#define PWM_CMPCTL_SHDWBMODE_Pos              6                      /*!< CMPB register operating mode */
#define PWM_CMPCTL_SHDWAFULL_Pos              8                      /*!< CMPA shadow register full status flag */
#define PWM_CMPCTL_SHDWBFULL_Pos              9                      /*!< CMPB shadow register full status flag */

/* Bit field masks: */
#define PWM_CMPCTL_LOADAMODE_Msk              0x00000003             /*!< Active CMPA load from shadow select mode */
#define PWM_CMPCTL_LOADBMODE_Msk              0x0000000C             /*!< Active CMPB load from shadow select mode */
#define PWM_CMPCTL_SHDWAMODE_Msk              0x00000010             /*!< CMPA register operating mode */
#define PWM_CMPCTL_SHDWBMODE_Msk              0x00000040             /*!< CMPB register operating mode */
#define PWM_CMPCTL_SHDWAFULL_Msk              0x00000100             /*!< CMPA shadow register full status flag */
#define PWM_CMPCTL_SHDWBFULL_Msk              0x00000200             /*!< CMPB shadow register full status flag */

/* Bit field enums: */
typedef enum {
  PWM_CMPCTL_LOADAMODE_CTREqZero             = 0x0,                  /*!< shadow load for CMPx (x=A,B) when CTR = 0 */
  PWM_CMPCTL_LOADAMODE_CTREqPRD              = 0x1,                  /*!< shadow load for CMPx (x=A,B) when CTR = PRD */
  PWM_CMPCTL_LOADAMODE_CTREqZeroPRD          = 0x2,                  /*!< shadow load for CMPx (x=A,B) when CTR = 0 or CTR = PRD */
  PWM_CMPCTL_LOADAMODE_Disable               = 0x3,                  /*!< shadow load for CMPx (x=A,B) disabled */
} PWM_CMPCTL_LOADAMODE_Enum;

typedef enum {
  PWM_CMPCTL_LOADBMODE_CTREqZero             = 0x0,                  /*!< shadow load for CMPx (x=A,B) when CTR = 0 */
  PWM_CMPCTL_LOADBMODE_CTREqPRD              = 0x1,                  /*!< shadow load for CMPx (x=A,B) when CTR = PRD */
  PWM_CMPCTL_LOADBMODE_CTREqZeroPRD          = 0x2,                  /*!< shadow load for CMPx (x=A,B) when CTR = 0 or CTR = PRD */
  PWM_CMPCTL_LOADBMODE_Disable               = 0x3,                  /*!< shadow load for CMPx (x=A,B) disabled */
} PWM_CMPCTL_LOADBMODE_Enum;

/*--  CMPA: Counter-Compare A Register ------------------------------------------------------------------------*/
typedef struct {
  uint32_t                        :8;                                /*!< RESERVED */
  uint32_t CMPAHR                 :8;                                /*!< The value compared to the time-base counter (TBCTR) in High-Resolution mode */
  uint32_t CMPA                   :16;                               /*!< The value compared to the time-base counter (TBCTR) */
} _PWM_CMPA_bits;

/* Bit field positions: */
#define PWM_CMPA_CMPAHR_Pos                   8                      /*!< The value compared to the time-base counter (TBCTR) in High-Resolution mode */
#define PWM_CMPA_CMPA_Pos                     16                     /*!< The value compared to the time-base counter (TBCTR) */

/* Bit field masks: */
#define PWM_CMPA_CMPAHR_Msk                   0x0000FF00             /*!< The value compared to the time-base counter (TBCTR) in High-Resolution mode */
#define PWM_CMPA_CMPA_Msk                     0xFFFF0000             /*!< The value compared to the time-base counter (TBCTR) */

/*--  CMPB: Counter-Compare B Register ------------------------------------------------------------------------*/
typedef struct {
  uint32_t                        :16;                               /*!< RESERVED */
  uint32_t CMPB                   :16;                               /*!< The value compared to the time-base counter (TBCTR) */
} _PWM_CMPB_bits;

/* Bit field positions: */
#define PWM_CMPB_CMPB_Pos                     16                     /*!< The value compared to the time-base counter (TBCTR) */

/* Bit field masks: */
#define PWM_CMPB_CMPB_Msk                     0xFFFF0000             /*!< The value compared to the time-base counter (TBCTR) */

/*--  AQCTLA: Action-Qualifier Output A Control Register ------------------------------------------------------*/
typedef struct {
  uint32_t ZRO                    :2;                                /*!< Action when counter equals zero */
  uint32_t PRD                    :2;                                /*!< Action when the counter equals the period */
  uint32_t CAU                    :2;                                /*!< Action when the counter equals the active CMPA register and the counter is incrementing */
  uint32_t CAD                    :2;                                /*!< Action when the counter equals the active CMPA register and the counter is decrementing */
  uint32_t CBU                    :2;                                /*!< Action when the counter equals the active CMPB register and the counter is incrementing */
  uint32_t CBD                    :2;                                /*!< Action when the time-base counter equals the active CMPB register and the counter is decrementing
 */
} _PWM_AQCTLA_bits;

/* Bit field positions: */
#define PWM_AQCTLA_ZRO_Pos                    0                      /*!< Action when counter equals zero */
#define PWM_AQCTLA_PRD_Pos                    2                      /*!< Action when the counter equals the period */
#define PWM_AQCTLA_CAU_Pos                    4                      /*!< Action when the counter equals the active CMPA register and the counter is incrementing */
#define PWM_AQCTLA_CAD_Pos                    6                      /*!< Action when the counter equals the active CMPA register and the counter is decrementing */
#define PWM_AQCTLA_CBU_Pos                    8                      /*!< Action when the counter equals the active CMPB register and the counter is incrementing */
#define PWM_AQCTLA_CBD_Pos                    10                     /*!< Action when the time-base counter equals the active CMPB register and the counter is decrementing
 */

/* Bit field masks: */
#define PWM_AQCTLA_ZRO_Msk                    0x00000003             /*!< Action when counter equals zero */
#define PWM_AQCTLA_PRD_Msk                    0x0000000C             /*!< Action when the counter equals the period */
#define PWM_AQCTLA_CAU_Msk                    0x00000030             /*!< Action when the counter equals the active CMPA register and the counter is incrementing */
#define PWM_AQCTLA_CAD_Msk                    0x000000C0             /*!< Action when the counter equals the active CMPA register and the counter is decrementing */
#define PWM_AQCTLA_CBU_Msk                    0x00000300             /*!< Action when the counter equals the active CMPB register and the counter is incrementing */
#define PWM_AQCTLA_CBD_Msk                    0x00000C00             /*!< Action when the time-base counter equals the active CMPB register and the counter is decrementing
 */

/* Bit field enums: */
typedef enum {
  PWM_AQCTLA_ZRO_NoAction                    = 0x0,                  /*!< no action */
  PWM_AQCTLA_ZRO_Clear                       = 0x1,                  /*!< clear PWMA/PWMB */
  PWM_AQCTLA_ZRO_Set                         = 0x2,                  /*!< set PWMA/PWMB */
  PWM_AQCTLA_ZRO_Toogle                      = 0x3,                  /*!< inverse PWMA/PWMB */
} PWM_AQCTLA_ZRO_Enum;

typedef enum {
  PWM_AQCTLA_PRD_NoAction                    = 0x0,                  /*!< no action */
  PWM_AQCTLA_PRD_Clear                       = 0x1,                  /*!< clear PWMA/PWMB */
  PWM_AQCTLA_PRD_Set                         = 0x2,                  /*!< set PWMA/PWMB */
  PWM_AQCTLA_PRD_Toogle                      = 0x3,                  /*!< inverse PWMA/PWMB */
} PWM_AQCTLA_PRD_Enum;

typedef enum {
  PWM_AQCTLA_CAU_NoAction                    = 0x0,                  /*!< no action */
  PWM_AQCTLA_CAU_Clear                       = 0x1,                  /*!< clear PWMA/PWMB */
  PWM_AQCTLA_CAU_Set                         = 0x2,                  /*!< set PWMA/PWMB */
  PWM_AQCTLA_CAU_Toogle                      = 0x3,                  /*!< inverse PWMA/PWMB */
} PWM_AQCTLA_CAU_Enum;

typedef enum {
  PWM_AQCTLA_CAD_NoAction                    = 0x0,                  /*!< no action */
  PWM_AQCTLA_CAD_Clear                       = 0x1,                  /*!< clear PWMA/PWMB */
  PWM_AQCTLA_CAD_Set                         = 0x2,                  /*!< set PWMA/PWMB */
  PWM_AQCTLA_CAD_Toogle                      = 0x3,                  /*!< inverse PWMA/PWMB */
} PWM_AQCTLA_CAD_Enum;

typedef enum {
  PWM_AQCTLA_CBU_NoAction                    = 0x0,                  /*!< no action */
  PWM_AQCTLA_CBU_Clear                       = 0x1,                  /*!< clear PWMA/PWMB */
  PWM_AQCTLA_CBU_Set                         = 0x2,                  /*!< set PWMA/PWMB */
  PWM_AQCTLA_CBU_Toogle                      = 0x3,                  /*!< inverse PWMA/PWMB */
} PWM_AQCTLA_CBU_Enum;

typedef enum {
  PWM_AQCTLA_CBD_NoAction                    = 0x0,                  /*!< no action */
  PWM_AQCTLA_CBD_Clear                       = 0x1,                  /*!< clear PWMA/PWMB */
  PWM_AQCTLA_CBD_Set                         = 0x2,                  /*!< set PWMA/PWMB */
  PWM_AQCTLA_CBD_Toogle                      = 0x3,                  /*!< inverse PWMA/PWMB */
} PWM_AQCTLA_CBD_Enum;

/*--  AQCTLB: Action-Qualifier Output B Control Register ------------------------------------------------------*/
typedef struct {
  uint32_t ZRO                    :2;                                /*!< Action when counter equals zero */
  uint32_t PRD                    :2;                                /*!< Action when the counter equals the period */
  uint32_t CAU                    :2;                                /*!< Action when the counter equals the active CMPA register and the counter is incrementing */
  uint32_t CAD                    :2;                                /*!< Action when the counter equals the active CMPA register and the counter is decrementing */
  uint32_t CBU                    :2;                                /*!< Action when the counter equals the active CMPB register and the counter is incrementing */
  uint32_t CBD                    :2;                                /*!< Action when the time-base counter equals the active CMPB register and the counter is decrementing
 */
} _PWM_AQCTLB_bits;

/* Bit field positions: */
#define PWM_AQCTLB_ZRO_Pos                    0                      /*!< Action when counter equals zero */
#define PWM_AQCTLB_PRD_Pos                    2                      /*!< Action when the counter equals the period */
#define PWM_AQCTLB_CAU_Pos                    4                      /*!< Action when the counter equals the active CMPA register and the counter is incrementing */
#define PWM_AQCTLB_CAD_Pos                    6                      /*!< Action when the counter equals the active CMPA register and the counter is decrementing */
#define PWM_AQCTLB_CBU_Pos                    8                      /*!< Action when the counter equals the active CMPB register and the counter is incrementing */
#define PWM_AQCTLB_CBD_Pos                    10                     /*!< Action when the time-base counter equals the active CMPB register and the counter is decrementing
 */

/* Bit field masks: */
#define PWM_AQCTLB_ZRO_Msk                    0x00000003             /*!< Action when counter equals zero */
#define PWM_AQCTLB_PRD_Msk                    0x0000000C             /*!< Action when the counter equals the period */
#define PWM_AQCTLB_CAU_Msk                    0x00000030             /*!< Action when the counter equals the active CMPA register and the counter is incrementing */
#define PWM_AQCTLB_CAD_Msk                    0x000000C0             /*!< Action when the counter equals the active CMPA register and the counter is decrementing */
#define PWM_AQCTLB_CBU_Msk                    0x00000300             /*!< Action when the counter equals the active CMPB register and the counter is incrementing */
#define PWM_AQCTLB_CBD_Msk                    0x00000C00             /*!< Action when the time-base counter equals the active CMPB register and the counter is decrementing
 */

/* Bit field enums: */
typedef enum {
  PWM_AQCTLB_ZRO_NoAction                    = 0x0,                  /*!< no action */
  PWM_AQCTLB_ZRO_Clear                       = 0x1,                  /*!< clear PWMA/PWMB */
  PWM_AQCTLB_ZRO_Set                         = 0x2,                  /*!< set PWMA/PWMB */
  PWM_AQCTLB_ZRO_Toogle                      = 0x3,                  /*!< inverse PWMA/PWMB */
} PWM_AQCTLB_ZRO_Enum;

typedef enum {
  PWM_AQCTLB_PRD_NoAction                    = 0x0,                  /*!< no action */
  PWM_AQCTLB_PRD_Clear                       = 0x1,                  /*!< clear PWMA/PWMB */
  PWM_AQCTLB_PRD_Set                         = 0x2,                  /*!< set PWMA/PWMB */
  PWM_AQCTLB_PRD_Toogle                      = 0x3,                  /*!< inverse PWMA/PWMB */
} PWM_AQCTLB_PRD_Enum;

typedef enum {
  PWM_AQCTLB_CAU_NoAction                    = 0x0,                  /*!< no action */
  PWM_AQCTLB_CAU_Clear                       = 0x1,                  /*!< clear PWMA/PWMB */
  PWM_AQCTLB_CAU_Set                         = 0x2,                  /*!< set PWMA/PWMB */
  PWM_AQCTLB_CAU_Toogle                      = 0x3,                  /*!< inverse PWMA/PWMB */
} PWM_AQCTLB_CAU_Enum;

typedef enum {
  PWM_AQCTLB_CAD_NoAction                    = 0x0,                  /*!< no action */
  PWM_AQCTLB_CAD_Clear                       = 0x1,                  /*!< clear PWMA/PWMB */
  PWM_AQCTLB_CAD_Set                         = 0x2,                  /*!< set PWMA/PWMB */
  PWM_AQCTLB_CAD_Toogle                      = 0x3,                  /*!< inverse PWMA/PWMB */
} PWM_AQCTLB_CAD_Enum;

typedef enum {
  PWM_AQCTLB_CBU_NoAction                    = 0x0,                  /*!< no action */
  PWM_AQCTLB_CBU_Clear                       = 0x1,                  /*!< clear PWMA/PWMB */
  PWM_AQCTLB_CBU_Set                         = 0x2,                  /*!< set PWMA/PWMB */
  PWM_AQCTLB_CBU_Toogle                      = 0x3,                  /*!< inverse PWMA/PWMB */
} PWM_AQCTLB_CBU_Enum;

typedef enum {
  PWM_AQCTLB_CBD_NoAction                    = 0x0,                  /*!< no action */
  PWM_AQCTLB_CBD_Clear                       = 0x1,                  /*!< clear PWMA/PWMB */
  PWM_AQCTLB_CBD_Set                         = 0x2,                  /*!< set PWMA/PWMB */
  PWM_AQCTLB_CBD_Toogle                      = 0x3,                  /*!< inverse PWMA/PWMB */
} PWM_AQCTLB_CBD_Enum;

/*--  AQSFRC: Action-Qualifier Software Force Register --------------------------------------------------------*/
typedef struct {
  uint32_t ACTSFA                 :2;                                /*!< Action when one-time software force A is invoked */
  uint32_t OTSFA                  :1;                                /*!< One-time software forced event on output A */
  uint32_t ACTSFB                 :2;                                /*!< Action when one-time software force B is invoked */
  uint32_t OTSFB                  :1;                                /*!< One-time software forced event on output B */
  uint32_t RLDCSF                 :2;                                /*!< AQCSFRC active register reload from shadow options */
} _PWM_AQSFRC_bits;

/* Bit field positions: */
#define PWM_AQSFRC_ACTSFA_Pos                 0                      /*!< Action when one-time software force A is invoked */
#define PWM_AQSFRC_OTSFA_Pos                  2                      /*!< One-time software forced event on output A */
#define PWM_AQSFRC_ACTSFB_Pos                 3                      /*!< Action when one-time software force B is invoked */
#define PWM_AQSFRC_OTSFB_Pos                  5                      /*!< One-time software forced event on output B */
#define PWM_AQSFRC_RLDCSF_Pos                 6                      /*!< AQCSFRC active register reload from shadow options */

/* Bit field masks: */
#define PWM_AQSFRC_ACTSFA_Msk                 0x00000003             /*!< Action when one-time software force A is invoked */
#define PWM_AQSFRC_OTSFA_Msk                  0x00000004             /*!< One-time software forced event on output A */
#define PWM_AQSFRC_ACTSFB_Msk                 0x00000018             /*!< Action when one-time software force B is invoked */
#define PWM_AQSFRC_OTSFB_Msk                  0x00000020             /*!< One-time software forced event on output B */
#define PWM_AQSFRC_RLDCSF_Msk                 0x000000C0             /*!< AQCSFRC active register reload from shadow options */

/* Bit field enums: */
typedef enum {
  PWM_AQSFRC_ACTSFA_NoAction                 = 0x0,                  /*!< no action */
  PWM_AQSFRC_ACTSFA_Clear                    = 0x1,                  /*!< clear PWMA/PWMB */
  PWM_AQSFRC_ACTSFA_Set                      = 0x2,                  /*!< set PWMA/PWMB */
  PWM_AQSFRC_ACTSFA_Toogle                   = 0x3,                  /*!< inverse PWMA/PWMB */
} PWM_AQSFRC_ACTSFA_Enum;

typedef enum {
  PWM_AQSFRC_ACTSFB_NoAction                 = 0x0,                  /*!< no action */
  PWM_AQSFRC_ACTSFB_Clear                    = 0x1,                  /*!< clear PWMA/PWMB */
  PWM_AQSFRC_ACTSFB_Set                      = 0x2,                  /*!< set PWMA/PWMB */
  PWM_AQSFRC_ACTSFB_Toogle                   = 0x3,                  /*!< inverse PWMA/PWMB */
} PWM_AQSFRC_ACTSFB_Enum;

typedef enum {
  PWM_AQSFRC_RLDCSF_CTREqZero                = 0x0,                  /*!< load when CTR = 0 */
  PWM_AQSFRC_RLDCSF_CTREqPRD                 = 0x1,                  /*!< load when CTR = PRD */
  PWM_AQSFRC_RLDCSF_CTREqZeroPRD             = 0x2,                  /*!< load when CTR = 0 or CTR = PRD */
  PWM_AQSFRC_RLDCSF_NoShadow                 = 0x3,                  /*!< load immediatelly */
} PWM_AQSFRC_RLDCSF_Enum;

/*--  AQCSFRC: Action-Qualifier Continuous Software Force Register --------------------------------------------*/
typedef struct {
  uint32_t CSFA                   :2;                                /*!< Continuous software force on output A */
  uint32_t CSFB                   :2;                                /*!< Continuous software force on output B */
} _PWM_AQCSFRC_bits;

/* Bit field positions: */
#define PWM_AQCSFRC_CSFA_Pos                  0                      /*!< Continuous software force on output A */
#define PWM_AQCSFRC_CSFB_Pos                  2                      /*!< Continuous software force on output B */

/* Bit field masks: */
#define PWM_AQCSFRC_CSFA_Msk                  0x00000003             /*!< Continuous software force on output A */
#define PWM_AQCSFRC_CSFB_Msk                  0x0000000C             /*!< Continuous software force on output B */

/* Bit field enums: */
typedef enum {
  PWM_AQCSFRC_CSFA_NoAction                  = 0x0,                  /*!< no action */
  PWM_AQCSFRC_CSFA_Clear                     = 0x1,                  /*!< clear PWMA/PWMB */
  PWM_AQCSFRC_CSFA_Set                       = 0x2,                  /*!< set PWMA/PWMB */
} PWM_AQCSFRC_CSFA_Enum;

typedef enum {
  PWM_AQCSFRC_CSFB_NoAction                  = 0x0,                  /*!< no action */
  PWM_AQCSFRC_CSFB_Clear                     = 0x1,                  /*!< clear PWMA/PWMB */
  PWM_AQCSFRC_CSFB_Set                       = 0x2,                  /*!< set PWMA/PWMB */
} PWM_AQCSFRC_CSFB_Enum;

/*--  DBCTL: Dead-Band Generator Control Register -------------------------------------------------------------*/
typedef struct {
  uint32_t OUTMODE                :2;                                /*!< Dead-band output mode control */
  uint32_t POLSEL                 :2;                                /*!< Polarity select control */
  uint32_t INMODE                 :2;                                /*!< Dead band input mode control */
} _PWM_DBCTL_bits;

/* Bit field positions: */
#define PWM_DBCTL_OUTMODE_Pos                 0                      /*!< Dead-band output mode control */
#define PWM_DBCTL_POLSEL_Pos                  2                      /*!< Polarity select control */
#define PWM_DBCTL_INMODE_Pos                  4                      /*!< Dead band input mode control */

/* Bit field masks: */
#define PWM_DBCTL_OUTMODE_Msk                 0x00000003             /*!< Dead-band output mode control */
#define PWM_DBCTL_POLSEL_Msk                  0x0000000C             /*!< Polarity select control */
#define PWM_DBCTL_INMODE_Msk                  0x00000030             /*!< Dead band input mode control */

/* Bit field enums: */
typedef enum {
  PWM_DBCTL_OUTMODE_NoSpec                   = 0x0,                  /*!< edge for deadtime is no specified */
  PWM_DBCTL_OUTMODE_BNeg                     = 0x1,                  /*!< deadtime on PWMB negedge */
  PWM_DBCTL_OUTMODE_APos                     = 0x2,                  /*!< deadtime on PWMA posedge */
  PWM_DBCTL_OUTMODE_Apos_BNeg                = 0x3,                  /*!< deadtime on PWMA posedge and PWMB negedge */
} PWM_DBCTL_OUTMODE_Enum;

typedef enum {
  PWM_DBCTL_POLSEL_InvDisable                = 0x0,                  /*!< inverse disabled */
  PWM_DBCTL_POLSEL_InvA                      = 0x1,                  /*!< inverse on PWMA */
  PWM_DBCTL_POLSEL_InvB                      = 0x2,                  /*!< inverse on PWMB */
  PWM_DBCTL_POLSEL_InvAB                     = 0x3,                  /*!< inverse on PWMA and PWMB */
} PWM_DBCTL_POLSEL_Enum;

typedef enum {
  PWM_DBCTL_INMODE_APosNeg                   = 0x0,                  /*!< PWMA is used for posedge and negedge control */
  PWM_DBCTL_INMODE_ANeg_BPos                 = 0x1,                  /*!< PWMA is used for negedge and PWMB is used for posedge control */
  PWM_DBCTL_INMODE_APos_BNeg                 = 0x2,                  /*!< PWMA is used for posedge and PWMB is used for negedge control */
  PWM_DBCTL_INMODE_BPosNeg                   = 0x3,                  /*!< PWMB is used for posedge and negedge control */
} PWM_DBCTL_INMODE_Enum;

/*--  DBRED: Dead-Band Generator Rising Edge Delay Register ---------------------------------------------------*/
typedef struct {
  uint32_t DEL                    :10;                               /*!< Rising edge delay count */
} _PWM_DBRED_bits;

/* Bit field positions: */
#define PWM_DBRED_DEL_Pos                     0                      /*!< Rising edge delay count */

/* Bit field masks: */
#define PWM_DBRED_DEL_Msk                     0x000003FF             /*!< Rising edge delay count */

/*--  DBFED: Dead-Band Generator Falling Edge Delay Register --------------------------------------------------*/
typedef struct {
  uint32_t DEL                    :10;                               /*!< Falling edge delay count */
} _PWM_DBFED_bits;

/* Bit field positions: */
#define PWM_DBFED_DEL_Pos                     0                      /*!< Falling edge delay count */

/* Bit field masks: */
#define PWM_DBFED_DEL_Msk                     0x000003FF             /*!< Falling edge delay count */

/*--  TZSEL: Trip-Zone Select Register ------------------------------------------------------------------------*/
typedef struct {
  uint32_t CBC0                   :1;                                /*!< Cycle-by-Cycle  trip-zone 0 enable
 */
  uint32_t CBC1                   :1;                                /*!< Cycle-by-Cycle  trip-zone 1 enable
 */
  uint32_t CBC2                   :1;                                /*!< Cycle-by-Cycle  trip-zone 2 enable
 */
  uint32_t CBC3                   :1;                                /*!< Cycle-by-Cycle  trip-zone 3 enable
 */
  uint32_t CBC4                   :1;                                /*!< Cycle-by-Cycle  trip-zone 4 enable
 */
  uint32_t CBC5                   :1;                                /*!< Cycle-by-Cycle  trip-zone 5 enable
 */
  uint32_t                        :2;                                /*!< RESERVED */
  uint32_t OSHT0                  :1;                                /*!< One-Shot trip-zone 0 enable */
  uint32_t OSHT1                  :1;                                /*!< One-Shot trip-zone 1 enable */
  uint32_t OSHT2                  :1;                                /*!< One-Shot trip-zone 2 enable */
  uint32_t OSHT3                  :1;                                /*!< One-Shot trip-zone 3 enable */
  uint32_t OSHT4                  :1;                                /*!< One-Shot trip-zone 4 enable */
  uint32_t OSHT5                  :1;                                /*!< One-Shot trip-zone 5 enable */
} _PWM_TZSEL_bits;

/* Bit field positions: */
#define PWM_TZSEL_CBC0_Pos                    0                      /*!< Cycle-by-Cycle  trip-zone 0 enable
 */
#define PWM_TZSEL_CBC1_Pos                    1                      /*!< Cycle-by-Cycle  trip-zone 1 enable
 */
#define PWM_TZSEL_CBC2_Pos                    2                      /*!< Cycle-by-Cycle  trip-zone 2 enable
 */
#define PWM_TZSEL_CBC3_Pos                    3                      /*!< Cycle-by-Cycle  trip-zone 3 enable
 */
#define PWM_TZSEL_CBC4_Pos                    4                      /*!< Cycle-by-Cycle  trip-zone 4 enable
 */
#define PWM_TZSEL_CBC5_Pos                    5                      /*!< Cycle-by-Cycle  trip-zone 5 enable
 */
#define PWM_TZSEL_OSHT0_Pos                   8                      /*!< One-Shot trip-zone 0 enable */
#define PWM_TZSEL_OSHT1_Pos                   9                      /*!< One-Shot trip-zone 1 enable */
#define PWM_TZSEL_OSHT2_Pos                   10                     /*!< One-Shot trip-zone 2 enable */
#define PWM_TZSEL_OSHT3_Pos                   11                     /*!< One-Shot trip-zone 3 enable */
#define PWM_TZSEL_OSHT4_Pos                   12                     /*!< One-Shot trip-zone 4 enable */
#define PWM_TZSEL_OSHT5_Pos                   13                     /*!< One-Shot trip-zone 5 enable */

/* Bit field masks: */
#define PWM_TZSEL_CBC0_Msk                    0x00000001             /*!< Cycle-by-Cycle  trip-zone 0 enable
 */
#define PWM_TZSEL_CBC1_Msk                    0x00000002             /*!< Cycle-by-Cycle  trip-zone 1 enable
 */
#define PWM_TZSEL_CBC2_Msk                    0x00000004             /*!< Cycle-by-Cycle  trip-zone 2 enable
 */
#define PWM_TZSEL_CBC3_Msk                    0x00000008             /*!< Cycle-by-Cycle  trip-zone 3 enable
 */
#define PWM_TZSEL_CBC4_Msk                    0x00000010             /*!< Cycle-by-Cycle  trip-zone 4 enable
 */
#define PWM_TZSEL_CBC5_Msk                    0x00000020             /*!< Cycle-by-Cycle  trip-zone 5 enable
 */
#define PWM_TZSEL_OSHT0_Msk                   0x00000100             /*!< One-Shot trip-zone 0 enable */
#define PWM_TZSEL_OSHT1_Msk                   0x00000200             /*!< One-Shot trip-zone 1 enable */
#define PWM_TZSEL_OSHT2_Msk                   0x00000400             /*!< One-Shot trip-zone 2 enable */
#define PWM_TZSEL_OSHT3_Msk                   0x00000800             /*!< One-Shot trip-zone 3 enable */
#define PWM_TZSEL_OSHT4_Msk                   0x00001000             /*!< One-Shot trip-zone 4 enable */
#define PWM_TZSEL_OSHT5_Msk                   0x00002000             /*!< One-Shot trip-zone 5 enable */

/*--  TZCTL: Trip-Zone Control Register -----------------------------------------------------------------------*/
typedef struct {
  uint32_t TZA                    :2;                                /*!< When a trip event occurs the following action is taken on output A */
  uint32_t TZB                    :2;                                /*!< When a trip event occurs the following action is taken on output B */
} _PWM_TZCTL_bits;

/* Bit field positions: */
#define PWM_TZCTL_TZA_Pos                     0                      /*!< When a trip event occurs the following action is taken on output A */
#define PWM_TZCTL_TZB_Pos                     2                      /*!< When a trip event occurs the following action is taken on output B */

/* Bit field masks: */
#define PWM_TZCTL_TZA_Msk                     0x00000003             /*!< When a trip event occurs the following action is taken on output A */
#define PWM_TZCTL_TZB_Msk                     0x0000000C             /*!< When a trip event occurs the following action is taken on output B */

/* Bit field enums: */
typedef enum {
  PWM_TZCTL_TZA_Z                            = 0x0,                  /*!< PWMA/PWMB go to Z on failture */
  PWM_TZCTL_TZA_Set                          = 0x1,                  /*!< PWMA/PWMB go to 1 on failture */
  PWM_TZCTL_TZA_Clear                        = 0x2,                  /*!< PWMA/PWMB go to 0 on failture */
  PWM_TZCTL_TZA_NoAction                     = 0x3,                  /*!< no action on failture */
} PWM_TZCTL_TZA_Enum;

typedef enum {
  PWM_TZCTL_TZB_Z                            = 0x0,                  /*!< PWMA/PWMB go to Z on failture */
  PWM_TZCTL_TZB_Set                          = 0x1,                  /*!< PWMA/PWMB go to 1 on failture */
  PWM_TZCTL_TZB_Clear                        = 0x2,                  /*!< PWMA/PWMB go to 0 on failture */
  PWM_TZCTL_TZB_NoAction                     = 0x3,                  /*!< no action on failture */
} PWM_TZCTL_TZB_Enum;

/*--  TZEINT: Trip-Zone Enable Interrupt Register -------------------------------------------------------------*/
typedef struct {
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t CBC                    :1;                                /*!< Trip-zone Cycle-by-Cycle interrupt enable */
  uint32_t OST                    :1;                                /*!< Trip-zone One-Shot interrupt enable */
} _PWM_TZEINT_bits;

/* Bit field positions: */
#define PWM_TZEINT_CBC_Pos                    1                      /*!< Trip-zone Cycle-by-Cycle interrupt enable */
#define PWM_TZEINT_OST_Pos                    2                      /*!< Trip-zone One-Shot interrupt enable */

/* Bit field masks: */
#define PWM_TZEINT_CBC_Msk                    0x00000002             /*!< Trip-zone Cycle-by-Cycle interrupt enable */
#define PWM_TZEINT_OST_Msk                    0x00000004             /*!< Trip-zone One-Shot interrupt enable */

/*--  TZFLG: Trip-Zone Flag Register --------------------------------------------------------------------------*/
typedef struct {
  uint32_t TZINT                  :1;                                /*!< Latched trip interrupt status flag */
  uint32_t CBC                    :1;                                /*!< Latched status flag for Cycle-By-Cycle trip event */
  uint32_t OST                    :1;                                /*!< Latched status flag for a One-Shot trip event */
} _PWM_TZFLG_bits;

/* Bit field positions: */
#define PWM_TZFLG_TZINT_Pos                   0                      /*!< Latched trip interrupt status flag */
#define PWM_TZFLG_CBC_Pos                     1                      /*!< Latched status flag for Cycle-By-Cycle trip event */
#define PWM_TZFLG_OST_Pos                     2                      /*!< Latched status flag for a One-Shot trip event */

/* Bit field masks: */
#define PWM_TZFLG_TZINT_Msk                   0x00000001             /*!< Latched trip interrupt status flag */
#define PWM_TZFLG_CBC_Msk                     0x00000002             /*!< Latched status flag for Cycle-By-Cycle trip event */
#define PWM_TZFLG_OST_Msk                     0x00000004             /*!< Latched status flag for a One-Shot trip event */

/*--  TZCLR: Trip-Zone Clear Register -------------------------------------------------------------------------*/
typedef struct {
  uint32_t TZINT                  :1;                                /*!< Clear trip-zone interrupt flag */
  uint32_t CBC                    :1;                                /*!< Clear flag for Cycle-By-Cycle trip latch
 */
  uint32_t OST                    :1;                                /*!< Clear flag for One-Shot trip latch */
} _PWM_TZCLR_bits;

/* Bit field positions: */
#define PWM_TZCLR_TZINT_Pos                   0                      /*!< Clear trip-zone interrupt flag */
#define PWM_TZCLR_CBC_Pos                     1                      /*!< Clear flag for Cycle-By-Cycle trip latch
 */
#define PWM_TZCLR_OST_Pos                     2                      /*!< Clear flag for One-Shot trip latch */

/* Bit field masks: */
#define PWM_TZCLR_TZINT_Msk                   0x00000001             /*!< Clear trip-zone interrupt flag */
#define PWM_TZCLR_CBC_Msk                     0x00000002             /*!< Clear flag for Cycle-By-Cycle trip latch
 */
#define PWM_TZCLR_OST_Msk                     0x00000004             /*!< Clear flag for One-Shot trip latch */

/*--  TZFRC: Trip-Zone Force Register -------------------------------------------------------------------------*/
typedef struct {
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t CBC                    :1;                                /*!< Force a Cycle-by-Cycle trip event via software */
  uint32_t OST                    :1;                                /*!< Force a One-Shot trip event via software */
} _PWM_TZFRC_bits;

/* Bit field positions: */
#define PWM_TZFRC_CBC_Pos                     1                      /*!< Force a Cycle-by-Cycle trip event via software */
#define PWM_TZFRC_OST_Pos                     2                      /*!< Force a One-Shot trip event via software */

/* Bit field masks: */
#define PWM_TZFRC_CBC_Msk                     0x00000002             /*!< Force a Cycle-by-Cycle trip event via software */
#define PWM_TZFRC_OST_Msk                     0x00000004             /*!< Force a One-Shot trip event via software */

/*--  ETSEL: Event-Trigger Selection Register -----------------------------------------------------------------*/
typedef struct {
  uint32_t INTSEL                 :3;                                /*!< PWM_INT interrupt selection options */
  uint32_t INTEN                  :1;                                /*!< Enable PWM_INT interrupt generation */
  uint32_t                        :4;                                /*!< RESERVED */
  uint32_t SOCASEL                :3;                                /*!< PWM_SOCA selection Options */
  uint32_t SOCAEN                 :1;                                /*!< Enable the ADC start of conversion A PWM_SOCA pulse */
  uint32_t SOCBSEL                :3;                                /*!< PWM_SOCB selection Options */
  uint32_t SOCBEN                 :1;                                /*!< Enable the ADC start of conversion B PWM_SOCB pulse */
  uint32_t DRQASEL                :3;                                /*!< PWM A DMA request event selection */
  uint32_t DRQAEN                 :1;                                /*!< Enable the DMA request from PWM A */
  uint32_t DRQBSEL                :3;                                /*!< PWM B DMA request event selection */
  uint32_t DRQBEN                 :1;                                /*!< Enable the DMA request from PWM B */
} _PWM_ETSEL_bits;

/* Bit field positions: */
#define PWM_ETSEL_INTSEL_Pos                  0                      /*!< PWM_INT interrupt selection options */
#define PWM_ETSEL_INTEN_Pos                   3                      /*!< Enable PWM_INT interrupt generation */
#define PWM_ETSEL_SOCASEL_Pos                 8                      /*!< PWM_SOCA selection Options */
#define PWM_ETSEL_SOCAEN_Pos                  11                     /*!< Enable the ADC start of conversion A PWM_SOCA pulse */
#define PWM_ETSEL_SOCBSEL_Pos                 12                     /*!< PWM_SOCB selection Options */
#define PWM_ETSEL_SOCBEN_Pos                  15                     /*!< Enable the ADC start of conversion B PWM_SOCB pulse */
#define PWM_ETSEL_DRQASEL_Pos                 16                     /*!< PWM A DMA request event selection */
#define PWM_ETSEL_DRQAEN_Pos                  19                     /*!< Enable the DMA request from PWM A */
#define PWM_ETSEL_DRQBSEL_Pos                 20                     /*!< PWM B DMA request event selection */
#define PWM_ETSEL_DRQBEN_Pos                  23                     /*!< Enable the DMA request from PWM B */

/* Bit field masks: */
#define PWM_ETSEL_INTSEL_Msk                  0x00000007             /*!< PWM_INT interrupt selection options */
#define PWM_ETSEL_INTEN_Msk                   0x00000008             /*!< Enable PWM_INT interrupt generation */
#define PWM_ETSEL_SOCASEL_Msk                 0x00000700             /*!< PWM_SOCA selection Options */
#define PWM_ETSEL_SOCAEN_Msk                  0x00000800             /*!< Enable the ADC start of conversion A PWM_SOCA pulse */
#define PWM_ETSEL_SOCBSEL_Msk                 0x00007000             /*!< PWM_SOCB selection Options */
#define PWM_ETSEL_SOCBEN_Msk                  0x00008000             /*!< Enable the ADC start of conversion B PWM_SOCB pulse */
#define PWM_ETSEL_DRQASEL_Msk                 0x00070000             /*!< PWM A DMA request event selection */
#define PWM_ETSEL_DRQAEN_Msk                  0x00080000             /*!< Enable the DMA request from PWM A */
#define PWM_ETSEL_DRQBSEL_Msk                 0x00700000             /*!< PWM B DMA request event selection */
#define PWM_ETSEL_DRQBEN_Msk                  0x00800000             /*!< Enable the DMA request from PWM B */

/* Bit field enums: */
typedef enum {
  PWM_ETSEL_INTSEL_CTREqZero                 = 0x1,                  /*!<  generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = 0 */
  PWM_ETSEL_INTSEL_CTREqPRD                  = 0x2,                  /*!<  generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = PRD */
  PWM_ETSEL_INTSEL_CTREqCMPA_OnUp            = 0x4,                  /*!<  generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = CMPA when count up */
  PWM_ETSEL_INTSEL_CTREqCMPA_OnDown          = 0x5,                  /*!<  generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = CMPA when count down */
  PWM_ETSEL_INTSEL_CTREqCMPB_OnUp            = 0x6,                  /*!<  generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = CMPB when count up */
  PWM_ETSEL_INTSEL_CTREqCMPB_OnDown          = 0x7,                  /*!<  generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = CMPB when count down */
} PWM_ETSEL_INTSEL_Enum;

typedef enum {
  PWM_ETSEL_SOCASEL_CTREqZero                = 0x1,                  /*!<  generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = 0 */
  PWM_ETSEL_SOCASEL_CTREqPRD                 = 0x2,                  /*!<  generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = PRD */
  PWM_ETSEL_SOCASEL_CTREqCMPA_OnUp           = 0x4,                  /*!<  generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = CMPA when count up */
  PWM_ETSEL_SOCASEL_CTREqCMPA_OnDown         = 0x5,                  /*!<  generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = CMPA when count down */
  PWM_ETSEL_SOCASEL_CTREqCMPB_OnUp           = 0x6,                  /*!<  generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = CMPB when count up */
  PWM_ETSEL_SOCASEL_CTREqCMPB_OnDown         = 0x7,                  /*!<  generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = CMPB when count down */
} PWM_ETSEL_SOCASEL_Enum;

typedef enum {
  PWM_ETSEL_SOCBSEL_CTREqZero                = 0x1,                  /*!<  generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = 0 */
  PWM_ETSEL_SOCBSEL_CTREqPRD                 = 0x2,                  /*!<  generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = PRD */
  PWM_ETSEL_SOCBSEL_CTREqCMPA_OnUp           = 0x4,                  /*!<  generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = CMPA when count up */
  PWM_ETSEL_SOCBSEL_CTREqCMPA_OnDown         = 0x5,                  /*!<  generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = CMPA when count down */
  PWM_ETSEL_SOCBSEL_CTREqCMPB_OnUp           = 0x6,                  /*!<  generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = CMPB when count up */
  PWM_ETSEL_SOCBSEL_CTREqCMPB_OnDown         = 0x7,                  /*!<  generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = CMPB when count down */
} PWM_ETSEL_SOCBSEL_Enum;

typedef enum {
  PWM_ETSEL_DRQASEL_CTREqZero                = 0x1,                  /*!<  generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = 0 */
  PWM_ETSEL_DRQASEL_CTREqPRD                 = 0x2,                  /*!<  generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = PRD */
  PWM_ETSEL_DRQASEL_CTREqCMPA_OnUp           = 0x4,                  /*!<  generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = CMPA when count up */
  PWM_ETSEL_DRQASEL_CTREqCMPA_OnDown         = 0x5,                  /*!<  generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = CMPA when count down */
  PWM_ETSEL_DRQASEL_CTREqCMPB_OnUp           = 0x6,                  /*!<  generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = CMPB when count up */
  PWM_ETSEL_DRQASEL_CTREqCMPB_OnDown         = 0x7,                  /*!<  generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = CMPB when count down */
} PWM_ETSEL_DRQASEL_Enum;

typedef enum {
  PWM_ETSEL_DRQBSEL_CTREqZero                = 0x1,                  /*!<  generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = 0 */
  PWM_ETSEL_DRQBSEL_CTREqPRD                 = 0x2,                  /*!<  generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = PRD */
  PWM_ETSEL_DRQBSEL_CTREqCMPA_OnUp           = 0x4,                  /*!<  generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = CMPA when count up */
  PWM_ETSEL_DRQBSEL_CTREqCMPA_OnDown         = 0x5,                  /*!<  generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = CMPA when count down */
  PWM_ETSEL_DRQBSEL_CTREqCMPB_OnUp           = 0x6,                  /*!<  generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = CMPB when count up */
  PWM_ETSEL_DRQBSEL_CTREqCMPB_OnDown         = 0x7,                  /*!<  generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = CMPB when count down */
} PWM_ETSEL_DRQBSEL_Enum;

/*--  ETPS: Event-Trigger Prescale Register -------------------------------------------------------------------*/
typedef struct {
  uint32_t INTPRD                 :2;                                /*!< PWM interrupt (PWM_INT) period select */
  uint32_t INTCNT                 :2;                                /*!< PWM interrupt event (PWM_INT) counter register */
  uint32_t                        :4;                                /*!< RESERVED */
  uint32_t SOCAPRD                :2;                                /*!< PWM ADC Start-of-Conversion A event (PWM_SOCA) period select */
  uint32_t SOCACNT                :2;                                /*!< PWM ADC Start-of-Conversion A event (PWM_SOCA) counter register */
  uint32_t SOCBPRD                :2;                                /*!< PWM ADC Start-of-Conversion B event (PWM_SOCB) period select */
  uint32_t SOCBCNT                :2;                                /*!< PWM ADC Start-of-Conversion B event (PWM_SOCB) counter register */
  uint32_t DRQAPRD                :2;                                /*!< PWM DMA request A period select */
  uint32_t DRQACNT                :2;                                /*!< PWM DMA request event A counter */
  uint32_t DRQBPRD                :2;                                /*!< PWM DMA request B period select */
  uint32_t DRQBCNT                :2;                                /*!< PWM DMA request event B counter */
} _PWM_ETPS_bits;

/* Bit field positions: */
#define PWM_ETPS_INTPRD_Pos                   0                      /*!< PWM interrupt (PWM_INT) period select */
#define PWM_ETPS_INTCNT_Pos                   2                      /*!< PWM interrupt event (PWM_INT) counter register */
#define PWM_ETPS_SOCAPRD_Pos                  8                      /*!< PWM ADC Start-of-Conversion A event (PWM_SOCA) period select */
#define PWM_ETPS_SOCACNT_Pos                  10                     /*!< PWM ADC Start-of-Conversion A event (PWM_SOCA) counter register */
#define PWM_ETPS_SOCBPRD_Pos                  12                     /*!< PWM ADC Start-of-Conversion B event (PWM_SOCB) period select */
#define PWM_ETPS_SOCBCNT_Pos                  14                     /*!< PWM ADC Start-of-Conversion B event (PWM_SOCB) counter register */
#define PWM_ETPS_DRQAPRD_Pos                  16                     /*!< PWM DMA request A period select */
#define PWM_ETPS_DRQACNT_Pos                  18                     /*!< PWM DMA request event A counter */
#define PWM_ETPS_DRQBPRD_Pos                  20                     /*!< PWM DMA request B period select */
#define PWM_ETPS_DRQBCNT_Pos                  22                     /*!< PWM DMA request event B counter */

/* Bit field masks: */
#define PWM_ETPS_INTPRD_Msk                   0x00000003             /*!< PWM interrupt (PWM_INT) period select */
#define PWM_ETPS_INTCNT_Msk                   0x0000000C             /*!< PWM interrupt event (PWM_INT) counter register */
#define PWM_ETPS_SOCAPRD_Msk                  0x00000300             /*!< PWM ADC Start-of-Conversion A event (PWM_SOCA) period select */
#define PWM_ETPS_SOCACNT_Msk                  0x00000C00             /*!< PWM ADC Start-of-Conversion A event (PWM_SOCA) counter register */
#define PWM_ETPS_SOCBPRD_Msk                  0x00003000             /*!< PWM ADC Start-of-Conversion B event (PWM_SOCB) period select */
#define PWM_ETPS_SOCBCNT_Msk                  0x0000C000             /*!< PWM ADC Start-of-Conversion B event (PWM_SOCB) counter register */
#define PWM_ETPS_DRQAPRD_Msk                  0x00030000             /*!< PWM DMA request A period select */
#define PWM_ETPS_DRQACNT_Msk                  0x000C0000             /*!< PWM DMA request event A counter */
#define PWM_ETPS_DRQBPRD_Msk                  0x00300000             /*!< PWM DMA request B period select */
#define PWM_ETPS_DRQBCNT_Msk                  0x00C00000             /*!< PWM DMA request event B counter */

/*--  ETFLG: Event-Trigger Flag Register ----------------------------------------------------------------------*/
typedef struct {
  uint32_t INT                    :1;                                /*!< Latched PWM Interrupt (PWM_INT) status flag */
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t SOCA                   :1;                                /*!< Latched PWM ADC Start-of-Conversion A (PWM_SOCA) status flag */
  uint32_t SOCB                   :1;                                /*!< Latched PWM ADC Start-of-Conversion B (PWM_SOCB) status flag */
  uint32_t DRQA                   :1;                                /*!< Latched PWM DMA request A status flag */
  uint32_t DRQB                   :1;                                /*!< Latched PWM DMA request B status flag */
} _PWM_ETFLG_bits;

/* Bit field positions: */
#define PWM_ETFLG_INT_Pos                     0                      /*!< Latched PWM Interrupt (PWM_INT) status flag */
#define PWM_ETFLG_SOCA_Pos                    2                      /*!< Latched PWM ADC Start-of-Conversion A (PWM_SOCA) status flag */
#define PWM_ETFLG_SOCB_Pos                    3                      /*!< Latched PWM ADC Start-of-Conversion B (PWM_SOCB) status flag */
#define PWM_ETFLG_DRQA_Pos                    4                      /*!< Latched PWM DMA request A status flag */
#define PWM_ETFLG_DRQB_Pos                    5                      /*!< Latched PWM DMA request B status flag */

/* Bit field masks: */
#define PWM_ETFLG_INT_Msk                     0x00000001             /*!< Latched PWM Interrupt (PWM_INT) status flag */
#define PWM_ETFLG_SOCA_Msk                    0x00000004             /*!< Latched PWM ADC Start-of-Conversion A (PWM_SOCA) status flag */
#define PWM_ETFLG_SOCB_Msk                    0x00000008             /*!< Latched PWM ADC Start-of-Conversion B (PWM_SOCB) status flag */
#define PWM_ETFLG_DRQA_Msk                    0x00000010             /*!< Latched PWM DMA request A status flag */
#define PWM_ETFLG_DRQB_Msk                    0x00000020             /*!< Latched PWM DMA request B status flag */

/*--  ETCLR: Event-Trigger Clear Register ---------------------------------------------------------------------*/
typedef struct {
  uint32_t INT                    :1;                                /*!< Latched PWM Interrupt (PWM_INT) flag clear bit */
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t SOCA                   :1;                                /*!< Latched PWM ADC Start-of-Conversion A (PWM_SOCA) flag clear bit */
  uint32_t SOCB                   :1;                                /*!< Latched PWM ADC Start-of-Conversion B (PWM_SOCB) flag clear bit */
  uint32_t DRQA                   :1;                                /*!< Latched PWM DMA request A flag clear bit */
  uint32_t DRQB                   :1;                                /*!< Latched PWM DMA request B flag clear bit */
} _PWM_ETCLR_bits;

/* Bit field positions: */
#define PWM_ETCLR_INT_Pos                     0                      /*!< Latched PWM Interrupt (PWM_INT) flag clear bit */
#define PWM_ETCLR_SOCA_Pos                    2                      /*!< Latched PWM ADC Start-of-Conversion A (PWM_SOCA) flag clear bit */
#define PWM_ETCLR_SOCB_Pos                    3                      /*!< Latched PWM ADC Start-of-Conversion B (PWM_SOCB) flag clear bit */
#define PWM_ETCLR_DRQA_Pos                    4                      /*!< Latched PWM DMA request A flag clear bit */
#define PWM_ETCLR_DRQB_Pos                    5                      /*!< Latched PWM DMA request B flag clear bit */

/* Bit field masks: */
#define PWM_ETCLR_INT_Msk                     0x00000001             /*!< Latched PWM Interrupt (PWM_INT) flag clear bit */
#define PWM_ETCLR_SOCA_Msk                    0x00000004             /*!< Latched PWM ADC Start-of-Conversion A (PWM_SOCA) flag clear bit */
#define PWM_ETCLR_SOCB_Msk                    0x00000008             /*!< Latched PWM ADC Start-of-Conversion B (PWM_SOCB) flag clear bit */
#define PWM_ETCLR_DRQA_Msk                    0x00000010             /*!< Latched PWM DMA request A flag clear bit */
#define PWM_ETCLR_DRQB_Msk                    0x00000020             /*!< Latched PWM DMA request B flag clear bit */

/*--  ETFRC: Event-Trigger Force Register ---------------------------------------------------------------------*/
typedef struct {
  uint32_t INT                    :1;                                /*!< PWM_INT force bit. */
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t SOCA                   :1;                                /*!< PWM_SOCA force bit */
  uint32_t SOCB                   :1;                                /*!< PWM_SOCB force bit */
  uint32_t DRQA                   :1;                                /*!< PWM DMA request A force bit */
  uint32_t DRQB                   :1;                                /*!< PWM DMA request B force bit */
} _PWM_ETFRC_bits;

/* Bit field positions: */
#define PWM_ETFRC_INT_Pos                     0                      /*!< PWM_INT force bit. */
#define PWM_ETFRC_SOCA_Pos                    2                      /*!< PWM_SOCA force bit */
#define PWM_ETFRC_SOCB_Pos                    3                      /*!< PWM_SOCB force bit */
#define PWM_ETFRC_DRQA_Pos                    4                      /*!< PWM DMA request A force bit */
#define PWM_ETFRC_DRQB_Pos                    5                      /*!< PWM DMA request B force bit */

/* Bit field masks: */
#define PWM_ETFRC_INT_Msk                     0x00000001             /*!< PWM_INT force bit. */
#define PWM_ETFRC_SOCA_Msk                    0x00000004             /*!< PWM_SOCA force bit */
#define PWM_ETFRC_SOCB_Msk                    0x00000008             /*!< PWM_SOCB force bit */
#define PWM_ETFRC_DRQA_Msk                    0x00000010             /*!< PWM DMA request A force bit */
#define PWM_ETFRC_DRQB_Msk                    0x00000020             /*!< PWM DMA request B force bit */

/*--  PCCTL: PWM-Chopper Control Register ---------------------------------------------------------------------*/
typedef struct {
  uint32_t CHPEN                  :1;                                /*!< PWM-chopping enable */
  uint32_t OSHTWTH                :4;                                /*!< One-Shot pulse width */
  uint32_t SHRFREQ                :3;                                /*!< Chopping clock frequency */
  uint32_t CHPDUTY                :3;                                /*!< Chopping clock duty cycle */
} _PWM_PCCTL_bits;

/* Bit field positions: */
#define PWM_PCCTL_CHPEN_Pos                   0                      /*!< PWM-chopping enable */
#define PWM_PCCTL_OSHTWTH_Pos                 1                      /*!< One-Shot pulse width */
#define PWM_PCCTL_SHRFREQ_Pos                 5                      /*!< Chopping clock frequency */
#define PWM_PCCTL_CHPDUTY_Pos                 8                      /*!< Chopping clock duty cycle */

/* Bit field masks: */
#define PWM_PCCTL_CHPEN_Msk                   0x00000001             /*!< PWM-chopping enable */
#define PWM_PCCTL_OSHTWTH_Msk                 0x0000001E             /*!< One-Shot pulse width */
#define PWM_PCCTL_SHRFREQ_Msk                 0x000000E0             /*!< Chopping clock frequency */
#define PWM_PCCTL_CHPDUTY_Msk                 0x00000700             /*!< Chopping clock duty cycle */

/* Bit field enums: */
typedef enum {
  PWM_PCCTL_SHRFREQ_Div1                     = 0x0,                  /*!< sync frequency divide by 1 */
  PWM_PCCTL_SHRFREQ_Div2                     = 0x1,                  /*!< sync frequency divide by 2 */
  PWM_PCCTL_SHRFREQ_Div3                     = 0x2,                  /*!< sync frequency divide by 3 */
  PWM_PCCTL_SHRFREQ_Div4                     = 0x3,                  /*!< sync frequency divide by 4 */
  PWM_PCCTL_SHRFREQ_Div5                     = 0x4,                  /*!< sync frequency divide by 5 */
  PWM_PCCTL_SHRFREQ_Div6                     = 0x5,                  /*!< sync frequency divide by 6 */
  PWM_PCCTL_SHRFREQ_Div7                     = 0x6,                  /*!< sync frequency divide by 7 */
  PWM_PCCTL_SHRFREQ_Div8                     = 0x7,                  /*!< sync frequency divide by 8 */
} PWM_PCCTL_SHRFREQ_Enum;

typedef enum {
  PWM_PCCTL_CHPDUTY_Duty_1_8                 = 0x0,                  /*!< duty 1/8 */
  PWM_PCCTL_CHPDUTY_Duty_2_8                 = 0x1,                  /*!< duty 2/8 */
  PWM_PCCTL_CHPDUTY_Duty_3_8                 = 0x2,                  /*!< duty 3/8 */
  PWM_PCCTL_CHPDUTY_Duty_4_8                 = 0x3,                  /*!< duty 4/8 */
  PWM_PCCTL_CHPDUTY_Duty_5_8                 = 0x4,                  /*!< duty 5/8 */
  PWM_PCCTL_CHPDUTY_Duty_6_8                 = 0x5,                  /*!< duty 6/8 */
  PWM_PCCTL_CHPDUTY_Duty_7_8                 = 0x6,                  /*!< duty 7/8 */
} PWM_PCCTL_CHPDUTY_Enum;

/*--  HRCTL: High-Resolution Control Register -----------------------------------------------------------------*/
typedef struct {
  uint32_t EDGMODEA               :2;                                /*!< Edge selecting for delay on chanel A */
  uint32_t CTLMODEA               :1;                                /*!< Register specifies the delay select on chanel A */
  uint32_t HRLOAD                 :1;                                /*!< CMPAHR register shadow load mode */
  uint32_t EDGMODEB               :2;                                /*!< Edge selecting for delay on chanel B */
  uint32_t CTLMODEB               :1;                                /*!< Register specifies the delay select on chanel B */
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t DELAYCALA              :2;                                /*!< Delay calibration flags of chanel A */
  uint32_t DELAYCALB              :2;                                /*!< Delay calibration flags of chanel B */
} _PWM_HRCTL_bits;

/* Bit field positions: */
#define PWM_HRCTL_EDGMODEA_Pos                0                      /*!< Edge selecting for delay on chanel A */
#define PWM_HRCTL_CTLMODEA_Pos                2                      /*!< Register specifies the delay select on chanel A */
#define PWM_HRCTL_HRLOAD_Pos                  3                      /*!< CMPAHR register shadow load mode */
#define PWM_HRCTL_EDGMODEB_Pos                4                      /*!< Edge selecting for delay on chanel B */
#define PWM_HRCTL_CTLMODEB_Pos                6                      /*!< Register specifies the delay select on chanel B */
#define PWM_HRCTL_DELAYCALA_Pos               8                      /*!< Delay calibration flags of chanel A */
#define PWM_HRCTL_DELAYCALB_Pos               10                     /*!< Delay calibration flags of chanel B */

/* Bit field masks: */
#define PWM_HRCTL_EDGMODEA_Msk                0x00000003             /*!< Edge selecting for delay on chanel A */
#define PWM_HRCTL_CTLMODEA_Msk                0x00000004             /*!< Register specifies the delay select on chanel A */
#define PWM_HRCTL_HRLOAD_Msk                  0x00000008             /*!< CMPAHR register shadow load mode */
#define PWM_HRCTL_EDGMODEB_Msk                0x00000030             /*!< Edge selecting for delay on chanel B */
#define PWM_HRCTL_CTLMODEB_Msk                0x00000040             /*!< Register specifies the delay select on chanel B */
#define PWM_HRCTL_DELAYCALA_Msk               0x00000300             /*!< Delay calibration flags of chanel A */
#define PWM_HRCTL_DELAYCALB_Msk               0x00000C00             /*!< Delay calibration flags of chanel B */

/* Bit field enums: */
typedef enum {
  PWM_HRCTL_EDGMODEA_PosEdge                 = 0x1,                  /*!< posedge will be delayed */
  PWM_HRCTL_EDGMODEA_NegEdge                 = 0x2,                  /*!< negedge will be delayed */
  PWM_HRCTL_EDGMODEA_PosNeg                  = 0x1,                  /*!< posedge and negedge will be delayed */
} PWM_HRCTL_EDGMODEA_Enum;

typedef enum {
  PWM_HRCTL_EDGMODEB_PosEdge                 = 0x1,                  /*!< posedge will be delayed */
  PWM_HRCTL_EDGMODEB_NegEdge                 = 0x2,                  /*!< negedge will be delayed */
  PWM_HRCTL_EDGMODEB_PosNeg                  = 0x1,                  /*!< posedge and negedge will be delayed */
} PWM_HRCTL_EDGMODEB_Enum;

/*--  FWDTH: Filter Width select Register ---------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :8;                                /*!< Pulse filter width selection */
} _PWM_FWDTH_bits;

/* Bit field positions: */
#define PWM_FWDTH_VAL_Pos                     0                      /*!< Pulse filter width selection */

/* Bit field masks: */
#define PWM_FWDTH_VAL_Msk                     0x000000FF             /*!< Pulse filter width selection */

/*--  HDSEL: Hold Detector event Select Register --------------------------------------------------------------*/
typedef struct {
  uint32_t ADCDC0                 :1;                                /*!< Hold detector event by ADC Digital Comparator 0 enable */
  uint32_t ADCDC1                 :1;                                /*!< Hold detector event by ADC Digital Comparator 1 enable */
  uint32_t ADCDC2                 :1;                                /*!< Hold detector event by ADC Digital Comparator 2 enable */
  uint32_t ADCDC3                 :1;                                /*!< Hold detector event by ADC Digital Comparator 3 enable */
  uint32_t                        :24;                               /*!< RESERVED */
  uint32_t CBC                    :1;                                /*!< Cycle-by-Cycle hold detector enable */
  uint32_t                        :2;                                /*!< RESERVED */
  uint32_t OST                    :1;                                /*!< One-Shot hold detector enable */
} _PWM_HDSEL_bits;

/* Bit field positions: */
#define PWM_HDSEL_ADCDC0_Pos                  0                      /*!< Hold detector event by ADC Digital Comparator 0 enable */
#define PWM_HDSEL_ADCDC1_Pos                  1                      /*!< Hold detector event by ADC Digital Comparator 1 enable */
#define PWM_HDSEL_ADCDC2_Pos                  2                      /*!< Hold detector event by ADC Digital Comparator 2 enable */
#define PWM_HDSEL_ADCDC3_Pos                  3                      /*!< Hold detector event by ADC Digital Comparator 3 enable */
#define PWM_HDSEL_CBC_Pos                     28                     /*!< Cycle-by-Cycle hold detector enable */
#define PWM_HDSEL_OST_Pos                     31                     /*!< One-Shot hold detector enable */

/* Bit field masks: */
#define PWM_HDSEL_ADCDC0_Msk                  0x00000001             /*!< Hold detector event by ADC Digital Comparator 0 enable */
#define PWM_HDSEL_ADCDC1_Msk                  0x00000002             /*!< Hold detector event by ADC Digital Comparator 1 enable */
#define PWM_HDSEL_ADCDC2_Msk                  0x00000004             /*!< Hold detector event by ADC Digital Comparator 2 enable */
#define PWM_HDSEL_ADCDC3_Msk                  0x00000008             /*!< Hold detector event by ADC Digital Comparator 3 enable */
#define PWM_HDSEL_CBC_Msk                     0x10000000             /*!< Cycle-by-Cycle hold detector enable */
#define PWM_HDSEL_OST_Msk                     0x80000000             /*!< One-Shot hold detector enable */

/*--  HDCTL: Hold Detector Control register -------------------------------------------------------------------*/
typedef struct {
  uint32_t HDA                    :2;                                /*!< Action when hold detection A is invoked */
  uint32_t HDB                    :2;                                /*!< Action when hold detection B is invoked */
} _PWM_HDCTL_bits;

/* Bit field positions: */
#define PWM_HDCTL_HDA_Pos                     0                      /*!< Action when hold detection A is invoked */
#define PWM_HDCTL_HDB_Pos                     2                      /*!< Action when hold detection B is invoked */

/* Bit field masks: */
#define PWM_HDCTL_HDA_Msk                     0x00000003             /*!< Action when hold detection A is invoked */
#define PWM_HDCTL_HDB_Msk                     0x0000000C             /*!< Action when hold detection B is invoked */

/* Bit field enums: */
typedef enum {
  PWM_HDCTL_HDA_Set                          = 0x1,                  /*!< PWMA/PWMB go to 1 on failture */
  PWM_HDCTL_HDA_Clear                        = 0x2,                  /*!< PWMA/PWMB go to 0 on failture */
  PWM_HDCTL_HDA_NoAction                     = 0x3,                  /*!< no action on failture */
} PWM_HDCTL_HDA_Enum;

typedef enum {
  PWM_HDCTL_HDB_Set                          = 0x1,                  /*!< PWMA/PWMB go to 1 on failture */
  PWM_HDCTL_HDB_Clear                        = 0x2,                  /*!< PWMA/PWMB go to 0 on failture */
  PWM_HDCTL_HDB_NoAction                     = 0x3,                  /*!< no action on failture */
} PWM_HDCTL_HDB_Enum;

/*--  HDEINT: Hold Detector Enable Interrupt Register ---------------------------------------------------------*/
typedef struct {
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t CBC                    :1;                                /*!< Hold detector Cycle-by-Cycle interrupt enable */
  uint32_t OST                    :1;                                /*!< Hold detector One-Shot interrupt enable */
} _PWM_HDEINT_bits;

/* Bit field positions: */
#define PWM_HDEINT_CBC_Pos                    1                      /*!< Hold detector Cycle-by-Cycle interrupt enable */
#define PWM_HDEINT_OST_Pos                    2                      /*!< Hold detector One-Shot interrupt enable */

/* Bit field masks: */
#define PWM_HDEINT_CBC_Msk                    0x00000002             /*!< Hold detector Cycle-by-Cycle interrupt enable */
#define PWM_HDEINT_OST_Msk                    0x00000004             /*!< Hold detector One-Shot interrupt enable */

/*--  HDFLG: Hold Detector Flag Register ----------------------------------------------------------------------*/
typedef struct {
  uint32_t HDINT                  :1;                                /*!< Latched hold detector interrupt status flag */
  uint32_t CBC                    :1;                                /*!< Latched status flag for hold detector Cycle-by-Cycle event */
  uint32_t OST                    :1;                                /*!< Latched status flag for hold detector One-Shot event */
} _PWM_HDFLG_bits;

/* Bit field positions: */
#define PWM_HDFLG_HDINT_Pos                   0                      /*!< Latched hold detector interrupt status flag */
#define PWM_HDFLG_CBC_Pos                     1                      /*!< Latched status flag for hold detector Cycle-by-Cycle event */
#define PWM_HDFLG_OST_Pos                     2                      /*!< Latched status flag for hold detector One-Shot event */

/* Bit field masks: */
#define PWM_HDFLG_HDINT_Msk                   0x00000001             /*!< Latched hold detector interrupt status flag */
#define PWM_HDFLG_CBC_Msk                     0x00000002             /*!< Latched status flag for hold detector Cycle-by-Cycle event */
#define PWM_HDFLG_OST_Msk                     0x00000004             /*!< Latched status flag for hold detector One-Shot event */

/*--  HDCLR: Register clear HD flag ---------------------------------------------------------------------------*/
typedef struct {
  uint32_t HDINT                  :1;                                /*!< Clear hold detector interrupt flag */
  uint32_t CBC                    :1;                                /*!< Clear flag for Cycle-By-Cycle hold detector latch
 */
  uint32_t OST                    :1;                                /*!< Clear flag for One-Shot hold detector latch */
} _PWM_HDCLR_bits;

/* Bit field positions: */
#define PWM_HDCLR_HDINT_Pos                   0                      /*!< Clear hold detector interrupt flag */
#define PWM_HDCLR_CBC_Pos                     1                      /*!< Clear flag for Cycle-By-Cycle hold detector latch
 */
#define PWM_HDCLR_OST_Pos                     2                      /*!< Clear flag for One-Shot hold detector latch */

/* Bit field masks: */
#define PWM_HDCLR_HDINT_Msk                   0x00000001             /*!< Clear hold detector interrupt flag */
#define PWM_HDCLR_CBC_Msk                     0x00000002             /*!< Clear flag for Cycle-By-Cycle hold detector latch
 */
#define PWM_HDCLR_OST_Msk                     0x00000004             /*!< Clear flag for One-Shot hold detector latch */

/*--  HDFRC: Hold Detector Force Register ---------------------------------------------------------------------*/
typedef struct {
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t CBC                    :1;                                /*!< Force a Cycle-by-Cycle hold detector event via software */
  uint32_t OST                    :1;                                /*!< Force a One-Shot hold detector event via software */
} _PWM_HDFRC_bits;

/* Bit field positions: */
#define PWM_HDFRC_CBC_Pos                     1                      /*!< Force a Cycle-by-Cycle hold detector event via software */
#define PWM_HDFRC_OST_Pos                     2                      /*!< Force a One-Shot hold detector event via software */

/* Bit field masks: */
#define PWM_HDFRC_CBC_Msk                     0x00000002             /*!< Force a Cycle-by-Cycle hold detector event via software */
#define PWM_HDFRC_OST_Msk                     0x00000004             /*!< Force a One-Shot hold detector event via software */

/*--  HDINTCLR: Hold Detector Interrupt pending Clear Register ------------------------------------------------*/
typedef struct {
  uint32_t HDINT                  :1;                                /*!< Clear HD interrupt pending */
} _PWM_HDINTCLR_bits;

/* Bit field positions: */
#define PWM_HDINTCLR_HDINT_Pos                0                      /*!< Clear HD interrupt pending */

/* Bit field masks: */
#define PWM_HDINTCLR_HDINT_Msk                0x00000001             /*!< Clear HD interrupt pending */

/*--  TZINTCLR: Trip-Zone Interrupt pending Clear Register ----------------------------------------------------*/
typedef struct {
  uint32_t TZINT                  :1;                                /*!< Clear TZ interrupt pending */
} _PWM_TZINTCLR_bits;

/* Bit field positions: */
#define PWM_TZINTCLR_TZINT_Pos                0                      /*!< Clear TZ interrupt pending */

/* Bit field masks: */
#define PWM_TZINTCLR_TZINT_Msk                0x00000001             /*!< Clear TZ interrupt pending */

/*--  INTCLR: PWM Interrupt pending Clear Register ------------------------------------------------------------*/
typedef struct {
  uint32_t INT                    :1;                                /*!< Clear interrupt pending */
} _PWM_INTCLR_bits;

/* Bit field positions: */
#define PWM_INTCLR_INT_Pos                    0                      /*!< Clear interrupt pending */

/* Bit field masks: */
#define PWM_INTCLR_INT_Msk                    0x00000001             /*!< Clear interrupt pending */

typedef struct {
  union {                                                               /*!< Time-Base Control Register */
    __IO uint32_t TBCTL;                                             /*!< TBCTL    : type used for word access */
    __IO _PWM_TBCTL_bits  TBCTL_bit;                                 /*!< TBCTL_bit: structure used for bit access */
  };
  union {                                                               /*!< Time-Base Status Register */
    __IO uint32_t TBSTS;                                             /*!< TBSTS    : type used for word access */
    __IO _PWM_TBSTS_bits  TBSTS_bit;                                 /*!< TBSTS_bit: structure used for bit access */
  };
  union {                                                               /*!< Time-Base Phase Register */
    __IO uint32_t TBPHS;                                             /*!< TBPHS    : type used for word access */
    __IO _PWM_TBPHS_bits  TBPHS_bit;                                 /*!< TBPHS_bit: structure used for bit access */
  };
  union {                                                               /*!< Time-Base Counter Register */
    __IO uint32_t TBCTR;                                             /*!< TBCTR    : type used for word access */
    __IO _PWM_TBCTR_bits  TBCTR_bit;                                 /*!< TBCTR_bit: structure used for bit access */
  };
  union {                                                               /*!< Time-Base Period Register */
    __IO uint32_t TBPRD;                                             /*!< TBPRD    : type used for word access */
    __IO _PWM_TBPRD_bits  TBPRD_bit;                                 /*!< TBPRD_bit: structure used for bit access */
  };
  union {                                                               /*!< Counter-Compare Control Register */
    __IO uint32_t CMPCTL;                                            /*!< CMPCTL    : type used for word access */
    __IO _PWM_CMPCTL_bits  CMPCTL_bit;                               /*!< CMPCTL_bit: structure used for bit access */
  };
  union {                                                               /*!< Counter-Compare A Register */
    __IO uint32_t CMPA;                                              /*!< CMPA    : type used for word access */
    __IO _PWM_CMPA_bits  CMPA_bit;                                   /*!< CMPA_bit: structure used for bit access */
  };
  union {                                                               /*!< Counter-Compare B Register */
    __IO uint32_t CMPB;                                              /*!< CMPB    : type used for word access */
    __IO _PWM_CMPB_bits  CMPB_bit;                                   /*!< CMPB_bit: structure used for bit access */
  };
  union {                                                               /*!< Action-Qualifier Output A Control Register */
    __IO uint32_t AQCTLA;                                            /*!< AQCTLA    : type used for word access */
    __IO _PWM_AQCTLA_bits  AQCTLA_bit;                               /*!< AQCTLA_bit: structure used for bit access */
  };
  union {                                                               /*!< Action-Qualifier Output B Control Register */
    __IO uint32_t AQCTLB;                                            /*!< AQCTLB    : type used for word access */
    __IO _PWM_AQCTLB_bits  AQCTLB_bit;                               /*!< AQCTLB_bit: structure used for bit access */
  };
  union {                                                               /*!< Action-Qualifier Software Force Register */
    __IO uint32_t AQSFRC;                                            /*!< AQSFRC    : type used for word access */
    __IO _PWM_AQSFRC_bits  AQSFRC_bit;                               /*!< AQSFRC_bit: structure used for bit access */
  };
  union {                                                               /*!< Action-Qualifier Continuous Software Force Register */
    __IO uint32_t AQCSFRC;                                           /*!< AQCSFRC    : type used for word access */
    __IO _PWM_AQCSFRC_bits  AQCSFRC_bit;                             /*!< AQCSFRC_bit: structure used for bit access */
  };
  union {                                                               /*!< Dead-Band Generator Control Register */
    __IO uint32_t DBCTL;                                             /*!< DBCTL    : type used for word access */
    __IO _PWM_DBCTL_bits  DBCTL_bit;                                 /*!< DBCTL_bit: structure used for bit access */
  };
  union {                                                               /*!< Dead-Band Generator Rising Edge Delay Register */
    __IO uint32_t DBRED;                                             /*!< DBRED    : type used for word access */
    __IO _PWM_DBRED_bits  DBRED_bit;                                 /*!< DBRED_bit: structure used for bit access */
  };
  union {                                                               /*!< Dead-Band Generator Falling Edge Delay Register */
    __IO uint32_t DBFED;                                             /*!< DBFED    : type used for word access */
    __IO _PWM_DBFED_bits  DBFED_bit;                                 /*!< DBFED_bit: structure used for bit access */
  };
  union {                                                               /*!< Trip-Zone Select Register */
    __IO uint32_t TZSEL;                                             /*!< TZSEL    : type used for word access */
    __IO _PWM_TZSEL_bits  TZSEL_bit;                                 /*!< TZSEL_bit: structure used for bit access */
  };
  union {                                                               /*!< Trip-Zone Control Register */
    __IO uint32_t TZCTL;                                             /*!< TZCTL    : type used for word access */
    __IO _PWM_TZCTL_bits  TZCTL_bit;                                 /*!< TZCTL_bit: structure used for bit access */
  };
  union {                                                               /*!< Trip-Zone Enable Interrupt Register */
    __IO uint32_t TZEINT;                                            /*!< TZEINT    : type used for word access */
    __IO _PWM_TZEINT_bits  TZEINT_bit;                               /*!< TZEINT_bit: structure used for bit access */
  };
  union {                                                               /*!< Trip-Zone Flag Register */
    __I uint32_t TZFLG;                                              /*!< TZFLG    : type used for word access */
    __I _PWM_TZFLG_bits  TZFLG_bit;                                  /*!< TZFLG_bit: structure used for bit access */
  };
  union {                                                               /*!< Trip-Zone Clear Register */
    __IO uint32_t TZCLR;                                             /*!< TZCLR    : type used for word access */
    __IO _PWM_TZCLR_bits  TZCLR_bit;                                 /*!< TZCLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Trip-Zone Force Register */
    __IO uint32_t TZFRC;                                             /*!< TZFRC    : type used for word access */
    __IO _PWM_TZFRC_bits  TZFRC_bit;                                 /*!< TZFRC_bit: structure used for bit access */
  };
  union {                                                               /*!< Event-Trigger Selection Register */
    __IO uint32_t ETSEL;                                             /*!< ETSEL    : type used for word access */
    __IO _PWM_ETSEL_bits  ETSEL_bit;                                 /*!< ETSEL_bit: structure used for bit access */
  };
  union {                                                               /*!< Event-Trigger Prescale Register */
    __IO uint32_t ETPS;                                              /*!< ETPS    : type used for word access */
    __IO _PWM_ETPS_bits  ETPS_bit;                                   /*!< ETPS_bit: structure used for bit access */
  };
  union {                                                               /*!< Event-Trigger Flag Register */
    __I uint32_t ETFLG;                                              /*!< ETFLG    : type used for word access */
    __I _PWM_ETFLG_bits  ETFLG_bit;                                  /*!< ETFLG_bit: structure used for bit access */
  };
  union {                                                               /*!< Event-Trigger Clear Register */
    __IO uint32_t ETCLR;                                             /*!< ETCLR    : type used for word access */
    __IO _PWM_ETCLR_bits  ETCLR_bit;                                 /*!< ETCLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Event-Trigger Force Register */
    __IO uint32_t ETFRC;                                             /*!< ETFRC    : type used for word access */
    __IO _PWM_ETFRC_bits  ETFRC_bit;                                 /*!< ETFRC_bit: structure used for bit access */
  };
  union {                                                               /*!< PWM-Chopper Control Register */
    __IO uint32_t PCCTL;                                             /*!< PCCTL    : type used for word access */
    __IO _PWM_PCCTL_bits  PCCTL_bit;                                 /*!< PCCTL_bit: structure used for bit access */
  };
  union {                                                               /*!< High-Resolution Control Register */
    __IO uint32_t HRCTL;                                             /*!< HRCTL    : type used for word access */
    __IO _PWM_HRCTL_bits  HRCTL_bit;                                 /*!< HRCTL_bit: structure used for bit access */
  };
  union {                                                               /*!< Filter Width select Register */
    __IO uint32_t FWDTH;                                             /*!< FWDTH    : type used for word access */
    __IO _PWM_FWDTH_bits  FWDTH_bit;                                 /*!< FWDTH_bit: structure used for bit access */
  };
    __IO uint32_t Reserved0[5];
  union {                                                               /*!< Hold Detector event Select Register */
    __IO uint32_t HDSEL;                                             /*!< HDSEL    : type used for word access */
    __IO _PWM_HDSEL_bits  HDSEL_bit;                                 /*!< HDSEL_bit: structure used for bit access */
  };
  union {                                                               /*!< Hold Detector Control register */
    __IO uint32_t HDCTL;                                             /*!< HDCTL    : type used for word access */
    __IO _PWM_HDCTL_bits  HDCTL_bit;                                 /*!< HDCTL_bit: structure used for bit access */
  };
  union {                                                               /*!< Hold Detector Enable Interrupt Register */
    __IO uint32_t HDEINT;                                            /*!< HDEINT    : type used for word access */
    __IO _PWM_HDEINT_bits  HDEINT_bit;                               /*!< HDEINT_bit: structure used for bit access */
  };
  union {                                                               /*!< Hold Detector Flag Register */
    __I uint32_t HDFLG;                                              /*!< HDFLG    : type used for word access */
    __I _PWM_HDFLG_bits  HDFLG_bit;                                  /*!< HDFLG_bit: structure used for bit access */
  };
  union {                                                               /*!< Register clear HD flag */
    __IO uint32_t HDCLR;                                             /*!< HDCLR    : type used for word access */
    __IO _PWM_HDCLR_bits  HDCLR_bit;                                 /*!< HDCLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Hold Detector Force Register */
    __IO uint32_t HDFRC;                                             /*!< HDFRC    : type used for word access */
    __IO _PWM_HDFRC_bits  HDFRC_bit;                                 /*!< HDFRC_bit: structure used for bit access */
  };
  union {                                                               /*!< Hold Detector Interrupt pending Clear Register */
    __O uint32_t HDINTCLR;                                           /*!< HDINTCLR    : type used for word access */
    __O _PWM_HDINTCLR_bits  HDINTCLR_bit;                            /*!< HDINTCLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Trip-Zone Interrupt pending Clear Register */
    __O uint32_t TZINTCLR;                                           /*!< TZINTCLR    : type used for word access */
    __O _PWM_TZINTCLR_bits  TZINTCLR_bit;                            /*!< TZINTCLR_bit: structure used for bit access */
  };
  union {                                                               /*!< PWM Interrupt pending Clear Register */
    __O uint32_t INTCLR;                                             /*!< INTCLR    : type used for word access */
    __O _PWM_INTCLR_bits  INTCLR_bit;                                /*!< INTCLR_bit: structure used for bit access */
  };
} PWM_TypeDef;

/******************************************************************************/
/*                         SPI registers                                      */
/******************************************************************************/

/*--  CR0: Control register 0 ---------------------------------------------------------------------------------*/
typedef struct {
  uint32_t DSS                    :4;                                /*!< Size of data */
  uint32_t FRF                    :2;                                /*!< Select protocol */
  uint32_t SPO                    :1;                                /*!< Polarity SSPCLKOUT */
  uint32_t SPH                    :1;                                /*!< Phase SSPCLKOUT */
  uint32_t SCR                    :8;                                /*!< Value divider */
} _SPI_CR0_bits;

/* Bit field positions: */
#define SPI_CR0_DSS_Pos                       0                      /*!< Size of data */
#define SPI_CR0_FRF_Pos                       4                      /*!< Select protocol */
#define SPI_CR0_SPO_Pos                       6                      /*!< Polarity SSPCLKOUT */
#define SPI_CR0_SPH_Pos                       7                      /*!< Phase SSPCLKOUT */
#define SPI_CR0_SCR_Pos                       8                      /*!< Value divider */

/* Bit field masks: */
#define SPI_CR0_DSS_Msk                       0x0000000F             /*!< Size of data */
#define SPI_CR0_FRF_Msk                       0x00000030             /*!< Select protocol */
#define SPI_CR0_SPO_Msk                       0x00000040             /*!< Polarity SSPCLKOUT */
#define SPI_CR0_SPH_Msk                       0x00000080             /*!< Phase SSPCLKOUT */
#define SPI_CR0_SCR_Msk                       0x0000FF00             /*!< Value divider */

/* Bit field enums: */
typedef enum {
  SPI_CR0_DSS_4bit                           = 0x3,                  /*!< data size 4 bit */
  SPI_CR0_DSS_5bit                           = 0x4,                  /*!< data size 5 bit */
  SPI_CR0_DSS_6bit                           = 0x5,                  /*!< data size 6 bit */
  SPI_CR0_DSS_7bit                           = 0x6,                  /*!< data size 7 bit */
  SPI_CR0_DSS_8bit                           = 0x7,                  /*!< data size 8 bit */
  SPI_CR0_DSS_9bit                           = 0x8,                  /*!< data size 9 bit */
  SPI_CR0_DSS_10bit                          = 0x9,                  /*!< data size 10 bit */
  SPI_CR0_DSS_11bit                          = 0xA,                  /*!< data size 11 bit */
  SPI_CR0_DSS_12bit                          = 0xB,                  /*!< data size 12 bit */
  SPI_CR0_DSS_13bit                          = 0xC,                  /*!< data size 13 bit */
  SPI_CR0_DSS_14bit                          = 0xD,                  /*!< data size 14 bit */
  SPI_CR0_DSS_15bit                          = 0xE,                  /*!< data size 15 bit */
  SPI_CR0_DSS_16bit                          = 0xF,                  /*!< data size 16 bit */
} SPI_CR0_DSS_Enum;

typedef enum {
  SPI_CR0_FRF_SPI                            = 0x0,                  /*!< SPI of Motorola */
  SPI_CR0_FRF_SSI                            = 0x1,                  /*!< SSI of Texas Instruments */
  SPI_CR0_FRF_Microwire                      = 0x2,                  /*!< Microwire of National Semiconductor */
} SPI_CR0_FRF_Enum;

/*--  CR1: Control register 1 ---------------------------------------------------------------------------------*/
typedef struct {
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t SSE                    :1;                                /*!< Enable transceiver */
  uint32_t MS                     :1;                                /*!< Select mode */
  uint32_t SOD                    :1;                                /*!< Disable bit data */
  uint32_t                        :4;                                /*!< RESERVED */
  uint32_t RXIFLSEL               :4;                                /*!< Receive interrupt FIFO level select */
  uint32_t TXIFLSEL               :4;                                /*!< Transmit interrupt FIFO level select */
} _SPI_CR1_bits;

/* Bit field positions: */
#define SPI_CR1_SSE_Pos                       1                      /*!< Enable transceiver */
#define SPI_CR1_MS_Pos                        2                      /*!< Select mode */
#define SPI_CR1_SOD_Pos                       3                      /*!< Disable bit data */
#define SPI_CR1_RXIFLSEL_Pos                  8                      /*!< Receive interrupt FIFO level select */
#define SPI_CR1_TXIFLSEL_Pos                  12                     /*!< Transmit interrupt FIFO level select */

/* Bit field masks: */
#define SPI_CR1_SSE_Msk                       0x00000002             /*!< Enable transceiver */
#define SPI_CR1_MS_Msk                        0x00000004             /*!< Select mode */
#define SPI_CR1_SOD_Msk                       0x00000008             /*!< Disable bit data */
#define SPI_CR1_RXIFLSEL_Msk                  0x00000F00             /*!< Receive interrupt FIFO level select */
#define SPI_CR1_TXIFLSEL_Msk                  0x0000F000             /*!< Transmit interrupt FIFO level select */

/*--  DR: Data register ---------------------------------------------------------------------------------------*/
typedef struct {
  uint32_t DATA                   :16;                               /*!<  */
} _SPI_DR_bits;

/* Bit field positions: */
#define SPI_DR_DATA_Pos                       0                      /*!<  */

/* Bit field masks: */
#define SPI_DR_DATA_Msk                       0x0000FFFF             /*!<  */

/*--  SR: State register --------------------------------------------------------------------------------------*/
typedef struct {
  uint32_t TFE                    :1;                                /*!< FIFO buffer empty flag transmitter */
  uint32_t TNF                    :1;                                /*!< Indicator the transmitter FIFO buffer is not full */
  uint32_t RNE                    :1;                                /*!< Indicate not empty receive buffer */
  uint32_t RFF                    :1;                                /*!< Indicate full receive buffer */
  uint32_t BSY                    :1;                                /*!< Activity flag */
} _SPI_SR_bits;

/* Bit field positions: */
#define SPI_SR_TFE_Pos                        0                      /*!< FIFO buffer empty flag transmitter */
#define SPI_SR_TNF_Pos                        1                      /*!< Indicator the transmitter FIFO buffer is not full */
#define SPI_SR_RNE_Pos                        2                      /*!< Indicate not empty receive buffer */
#define SPI_SR_RFF_Pos                        3                      /*!< Indicate full receive buffer */
#define SPI_SR_BSY_Pos                        4                      /*!< Activity flag */

/* Bit field masks: */
#define SPI_SR_TFE_Msk                        0x00000001             /*!< FIFO buffer empty flag transmitter */
#define SPI_SR_TNF_Msk                        0x00000002             /*!< Indicator the transmitter FIFO buffer is not full */
#define SPI_SR_RNE_Msk                        0x00000004             /*!< Indicate not empty receive buffer */
#define SPI_SR_RFF_Msk                        0x00000008             /*!< Indicate full receive buffer */
#define SPI_SR_BSY_Msk                        0x00000010             /*!< Activity flag */

/*--  CPSR: Clock division factor register --------------------------------------------------------------------*/
typedef struct {
  uint32_t CPSDVSR                :8;                                /*!< Clock division factor. Bit0 always 0 */
} _SPI_CPSR_bits;

/* Bit field positions: */
#define SPI_CPSR_CPSDVSR_Pos                  0                      /*!< Clock division factor. Bit0 always 0 */

/* Bit field masks: */
#define SPI_CPSR_CPSDVSR_Msk                  0x000000FF             /*!< Clock division factor. Bit0 always 0 */

/*--  IMSC: Mask interrupt register ---------------------------------------------------------------------------*/
typedef struct {
  uint32_t RORIM                  :1;                                /*!< Interrupt mask bit SSPRORINTR buffer overflow receiver */
  uint32_t RTIM                   :1;                                /*!< Interrupt mask bit SSPRTINTR timeout receiver */
  uint32_t RXIM                   :1;                                /*!< SSPRXINTR interrupt mask bit to fill 50% or less of the receiver FIFO buffer */
  uint32_t TXIM                   :1;                                /*!< SSPTXINTR interrupt mask bit to fill 50% or less of the FIFO buffer of the transmitter */
} _SPI_IMSC_bits;

/* Bit field positions: */
#define SPI_IMSC_RORIM_Pos                    0                      /*!< Interrupt mask bit SSPRORINTR buffer overflow receiver */
#define SPI_IMSC_RTIM_Pos                     1                      /*!< Interrupt mask bit SSPRTINTR timeout receiver */
#define SPI_IMSC_RXIM_Pos                     2                      /*!< SSPRXINTR interrupt mask bit to fill 50% or less of the receiver FIFO buffer */
#define SPI_IMSC_TXIM_Pos                     3                      /*!< SSPTXINTR interrupt mask bit to fill 50% or less of the FIFO buffer of the transmitter */

/* Bit field masks: */
#define SPI_IMSC_RORIM_Msk                    0x00000001             /*!< Interrupt mask bit SSPRORINTR buffer overflow receiver */
#define SPI_IMSC_RTIM_Msk                     0x00000002             /*!< Interrupt mask bit SSPRTINTR timeout receiver */
#define SPI_IMSC_RXIM_Msk                     0x00000004             /*!< SSPRXINTR interrupt mask bit to fill 50% or less of the receiver FIFO buffer */
#define SPI_IMSC_TXIM_Msk                     0x00000008             /*!< SSPTXINTR interrupt mask bit to fill 50% or less of the FIFO buffer of the transmitter */

/*--  RIS: Status register interrupt without mask -------------------------------------------------------------*/
typedef struct {
  uint32_t RORRIS                 :1;                                /*!< Interrupt status before masking SSPRORINTR */
  uint32_t RTRIS                  :1;                                /*!< Interrupt status before masking SSPRTINTR */
  uint32_t RXRIS                  :1;                                /*!< Interrupt status before masking SSPRXINTR */
  uint32_t TXRIS                  :1;                                /*!< Interrupt status before masking SSPTXINTR */
} _SPI_RIS_bits;

/* Bit field positions: */
#define SPI_RIS_RORRIS_Pos                    0                      /*!< Interrupt status before masking SSPRORINTR */
#define SPI_RIS_RTRIS_Pos                     1                      /*!< Interrupt status before masking SSPRTINTR */
#define SPI_RIS_RXRIS_Pos                     2                      /*!< Interrupt status before masking SSPRXINTR */
#define SPI_RIS_TXRIS_Pos                     3                      /*!< Interrupt status before masking SSPTXINTR */

/* Bit field masks: */
#define SPI_RIS_RORRIS_Msk                    0x00000001             /*!< Interrupt status before masking SSPRORINTR */
#define SPI_RIS_RTRIS_Msk                     0x00000002             /*!< Interrupt status before masking SSPRTINTR */
#define SPI_RIS_RXRIS_Msk                     0x00000004             /*!< Interrupt status before masking SSPRXINTR */
#define SPI_RIS_TXRIS_Msk                     0x00000008             /*!< Interrupt status before masking SSPTXINTR */

/*--  MIS: Status register interrupt masking account ----------------------------------------------------------*/
typedef struct {
  uint32_t RORRIS                 :1;                                /*!< Masked interrupt status SSPRORINTR */
  uint32_t RTRIS                  :1;                                /*!< Masked interrupt status SSPRTINTR */
  uint32_t RXRIS                  :1;                                /*!< Masked interrupt status SSPRXINTR */
  uint32_t TXRIS                  :1;                                /*!< Masked interrupt status SSPTXINTR */
} _SPI_MIS_bits;

/* Bit field positions: */
#define SPI_MIS_RORRIS_Pos                    0                      /*!< Masked interrupt status SSPRORINTR */
#define SPI_MIS_RTRIS_Pos                     1                      /*!< Masked interrupt status SSPRTINTR */
#define SPI_MIS_RXRIS_Pos                     2                      /*!< Masked interrupt status SSPRXINTR */
#define SPI_MIS_TXRIS_Pos                     3                      /*!< Masked interrupt status SSPTXINTR */

/* Bit field masks: */
#define SPI_MIS_RORRIS_Msk                    0x00000001             /*!< Masked interrupt status SSPRORINTR */
#define SPI_MIS_RTRIS_Msk                     0x00000002             /*!< Masked interrupt status SSPRTINTR */
#define SPI_MIS_RXRIS_Msk                     0x00000004             /*!< Masked interrupt status SSPRXINTR */
#define SPI_MIS_TXRIS_Msk                     0x00000008             /*!< Masked interrupt status SSPTXINTR */

/*--  ICR: Register reset interrupt ---------------------------------------------------------------------------*/
typedef struct {
  uint32_t RORIC                  :1;                                /*!< Reset interrupt SSPRORINTR */
  uint32_t RTIC                   :1;                                /*!< Reset interrupt SSPRTINTR */
} _SPI_ICR_bits;

/* Bit field positions: */
#define SPI_ICR_RORIC_Pos                     0                      /*!< Reset interrupt SSPRORINTR */
#define SPI_ICR_RTIC_Pos                      1                      /*!< Reset interrupt SSPRTINTR */

/* Bit field masks: */
#define SPI_ICR_RORIC_Msk                     0x00000001             /*!< Reset interrupt SSPRORINTR */
#define SPI_ICR_RTIC_Msk                      0x00000002             /*!< Reset interrupt SSPRTINTR */

/*--  DMACR: Control register DMA -----------------------------------------------------------------------------*/
typedef struct {
  uint32_t RXDMAE                 :1;                                /*!< DMA enable bit at reception */
  uint32_t TXDMAE                 :1;                                /*!< DMA enable bit transmission */
} _SPI_DMACR_bits;

/* Bit field positions: */
#define SPI_DMACR_RXDMAE_Pos                  0                      /*!< DMA enable bit at reception */
#define SPI_DMACR_TXDMAE_Pos                  1                      /*!< DMA enable bit transmission */

/* Bit field masks: */
#define SPI_DMACR_RXDMAE_Msk                  0x00000001             /*!< DMA enable bit at reception */
#define SPI_DMACR_TXDMAE_Msk                  0x00000002             /*!< DMA enable bit transmission */

typedef struct {
  union {                                                               /*!< Control register 0 */
    __IO uint32_t CR0;                                               /*!< CR0    : type used for word access */
    __IO _SPI_CR0_bits  CR0_bit;                                     /*!< CR0_bit: structure used for bit access */
  };
  union {                                                               /*!< Control register 1 */
    __IO uint32_t CR1;                                               /*!< CR1    : type used for word access */
    __IO _SPI_CR1_bits  CR1_bit;                                     /*!< CR1_bit: structure used for bit access */
  };
  union {                                                               /*!< Data register */
    __IO uint32_t DR;                                                /*!< DR    : type used for word access */
    __IO _SPI_DR_bits  DR_bit;                                       /*!< DR_bit: structure used for bit access */
  };
  union {                                                               /*!< State register */
    __I uint32_t SR;                                                 /*!< SR    : type used for word access */
    __I _SPI_SR_bits  SR_bit;                                        /*!< SR_bit: structure used for bit access */
  };
  union {                                                               /*!< Clock division factor register */
    __IO uint32_t CPSR;                                              /*!< CPSR    : type used for word access */
    __IO _SPI_CPSR_bits  CPSR_bit;                                   /*!< CPSR_bit: structure used for bit access */
  };
  union {                                                               /*!< Mask interrupt register */
    __IO uint32_t IMSC;                                              /*!< IMSC    : type used for word access */
    __IO _SPI_IMSC_bits  IMSC_bit;                                   /*!< IMSC_bit: structure used for bit access */
  };
  union {                                                               /*!< Status register interrupt without mask */
    __I uint32_t RIS;                                                /*!< RIS    : type used for word access */
    __I _SPI_RIS_bits  RIS_bit;                                      /*!< RIS_bit: structure used for bit access */
  };
  union {                                                               /*!< Status register interrupt masking account */
    __I uint32_t MIS;                                                /*!< MIS    : type used for word access */
    __I _SPI_MIS_bits  MIS_bit;                                      /*!< MIS_bit: structure used for bit access */
  };
  union {                                                               /*!< Register reset interrupt */
    __O uint32_t ICR;                                                /*!< ICR    : type used for word access */
    __O _SPI_ICR_bits  ICR_bit;                                      /*!< ICR_bit: structure used for bit access */
  };
  union {                                                               /*!< Control register DMA */
    __IO uint32_t DMACR;                                             /*!< DMACR    : type used for word access */
    __IO _SPI_DMACR_bits  DMACR_bit;                                 /*!< DMACR_bit: structure used for bit access */
  };
} SPI_TypeDef;

/******************************************************************************/
/*                         CAN registers                                      */
/******************************************************************************/

/*--  CLC: CAN Clock Control Register -------------------------------------------------------------------------*/
typedef struct {
  uint32_t DISR                   :1;                                /*!< Module Disable Request bit */
  uint32_t DISS                   :1;                                /*!< Module Disable Status Bit */
  uint32_t SPEN                   :1;                                /*!< Module Suspend Enable for debug */
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t SBWE                   :1;                                /*!< Module Suspend Bit Write Enable */
  uint32_t FSOE                   :1;                                /*!< Fast Shut-off Enable */
} _CAN_CLC_bits;

/* Bit field positions: */
#define CAN_CLC_DISR_Pos                      0                      /*!< Module Disable Request bit */
#define CAN_CLC_DISS_Pos                      1                      /*!< Module Disable Status Bit */
#define CAN_CLC_SPEN_Pos                      2                      /*!< Module Suspend Enable for debug */
#define CAN_CLC_SBWE_Pos                      4                      /*!< Module Suspend Bit Write Enable */
#define CAN_CLC_FSOE_Pos                      5                      /*!< Fast Shut-off Enable */

/* Bit field masks: */
#define CAN_CLC_DISR_Msk                      0x00000001             /*!< Module Disable Request bit */
#define CAN_CLC_DISS_Msk                      0x00000002             /*!< Module Disable Status Bit */
#define CAN_CLC_SPEN_Msk                      0x00000004             /*!< Module Suspend Enable for debug */
#define CAN_CLC_SBWE_Msk                      0x00000010             /*!< Module Suspend Bit Write Enable */
#define CAN_CLC_FSOE_Msk                      0x00000020             /*!< Fast Shut-off Enable */

/*--  ID: Module Identification Register ----------------------------------------------------------------------*/
typedef struct {
  uint32_t MODREV                 :8;                                /*!< Module Revision Number */
  uint32_t MODTYPE                :8;                                /*!< Module type */
  uint32_t MODNUM                 :16;                               /*!< Module Number Value */
} _CAN_ID_bits;

/* Bit field positions: */
#define CAN_ID_MODREV_Pos                     0                      /*!< Module Revision Number */
#define CAN_ID_MODTYPE_Pos                    8                      /*!< Module type */
#define CAN_ID_MODNUM_Pos                     16                     /*!< Module Number Value */

/* Bit field masks: */
#define CAN_ID_MODREV_Msk                     0x000000FF             /*!< Module Revision Number */
#define CAN_ID_MODTYPE_Msk                    0x0000FF00             /*!< Module type */
#define CAN_ID_MODNUM_Msk                     0xFFFF0000             /*!< Module Number Value */

/*--  FDR: Fractional Divider Register ------------------------------------------------------------------------*/
typedef struct {
  uint32_t STEP                   :10;                               /*!< Step Value */
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t SM                     :1;                                /*!< Suspend Mode */
  uint32_t SC                     :2;                                /*!< Suspend Control */
  uint32_t DM                     :2;                                /*!< Divider Mode */
  uint32_t RESULT                 :10;                               /*!< Result Value */
  uint32_t                        :2;                                /*!< RESERVED */
  uint32_t SUSACK                 :1;                                /*!< Suspend Mode Acknowledge */
  uint32_t SUSREQ                 :1;                                /*!< Suspend Mode Request */
  uint32_t ENHW                   :1;                                /*!< Enable Hardware Clock Control */
  uint32_t DISCLK                 :1;                                /*!< Disable Clock */
} _CAN_FDR_bits;

/* Bit field positions: */
#define CAN_FDR_STEP_Pos                      0                      /*!< Step Value */
#define CAN_FDR_SM_Pos                        11                     /*!< Suspend Mode */
#define CAN_FDR_SC_Pos                        12                     /*!< Suspend Control */
#define CAN_FDR_DM_Pos                        14                     /*!< Divider Mode */
#define CAN_FDR_RESULT_Pos                    16                     /*!< Result Value */
#define CAN_FDR_SUSACK_Pos                    28                     /*!< Suspend Mode Acknowledge */
#define CAN_FDR_SUSREQ_Pos                    29                     /*!< Suspend Mode Request */
#define CAN_FDR_ENHW_Pos                      30                     /*!< Enable Hardware Clock Control */
#define CAN_FDR_DISCLK_Pos                    31                     /*!< Disable Clock */

/* Bit field masks: */
#define CAN_FDR_STEP_Msk                      0x000003FF             /*!< Step Value */
#define CAN_FDR_SM_Msk                        0x00000800             /*!< Suspend Mode */
#define CAN_FDR_SC_Msk                        0x00003000             /*!< Suspend Control */
#define CAN_FDR_DM_Msk                        0x0000C000             /*!< Divider Mode */
#define CAN_FDR_RESULT_Msk                    0x03FF0000             /*!< Result Value */
#define CAN_FDR_SUSACK_Msk                    0x10000000             /*!< Suspend Mode Acknowledge */
#define CAN_FDR_SUSREQ_Msk                    0x20000000             /*!< Suspend Mode Request */
#define CAN_FDR_ENHW_Msk                      0x40000000             /*!< Enable Hardware Clock Control */
#define CAN_FDR_DISCLK_Msk                    0x80000000             /*!< Disable Clock */

/* Bit field enums: */
typedef enum {
  CAN_FDR_DM_Disable                         = 0x0,                  /*!< counter disabled */
  CAN_FDR_DM_NormalMode                      = 0x1,                  /*!< normal operation mode */
  CAN_FDR_DM_DividerMode                     = 0x2,                  /*!< divider operation mode */
} CAN_FDR_DM_Enum;

/*-- LIST: LIST: List Register0 -------------------------------------------------------------------------------*/
typedef struct {
  uint32_t BEGIN                  :8;                                /*!< List Begin */
  uint32_t END                    :8;                                /*!< List End */
  uint32_t SIZE                   :8;                                /*!< List Size */
  uint32_t EMPTY                  :1;                                /*!< List Empty Indication */
} _CAN_LIST_LIST_bits;

/* Bit field positions: */
#define CAN_LIST_LIST_BEGIN_Pos               0                      /*!< List Begin */
#define CAN_LIST_LIST_END_Pos                 8                      /*!< List End */
#define CAN_LIST_LIST_SIZE_Pos                16                     /*!< List Size */
#define CAN_LIST_LIST_EMPTY_Pos               24                     /*!< List Empty Indication */

/* Bit field masks: */
#define CAN_LIST_LIST_BEGIN_Msk               0x000000FF             /*!< List Begin */
#define CAN_LIST_LIST_END_Msk                 0x0000FF00             /*!< List End */
#define CAN_LIST_LIST_SIZE_Msk                0x00FF0000             /*!< List Size */
#define CAN_LIST_LIST_EMPTY_Msk               0x01000000             /*!< List Empty Indication */

/*-- MSPND: MSPND: Message Pending Register0 ------------------------------------------------------------------*/
typedef struct {
  uint32_t PND                    :32;                               /*!< Message Pending */
} _CAN_MSPND_MSPND_bits;

/* Bit field positions: */
#define CAN_MSPND_MSPND_PND_Pos               0                      /*!< Message Pending */

/* Bit field masks: */
#define CAN_MSPND_MSPND_PND_Msk               0xFFFFFFFF             /*!< Message Pending */

/*-- MSID: MSID: Message Index Register0 ----------------------------------------------------------------------*/
typedef struct {
  uint32_t INDEX                  :8;                                /*!< Message Pending Index */
} _CAN_MSID_MSID_bits;

/* Bit field positions: */
#define CAN_MSID_MSID_INDEX_Pos               0                      /*!< Message Pending Index */

/* Bit field masks: */
#define CAN_MSID_MSID_INDEX_Msk               0x000000FF             /*!< Message Pending Index */

/*--  MSIMASK: Message Index Mask Register --------------------------------------------------------------------*/
typedef struct {
  uint32_t IM                     :32;                               /*!< Message Index Mask */
} _CAN_MSIMASK_bits;

/* Bit field positions: */
#define CAN_MSIMASK_IM_Pos                    0                      /*!< Message Index Mask */

/* Bit field masks: */
#define CAN_MSIMASK_IM_Msk                    0xFFFFFFFF             /*!< Message Index Mask */

/*--  PANCTR: Panel Control Register --------------------------------------------------------------------------*/
typedef struct {
  uint32_t PANCMD                 :8;                                /*!< Panel Command */
  uint32_t BUSY                   :1;                                /*!< Panel Busy Flag */
  uint32_t RBUSY                  :1;                                /*!< Result Busy Flag */
  uint32_t                        :6;                                /*!< RESERVED */
  uint32_t PANAR1                 :8;                                /*!< Panel argument 1 */
  uint32_t PANAR2                 :8;                                /*!< Panel argument 2 */
} _CAN_PANCTR_bits;

/* Bit field positions: */
#define CAN_PANCTR_PANCMD_Pos                 0                      /*!< Panel Command */
#define CAN_PANCTR_BUSY_Pos                   8                      /*!< Panel Busy Flag */
#define CAN_PANCTR_RBUSY_Pos                  9                      /*!< Result Busy Flag */
#define CAN_PANCTR_PANAR1_Pos                 16                     /*!< Panel argument 1 */
#define CAN_PANCTR_PANAR2_Pos                 24                     /*!< Panel argument 2 */

/* Bit field masks: */
#define CAN_PANCTR_PANCMD_Msk                 0x000000FF             /*!< Panel Command */
#define CAN_PANCTR_BUSY_Msk                   0x00000100             /*!< Panel Busy Flag */
#define CAN_PANCTR_RBUSY_Msk                  0x00000200             /*!< Result Busy Flag */
#define CAN_PANCTR_PANAR1_Msk                 0x00FF0000             /*!< Panel argument 1 */
#define CAN_PANCTR_PANAR2_Msk                 0xFF000000             /*!< Panel argument 2 */

/*--  MCRREG:  ------------------------------------------------------------------------------------------------*/
typedef struct {
  uint32_t                        :12;                               /*!< RESERVED */
  uint32_t MPSEL                  :4;                                /*!< Message Pending Selector */
} _CAN_MCRREG_bits;

/* Bit field positions: */
#define CAN_MCRREG_MPSEL_Pos                  12                     /*!< Message Pending Selector */

/* Bit field masks: */
#define CAN_MCRREG_MPSEL_Msk                  0x0000F000             /*!< Message Pending Selector */

/*--  MITR: Module Interrupt Trigger Register -----------------------------------------------------------------*/
typedef struct {
  uint32_t IT                     :16;                               /*!< Interrupt Trigger */
} _CAN_MITR_bits;

/* Bit field positions: */
#define CAN_MITR_IT_Pos                       0                      /*!< Interrupt Trigger */

/* Bit field masks: */
#define CAN_MITR_IT_Msk                       0x0000FFFF             /*!< Interrupt Trigger */

/*-- Node: NCR: Node control register0 ------------------------------------------------------------------------*/
typedef struct {
  uint32_t INIT                   :1;                                /*!< Node Initialization */
  uint32_t TRIE                   :1;                                /*!< Transfer Interrupt Enable */
  uint32_t LECIE                  :1;                                /*!< LEC Indicated Error Interrupt Enable */
  uint32_t ALIE                   :1;                                /*!< Alert Interrupt Enable */
  uint32_t CANDIS                 :1;                                /*!< CAN Disable */
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t CCE                    :1;                                /*!< Configuration Change Enable */
  uint32_t CALM                   :1;                                /*!< CAN Analyzer Mode */
  uint32_t SUSEN                  :1;                                /*!< Suspend Enable */
} _CAN_Node_NCR_bits;

/* Bit field positions: */
#define CAN_Node_NCR_INIT_Pos                 0                      /*!< Node Initialization */
#define CAN_Node_NCR_TRIE_Pos                 1                      /*!< Transfer Interrupt Enable */
#define CAN_Node_NCR_LECIE_Pos                2                      /*!< LEC Indicated Error Interrupt Enable */
#define CAN_Node_NCR_ALIE_Pos                 3                      /*!< Alert Interrupt Enable */
#define CAN_Node_NCR_CANDIS_Pos               4                      /*!< CAN Disable */
#define CAN_Node_NCR_CCE_Pos                  6                      /*!< Configuration Change Enable */
#define CAN_Node_NCR_CALM_Pos                 7                      /*!< CAN Analyzer Mode */
#define CAN_Node_NCR_SUSEN_Pos                8                      /*!< Suspend Enable */

/* Bit field masks: */
#define CAN_Node_NCR_INIT_Msk                 0x00000001             /*!< Node Initialization */
#define CAN_Node_NCR_TRIE_Msk                 0x00000002             /*!< Transfer Interrupt Enable */
#define CAN_Node_NCR_LECIE_Msk                0x00000004             /*!< LEC Indicated Error Interrupt Enable */
#define CAN_Node_NCR_ALIE_Msk                 0x00000008             /*!< Alert Interrupt Enable */
#define CAN_Node_NCR_CANDIS_Msk               0x00000010             /*!< CAN Disable */
#define CAN_Node_NCR_CCE_Msk                  0x00000040             /*!< Configuration Change Enable */
#define CAN_Node_NCR_CALM_Msk                 0x00000080             /*!< CAN Analyzer Mode */
#define CAN_Node_NCR_SUSEN_Msk                0x00000100             /*!< Suspend Enable */

/*-- Node: NSR: Node Status Register0 -------------------------------------------------------------------------*/
typedef struct {
  uint32_t LEC                    :3;                                /*!< Last Error Code */
  uint32_t TXOK                   :1;                                /*!< Message Transmitted Successfully */
  uint32_t RXOK                   :1;                                /*!< Message Received Successfully */
  uint32_t ALERT                  :1;                                /*!< Alert Warning */
  uint32_t EWRN                   :1;                                /*!< Error Warning Status */
  uint32_t BOFF                   :1;                                /*!< Bus-Off Status */
  uint32_t LLE                    :1;                                /*!< List Length Error */
  uint32_t LOE                    :1;                                /*!< List Object Error */
  uint32_t SUSACK                 :1;                                /*!< Suspend Acknowledge */
} _CAN_Node_NSR_bits;

/* Bit field positions: */
#define CAN_Node_NSR_LEC_Pos                  0                      /*!< Last Error Code */
#define CAN_Node_NSR_TXOK_Pos                 3                      /*!< Message Transmitted Successfully */
#define CAN_Node_NSR_RXOK_Pos                 4                      /*!< Message Received Successfully */
#define CAN_Node_NSR_ALERT_Pos                5                      /*!< Alert Warning */
#define CAN_Node_NSR_EWRN_Pos                 6                      /*!< Error Warning Status */
#define CAN_Node_NSR_BOFF_Pos                 7                      /*!< Bus-Off Status */
#define CAN_Node_NSR_LLE_Pos                  8                      /*!< List Length Error */
#define CAN_Node_NSR_LOE_Pos                  9                      /*!< List Object Error */
#define CAN_Node_NSR_SUSACK_Pos               10                     /*!< Suspend Acknowledge */

/* Bit field masks: */
#define CAN_Node_NSR_LEC_Msk                  0x00000007             /*!< Last Error Code */
#define CAN_Node_NSR_TXOK_Msk                 0x00000008             /*!< Message Transmitted Successfully */
#define CAN_Node_NSR_RXOK_Msk                 0x00000010             /*!< Message Received Successfully */
#define CAN_Node_NSR_ALERT_Msk                0x00000020             /*!< Alert Warning */
#define CAN_Node_NSR_EWRN_Msk                 0x00000040             /*!< Error Warning Status */
#define CAN_Node_NSR_BOFF_Msk                 0x00000080             /*!< Bus-Off Status */
#define CAN_Node_NSR_LLE_Msk                  0x00000100             /*!< List Length Error */
#define CAN_Node_NSR_LOE_Msk                  0x00000200             /*!< List Object Error */
#define CAN_Node_NSR_SUSACK_Msk               0x00000400             /*!< Suspend Acknowledge */

/* Bit field enums: */
typedef enum {
  CAN_Node_NSR_LEC_NoErr                     = 0x0,                  /*!< no error */
  CAN_Node_NSR_LEC_StuffErr                  = 0x1,                  /*!< stuff error */
  CAN_Node_NSR_LEC_FormErr                   = 0x2,                  /*!< form error */
  CAN_Node_NSR_LEC_AckErr                    = 0x3,                  /*!< acknowlegment error */
  CAN_Node_NSR_LEC_Bit1Err                   = 0x4,                  /*!< bit 1 error */
  CAN_Node_NSR_LEC_Bit0Err                   = 0x5,                  /*!< bit 0 error */
  CAN_Node_NSR_LEC_CRCErr                    = 0x6,                  /*!< CRC error */
  CAN_Node_NSR_LEC_WriteEn                   = 0x7,                  /*!< enable hardware write */
} CAN_Node_NSR_LEC_Enum;

/*-- Node: NIPR: Node Interrupt Pointer Register0 -------------------------------------------------------------*/
typedef struct {
  uint32_t ALINP                  :4;                                /*!< Alert Interrupt Node Pointer */
  uint32_t LECINP                 :4;                                /*!< Last Error Code Interrupt Node Pointer */
  uint32_t TRINP                  :4;                                /*!< Transfer OK Interrupt Node Pointer */
  uint32_t CFCINP                 :4;                                /*!< Frame Counter Interrupt Node Pointer */
} _CAN_Node_NIPR_bits;

/* Bit field positions: */
#define CAN_Node_NIPR_ALINP_Pos               0                      /*!< Alert Interrupt Node Pointer */
#define CAN_Node_NIPR_LECINP_Pos              4                      /*!< Last Error Code Interrupt Node Pointer */
#define CAN_Node_NIPR_TRINP_Pos               8                      /*!< Transfer OK Interrupt Node Pointer */
#define CAN_Node_NIPR_CFCINP_Pos              12                     /*!< Frame Counter Interrupt Node Pointer */

/* Bit field masks: */
#define CAN_Node_NIPR_ALINP_Msk               0x0000000F             /*!< Alert Interrupt Node Pointer */
#define CAN_Node_NIPR_LECINP_Msk              0x000000F0             /*!< Last Error Code Interrupt Node Pointer */
#define CAN_Node_NIPR_TRINP_Msk               0x00000F00             /*!< Transfer OK Interrupt Node Pointer */
#define CAN_Node_NIPR_CFCINP_Msk              0x0000F000             /*!< Frame Counter Interrupt Node Pointer */

/*-- Node: NPCR: Node Port Control Register0 ------------------------------------------------------------------*/
typedef struct {
  uint32_t RXSEL                  :3;                                /*!< Receive Select */
  uint32_t                        :5;                                /*!< RESERVED */
  uint32_t LBM                    :1;                                /*!< Loop-Back Mode */
} _CAN_Node_NPCR_bits;

/* Bit field positions: */
#define CAN_Node_NPCR_RXSEL_Pos               0                      /*!< Receive Select */
#define CAN_Node_NPCR_LBM_Pos                 8                      /*!< Loop-Back Mode */

/* Bit field masks: */
#define CAN_Node_NPCR_RXSEL_Msk               0x00000007             /*!< Receive Select */
#define CAN_Node_NPCR_LBM_Msk                 0x00000100             /*!< Loop-Back Mode */

/*-- Node: NBTR: Node Bit Timing Register0 --------------------------------------------------------------------*/
typedef struct {
  uint32_t BRP                    :6;                                /*!< Baud Rate Prescaler */
  uint32_t SJW                    :2;                                /*!< Synchronization Jump Width */
  uint32_t TSEG1                  :4;                                /*!< Time Segment Before Sample Point */
  uint32_t TSEG2                  :3;                                /*!< Time Segment After Sample Point */
  uint32_t DIV8                   :1;                                /*!< Divide Prescaler Clock by 8 */
} _CAN_Node_NBTR_bits;

/* Bit field positions: */
#define CAN_Node_NBTR_BRP_Pos                 0                      /*!< Baud Rate Prescaler */
#define CAN_Node_NBTR_SJW_Pos                 6                      /*!< Synchronization Jump Width */
#define CAN_Node_NBTR_TSEG1_Pos               8                      /*!< Time Segment Before Sample Point */
#define CAN_Node_NBTR_TSEG2_Pos               12                     /*!< Time Segment After Sample Point */
#define CAN_Node_NBTR_DIV8_Pos                15                     /*!< Divide Prescaler Clock by 8 */

/* Bit field masks: */
#define CAN_Node_NBTR_BRP_Msk                 0x0000003F             /*!< Baud Rate Prescaler */
#define CAN_Node_NBTR_SJW_Msk                 0x000000C0             /*!< Synchronization Jump Width */
#define CAN_Node_NBTR_TSEG1_Msk               0x00000F00             /*!< Time Segment Before Sample Point */
#define CAN_Node_NBTR_TSEG2_Msk               0x00007000             /*!< Time Segment After Sample Point */
#define CAN_Node_NBTR_DIV8_Msk                0x00008000             /*!< Divide Prescaler Clock by 8 */

/*-- Node: NECNT: Node Error Counter Register0 ----------------------------------------------------------------*/
typedef struct {
  uint32_t REC                    :8;                                /*!< Receive Error Counter */
  uint32_t TEC                    :8;                                /*!< Transmit Error Counter */
  uint32_t EWRNLVL                :8;                                /*!< Error Warning Level */
  uint32_t LETD                   :1;                                /*!< Last Error Transfer Direction */
  uint32_t LEINC                  :1;                                /*!< Last Error Increment */
} _CAN_Node_NECNT_bits;

/* Bit field positions: */
#define CAN_Node_NECNT_REC_Pos                0                      /*!< Receive Error Counter */
#define CAN_Node_NECNT_TEC_Pos                8                      /*!< Transmit Error Counter */
#define CAN_Node_NECNT_EWRNLVL_Pos            16                     /*!< Error Warning Level */
#define CAN_Node_NECNT_LETD_Pos               24                     /*!< Last Error Transfer Direction */
#define CAN_Node_NECNT_LEINC_Pos              25                     /*!< Last Error Increment */

/* Bit field masks: */
#define CAN_Node_NECNT_REC_Msk                0x000000FF             /*!< Receive Error Counter */
#define CAN_Node_NECNT_TEC_Msk                0x0000FF00             /*!< Transmit Error Counter */
#define CAN_Node_NECNT_EWRNLVL_Msk            0x00FF0000             /*!< Error Warning Level */
#define CAN_Node_NECNT_LETD_Msk               0x01000000             /*!< Last Error Transfer Direction */
#define CAN_Node_NECNT_LEINC_Msk              0x02000000             /*!< Last Error Increment */

/*-- Node: NFCR: Node Frame Counter Register0 -----------------------------------------------------------------*/
typedef struct {
  uint32_t CFC                    :16;                               /*!< CAN Frame Counter */
  uint32_t CFSEL                  :3;                                /*!< CAN Frame Count Selection */
  uint32_t CFMOD                  :2;                                /*!< CAN Frame Counter Mode */
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t CFCIE                  :1;                                /*!< CAN Frame Counter Interrupt Enable */
  uint32_t CFCOV                  :1;                                /*!< CAN Frame Counter Overflow Flag */
} _CAN_Node_NFCR_bits;

/* Bit field positions: */
#define CAN_Node_NFCR_CFC_Pos                 0                      /*!< CAN Frame Counter */
#define CAN_Node_NFCR_CFSEL_Pos               16                     /*!< CAN Frame Count Selection */
#define CAN_Node_NFCR_CFMOD_Pos               19                     /*!< CAN Frame Counter Mode */
#define CAN_Node_NFCR_CFCIE_Pos               22                     /*!< CAN Frame Counter Interrupt Enable */
#define CAN_Node_NFCR_CFCOV_Pos               23                     /*!< CAN Frame Counter Overflow Flag */

/* Bit field masks: */
#define CAN_Node_NFCR_CFC_Msk                 0x0000FFFF             /*!< CAN Frame Counter */
#define CAN_Node_NFCR_CFSEL_Msk               0x00070000             /*!< CAN Frame Count Selection */
#define CAN_Node_NFCR_CFMOD_Msk               0x00180000             /*!< CAN Frame Counter Mode */
#define CAN_Node_NFCR_CFCIE_Msk               0x00400000             /*!< CAN Frame Counter Interrupt Enable */
#define CAN_Node_NFCR_CFCOV_Msk               0x00800000             /*!< CAN Frame Counter Overflow Flag */

//Cluster LIST:
typedef struct {
  union { 
  /*!< List Register0 */
    __I uint32_t LIST;                                               /*!< LIST : type used for word access */
    __I _CAN_LIST_LIST_bits LIST_bit;                                /*!< LIST_bit: structure used for bit access */
  };
} _CAN_LIST_TypeDef;
//Cluster MSPND:
typedef struct {
  union { 
  /*!< Message Pending Register0 */
    __IO uint32_t MSPND;                                             /*!< MSPND : type used for word access */
    __IO _CAN_MSPND_MSPND_bits MSPND_bit;                            /*!< MSPND_bit: structure used for bit access */
  };
} _CAN_MSPND_TypeDef;
//Cluster MSID:
typedef struct {
  union { 
  /*!< Message Index Register0 */
    __I uint32_t MSID;                                               /*!< MSID : type used for word access */
    __I _CAN_MSID_MSID_bits MSID_bit;                                /*!< MSID_bit: structure used for bit access */
  };
} _CAN_MSID_TypeDef;
//Cluster Node:
typedef struct {
  union { 
  /*!< Node control register0 */
    __IO uint32_t NCR;                                               /*!< NCR : type used for word access */
    __IO _CAN_Node_NCR_bits NCR_bit;                                 /*!< NCR_bit: structure used for bit access */
  };
  union { 
  /*!< Node Status Register0 */
    __IO uint32_t NSR;                                               /*!< NSR : type used for word access */
    __IO _CAN_Node_NSR_bits NSR_bit;                                 /*!< NSR_bit: structure used for bit access */
  };
  union { 
  /*!< Node Interrupt Pointer Register0 */
    __IO uint32_t NIPR;                                              /*!< NIPR : type used for word access */
    __IO _CAN_Node_NIPR_bits NIPR_bit;                               /*!< NIPR_bit: structure used for bit access */
  };
  union { 
  /*!< Node Port Control Register0 */
    __IO uint32_t NPCR;                                              /*!< NPCR : type used for word access */
    __IO _CAN_Node_NPCR_bits NPCR_bit;                               /*!< NPCR_bit: structure used for bit access */
  };
  union { 
  /*!< Node Bit Timing Register0 */
    __IO uint32_t NBTR;                                              /*!< NBTR : type used for word access */
    __IO _CAN_Node_NBTR_bits NBTR_bit;                               /*!< NBTR_bit: structure used for bit access */
  };
  union { 
  /*!< Node Error Counter Register0 */
    __IO uint32_t NECNT;                                             /*!< NECNT : type used for word access */
    __IO _CAN_Node_NECNT_bits NECNT_bit;                             /*!< NECNT_bit: structure used for bit access */
  };
  union { 
  /*!< Node Frame Counter Register0 */
    __IO uint32_t NFCR;                                              /*!< NFCR : type used for word access */
    __IO _CAN_Node_NFCR_bits NFCR_bit;                               /*!< NFCR_bit: structure used for bit access */
  };
    __IO uint32_t Reserved0[57];
} _CAN_Node_TypeDef;
typedef struct {
  union {                                                               /*!< CAN Clock Control Register */
    __IO uint32_t CLC;                                               /*!< CLC    : type used for word access */
    __IO _CAN_CLC_bits  CLC_bit;                                     /*!< CLC_bit: structure used for bit access */
  };
    __IO uint32_t Reserved0;
  union {                                                               /*!< Module Identification Register */
    __IO uint32_t ID;                                                /*!< ID    : type used for word access */
    __IO _CAN_ID_bits  ID_bit;                                       /*!< ID_bit: structure used for bit access */
  };
  union {                                                               /*!< Fractional Divider Register */
    __IO uint32_t FDR;                                               /*!< FDR    : type used for word access */
    __IO _CAN_FDR_bits  FDR_bit;                                     /*!< FDR_bit: structure used for bit access */
  };
    __IO uint32_t Reserved1[60];
  _CAN_LIST_TypeDef LIST[8];
    __IO uint32_t Reserved2[8];
  _CAN_MSPND_TypeDef MSPND[8];
    __IO uint32_t Reserved3[8];
  _CAN_MSID_TypeDef MSID[8];
    __IO uint32_t Reserved4[8];
  union {                                                               /*!< Message Index Mask Register */
    __IO uint32_t MSIMASK;                                           /*!< MSIMASK    : type used for word access */
    __IO _CAN_MSIMASK_bits  MSIMASK_bit;                             /*!< MSIMASK_bit: structure used for bit access */
  };
  union {                                                               /*!< Panel Control Register */
    __IO uint32_t PANCTR;                                            /*!< PANCTR    : type used for word access */
    __IO _CAN_PANCTR_bits  PANCTR_bit;                               /*!< PANCTR_bit: structure used for bit access */
  };
  union {                                                               /*!<  */
    __IO uint32_t MCRREG;                                            /*!< MCRREG    : type used for word access */
    __IO _CAN_MCRREG_bits  MCRREG_bit;                               /*!< MCRREG_bit: structure used for bit access */
  };
  union {                                                               /*!< Module Interrupt Trigger Register */
    __O uint32_t MITR;                                               /*!< MITR    : type used for word access */
    __O _CAN_MITR_bits  MITR_bit;                                    /*!< MITR_bit: structure used for bit access */
  };
    __IO uint32_t Reserved5[12];
  _CAN_Node_TypeDef Node[2];
} CAN_TypeDef;

/******************************************************************************/
/*                         I2C registers                                      */
/******************************************************************************/

/*--  SDA: Data register --------------------------------------------------------------------------------------*/
typedef struct {
  uint32_t DATA                   :8;                                /*!< Data field */
} _I2C_SDA_bits;

/* Bit field positions: */
#define I2C_SDA_DATA_Pos                      0                      /*!< Data field */

/* Bit field masks: */
#define I2C_SDA_DATA_Msk                      0x000000FF             /*!< Data field */

/*--  ST: Status register -------------------------------------------------------------------------------------*/
typedef struct {
  uint32_t MODE                   :6;                                /*!< Status code */
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t INT                    :1;                                /*!< Interrupt flag */
} _I2C_ST_bits;

/* Bit field positions: */
#define I2C_ST_MODE_Pos                       0                      /*!< Status code */
#define I2C_ST_INT_Pos                        7                      /*!< Interrupt flag */

/* Bit field masks: */
#define I2C_ST_MODE_Msk                       0x0000003F             /*!< Status code */
#define I2C_ST_INT_Msk                        0x00000080             /*!< Interrupt flag */

/* Bit field enums: */
typedef enum {
  I2C_ST_MODE_IDLE                           = 0x0,                  /*!< General - Idle, no valid status information available */
  I2C_ST_MODE_STDONE                         = 0x1,                  /*!< FS master - Start condition generated */
  I2C_ST_MODE_RSDONE                         = 0x2,                  /*!< FS master - Repeated start condition generated */
  I2C_ST_MODE_IDLARL                         = 0x3,                  /*!< FS master - Arbitration lost, unaddressed slave mode entered */
  I2C_ST_MODE_MTADPA                         = 0x4,                  /*!< FS master transmit - Slave address sent, positive ACK */
  I2C_ST_MODE_MTADNA                         = 0x5,                  /*!< FS master transmit - Slave address sent, negative ACK */
  I2C_ST_MODE_MTDAPA                         = 0x6,                  /*!< FS master transmit - Data byte sent, positive ACK */
  I2C_ST_MODE_MTDANA                         = 0x7,                  /*!< FS master transmit - Data byte sent, negative ACK */
  I2C_ST_MODE_MRADPA                         = 0x8,                  /*!< FS master receive - Slave addres sent, positive ACK */
  I2C_ST_MODE_MRADNA                         = 0x9,                  /*!< FS master receive - Slave addres sent, negative ACK */
  I2C_ST_MODE_MRDAPA                         = 0xA,                  /*!< FS master receive - Data byte received, positive ACK */
  I2C_ST_MODE_MRDANA                         = 0xB,                  /*!< FS master receive - Data byte received, negative ACK */
  I2C_ST_MODE_MTMCER                         = 0xC,                  /*!< FS master - Mastercode transmitted, error detected (positive ACK) */
  I2C_ST_MODE_SRADPA                         = 0x10,                 /*!< FS slave receive - Slave address received, positive ACK */
  I2C_ST_MODE_SRAAPA                         = 0x11,                 /*!< FS slave receive - Slave address received after arbitration loss, positive ACK */
  I2C_ST_MODE_SRDAPA                         = 0x12,                 /*!< FS slave receive - Data byte received, positive ACK */
  I2C_ST_MODE_SRDANA                         = 0x13,                 /*!< FS slave receive - Data byte received, negative ACK */
  I2C_ST_MODE_STADPA                         = 0x14,                 /*!< FS slave transmit - Slave address received, positive ACK */
  I2C_ST_MODE_STAAPA                         = 0x15,                 /*!< FS slave transmit - Slave address received, negative ACK */
  I2C_ST_MODE_STDAPA                         = 0x16,                 /*!< FS slave transmit - Data byte sent, positive ACK */
  I2C_ST_MODE_STDANA                         = 0x17,                 /*!< FS slave transmit - Data byte sent, negative ACK */
  I2C_ST_MODE_SATADP                         = 0x18,                 /*!< FS slave transmit alert response - Alert response address received, positive ACK */
  I2C_ST_MODE_SATAAP                         = 0x19,                 /*!< FS slave transmit alert response - Alert response address received after arbitration loss, positive ACK */
  I2C_ST_MODE_SATDAP                         = 0x1A,                 /*!< FS slave transmit alert response - Alert response data byte sent, positive ACK */
  I2C_ST_MODE_SATDAN                         = 0x1B,                 /*!< FS slave transmit alert response - Alert response data byte sent, negative ACK */
  I2C_ST_MODE_SSTOP                          = 0x1C,                 /*!< FS slave - Slave mode stop condition detected */
  I2C_ST_MODE_SGADPA                         = 0x1D,                 /*!< FS slave - Global call address received, positive ACK */
  I2C_ST_MODE_SDAAPA                         = 0x1E,                 /*!< FS slave - Global call address received after arbitration loss, positive ACK */
  I2C_ST_MODE_BERROR                         = 0x1F,                 /*!< General - Bus error detected (invalid start or stop condition */
  I2C_ST_MODE_HMTMCOK                        = 0x21,                 /*!< HS master - Master code transmitted OK - switched to HS mode */
  I2C_ST_MODE_HRSDONE                        = 0x22,                 /*!< HS master - Repeated start condition generated */
  I2C_ST_MODE_HIDLARL                        = 0x23,                 /*!< HS master - Arbitration lost, HS unaddressed slave mode entered */
  I2C_ST_MODE_HMTADPA                        = 0x24,                 /*!< HS master transmit - Slave address sent, positive ACK */
  I2C_ST_MODE_HMTADNA                        = 0x25,                 /*!< HS master transmit - Slave address sent, negative ACK */
  I2C_ST_MODE_HMTDAPA                        = 0x26,                 /*!< HS master transmit - Data byte sent, positive ACK */
  I2C_ST_MODE_HMTDANA                        = 0x27,                 /*!< HS master transmit - Data byte sent, negative ACK */
  I2C_ST_MODE_HMRADPA                        = 0x28,                 /*!< HS master receive - Slave address sent, positive ACK */
  I2C_ST_MODE_HMRADNA                        = 0x29,                 /*!< HS master receive - Slave address sent, negative ACK */
  I2C_ST_MODE_HMRDAPA                        = 0x2A,                 /*!< HS master receive - Data byte received, positive ACK */
  I2C_ST_MODE_HMRDANA                        = 0x2B,                 /*!< HS master receive - Data byte received, negative ACK */
  I2C_ST_MODE_HSRADPA                        = 0x30,                 /*!< HS slave receive - Slave address received, positive ACK */
  I2C_ST_MODE_HSRDAPA                        = 0x32,                 /*!< HS slave receive - Data byte received, positive ACK */
  I2C_ST_MODE_HSRDANA                        = 0x33,                 /*!< HS slave receive - Data byte received, negative ACK */
  I2C_ST_MODE_HSTADPA                        = 0x34,                 /*!< HS slave transmit - Slave address received, positive ACK */
  I2C_ST_MODE_HSTDAPA                        = 0x36,                 /*!< HS slave transmit - Data byte sent, positive ACK */
  I2C_ST_MODE_HSTDANA                        = 0x37,                 /*!< HS slave transmit - Data byte sent, negative ACK */
} I2C_ST_MODE_Enum;

/*--  CST: Status and control register ------------------------------------------------------------------------*/
typedef struct {
  uint32_t BB                     :1;                                /*!< Bus Busy */
  uint32_t TOCDIV                 :2;                                /*!< SMBus Timeout Divider */
  uint32_t TOERR                  :1;                                /*!< SMBus Timeout Error */
  uint32_t TSDA                   :1;                                /*!< Bit test SDA */
  uint32_t TGSCL                  :1;                                /*!< Toggle SCL */
  uint32_t PECNEXT                :1;                                /*!< PEC Next */
  uint32_t PECFAULT               :1;                                /*!< Packet Error Fault */
} _I2C_CST_bits;

/* Bit field positions: */
#define I2C_CST_BB_Pos                        0                      /*!< Bus Busy */
#define I2C_CST_TOCDIV_Pos                    1                      /*!< SMBus Timeout Divider */
#define I2C_CST_TOERR_Pos                     3                      /*!< SMBus Timeout Error */
#define I2C_CST_TSDA_Pos                      4                      /*!< Bit test SDA */
#define I2C_CST_TGSCL_Pos                     5                      /*!< Toggle SCL */
#define I2C_CST_PECNEXT_Pos                   6                      /*!< PEC Next */
#define I2C_CST_PECFAULT_Pos                  7                      /*!< Packet Error Fault */

/* Bit field masks: */
#define I2C_CST_BB_Msk                        0x00000001             /*!< Bus Busy */
#define I2C_CST_TOCDIV_Msk                    0x00000006             /*!< SMBus Timeout Divider */
#define I2C_CST_TOERR_Msk                     0x00000008             /*!< SMBus Timeout Error */
#define I2C_CST_TSDA_Msk                      0x00000010             /*!< Bit test SDA */
#define I2C_CST_TGSCL_Msk                     0x00000020             /*!< Toggle SCL */
#define I2C_CST_PECNEXT_Msk                   0x00000040             /*!< PEC Next */
#define I2C_CST_PECFAULT_Msk                  0x00000080             /*!< Packet Error Fault */

/* Bit field enums: */
typedef enum {
  I2C_CST_TOCDIV_Disable                     = 0x0,                  /*!< disable clock */
  I2C_CST_TOCDIV_Div4                        = 0x1,                  /*!< clock divided by 4 */
  I2C_CST_TOCDIV_Div8                        = 0x2,                  /*!< clock divided by 8 */
  I2C_CST_TOCDIV_Div16                       = 0x3,                  /*!< clock divided by 16 */
} I2C_CST_TOCDIV_Enum;

/*--  CTL0: Control register 0 --------------------------------------------------------------------------------*/
typedef struct {
  uint32_t START                  :1;                                /*!< Start bit */
  uint32_t STOP                   :1;                                /*!< Stop bit */
  uint32_t INTEN                  :1;                                /*!< Interrupt enable bit */
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t ACK                    :1;                                /*!< Acknowledge bit */
  uint32_t GCMEN                  :1;                                /*!< Global call match enable */
  uint32_t SMBARE                 :1;                                /*!< SMBus Alert Response Match Enable */
  uint32_t CLRST                  :1;                                /*!< Clear interrupt status */
} _I2C_CTL0_bits;

/* Bit field positions: */
#define I2C_CTL0_START_Pos                    0                      /*!< Start bit */
#define I2C_CTL0_STOP_Pos                     1                      /*!< Stop bit */
#define I2C_CTL0_INTEN_Pos                    2                      /*!< Interrupt enable bit */
#define I2C_CTL0_ACK_Pos                      4                      /*!< Acknowledge bit */
#define I2C_CTL0_GCMEN_Pos                    5                      /*!< Global call match enable */
#define I2C_CTL0_SMBARE_Pos                   6                      /*!< SMBus Alert Response Match Enable */
#define I2C_CTL0_CLRST_Pos                    7                      /*!< Clear interrupt status */

/* Bit field masks: */
#define I2C_CTL0_START_Msk                    0x00000001             /*!< Start bit */
#define I2C_CTL0_STOP_Msk                     0x00000002             /*!< Stop bit */
#define I2C_CTL0_INTEN_Msk                    0x00000004             /*!< Interrupt enable bit */
#define I2C_CTL0_ACK_Msk                      0x00000010             /*!< Acknowledge bit */
#define I2C_CTL0_GCMEN_Msk                    0x00000020             /*!< Global call match enable */
#define I2C_CTL0_SMBARE_Msk                   0x00000040             /*!< SMBus Alert Response Match Enable */
#define I2C_CTL0_CLRST_Msk                    0x00000080             /*!< Clear interrupt status */

/*--  ADDR: Register own address ------------------------------------------------------------------------------*/
typedef struct {
  uint32_t ADDR                   :7;                                /*!< Own 7-bit address */
  uint32_t SAEN                   :1;                                /*!< Enable address recognition */
} _I2C_ADDR_bits;

/* Bit field positions: */
#define I2C_ADDR_ADDR_Pos                     0                      /*!< Own 7-bit address */
#define I2C_ADDR_SAEN_Pos                     7                      /*!< Enable address recognition */

/* Bit field masks: */
#define I2C_ADDR_ADDR_Msk                     0x0000007F             /*!< Own 7-bit address */
#define I2C_ADDR_SAEN_Msk                     0x00000080             /*!< Enable address recognition */

/*--  CTL1: Control register 1 --------------------------------------------------------------------------------*/
typedef struct {
  uint32_t ENABLE                 :1;                                /*!< Enable I2C */
  uint32_t SCLFRQ                 :7;                                /*!< SCL frequency (bits [6:0]) */
} _I2C_CTL1_bits;

/* Bit field positions: */
#define I2C_CTL1_ENABLE_Pos                   0                      /*!< Enable I2C */
#define I2C_CTL1_SCLFRQ_Pos                   1                      /*!< SCL frequency (bits [6:0]) */

/* Bit field masks: */
#define I2C_CTL1_ENABLE_Msk                   0x00000001             /*!< Enable I2C */
#define I2C_CTL1_SCLFRQ_Msk                   0x000000FE             /*!< SCL frequency (bits [6:0]) */

/*--  TOPR: Prescaler load register ---------------------------------------------------------------------------*/
typedef struct {
  uint32_t SMBTOPR                :8;                                /*!< Prescaler reload value */
} _I2C_TOPR_bits;

/* Bit field positions: */
#define I2C_TOPR_SMBTOPR_Pos                  0                      /*!< Prescaler reload value */

/* Bit field masks: */
#define I2C_TOPR_SMBTOPR_Msk                  0x000000FF             /*!< Prescaler reload value */

/*--  CTL2: Control register 2 --------------------------------------------------------------------------------*/
typedef struct {
  uint32_t S10ADR                 :3;                                /*!< Upper bits of 10-bit slave address */
  uint32_t S10EN                  :1;                                /*!< Enabled 10-bit slave address */
  uint32_t HSDIV                  :4;                                /*!< SCL frequency select  in HS master mode (bits [3:0]) */
} _I2C_CTL2_bits;

/* Bit field positions: */
#define I2C_CTL2_S10ADR_Pos                   0                      /*!< Upper bits of 10-bit slave address */
#define I2C_CTL2_S10EN_Pos                    3                      /*!< Enabled 10-bit slave address */
#define I2C_CTL2_HSDIV_Pos                    4                      /*!< SCL frequency select  in HS master mode (bits [3:0]) */

/* Bit field masks: */
#define I2C_CTL2_S10ADR_Msk                   0x00000007             /*!< Upper bits of 10-bit slave address */
#define I2C_CTL2_S10EN_Msk                    0x00000008             /*!< Enabled 10-bit slave address */
#define I2C_CTL2_HSDIV_Msk                    0x000000F0             /*!< SCL frequency select  in HS master mode (bits [3:0]) */

/*--  CTL3: Control register 3 --------------------------------------------------------------------------------*/
typedef struct {
  uint32_t SCLFRQ                 :8;                                /*!< SCL frequency (bits [14:7]) */
} _I2C_CTL3_bits;

/* Bit field positions: */
#define I2C_CTL3_SCLFRQ_Pos                   0                      /*!< SCL frequency (bits [14:7]) */

/* Bit field masks: */
#define I2C_CTL3_SCLFRQ_Msk                   0x000000FF             /*!< SCL frequency (bits [14:7]) */

/*--  CTL4: Control Register 4 --------------------------------------------------------------------------------*/
typedef struct {
  uint32_t HSDIV                  :8;                                /*!< SCL frequency select  in HS master mode (bits [11:4]) */
} _I2C_CTL4_bits;

/* Bit field positions: */
#define I2C_CTL4_HSDIV_Pos                    0                      /*!< SCL frequency select  in HS master mode (bits [11:4]) */

/* Bit field masks: */
#define I2C_CTL4_HSDIV_Msk                    0x000000FF             /*!< SCL frequency select  in HS master mode (bits [11:4]) */

typedef struct {
  union {                                                               /*!< Data register */
    __IO uint32_t SDA;                                               /*!< SDA    : type used for word access */
    __IO _I2C_SDA_bits  SDA_bit;                                     /*!< SDA_bit: structure used for bit access */
  };
  union {                                                               /*!< Status register */
    __I uint32_t ST;                                                 /*!< ST    : type used for word access */
    __I _I2C_ST_bits  ST_bit;                                        /*!< ST_bit: structure used for bit access */
  };
  union {                                                               /*!< Status and control register */
    __IO uint32_t CST;                                               /*!< CST    : type used for word access */
    __IO _I2C_CST_bits  CST_bit;                                     /*!< CST_bit: structure used for bit access */
  };
  union {                                                               /*!< Control register 0 */
    __IO uint32_t CTL0;                                              /*!< CTL0    : type used for word access */
    __IO _I2C_CTL0_bits  CTL0_bit;                                   /*!< CTL0_bit: structure used for bit access */
  };
  union {                                                               /*!< Register own address */
    __IO uint32_t ADDR;                                              /*!< ADDR    : type used for word access */
    __IO _I2C_ADDR_bits  ADDR_bit;                                   /*!< ADDR_bit: structure used for bit access */
  };
  union {                                                               /*!< Control register 1 */
    __IO uint32_t CTL1;                                              /*!< CTL1    : type used for word access */
    __IO _I2C_CTL1_bits  CTL1_bit;                                   /*!< CTL1_bit: structure used for bit access */
  };
  union {                                                               /*!< Prescaler load register */
    __IO uint32_t TOPR;                                              /*!< TOPR    : type used for word access */
    __IO _I2C_TOPR_bits  TOPR_bit;                                   /*!< TOPR_bit: structure used for bit access */
  };
  union {                                                               /*!< Control register 2 */
    __IO uint32_t CTL2;                                              /*!< CTL2    : type used for word access */
    __IO _I2C_CTL2_bits  CTL2_bit;                                   /*!< CTL2_bit: structure used for bit access */
  };
  union {                                                               /*!< Control register 3 */
    __IO uint32_t CTL3;                                              /*!< CTL3    : type used for word access */
    __IO _I2C_CTL3_bits  CTL3_bit;                                   /*!< CTL3_bit: structure used for bit access */
  };
  union {                                                               /*!< Control Register 4 */
    __IO uint32_t CTL4;                                              /*!< CTL4    : type used for word access */
    __IO _I2C_CTL4_bits  CTL4_bit;                                   /*!< CTL4_bit: structure used for bit access */
  };
} I2C_TypeDef;

/******************************************************************************/
/*                         CANMSG registers                                   */
/******************************************************************************/

/*-- Msg: MOFCR: Message Object Function Control Register0 ----------------------------------------------------*/
typedef struct {
  uint32_t MMC                    :4;                                /*!< Message Mode Control */
  uint32_t                        :4;                                /*!< RESERVED */
  uint32_t GDFS                   :1;                                /*!< Gateway Data Frame Selected */
  uint32_t IDC                    :1;                                /*!< Identifier Copy */
  uint32_t DLCC                   :1;                                /*!< Data Lengh Code Copy */
  uint32_t DATC                   :1;                                /*!< Data Copy */
  uint32_t                        :4;                                /*!< RESERVED */
  uint32_t RXIE                   :1;                                /*!< Receive Interrupt Enable */
  uint32_t TXIE                   :1;                                /*!< Transmit Interrupt Enable */
  uint32_t OVIE                   :1;                                /*!< Overflow Interrupt Enable */
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t FRREN                  :1;                                /*!< Foreign Remote Request Enable */
  uint32_t RMM                    :1;                                /*!< Transmit Object Remote Monitoring */
  uint32_t SDT                    :1;                                /*!< Single Data Transfer */
  uint32_t STT                    :1;                                /*!< Single Transmit Trial */
  uint32_t DLC                    :4;                                /*!< Data Length Code */
} _CANMSG_Msg_MOFCR_bits;

/* Bit field positions: */
#define CANMSG_Msg_MOFCR_MMC_Pos              0                      /*!< Message Mode Control */
#define CANMSG_Msg_MOFCR_GDFS_Pos             8                      /*!< Gateway Data Frame Selected */
#define CANMSG_Msg_MOFCR_IDC_Pos              9                      /*!< Identifier Copy */
#define CANMSG_Msg_MOFCR_DLCC_Pos             10                     /*!< Data Lengh Code Copy */
#define CANMSG_Msg_MOFCR_DATC_Pos             11                     /*!< Data Copy */
#define CANMSG_Msg_MOFCR_RXIE_Pos             16                     /*!< Receive Interrupt Enable */
#define CANMSG_Msg_MOFCR_TXIE_Pos             17                     /*!< Transmit Interrupt Enable */
#define CANMSG_Msg_MOFCR_OVIE_Pos             18                     /*!< Overflow Interrupt Enable */
#define CANMSG_Msg_MOFCR_FRREN_Pos            20                     /*!< Foreign Remote Request Enable */
#define CANMSG_Msg_MOFCR_RMM_Pos              21                     /*!< Transmit Object Remote Monitoring */
#define CANMSG_Msg_MOFCR_SDT_Pos              22                     /*!< Single Data Transfer */
#define CANMSG_Msg_MOFCR_STT_Pos              23                     /*!< Single Transmit Trial */
#define CANMSG_Msg_MOFCR_DLC_Pos              24                     /*!< Data Length Code */

/* Bit field masks: */
#define CANMSG_Msg_MOFCR_MMC_Msk              0x0000000F             /*!< Message Mode Control */
#define CANMSG_Msg_MOFCR_GDFS_Msk             0x00000100             /*!< Gateway Data Frame Selected */
#define CANMSG_Msg_MOFCR_IDC_Msk              0x00000200             /*!< Identifier Copy */
#define CANMSG_Msg_MOFCR_DLCC_Msk             0x00000400             /*!< Data Lengh Code Copy */
#define CANMSG_Msg_MOFCR_DATC_Msk             0x00000800             /*!< Data Copy */
#define CANMSG_Msg_MOFCR_RXIE_Msk             0x00010000             /*!< Receive Interrupt Enable */
#define CANMSG_Msg_MOFCR_TXIE_Msk             0x00020000             /*!< Transmit Interrupt Enable */
#define CANMSG_Msg_MOFCR_OVIE_Msk             0x00040000             /*!< Overflow Interrupt Enable */
#define CANMSG_Msg_MOFCR_FRREN_Msk            0x00100000             /*!< Foreign Remote Request Enable */
#define CANMSG_Msg_MOFCR_RMM_Msk              0x00200000             /*!< Transmit Object Remote Monitoring */
#define CANMSG_Msg_MOFCR_SDT_Msk              0x00400000             /*!< Single Data Transfer */
#define CANMSG_Msg_MOFCR_STT_Msk              0x00800000             /*!< Single Transmit Trial */
#define CANMSG_Msg_MOFCR_DLC_Msk              0x0F000000             /*!< Data Length Code */

/* Bit field enums: */
typedef enum {
  CANMSG_Msg_MOFCR_MMC_MsgObj                = 0x0,                  /*!< message object */
  CANMSG_Msg_MOFCR_MMC_RXObj                 = 0x1,                  /*!< receiver FIFO structure object */
  CANMSG_Msg_MOFCR_MMC_TXObj                 = 0x2,                  /*!< transmitter FIFO structure object */
  CANMSG_Msg_MOFCR_MMC_SlaveTXObj            = 0x3,                  /*!< transmitter FIFO structure slave object */
  CANMSG_Msg_MOFCR_MMC_SrcObj                = 0x4,                  /*!< gateway source object */
} CANMSG_Msg_MOFCR_MMC_Enum;

/*-- Msg: MOFGPR: Message Object FIFO/Gateway Pointer Register0 -----------------------------------------------*/
typedef struct {
  uint32_t BOT                    :8;                                /*!< Botom Pointer */
  uint32_t TOP                    :8;                                /*!< Top Pointer */
  uint32_t CUR                    :8;                                /*!< Current Object Pointer */
  uint32_t SEL                    :8;                                /*!< Object Select Pointer */
} _CANMSG_Msg_MOFGPR_bits;

/* Bit field positions: */
#define CANMSG_Msg_MOFGPR_BOT_Pos             0                      /*!< Botom Pointer */
#define CANMSG_Msg_MOFGPR_TOP_Pos             8                      /*!< Top Pointer */
#define CANMSG_Msg_MOFGPR_CUR_Pos             16                     /*!< Current Object Pointer */
#define CANMSG_Msg_MOFGPR_SEL_Pos             24                     /*!< Object Select Pointer */

/* Bit field masks: */
#define CANMSG_Msg_MOFGPR_BOT_Msk             0x000000FF             /*!< Botom Pointer */
#define CANMSG_Msg_MOFGPR_TOP_Msk             0x0000FF00             /*!< Top Pointer */
#define CANMSG_Msg_MOFGPR_CUR_Msk             0x00FF0000             /*!< Current Object Pointer */
#define CANMSG_Msg_MOFGPR_SEL_Msk             0xFF000000             /*!< Object Select Pointer */

/*-- Msg: MOIPR: Message Object Interrupt Pointer Register0 ---------------------------------------------------*/
typedef struct {
  uint32_t RXINP                  :4;                                /*!< Receive Interrupt Node Pointer */
  uint32_t TXINP                  :4;                                /*!< Transmit Interrupt Node Pointer */
  uint32_t MPN                    :8;                                /*!< Message Pending Number */
  uint32_t CFCVAL                 :16;                               /*!< CAN Frame Counter Value */
} _CANMSG_Msg_MOIPR_bits;

/* Bit field positions: */
#define CANMSG_Msg_MOIPR_RXINP_Pos            0                      /*!< Receive Interrupt Node Pointer */
#define CANMSG_Msg_MOIPR_TXINP_Pos            4                      /*!< Transmit Interrupt Node Pointer */
#define CANMSG_Msg_MOIPR_MPN_Pos              8                      /*!< Message Pending Number */
#define CANMSG_Msg_MOIPR_CFCVAL_Pos           16                     /*!< CAN Frame Counter Value */

/* Bit field masks: */
#define CANMSG_Msg_MOIPR_RXINP_Msk            0x0000000F             /*!< Receive Interrupt Node Pointer */
#define CANMSG_Msg_MOIPR_TXINP_Msk            0x000000F0             /*!< Transmit Interrupt Node Pointer */
#define CANMSG_Msg_MOIPR_MPN_Msk              0x0000FF00             /*!< Message Pending Number */
#define CANMSG_Msg_MOIPR_CFCVAL_Msk           0xFFFF0000             /*!< CAN Frame Counter Value */

/*-- Msg: MOAMR: Message Object Acceptance Mask Register0 -----------------------------------------------------*/
typedef struct {
  uint32_t AM                     :29;                               /*!< Acceptance Mask for Message Identifier */
  uint32_t MIDE                   :1;                                /*!< Acceptance Mask Bit for Message IDE Bit */
} _CANMSG_Msg_MOAMR_bits;

/* Bit field positions: */
#define CANMSG_Msg_MOAMR_AM_Pos               0                      /*!< Acceptance Mask for Message Identifier */
#define CANMSG_Msg_MOAMR_MIDE_Pos             29                     /*!< Acceptance Mask Bit for Message IDE Bit */

/* Bit field masks: */
#define CANMSG_Msg_MOAMR_AM_Msk               0x1FFFFFFF             /*!< Acceptance Mask for Message Identifier */
#define CANMSG_Msg_MOAMR_MIDE_Msk             0x20000000             /*!< Acceptance Mask Bit for Message IDE Bit */

/*-- Msg: MODATAL: Message Object Data Register Low0 ----------------------------------------------------------*/
typedef struct {
  uint32_t DB0                    :8;                                /*!< Data byte 0 of message object */
  uint32_t DB1                    :8;                                /*!< Data byte 1 of message object */
  uint32_t DB2                    :8;                                /*!< Data byte 2 of message object */
  uint32_t DB3                    :8;                                /*!< Data byte 3 of message object */
} _CANMSG_Msg_MODATAL_bits;

/* Bit field positions: */
#define CANMSG_Msg_MODATAL_DB0_Pos            0                      /*!< Data byte 0 of message object */
#define CANMSG_Msg_MODATAL_DB1_Pos            8                      /*!< Data byte 1 of message object */
#define CANMSG_Msg_MODATAL_DB2_Pos            16                     /*!< Data byte 2 of message object */
#define CANMSG_Msg_MODATAL_DB3_Pos            24                     /*!< Data byte 3 of message object */

/* Bit field masks: */
#define CANMSG_Msg_MODATAL_DB0_Msk            0x000000FF             /*!< Data byte 0 of message object */
#define CANMSG_Msg_MODATAL_DB1_Msk            0x0000FF00             /*!< Data byte 1 of message object */
#define CANMSG_Msg_MODATAL_DB2_Msk            0x00FF0000             /*!< Data byte 2 of message object */
#define CANMSG_Msg_MODATAL_DB3_Msk            0xFF000000             /*!< Data byte 3 of message object */

/*-- Msg: MODATAH: Message Object Data Register High0 ---------------------------------------------------------*/
typedef struct {
  uint32_t DB4                    :8;                                /*!< Data byte 4 of message object */
  uint32_t DB5                    :8;                                /*!< Data byte 5 of message object */
  uint32_t DB6                    :8;                                /*!< Data byte 6 of message object */
  uint32_t DB7                    :8;                                /*!< Data byte 7 of message object */
} _CANMSG_Msg_MODATAH_bits;

/* Bit field positions: */
#define CANMSG_Msg_MODATAH_DB4_Pos            0                      /*!< Data byte 4 of message object */
#define CANMSG_Msg_MODATAH_DB5_Pos            8                      /*!< Data byte 5 of message object */
#define CANMSG_Msg_MODATAH_DB6_Pos            16                     /*!< Data byte 6 of message object */
#define CANMSG_Msg_MODATAH_DB7_Pos            24                     /*!< Data byte 7 of message object */

/* Bit field masks: */
#define CANMSG_Msg_MODATAH_DB4_Msk            0x000000FF             /*!< Data byte 4 of message object */
#define CANMSG_Msg_MODATAH_DB5_Msk            0x0000FF00             /*!< Data byte 5 of message object */
#define CANMSG_Msg_MODATAH_DB6_Msk            0x00FF0000             /*!< Data byte 6 of message object */
#define CANMSG_Msg_MODATAH_DB7_Msk            0xFF000000             /*!< Data byte 7 of message object */

/*-- Msg: MOAR: Message Object Arbitration Register0 ----------------------------------------------------------*/
typedef struct {
  uint32_t ID                     :29;                               /*!< CAN identifier of Message Object */
  uint32_t IDE                    :1;                                /*!< Identifier Extension Bit of Messgae Object */
  uint32_t PRI                    :2;                                /*!< Priority Class */
} _CANMSG_Msg_MOAR_bits;

/* Bit field positions: */
#define CANMSG_Msg_MOAR_ID_Pos                0                      /*!< CAN identifier of Message Object */
#define CANMSG_Msg_MOAR_IDE_Pos               29                     /*!< Identifier Extension Bit of Messgae Object */
#define CANMSG_Msg_MOAR_PRI_Pos               30                     /*!< Priority Class */

/* Bit field masks: */
#define CANMSG_Msg_MOAR_ID_Msk                0x1FFFFFFF             /*!< CAN identifier of Message Object */
#define CANMSG_Msg_MOAR_IDE_Msk               0x20000000             /*!< Identifier Extension Bit of Messgae Object */
#define CANMSG_Msg_MOAR_PRI_Msk               0xC0000000             /*!< Priority Class */

/*-- Msg: MOCTR: Message Object Control Register0 -------------------------------------------------------------*/
typedef struct {
  uint32_t RESRXPND               :1;                                /*!< Reset Receive Pending */
  uint32_t RESTXPND               :1;                                /*!< Reset Transmit Pending */
  uint32_t RESRXUPD               :1;                                /*!< Reset Receive Updating */
  uint32_t RESNEWDAT              :1;                                /*!< Reset New Data */
  uint32_t RESMSGLST              :1;                                /*!< Reset Message Lost */
  uint32_t RESMSGVAL              :1;                                /*!< Reset Message Valid */
  uint32_t RESRTSEL               :1;                                /*!< Reset Receive/Transmit Selected */
  uint32_t RESRXEN                :1;                                /*!< Reset Receive Enable */
  uint32_t RESTXRQ                :1;                                /*!< Reset Transmit Request */
  uint32_t RESTXEN0               :1;                                /*!< Reset Transmit Enable 0 */
  uint32_t RESTXEN1               :1;                                /*!< Reset Transmit Enable 1 */
  uint32_t RESDIR                 :1;                                /*!< Reset Message Direction */
  uint32_t                        :4;                                /*!< RESERVED */
  uint32_t SETRXPND               :1;                                /*!< Set Receive Pending */
  uint32_t SETTXPND               :1;                                /*!< Set Transmit Pending */
  uint32_t SETRXUPD               :1;                                /*!< Set Receive Updating */
  uint32_t SETNEWDAT              :1;                                /*!< Set New Data */
  uint32_t SETMSGLST              :1;                                /*!< Set Message Lost */
  uint32_t SETMSGVAL              :1;                                /*!< Set Message Valid */
  uint32_t SETRTSEL               :1;                                /*!< Set Receive/Transmit Selected */
  uint32_t SETRXEN                :1;                                /*!< Set Receive Enable */
  uint32_t SETTXRQ                :1;                                /*!< Set Transmit Request */
  uint32_t SETTXEN0               :1;                                /*!< Set Transmit Enable 0 */
  uint32_t SETTXEN1               :1;                                /*!< Set Transmit Enable 1 */
  uint32_t SETDIR                 :1;                                /*!< Set Message Direction */
} _CANMSG_Msg_MOCTR_bits;

/* Bit field positions: */
#define CANMSG_Msg_MOCTR_RESRXPND_Pos         0                      /*!< Reset Receive Pending */
#define CANMSG_Msg_MOCTR_RESTXPND_Pos         1                      /*!< Reset Transmit Pending */
#define CANMSG_Msg_MOCTR_RESRXUPD_Pos         2                      /*!< Reset Receive Updating */
#define CANMSG_Msg_MOCTR_RESNEWDAT_Pos        3                      /*!< Reset New Data */
#define CANMSG_Msg_MOCTR_RESMSGLST_Pos        4                      /*!< Reset Message Lost */
#define CANMSG_Msg_MOCTR_RESMSGVAL_Pos        5                      /*!< Reset Message Valid */
#define CANMSG_Msg_MOCTR_RESRTSEL_Pos         6                      /*!< Reset Receive/Transmit Selected */
#define CANMSG_Msg_MOCTR_RESRXEN_Pos          7                      /*!< Reset Receive Enable */
#define CANMSG_Msg_MOCTR_RESTXRQ_Pos          8                      /*!< Reset Transmit Request */
#define CANMSG_Msg_MOCTR_RESTXEN0_Pos         9                      /*!< Reset Transmit Enable 0 */
#define CANMSG_Msg_MOCTR_RESTXEN1_Pos         10                     /*!< Reset Transmit Enable 1 */
#define CANMSG_Msg_MOCTR_RESDIR_Pos           11                     /*!< Reset Message Direction */
#define CANMSG_Msg_MOCTR_SETRXPND_Pos         16                     /*!< Set Receive Pending */
#define CANMSG_Msg_MOCTR_SETTXPND_Pos         17                     /*!< Set Transmit Pending */
#define CANMSG_Msg_MOCTR_SETRXUPD_Pos         18                     /*!< Set Receive Updating */
#define CANMSG_Msg_MOCTR_SETNEWDAT_Pos        19                     /*!< Set New Data */
#define CANMSG_Msg_MOCTR_SETMSGLST_Pos        20                     /*!< Set Message Lost */
#define CANMSG_Msg_MOCTR_SETMSGVAL_Pos        21                     /*!< Set Message Valid */
#define CANMSG_Msg_MOCTR_SETRTSEL_Pos         22                     /*!< Set Receive/Transmit Selected */
#define CANMSG_Msg_MOCTR_SETRXEN_Pos          23                     /*!< Set Receive Enable */
#define CANMSG_Msg_MOCTR_SETTXRQ_Pos          24                     /*!< Set Transmit Request */
#define CANMSG_Msg_MOCTR_SETTXEN0_Pos         25                     /*!< Set Transmit Enable 0 */
#define CANMSG_Msg_MOCTR_SETTXEN1_Pos         26                     /*!< Set Transmit Enable 1 */
#define CANMSG_Msg_MOCTR_SETDIR_Pos           27                     /*!< Set Message Direction */

/* Bit field masks: */
#define CANMSG_Msg_MOCTR_RESRXPND_Msk         0x00000001             /*!< Reset Receive Pending */
#define CANMSG_Msg_MOCTR_RESTXPND_Msk         0x00000002             /*!< Reset Transmit Pending */
#define CANMSG_Msg_MOCTR_RESRXUPD_Msk         0x00000004             /*!< Reset Receive Updating */
#define CANMSG_Msg_MOCTR_RESNEWDAT_Msk        0x00000008             /*!< Reset New Data */
#define CANMSG_Msg_MOCTR_RESMSGLST_Msk        0x00000010             /*!< Reset Message Lost */
#define CANMSG_Msg_MOCTR_RESMSGVAL_Msk        0x00000020             /*!< Reset Message Valid */
#define CANMSG_Msg_MOCTR_RESRTSEL_Msk         0x00000040             /*!< Reset Receive/Transmit Selected */
#define CANMSG_Msg_MOCTR_RESRXEN_Msk          0x00000080             /*!< Reset Receive Enable */
#define CANMSG_Msg_MOCTR_RESTXRQ_Msk          0x00000100             /*!< Reset Transmit Request */
#define CANMSG_Msg_MOCTR_RESTXEN0_Msk         0x00000200             /*!< Reset Transmit Enable 0 */
#define CANMSG_Msg_MOCTR_RESTXEN1_Msk         0x00000400             /*!< Reset Transmit Enable 1 */
#define CANMSG_Msg_MOCTR_RESDIR_Msk           0x00000800             /*!< Reset Message Direction */
#define CANMSG_Msg_MOCTR_SETRXPND_Msk         0x00010000             /*!< Set Receive Pending */
#define CANMSG_Msg_MOCTR_SETTXPND_Msk         0x00020000             /*!< Set Transmit Pending */
#define CANMSG_Msg_MOCTR_SETRXUPD_Msk         0x00040000             /*!< Set Receive Updating */
#define CANMSG_Msg_MOCTR_SETNEWDAT_Msk        0x00080000             /*!< Set New Data */
#define CANMSG_Msg_MOCTR_SETMSGLST_Msk        0x00100000             /*!< Set Message Lost */
#define CANMSG_Msg_MOCTR_SETMSGVAL_Msk        0x00200000             /*!< Set Message Valid */
#define CANMSG_Msg_MOCTR_SETRTSEL_Msk         0x00400000             /*!< Set Receive/Transmit Selected */
#define CANMSG_Msg_MOCTR_SETRXEN_Msk          0x00800000             /*!< Set Receive Enable */
#define CANMSG_Msg_MOCTR_SETTXRQ_Msk          0x01000000             /*!< Set Transmit Request */
#define CANMSG_Msg_MOCTR_SETTXEN0_Msk         0x02000000             /*!< Set Transmit Enable 0 */
#define CANMSG_Msg_MOCTR_SETTXEN1_Msk         0x04000000             /*!< Set Transmit Enable 1 */
#define CANMSG_Msg_MOCTR_SETDIR_Msk           0x08000000             /*!< Set Message Direction */

/*-- Msg: MOSTAT: Message Object Status Register 0 ------------------------------------------------------------*/
typedef struct {
  uint32_t RXPND                  :1;                                /*!< Receive Pending */
  uint32_t TXPND                  :1;                                /*!< Transmit Pending */
  uint32_t RXUPD                  :1;                                /*!< Receive Updating */
  uint32_t NEWDAT                 :1;                                /*!< New Data */
  uint32_t MSGLST                 :1;                                /*!< Message Lost */
  uint32_t MSGVAL                 :1;                                /*!< Message Valid */
  uint32_t RTSEL                  :1;                                /*!< Receive/Transmit Selected */
  uint32_t RXEN                   :1;                                /*!< Receive Enable */
  uint32_t TXRQ                   :1;                                /*!< Transmit Request */
  uint32_t TXEN0                  :1;                                /*!< Transmit Enable 0 */
  uint32_t TXEN1                  :1;                                /*!< Transmit Enable 1 */
  uint32_t DIR                    :1;                                /*!< Message Direction */
  uint32_t LIST                   :4;                                /*!< List Allocation */
  uint32_t PPREV                  :8;                                /*!< Pointer To Previous Message Object */
  uint32_t PNEXT                  :8;                                /*!< Pointer to Next Message Object */
} _CANMSG_Msg_MOSTAT_bits;

/* Bit field positions: */
#define CANMSG_Msg_MOSTAT_RXPND_Pos           0                      /*!< Receive Pending */
#define CANMSG_Msg_MOSTAT_TXPND_Pos           1                      /*!< Transmit Pending */
#define CANMSG_Msg_MOSTAT_RXUPD_Pos           2                      /*!< Receive Updating */
#define CANMSG_Msg_MOSTAT_NEWDAT_Pos          3                      /*!< New Data */
#define CANMSG_Msg_MOSTAT_MSGLST_Pos          4                      /*!< Message Lost */
#define CANMSG_Msg_MOSTAT_MSGVAL_Pos          5                      /*!< Message Valid */
#define CANMSG_Msg_MOSTAT_RTSEL_Pos           6                      /*!< Receive/Transmit Selected */
#define CANMSG_Msg_MOSTAT_RXEN_Pos            7                      /*!< Receive Enable */
#define CANMSG_Msg_MOSTAT_TXRQ_Pos            8                      /*!< Transmit Request */
#define CANMSG_Msg_MOSTAT_TXEN0_Pos           9                      /*!< Transmit Enable 0 */
#define CANMSG_Msg_MOSTAT_TXEN1_Pos           10                     /*!< Transmit Enable 1 */
#define CANMSG_Msg_MOSTAT_DIR_Pos             11                     /*!< Message Direction */
#define CANMSG_Msg_MOSTAT_LIST_Pos            12                     /*!< List Allocation */
#define CANMSG_Msg_MOSTAT_PPREV_Pos           16                     /*!< Pointer To Previous Message Object */
#define CANMSG_Msg_MOSTAT_PNEXT_Pos           24                     /*!< Pointer to Next Message Object */

/* Bit field masks: */
#define CANMSG_Msg_MOSTAT_RXPND_Msk           0x00000001             /*!< Receive Pending */
#define CANMSG_Msg_MOSTAT_TXPND_Msk           0x00000002             /*!< Transmit Pending */
#define CANMSG_Msg_MOSTAT_RXUPD_Msk           0x00000004             /*!< Receive Updating */
#define CANMSG_Msg_MOSTAT_NEWDAT_Msk          0x00000008             /*!< New Data */
#define CANMSG_Msg_MOSTAT_MSGLST_Msk          0x00000010             /*!< Message Lost */
#define CANMSG_Msg_MOSTAT_MSGVAL_Msk          0x00000020             /*!< Message Valid */
#define CANMSG_Msg_MOSTAT_RTSEL_Msk           0x00000040             /*!< Receive/Transmit Selected */
#define CANMSG_Msg_MOSTAT_RXEN_Msk            0x00000080             /*!< Receive Enable */
#define CANMSG_Msg_MOSTAT_TXRQ_Msk            0x00000100             /*!< Transmit Request */
#define CANMSG_Msg_MOSTAT_TXEN0_Msk           0x00000200             /*!< Transmit Enable 0 */
#define CANMSG_Msg_MOSTAT_TXEN1_Msk           0x00000400             /*!< Transmit Enable 1 */
#define CANMSG_Msg_MOSTAT_DIR_Msk             0x00000800             /*!< Message Direction */
#define CANMSG_Msg_MOSTAT_LIST_Msk            0x0000F000             /*!< List Allocation */
#define CANMSG_Msg_MOSTAT_PPREV_Msk           0x00FF0000             /*!< Pointer To Previous Message Object */
#define CANMSG_Msg_MOSTAT_PNEXT_Msk           0xFF000000             /*!< Pointer to Next Message Object */

//Cluster Msg:
typedef struct {
  union { 
  /*!< Message Object Function Control Register0 */
    __IO uint32_t MOFCR;                                             /*!< MOFCR : type used for word access */
    __IO _CANMSG_Msg_MOFCR_bits MOFCR_bit;                           /*!< MOFCR_bit: structure used for bit access */
  };
  union { 
  /*!< Message Object FIFO/Gateway Pointer Register0 */
    __IO uint32_t MOFGPR;                                            /*!< MOFGPR : type used for word access */
    __IO _CANMSG_Msg_MOFGPR_bits MOFGPR_bit;                         /*!< MOFGPR_bit: structure used for bit access */
  };
  union { 
  /*!< Message Object Interrupt Pointer Register0 */
    __IO uint32_t MOIPR;                                             /*!< MOIPR : type used for word access */
    __IO _CANMSG_Msg_MOIPR_bits MOIPR_bit;                           /*!< MOIPR_bit: structure used for bit access */
  };
  union { 
  /*!< Message Object Acceptance Mask Register0 */
    __IO uint32_t MOAMR;                                             /*!< MOAMR : type used for word access */
    __IO _CANMSG_Msg_MOAMR_bits MOAMR_bit;                           /*!< MOAMR_bit: structure used for bit access */
  };
  union { 
  /*!< Message Object Data Register Low0 */
    __IO uint32_t MODATAL;                                           /*!< MODATAL : type used for word access */
    __IO _CANMSG_Msg_MODATAL_bits MODATAL_bit;                       /*!< MODATAL_bit: structure used for bit access */
  };
  union { 
  /*!< Message Object Data Register High0 */
    __IO uint32_t MODATAH;                                           /*!< MODATAH : type used for word access */
    __IO _CANMSG_Msg_MODATAH_bits MODATAH_bit;                       /*!< MODATAH_bit: structure used for bit access */
  };
  union { 
  /*!< Message Object Arbitration Register0 */
    __IO uint32_t MOAR;                                              /*!< MOAR : type used for word access */
    __IO _CANMSG_Msg_MOAR_bits MOAR_bit;                             /*!< MOAR_bit: structure used for bit access */
  };
  union {
    union { 
                                                                     /*!< Message Object Control Register0 */
      __O uint32_t MOCTR;                                            /*!< MOCTR : type used for word access */
      __O _CANMSG_Msg_MOCTR_bits MOCTR_bit;                          /*!< MOCTR_bit: structure used for bit access */
    };
    union { 
                                                                     /*!< Message Object Status Register 0 */
      __I uint32_t MOSTAT;                                           /*!< MOSTAT : type used for word access */
      __I _CANMSG_Msg_MOSTAT_bits MOSTAT_bit;                        /*!< MOSTAT_bit: structure used for bit access */
    };
  };
} _CANMSG_Msg_TypeDef;
typedef struct {
  _CANMSG_Msg_TypeDef Msg[256];
} CANMSG_TypeDef;

/* --------------------  End of section using anonymous unions  ------------------- */
#if defined(__CC_ARM)
  #pragma pop
#elif defined(__ICCARM__)
  /* leave anonymous unions enabled */
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined(__TASKING__)
  #pragma warning restore
#else
  #warning Not supported compiler type
#endif


/******************************************************************************/
/*                          Peripheral memory map                             */
/******************************************************************************/
#define ADC_BASE                (0x40000000UL)
#define GPIOA_BASE              (0x40010000UL)
#define GPIOB_BASE              (0x40011000UL)
#define CAN_BASE                (0x40020000UL)
#define CANMSG_BASE             (0x40021000UL)
#define MFLASH_BASE             (0x40030000UL)
#define SIU_BASE                (0x40040000UL)
#define RCU_BASE                (0x40041000UL)
#define PMU_BASE                (0x40042000UL)
#define WDT_BASE                (0x40043000UL)
#define DMA_BASE                (0x40044000UL)
#define UART0_BASE              (0x40045000UL)
#define UART1_BASE              (0x40046000UL)
#define SPI_BASE                (0x40047000UL)
#define TMR0_BASE               (0x40048000UL)
#define TMR1_BASE               (0x40049000UL)
#define TMR2_BASE               (0x4004A000UL)
#define TMR3_BASE               (0x4004B000UL)
#define PWM0_BASE               (0x4004C000UL)
#define PWM1_BASE               (0x4004D000UL)
#define PWM2_BASE               (0x4004E000UL)
#define QEP_BASE                (0x4004F000UL)
#define I2C_BASE                (0x40050000UL)
#define ECAP0_BASE              (0x40051000UL)
#define ECAP1_BASE              (0x40052000UL)
#define ECAP2_BASE              (0x40053000UL)

/******************************************************************************/
/*                          Peripheral declaration                            */
/******************************************************************************/
#define ADC                  ((ADC_TypeDef       *) ADC_BASE)
#define GPIOA                ((GPIO_TypeDef      *) GPIOA_BASE)
#define GPIOB                ((GPIO_TypeDef      *) GPIOB_BASE)
#define CAN                  ((CAN_TypeDef       *) CAN_BASE)
#define CANMSG               ((CANMSG_TypeDef    *) CANMSG_BASE)
#define MFLASH               ((MFLASH_TypeDef    *) MFLASH_BASE)
#define SIU                  ((SIU_TypeDef       *) SIU_BASE)
#define RCU                  ((RCU_TypeDef       *) RCU_BASE)
#define PMU                  ((PMU_TypeDef       *) PMU_BASE)
#define WDT                  ((WDT_TypeDef       *) WDT_BASE)
#define DMA                  ((DMA_TypeDef       *) DMA_BASE)
#define UART0                ((UART_TypeDef      *) UART0_BASE)
#define UART1                ((UART_TypeDef      *) UART1_BASE)
#define SPI                  ((SPI_TypeDef       *) SPI_BASE)
#define TMR0                 ((TMR_TypeDef       *) TMR0_BASE)
#define TMR1                 ((TMR_TypeDef       *) TMR1_BASE)
#define TMR2                 ((TMR_TypeDef       *) TMR2_BASE)
#define TMR3                 ((TMR_TypeDef       *) TMR3_BASE)
#define PWM0                 ((PWM_TypeDef       *) PWM0_BASE)
#define PWM1                 ((PWM_TypeDef       *) PWM1_BASE)
#define PWM2                 ((PWM_TypeDef       *) PWM2_BASE)
#define QEP                  ((QEP_TypeDef       *) QEP_BASE)
#define I2C                  ((I2C_TypeDef       *) I2C_BASE)
#define ECAP0                ((ECAP_TypeDef      *) ECAP0_BASE)
#define ECAP1                ((ECAP_TypeDef      *) ECAP1_BASE)
#define ECAP2                ((ECAP_TypeDef      *) ECAP2_BASE)

#ifdef __cplusplus
}
#endif

#endif /* __K1921VK035_H */

/************************** (C) COPYRIGHT 2018 NIIET ***************************
*
* END OF FILE K1921VK035.h */
