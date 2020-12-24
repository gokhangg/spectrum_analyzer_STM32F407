/*
 * Project: Dynamic memory manager abstracction layer user can select memory manager from standard library or OS manager
 * Note: This file is not intended as a library can be manipulated as per desire
 * Author: Gokhan Gunay, ghngunay@gmail.com
 * Copyright: (C) 2018 by Gokhan Gunay
 * License: GNU GPL v3 (see License.txt)
 */

#include <stdio.h>
#include <stdlib.h>
#include "FreeRTOS.h"

#ifndef MEM_MAN_H_
#define MEM_MAN_H_

void* mm_malloc(size_t sz);
void mm_free(void *ptr);


#endif /* MEM_MAN_H_ */
