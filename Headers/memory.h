#ifndef _SNAKE_MEMORY_H_
#define _SNAKE_MEMORY_H_

#include "common.h"
#include "structures/game.h"
#include "structures/interface.h"

/* Usage functions */

t_interface     create_interface    (void);
t_game *        init_game           (void);
char **         init_map            (int x, int y);
char *          init_map_cell       (int x);
_Bool           init_player         (t_game * g);
void            free_game           (t_game * g);
void            free_map            (t_game * g);
void            free_player         (t_game * g);
void            free_interface      (t_interface * i);

#endif //_SNAKE_MEMORY_H_
