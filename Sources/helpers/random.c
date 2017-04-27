#include <time.h>
#include <stdlib.h>
#include "../../Headers/helpers/random.h"
#include "../../Headers/helpers/print.h"


unsigned short      rand_pos(unsigned short max)
{
    int  b_m;

    srand((unsigned short)time(NULL));
    b_m = (rand() % (max)) + 1;
    while (b_m == max || b_m == max -1 || b_m == 0) {
        b_m = (rand() % (max)) + 1;
    }
    return (unsigned short) b_m;
}
