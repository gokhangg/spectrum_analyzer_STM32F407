/*
 * Project: Spectrum analyzer application hardware initialization file
 * Note: This file is not intended as a library can be manipulated as per desire
 * Author: Gokhan Gunay, ghngunay@gmail.com
 * Copyright: (C) 2018 by Gokhan Gunay
 * License: GNU GPL v3 (see License.txt)
 */
#include "hardware_init.h"

system_t sys_var;

/*Get core frequency*/
unsigned int get_core_freq(void)
{
	int32_t var = ((int32_t) RCC->cfgr.HPRE) - 0x1000;
	int32_t var2 = ((unsigned int) RCC->pllcfgr.PLLN) * (XTALL_freq);
	if (var < 0)
	{
		var = 1;
	}
	else if (var <= 3)
	{
		var = (1 << (var + 1));
	}
	else
	{
		var = (1 << (var + 3));
	}

	var2 /= (2 * (((int32_t) RCC->pllcfgr.PLLP) + 1))
			* (var * ((unsigned int) RCC->pllcfgr.PLLM));

	switch ((unsigned char) RCC->cfgr.SW)
	{
	case 0:
		return 8000000 / (var);
	case 1:
		return XTALL_freq / (var);
	case 2:
		return var2;

	};

	return 0;
}

/*Get APB bus frequency for APB1 apb=1,for APB2 apb=2*/
unsigned int get_apb_freq(unsigned char apb)
{
	int32_t var = ((int32_t) RCC->cfgr.HPRE) - 0x8;
	int32_t var2 = 0;

	if (var < 0)
	{
		var = 1;
	}
	else if (var <= 3)
	{
		var = (1 << (var + 1));
	}
	else
	{
		var = (1 << (var + 3));
	}

	if (apb == 1)
	{
		var2 = ((int32_t) RCC->cfgr.PPRE1) - 0x4;

	}
	else if (apb == 2)
	{
		var2 = ((int32_t) RCC->cfgr.PPRE2) - 0x4;
	}
	else
	{
		return 0;
	}

	if (var2 < 0)
	{
		var2 = 1;
	}
	else
	{
		var2 = (1 << (var2 + 1));
	}

	return get_core_freq() / (var * var2);

}

/*Init PORTD*/
void port_init(void)
{
	RCC->ahb1enr.GPIODEN = 1;
	PORTD->moder.MODER13 = 1;
	PORTD->speedr.OSPEEDR13 = 3;
	PORTD->moder.MODER12 = 1;
	PORTD->speedr.OSPEEDR12 = 3;
}

void int_init(void)
{
	EXTI->imr.MR5 = 0;
	EXTI->ftrs.TR5 = 1;

	RCC->ahb1enr.GPIOCEN = 1;

	PORTC->moder.MODER5 = 0;
	PORTC->afrl.AFRL5 = 15;
	PORTC->pupdr.PUPDR5 = 0;
	PORTC->speedr.OSPEEDR5 = 3;

	RCC->apb2enr.SYSCFGREN = 1;

	SYSCFG->exticr2.EXTI5 = 2;

	NVIC_EnableIRQ(EXTI9_5_IRQn);
}

/*Init SPI2*/
unsigned int spi2_init(void)
{
	RCC->ahb1enr.GPIOBEN = 1;
	RCC->ahb1enr.GPIOCEN = 1;
	RCC->apb1enr.SPI2EN = 1;

	PORTC->moder.MODER4 = 1;
	PORTC->speedr.OSPEEDR4 = 3;
	PORTC->bsrr.BS4 = 1;

	PORTC->moder.MODER5 = 0;

	PORTB->moder.MODER13 = 2;
	PORTB->speedr.OSPEEDR13 = 3;
	PORTB->afrh.AFRH13 = 5;
	PORTB->moder.MODER14 = 2;
	PORTB->speedr.OSPEEDR14 = 3;
	PORTB->afrh.AFRH14 = 5;
	PORTB->moder.MODER15 = 2;
	PORTB->speedr.OSPEEDR15 = 3;
	PORTB->afrh.AFRH15 = 5;

	PORTB->afrh.AFRH12 = 5;

	SPI2->cr1.CPHA = 0;
	SPI2->cr1.CPOL = 0;
	SPI2->cr1.MSTR = 1;
	SPI2->cr1.BR = 7;
	SPI2->cr1.LSBFIRST = 0;
	SPI2->cr1.SSM = 1;
	SPI2->cr1.DFF = 1;
	SPI2->cr1.SSI = 1;
	SPI2->cr2.SSOE = 1;
	SPI2->cr2.RXNEIE = 1;
	SPI2->cr1.SPE = 1;

	NVIC_EnableIRQ(SPI2_IRQn);

	PORTC->bsrr.BR4 = 1; //Strobe for spi device
	SPI2->DR = 0xD000;

	return 0;
}

unsigned int fscm_init(void)
{

	RCC->ahb1enr.GPIODEN = 1;
	RCC->ahb1enr.GPIOEEN = 1;
	RCC->ahb3enr.FSMCEN = 1;

	PORTD->moder.MODER15 = 2;
	PORTD->speedr.OSPEEDR15 = 3;
	PORTD->afrh.AFRH15 = 12;

	PORTD->moder.MODER14 = 2;
	PORTD->speedr.OSPEEDR14 = 3;
	PORTD->afrh.AFRH14 = 12;

	PORTD->moder.MODER1 = 2;
	PORTD->speedr.OSPEEDR1 = 3;
	PORTD->afrl.AFRL1 = 12;

	PORTD->moder.MODER0 = 2;
	PORTD->speedr.OSPEEDR0 = 3;
	PORTD->afrl.AFRL0 = 12;

	PORTD->moder.MODER8 = 2;
	PORTD->speedr.OSPEEDR8 = 3;
	PORTD->afrh.AFRH8 = 12;

	PORTD->moder.MODER9 = 2;
	PORTD->speedr.OSPEEDR9 = 3;
	PORTD->afrh.AFRH9 = 12;

	PORTD->moder.MODER7 = 2;
	PORTD->speedr.OSPEEDR7 = 3;
	PORTD->afrl.AFRL7 = 12;

	PORTD->moder.MODER11 = 2;
	PORTD->speedr.OSPEEDR11 = 3;
	PORTD->afrh.AFRH11 = 12;

	PORTD->moder.MODER10 = 2;
	PORTD->speedr.OSPEEDR10 = 3;
	PORTD->afrh.AFRH10 = 12;

	PORTD->moder.MODER4 = 2;
	PORTD->speedr.OSPEEDR4 = 3;
	PORTD->afrl.AFRL4 = 12;

	PORTD->moder.MODER5 = 2;
	PORTD->speedr.OSPEEDR5 = 3;
	PORTD->afrl.AFRL5 = 12;

	PORTE->moder.MODER7 = 2;
	PORTE->speedr.OSPEEDR7 = 3;
	PORTE->afrl.AFRL7 = 12;

	PORTE->moder.MODER8 = 2;
	PORTE->speedr.OSPEEDR8 = 3;
	PORTE->afrh.AFRH8 = 12;

	PORTE->moder.MODER9 = 2;
	PORTE->speedr.OSPEEDR9 = 3;
	PORTE->afrh.AFRH9 = 12;

	PORTE->moder.MODER10 = 2;
	PORTE->speedr.OSPEEDR10 = 3;
	PORTE->afrh.AFRH10 = 12;

	PORTE->moder.MODER11 = 2;
	PORTE->speedr.OSPEEDR11 = 3;
	PORTE->afrh.AFRH11 = 12;

	PORTE->moder.MODER12 = 2;
	PORTE->speedr.OSPEEDR12 = 3;
	PORTE->afrh.AFRH12 = 12;

	PORTE->moder.MODER13 = 2;
	PORTE->speedr.OSPEEDR13 = 3;
	PORTE->afrh.AFRH13 = 12;

	PORTE->moder.MODER14 = 2;
	PORTE->speedr.OSPEEDR14 = 3;
	PORTE->afrh.AFRH14 = 12;

	PORTE->moder.MODER15 = 2;
	PORTE->speedr.OSPEEDR15 = 3;
	PORTE->afrh.AFRH15 = 12;

	FSMC_Bank1->bcr4.MUXEN = 0;
	FSMC_Bank1->bcr4.MTYP = 0;
	FSMC_Bank1->bcr4.MWID = 1;
	FSMC_Bank1->bcr4.FACCEN = 0;
	FSMC_Bank1->bcr4.BURSTEN = 0;
	FSMC_Bank1->bcr4.WRAPMOD = 0;
	FSMC_Bank1->bcr4.WREN = 1;
	FSMC_Bank1->bcr4.WAITEN = 1;
	FSMC_Bank1->bcr4.ASYNCWAIT = 0;
	FSMC_Bank1->bcr4.EXTMOD = 1;
	FSMC_Bank1->bcr4.CBURSTRW = 0;

	FSMC_Bank1->btr4.ADDSET = 0;
	FSMC_Bank1->btr4.ADDHLD = 0;
	FSMC_Bank1->btr4.DATAST = 0;
	FSMC_Bank1->btr4.BUSTURN = 0;
	FSMC_Bank1->btr4.CLKDIV = 0;
	FSMC_Bank1->btr4.DATLAT = 0;
	FSMC_Bank1->btr4.ACCMOD = 0;

	FSMC_Bank1E->bwtr4.ACCMOD = 0;
	FSMC_Bank1E->bwtr4.ADDHLD = 0;
	FSMC_Bank1E->bwtr4.ADDSET = 0;
	FSMC_Bank1E->bwtr4.DATAST = 0;
	FSMC_Bank1E->bwtr4.DATLAT = 0;

	FSMC_Bank1->bcr4.MBKEN = 1;
	return 0;
}

void rcc_init(void)
{
	RCC->AHB1RSTR = 0xFFFFFFFF;
	RCC->AHB2RSTR = 0xFFFFFFFF;
	RCC->AHB3RSTR = 0xFFFFFFFF;
	RCC->APB1RSTR = 0xFFFFFFFF;
	RCC->APB2RSTR = 0xFFFFFFFF;
	RCC->AHB1RSTR = 0;
	RCC->AHB2RSTR = 0;
	RCC->AHB3RSTR = 0;
	RCC->APB1RSTR = 0;
	RCC->APB2RSTR = 0;

	/*xtall oscillator enabled*/
	RCC->cr.HSEON = 1;
	/*wait for xtall oscillator to settle*/
	while (!RCC->cr.HSERDY)
	{
	}

	/*source for PLL =  xtall oscillator*/
	RCC->pllcfgr.PLLSRC = 1;
	/*PLL VCO freq = PLLN * xtall oscillator*/
	RCC->pllcfgr.PLLN = 144;
	/*PLL VCO ref freq  =  xtall oscillator/PLLM */
	RCC->pllcfgr.PLLM = 4;
	/*PLL VCO out freq  =  VCO_freq/PLLP */
	RCC->pllcfgr.PLLP = 0;

	/*PWR clk and high power selection*/
	RCC->APB1ENR |= RCC_APB1ENR_PWREN;
	PWR->cr.VOS = 1;

	/*PLL oscillator enabled*/
	RCC->cr.PLLON = 1;
	/*wait for PLL oscillator to lock*/
	while (!RCC->cr.PLLRDY)
	{
	}

	/*APB1 freq divider selection*/
	RCC->cfgr.PPRE1 = 5;
	/*APB2 freq divider selection*/
	RCC->cfgr.PPRE2 = 4;
	/*AHB freq divider selection*/
	RCC->cfgr.HPRE = 0;

	/*Flash data cache enabled*/
	FLASH->acr.DCEN = 1;
	/*Flash instruction cache enabled*/
	FLASH->acr.ICEN = 1;
	/*Flash prefetch enabled*/
	FLASH->acr.PRFTEN = 1;
	/*Flash data cache enabled*/
	FLASH->acr.LATENCY = 5;

	/*PLL is main clk source*/
	RCC->cfgr.SW = 2;

	/*Update system core parameters*/
	sys_var.core_freq = get_core_freq();
	sys_var.APB1_freq = get_apb_freq(1);
	sys_var.APB2_freq = get_apb_freq(2);
}

void tim2_init(void)
{

	RCC->apb1enr.TIM2EN = 1;

	TIM2->cr1.URS = 1;
	TIM2->cr1.DIR = 1;
	TIM2->cr1.ARPE = 1;
	TIM2->cr2.MMS = 2;
	TIM2->dier.UIE = 1;
	TIM2->PSC = 0;
	TIM2->ARR = 17;
}

void adc1_dma_init(void *arr, unsigned short ln)
{
	RCC->ahb1enr.DMA2EN = 1;
	DMA2_Stream0->PAR = (unsigned int) & ADC1->DR;
	DMA2_Stream0->M0AR = (unsigned int) arr;
	DMA2_Stream0->cr.DIR = 0;
	DMA2_Stream0->cr.MINC = 1;
	DMA2_Stream0->cr.PFCTRL = 0;
	DMA2_Stream0->cr.MSIZE = 0;
	DMA2_Stream0->cr.PSIZE = 0;
	DMA2_Stream0->cr.CIRC = 1;
	DMA2_Stream0->cr.CHSEL = 0;
	DMA2_Stream0->cr.PL = 1;
	DMA2_Stream0->cr.MINC = 1;
	DMA2_Stream0->cr.TCIE = 1;
	DMA2_Stream0->NDTR = ln;

	DMA2_Stream0->cr.EN = 1;

	NVIC_EnableIRQ(DMA2_Stream0_IRQn); //activation of DMA2 stream0 interrupt
}

void adc1_init(void)
{

	RCC->ahb1enr.GPIOCEN = 1;
	PORTC->moder.MODER1 = 3;
	/*Clk feed activation*/
	RCC->apb2enr.ADCEN = 1;
	/*8Bit operation*/
	ADC1->cr1.RES = 2;
	ADC1->cr1.DISCEN = 1;
	/*TIM2 is pulse source*/
	ADC1->cr2.EXTEN = 1;
	ADC1->cr2.EXTSEL = 6;
	/*DMA request activated*/
	ADC1->cr2.DMA = 1;
	ADC1->cr2.DDS = 1;
	ADC1->cr2.EOCS = 1;
	ADC1->cr1.EOCIE = 1;
	ADC1->sqr3.SQ1 = 11;
	ADC1->cr2.ADON = 1;
}
