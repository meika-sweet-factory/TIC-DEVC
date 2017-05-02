/*
** map.h for Snake in /home/asuramaru/Projects/snake/Headers/structures
**
**        Made by PHETSINORATH William
**        Login   <phetsi_w@etna-alternance.net>
**
** Started on  Tue May  2 15:32:14 2017 PHETSINORATH William
** Last update Tue May  2 15:32:24 2017 PHETSINORATH William
*/

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
