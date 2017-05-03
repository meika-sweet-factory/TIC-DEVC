#ifndef _RANDOM_H_
#define _RANDOM_H_

#include "../../Headers/structures/geometry.h"
#include "../../Headers/structures/game.h"

t_axe           generate_rand_pos   (t_map *m, int type);
unsigned short  rand_pos            (unsigned short max);
unsigned short  initial_rand_pos    (unsigned short max);

#endif //_RANDOM_H_
