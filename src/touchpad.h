/*
 * Project: GUI library for microcontrollers /items/touchpad
 * Author: Gokhan Gunay, ghngunay@gmail.com
 * Copyright: (C) 2018 by Gokhan Gunay
 * License: GNU GPL v3 (see License.txt)
 */

#include "hardware_init.h"
#include "mem_man.h"

#ifndef TOUCHPAD_H_
#define TOUCHPAD_H_

/////////////////////////////////////////////////////////////////////////
#define Calibration_start_x 3744
#define Calibration_end_x 224
#define Calibration_start_y 224
#define Calibration_end_y 3840

enum touchpad_return_e
{
	touchpad_ok = 0, touchpad_prev_alloc = -1, touchpad_alloc_er = -2, touchpad_hard_er = -3,
};
typedef enum touchpad_return_e tp_return_e;


union touchpad_status_u
{
	struct
	{
		unsigned char NewData :1;
		unsigned char WasClicked :1;
		unsigned char FirstClick :1;
		unsigned char Released :1;
		unsigned char ConFin :1;
		unsigned char RESERVED :3;
	};
	unsigned char STATUS;
};

typedef union touchpad_status_u touchpad_status_t;

struct position_s
{
	unsigned short pos_x;
	unsigned short pos_y;
};

typedef struct position_s position_t;

struct touchpad_s
{
	touchpad_status_t status;
	position_t const *position;
	unsigned short *raw_data;


	void(*update_pos)(void);
	void(*read_pos)(void);
	void(*hardware_init)(void);
	void(*hardware_deinit)(void);
};

typedef struct touchpad_s touchpad_t;

/*
  * @brief  initializes touchpad module.
  * @param  touchpad_pp: pointer to pointer to the touchpad where the module allocated and initialized.
  * @param  hardware_init: hardware initialization method.
  * @param  hardware_deinit: hardware deinitialization method.
  * @retval succes condition of initialization process.
 */
tp_return_e touchpad_init(touchpad_t **touchpad_pp,
		unsigned int (*hardware_init)(void),unsigned int (*hardware_deinit)(void));
/*
  * @brief  deinitializes touchpad module.
  * @param  touchpad_pp: pointer to pointer to the touchpad where the module deallocated and deinitialized.
 */
void touchpad_deinit(touchpad_t **touchpad_pp);

void touchscreen_cor(void);

void touchpad_spi_int(void);

#endif /* TOUCHPAD_H_ */
