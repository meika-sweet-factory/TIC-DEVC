/*
** conversion.c for Snake in /home/asuramaru/Projects/snake/Sources/helpers
**
**        Made by PHETSINORATH William
**        Login   <phetsi_w@etna-alternance.net>
**
** Started on  Tue May  2 15:32:14 2017 PHETSINORATH William
** Last update Tue May  2 15:32:24 2017 PHETSINORATH William
*/

#include "../../Headers/helpers/conversion.h"

unsigned short  str_to_unshort(const char * s)
{
    int         i;
    int         v;

    if (s[0] == '-') return 0;
    for(i = 0, v = 0; s[i] >= 48 && s[i] <= 57 && s[i] != '\0'; ++i) {
        v = v * 10 + s[i] - 48;
        if (v > 65534) return 0;
    }
    return (unsigned short) v;
}

t_axe       str_to_axe(const char * x, const char * y)
{
    t_axe   a;

    a.x = str_to_unshort(x);
    a.y = str_to_unshort(y);
    return a;
}