/*
 * Project: Spectrum analyzer application main header file
 * Note: This file is not intended as a library can be manipulated as per desire
 * Author: Gokhan Gunay, ghngunay@gmail.com
 * Copyright: (C) 2018 by Gokhan Gunay
 * License: GNU GPL v3 (see License.txt)
 */

#include <form.h>
#include <glcd.h>
#include <stdlib.h>
#include <math.h>
#include "events.h"
#include "graph.h"
#include "FreeRTOS.h"
#include "task.h"

#include "screen.h"
#include "touchpad.h"
#include "spectrum.h"
#include "hardware_init.h"
#include "form.h"

#define pi 3.14159265f


