/*
 * Project: GUI library for microcontrollers /items/button
 * Author: Gokhan Gunay, ghngunay@gmail.com
 * Copyright: (C) 2018 by Gokhan Gunay
 * License: GNU GPL v3 (see License.txt)
 */

#include "glcd.h"
#include "mem_man.h"
#include "hardware_init.h"

#ifndef BUTTON_H_
#define BUTTON_H_

enum button_retval_e
{
	button_ok = 0, button_prev_alloc = -1, button_alloc_er = -2, button_lcd_er = -2,
};

typedef enum button_retval_e button_retval_t;


struct button_s
{
	union
	{
		struct
		{
			unsigned char visible :1;
			unsigned char hold :1;
			unsigned RESERVED :6;
		} status;
		unsigned char Status;
	};
	union
	{
		struct
		{
			unsigned clicked :1;
			unsigned pressed :1;
		} event;
		unsigned char Event;
	};

	unsigned short int pos_x;
	unsigned short int pos_y;
	unsigned char len_x;
	unsigned char len_y;
	unsigned short int back_color;
	unsigned short int font_color;
	unsigned short int back_color_clicked;
	unsigned char label[16];

	void (*button_fill)(struct button_s * button_p);
	void (*button_action)(void);
	unsigned char (*button_pressed)(struct button_s * button_p,unsigned short pos_x,unsigned short pos_y);

};

typedef struct button_s button_t;

button_retval_t button_init(button_t **button_pp,unsigned char but_num);
button_retval_t button_deinit(button_t **button_pp);

#endif
