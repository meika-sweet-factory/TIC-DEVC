#include"../Headers/helpers/string.h"

int	    str_to_int(const char * s)
{
    int	i;
    int	v;
    int	sn;

    for(sn = 1, i = 0; s[i] == 45 || s[i] == 43; i++) {
        if (s[i] == 45) sn *= -1;
    }
    for(v = 0; s[i] >= 48  && s[i] <= 57; i++) {
        v = v * 10 + s[i] - 48;
    }
    return sn * v;
}
