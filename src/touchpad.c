/*
 * Project: GUI library for microcontrollers /items/touchpad
 * Author: Gokhan Gunay, ghngunay@gmail.com
 * Copyright: (C) 2018 by Gokhan Gunay
 * License: GNU GPL v3 (see License.txt)
 */

#include "touchpad.h"

touchpad_t *touchpad_p;

position_t position_old;
position_t position_new;

unsigned char initialized;
unsigned short RawData[3];

void update_position_(void);
void read_position_(void);

void touchpad_init2(void)
{
	spi2_init();
}

tp_return_e touchpad_init(touchpad_t **touchpad_pp,
		unsigned int (*hardware_init)(void),
		unsigned int (*hardware_deinit)(void))
{

	if (touchpad_p != NULL)
	{
		*touchpad_pp = touchpad_p;
		return touchpad_prev_alloc;
	}

	else
	{
		touchpad_p = (touchpad_t*) mm_malloc(sizeof(touchpad_t));
		*touchpad_pp = touchpad_p;

		if (touchpad_p == NULL)
		{
			return touchpad_alloc_er;
		}
	}

	if (hardware_init == NULL)
	{
		mm_free(touchpad_p);
		*touchpad_pp = NULL;
		return touchpad_hard_er;
	}
	if (hardware_init())
	{
		mm_free(touchpad_p);
		*touchpad_pp = NULL;
		return touchpad_hard_er;
	}

	touchpad_p->update_pos = update_position_;
	touchpad_p->read_pos = read_position_;
	touchpad_p->raw_data = RawData;
	touchpad_p->position = &position_new;
	initialized = 1;
	return touchpad_ok;

}

void update_position_(void)
{
	position_old = position_new;
	position_new.pos_y = (((RawData[0] & 0x7f) << 5)
			| ((RawData[1] & 0xf800) >> 11));
	position_new.pos_x = (((RawData[1] & 0x7f) << 5)
			| ((RawData[2] & 0xf800) >> 11));
	if (position_new.pos_y == 0)
		position_new.pos_x = 0;
	if (position_new.pos_x > Calibration_start_x)
		position_new.pos_x = Calibration_start_x;
	else if (position_new.pos_x < Calibration_end_x)
		position_new.pos_x = Calibration_end_x;
	position_new.pos_x = (unsigned short int) ((320
			* (Calibration_start_x - position_new.pos_x))
			/ (Calibration_start_x - Calibration_end_x));
	if (position_new.pos_y < Calibration_start_y)
		position_new.pos_y = Calibration_start_y;
	else if (position_new.pos_y > Calibration_end_y)
		position_new.pos_y = Calibration_end_y;
	position_new.pos_y = (unsigned short) ((240
			* (position_new.pos_y - Calibration_start_y))
			/ (Calibration_end_y - Calibration_start_y));
	touchpad_p->status.NewData = 1;
	touchpad_p->status.ConFin = 0;
}

void read_position_(void)
{
	if (touchpad_p->status.ConFin)
	{
		touchpad_p->update_pos(); //conversion of raw data to coordinates

		touchpad_p->status.NewData = 1;
		PORTC->bsrr.BR4 = 1; //Strobe for spi device
		SPI2->DR = 0xD000;
	}
}

void touchpad_spi_int(void)
{
	static unsigned char i = 0;

	switch (i)
	{
	case 0:
	{
		touchpad_p->raw_data[0] = SPI2->dr.DR;
		SPI2->DR = 0x9000; //cor_y for spi device
		i = 1;
		break;
	}
	case 1:
	{
		touchpad_p->raw_data[1] = SPI2->dr.DR;
		SPI2->dr.DR = 0; //Flush for remnant parts of touch screen data
		i = 2;
		break;
	}
	case 2:
	{
		touchpad_p->raw_data[2] = SPI2->dr.DR;
		i = 0;
		PORTC->bsrr.BS4 = 1; //Shutdown for spi device
		touchpad_p->status.ConFin = 1;
		break;
	}
	}
}
void touchpad_deinit(touchpad_t **touchpad_pp)
{
	if (touchpad_p->hardware_deinit != NULL)
	{
		touchpad_p->hardware_deinit();
	}
	mm_free(touchpad_p);
	*touchpad_pp = touchpad_p;
}
