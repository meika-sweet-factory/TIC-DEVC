#include <SDL2/SDL.h>
#include "../Headers/interface.h"

_Bool create_interface(t_interface * i)
{
    if (!(i->window = SDL_CreateWindow("Snake 2.0", SDL_WINDOWPOS_UNDEFINED,
                                                    SDL_WINDOWPOS_UNDEFINED,
                                                    600, 600,
                                                    SDL_WINDOW_SHOWN))) return ERROR;
    // if (!(i->render = SDL_CreateRenderer(i->window, -1, SDL_RENDERER_ACCELERATED |
    //                                                     SDL_RENDERER_PRESENTVSYNC))) return ERROR;
    return SUCCESS;
}

void    free_interface(t_interface * i)
{
    SDL_DestroyRenderer(i->render);
    SDL_DestroyWindow(i->window);
}

_Bool               sdl_engine(t_game * g)
{
    (void) g;
    t_interface *   interface;

    interface = 0;
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) < 0) return ERROR;
    if (!create_interface(interface)) return ERROR;
    SDL_Quit();
    return SUCCESS;
}
