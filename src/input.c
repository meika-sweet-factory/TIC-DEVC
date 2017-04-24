#include<regex.h>
#include"Headers/common.h"
#include"Headers/input.h"

bool            is_digit(string s)
{
    short int   b;
    char        msgbuf[100];
    regex_t     x;

    if (regcomp(&x, "^[:digit:]", 0)) {
        print_str("Could not compile regex\n");
        return false;
    }
    if (!regexec(&x, s, 0, NULL, 0)) {
        b = true;
    } else if (reti == REG_NOMATCH) {
        b = false;
    } else {
        regerror(reti, &x, msgbuf, sizeof(msgbuf));
        print_str("Regex match failed: %s\n", msgbuf);
        return false;
    }
    regfree(&x);
    return b;
}

bool            is_alnum(string s)
{
    short int   b;
    char        msgbuf[100];
    regex_t     x;

    if (regcomp(&x, "^[:alnum:]", 0)) {
        print_str("Could not compile regex\n");
        return false;
    }
    if (!regexec(&x, s, 0, NULL, 0)) {
        b = true;
    } else if (reti == REG_NOMATCH) {
        b = false;
    } else {
        regerror(reti, &x, msgbuf, sizeof(msgbuf));
        print_str("Regex match failed: %s\n", msgbuf);
        return false;
    }
    regfree(&x);
    return b;
}