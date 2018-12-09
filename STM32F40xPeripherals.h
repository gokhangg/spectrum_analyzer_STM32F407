/*
 * Project: Hardware driver register file for STM32F4XX microcontrollers
 * Author: Gokhan Gunay, ghngunay@gmail.com
 * Copyright: (C) 2014 by Gokhan Gunay
 * License: GNU GPL v3 (see License.txt)
 */

#include "stm32f4xx.h"

#ifndef __STM32F40xPeripherals
#define __STM32F40xPeripherals
/********************************* FLASH CONTROL REGISTER DEFINITION REGION *********************************/
typedef volatile struct
{
	
	/*!< FLASH access control register, Address offset: 0x00 */
	union
	{
		volatile struct
		{
			unsigned LATENCY :3;
			unsigned RESERVED :5;
			unsigned PRFTEN :1;
			unsigned ICEN :1;
			unsigned DCEN :1;
			unsigned ICRST :1;
			unsigned DCRST :1;
		} acr;
		volatile uint32_t ACR;
	};

	volatile uint32_t KEYR; /*!< FLASH key register,            Address offset: 0x04 */
	volatile uint32_t OPTKEYR; /*!< FLASH option key register,     Address offset: 0x08 */
	
	/*!< FLASH status register,         Address offset: 0x0C */
	union
	{
		volatile struct
		{
			unsigned EOP :1;
			unsigned OPERR :1;
			unsigned RESERVED :2;
			unsigned WRPERR :1;
			unsigned PGAERR :1;
			unsigned PGPERR :1;
			unsigned PGSERR :1;
			unsigned RESERVED2 :8;
			unsigned BSY :1;
		} sr;
		volatile uint32_t SR;
	};
	/*!< FLASH control register,        Address offset: 0x10 */
	union
	{
		volatile struct
		{
			unsigned PG :1;
			unsigned SER :1;
			unsigned MER :1;
			unsigned SNB :4;
			unsigned RESERVED :1;
			unsigned PSIZE :2;
			unsigned RESERVED2 :6;
			unsigned START :1;
			unsigned RESERVED3 :7;
			unsigned EOPIE :1;
			unsigned ERRIE :1;
			unsigned RESERVED4 :5;
			unsigned LOCK :1;
		} cr;
		volatile uint32_t CR;
	};
	/*!< FLASH option control register, Address offset: 0x14 */
	union
	{
		volatile struct
		{
			unsigned OPTLOCK :1;
			unsigned OPTSTRT :1;
			unsigned BOR_LEV :2;
			unsigned RESERVED :1;
			unsigned USER :3;
			unsigned RDP :8;
			unsigned nWRP :12;
		} optcr;
		volatile uint32_t OPTCR;
	};
} FLASH_Type;

#undef FLASH
#define FLASH              ((FLASH_Type *) FLASH_R_BASE)

/********************************* CRC UNIT REGISTER DEFINITION REGION *********************************/
typedef volatile struct
{
	volatile uint32_t DR; /*!< CRC Data register,             Address offset: 0x00 */
	volatile uint8_t IDR; /*!< CRC Independent data register, Address offset: 0x04 */
	volatile uint8_t RESERVED0; /*!< Reserved, 0x05                                      */
	volatile uint16_t RESERVED1; /*!< Reserved, 0x06                                      */
	
	/*!< CRC Control register,          Address offset: 0x08 */
	union
	{
		volatile struct
		{
			unsigned RESET :1;
		} cr;
		volatile uint32_t CR;
	};
} CRC_Type;

#undef CRC
#define CRC                 ((CRC_Type *) CRC_BASE)

/********************************* POWER UNIT REGISTER DEFINITION REGION *********************************/
typedef volatile struct
{
	/*!< PWR power control register,        Address offset: 0x00 */
	union
	{
		volatile struct
		{
			unsigned LPDS :1;
			unsigned PDDS :1;
			unsigned CWUF :1;
			unsigned CSBF :1;
			unsigned PVDE :1;
			unsigned PLS :3;
			unsigned DBP :1;
			unsigned FPDS :1;
			unsigned RESERVED :4;
			unsigned VOS :1;
		} cr;
		volatile uint32_t CR;
	};
	/*!< PWR power control/status register, Address offset: 0x04 */
	union
	{
		volatile struct
		{
			unsigned LPDS :1;
			unsigned SBF :1;
			unsigned PVDO :1;
			unsigned BRR :1;
			unsigned RESERVED :4;
			unsigned EWUP :1;
			unsigned BRE :1;
			unsigned RESERVED2 :4;
			unsigned VOSRDY :1;
		} csr;
		volatile uint32_t CSR;
	};
} PWR_Type;

#undef PWR
#define PWR                 ((PWR_Type *) PWR_BASE)

/********************************* RCC REGISTER DEFINITION REGION *********************************/
typedef volatile struct
{
	/*!< RCC clock control register,                                  Address offset: 0x00 */
	union
	{
		volatile struct
		{
			unsigned HSION :1;
			unsigned HSIRDY :1;
			unsigned RESERVED :1;
			unsigned HSITRIM :5;
			unsigned HSICAL :8;
			unsigned HSEON :1;
			unsigned HSERDY :1;
			unsigned HSEBYP :1;
			unsigned CSSON :1;
			unsigned RESERVED2 :4;
			unsigned PLLON :1;
			unsigned PLLRDY :1;
			unsigned PLL2SON :1;
			unsigned PLL2SRDY :1;
		} cr;
		volatile uint32_t CR;
	};
	/*!< RCC PLL configuration register,                              Address offset: 0x04 */
	union
	{
		volatile struct
		{
			unsigned PLLM :6;
			unsigned PLLN :9;
			unsigned RESERVED :1;
			unsigned PLLP :2;
			unsigned RESERVED1 :4;
			unsigned PLLSRC :1;
			unsigned RESERVED2 :1;
			unsigned PLLQ :4;
			unsigned RESERVED3 :4;
		} pllcfgr;
		volatile uint32_t PLLCFGR;
	};
	/*!< RCC clock configuration register,                            Address offset: 0x08 */
	union
	{
		volatile struct
		{
			unsigned SW :2;
			unsigned SWS :2;
			unsigned HPRE :4;
			unsigned RESERVED :2;
			unsigned PPRE1 :3;
			unsigned PPRE2 :3;
			unsigned RTCPRE :5;
			unsigned MCO1 :2;
			unsigned I2SSRC :1;
			unsigned MCO1PRE :3;
			unsigned MCO2PRE :3;
			unsigned MCO2 :2;
		} cfgr;
		volatile uint32_t CFGR;
	};
	/*!< RCC clock interrupt register,                                Address offset: 0x0C */
	union
	{
		volatile struct
		{
			unsigned LSIRDYF :1;
			unsigned LSERDYF :1;
			unsigned HSIRDYF :1;
			unsigned HSERDYF :1;
			unsigned PLLRDYF :1;
			unsigned PLL2SRDYF :1;
			unsigned RESERVED :1;
			unsigned CSSF :1;
			unsigned LSIRDYIE :1;
			unsigned LSERDYIE :1;
			unsigned HSIRDYIE :1;
			unsigned HSERDYIE :1;
			unsigned PLLRDYIE :1;
			unsigned PLL2SRDYIE :1;
			unsigned RESERVED2 :2;
			unsigned LSIRDYC :1;
			unsigned LSERDYC :1;
			unsigned HSIRDYC :1;
			unsigned HSERDYC :1;
			unsigned PLLRDYC :1;
			unsigned PLL2SRDYC :1;
			unsigned RESERVED3 :1;
			unsigned CSSC :1;
		} cir;
		volatile uint32_t CIR;
	};
	/*!< RCC AHB1 peripheral reset register,                          Address offset: 0x10 */
	union
	{
		volatile struct
		{
			unsigned GPIOARST :1;
			unsigned GPIOBRST :1;
			unsigned GPIOCRST :1;
			unsigned GPIODRST :1;
			unsigned GPIOERST :1;
			unsigned GPIOFRST :1;
			unsigned GPIOGRST :1;
			unsigned GPIOHRST :1;
			unsigned GPIOIRST :1;
			unsigned RESERVED :3;
			unsigned CRCRST :1;
			unsigned RESERVED2 :8;
			unsigned DMA1RST :1;
			unsigned DMA2RST :1;
			unsigned RESERVED3 :2;
			unsigned ETHMACRST :1;
			unsigned RESERVED4 :3;
			unsigned OTGHSRST :1;
			unsigned RESERVED5 :2;
		} ahb1rstr;
		volatile uint32_t AHB1RSTR;
	};
	/*!< RCC AHB2 peripheral reset register,                          Address offset: 0x14 */
	union
	{
		volatile struct
		{
			unsigned DCMIRST :1;
			unsigned RESERVED :3;
			unsigned CRYPTRST :1;
			unsigned HASHRST :1;
			unsigned RNGRST :1;
			unsigned OTGFSRTS :1;
		} ahb2rstr;
		volatile uint32_t AHB2RSTR;
	};
	/*!< RCC AHB3 peripheral reset register,                          Address offset: 0x18 */
	union
	{
		volatile struct
		{
			unsigned FSMCRST :1;
		} ahb3rstr;
		volatile uint32_t AHB3RSTR;
	};
	uint32_t RESERVED0; /*!< Reserved, 0x1C                                                                    */
	/*!< RCC APB1 peripheral reset register,                          Address offset: 0x20 */
	union
	{
		volatile struct
		{
			unsigned TIM2RST :1;
			unsigned TIM3RST :1;
			unsigned TIM4RST :1;
			unsigned TIM5RST :1;
			unsigned TIM6RST :1;
			unsigned TIM7RST :1;
			unsigned TIM12RST :1;
			unsigned TIM13RST :1;
			unsigned TIM14RST :1;
			unsigned RESERVED :2;
			unsigned WWDGRST :1;
			unsigned RESERVED2 :2;
			unsigned SPI2RST :1;
			unsigned SPI3RST :1;
			unsigned RESERVED3 :1;
			unsigned USART2RST :1;
			unsigned USART3RST :1;
			unsigned UART4RST :1;
			unsigned UART5RST :1;
			unsigned I2C1RST :1;
			unsigned I2C2RST :1;
			unsigned I2C3RST :1;
			unsigned RESERVED4 :1;
			unsigned CAN1RST :1;
			unsigned CAN2RST :1;
			unsigned RESERVED5 :1;
			unsigned PWRRST :1;
			unsigned DACRST :1;
		} apb1rstr;
		volatile uint32_t APB1RSTR;
	};
	/*!< RCC APB2 peripheral reset register,                          Address offset: 0x24 */
	union
	{
		volatile struct
		{
			unsigned TIM1RST :1;
			unsigned TIM8RST :1;
			unsigned RESERVED :2;
			unsigned USART1RST :1;
			unsigned USART6RST :1;
			unsigned RESERVED2 :2;
			unsigned ADCRST :1;
			unsigned RESERVED3 :2;
			unsigned SDIORST :1;
			unsigned SPI1RST :1;
			unsigned RESERVED4 :1;
			unsigned SYSCFGRRST :1;
			unsigned RESERVED5 :1;
			unsigned TIM9RST :1;
			unsigned TIM10RST :1;
			unsigned TIM11RST :1;
		} apb2rstr;
		volatile uint32_t APB2RSTR;
	};
	uint32_t RESERVED1[2]; /*!< Reserved, 0x28-0x2C                                                               */
	/*!< RCC AHB1 peripheral clock register,                          Address offset: 0x30 */
	union
	{
		volatile struct
		{
			unsigned GPIOAEN :1;
			unsigned GPIOBEN :1;
			unsigned GPIOCEN :1;
			unsigned GPIODEN :1;
			unsigned GPIOEEN :1;
			unsigned GPIOFEN :1;
			unsigned GPIOGEN :1;
			unsigned GPIOHEN :1;
			unsigned GPIOIEN :1;
			unsigned RESERVED :2;
			unsigned CRCEN :1;
			unsigned RESERVED2 :5;
			unsigned BKPSRAMEN :1;
			unsigned RESERVED3 :2;
			unsigned CCMDATARAMEN :1;
			unsigned DMA1EN :1;
			unsigned DMA2EN :1;
			unsigned RESERVED4 :2;
			unsigned ETHMACEN :1;
			unsigned ETHMACTXEN :1;
			unsigned ETHMACRXEN :1;
			unsigned ETHMACPTPEN :1;
			unsigned OTGHSEN :1;
			unsigned OTGHSULPIEN :1;
		} ahb1enr;
		volatile uint32_t AHB1ENR;
	};

	/*!< RCC AHB2 peripheral clock register,                          Address offset: 0x34 */
	union
	{
		volatile struct
		{
			unsigned DCMIEN :1;
			unsigned RESERVED :3;
			unsigned CRYPEN :1;
			unsigned HASHEN :1;
			unsigned RNGEN :1;
			unsigned OTGFSEN :1;
		} ahb2enr;
		volatile uint32_t AHB2ENR;
	};
	/*!< RCC AHB3 peripheral clock register,                          Address offset: 0x38 */
	union
	{
		volatile struct
		{
			unsigned FSMCEN :1;
		} ahb3enr;
		volatile uint32_t AHB3ENR;
	};
	uint32_t RESERVED2; /*!< Reserved, 0x3C                                                                    */
	/*!< RCC APB1 peripheral clock enable register,                   Address offset: 0x40 */
	union
	{
		volatile struct
		{
			unsigned TIM2EN :1;
			unsigned TIM3EN :1;
			unsigned TIM4EN :1;
			unsigned TIM5EN :1;
			unsigned TIM6EN :1;
			unsigned TIM7EN :1;
			unsigned TIM12EN :1;
			unsigned TIM13EN :1;
			unsigned TIM14EN :1;
			unsigned RESERVED :2;
			unsigned WWDGEN :1;
			unsigned RESERVED2 :2;
			unsigned SPI2EN :1;
			unsigned SPI3EN :1;
			unsigned RESERVED3 :1;
			unsigned USART2EN :1;
			unsigned USART3EN :1;
			unsigned UART4EN :1;
			unsigned UART5EN :1;
			unsigned I2C1EN :1;
			unsigned I2C2EN :1;
			unsigned I2C3EN :1;
			unsigned RESERVED4 :1;
			unsigned CAN1EN :1;
			unsigned CAN2EN :1;
			unsigned RESERVED5 :1;
			unsigned PWREN :1;
			unsigned DACEN :1;
		} apb1enr;
		volatile uint32_t APB1ENR;
	};
	/*!< RCC APB2 peripheral clock enable register,                   Address offset: 0x44 */
	union
	{
		volatile struct
		{
			unsigned TIM1EN :1;
			unsigned TIM8EN :1;
			unsigned RESERVED :2;
			unsigned USART1EN :1;
			unsigned USART6EN :1;
			unsigned RESERVED2 :2;
			unsigned ADCEN :1;
			unsigned RESERVED3 :2;
			unsigned SDIOEN :1;
			unsigned SPI1EN :1;
			unsigned RESERVED4 :1;
			unsigned SYSCFGREN :1;
			unsigned RESERVED5 :1;
			unsigned TIM9EN :1;
			unsigned TIM10EN :1;
			unsigned TIM11EN :1;
		} apb2enr;
		volatile uint32_t APB2ENR;
	};
	uint32_t RESERVED3[2]; /*!< Reserved, 0x48-0x4C                                                               */
	/*!< RCC AHB1 peripheral clock enable in low power mode register, Address offset: 0x50 */
	union
	{
		volatile struct
		{
			unsigned GPIOALPEN :1;
			unsigned GPIOBLPEN :1;
			unsigned GPIOCLPEN :1;
			unsigned GPIODLPEN :1;
			unsigned GPIOELPEN :1;
			unsigned GPIOFLPEN :1;
			unsigned GPIOGLPEN :1;
			unsigned GPIOHLPEN :1;
			unsigned GPIOILPEN :1;
			unsigned RESERVED :2;
			unsigned CRCLPEN :1;
			unsigned RESERVED2 :5;
			unsigned BKPSRAMLPEN :1;
			unsigned RESERVED3 :2;
			unsigned CCMDATARAMLPEN :1;
			unsigned DMA1LPEN :1;
			unsigned DMA2LPEN :1;
			unsigned RESERVED4 :2;
			unsigned ETHMACLPEN :1;
			unsigned ETHMACTXLPEN :1;
			unsigned ETHMACRXLPEN :1;
			unsigned ETHMACPTPLPEN :1;
			unsigned OTGHSLPEN :1;
			unsigned OTGHSULPILPEN :1;
		} ahb1lpenr;
		volatile uint32_t AHB1LPENR;
	};
	/*!< RCC AHB2 peripheral clock enable in low power mode register, Address offset: 0x54 */
	union
	{
		volatile struct
		{
			unsigned DCMILPEN :1;
			unsigned RESERVED :3;
			unsigned CRYPLPEN :1;
			unsigned HASHLPEN :1;
			unsigned RNGLPEN :1;
			unsigned OTGFSLPEN :1;
		} ahb2lpenr;
		volatile uint32_t AHB2LPENR;
	};
	/*!< RCC AHB3 peripheral clock enable in low power mode register, Address offset: 0x58 */
	union
	{
		volatile struct
		{
			unsigned FSMCLPEN :1;
		} ahb3lpenr;
		volatile uint32_t AHB3LPENR;
	};
	uint32_t RESERVED4; /*!< Reserved, 0x5C                                                                    */
	/*!< RCC APB1 peripheral clock enable in low power mode register, Address offset: 0x60 */
	union
	{
		volatile struct
		{
			unsigned TIM2LPEN :1;
			unsigned TIM3LPEN :1;
			unsigned TIM4LPEN :1;
			unsigned TIM5LPEN :1;
			unsigned TIM6LPEN :1;
			unsigned TIM7LPEN :1;
			unsigned TIM12LPEN :1;
			unsigned TIM13LPEN :1;
			unsigned TIM14LPEN :1;
			unsigned RESERVED :2;
			unsigned WWDGLPEN :1;
			unsigned RESERVED2 :2;
			unsigned SPI2LPEN :1;
			unsigned SPI3LPEN :1;
			unsigned RESERVED3 :1;
			unsigned USART2LPEN :1;
			unsigned USART3LPEN :1;
			unsigned UART4LPEN :1;
			unsigned UART5LPEN :1;
			unsigned I2C1LPEN :1;
			unsigned I2C2LPEN :1;
			unsigned I2C3LPEN :1;
			unsigned RESERVED4 :1;
			unsigned CAN1LPEN :1;
			unsigned CAN2LPEN :1;
			unsigned RESERVED5 :1;
			unsigned PWRLPEN :1;
			unsigned DACLPEN :1;
		} apb1lpenr;
		volatile uint32_t APB1LPENR;
	};

	/*!< RCC APB2 peripheral clock enable in low power mode register, Address offset: 0x64 */
	union
	{
		volatile struct
		{
			unsigned TIM1LPEN :1;
			unsigned TIM8LPEN :1;
			unsigned RESERVED :2;
			unsigned USART1LPEN :1;
			unsigned USART6LPEN :1;
			unsigned RESERVED2 :2;
			unsigned ADCLPEN :1;
			unsigned RESERVED3 :2;
			unsigned SDIOLPEN :1;
			unsigned SPI1LPEN :1;
			unsigned RESERVED4 :1;
			unsigned SYSCFGRLPEN :1;
			unsigned RESERVED5 :1;
			unsigned TIM9LPEN :1;
			unsigned TIM10LPEN :1;
			unsigned TIM11LPEN :1;
		} apb2lpenr;
		volatile uint32_t APB2LPENR;
	};
	uint32_t RESERVED5[2]; /*!< Reserved, 0x68-0x6C                                                               */
	/*!< RCC Backup domain control register,                          Address offset: 0x70 */
	union
	{
		volatile struct
		{
			unsigned LSEON :1;
			unsigned LSERDY :1;
			unsigned LSEBYP :1;
			unsigned RESERVED :5;
			unsigned RTCSEL :2;
			unsigned RESERVED2 :5;
			unsigned RTCEN :1;
			unsigned BDRST :1;
		} bdcr;
		volatile uint32_t BDCR;
	};
	/*!< RCC clock control & status register,                         Address offset: 0x74 */
	union
	{
		volatile struct
		{
			unsigned LSION :1;
			unsigned LSIRDY :1;
			unsigned RESERVED :22;
			unsigned RMVF :1;
			unsigned BORRSTF :1;
			unsigned PINRSTF :1;
			unsigned PORRSTF :1;
			unsigned SFTRSTF :1;
			unsigned IWDGRSTF :1;
			unsigned WWDGRSTF :1;
			unsigned LPWRRSTF :1;
		} csr;
		volatile uint32_t CSR;
	};
	uint32_t RESERVED6[2]; /*!< Reserved, 0x78-0x7C                                                               */
	/*!< RCC spread spectrum clock generation register,               Address offset: 0x80 */
	union
	{
		volatile struct
		{
			unsigned MODPER :12;
			unsigned INCSTEP :15;
			unsigned RESERVED :2;
			unsigned SPREADSEL :1;
			unsigned SSGEN :1;
		} sscgr;
		volatile uint32_t SSCGR;
	};
	/*!< RCC PLLI2S configuration register,                           Address offset: 0x84 */
	union
	{
		volatile struct
		{
			unsigned RESERVED :6;
			unsigned PLLI2SN :9;
			unsigned RESERVED2 :13;
			unsigned PLLI2SR :3;
		} plli2scfgr;
		volatile uint32_t PLL2I2SCFGR;
	};
	volatile uint32_t RESERVED7; /*!< RCC spread spectrum clock generation register,               Address offset: 0x88 */
	volatile uint32_t DCKCFGR; /*!< RCC PLLI2S configuration register,                           Address offset: 0x8c */
} RCC_Type;

#undef RCC
#define RCC      ((RCC_Type *) RCC_BASE)

/********************************* GPIO REGISTER DEFINITION REGION *********************************/
typedef volatile struct
{
	/*!< GPIO port mode register,               Address offset: 0x00      */
	union
	{
		volatile struct
		{
			unsigned MODER0 :2;
			unsigned MODER1 :2;
			unsigned MODER2 :2;
			unsigned MODER3 :2;
			unsigned MODER4 :2;
			unsigned MODER5 :2;
			unsigned MODER6 :2;
			unsigned MODER7 :2;
			unsigned MODER8 :2;
			unsigned MODER9 :2;
			unsigned MODER10 :2;
			unsigned MODER11 :2;
			unsigned MODER12 :2;
			unsigned MODER13 :2;
			unsigned MODER14 :2;
			unsigned MODER15 :2;
		} moder;
		volatile uint32_t MODER;
	};

	/*!< GPIO port output type register,        Address offset: 0x04      */
	union
	{
		volatile struct
		{
			unsigned OT0 :1;
			unsigned OT1 :1;
			unsigned OT2 :1;
			unsigned OT3 :1;
			unsigned OT4 :1;
			unsigned OT5 :1;
			unsigned OT6 :1;
			unsigned OT7 :1;
			unsigned OT8 :1;
			unsigned OT9 :1;
			unsigned OT10 :1;
			unsigned OT11 :1;
			unsigned OT12 :1;
			unsigned OT13 :1;
			unsigned OT14 :1;
			unsigned OT15 :1;
		} otyper;
		volatile uint32_t OTYPER;
	};

	/*!< GPIO port output speed register,       Address offset: 0x08      */
	union
	{
		volatile struct
		{
			unsigned OSPEEDR0 :2;
			unsigned OSPEEDR1 :2;
			unsigned OSPEEDR2 :2;
			unsigned OSPEEDR3 :2;
			unsigned OSPEEDR4 :2;
			unsigned OSPEEDR5 :2;
			unsigned OSPEEDR6 :2;
			unsigned OSPEEDR7 :2;
			unsigned OSPEEDR8 :2;
			unsigned OSPEEDR9 :2;
			unsigned OSPEEDR10 :2;
			unsigned OSPEEDR11 :2;
			unsigned OSPEEDR12 :2;
			unsigned OSPEEDR13 :2;
			unsigned OSPEEDR14 :2;
			unsigned OSPEEDR15 :2;
		} speedr;
		volatile uint32_t SPEEDR;
	};

	/*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
	union
	{
		volatile struct
		{
			unsigned PUPDR0 :2;
			unsigned PUPDR1 :2;
			unsigned PUPDR2 :2;
			unsigned PUPDR3 :2;
			unsigned PUPDR4 :2;
			unsigned PUPDR5 :2;
			unsigned PUPDR6 :2;
			unsigned PUPDR7 :2;
			unsigned PUPDR8 :2;
			unsigned PUPDR9 :2;
			unsigned PUPDR10 :2;
			unsigned PUPDR11 :2;
			unsigned PUPDR12 :2;
			unsigned PUPDR13 :2;
			unsigned PUPDR14 :2;
			unsigned PUPDR15 :2;
		} pupdr;
		volatile uint32_t PUPDR;
	};
	/*!< GPIO port input data register,         Address offset: 0x10      */
	union
	{
		volatile struct
		{
			unsigned IDR0 :1;
			unsigned IDR1 :1;
			unsigned IDR2 :1;
			unsigned IDR3 :1;
			unsigned IDR4 :1;
			unsigned IDR5 :1;
			unsigned IDR6 :1;
			unsigned IDR7 :1;
			unsigned IDR8 :1;
			unsigned IDR9 :1;
			unsigned IDR10 :1;
			unsigned IDR11 :1;
			unsigned IDR12 :1;
			unsigned IDR13 :1;
			unsigned IDR14 :1;
			unsigned IDR15 :1;
		} idr;
		volatile uint32_t IDR;
	};

	/*!< GPIO port output data register,        Address offset: 0x14      */
	union
	{
		volatile struct
		{
			unsigned ODR0 :1;
			unsigned ODR1 :1;
			unsigned ODR2 :1;
			unsigned ODR3 :1;
			unsigned ODR4 :1;
			unsigned ODR5 :1;
			unsigned ODR6 :1;
			unsigned ODR7 :1;
			unsigned ODR8 :1;
			unsigned ODR9 :1;
			unsigned ODR10 :1;
			unsigned ODR11 :1;
			unsigned ODR12 :1;
			unsigned ODR13 :1;
			unsigned ODR14 :1;
			unsigned ODR15 :1;
		} odr;
		volatile uint32_t ODR;
	};

	/*!< GPIO port bit set/reset low register,  Address offset: 0x18      */
	union
	{
		volatile struct
		{
			unsigned BS0 :1;
			unsigned BS1 :1;
			unsigned BS2 :1;
			unsigned BS3 :1;
			unsigned BS4 :1;
			unsigned BS5 :1;
			unsigned BS6 :1;
			unsigned BS7 :1;
			unsigned BS8 :1;
			unsigned BS9 :1;
			unsigned BS10 :1;
			unsigned BS11 :1;
			unsigned BS12 :1;
			unsigned BS13 :1;
			unsigned BS14 :1;
			unsigned BS15 :1;
			unsigned BR0 :1;
			unsigned BR1 :1;
			unsigned BR2 :1;
			unsigned BR3 :1;
			unsigned BR4 :1;
			unsigned BR5 :1;
			unsigned BR6 :1;
			unsigned BR7 :1;
			unsigned BR8 :1;
			unsigned BR9 :1;
			unsigned BR10 :1;
			unsigned BR11 :1;
			unsigned BR12 :1;
			unsigned BR13 :1;
			unsigned BR14 :1;
			unsigned BR15 :1;
		} bsrr;
		volatile uint32_t BSRR;
	};

	/*!< GPIO port configuration lock register, Address offset: 0x1C      */
	union
	{
		volatile struct
		{
			unsigned LCK0 :1;
			unsigned LCK1 :1;
			unsigned LCK2 :1;
			unsigned LCK3 :1;
			unsigned LCK4 :1;
			unsigned LCK5 :1;
			unsigned LCK6 :1;
			unsigned LCK7 :1;
			unsigned LCK8 :1;
			unsigned LCK9 :1;
			unsigned LCK10 :1;
			unsigned LCK11 :1;
			unsigned LCK12 :1;
			unsigned LCK13 :1;
			unsigned LCK14 :1;
			unsigned LCK15 :1;
			unsigned LCKK :1;
		} lckr;
		volatile uint32_t LCKR;
	};
	/*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
	union
	{
		volatile struct
		{
			unsigned AFRL0 :4;
			unsigned AFRL1 :4;
			unsigned AFRL2 :4;
			unsigned AFRL3 :4;
			unsigned AFRL4 :4;
			unsigned AFRL5 :4;
			unsigned AFRL6 :4;
			unsigned AFRL7 :4;
		} afrl;
		volatile uint32_t AFRL;
	};
	union
	{
		volatile struct
		{
			unsigned AFRH8 :4;
			unsigned AFRH9 :4;
			unsigned AFRH10 :4;
			unsigned AFRH11 :4;
			unsigned AFRH12 :4;
			unsigned AFRH13 :4;
			unsigned AFRH14 :4;
			unsigned AFRH15 :4;
		} afrh;
		volatile uint32_t AFRH;
	};
	
} GPIO_Type;

#undef PORTA
#undef PORTB
#undef PORTC
#undef PORTD
#undef PORTE
#undef PORTF
#undef PORTG
#undef PORTH
#undef PORTI
#define PORTA ((GPIO_Type*)GPIOA_BASE)
#define PORTB ((GPIO_Type*)GPIOB_BASE)
#define PORTC ((GPIO_Type*)GPIOC_BASE)
#define PORTD ((GPIO_Type*)GPIOD_BASE)
#define PORTE ((GPIO_Type*)GPIOE_BASE)
#define PORTF ((GPIO_Type*)GPIOF_BASE)
#define PORTG ((GPIO_Type*)GPIOG_BASE)
#define PORTH ((GPIO_Type*)GPIOH_BASE)
#define PORTI ((GPIO_Type*)GPIOI_BASE)

/********************************* SYSCFG REGISTER DEFINITION REGION *********************************/
typedef volatile struct
{
	/*!< SYSCFG memory remap register,                      Address offset: 0x00      */
	union
	{
		volatile struct
		{
			unsigned MEM_MODE :2;
		} memrmp;
		volatile uint32_t MEMRMP;
	};

	/*!< SYSCFG peripheral mode configuration register,     Address offset: 0x04      */
	union
	{
		volatile struct
		{
			unsigned RESERVED :23;
			unsigned MII_RMII_SEL :1;
		} pmc;
		volatile uint32_t PMC;
	};
	/*!< SYSCFG external interrupt configuration registers, Address offset: 0x08-0x14 */
	union
	{
		volatile struct
		{
			unsigned EXTI0 :4;
			unsigned EXTI1 :4;
			unsigned EXTI2 :4;
			unsigned EXTI3 :4;
		} exticr1;
		volatile uint32_t EXTICR1;
	};
	union
	{
		volatile struct
		{
			unsigned EXTI4 :4;
			unsigned EXTI5 :4;
			unsigned EXTI6 :4;
			unsigned EXTI7 :4;
		} exticr2;
		volatile uint32_t EXTICR2;
	};
	union
	{
		volatile struct
		{
			unsigned EXTI8 :4;
			unsigned EXTI9 :4;
			unsigned EXTI10 :4;
			unsigned EXTI11 :4;
		} exticr3;
		volatile uint32_t EXTICR3;
	};
	union
	{
		volatile struct
		{
			unsigned EXTI12 :4;
			unsigned EXTI13 :4;
			unsigned EXTI14 :4;
			unsigned EXTI15 :4;
		} exticr4;
		volatile uint32_t EXTICR4;
	};

	volatile uint32_t RESERVED[2]; /*!< Reserved, 0x18-0x1C                                                          */
	
	/*!< SYSCFG Compensation cell control register,         Address offset: 0x20      */
	union
	{
		volatile struct
		{
			unsigned CM_PD :4;
			unsigned RESERVED :7;
			unsigned READY :4;
		} cmpcr;
		volatile uint32_t CMPCR;
	};
} SYSCFG_Type;

#undef SYSCFG
#define SYSCFG              ((SYSCFG_Type *) SYSCFG_BASE)

/********************************* DMA REGISTER DEFINITION REGION *********************************/

typedef volatile struct
{
	/*!< DMA stream x configuration register      */
	union
	{
		volatile struct
		{
			unsigned EN :1;
			unsigned DMEIE :1;
			unsigned TEIE :1;
			unsigned HTIE :1;
			unsigned TCIE :1;
			unsigned PFCTRL :1;
			unsigned DIR :2;
			unsigned CIRC :1;
			unsigned PINC :1;
			unsigned MINC :1;
			unsigned PSIZE :2;
			unsigned MSIZE :2;
			unsigned PINCOS :1;
			unsigned PL :2;
			unsigned DBM :1;
			unsigned CT :1;
			unsigned RESERVED :1;
			unsigned PBURST :2;
			unsigned MBURST :2;
			unsigned CHSEL :3;
		} cr;
		volatile uint32_t CR;
	};
	volatile uint32_t NDTR; /*!< DMA stream x number of data register     */
	volatile uint32_t PAR; /*!< DMA stream x peripheral address register */
	volatile uint32_t M0AR; /*!< DMA stream x memory 0 address register   */
	volatile uint32_t M1AR; /*!< DMA stream x memory 1 address register   */
	/*!< DMA stream x FIFO control register       */
	union
	{
		volatile struct
		{
			unsigned FTH :2;
			unsigned DMDIS :1;
			unsigned FS :2;
			unsigned RESERVED :1;
			unsigned FEIE :1;
		} fcr;
		volatile uint32_t FCR;
	};
} DMA_Stream_Type;

typedef volatile struct
{
	/*!< DMA low interrupt status register,      Address offset: 0x00 */
	union
	{
		volatile struct
		{
			unsigned FEIF0 :1;
			unsigned RESERVED :1;
			unsigned DMEIF0 :1;
			unsigned TEIF0 :1;
			unsigned HTIF0 :1;
			unsigned TCIF0 :1;
			unsigned FEIF1 :1;
			unsigned RESERVED2 :1;
			unsigned DMEIF1 :1;
			unsigned TEIF1 :1;
			unsigned HTIF1 :1;
			unsigned TCIF1 :1;
			unsigned RESERVED3 :4;
			unsigned FEIF2 :1;
			unsigned RESERVED4 :1;
			unsigned DMEIF2 :1;
			unsigned TEIF2 :1;
			unsigned HTIF2 :1;
			unsigned TCIF2 :1;
			unsigned FEIF3 :1;
			unsigned RESERVED5 :1;
			unsigned DMEIF3 :1;
			unsigned TEIF3 :1;
			unsigned HTIF3 :1;
			unsigned TCIF3 :1;
		} lisr;
		volatile uint32_t LISR;
	};
	/*!< DMA high interrupt status register,     Address offset: 0x04 */
	union
	{
		volatile struct
		{
			unsigned FEIF4 :1;
			unsigned RESERVED :1;
			unsigned DMEIF4 :1;
			unsigned TEIF4 :1;
			unsigned HTIF4 :1;
			unsigned TCIF4 :1;
			unsigned FEIF5 :1;
			unsigned RESERVED2 :1;
			unsigned DMEIF5 :1;
			unsigned TEIF5 :1;
			unsigned HTIF5 :1;
			unsigned TCIF5 :1;
			unsigned RESERVED3 :4;
			unsigned FEIF6 :1;
			unsigned RESERVED4 :1;
			unsigned DMEIF6 :1;
			unsigned TEIF6 :1;
			unsigned HTIF6 :1;
			unsigned TCIF6 :1;
			unsigned FEIF7 :1;
			unsigned RESERVED5 :1;
			unsigned DMEIF7 :1;
			unsigned TEIF7 :1;
			unsigned HTIF7 :1;
			unsigned TCIF7 :1;
		} hisr;
		volatile uint32_t HISR;
	};
	/*!< DMA low interrupt flag clear register,  Address offset: 0x08 */
	union
	{
		volatile struct
		{
			unsigned CFEIF0 :1;
			unsigned RESERVED :1;
			unsigned CDMEIF0 :1;
			unsigned CTEIF0 :1;
			unsigned CHTIF0 :1;
			unsigned CTCIF0 :1;
			unsigned CFEIF1 :1;
			unsigned RESERVED2 :1;
			unsigned CDMEIF1 :1;
			unsigned CTEIF1 :1;
			unsigned CHTIF1 :1;
			unsigned CTCIF1 :1;
			unsigned RESERVED3 :4;
			unsigned CFEIF2 :1;
			unsigned RESERVED4 :1;
			unsigned CDMEIF2 :1;
			unsigned CTEIF2 :1;
			unsigned CHTIF2 :1;
			unsigned CTCIF2 :1;
			unsigned CFEIF3 :1;
			unsigned RESERVED5 :1;
			unsigned CDMEIF3 :1;
			unsigned CTEIF3 :1;
			unsigned CHTIF3 :1;
			unsigned CTCIF3 :1;
		} lifcr;
		volatile uint32_t LIFCR;
	};
	/*!< DMA high interrupt flag clear register, Address offset: 0x0C */
	union
	{
		volatile struct
		{
			unsigned CFEIF4 :1;
			unsigned RESERVED :1;
			unsigned CDMEIF4 :1;
			unsigned CTEIF4 :1;
			unsigned CHTIF4 :1;
			unsigned CTCIF4 :1;
			unsigned CFEIF5 :1;
			unsigned RESERVED2 :1;
			unsigned CDMEIF5 :1;
			unsigned CTEIF5 :1;
			unsigned CHTIF5 :1;
			unsigned CTCIF5 :1;
			unsigned RESERVED3 :4;
			unsigned CFEIF6 :1;
			unsigned RESERVED4 :1;
			unsigned CDMEIF6 :1;
			unsigned CTEIF6 :1;
			unsigned CHTIF6 :1;
			unsigned CTCIF6 :1;
			unsigned CFEIF7 :1;
			unsigned RESERVED5 :1;
			unsigned CDMEIF7 :1;
			unsigned CTEIF7 :1;
			unsigned CHTIF7 :1;
			unsigned CTCIF7 :1;
		} hifcr;
		volatile uint32_t HIFCR;
	};
} DMA_Type;


#undef DMA1
#undef DMA1_Stream0
#undef DMA1_Stream1
#undef DMA1_Stream2
#undef DMA1_Stream3
#undef DMA1_Stream4
#undef DMA1_Stream5
#undef DMA1_Stream6
#undef DMA1_Stream7
#undef DMA2
#undef DMA2_Stream0
#undef DMA2_Stream1
#undef DMA2_Stream2
#undef DMA2_Stream3
#undef DMA2_Stream4
#undef DMA2_Stream5
#undef DMA2_Stream6
#undef DMA2_Stream7

#define DMA1                ((DMA_Type *) DMA1_BASE)
#define DMA1_Stream0        ((DMA_Stream_Type *) DMA1_Stream0_BASE)
#define DMA1_Stream1        ((DMA_Stream_Type *) DMA1_Stream1_BASE)
#define DMA1_Stream2        ((DMA_Stream_Type *) DMA1_Stream2_BASE)
#define DMA1_Stream3        ((DMA_Stream_Type *) DMA1_Stream3_BASE)
#define DMA1_Stream4        ((DMA_Stream_Type *) DMA1_Stream4_BASE)
#define DMA1_Stream5        ((DMA_Stream_Type *) DMA1_Stream5_BASE)
#define DMA1_Stream6        ((DMA_Stream_Type *) DMA1_Stream6_BASE)
#define DMA1_Stream7        ((DMA_Stream_Type *) DMA1_Stream7_BASE)
#define DMA2                ((DMA_Type *) DMA2_BASE)
#define DMA2_Stream0        ((DMA_Stream_Type *) DMA2_Stream0_BASE)
#define DMA2_Stream1        ((DMA_Stream_Type *) DMA2_Stream1_BASE)
#define DMA2_Stream2        ((DMA_Stream_Type *) DMA2_Stream2_BASE)
#define DMA2_Stream3        ((DMA_Stream_Type *) DMA2_Stream3_BASE)
#define DMA2_Stream4        ((DMA_Stream_Type *) DMA2_Stream4_BASE)
#define DMA2_Stream5        ((DMA_Stream_Type *) DMA2_Stream5_BASE)
#define DMA2_Stream6        ((DMA_Stream_Type *) DMA2_Stream6_BASE)
#define DMA2_Stream7        ((DMA_Stream_Type *) DMA2_Stream7_BASE)

/********************************* INTERRUPT REGISTER DEFINITION REGION *********************************/

typedef struct
{
	/*!< EXTI Interrupt mask register,            Address offset: 0x00 */
	union
	{
		volatile struct
		{
			unsigned MR0 :1;
			unsigned MR1 :1;
			unsigned MR2 :1;
			unsigned MR3 :1;
			unsigned MR4 :1;
			unsigned MR5 :1;
			unsigned MR6 :1;
			unsigned MR7 :1;
			unsigned MR8 :1;
			unsigned MR9 :1;
			unsigned MR10 :1;
			unsigned MR11 :1;
			unsigned MR12 :1;
			unsigned MR13 :1;
			unsigned MR14 :1;
			unsigned MR15 :1;
			unsigned MR16 :1;
			unsigned MR17 :1;
			unsigned MR18 :1;
			unsigned MR19 :1;
			unsigned MR20 :1;
			unsigned MR21 :1;
			unsigned MR22 :1;
		} imr;
		volatile uint32_t IMR;
	};
	/*!< EXTI Event mask register,                Address offset: 0x04 */
	union
	{
		volatile struct
		{
			unsigned MR0 :1;
			unsigned MR1 :1;
			unsigned MR2 :1;
			unsigned MR3 :1;
			unsigned MR4 :1;
			unsigned MR5 :1;
			unsigned MR6 :1;
			unsigned MR7 :1;
			unsigned MR8 :1;
			unsigned MR9 :1;
			unsigned MR10 :1;
			unsigned MR11 :1;
			unsigned MR12 :1;
			unsigned MR13 :1;
			unsigned MR14 :1;
			unsigned MR15 :1;
			unsigned MR16 :1;
			unsigned MR17 :1;
			unsigned MR18 :1;
			unsigned MR19 :1;
			unsigned MR20 :1;
			unsigned MR21 :1;
			unsigned MR22 :1;
		} emr;
		volatile uint32_t EMR;
	};
	/*!< EXTI Rising trigger selection register,  Address offset: 0x08 */
	union
	{
		volatile struct
		{
			unsigned TR0 :1;
			unsigned TR1 :1;
			unsigned TR2 :1;
			unsigned TR3 :1;
			unsigned TR4 :1;
			unsigned TR5 :1;
			unsigned TR6 :1;
			unsigned TR7 :1;
			unsigned TR8 :1;
			unsigned TR9 :1;
			unsigned TR10 :1;
			unsigned TR11 :1;
			unsigned TR12 :1;
			unsigned TR13 :1;
			unsigned TR14 :1;
			unsigned TR15 :1;
			unsigned TR16 :1;
			unsigned TR17 :1;
			unsigned TR18 :1;
			unsigned TR19 :1;
			unsigned TR20 :1;
			unsigned TR21 :1;
			unsigned TR22 :1;
		} rtrs;
		volatile uint32_t RTRS;
	};

	/*!< EXTI Falling trigger selection register, Address offset: 0x0C */
	union
	{
		volatile struct
		{
			unsigned TR0 :1;
			unsigned TR1 :1;
			unsigned TR2 :1;
			unsigned TR3 :1;
			unsigned TR4 :1;
			unsigned TR5 :1;
			unsigned TR6 :1;
			unsigned TR7 :1;
			unsigned TR8 :1;
			unsigned TR9 :1;
			unsigned TR10 :1;
			unsigned TR11 :1;
			unsigned TR12 :1;
			unsigned TR13 :1;
			unsigned TR14 :1;
			unsigned TR15 :1;
			unsigned TR16 :1;
			unsigned TR17 :1;
			unsigned TR18 :1;
			unsigned TR19 :1;
			unsigned TR20 :1;
			unsigned TR21 :1;
			unsigned TR22 :1;
		} ftrs;
		volatile uint32_t FTRS;
	};

	/*!< EXTI Software interrupt event register,  Address offset: 0x10 */
	union
	{
		volatile struct
		{
			unsigned SWIER0 :1;
			unsigned SWIER1 :1;
			unsigned SWIER2 :1;
			unsigned SWIER3 :1;
			unsigned SWIER4 :1;
			unsigned SWIER5 :1;
			unsigned SWIER6 :1;
			unsigned SWIER7 :1;
			unsigned SWIER8 :1;
			unsigned SWIER9 :1;
			unsigned SWIER10 :1;
			unsigned SWIER11 :1;
			unsigned SWIER12 :1;
			unsigned SWIER13 :1;
			unsigned SWIER14 :1;
			unsigned SWIER15 :1;
			unsigned SWIER16 :1;
			unsigned SWIER17 :1;
			unsigned SWIER18 :1;
			unsigned SWIER19 :1;
			unsigned SWIER20 :1;
			unsigned SWIER21 :1;
			unsigned SWIER22 :1;
		} swier;
		volatile uint32_t SWIER;
	};

	/*!< EXTI Pending register,                   Address offset: 0x14 */
	union
	{
		volatile struct
		{
			unsigned PR0 :1;
			unsigned PR1 :1;
			unsigned PR2 :1;
			unsigned PR3 :1;
			unsigned PR4 :1;
			unsigned PR5 :1;
			unsigned PR6 :1;
			unsigned PR7 :1;
			unsigned PR8 :1;
			unsigned PR9 :1;
			unsigned PR10 :1;
			unsigned PR11 :1;
			unsigned PR12 :1;
			unsigned PR13 :1;
			unsigned PR14 :1;
			unsigned PR15 :1;
			unsigned PR16 :1;
			unsigned PR17 :1;
			unsigned PR18 :1;
			unsigned PR19 :1;
			unsigned PR20 :1;
			unsigned PR21 :1;
			unsigned PR22 :1;
		} pr;
		volatile uint32_t PR;
	};
} EXTI_Type;

#undef EXTI
#define EXTI                ((EXTI_Type *) EXTI_BASE)

/********************************* ADC REGISTER DEFINITION REGION *********************************/
typedef volatile struct
{
	union
	{
		volatile struct
		{
			unsigned AWD :1;
			unsigned EOC :1;
			unsigned JEOC :1;
			unsigned JSTRT :1;
			unsigned STRT :1;
			unsigned OVR :1;
		} sr;
		volatile uint32_t SR;
	};
	union
	{
		volatile struct
		{
			unsigned AWDCH :5;
			unsigned EOCIE :1;
			unsigned AWDIE :1;
			unsigned JEOCIE :1;
			unsigned SCAN :1;
			unsigned AWDSGL :1;
			unsigned JAUTO :1;
			unsigned DISCEN :1;
			unsigned JDISCEN :1;
			unsigned DISCNUM :3;
			unsigned RESERVED :6;
			unsigned JAWDEN :1;
			unsigned AWDEN :1;
			unsigned RES :2;
			unsigned OVRIE :1;
		} cr1;
		volatile uint32_t CR1;
	};

	union
	{
		volatile struct
		{
			unsigned ADON :1;
			unsigned CONT :1;
			unsigned RESERVED :6;
			unsigned DMA :1;
			unsigned DDS :1;
			unsigned EOCS :1;
			unsigned ALIGN :1;
			unsigned RESERVED2 :4;
			unsigned JEXTSEL :4;
			unsigned JEXTSEN :2;
			unsigned JSWSTART :1;
			unsigned RESERVED3 :1;
			unsigned EXTSEL :4;
			unsigned EXTEN :2;
			unsigned SWSTART :1;
		} cr2;
		volatile uint32_t CR2;
	};
	union
	{
		volatile struct
		{
			unsigned SMP10 :3;
			unsigned SMP11 :3;
			unsigned SMP12 :3;
			unsigned SMP13 :3;
			unsigned SMP14 :3;
			unsigned SMP15 :3;
			unsigned SMP16 :3;
			unsigned SMP17 :3;
			unsigned SMP18 :3;
		} smpr1;
		volatile uint32_t SMPR1;
	};
	union
	{
		volatile struct
		{
			unsigned SMP0 :3;
			unsigned SMP1 :3;
			unsigned SMP2 :3;
			unsigned SMP3 :3;
			unsigned SMP4 :3;
			unsigned SMP5 :3;
			unsigned SMP6 :3;
			unsigned SMP7 :3;
			unsigned SMP8 :3;
			unsigned SMP9 :3;
		} smpr2;
		volatile uint32_t SMPR2;
	};
	volatile uint32_t JOFR1;
	volatile uint32_t JOFR2;
	volatile uint32_t JOFR3;
	volatile uint32_t JOFR4;
	volatile uint32_t HTR;
	volatile uint32_t LTR;
	union
	{
		volatile struct
		{
			unsigned SQ13 :5;
			unsigned SQ14 :5;
			unsigned SQ15 :5;
			unsigned SQ16 :5;
			unsigned L :4;
		} sqr1;
		volatile uint32_t SQR1;
	};
	union
	{
		volatile struct
		{
			unsigned SQ7 :5;
			unsigned SQ8 :5;
			unsigned SQ9 :5;
			unsigned SQ10 :5;
			unsigned SQ11 :5;
			unsigned SQ12 :5;
		} sqr2;
		volatile uint32_t SQR2;
	};
	union
	{
		volatile struct
		{
			unsigned SQ1 :5;
			unsigned SQ2 :5;
			unsigned SQ3 :5;
			unsigned SQ4 :5;
			unsigned SQ5 :5;
			unsigned SQ6 :5;
		} sqr3;
		volatile uint32_t SQR3;
	};
	union
	{
		volatile struct
		{
			unsigned JSQ1 :5;
			unsigned JSQ2 :5;
			unsigned JSQ3 :5;
			unsigned JSQ4 :5;
			unsigned JL :2;
		} jsqr;
		volatile uint32_t JSQR;
	};
	volatile uint32_t JDR1;
	volatile uint32_t JDR2;
	volatile uint32_t JDR3;
	volatile uint32_t JDR4;
	volatile uint32_t DR;
	
} ADC_Type;

#undef ADC1
#undef ADC2
#undef ADC3
#define ADC1 ((ADC_Type*)ADC1_BASE)
#define ADC2 ((ADC_Type*)ADC2_BASE)
#define ADC3 ((ADC_Type*)ADC3_BASE)

typedef volatile struct
{
	/*!< ADC Common status register,                  Address offset: ADC1 base address + 0x300 */
	union
	{
		volatile struct
		{
			unsigned AWD1 :1;
			unsigned EOC1 :1;
			unsigned JEOC1 :1;
			unsigned JSTRT1 :1;
			unsigned STRT1 :1;
			unsigned RESERVED :2;
			unsigned AWD2 :1;
			unsigned EOC2 :1;
			unsigned JEOC2 :1;
			unsigned JSTRT2 :1;
			unsigned STRT2 :1;
			unsigned RESERVED2 :2;
			unsigned AWD3 :1;
			unsigned EOC3 :1;
			unsigned JEOC3 :1;
			unsigned JSTRT3 :1;
			unsigned STRT3 :1;
			unsigned RESERVED3 :2;
			
		} csr;
		volatile uint32_t CSR;
	};
	/*!< ADC common control register,                 Address offset: ADC1 base address + 0x304 */
	union
	{
		volatile struct
		{
			unsigned MULTI :4;
			unsigned RESERVED :3;
			unsigned DELAY :4;
			unsigned RESERVED2 :1;
			unsigned DDS :1;
			unsigned DMA :2;
			unsigned ADCPRE :2;
			unsigned RESERVED3 :4;
			unsigned VBATE :1;
			unsigned TSVREFE :1;
			
		} ccr;
		volatile uint32_t CCR;
	};
	/*!< ADC common regular data register for dual
	 AND triple modes,                            Address offset: ADC1 base address + 0x308 */
	union
	{
		volatile struct
		{
			
			unsigned short int DATA1;
			unsigned short int DATA2;
			
		} cdr;
		volatile uint32_t CDR;
	};
} ADC_Common_Type;

#undef ADC
#define ADC ((ADC_Common_Type*)(ADC1_BASE+0x300))

/********************************* TIM REGISTER DEFINITION REGION *********************************/
typedef struct
{
	
	union
	{
		volatile struct
		{
			unsigned short int CEN :1;
			unsigned short int UDIS :1;
			unsigned short int URS :1;
			unsigned short int OPM :1;
			unsigned short int DIR :1;
			unsigned short int CMS :2;
			unsigned short int ARPE :1;
			unsigned short int CKD :2;
			unsigned short int RESERVED :6;
			
		} cr1;
		volatile unsigned short int CR1;
	};
	volatile unsigned short int RESERVED0;

	union
	{
		volatile struct
		{
			unsigned short int RESERVED :3;
			unsigned short int CCDS :1;
			unsigned short int MMS :3;
			unsigned short int TI1S :1;
			unsigned short int RESERVED1 :8;
		} cr2;
		volatile unsigned short int CR2;
	};

	volatile unsigned short int RESERVED1;
	union
	{
		volatile struct
		{
			unsigned short int SMS :3;
			unsigned short int RESERVED :1;
			unsigned short int TS :3;
			unsigned short int MSM :1;
			unsigned short int ETF :4;
			unsigned short int ETPS :2;
			unsigned short int ECE :1;
			unsigned short int ETP :1;
		} smcr;
		volatile unsigned short int SMCR;
	};
	volatile unsigned short int RESERVED2;
	union
	{
		volatile struct
		{
			unsigned short int UIE :1;
			unsigned short int CC1IE :1;
			unsigned short int CC2IE :1;
			unsigned short int CC3IE :1;
			unsigned short int CC4IE :1;
			unsigned short int RESERVED :1;
			unsigned short int TIE :1;
			unsigned short int RESERVED1 :1;
			unsigned short int UDE :1;
			unsigned short int CC1DE :1;
			unsigned short int CC2DE :1;
			unsigned short int CC3DE :1;
			unsigned short int CC4DE :1;
			unsigned short int RESERVED2 :1;
			unsigned short int TDE :1;
		} dier;
		volatile unsigned short int DIER;
	};
	volatile unsigned short int RESERVED3;
	volatile unsigned short int SR;
	volatile unsigned short int RESERVED4;
	union
	{
		volatile struct
		{
			unsigned short int UG :1;
			unsigned short int CC1G :1;
			unsigned short int CC2G :1;
			unsigned short int CC3G :1;
			unsigned short int CC4G :1;
			unsigned short int RESERVED :1;
			unsigned short int TG :1;
		} egr;
		volatile unsigned short int EGR;
	};
	volatile unsigned short int RESERVED5;
	union
	{
		volatile struct
		{
			unsigned short int CC1S :2;
			unsigned short int OC1FE :1;
			unsigned short int OC1PE :1;
			unsigned short int OC1M :3;
			unsigned short int OC1CE :1;
			unsigned short int CC2S :2;
			unsigned short int OC2FE :1;
			unsigned short int OC2PE :1;
			unsigned short int OC2M :3;
			unsigned short int OC2CE :1;
		} ccmr1;
		volatile unsigned short int CCMR1;
	};
	volatile unsigned short int RESERVED6;
	union
	{
		volatile struct
		{
			unsigned short int CC3S :2;
			unsigned short int OC3FE :1;
			unsigned short int OC3PE :1;
			unsigned short int OC3M :3;
			unsigned short int OC3CE :1;
			unsigned short int CC4S :2;
			unsigned short int OC4FE :1;
			unsigned short int OC4PE :1;
			unsigned short int OC4M :3;
			unsigned short int OC4CE :1;
		} ccmr2;
		volatile unsigned short int CCMR2;
	};
	volatile unsigned short int RESERVED7;
	union
	{
		volatile struct
		{
			unsigned short int CC1E :1;
			unsigned short int CC1P :1;
			unsigned short int RESERVED :1;
			unsigned short int CC1NP :1;
			unsigned short int CC2E :1;
			unsigned short int CC2P :1;
			unsigned short int RESERVED1 :1;
			unsigned short int CC2NP :1;
			unsigned short int CC3E :1;
			unsigned short int CC3P :1;
			unsigned short int RESERVED2 :1;
			unsigned short int CC3NP :1;
			unsigned short int CC4E :1;
			unsigned short int CC4P :1;
			unsigned short int RESERVED3 :1;
			unsigned short int CC4NP :1;
		} ccer;
		volatile unsigned short int CCER;
	};

	volatile unsigned short int RESERVED8;

	union
	{
		volatile struct
		{
			unsigned short int BIT0 :1;
			unsigned short int BIT1 :1;
			unsigned short int BIT2 :1;
			unsigned short int BIT3 :1;
			unsigned short int BIT4 :1;
			unsigned short int BIT5 :1;
			unsigned short int BIT6 :1;
			unsigned short int BIT7 :1;
			unsigned short int BIT8 :1;
			unsigned short int BIT9 :1;
			unsigned short int BIT10 :1;
			unsigned short int BIT11 :1;
			unsigned short int BIT12 :1;
			unsigned short int BIT13 :1;
			unsigned short int BIT14 :1;
			unsigned short int BIT15 :1;
		} cnt;
		volatile unsigned int CNT;
	};

	volatile unsigned short int PSC;
	volatile unsigned short int RESERVED9;
	volatile uint32_t ARR;
	volatile unsigned short int RCR;
	volatile unsigned short int RESERVED10;
	volatile uint32_t CCR1;
	volatile uint32_t CCR2;
	volatile uint32_t CCR3;
	volatile uint32_t CCR4;
	volatile unsigned short int BDTR;
	volatile unsigned short int RESERVED11;
	union
	{
		volatile struct
		{
			unsigned short int DBA :5;
			unsigned short int RESERVED :3;
			unsigned short int DBL :5;
		} dcr;
		volatile unsigned short int DCR;
	};
	volatile unsigned short int RESERVED12;
	volatile unsigned short int DMAR;
	volatile unsigned short int RESERVED13;
	volatile unsigned short int OR;
	volatile unsigned short int RESERVED14;
} TIM_Type;

#undef TIM1
#undef TIM2
#undef TIM3
#undef TIM4
#undef TIM5
#undef TIM6
#undef TIM7
#undef TIM8
#undef TIM12
#undef TIM13
#undef TIM14
#define TIM1                ((TIM_Type *) TIM1_BASE)
#define TIM2                ((TIM_Type *) TIM2_BASE)
#define TIM3                ((TIM_Type *) TIM3_BASE)
#define TIM4                ((TIM_Type *) TIM4_BASE)
#define TIM5                ((TIM_Type *) TIM5_BASE)
#define TIM6                ((TIM_Type *) TIM6_BASE)
#define TIM7                ((TIM_Type *) TIM7_BASE)
#define TIM8                ((TIM_Type *) TIM8_BASE)
#define TIM12               ((TIM_Type *) TIM12_BASE)
#define TIM13               ((TIM_Type *) TIM13_BASE)
#define TIM14               ((TIM_Type *) TIM14_BASE)

/********************************* FSMC REGISTER DEFINITION REGION *********************************/

typedef volatile struct
{
	/*!< NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR), Address offset: 0x00-1C */
	union
	{
		volatile struct
		{
			unsigned short int MBKEN :1;
			unsigned short int MUXEN :1;
			unsigned short int MTYP :2;
			unsigned short int MWID :2;
			unsigned short int FACCEN :1;
			unsigned short int RESERVED :1;
			unsigned short int BURSTEN :1;
			unsigned short int WAITPOL :1;
			unsigned short int WRAPMOD :1;
			unsigned short int WAITCFG :1;
			unsigned short int WREN :1;
			unsigned short int WAITEN :1;
			unsigned short int EXTMOD :1;
			unsigned short int ASYNCWAIT :1;
			unsigned short int RESERVED2 :3;
			unsigned short int CBURSTRW :1;
		} bcr1;
		volatile uint32_t BCR1;
	};
	union
	{
		volatile struct
		{
			unsigned short int ADDSET :4;
			unsigned short int ADDHLD :4;
			unsigned short int DATAST :8;
			unsigned short int BUSTURN :4;
			unsigned short int CLKDIV :4;
			unsigned short int DATLAT :4;
			unsigned short int ACCMOD :2;
		} btr1;
		volatile uint32_t BTR1;
	};
	union
	{
		volatile struct
		{
			unsigned short int MBKEN :1;
			unsigned short int MUXEN :1;
			unsigned short int MTYP :2;
			unsigned short int MWID :2;
			unsigned short int FACCEN :1;
			unsigned short int RESERVED :1;
			unsigned short int BURSTEN :1;
			unsigned short int WAITPOL :1;
			unsigned short int WRAPMOD :1;
			unsigned short int WAITCFG :1;
			unsigned short int WREN :1;
			unsigned short int WAITEN :1;
			unsigned short int EXTMOD :1;
			unsigned short int ASYNCWAIT :1;
			unsigned short int RESERVED2 :3;
			unsigned short int CBURSTRW :1;
		} bcr2;
		volatile uint32_t BCR2;
	};

	union
	{
		volatile struct
		{
			unsigned short int ADDSET :4;
			unsigned short int ADDHLD :4;
			unsigned short int DATAST :8;
			unsigned short int BUSTURN :4;
			unsigned short int CLKDIV :4;
			unsigned short int DATLAT :4;
			unsigned short int ACCMOD :2;
		} btr2;
		volatile uint32_t BTR2;
	};
	union
	{
		volatile struct
		{
			unsigned short int MBKEN :1;
			unsigned short int MUXEN :1;
			unsigned short int MTYP :2;
			unsigned short int MWID :2;
			unsigned short int FACCEN :1;
			unsigned short int RESERVED :1;
			unsigned short int BURSTEN :1;
			unsigned short int WAITPOL :1;
			unsigned short int WRAPMOD :1;
			unsigned short int WAITCFG :1;
			unsigned short int WREN :1;
			unsigned short int WAITEN :1;
			unsigned short int EXTMOD :1;
			unsigned short int ASYNCWAIT :1;
			unsigned short int RESERVED2 :3;
			unsigned short int CBURSTRW :1;
		} bcr3;
		volatile uint32_t BCR3;
	};

	union
	{
		volatile struct
		{
			unsigned short int ADDSET :4;
			unsigned short int ADDHLD :4;
			unsigned short int DATAST :8;
			unsigned short int BUSTURN :4;
			unsigned short int CLKDIV :4;
			unsigned short int DATLAT :4;
			unsigned short int ACCMOD :2;
		} btr3;
		volatile uint32_t BTR3;
	};
	union
	{
		volatile struct
		{
			unsigned short int MBKEN :1;
			unsigned short int MUXEN :1;
			unsigned short int MTYP :2;
			unsigned short int MWID :2;
			unsigned short int FACCEN :1;
			unsigned short int RESERVED :1;
			unsigned short int BURSTEN :1;
			unsigned short int WAITPOL :1;
			unsigned short int WRAPMOD :1;
			unsigned short int WAITCFG :1;
			unsigned short int WREN :1;
			unsigned short int WAITEN :1;
			unsigned short int EXTMOD :1;
			unsigned short int ASYNCWAIT :1;
			unsigned short int RESERVED2 :3;
			unsigned short int CBURSTRW :1;
		} bcr4;
		volatile uint32_t BCR4;
	};

	union
	{
		volatile struct
		{
			unsigned short int ADDSET :4;
			unsigned short int ADDHLD :4;
			unsigned short int DATAST :8;
			unsigned short int BUSTURN :4;
			unsigned short int CLKDIV :4;
			unsigned short int DATLAT :4;
			unsigned short int ACCMOD :2;
		} btr4;
		volatile uint32_t BTR4;
	};
	
} FSMC_Bank1_Type;

#undef FSMC_Bank1
#define FSMC_Bank1          ((FSMC_Bank1_Type*) FSMC_Bank1_R_BASE)

/**
 * @brief Flexible Static Memory Controller Bank1E
 */

typedef volatile struct
{
	/*!< NOR/PSRAM write timing registers, Address offset: 0x104-0x11C */
	union
	{
		volatile struct
		{
			unsigned short int ADDSET :4;
			unsigned short int ADDHLD :4;
			unsigned short int DATAST :8;
			unsigned short int BUSTURN :4;
			unsigned short int CLKDIV :4;
			unsigned short int DATLAT :4;
			unsigned short int ACCMOD :2;
		} bwtr1;
		volatile uint32_t BWTR1;
	};
	volatile uint32_t RESERVED;
	union
	{
		volatile struct
		{
			unsigned short int ADDSET :4;
			unsigned short int ADDHLD :4;
			unsigned short int DATAST :8;
			unsigned short int BUSTURN :4;
			unsigned short int CLKDIV :4;
			unsigned short int DATLAT :4;
			unsigned short int ACCMOD :2;
		} bwtr2;
		volatile uint32_t BWTR2;
	};
	volatile uint32_t RESERVED2;
	union
	{
		volatile struct
		{
			unsigned short int ADDSET :4;
			unsigned short int ADDHLD :4;
			unsigned short int DATAST :8;
			unsigned short int BUSTURN :4;
			unsigned short int CLKDIV :4;
			unsigned short int DATLAT :4;
			unsigned short int ACCMOD :2;
		} bwtr3;
		volatile uint32_t BWTR3;
	};
	volatile uint32_t RESERVED3;

	union
	{
		volatile struct
		{
			unsigned short int ADDSET :4;
			unsigned short int ADDHLD :4;
			unsigned short int DATAST :8;
			unsigned short int BUSTURN :4;
			unsigned short int CLKDIV :4;
			unsigned short int DATLAT :4;
			unsigned short int ACCMOD :2;
		} bwtr4;
		volatile uint32_t BWTR4;
	};
	
} FSMC_Bank1E_Type;

#undef FSMC_Bank1E
#define FSMC_Bank1E         ((FSMC_Bank1E_Type*) FSMC_Bank1E_R_BASE)

/**
 * @brief Flexible Static Memory Controller Bank2
 */

typedef volatile struct
{
	/*!< NAND Flash control register 2,                       Address offset: 0x60 */
	union
	{
		volatile struct
		{
			unsigned short int PWAITEN :1;
			unsigned short int PBKEN :1;
			unsigned short int PTYP :1;
			unsigned short int PWID :2;
			unsigned short int ECCEN :1;
			unsigned short int RESERVED :2;
			unsigned short int TCLR :4;
			unsigned short int TAR :4;
			unsigned short int ECCPS :3;
			
		} pcr2;
		volatile uint32_t PCR2;
	};
	/*!< NAND Flash FIFO status and interrupt register 2,     Address offset: 0x64 */
	union
	{
		volatile struct
		{
			unsigned short int IRS :1;
			unsigned short int ILS :1;
			unsigned short int IFS :1;
			unsigned short int IREN :1;
			unsigned short int ILEN :1;
			unsigned short int IFEN :1;
			unsigned short int FEMPT :4;
		} sr2;
		volatile uint32_t SR2;
	};
	/*!< NAND Flash Common memory space timing register 2,    Address offset: 0x68 */
	union
	{
		volatile struct
		{
			unsigned short int MEMSET :8;
			unsigned short int MEMWAIT :8;
			unsigned short int MEMHOLD :8;
			unsigned short int MEMHIZ :8;
		} pmem2;
		volatile uint32_t PMEM2;
	};
	/*!< NAND Flash Attribute memory space timing register 2, Address offset: 0x6C */
	union
	{
		volatile struct
		{
			unsigned short int ATTSET :8;
			unsigned short int ATTWAIT :8;
			unsigned short int ATTHOLD :8;
			unsigned short int ATTHIZ :8;
		} patt2;
		volatile uint32_t PATT2;
	};
	volatile uint32_t RESERVED; /*!< Reserved, 0x70                                                            */
	volatile uint32_t ECCR2; /*!< NAND Flash ECC result registers 2,                   Address offset: 0x74 */
} FSMC_Bank2_Type;

#undef FSMC_Bank2
#define FSMC_Bank2          ((FSMC_Bank2_Type*) FSMC_Bank2_R_BASE)

/**
 * @brief Flexible Static Memory Controller Bank3
 */

typedef volatile struct
{
	/*!< NAND Flash control register 3,                       Address offset: 0x80 */
	union
	{
		volatile struct
		{
			unsigned short int PWAITEN :1;
			unsigned short int PBKEN :1;
			unsigned short int PTYP :1;
			unsigned short int PWID :2;
			unsigned short int ECCEN :1;
			unsigned short int RESERVED :2;
			unsigned short int TCLR :4;
			unsigned short int TAR :4;
			unsigned short int ECCPS :3;
			
		} pcr3;
		volatile uint32_t PCR3;
	};
	/*!< NAND Flash FIFO status and interrupt register 3,     Address offset: 0x84 */
	union
	{
		volatile struct
		{
			unsigned short int IRS :1;
			unsigned short int ILS :1;
			unsigned short int IFS :1;
			unsigned short int IREN :1;
			unsigned short int ILEN :1;
			unsigned short int IFEN :1;
			unsigned short int FEMPT :4;
		} sr3;
		volatile uint32_t SR3;
	};
	/*!< NAND Flash Common memory space timing register 3,    Address offset: 0x88 */
	union
	{
		volatile struct
		{
			unsigned short int MEMSET :8;
			unsigned short int MEMWAIT :8;
			unsigned short int MEMHOLD :8;
			unsigned short int MEMHIZ :8;
		} pmem3;
		volatile uint32_t PMEM3;
	};
	/*!< NAND Flash Attribute memory space timing register 3, Address offset: 0x8C */
	union
	{
		volatile struct
		{
			unsigned short int ATTSET :8;
			unsigned short int ATTWAIT :8;
			unsigned short int ATTHOLD :8;
			unsigned short int ATTHIZ :8;
		} patt3;
		volatile uint32_t PATT3;
	};
	uint32_t RESERVED; /*!< Reserved, 0x90                                                            */
	volatile uint32_t ECCR3; /*!< NAND Flash ECC result registers 3,                   Address offset: 0x94 */
} FSMC_Bank3_Type;

#undef FSMC_Bank3
#define FSMC_Bank3          ((FSMC_Bank3_Type*) FSMC_Bank3_R_BASE)

/**
 * @brief Flexible Static Memory Controller Bank4
 */

typedef volatile struct
{
	/*!< PC Card  control register 4,                       Address offset: 0xA0 */
	union
	{
		volatile struct
		{
			unsigned short int PWAITEN :1;
			unsigned short int PBKEN :1;
			unsigned short int PTYP :1;
			unsigned short int PWID :2;
			unsigned short int ECCEN :1;
			unsigned short int RESERVED :2;
			unsigned short int TCLR :4;
			unsigned short int TAR :4;
			unsigned short int ECCPS :3;
			
		} pcr4;
		volatile uint32_t PCR4;
	};
	/*!< PC Card  FIFO status and interrupt register 4,     Address offset: 0xA4 */
	union
	{
		volatile struct
		{
			unsigned short int IRS :1;
			unsigned short int ILS :1;
			unsigned short int IFS :1;
			unsigned short int IREN :1;
			unsigned short int ILEN :1;
			unsigned short int IFEN :1;
			unsigned short int FEMPT :4;
		} sr4;
		volatile uint32_t SR4;
	};
	/*!< PC Card  Common memory space timing register 4,    Address offset: 0xA8 */
	union
	{
		volatile struct
		{
			unsigned short int MEMSET :8;
			unsigned short int MEMWAIT :8;
			unsigned short int MEMHOLD :8;
			unsigned short int MEMHIZ :8;
		} pmem4;
		volatile uint32_t PMEM4;
	};
	/*!< PC Card  Attribute memory space timing register 4, Address offset: 0xAC */
	union
	{
		volatile struct
		{
			unsigned short int ATTSET :8;
			unsigned short int ATTWAIT :8;
			unsigned short int ATTHOLD :8;
			unsigned short int ATTHIZ :8;
		} patt4;
		volatile uint32_t PATT4;
	};
	/*!< PC Card  I/O space timing register 4,              Address offset: 0xB0 */
	union
	{
		volatile struct
		{
			unsigned short int IOTSET :8;
			unsigned short int IOTWAIT :8;
			unsigned short int IOTHOLD :8;
			unsigned short int IOTHIZ :8;
		} pio4;
		volatile uint32_t PIO4;
	};
} FSMC_Bank4_Type;

#undef FSMC_Bank4
#define FSMC_Bank4          ((FSMC_Bank4_Type*) FSMC_Bank4_R_BASE)

/********************************* SPI REGISTER DEFINITION REGION *********************************/
typedef volatile struct
{
	/*!< SPI control register 1 (not used in I2S mode),      Address offset: 0x00 */
	union
	{
		volatile struct
		{
			unsigned short int CPHA :1;
			unsigned short int CPOL :1;
			unsigned short int MSTR :1;
			unsigned short int BR :3;
			unsigned short int SPE :1;
			unsigned short int LSBFIRST :1;
			unsigned short int SSI :1;
			unsigned short int SSM :1;
			unsigned short int RXONLY :1;
			unsigned short int DFF :1;
			unsigned short int CRCNEXT :1;
			unsigned short int CRCEN :1;
			unsigned short int BIDIOE :1;
			unsigned short int BIDIMODE :1;
		} cr1;
		volatile uint16_t CR1;
	};

	uint16_t RESERVED0; /*!< Reserved, 0x02
	 */
	/*!< SPI control register 2,                             Address offset: 0x04 */
	union
	{
		volatile struct
		{
			unsigned short int RXDMAEN :1;
			unsigned short int TXDMAEN :1;
			unsigned short int SSOE :1;
			unsigned short int RESERVED :1;
			unsigned short int FRF :1;
			unsigned short int ERRIE :1;
			unsigned short int RXNEIE :1;
			unsigned short int TXEIE :1;
		} cr2;
		volatile uint16_t CR2;
	};

	uint16_t RESERVED1; /*!< Reserved, 0x06                                                           */
	
	/*!< SPI status register,                                Address offset: 0x08 */
	union
	{
		volatile struct
		{
			unsigned short int RXNE :1;
			unsigned short int TXE :1;
			unsigned short int CHSIDE :1;
			unsigned short int UDR :1;
			unsigned short int CRCERR :1;
			unsigned short int MODF :1;
			unsigned short int OVR :1;
			unsigned short int BSY :1;
			unsigned short int TIFRFE :1;
		} sr;
		volatile uint16_t SR;
	};

	uint16_t RESERVED2; /*!< Reserved, 0x0A                                                           */
	
	/*!< SPI data register,                                  Address offset: 0x0C */
	union
	{
		volatile struct
		{
			unsigned char DR :8;
		} dr;
		volatile uint16_t DR;
	};

	uint16_t RESERVED3; /*!< Reserved, 0x0E                                                           */
	__IO
	uint16_t CRCPR; /*!< SPI CRC polynomial register (not used in I2S mode), Address offset: 0x10 */
	uint16_t RESERVED4; /*!< Reserved, 0x12                                                           */
	__IO
	uint16_t RXCRCR; /*!< SPI RX CRC register (not used in I2S mode),         Address offset: 0x14 */
	uint16_t RESERVED5; /*!< Reserved, 0x16                                                           */
	__IO
	uint16_t TXCRCR; /*!< SPI TX CRC register (not used in I2S mode),         Address offset: 0x18 */
	uint16_t RESERVED6; /*!< Reserved, 0x1A                                                           */
	
	/*!< SPI_I2S configuration register,                     Address offset: 0x1C */
	union
	{
		volatile struct
		{
			unsigned short int CHLEN :1;
			unsigned short int DATLEN :2;
			unsigned short int CKPOL :1;
			unsigned short int I2SSTD :2;
			unsigned short int RESERVED :1;
			unsigned short int PCMSYNC :1;
			unsigned short int I2SCFG :2;
			unsigned short int I2SE :1;
			unsigned short int I2SMOD :1;
		} i2scfgr;
		volatile uint16_t I2SCFGR;
	};

	uint16_t RESERVED7; /*!< Reserved, 0x1E                                                           */
	
	/*!< SPI_I2S prescaler register,                         Address offset: 0x20 */
	union
	{
		volatile struct
		{
			unsigned short int I2SDIV :8;
			unsigned short int ODD :1;
			unsigned short int MCKOE :1;
		} i2spr;
		volatile uint16_t I2SPR;
	};

	uint16_t RESERVED8; /*!< Reserved, 0x22                                                           */
} SPI_Type;

#undef I2S2ext
#undef SPI2
#undef SPI3
#undef I2S3ext
#undef SPI1

#define I2S2ext             ((SPI_Type*) I2S2ext_BASE)
#define SPI2  			((SPI_Type*) SPI2_BASE)
#define SPI3            ((SPI_Type*) SPI3_BASE)
#define I2S3ext            ((SPI_Type*) I2S3ext_BASE)
#define SPI1         ((SPI_Type*) SPI1_BASE)

#endif

