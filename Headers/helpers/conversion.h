#ifndef _SNAKE_CONVERSION_H_
#define _SNAKE_CONVERSION_H_

/* Helpers */

#include "../common.h"
#include "../structures/geometry.h"

/* Usage functions */

t_axe   str_to_axe  (const char * restrict x, const char * restrict y);
int     str_to_int  (const char *s);
void    str_copy    (char * restrict sd, const char * restrict sc);
void    str_cat     (char * restrict sd, const char * restrict sc);
char    *int_to_str (int num, char *str);

#endif //_SNAKE_CONVERSION_H_
