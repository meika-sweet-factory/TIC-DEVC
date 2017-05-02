#include <SDL2/SDL.h>
#include "../../Headers/memory.h"

inline void free_sdl(window, render)
{
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
