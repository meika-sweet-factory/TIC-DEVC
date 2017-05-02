#ifndef _SNAKE_CONVERSION_H_
#define _SNAKE_CONVERSION_H_

/* Helpers */

#include "../common.h"
#include "../structures/geometry.h"

/* Usage functions */

unsigned short  str_to_unshort  (const char *s);
t_axe           str_to_axe      (const char * restrict x, const char * restrict y);

#endif //_SNAKE_CONVERSION_H_
