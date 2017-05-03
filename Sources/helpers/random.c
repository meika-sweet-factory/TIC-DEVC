#include <time.h>
#include <stdlib.h>
#include "../../Headers/helpers/random.h"

t_axe       generate_rand_pos(t_map *m, int type)
{
    t_axe   item;

    if (type == 0) {
        item.x = initial_rand_pos(m->size.x);
        item.y = initial_rand_pos(m->size.y);
    }
    else {
        item.x = rand_pos(m->size.x);
        item.y = rand_pos(m->size.y);
    }
    return item;
}



unsigned short  initial_rand_pos(unsigned short max)
{
    int         b;

    srand((unsigned short) (time(NULL) + (rand() % 100)));
    b = rand() % max + 1;
    while (
        b == max || b == max - 1 || b == 0 || 
        b == max / 2 || b == (max + 1) / 2)
    {
        b = (rand() % (max)) + 1;
    }
    return (unsigned short) b;
}

unsigned short      rand_pos(unsigned short max)
{
    int  b;

    srand((unsigned short) (time(NULL) + (rand() % 100)));
    b = rand() % max + 1;
    while (b == max || b == max - 1 || b == 0) {
        b = (rand() % (max)) + 1;
    }
    return (unsigned short) b;
}
