#include "../../Headers/helpers/string.h"

/* Usable functions */

void        reverse(char * str, int length)
{
    int     start;
    int     end;
    char    tmp;

    start = 0;
    end = length - 1;
    while (start < end) {
        tmp = *(str + end);
        *(str + end) = *(str + start);
        *(str + start) = tmp;
        start++;
        end--;
    }
}