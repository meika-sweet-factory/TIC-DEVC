#ifndef _DRAW_H_
#define _DRAW_H_

#include <SDL2/SDL.h>
#include "../Headers/structures/game.h"

SDL_Renderer    *draw_walls     (t_game *g, SDL_Renderer *rd, SDL_Rect rc);
SDL_Renderer    *draw_snake     (t_player *p, SDL_Renderer *rd, SDL_Rect rc);
SDL_Renderer    *draw_spawn     (t_map *m, SDL_Renderer *rd, SDL_Rect rc, char spawn);
SDL_Renderer    *draw_score     (SDL_Renderer *rd, SDL_Rect rc, const char *title);
SDL_Renderer    *draw_intscore  (SDL_Renderer *rd, SDL_Rect rc, int score);
void            draw_string     (t_map *m, SDL_Renderer *rd, SDL_Rect rc, const char *msg);

#endif //_DRAW_H_
