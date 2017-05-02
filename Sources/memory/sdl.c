/*
** sdl.c for Snake in /home/asuramaru/Projects/snake/Sources/memory
**
**        Made by BAILLIF Killian
**        Login   <bailli_k@etna-alternance.net>
**
** Started on  Tue May  2 15:32:14 2017 BAILLIF Killian
** Last update Tue May  2 15:32:24 2017 BAILLIF Killian
*/

#include <SDL2/SDL.h>
#include "../../Headers/memory.h"
#define SDL_PARAM SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER

SDL_Renderer *        init_sdl(t_game * g, SDL_Window * window, SDL_Renderer * render)
{
    if (SDL_Init(SDL_PARAM) < 0) return ERROR;
    if (!(window = SDL_CreateWindow("Snake 2.0", SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    g->map->size.x * 10, g->map->size.y * 10,
                                    SDL_WINDOW_SHOWN))) return ERROR;
    if (!(render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                                  SDL_RENDERER_PRESENTVSYNC))) return ERROR;
    g->player->direction = 2;
    SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
    SDL_RenderClear(render);
    SDL_RenderPresent(render);
    return render;
}

inline void free_sdl(SDL_Window * window, SDL_Renderer * render)
{
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
