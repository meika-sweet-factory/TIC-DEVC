#ifndef _SNAKE_MEMORY_H_
#define _SNAKE_MEMORY_H_

#include "common.h" 
#include "structures/game.h" 

/* Usage functions */

_Bool       init_map            (t_game * g, t_axe s);
_Bool       init_player         (t_game * g, t_axe s);
t_game *    create_game         (void);
char *      create_map_cell     (int x);
void        free_game           (t_game * g);
void        free_map            (t_game * g);
void        free_player         (t_game * g);

#endif //_SNAKE_MEMORY_H_
