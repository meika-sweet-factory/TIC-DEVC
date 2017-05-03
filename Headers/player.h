#ifndef _SNAKE_PLAYER_H_
#define _SNAKE_PLAYER_H_

#include "common.h"
#include "chain/pile.h"
#include "structures/game.h"

/* Usage functions */

_Bool   move                (t_player *p, t_axe d);
void    add_player_queue    (t_player *p, t_axe a);
void    move_forward        (t_player *p);

#endif //_SNAKE_PLAYER_H_
