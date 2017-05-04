#ifndef _SPAWNERS_H_
#define _SPAWNERS_H_

#include "common.h"
#include "structures/game.h"
#include "structures/player.h"

_Bool   get_spawn (t_map *m, t_player *p);
void    rand_bonus(t_player *p);
_Bool   rand_malus(t_player *p);

#endif //SNAKE_SPAWNERS_H
