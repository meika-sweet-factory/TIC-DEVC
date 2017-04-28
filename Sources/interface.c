#include <SDL2/SDL.h>
#include "../Headers/interface.h"
#include "../Headers/memory.h"

_Bool               sdl_engine(t_game * g)
{
    (void) g;
    t_interface *   window;

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) < 0) return ERROR;
    if (!(window = create_interface())) return ERROR;
    free_interface(i);
    SDL_Quit();
    return SUCCESS;
}
