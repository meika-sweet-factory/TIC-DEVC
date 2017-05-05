#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "common.h"
#include "chain/pile.h"
#include "structures/game.h"

/* Usage functions */

_Bool   move                (t_map *m, t_player *p, t_axe d);
_Bool   move_forward        (t_map *m, t_player *p);
void    add_player_queue    (t_player *p, t_axe a);
void    remove_player_queue (t_player *p);
#endif //_PLAYER_H_
