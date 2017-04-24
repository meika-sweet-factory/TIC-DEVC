#include<regex.h>
#include<stdlib.h>
#include"../Headers/helpers/print.h"
#include"../Headers/helpers/type.h"

short int       is_digit(char * s)
{
    int         r;
    short int   b;
    char        m[100];
    regex_t     x;

    if ((r = regcomp(&x, "^[:digit:]", 0))) {
        print_str("Could not compile regex\n");
        return 0;
    }
    if (!(r = regexec(&x, s, 0, NULL, 0))) {
        b = 0;
    } else if (r == REG_NOMATCH) {
        b = 1;
    } else {
        regerror(r, &x, m, sizeof(m));
        print_str("Regex match failed: ");
        print_str(m);
        print_char('\n');
        return 0;
    }
    regfree(&x);
    return b;
}

short int       is_alnum(char * s)
{
    int         r;
    short int   b;
    char        m[100];
    regex_t     x;

    if ((r = regcomp(&x, "^[:alnum:]", 0))) {
        print_str("Could not compile regex\n");
        return 0;
    }
    if (!(r = regexec(&x, s, 0, NULL, 0))) {
        b = 0;
    } else if (r == REG_NOMATCH) {
        b = 1;
    } else {
        regerror(r, &x, m, sizeof(m));
        print_str("Regex match failed: ");
        print_str(m);
        print_char('\n');
        return 0;
    }
    regfree(&x);
    return b;
}