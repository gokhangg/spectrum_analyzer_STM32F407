/*
 * Project: Spectrum analyzer application on STM32F407 MCU
 * Note: This file is not intended as a library can be manipulated as per desire
 * Author: Gokhan Gunay, ghngunay@gmail.com
 * Copyright: (C) 2018 by Gokhan Gunay
 * License: GNU GPL v3 (see License.txt)
 */


#include "spectrum.h"

spectrum_status_t spectrum_status;

static arm_rfft_fast_instance_f32 S;

uint8_t adc_arr[spect_lngth];
float *out_arr;
float in_arr[spect_lngth];

float ratio = (Vref / 255.0f);
uint8_t sm1 = 0;

uint32_t get_upper_freq(void)
{
	uint32_t var = get_core_freq() / (4);

	var/=(((uint32_t) (TIM2->PSC + 1)) * ((uint32_t) (TIM2->ARR + 1)));
	return var ;
}

uint32_t set_upper_freq(uint32_t freq)
{
	uint32_t var = get_core_freq() / (8 * freq);
	int32_t var2;

	TIM2->cr1.CEN = 0;
	DMA2_Stream0->cr.EN=0;
	if (var < 0xFFFF)
	{
		TIM2->PSC = 1;
		TIM2->ARR = (var) - 1;
	}
	else if (var < 0x1FFFF)
	{
		TIM2->PSC = 3;
		TIM2->ARR = (var >> 1) - 1;
	}
	else if (var < 0x3FFFF)
	{
		TIM2->PSC = 7;
		TIM2->ARR = (var >> 2) - 1;
	}
	DMA2_Stream0->cr.EN=1;
	TIM2->cr1.CEN = 1;
	var2=get_upper_freq()-freq;
	if (var2<0)
	{
		return (uint32_t)-var2;
	}
	return var2;
}

void spectrum_init(float *out_arr_)
{
	uint16_t ln = spect_lngth;
	out_arr = out_arr_;
	arm_rfft_fast_init_f32(&S, ln);

	tim2_init();
	adc1_init();
	adc1_dma_init((void*) adc_arr,ln);

	set_upper_freq(start_freq);
	TIM2->cr1.CEN = 1;
}

uint32_t spectrum_process(void)
{

	if (spectrum_status.new_data)
	{

		for (uint16_t i = 0; i < 256; i++)
		{
			in_arr[i] = ratio * ((float) adc_arr[i]);
		}
		arm_rfft_fast_f32(&S, in_arr, out_arr, 0);
		for (uint16_t i = 0; i < 256; i++)
			out_arr[i] = abs(out_arr[i])*rat1;
		spectrum_status.new_data = 0;
		spectrum_status.processed = 1;
		return 0;
	}
	return -1;
}


