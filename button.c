
/*
 * Project: GUI library for microcontrollers /items/button
 * Author: Gokhan Gunay, ghngunay@gmail.com
 * Copyright: (C) 2018 by Gokhan Gunay
 * License: GNU GPL v3 (see License.txt)
 */

#include "button.h"

lcd_t *lcd_p;

unsigned char button_pressed_(struct button_s * button_p, unsigned short pos_x,
		unsigned short pos_y)
{
	if ((button_p->pos_x > pos_x)
			|| (button_p->len_x + button_p->pos_x < pos_x))
	{
		return 0;
	}
	if ((button_p->pos_y > pos_y)
			|| (button_p->len_y + button_p->pos_y < pos_y))
	{
		return 0;
	}
	return 1;

}

void button_fill_(button_t *button_p)
{
	if (button_p->status.visible)
	{
		unsigned char j = 0;
		for (j = 0; j < 16; j++)
		{
			if (button_p->label[j] == 0)
				break;
		}

		if (button_p->event.clicked)
		{
			lcd_p->fill_screen(button_p->back_color_clicked, button_p->pos_x,
					button_p->pos_x + button_p->len_x, button_p->pos_y,
					button_p->pos_y + button_p->len_y);
			lcd_p->write_str(button_p->label,
					1 + button_p->pos_x + (button_p->len_x - 6 * j) / 2,
					(unsigned char) button_p->pos_y + (button_p->len_y - 8) / 2,
					button_p->font_color, button_p->back_color_clicked,
					lcd_hor);
		}
		else
		{
			lcd_p->fill_screen(button_p->back_color, button_p->pos_x,
					button_p->pos_x + button_p->len_x, button_p->pos_y,
					button_p->pos_y + button_p->len_y);
			lcd_p->write_str(button_p->label,
					1 + button_p->pos_x + (button_p->len_x - 6 * j) / 2,
					(unsigned char) button_p->pos_y + (button_p->len_y - 8) / 2,
					button_p->font_color, button_p->back_color, lcd_hor);
		}
	}
}

button_retval_t button_init(button_t **button_pp, unsigned char but_num)
{

	lcd_init(&lcd_p, NULL, NULL);
	if (lcd_p == NULL)
	{
		*button_pp = NULL;
		return button_lcd_er;
	}

	if (*button_pp != NULL)
		return button_prev_alloc;
	*button_pp = mm_malloc(but_num * sizeof(button_t));
	if (*button_pp == NULL)
		return button_alloc_er;

	for (short i = 0; i < but_num; i++)
	{
		(*button_pp)[i].button_fill = button_fill_;
		(*button_pp)[i].button_pressed = button_pressed_;
	}
	return button_ok;
}

button_retval_t button_deinit(button_t **button_pp)
{
	mm_free(*button_pp);
	return button_ok;
}
