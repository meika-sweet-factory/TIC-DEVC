/*
** interface.c for Snake in /home/asuramaru/Projects/snake/Sources
**
**        Made by BAILLIF Killian
**        Login   <bailli_k@etna-alternance.net>
**
** Started on  Tue May  2 15:32:14 2017 BAILLIF Killian
** Last update Tue May  2 15:32:24 2017 BAILLIF Killian
*/

#include <SDL2/SDL.h>
#include <time.h>
#include <stdbool.h>
#include "../Headers/helpers/print.h"
#include "../Headers/memory.h"
#include "../Headers/interface.h"
#include "../Headers/player.h"

void this_game(t_game * g, SDL_Rect rect, SDL_Renderer * render);
void draw_walls(t_game * g, SDL_Rect rect, SDL_Renderer * render);

_Bool               sdl_engine(t_game * g)
{
    SDL_Rect        rect;
    SDL_Window *    window;
    SDL_Renderer *  render;

    window = 0;
    render = 0;
    render = init_sdl(g, window, render);
    rect.w = 10;
    rect.h = 10;
    draw_walls(g, rect, render);
//  Ici la boucle;
    this_game(g, rect, render);
    free_sdl(window, render);
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
    for (m.y = 0, map.y = 0; m.y < g->map->size.y * 10; m.y += 10, ++map.y) {
        for (m.x = 0, map.x = 0; m.x < g->map->size.x * 10; m.x += 10, ++map.x) {
            rect.x = m.x;
            rect.y = m.y;
            if (g->map->board[map.y][map.x] == '1') {
                cr = 255;
                cv = 255;
                cb = 255;
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
}

void            this_game(t_game * g, SDL_Rect rect, SDL_Renderer * render)
{
    (void)rect;
    (void)render;
    bool        run;
    SDL_Event   e;

    run = true;
    while (run)
    {
        while(SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
                run = false;
            else if (e.type == SDL_KEYDOWN){
                if (e.key.keysym.sym == SDLK_UP) g->player->direction = 0;
                else if (e.key.keysym.sym == SDLK_DOWN) g->player->direction = 1;
                else if (e.key.keysym.sym == SDLK_RIGHT) g->player->direction = 2;
                else if (e.key.keysym.sym == SDLK_LEFT) g->player->direction = 3;
            }
        }
//      Function wichch will update the snake
        go_forward(g->player);
//      Need a function to set delay associated with bonus (fast)
        SDL_Delay(500);
//      Fucntion wich will draw the snake
//      SDL_UpdateWindowSurface(window);
//      SDL_RenderPresent(render);
    }
}