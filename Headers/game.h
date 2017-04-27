#ifndef _SNAKE_GAME_H_
#define _SNAKE_GAME_H_

/* Helpers */

#include "structures/type.h"
#include "structures/game.h"

/* Usage functions */

_Bool   new_game    (t_game * restrict g, const char * restrict x, const char * restrict y, _Bool (* callback)(t_game * g));
_Bool   load_game   (t_game * restrict g, const char * restrict f, _Bool (* callback)(t_game * g));
_Bool   play_game   (t_game * g);

#endif //_SNAKE_GAME_H_
