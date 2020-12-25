/*
 * Project: GUI library for microcontrollers /items/form
 * Author: Gokhan Gunay, ghngunay@gmail.com
 * Copyright: (C) 2018 by Gokhan Gunay
 * License: GNU GPL v3 (see License.txt)
 */

#include "form.h"

form_t *form_p;

void events_(void)
{
	if (form_p->touchpad_p->status.NewData)
	{
#if(debug__==1)
		sprintf((char*) form_p->graph_p->lcd_p->screen_str,
				"X: %d      Y: %d    ", form_p->touchpad_p->position->pos_x,
				form_p->touchpad_p->position->pos_y);
		form_p->graph_p->lcd_p->write_str(form_p->graph_p->lcd_p->screen_str,
				50, 5, Red, Black, 0);
#endif
		for (short i = 0; i < form_p->button_num; i++)
		{
			if (form_p->button_p[i].button_pressed(&form_p->button_p[i],
					form_p->touchpad_p->position->pos_x,
					form_p->touchpad_p->position->pos_y))
			{
				if (form_p->button_p[i].event.clicked != 1)
				{
					form_p->button_p[i].event.clicked = 1;
					form_p->button_p[i].button_fill(&form_p->button_p[i]);
				}
			}
			else
			{
				if (form_p->button_p[i].event.clicked)
				{
					form_p->button_p[i].event.clicked = 0;
					form_p->button_p[i].button_fill(&form_p->button_p[i]);
					form_p->button_p[i].button_action();
				}
			}
		}
		form_p->touchpad_p->status.NewData = 0;
	}
}

form_retval_t form_init(form_t **form_pp)
{
	if (form_p != NULL) //graph was previously allocated and initialized
	{
		*form_pp = form_p;
		return form_prev_alloc;
	}
	else
	{
		form_p = (form_t*) mm_malloc(sizeof(form_t));
		*form_pp = form_p;
		if (form_p == NULL) //memory allocation error
			return form_alloc_er;
	}

	form_p->events=events_;

	return form_ok;
}

form_retval_t form_deinit(form_t **form_pp)
{

	if (form_p->graph_p != NULL)
	{
		graph_deinit(&form_p->graph_p, 0);
		form_p->graph_p = NULL;
	}
	if (form_p->button_p != NULL)
	{
		for (int i = 0; i < form_p->button_num; i++)
		{
			button_deinit(&form_p->button_p);
		}
		form_p->button_num = 0;
		form_p->button_p = NULL;
	}
	mm_free(form_p);
	*form_pp = form_p;
	return form_ok;
}
