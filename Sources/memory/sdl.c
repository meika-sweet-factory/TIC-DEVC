#include <SDL2/SDL.h>
#include "../../Headers/memory.h"
#define INIT_CONFIG SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER
#define RENDER_CONFIG SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC

inline SDL_Renderer * init_sdl(t_game *g, SDL_Window *window, SDL_Renderer *render)
{
    if (SDL_Init(INIT_CONFIG) < 0) return ERROR;
    if (!(window = SDL_CreateWindow("Snake 2.0", SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    g->map->size.x * 10, g->map->size.y * 10,
                                    SDL_WINDOW_SHOWN))) return ERROR;
    if (!(render = SDL_CreateRenderer(window, -1, RENDER_CONFIG))) return ERROR;
    g->player->direction = RIGHT;
    SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
    SDL_RenderClear(render);
    SDL_RenderPresent(render);
    return render;
}

inline void free_sdl(SDL_Window *window, SDL_Renderer *render)
{
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
