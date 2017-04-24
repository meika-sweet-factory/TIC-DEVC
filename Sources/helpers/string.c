#include"../../Headers/helpers/string.h"

unsigned short      str_to_int(const char * s)
{
    unsigned short	i;
    unsigned short	v;

    if (s[0] == '-') return 0;
    for(v = 0; s[i] >= 48  && s[i] <= 57; ++i) {
        v = v * 10 + s[i] - 48;
        if (v > 65534) return 0;
    }
    return v;
}
