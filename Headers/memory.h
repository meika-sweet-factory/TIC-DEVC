#ifndef _SNAKE_MEMORY_H_
#define _SNAKE_MEMORY_H_

#include <SDL2/SDL.h>
#include "common.h" 
#include "structures/game.h"
#include "structures/player.h"

/* Usage functions */

SDL_Renderer *  init_sdl            (t_game * g, SDL_Window * w, SDL_Renderer * r);
_Bool           init_map            (t_game * g, t_axe s);
_Bool           init_player         (t_game * g, t_axe s);
t_game *        create_game         (void);
t_board *       create_map_cell     (int x);
void            free_game           (t_game * g);
void            free_map            (t_map * m);
void            free_player         (t_player * p);
void            free_sdl            (SDL_Window * w, SDL_Renderer * r);

#endif //_SNAKE_MEMORY_H_
