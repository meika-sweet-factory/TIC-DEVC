#include <SDL2/SDL.h>
#include "../Headers/interface.h"
#include "../Headers/memory.h"

_Bool               sdl_engine(t_game * g)
{
    (void) g;
    t_interface *   interface;

    interface = 0;
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) < 0) return ERROR;
    if (!create_interface(interface)) return ERROR;
    free_interface(interface);
    SDL_Quit();
    return SUCCESS;
}
