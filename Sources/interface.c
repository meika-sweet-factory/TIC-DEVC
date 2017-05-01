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
    int cr,cv,cb, x, y;

    window = 0;
    render = 0;
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) < 0) return ERROR;
    if (!(window = SDL_CreateWindow("Snake 2.0", SDL_WINDOWPOS_UNDEFINED,
                                                    SDL_WINDOWPOS_UNDEFINED,
                                    (600 / (g->map.size.x)) * g->map.size.x, (600 / (g->map.size.y)) * g->map.size.y,
                                                    SDL_WINDOW_SHOWN))) return ERROR;
    if (!(render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                                        SDL_RENDERER_PRESENTVSYNC))) return ERROR;
    SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
    SDL_RenderClear(render);
    SDL_RenderPresent(render);

    srand((unsigned short) time(NULL));
    cell_size.x = (unsigned short) (600 / (g->map.size.x));
    cell_size.y = (unsigned short) (600 / (g->map.size.y));
    print_char('\n');
    print_int(g->map.size.x);
    print_int(g->map.size.y);
    rect.w = cell_size.x;
    rect.h = cell_size.y;
    SDL_SetRenderDrawBlendMode(render, SDL_BLENDMODE_BLEND);
    for (m.y = 0, y = 0; m.y < (600 / (g->map.size.y)) * g->map.size.y;m.y = m.y + cell_size.y, ++y){
        for (m.x = 0, x = 0; m.x < (600 / (g->map.size.x)) * g->map.size.x; m.x = m.x + cell_size.x, ++x){
            rect.x = m.x;
            rect.y = m.y;
            print_int(y);
            print_char(':');
            print_int(x);
            print_char('\n');

            if (g->map.board[y][x] == '1') {
                cr = rand() % 256;
                cv = rand() % 256;
                cb = rand() % 256;
            } else {
                cr = 0;
                cv = 0;
                cb = 0;
            }
            SDL_SetRenderDrawColor(render,cr,cv,cb,100);
            SDL_RenderFillRect(render, &rect);
        }
    }
    SDL_RenderPresent(render);
    SDL_Delay(3000);

    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return SUCCESS;
}
