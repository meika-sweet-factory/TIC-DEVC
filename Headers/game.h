#ifndef _SNAKE_GAME_H_
#define _SNAKE_GAME_H_

#include "common.h"
#include "structures/game.h"

/* Usage functions */

_Bool   new_game            (const char * restrict x, const char * restrict y, _Bool (* process)(t_game * g));
_Bool   load_game           (const char * f, _Bool (* process)(t_game * g));
_Bool   play_normal_game    (t_game *g);

#endif //_SNAKE_GAME_H_
