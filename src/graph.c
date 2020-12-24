/*
 * Project: GUI library for microcontrollers /items/graph
 * Author: Gokhan Gunay, ghngunay@gmail.com
 * Copyright: (C) 2018 by Gokhan Gunay
 * License: GNU GPL v3 (see License.txt)
 */

#include "graph.h"
#include "glcd.h"

void fill_legend_(unsigned char l);

void fill_back_(void);

void fill_graph_(void);

void refresh_graph(graph_t *graph_p, unsigned char ln_nm);

graph_t *graph_p = NULL;

graph_retval_t graph_init(graph_t **graph_pp, unsigned short width,
		unsigned char ln_nm)
{

	if (graph_p != NULL) //graph was previously allocated and initialized
	{
		*graph_pp = graph_p;
		return graph_prev_alloc;
	}
	else
	{
		graph_p = (graph_t*) mm_malloc(sizeof(graph_t));
		*graph_pp = graph_p;
		if (graph_p == NULL) //memory allocation error
			return graph_alloc_er;

		lcd_init(&graph_p->lcd_p, NULL, NULL);
		if (graph_p->lcd_p == NULL) //lcd error
		{
			mm_free(graph_p);
			*graph_pp = graph_p;
			return graph_lcd_er;
		}

	}

	graph_p->lines = (line_t*) mm_malloc(ln_nm * sizeof(line_t));
	if (graph_p->lines == NULL)
	{
		mm_free(graph_p);
		return graph_alloc_er;
	}

	for (int i = 0; i < ln_nm; i++)
	{
		graph_p->lines[i].arr = (float*) mm_malloc(2 * width * sizeof(float));
		if ((graph_p->lines[i].arr == NULL))
		{
			for (int ii = 0; ii < i; ii++)
			{
				mm_free(graph_p->lines[ii].arr);
			}
			mm_free(graph_p->lines);
			mm_free(graph_p);
			return graph_alloc_er;
		}
		graph_p->lines[i].old_arr = graph_p->lines[i].arr + width;
	}
	graph_p->line_num = ln_nm;
	graph_p->x_width = width;
	for (int j = 0; j < ln_nm; j++)
	{
		for (int i = 0; i < width; i++)
		{
			graph_p->lines[j].arr[i] = 0.f;
		}
	}
	graph_p->fill_back = fill_back_;
	graph_p->fill_legend = fill_legend_;
	graph_p->fill_graph = fill_graph_;
	return graph_ok;
}

graph_retval_t graph_deinit(graph_t **graph_pp, unsigned char deinit_lcd)
{
	if (graph_p == NULL)
	{
		return graph_alloc_er;
	}

	for (int i = 0; i < (*graph_pp)->line_num; i++)
	{
		mm_free(graph_p->lines[i].arr);

	}
	mm_free(graph_p->lines);
	if (deinit_lcd != 0)
	{
		mm_free(graph_p->lcd_p);
	}
	mm_free(graph_p);
	return graph_ok;
}

void fill_back__(graph_t *graph_p)
{
	lcd_t *lcd_p = graph_p->lcd_p;
	unsigned short j, k;
	lcd_p->set_range(graph_p->x_start, graph_p->x_width + graph_p->x_start,
			graph_p->y_start, graph_p->y_width + graph_p->y_start);

	k = (graph_p->x_width + 1) * (graph_p->y_width + 1); ////Fill grid area with back color

	lcd_p->set_cursor(graph_p->x_start, graph_p->y_start);
	lcd_p->reg_add(0x22);
	for (j = 0; j < k; j++)
	{
		LCD_RAM = (graph_p->back_color);
	} ////Fill grid area with back color
}

void legend_layer(graph_t *graph_p, unsigned char ln_nm)
{
	unsigned short k;
	line_t * line_p = &graph_p->lines[ln_nm];
	lcd_t *lcd_p = graph_p->lcd_p;
	unsigned short y_end = graph_p->y_start + graph_p->y_width;
	unsigned short x_end = graph_p->x_start + graph_p->x_width;

	lcd_p->screen_str[0] = 127;
	sprintf((char*) &lcd_p->screen_str[1], "%.2f", line_p->x_min);
	lcd_p->write_str(graph_p->lcd_p->screen_str, graph_p->x_start - 2,
			y_end + 2, line_p->color, graph_p->back_color, lcd_hor);
	lcd_p->screen_str[0] = sprintf((char*) &lcd_p->screen_str[1], "  %.2f",
			line_p->x_max);
	lcd_p->screen_str[(unsigned char) lcd_p->screen_str[0]] = 127;
	lcd_p->write_str(&lcd_p->screen_str[1],
			x_end - 6 * lcd_p->screen_str[0] + 3, y_end + 2, line_p->color,
			graph_p->back_color, lcd_hor);
	lcd_p->screen_str[0] = 127;

	sprintf((char*) &lcd_p->screen_str[1], "%.2f  ",
			(line_p->x_min + line_p->x_max) / 2.0);
	lcd_p->write_str(lcd_p->screen_str,
			graph_p->x_start + (graph_p->x_width / 2) - 2, y_end + 2,
			line_p->color, graph_p->back_color, lcd_hor);
	k = 0;
	while ((line_p->x_legend[k]) != 0)
	{
		k++;
	}
	lcd_p->write_str(&line_p->x_legend[0],
			graph_p->x_start + (graph_p->x_width - 6 * k) / 2, y_end + 10,
			line_p->color, graph_p->back_color, lcd_hor);
	lcd_p->screen_str[0] = 128;
	sprintf((char*) &lcd_p->screen_str[1], "%.2f", line_p->y_min);
	lcd_p->write_str(lcd_p->screen_str, graph_p->x_start - 9, y_end + 2,
			line_p->color, graph_p->back_color, lcd_ver_up);
	lcd_p->screen_str[0] = 128;
	sprintf((char*) &lcd_p->screen_str[1], "%.2f",
			(line_p->y_min + line_p->y_max) / 2.0f);
	lcd_p->write_str(lcd_p->screen_str, graph_p->x_start - 9,
			graph_p->y_start + (graph_p->y_width / 2) + 2, line_p->color,
			graph_p->back_color, lcd_ver_up);
	lcd_p->screen_str[0] = sprintf((char*) &lcd_p->screen_str[1], "%.2f",
			line_p->y_max);
	lcd_p->screen_str[(unsigned char) lcd_p->screen_str[0]] = 128;
	lcd_p->write_str(&lcd_p->screen_str[1], graph_p->x_start - 9,
			graph_p->y_start + 6 * lcd_p->screen_str[0] - 3, line_p->color,
			graph_p->back_color, lcd_ver_up);
	k = 0;
	while ((line_p->y_legend[k]) != 0)
	{
		k++;
	}
	lcd_p->write_str(line_p->y_legend, graph_p->x_start - 17,
			graph_p->y_start + (graph_p->y_width + 6 * k) / 2, line_p->color,
			graph_p->back_color, lcd_ver_up);
	graph_p->status.legend_w = 0;

}

void grid_layer(graph_t *graph_p)
{
	lcd_t *lcd_p = graph_p->lcd_p;
	unsigned short i, j;
	unsigned short y_grid_width = graph_p->y_width / graph_p->y_grid_cnt;
	unsigned short x_grid_width = graph_p->x_width / graph_p->x_grid_cnt;
	if (graph_p->grid_color != 0)
	{
		lcd_p->write_reg(0x0011, 0x6078);
		for (i = 0; i <= graph_p->y_grid_cnt; i++)
		{
			lcd_p->set_cursor(graph_p->x_start,
					(graph_p->y_start + i * y_grid_width));
			lcd_p->reg_add(0x22);
			for (j = 0; j <= graph_p->x_width; j++)
			{
				LCD_RAM = (graph_p->grid_color);
			}
		}
		// vsmode DFM1 DFM0 TRANS OEDef WMode DMode1 DMode0 TY1 TY0 ID1 ID0 AM LG2 LG2 LG0
		//   0     1    1     0     0     0     0      0     0   1   1   1   0  0   0   0
		lcd_p->write_reg(0x0011, 0x6070);

		for (i = 0; i <= graph_p->x_grid_cnt; i++)
		{

			lcd_p->set_cursor((graph_p->x_start + i * x_grid_width),
					graph_p->y_start);
			lcd_p->reg_add(0x22);
			for (j = 0; j <= graph_p->y_width; j++)
			{
				LCD_RAM = (graph_p->grid_color);
			}
		}
	}
}

void fill_gr(graph_t *graph_p, unsigned char ln_nm, unsigned char rm)
{
	line_t *line_p = &graph_p->lines[ln_nm];
	unsigned short color = 0;
	unsigned char thickness = line_p->thickness;
	float *ar_p, *old_ar_p;
	int16_t i = 0, k = 0;
	unsigned short y_end = graph_p->y_start + graph_p->y_width;
	float y_min = line_p->y_min;
	float gr_y_wdth = line_p->y_max - y_min;
	float gr_y_rat = ((float) graph_p->y_width) / gr_y_wdth;
	float diff = 0.0f;
	unsigned char h_tic = (2 * thickness + 1) >> 1;
	lcd_t *lcd_p = graph_p->lcd_p;
	unsigned short x_start = graph_p->x_start;

	unsigned short x_width = graph_p->x_width;
	thickness = 2 * thickness + 1;

	if (rm)
	{
		ar_p = line_p->old_arr;
		old_ar_p = NULL;
		color = graph_p->back_color;
	}
	else
	{
		ar_p = line_p->arr;
		old_ar_p = line_p->old_arr;
		color = line_p->color;
	}

	lcd_p->set_cursor(x_start,
			(y_end) + h_tic
					- ((unsigned short) (gr_y_rat * (ar_p[0] - y_min))));
	lcd_p->write_reg(0x0011, 0x6060);
	lcd_p->reg_add(0x22);
	k = thickness;
	while (k-- > 0)
	{
		LCD_RAM = (color);
	}
	if (old_ar_p != NULL)
		old_ar_p[0] = ar_p[0];

	for (i = 1; i < x_width; i++)
	{
		diff = ar_p[i] - ar_p[i - 1];
		if (diff > 0.0f)
		{
			// vsmode DFM1 DFM0 TRANS OEDef WMode DMode1 DMode0 TY1 TY0 ID1 ID0 AM LG2 LG2 LG0
			//   0     1    1     0     0     0     0      0     0   1   1   0   0  0   0   0
			lcd_p->write_reg(0x0011, 0x6060);
			k = (unsigned short) (gr_y_rat * (diff));
			lcd_p->set_cursor(x_start + i,
					y_end + h_tic
							- ((unsigned short) (gr_y_rat
									* (ar_p[i - 1] - y_min))));
		}
		else
		{
			// vsmode DFM1 DFM0 TRANS OEDef WMode DMode1 DMode0 TY1 TY0 ID1 ID0 AM LG2 LG2 LG0
			//   0     1    1     0     0     0     0      0     0   1   1   1   0  0   0   0
			lcd_p->write_reg(0x0011, 0x6070);
			k = 0;
			k = (unsigned short) (gr_y_rat * (-diff));
			lcd_p->set_cursor(x_start + i,
					y_end - h_tic
							- ((unsigned short) (gr_y_rat
									* (ar_p[i - 1] - y_min))));
		}

		lcd_p->reg_add(0x22);
		k += thickness;
		while (k-- > 0)
		{
			LCD_RAM = (color);
		}
		if (old_ar_p != NULL)
			old_ar_p[i] = ar_p[i];
	}

}

inline void refresh_graph(graph_t *graph_p, unsigned char ln_nm)
{

	if (graph_p->status.legend_w)
	{
		for (unsigned short nm = 0; nm < ln_nm; nm++)
		{
			legend_layer(graph_p, nm);
		}
		graph_p->status.legend_w = 0;
	}
	for (unsigned short nm = 0; nm < ln_nm; nm++)
	{
		fill_gr(graph_p, nm, 1);
		fill_gr(graph_p, nm, 0);
	}
	grid_layer(graph_p);
	for (unsigned short nm = 0; nm < ln_nm; nm++)
	{
		fill_gr(graph_p, nm, 0);
	}

	graph_p->lcd_p->write_reg(0x0044, 0xEF00);
	graph_p->lcd_p->write_reg(0x0045, 0x0000);
	graph_p->lcd_p->write_reg(0x0046, 0x013F);
	graph_p->lcd_p->write_reg(0x0011, 0x6078);
}

void fill_legend_(unsigned char l)
{
	legend_layer(graph_p, l);
}

void fill_back_(void)
{
	fill_back__(graph_p);
}

void fill_graph_(void)
{
	refresh_graph(graph_p, graph_p->line_num);
}
