#include "../../Headers/helpers/conversion.h"
#include "../../Headers/helpers/string.h"

/* Usable functions */

t_axe       str_to_axe(const char * restrict x, const char * restrict y)
{
    t_axe   a;

    a.x = str_to_int(x);
    a.y = str_to_int(y);
    return a;
}

int     str_to_int(const char *s)
{
    int i;
    int v;

    if (s[0] == '-') return 0;
    for(i = 0, v = 0; s[i] >= 48 && s[i] <= 57 && s[i] != '\0'; ++i) {
        v = v * 10 + s[i] - 48;
        if (v > 65534) return 0;
    }
    return v;
}

inline void str_copy(char * restrict sd, const char * restrict sc)
{
    while ((*sd++ = *sc++) != '\0');
}

inline void str_cat(char * restrict sd, const char * restrict sc)
{
    while (*sd) sd++;
    str_copy(sd, sc);
}

char    *int_to_str(int num, char *str)
{
    int i;

    i = 0;
    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
    while (num != 0) {
        int rem = num % 10;
        str[i++] = (rem > 9) ? (char) ((rem - 10) + 'a') : (char) (rem + '0');
        num /= 10;
    }
    str[i] = '\0';
    reverse(str, i);
    return str;
}
