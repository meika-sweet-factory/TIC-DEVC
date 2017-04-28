#include <SDL/SDL.h>
#include "../../Headers/memory.h"

t_interface     create_interface()
{
    t_interface i;

    if (!(window = SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &i.window, &i.render))) return ERROR;
    return i;
}

void    free_interface(t_interface * i)
{
    SDL_DestroyRenderer(i->render);
    SDL_DestroyWindow(i->window);
}
