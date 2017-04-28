#ifndef _SNAKE_MAP_H_
#define _SNAKE_MAP_H_

#include "common.h"
#include "structures/game.h"
#include "structures/geometry.h"

_Bool   generate_map        (t_game * g, t_axe a);
_Bool   generate_snake      (t_game * g);
void    generate_spawn      (t_game * g);

#endif //_SNAKE_MAP_H_
