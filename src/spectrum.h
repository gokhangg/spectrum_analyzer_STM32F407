/*
 * Project: Spectrum analyzer application on STM32F407 MCU
 * Note: This file is not intended as a library can be manipulated as per desire
 * Author: Gokhan Gunay, ghngunay@gmail.com
 * Copyright: (C) 2018 by Gokhan Gunay
 * License: GNU GPL v3 (see License.txt)
 */

#include <hardware_init.h>
#include "arm_math.h"
#include <math.h>
#include <stdlib.h>

#ifndef SPECTRUM_H_
#define SPECTRUM_H_

#define Vref 3.06f
#define spect_lngth 256
#define start_freq 10000
#define rat1 1000/256

union spectrum_status_u
{
	struct
	{
		uint8_t new_data :1;
		uint8_t processed :1;
		uint8_t RESERVED :6;
	};
	uint8_t STATUS;
};

typedef union spectrum_status_u spectrum_status_t;

/*
  * @brief  sets upper frequency for the spectrum analyzer.
  * @param  freq: desired upper band frequency.
  * @retval absolute difference between the requested and set frequency
 */
uint32_t set_upper_freq(uint32_t freq);

/*
  * @brief  gets upper frequency for the spectrum analyzer.
  * @retval upper frequency for the spectrum analyzer.
 */
uint32_t get_upper_freq(void);


/*
  * @brief  inits spectrum analyzer.
  * @param  out_arr_: array pointer to the line plot.
 */
void spectrum_init(float *out_arr_);

/*
  * @brief  gets fft of raw adc samples.
  *@retval returns 0 if done otherwise 1.
 */
uint32_t spectrum_process(void);

#endif /* SPECTRUM_H_ */
