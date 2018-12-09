/*
 * Project: GUI library for STM32F4XX microcontrollers /items/glcd
 * Author: Gokhan Gunay, ghngunay@gmail.com
 * Copyright: (C) 2018 by Gokhan Gunay
 * License: GNU GPL v3 (see License.txt)
 */
#include "glcd.h"

const unsigned char FONT[98][5] =
{
{ 0x00, 0x00, 0x00, 0x00, 0x00 }, // SPACE
		{ 0x00, 0x00, 0x5F, 0x00, 0x00 }, // !
		{ 0x00, 0x03, 0x00, 0x03, 0x00 }, // "
		{ 0x14, 0x3E, 0x14, 0x3E, 0x14 }, // #
		{ 0x24, 0x2A, 0x7F, 0x2A, 0x12 }, // $
		{ 0x43, 0x33, 0x08, 0x66, 0x61 }, // %
		{ 0x36, 0x49, 0x55, 0x22, 0x50 }, // &
		{ 0x00, 0x05, 0x03, 0x00, 0x00 }, // '
		{ 0x00, 0x1C, 0x22, 0x41, 0x00 }, // (
		{ 0x00, 0x41, 0x22, 0x1C, 0x00 }, // )
		{ 0x14, 0x08, 0x3E, 0x08, 0x14 }, // *
		{ 0x08, 0x08, 0x3E, 0x08, 0x08 }, // +
		{ 0x00, 0x50, 0x30, 0x00, 0x00 }, // ,
		{ 0x08, 0x08, 0x08, 0x08, 0x08 }, // -
		{ 0x00, 0x60, 0x60, 0x00, 0x00 }, // .
		{ 0x20, 0x10, 0x08, 0x04, 0x02 }, // /
		{ 0x3E, 0x51, 0x49, 0x45, 0x3E }, // 0
		{ 0x00, 0x04, 0x02, 0x7F, 0x00 }, // 1
		{ 0x42, 0x61, 0x51, 0x49, 0x46 }, // 2
		{ 0x22, 0x41, 0x49, 0x49, 0x36 }, // 3
		{ 0x18, 0x14, 0x12, 0x7F, 0x10 }, // 4
		{ 0x27, 0x45, 0x45, 0x45, 0x39 }, // 5
		{ 0x3E, 0x49, 0x49, 0x49, 0x32 }, // 6
		{ 0x01, 0x01, 0x71, 0x09, 0x07 }, // 7
		{ 0x36, 0x49, 0x49, 0x49, 0x36 }, // 8
		{ 0x26, 0x49, 0x49, 0x49, 0x3E }, // 9
		{ 0x00, 0x36, 0x36, 0x00, 0x00 }, // :
		{ 0x00, 0x56, 0x36, 0x00, 0x00 }, // ;
		{ 0x08, 0x14, 0x22, 0x41, 0x00 }, // <
		{ 0x14, 0x14, 0x14, 0x14, 0x14 }, // =
		{ 0x00, 0x41, 0x22, 0x14, 0x08 }, // >
		{ 0x02, 0x01, 0x51, 0x09, 0x06 }, // ?
		{ 0x3E, 0x41, 0x59, 0x55, 0x5E }, // @
		{ 0x7E, 0x09, 0x09, 0x09, 0x7E }, // A
		{ 0x7F, 0x49, 0x49, 0x49, 0x36 }, // B
		{ 0x3E, 0x41, 0x41, 0x41, 0x22 }, // C
		{ 0x7F, 0x41, 0x41, 0x41, 0x3E }, // D
		{ 0x7F, 0x49, 0x49, 0x49, 0x41 }, // E
		{ 0x7F, 0x09, 0x09, 0x09, 0x01 }, // F
		{ 0x3E, 0x41, 0x41, 0x49, 0x3A }, // G
		{ 0x7F, 0x08, 0x08, 0x08, 0x7F }, // H
		{ 0x00, 0x41, 0x7F, 0x41, 0x00 }, // I
		{ 0x30, 0x40, 0x40, 0x40, 0x3F }, // J
		{ 0x7F, 0x08, 0x14, 0x22, 0x41 }, // K
		{ 0x7F, 0x40, 0x40, 0x40, 0x40 }, // L
		{ 0x7F, 0x02, 0x0C, 0x02, 0x7F }, // M
		{ 0x7F, 0x02, 0x04, 0x08, 0x7F }, // N
		{ 0x3E, 0x41, 0x41, 0x41, 0x3E }, // O
		{ 0x7F, 0x09, 0x09, 0x09, 0x06 }, // P
		{ 0x1E, 0x21, 0x21, 0x21, 0x5E }, // Q
		{ 0x7F, 0x09, 0x09, 0x09, 0x76 }, // R
		{ 0x26, 0x49, 0x49, 0x49, 0x32 }, // S
		{ 0x01, 0x01, 0x7F, 0x01, 0x01 }, // T
		{ 0x3F, 0x40, 0x40, 0x40, 0x3F }, // U
		{ 0x1F, 0x20, 0x40, 0x20, 0x1F }, // V
		{ 0x7F, 0x20, 0x10, 0x20, 0x7F }, // W
		{ 0x41, 0x22, 0x1C, 0x22, 0x41 }, // X
		{ 0x07, 0x08, 0x70, 0x08, 0x07 }, // Y
		{ 0x61, 0x51, 0x49, 0x45, 0x43 }, // Z
		{ 0x00, 0x7F, 0x41, 0x00, 0x00 }, // [
		{ 0x02, 0x04, 0x08, 0x10, 0x20 }, //
		{ 0x00, 0x00, 0x41, 0x7F, 0x00 }, // ]
		{ 0x04, 0x02, 0x01, 0x02, 0x04 }, // ^
		{ 0x40, 0x40, 0x40, 0x40, 0x40 }, // _
		{ 0x00, 0x01, 0x02, 0x04, 0x00 }, // `
		{ 0x20, 0x54, 0x54, 0x54, 0x78 }, // a
		{ 0x7F, 0x44, 0x44, 0x44, 0x38 }, // b
		{ 0x38, 0x44, 0x44, 0x44, 0x44 }, // c
		{ 0x38, 0x44, 0x44, 0x44, 0x7F }, // d
		{ 0x38, 0x54, 0x54, 0x54, 0x18 }, // e
		{ 0x04, 0x04, 0x7E, 0x05, 0x05 }, // f
		{ 0x08, 0x54, 0x54, 0x54, 0x3C }, // g
		{ 0x7F, 0x08, 0x04, 0x04, 0x78 }, // h
		{ 0x00, 0x44, 0x7D, 0x40, 0x00 }, // i
		{ 0x20, 0x40, 0x44, 0x3D, 0x00 }, // j
		{ 0x7F, 0x10, 0x28, 0x44, 0x00 }, // k
		{ 0x00, 0x41, 0x7F, 0x40, 0x00 }, // l
		{ 0x7C, 0x04, 0x78, 0x04, 0x78 }, // m
		{ 0x7C, 0x08, 0x04, 0x04, 0x78 }, // n
		{ 0x38, 0x44, 0x44, 0x44, 0x38 }, // o
		{ 0x7C, 0x14, 0x14, 0x14, 0x08 }, // p
		{ 0x08, 0x14, 0x14, 0x14, 0x7C }, // q
		{ 0x00, 0x7C, 0x08, 0x04, 0x04 }, // r
		{ 0x48, 0x54, 0x54, 0x54, 0x20 }, // s
		{ 0x04, 0x04, 0x3F, 0x44, 0x44 }, // t
		{ 0x3C, 0x40, 0x40, 0x20, 0x7C }, // u
		{ 0x1C, 0x20, 0x40, 0x20, 0x1C }, // v
		{ 0x3C, 0x40, 0x30, 0x40, 0x3C }, // w
		{ 0x44, 0x28, 0x10, 0x28, 0x44 }, // x
		{ 0x0C, 0x50, 0x50, 0x50, 0x3C }, // y
		{ 0x44, 0x64, 0x54, 0x4C, 0x44 }, // z
		{ 0x00, 0x08, 0x36, 0x41, 0x41 }, // {
		{ 0x00, 0x00, 0x7F, 0x00, 0x00 }, // |
		{ 0x41, 0x41, 0x36, 0x08, 0x00 }, // }
		{ 0x02, 0x01, 0x02, 0x04, 0x02 }, // ~
		{ 0x04, 0x02, 0xFF, 0x02, 0x04 }, // up arrow
		{ 0x20, 0x40, 0xFF, 0x40, 0x20 }  // down arrow
};

void write_reg_(unsigned char adr, unsigned short cmd);
void set_cursor_(unsigned short x, unsigned char y);

void reg_add_(unsigned short add)
{
	LCD_REG = add;
}

void write_ram_(unsigned short ram)
{
	LCD_RAM = ram;
}

void write_reg_(unsigned char adr, unsigned short cmd)
{
	LCD_REG = (adr);
	LCD_RAM = (cmd);
}

unsigned short read_reg_(unsigned char adr)
{
	LCD_REG = (adr);
	return LCD_RAM;
}

void set_cursor_(unsigned short x, unsigned char y)
{
	write_reg_(0x004e, y);
	write_reg_(0x004f, x);
}

void fill_screen_(unsigned short color, unsigned short x_start, unsigned short x_stop,
		unsigned short y_start, unsigned short y_stop);
void write_dot_(unsigned char character);
void write_str_(unsigned char * character, unsigned short x, unsigned char y, unsigned short font_color,
		unsigned short fill_color1, unsigned char direction);
void set_range_(unsigned short x_start, unsigned short x_stop, unsigned short y_start,
		unsigned short y_stop);

static lcd_t* lcd_p = NULL;

lcd_retval_t lcd_init(lcd_t **lcd_pp, unsigned int (*hardware_init)(void),
		unsigned int (*hardware_deinit)(void)) // The required modifications for the io bits for the lcd are done here, in case of any hardware change consider this
{
	if (lcd_p != NULL)
	{
		*lcd_pp = lcd_p;
		return lcd_prev_alloc;
	}
	else
	{
		lcd_p = (lcd_t*) mm_malloc(sizeof(lcd_t));
		*lcd_pp = lcd_p;
		if (lcd_p == NULL)
			return lcd_alloc_er;
	}

	if (hardware_init == NULL)
	{
		mm_free(lcd_p);
		*lcd_pp = NULL;
		return lcd_hard_er;
	}
	if (hardware_init())
	{
		mm_free(lcd_p);
				*lcd_pp = NULL;
		return lcd_hard_er;
	}

	if (read_reg_(0) != 0x8989) //If not SSD1289 screen return with hard error
	{
		return lcd_hard_er;
	}
	// power supply setting
	// set R07h at 0021h (GON=1,DTE=0,D[1:0]=01)
	write_reg_(0x0007, 0x0021);
	// set R00h at 0001h (OSCEN=1)
	write_reg_(0x0000, 0x0001);
	// set R07h at 0023h (GON=1,DTE=0,D[1:0]=11)
	write_reg_(0x0007, 0x0023);
	// set R10h at 0000h (Exit sleep mode)
	write_reg_(0x0010, 0x0000);
	// Wait 30ms
	for (int i = 0; i < 300000; i++)
		;
	// set R07h at 0033h (GON=1,DTE=1,D[1:0]=11)
	write_reg_(0x0007, 0x0033);
	// Entry mode setting (R11h)
	// R11H Entry mode
	// vsmode DFM1 DFM0 TRANS OEDef WMode DMode1 DMode0 TY1 TY0 ID1 ID0 AM LG2 LG2 LG0
	//   0     1    1     0     0     0     0      0     0   1   1   1   1  0   0   0
	write_reg_(0x0011, 0x6078);
	// LCD driver AC setting (R02h)
	// 0 0 0 FLD ENWS B/C EOR WSMD NW7 NW6 NW5 NW4 NW3 NW2 NW1 NW0
	// 0 0 0  1   0    1   1
	write_reg_(0x0002, 0x8600);
	// power control 1
	// DCT3 DCT2 DCT1 DCT0 BT2 BT1 BT0 0 DC3 DC2 DC1 DC0 AP2 AP1 AP0 0
	// 1     0    1    0    1   0   0  0  1   0   1   0   0   1   0  0
	// DCT[3:0] fosc/4 BT[2:0]  DC{3:0] fosc/4
	write_reg_(0x0003, 0xa8a4); //0xA8A4
	write_reg_(0x000C, 0x0000); //
	write_reg_(0x000D, 0x0808); // 0x080C --> 0x0808
	// power control 4
	// 0 0 VCOMG VDV4 VDV3 VDV2 VDV1 VDV0 0 0 0 0 0 0 0 0
	// 0 0   1    0    1    0    1    1   0 0 0 0 0 0 0 0
	write_reg_(0x000E, 0x2900);
	write_reg_(0x001E, 0x00B8);

	// 0 RL REV CAD BGR SM TB MUX8 MUX7 MUX6 MUX5 MUX4 MUX3 MUX2 MUX1 MUX0
	//    0  1   0   1   0  0  100111111
	write_reg_(0x0001, 0x293f);
	write_reg_(0x0010, 0x0000);
	write_reg_(0x0005, 0x0000);
	// write_reg_(0x0001,0x493F);//!!!
	write_reg_(0x0006, 0x0000);
	write_reg_(0x0016, 0xEF1C);
	write_reg_(0x0017, 0x0003);
	//Display Control (R07h) (POR = 0000h)
	//0 0 0 PT1 PT0 VLE2 VLE1 SPT 0 0 GON DTE CM 0 D1 D0
	//0 0 0  0   0    0   1    0  0 0  1   1   0 0 1  1
	write_reg_(0x0007, 0x0233); //0x0233
	write_reg_(0x000B, 0x0000 | (3 << 6));
	write_reg_(0x000F, 0x0000);
	write_reg_(0x0041, 0x0000);
	write_reg_(0x0042, 0x0000);
	write_reg_(0x0048, 0x0000);
	write_reg_(0x0049, 0x013F);
	write_reg_(0x004A, 0x0000);
	write_reg_(0x004B, 0x0000);
	write_reg_(0x0044, 0xEF00);
	write_reg_(0x0045, 0x0000);
	write_reg_(0x0046, 0x013F);
	write_reg_(0x0030, 0x0707);
	write_reg_(0x0031, 0x0204);
	write_reg_(0x0032, 0x0204);
	write_reg_(0x0033, 0x0502);
	write_reg_(0x0034, 0x0507);
	write_reg_(0x0035, 0x0204);
	write_reg_(0x0036, 0x0204);
	write_reg_(0x0037, 0x0502);
	write_reg_(0x003A, 0x0302);
	write_reg_(0x003B, 0x0302);
	write_reg_(0x0023, 0x0000);
	write_reg_(0x0024, 0x0000);
	write_reg_(0x0025, 0xE000); // 80hz
	write_reg_(0x004f, 0); // ??��ַ0
	write_reg_(0x004e, 0); // �?��ַ0}

	fill_screen_(Black, 0, 319, 0, 239);

	lcd_p->set_cursor = set_cursor_;
	lcd_p->write_dot = write_dot_;
	lcd_p->fill_screen = fill_screen_;
	lcd_p->write_str = write_str_;
	lcd_p->set_range = set_range_;
	lcd_p->reg_add = reg_add_;
	lcd_p->write_reg = write_reg_;
	lcd_p->write_ram = write_ram_;

	return lcd_ok;
}

lcd_retval_t lcd_deinit(lcd_t **lcd_pp)
{
	lcd_p->hardware_deinit();
	mm_free(lcd_p);
	*lcd_pp = lcd_p;
	return lcd_ok;
}

void set_range_(unsigned short x_start, unsigned short x_stop, unsigned short y_start,
		unsigned short y_stop)
{
	write_reg_(0x0044, (y_stop << 8) | y_start); /// y direction end/start
	write_reg_(0x0045, x_start); /// x direction start
	write_reg_(0x0046, x_stop); /// x direction end
}

void fill_screen_(unsigned short color, unsigned short x_start, unsigned short x_stop,
		unsigned short y_start, unsigned short y_stop)
{
	unsigned short i, j;
	for (j = y_start; j <= y_stop; j++)
	{
		set_cursor_(x_start, j);
		LCD_REG = (0x22);
		for (i = x_start; i <= x_stop; i++)
			LCD_RAM = (color);

	}
}

void write_dot_(unsigned char character)
{
	unsigned char i, j;
	switch (character)
	{
	case '\b':
		lcd_p->cor_x -= 6; //backspace
		break;
	case '\f':
		lcd_p->cor_x = 0; //return home
		lcd_p->cor_y = 0;
		break;
	case '\n':
		lcd_p->cor_x = 0;
		lcd_p->cor_y += 10; //newline
		break;
	case '\r':
		lcd_p->cor_x = 0; //return beginning
		break;
	case '\t':
		lcd_p->cor_y += 30; //horizontal tab
		break;
	case '\v':
		lcd_p->cor_x = 0;
		lcd_p->cor_y += 40; //vertical tab
		break;
	default:
		for (j = 0; j <= 4; j++)
		{
			for (i = 0; i <= 7; i++)
			{
				set_cursor_(lcd_p->cor_x + (j), lcd_p->cor_y + i);
				LCD_REG = (0x22);
				LCD_RAM = (lcd_p->color
						* ((FONT[character - 32][j] & (1 << i)) > 0)
						+ lcd_p->fill_color
								* ((FONT[character - 32][j] & (1 << i)) == 0));
			}
		}
		for (i = 0; i <= 7; i++)
		{
			set_cursor_(lcd_p->cor_x + 5, lcd_p->cor_y + i);
			LCD_REG = (0x22);
			LCD_RAM = (lcd_p->fill_color);
		}
		lcd_p->cor_x += 6;
	}
}

void write_str_(unsigned char * character, unsigned short x, unsigned char y, unsigned short font_color,
		unsigned short fill_color1, unsigned char direction)
{
	unsigned char i, j, k, l, p;

	k = 0;
	while (*(character + k) != 0)
	{
		k++;
	}

	switch (direction)
	{
	case lcd_hor:
		write_reg_(0x0044, (256 * (y + 7)) | (y)); /// y direction end/start
		write_reg_(0x0045, x); /// x direction start
		write_reg_(0x0046, x + 6 * k - 1); /// x direction end
		// vsmode DFM1 DFM0 TRANS OEDef WMode DMode1 DMode0 TY1 TY0 ID1 ID0 AM LG2 LG2 LG0
		//   0     1    1     0     0     0     0      0     0   1   1   1   0  0   0   0
		write_reg_(0x0011, 0x6070);
		break;
	case lcd_ver_up:
		write_reg_(0x0044, (256 * (y)) | (y - 6 * k + 1)); /// y direction end/start
		write_reg_(0x0045, x); /// x direction start
		write_reg_(0x0046, x + 7); /// x direction end
		// vsmode DFM1 DFM0 TRANS OEDef WMode DMode1 DMode0 TY1 TY0 ID1 ID0 AM LG2 LG2 LG0
		//   0     1    1     0     0     0     0      0     0   1   1   1   0  0   0   0
		write_reg_(0x0011, 0x6068);
		break;
	case lcd_ver_down:
		write_reg_(0x0044, (256 * (y + 6 * k - 1)) | (y)); /// y direction end/start
		write_reg_(0x0045, x - 7); /// x direction start
		write_reg_(0x0046, x); /// x direction end
		// vsmode DFM1 DFM0 TRANS OEDef WMode DMode1 DMode0 TY1 TY0 ID1 ID0 AM LG2 LG2 LG0
		//   0     1    1     0     0     0     0      0     0   1   1   1   0  0   0   0
		write_reg_(0x0011, 0x6058);
		break;

	}

	set_cursor_(x, y);
	LCD_REG = (0x22);

	for (l = 0; l < k; l++)
	{
		for (j = 0; j < 5; j++)
		{
			p = FONT[*(character + l) - 32][j];
			for (i = 0; i < 8; i++)
			{
				LCD_RAM = ((p & (1 << i)) == 0) ? fill_color1 : font_color;
			}
		}
		for (i = 0; i <= 7; i++)
		{
			LCD_RAM = (fill_color1);
		}
	}

	write_reg_(0x0044, 0xEF00);
	write_reg_(0x0045, 0x0000);
	write_reg_(0x0046, 0x013F);
	write_reg_(0x0011, 0x6078);
}

