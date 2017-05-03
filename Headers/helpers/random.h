#ifndef _RANDOM_H_
#define _RANDOM_H_

#include "../../Headers/structures/geometry.h"
#include "../../Headers/structures/game.h"

t_axe           generate_rand_pos   (t_map *m, int type);
int  rand_pos            (int max);
int  initial_rand_pos    (int max);

#endif //_RANDOM_H_
