#ifndef _SNAKE_CONVERSION_H_
#define _SNAKE_CONVERSION_H_

/* Helpers */

#include "../common.h"
#include "../structures/geometry.h"

/* Usage functions */

t_axe   str_to_axe  (const char * restrict x, const char * restrict y);
int     str_to_int  (const char * s);
void    str_copy    (char * sd, const char * sc);
void    str_cat     (char * sd, const char * sc);

#endif //_SNAKE_CONVERSION_H_
