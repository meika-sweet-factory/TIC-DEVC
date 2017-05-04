#ifndef _DRAW_H_
#define _DRAW_H_

#include <SDL2/SDL.h>
#include "../Headers/structures/game.h"

SDL_Renderer *  draw_walls  (t_game * g, SDL_Rect rect, SDL_Renderer *render);
SDL_Renderer *  draw_snake  (t_player * p, SDL_Renderer * render, SDL_Rect rect);
SDL_Renderer *  draw_spawn  (t_map * m, SDL_Renderer * render, SDL_Rect rect, char spawn);
SDL_Renderer *  draw_score  (SDL_Renderer * render, const char * title, SDL_Rect rect);
void            draw_string (const char * str, SDL_Rect fontrect, SDL_Renderer * render, t_map * m);
SDL_Renderer * draw_intscore(SDL_Renderer * render, SDL_Rect rect, int score);

#endif //_DRAW_H_
