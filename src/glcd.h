/*
 * Project: GUI library for STM32F4XX microcontrollers /items/glcd
 * Author: Gokhan Gunay, ghngunay@gmail.com
 * Copyright: (C) 2018 by Gokhan Gunay
 * License: GNU GPL v3 (see License.txt)
 */

#include "mem_man.h"

#ifndef LCD__
#define LCD__

#define LCD_REG              (*((volatile unsigned short *) 0x60000000)) /* RS = 0 */
#define LCD_RAM              (*((volatile unsigned short *) 0x60020000)) /* RS = 1 */


#define White            0xFFFF
#define Black            0x0000
#define Grey             0x7BEF
#define Blue             0x001F
#define Blue2            0x051F
#define Red              0xF800
#define Magenta          0xF81F
#define Green            0x07E0
#define Cyan             0x7FFF
#define Yellow           0xFFE0

enum
{
	lcd_ver_down = 2, lcd_ver_up = 1, lcd_hor = 0,
};

union COLOR
{
	struct
	{
		unsigned B :5;
		unsigned G :6;
		unsigned R :5;
	};
	unsigned short COLOR;
} ;


enum lcd_retval_e
{
	lcd_ok = 0, lcd_prev_alloc = -1, lcd_alloc_er = -2, lcd_hard_er = -3,
};

typedef enum lcd_retval_e lcd_retval_t;

struct lcd_s
{
	unsigned char screen_str[40];
	unsigned short fill_color;
	unsigned short color; //Global variable for color of written pixel
	unsigned short cor_x; //Global variable for x coordinate of the screen
	unsigned short cor_y; //Global variable for y coordinate of the screen

	void (*write_dot)(unsigned char character);
	void (*write_str)(unsigned char * character, unsigned short x, unsigned char y, unsigned short font_color,
			unsigned short fill_color1, unsigned char direction);
	void (*fill_screen)(unsigned short color, unsigned short x_start, unsigned short x_stop, unsigned short y_start,
			unsigned short y_stop);
	void (*set_range)(unsigned short x_start, unsigned short x_stop, unsigned short y_start, unsigned short y_stop);
	void (*set_cursor)(unsigned short x, unsigned char y);
	void (*reg_add)(unsigned short add);
	void (*write_reg)(unsigned char adr, unsigned short cmd);
	void (*write_ram)(unsigned short ram);
	unsigned int (*hardware_init)(void);
	unsigned int (*hardware_deinit)(void);

};

typedef struct lcd_s lcd_t;

/*
  * @brief  initializes lcd module.
  * @param  lcd_pp: pointer to pointer to the lcd where the module allocated and initialized.
  * @param  hardware_init: hardware initialization method.
  * @param  hardware_deinit: hardware deinitialization method.
  * @retval succes condition of initialization process.
 */
lcd_retval_t lcd_init(lcd_t **lcd_pp, unsigned int (*hardware_init)(void),
		unsigned int (*hardware_deinit)(void));

/*
  * @brief  deinitializes lcd module.
  * @param  lcd_pp: pointer to pointer to the lcd where the module deallocated and deinitialized.
 */
lcd_retval_t lcd_deinit(lcd_t **lcd_pp);

#endif
