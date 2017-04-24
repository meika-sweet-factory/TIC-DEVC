#include<regex.h>
#include"../../Headers/helpers/print.h"
#include"../../Headers/helpers/type.h"

short int       is_digit(char * s)
{
    int         r;
    short int   b;
    regex_t     x;

    if ((r = regcomp(&x, "^[:digit:]", 0))) return 0;
    if (!(r = regexec(&x, s, 0, 0, 0)))  b = 0;
    else if (r == REG_NOMATCH) b = 1;
    else return 0;
    regfree(&x);
    return b;
}

short int       is_alnum(char * s)
{
    int         r;
    short int   b;
    regex_t     x;

    if ((r = regcomp(&x, "^[:alnum:]", 0))) return 0;
    if (!(r = regexec(&x, s, 0, 0, 0))) b = 0;
    else if (r == REG_NOMATCH) b = 1;
    else return 0;
    regfree(&x);
    return b;
}