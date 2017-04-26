#ifndef _SNAKE_GAME_H_
#define _SNAKE_GAME_H_

/* Helpers */

#include"structures/type.h"
#include"structures/game.h"

/* Usage functions */

int new_game    (game_t * restrict g, char * restrict x, char * restrict y, int (* callback)(game_t * g));
int load_game   (game_t * restrict g, char * restrict d, int (* callback)(game_t * g));
int play_game   (game_t * g);

#endif //_SNAKE_GAME_H_
