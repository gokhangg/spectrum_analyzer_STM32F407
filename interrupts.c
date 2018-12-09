/*
 * Project: Spectrum analyzer application interruptions file
 * Note: This file is not intended as a library can be manipulated as per desire
 * Author: Gokhan Gunay, ghngunay@gmail.com
 * Copyright: (C) 2018 by Gokhan Gunay
 * License: GNU GPL v3 (see License.txt)
 */

#include "interrupts.h"

extern uint16_t RawData[3];
extern touchpad_status_t touchpad_status;
extern spectrum_status_t spectrum_status;

touchpad_t *touchpad_p;

void interrupts_init(void)
{

	touchpad_init(&touchpad_p, NULL, NULL);

}

void assert_param(uint8_t* file, uint32_t line)
{
}

void SPI2_IRQHandler(void)
{

	touchpad_spi_int();
}

void EXTI9_5_IRQHandler(void)
{
	EXTI->imr.MR5 = 0; // EXTI5 interrupt is inactive
	//touchscreen.Status=0;
	//SPI2->CR2 |= BIT_6;		// SPI2 interrupt is active
	EXTI->PR |= BIT_5; // Clearing pending bit for EXTI5

	//EXTI->imr.MR5 = 1;
}

void DMA2_Stream0_IRQHandler(void)
{
	TIM2->cr1.CEN = 0;
	//DMA_Cmd(DMA2_Stream0, DISABLE); //initialization of DMA2 stream 0
	DMA2_Stream0->cr.EN = 0;
	DMA2->LIFCR |= (BIT_0 | BIT_2 | BIT_3 | BIT_4 | BIT_5 | BIT_6);
	spectrum_status.new_data = 1;
}

void NMI_Handler(void)
{
	/* Go into an infinite loop. */
	while (1)
	{
	}
}

void HardFault_Handler(void)
{
	/* Go into an infinite loop. */

	while (1)
	{
	}
}

void MemManage_Handler(void)
{
	/* Go into an infinite loop. */
	while (1)
	{
	}
}
void BusFault_Handler(void)
{
	/* Go into an infinite loop. */
	while (1)
	{
	}
}

void UsageFault_Handler(void)
{
	/* Go into an infinite loop. */
	while (1)
	{
	}
}

void DebugMon_Handler(void)
{
	/* Go into an infinite loop. */
	while (1)
	{
	}
}
