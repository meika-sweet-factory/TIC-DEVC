#ifndef _SNAKE_MEMORY_H_
#define _SNAKE_MEMORY_H_

/* Helpers */

#include "structures/type.h"
#include "structures/game.h"

/* Usage functions */

game_t *    init_game       (void);
char **     init_map      (int x, int y);
char *      init_map_cell (int x);
void        free_game       (game_t * g);
void        free_map      (game_t * g);

#endif //_SNAKE_MEMORY_H_
