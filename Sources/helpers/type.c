/*
** type.c for Snake in /home/asuramaru/Projects/snake/Sources/helpers
**
**        Made by PHETSINORATH William
**        Login   <phetsi_w@etna-alternance.net>
**
** Started on  Tue May  2 15:32:14 2017 PHETSINORATH William
** Last update Tue May  2 15:32:24 2017 PHETSINORATH William
*/

#include <regex.h>
#include "../../Headers/helpers/type.h"

_Bool       is_digit(const char * s)
{
    int     r;
    _Bool   b;
    regex_t x;

    if ((r = regcomp(&x, "^[:digit:]", 0))) return 0;
    if (!(r = regexec(&x, s, 0, 0, 0)))  b = 0;
    else if (r == REG_NOMATCH) b = 1;
    else return 0;
    regfree(&x);
    return b;
}
