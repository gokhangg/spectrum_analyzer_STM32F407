/*
 * Project: GUI library for microcontrollers /items/graph
 * Author: Gokhan Gunay, ghngunay@gmail.com
 * Copyright: (C) 2018 by Gokhan Gunay
 * License: GNU GPL v3 (see License.txt)
 */

#include "glcd.h"
#include "mem_man.h"

#ifndef GRAPH_H_
#define GRAPH_H_

enum graph_retval_e
{
	graph_ok = 0, graph_prev_alloc = -1, graph_alloc_er = -2, graph_lcd_er = -3,
};

typedef enum graph_retval_e graph_retval_t;

struct line_s
{
	unsigned char x_legend[20];
	unsigned char y_legend[20];
	unsigned short color;
	float * arr;
	float * old_arr;
	float x_max;
	float x_min;
	float y_max;
	float y_min;
	unsigned char thickness;
};

typedef struct line_s line_t;

struct graph_s
{
	union
	{
		struct
		{
			unsigned legend_w :1;
		} status;
		unsigned char Status;
	};

	unsigned short x_start;
	unsigned char y_start;
	unsigned short x_width;
	unsigned char y_width;
	unsigned char x_grid_width;
	unsigned char y_grid_width;
	unsigned char x_grid_cnt;
	unsigned char y_grid_cnt;
	unsigned short grid_color;
	unsigned short back_color;
	lcd_t *lcd_p;
	unsigned char line_num;
	line_t *lines;
	void (*fill_back)(void);
	void (*fill_legend)(unsigned char l);
	void (*fill_graph)(void);

//GRAPH(unsigned int16_t int sz);
};

typedef struct graph_s graph_t;

graph_retval_t graph_init(graph_t **graph_pp, unsigned short width, unsigned char ln_nm);
graph_retval_t graph_deinit(graph_t **graph_pp, unsigned char deinit_lcd);

#endif /* GRAPH_H_ */
