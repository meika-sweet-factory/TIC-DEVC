#ifndef _SNAKE_MAP_H_
#define _SNAKE_MAP_H_

#include "structures/type.h"
#include "structures/game.h"
#include "structures/geometry.h"

_Bool   generate_map        (t_game * restrict g, const char * restrict x, const char * restrict y);
void    generate_snake      (t_game * g);
void    generate_spawn      (t_game * g);
t_axe   generate_rand_pos   (t_game * g);

#endif //_SNAKE_MAP_H_
