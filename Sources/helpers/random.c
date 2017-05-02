/*
** random.c for Snake in /home/asuramaru/Projects/snake/Sources/helpers
**
**        Made by BAILLIF Killian
**        Login   <bailli_k@etna-alternance.net>
**
** Started on  Tue May  2 15:32:14 2017 BAILLIF Killian
** Last update Tue May  2 15:32:24 2017 BAILLIF Killian
*/

#include <time.h>
#include <stdlib.h>
#include "../../Headers/helpers/random.h"

t_axe       generate_rand_pos(t_game * g, int type)
{
    t_axe   item;

    if (type == 0) {
        item.x = initial_rand_pos(g->map->size.x);
        item.y = initial_rand_pos(g->map->size.y);
    } else {
        item.x = rand_pos(g->map->size.x);
        item.y = rand_pos(g->map->size.y);
    }
    return item;
}



unsigned short      initial_rand_pos(unsigned short max)
{
    int  b_m;

    srand((unsigned short) (time(NULL) +(rand() % 100)));
    b_m = (rand() % (max)) + 1;
    while (b_m == max || b_m == max - 1 ||
            b_m == 0 || b_m == max/2 ||
            b_m == (max+1)/2) {
        b_m = (rand() % (max)) + 1;
    }
    return (unsigned short) b_m;
}

unsigned short      rand_pos(unsigned short max)
{
    int  b_m;

    srand((unsigned short) (time(NULL) +(rand() % 100)));
    b_m = (rand() % (max)) + 1;
    while (b_m == max || b_m == max - 1 || b_m == 0) {
        b_m = (rand() % (max)) + 1;
    }
    return (unsigned short) b_m;
}
