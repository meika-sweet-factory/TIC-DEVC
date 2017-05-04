#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../../Headers/memory.h"
#define INIT_CONFIG SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER
#define RENDER_CONFIG SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC

/* Usable functions */

inline SDL_Renderer *init_sdl(t_game *g, SDL_Window *w, SDL_Renderer *r)
{
    if (SDL_Init(INIT_CONFIG) < 0) return ERROR;
    if (TTF_Init() < 0) return ERROR;
    if (!(w = SDL_CreateWindow("Snake 2.0", SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    g->map->size.x * 10 + 100, g->map->size.y * 10,
                                    SDL_WINDOW_SHOWN))) return ERROR;
    if (!(r = SDL_CreateRenderer(w, -1, RENDER_CONFIG))) return ERROR;
    SDL_SetRenderDrawColor(r, 0, 0, 0, 255);
    SDL_RenderClear(r);
    SDL_RenderPresent(r);
    return r;
}

inline void free_sdl(SDL_Window *w, SDL_Renderer *r)
{
    SDL_DestroyRenderer(r);
    SDL_DestroyWindow(w);
    TTF_Quit();
    SDL_Quit();
}
