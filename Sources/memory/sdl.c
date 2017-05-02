#include <SDL2/SDL.h>
#include "../../Headers/memory.h"

inline void free_sdl(SDL_Window * window, SDL_Renderer * render)
{
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
