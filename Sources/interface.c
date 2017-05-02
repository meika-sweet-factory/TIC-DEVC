#include <SDL2/SDL.h>
#include "../Headers/interface.h"
#include "../Headers/helpers/print.h"
#include <time.h>

void draw_walls(t_game * g, SDL_Rect rect, SDL_Renderer * render);

_Bool               sdl_engine(t_game * g)
{
    SDL_Rect        rect;
    SDL_Window *    window;
    SDL_Renderer *  render;

    window = 0;
    render = 0;
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) < 0) return ERROR;
    if (!(window = SDL_CreateWindow("Snake 2.0", SDL_WINDOWPOS_UNDEFINED,
                                                    SDL_WINDOWPOS_UNDEFINED,
                                                    g->map.size.x * 10, g->map.size.y * 10,
                                                    SDL_WINDOW_SHOWN))) return ERROR;
    if (!(render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                                        SDL_RENDERER_PRESENTVSYNC))) return ERROR;
    SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
    SDL_RenderClear(render);
    SDL_RenderPresent(render);
    rect.w = 10;
    rect.h = 10;
    draw_walls(g, rect, render);
    SDL_Delay(3000);
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return SUCCESS;
}

void        draw_walls(t_game * g, SDL_Rect rect, SDL_Renderer * render)
{
    t_axe   m;
    t_axe   map;
    int     cr;
    int     cv;
    int     cb;

    SDL_SetRenderDrawBlendMode(render, SDL_BLENDMODE_BLEND);
    for (m.y = 0, map.y = 0; m.y < g->map.size.y * 10; m.y += 10, ++map.y) {
        for (m.x = 0, map.x = 0; m.x < g->map.size.x * 10; m.x += 10, ++map.x) {
            rect.x = m.x;
            rect.y = m.y;
            if (g->map.board[map.y][map.x] == '1') {
                cr = 255;
                cv = 255;
                cb = 255;
            } else {
                cr = 0;
                cv = 0;
                cb = 0;
            }
            SDL_SetRenderDrawColor(render,cr,cv,cb,255);
            SDL_RenderFillRect(render, &rect);
        }
    }
    SDL_RenderPresent(render);
}

