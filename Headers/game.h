#ifndef _SNAKE_GAME_H_
#define _SNAKE_GAME_H_

/* Helpers */

#include "structures/type.h"
#include "structures/game.h"

/* Usage functions */

int new_game    (game_t * g, const char * x, const char * y, _Bool (* callback)(game_t * g));
int load_game   (game_t * g, const char * f, _Bool (* callback)(game_t * g));
int play_game   (game_t * g);

#endif //_SNAKE_GAME_H_
