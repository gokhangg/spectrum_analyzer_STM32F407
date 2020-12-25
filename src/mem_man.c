/*
 * Project: Dynamic memory manager abstracction layer user can select memory manager from standard library or OS manager
 * Note: This file is not intended as a library can be manipulated as per desire
 * Author: Gokhan Gunay, ghngunay@gmail.com
 * Copyright: (C) 2018 by Gokhan Gunay
 * License: GNU GPL v3 (see License.txt)
 */

#include "mem_man.h"

void*
mm_malloc (size_t sz)
{
  return pvPortMalloc (sz);
}
void
mm_free (void *ptr)
{
	vPortFree (ptr);
}
