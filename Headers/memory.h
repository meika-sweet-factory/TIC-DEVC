#ifndef _SNAKE_MEMORY_H_
#define _SNAKE_MEMORY_H_

#include "common.h"
#include "structures/game.h"
#include "structures/interface.h"

/* Usage functions */

_Bool       create_interface    (t_interface * i);
t_game *    init_game           (void);
_Bool       init_map            (t_game * g, t_axe s);
_Bool       init_player         (t_game * g, t_axe s);
char *      map_cell_create     (int x);
void        free_game           (t_game * g);
void        free_map            (t_game * g);
void        free_player         (t_game * g);
void        free_interface      (t_interface * i);

#endif //_SNAKE_MEMORY_H_
