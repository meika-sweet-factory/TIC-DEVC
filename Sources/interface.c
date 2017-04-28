#include <SDL2/SDL.h>
#include "../Headers/interface.h"

_Bool               sdl_engine(t_game * g)
{
    (void) g;
    SDL_Window * window;
    SDL_Renderer * render;

    window = 0;
    render = 0;
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) < 0) return ERROR;
    if (!(window = SDL_CreateWindow("Snake 2.0", SDL_WINDOWPOS_UNDEFINED,
                                                    SDL_WINDOWPOS_UNDEFINED,
                                                    600, 600,
                                                    SDL_WINDOW_SHOWN))) return ERROR;
    if (!(render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                                        SDL_RENDERER_PRESENTVSYNC))) return ERROR;
                                                        SDL_Delay(3000);
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return SUCCESS;
}
