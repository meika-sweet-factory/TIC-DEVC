#ifndef _SNAKE_PLAYER_H_
#define _SNAKE_PLAYER_H_

#include "common.h"
#include "chain/pile.h"

/* Usage functions */

_Bool   move        (t_player * p, t_axe d);
_Bool   add_meat    (t_player * p, t_axe d);

#endif //_SNAKE_PLAYER_H_
