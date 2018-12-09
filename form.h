/*
 * Project: GUI library for microcontrollers /items/form
 * Author: Gokhan Gunay, ghngunay@gmail.com
 * Copyright: (C) 2018 by Gokhan Gunay
 * License: GNU GPL v3 (see License.txt)
 */

#include "glcd.h"
#include "mem_man.h"
#include "button.h"
#include "graph.h"
#include "touchpad.h"

#ifndef FORM_H_
#define FORM_H_

#define debug__ 0

enum form_retval_e
{
	form_ok = 0, form_prev_alloc = -1, form_alloc_er = -2, form_lcd_er = -3,
};

typedef enum form_retval_e form_retval_t;

struct form_s
{
	button_t *button_p;
	unsigned char button_num;
	graph_t *graph_p;
	touchpad_t *touchpad_p;
	lcd_t *lcd_p;
	unsigned char FormIndex;
	unsigned short int FormBackColor;

	union
	{
		struct
		{
			unsigned clicked :1;
			unsigned active :1;
			unsigned cleared :1;
			unsigned new_item :1;
			unsigned graph_used :1;
		} status;

		unsigned char Status;
	};

	graph_retval_t (*graph_init)(graph_t **graph_pp, uint16_t width,
			uint8_t ln_nm);
	graph_retval_t (*graph_deinit)(graph_t **graph_pp, uint8_t deinit_lcd);
	void (*events)(void);
};

typedef struct form_s form_t;

form_retval_t form_init(form_t **form_pp);
form_retval_t form_deinit(form_t **form_pp);

#endif
