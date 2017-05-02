#include <SDL2/SDL.h>
#include "../../Headers/memory.h"
#define SDL_PARAM SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER

inline _Bool        init_sdl(SDL_Window * window, SDL_Renderer * render)
{
    SDL_Window *    window;
    SDL_Renderer *  render;

    window = 0;
    render = 0;
    if (SDL_Init(SDL_PARAM) < 0) return ERROR;
    if (!(window = SDL_CreateWindow("Snake 2.0", SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    g->map.size.x * 10, g->map.size.y * 10,
                                    SDL_WINDOW_SHOWN))) return ERROR;
    if (!(render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                                  SDL_RENDERER_PRESENTVSYNC))) return ERROR;
    SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
    SDL_RenderClear(render);
    SDL_RenderPresent(render);
    rect.w = 10;
    rect.h = 10;
    return SUCCESS;
}

inline void free_sdl(SDL_Window * window, SDL_Renderer * render)
{
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
