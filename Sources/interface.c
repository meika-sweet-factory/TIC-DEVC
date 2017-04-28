#include <SDL2/SDL.h>
#include "../Headers/interface.h"
#include "../Headers/helpers/print.h"
#include <time.h>

_Bool               sdl_engine(t_game * g)
{
    (void) g;
    SDL_Rect rect;
    SDL_Window * window;
    SDL_Renderer * render;
    t_axe        cell_size;
    t_axe        m;
    int cr,cv,cb;
    int res;
    unsigned int value;

    window = 0;
    render = 0;
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) < 0) return ERROR;
    if (!(window = SDL_CreateWindow("Snake 2.0", SDL_WINDOWPOS_UNDEFINED,
                                                    SDL_WINDOWPOS_UNDEFINED,
                                                    600, 600,
                                                    SDL_WINDOW_SHOWN))) return ERROR;
    if (!(render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                                        SDL_RENDERER_PRESENTVSYNC))) return ERROR;
    SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
    SDL_RenderClear(render);
    SDL_RenderPresent(render);

    srand((unsigned short) time(NULL));
    cell_size.x = (unsigned short) (600 / (g->map.size.x - 1));
    cell_size.y = (unsigned short) (600 / g->map.size.y);
    print_int(cell_size.x);
    print_int(cell_size.y);
    rect.w = cell_size.x;
    rect.h = cell_size.y;
    for (m.y = 0; m.y < 600; m.y = m.y + cell_size.y){
        for (m.x = 0; m.x < 600; m.x = m.x + cell_size.x){
            rect.x = m.y;
            rect.y = m.x;
            res = SDL_RenderReadPixels(render, &rect, SDL_PIXELFORMAT_ARGB8888, &value, 32 * 600);
            if (res < 0) {
                printf("Lecture erronée : %s\n", SDL_GetError());
            }
            cr = (value & 0xFF0000) >> 16;
            cv = (value & 0x00FF00) >> 8;
            cb = (value & 0x0000FF);

            SDL_SetRenderDrawColor(render, cr, cv, cb, 0);
            SDL_RenderDrawPoint(render, m.y, m.x);
        }
    }
    SDL_RenderPresent(render);
    SDL_Delay(3000);

    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return SUCCESS;
}
