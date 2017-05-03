#include <time.h>
#include <stdlib.h>
#include "../../Headers/helpers/random.h"

t_axe       generate_rand_pos(t_map * m, int type)
{
    t_axe   item;

    if (type == 0) {
        item.x = initial_rand_pos(m->size.x);
        item.y = initial_rand_pos(m->size.y);
    } else {
        item.x = rand_pos(m->size.x);
        item.y = rand_pos(m->size.y);
    }
    return item;
}



int        initial_rand_pos(int max)
{
    int    b;

    srand((unsigned int) (time(NULL) + (rand() % 100)));
    b = (rand() % max) + 1;
    while (
        b == max || b == max - 1 || b == 0 || 
        b == max / 2 || b == (max + 1) / 2)
    {
        b = (rand() % max) + 1;
    }
    return b;
}

int      rand_pos(int max)
{
    int  b;

    srand((unsigned int) (time(NULL) + (rand() % 100)));
    b = (rand() % max) + 1;
    while (b == max || b == max - 1 || b == 0) b = (rand() % max) + 1;
    return b;
}
