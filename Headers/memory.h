/*
** memory.h for Snake in /home/asuramaru/Projects/snake/Headers
**
**        Made by PHETSINORATH William
**        Login   <phetsi_w@etna-alternance.net>
**
** Started on  Tue May  2 15:32:14 2017 PHETSINORATH William
** Last update Tue May  2 15:32:24 2017 PHETSINORATH William
*/

#ifndef _SNAKE_MEMORY_H_
#define _SNAKE_MEMORY_H_

#include <SDL2/SDL.h>
#include "common.h" 
#include "structures/game.h" 

/* Usage functions */

SDL_Renderer *       init_sdl            (t_game * g, SDL_Window * window, SDL_Renderer * render);
_Bool       init_map            (t_game * g, t_axe s);
_Bool       init_player         (t_game * g, t_axe s);
t_game *    create_game         (void);
char *      create_map_cell     (int x);
void        free_game           (t_game * g);
void        free_map            (t_game * g);
void        free_player         (t_game * g);
void        free_sdl            (SDL_Window * window, SDL_Renderer * render);

#endif //_SNAKE_MEMORY_H_
