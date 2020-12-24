/*
 * Project: Spectrum analyzer application main file
 * Note: This file is not intended as a library can be manipulated as per desire
 * Author: Gokhan Gunay, ghngunay@gmail.com
 * Copyright: (C) 2018 by Gokhan Gunay
 * License: GNU GPL v3 (see License.txt)
 */


#include "main.h"

extern form_t *form_p;

void screen(void *pvParameters);
void spectrum_analyzer(void *pvParameters);
void touchpad(void *pvParameters);

int main(void)
{
	rcc_init();

	xTaskCreate(screen, "Task 2", 400, NULL, 3, NULL);
	xTaskCreate(spectrum_analyzer, "Task 1", 400, NULL, 2, NULL);
	xTaskCreate(touchpad, "Task 3", 100, NULL, 1, NULL);
	vTaskStartScheduler();

	for (;;)
		;
}

void spectrum_analyzer(void *pvParameters)
{

	uint32_t xLastWakeTime = xTaskGetTickCount();

	if (form_p->graph_p == NULL)
	{
		vTaskDelayUntil(&xLastWakeTime, 90);
	}
	spectrum_init(form_p->graph_p->lines->arr);

	for (;;)
	{
		spectrum_process();
		vTaskDelayUntil(&xLastWakeTime, 90);
	}
}

void touchpad(void *pvParameters)
{
	uint32_t xLastWakeTime = xTaskGetTickCount();
	touchpad_t *touchpad_p;
	touchpad_init(&touchpad_p, spi2_init, NULL);
	for (;;)
	{

		form_p->touchpad_p->read_pos(); //conversion of raw data to coordinates

		vTaskDelayUntil(&xLastWakeTime, 50);
	}
}

void screen(void *pvParameters)
{

	uint32_t xLastWakeTime = xTaskGetTickCount();
	init_screen();

	for (;;)
	{
		refresh_screen();
		vTaskDelayUntil(&xLastWakeTime, 100);
	}
}

