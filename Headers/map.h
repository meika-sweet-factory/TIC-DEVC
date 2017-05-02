/*
** map.h for Snake in /home/asuramaru/Projects/snake/Headers
**
**        Made by PHETSINORATH William
**        Login   <phetsi_w@etna-alternance.net>
**
** Started on  Tue May  2 15:32:14 2017 PHETSINORATH William
** Last update Tue May  2 15:32:24 2017 PHETSINORATH William
*/

#ifndef _SNAKE_MAP_H_
#define _SNAKE_MAP_H_

#include "common.h"
#include "structures/game.h"
#include "structures/geometry.h"

_Bool   generate_map        (t_game * g, t_axe a);
_Bool   generate_snake      (t_game * g);
void    generate_spawn      (t_game * g);

#endif //_SNAKE_MAP_H_
