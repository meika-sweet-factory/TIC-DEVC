#ifndef _DRAW_H_
#define _DRAW_H_

#include <SDL2/SDL.h>
#include "../Headers/structures/game.h"

SDL_Renderer *  draw_walls(t_game *g, SDL_Rect rect, SDL_Renderer *render);
SDL_Renderer *  draw_snake(t_player *p, SDL_Renderer *render, SDL_Rect rect);

#endif //_DRAW_H_
