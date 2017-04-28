#ifndef _SNAKE_MEMORY_H_
#define _SNAKE_MEMORY_H_

#include "common.h"
#include "structures/game.h"

/* Usage functions */

t_game *    init_game       (void);
char **     init_map        (int x, int y);
char *      init_map_cell   (int x);
void        free_game       (t_game * g);
void        free_map        (t_game * g);
void        free_player     (t_game * g);

#endif //_SNAKE_MEMORY_H_
