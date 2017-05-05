#include <regex.h>
#include "../../Headers/helpers/type.h"

/* Usable function */

_Bool       is_digit(const char *s)
{
    int     r;
    _Bool   b;
    regex_t x;

    if ((r = regcomp(&x, "^[:digit:]", 0))) return ERROR;
    if (!(r = regexec(&x, s, 0, 0, 0))) b = 0;
    else if (r == REG_NOMATCH) b = 1;
    else return ERROR;
    regfree(&x);
    return b;
}


