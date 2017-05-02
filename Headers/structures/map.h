#ifndef _SNAKE_STUCTURE_MAP_H_
#define _SNAKE_STUCTURE_MAP_H_

#include "geometry.h"

typedef struct  s_items
{
    t_axe       bonus;
    t_axe       malus;
}               t_items;

typedef struct  s_map
{
    char **     board;
    t_items     spawns;
    t_axe       size;
}               t_map;

#endif //_SNAKE_STUCTURE_MAP_H_
