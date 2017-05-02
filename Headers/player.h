#ifndef _SNAKE_PLAYER_H_
#define _SNAKE_PLAYER_H_

#include "common.h"
#include "chain/pile.h"
#include "structures/game.h"

/* Usage functions */

_Bool   move        (t_game * g, t_axe d);
_Bool   add_meat    (t_game * g, t_axe d);
void    go_forward  (t_game * g);


#endif //_SNAKE_PLAYER_H_
