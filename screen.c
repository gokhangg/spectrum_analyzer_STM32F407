/*
 * Project: Screen layer application STM32F407 MCU
 * Note: This file is not intended as a library can be manipulated as per desire
 * Author: Gokhan Gunay, ghngunay@gmail.com
 * Copyright: (C) 2018 by Gokhan Gunay
 * License: GNU GPL v3 (see License.txt)
 */


#include "screen.h"

form_t *form_p;

extern spectrum_status_t spectrum_status;

void button0_action(void);
void button1_action(void);

void init_screen(void)
{

	form_init(&form_p);

	form_p->button_num = 2;//Number of buttons on this form

	touchpad_init(&form_p->touchpad_p, spi2_init, NULL);
	lcd_init(&form_p->lcd_p, fscm_init, NULL);
	if (graph_init(&form_p->graph_p, 256, 1) != graph_ok)
	{
		//An error caught during initialization, handle here
	}
	
	if (button_init(&form_p->button_p, form_p->button_num) != button_ok)
	{
		//An error caught during initialization, handle here
	}

	form_p->graph_p->grid_color = Red;
	form_p->graph_p->Status = 1;
	form_p->graph_p->x_start = 33;
	form_p->graph_p->x_width = 256;
	form_p->graph_p->x_grid_cnt = 8;
	form_p->graph_p->y_start = 23;
	form_p->graph_p->y_width = 180; //initialization of graph variable
	form_p->graph_p->y_grid_cnt = 9;

	form_p->graph_p->back_color = Black; //initialization of graph variable

	form_p->graph_p->lines[0].color = Green;
	sprintf((char*) form_p->graph_p->lines[0].x_legend, "Frequency (KHz)");
	form_p->graph_p->lines[0].x_max = start_freq / 1000;
	form_p->graph_p->lines[0].x_min = 0;
	sprintf((char*) form_p->graph_p->lines[0].y_legend, "Amplitute (mV)");
	form_p->graph_p->lines[0].y_max = 3500.f;
	form_p->graph_p->lines[0].y_min = -0.0f;
	form_p->graph_p->lines[0].thickness = 0;

	form_p->graph_p->fill_back();
	form_p->graph_p->fill_legend(0);

	form_p->button_p[0].back_color = Red;
	form_p->button_p[0].back_color_clicked = Cyan;
	form_p->button_p[0].pos_x = 295;
	form_p->button_p[0].pos_y = 25;
	form_p->button_p[0].len_x = 15;
	form_p->button_p[0].len_y = 75;

	form_p->button_p[0].label[0] = 127; //Up arrow
	form_p->button_p[0].label[1] = 127; //Up arrow
	form_p->button_p[0].label[2] = 0; //end of string

	form_p->button_p[0].font_color = Yellow;
	form_p->button_p[0].Status = 0;
	form_p->button_p[0].Event = 0;
	form_p->button_p[0].status.visible = 1;
	form_p->button_p[0].button_action = button0_action;
	form_p->button_p[0].button_fill(&form_p->button_p[0]);

	form_p->button_p[1].back_color = Red;
	form_p->button_p[1].back_color_clicked = Cyan;
	form_p->button_p[1].pos_x = 295;
	form_p->button_p[1].pos_y = 125;
	form_p->button_p[1].len_x = 15;
	form_p->button_p[1].len_y = 75;

	form_p->button_p[1].label[0] = 128; //Down arrow
	form_p->button_p[1].label[1] = 128; //Down arrow
	form_p->button_p[1].label[2] = 0; //end of string

	form_p->button_p[1].font_color = Yellow;
	form_p->button_p[1].Status = 0;
	form_p->button_p[1].Event = 0;
	form_p->button_p[1].status.visible = 1;
	form_p->button_p[1].button_action = button1_action;
	form_p->button_p[1].button_fill(&form_p->button_p[1]);

}

void refresh_screen(void)
{
	form_p->events();

	if (spectrum_status.processed)
	{
		form_p->graph_p->fill_graph();
		spectrum_status.processed = 0;
		DMA2_Stream0->cr.EN = 1;
		TIM2->cr1.CEN = 1;
	}
}

unsigned int freq = start_freq;

void button0_action(void)
{
	if (freq >= 1000000)
	{
		goto MHz;
	}
	else if (freq >= 100000)
	{
		freq += 100000;

		if (freq >= 1000000)
			goto MHz;
		goto KHz;
	}
	else if (freq >= 10000)
	{
		freq += 10000;
		goto KHz;
	}
	else if (freq >= 1000)
	{
		freq += 1000;
		goto KHz;
	}
	else
	{
		freq += 100;
		if (freq >= 1000)
			goto KHz;
		goto Hz;
	}

	MHz:

	form_p->graph_p->lines[0].x_max = ((float) freq) / 1000000.0;
	sprintf((char*) form_p->graph_p->lines[0].x_legend, "Frequency (MHz)");
	goto rtn;

	KHz:

	form_p->graph_p->lines[0].x_max = ((float) freq) / 1000.0;
	sprintf((char*) form_p->graph_p->lines[0].x_legend, "Frequency (KHz)");
	goto rtn;

	Hz:

	form_p->graph_p->lines[0].x_max = ((float) freq);
	sprintf((char*) form_p->graph_p->lines[0].x_legend, " Frequency (Hz) ");

	rtn:

	set_upper_freq(freq);
	form_p->graph_p->status.legend_w=1;
}

void button1_action(void)
{

	if (freq >= 1000000)
	{
		freq -= 100000;
		goto KHz;
	}
	else if (freq > 100000)
	{
		freq -= 100000;
		goto KHz;
	}
	else if (freq > 10000)
	{
		freq -= 10000;
		goto KHz;
	}
	else if (freq > 1000)
	{
		freq -= 1000;
		goto KHz;
	}
	else if (freq > 400)
	{
		freq -= 100;
		goto Hz;
	}
	else
	{
		goto Hz;
	}

	KHz:

	form_p->graph_p->lines[0].x_max = ((float) freq) / 1000.0;
	sprintf((char*) form_p->graph_p->lines[0].x_legend, " Frequency (KHz)");
	goto rtn;

	Hz:

	form_p->graph_p->lines[0].x_max = ((float) freq);
	sprintf((char*) form_p->graph_p->lines[0].x_legend, " Frequency (Hz) ");

	rtn:

	set_upper_freq(freq);
	form_p->graph_p->status.legend_w=1;
}
