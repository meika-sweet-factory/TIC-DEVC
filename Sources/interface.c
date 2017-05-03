#include <SDL2/SDL.h>
#include <time.h>
#include <stdbool.h>
#include "../Headers/helpers/print.h"
#include "../Headers/memory.h"
#include "../Headers/interface.h"
#include "../Headers/player.h"

void            this_game(t_game *g, SDL_Rect rect, SDL_Renderer * render);
SDL_Renderer *  draw_walls(t_game *g, SDL_Rect rect, SDL_Renderer *render);
SDL_Renderer *  draw_snake(t_player *p, SDL_Renderer *render, SDL_Rect rect);


_Bool               sdl_engine(t_game * g)
{
    SDL_Rect        rect;
    SDL_Window      *window;
    SDL_Renderer    *render;

    window = 0;
    render = 0;
    render = init_sdl(g, window, render);
    rect.w = 10;
    rect.h = 10;
    render = draw_walls(g, rect, render);

//  Ici la boucle;
    this_game(g, rect, render);
    free_sdl(window, render);
    return SUCCESS;
}

SDL_Renderer *        draw_walls(t_game * g, SDL_Rect rect, SDL_Renderer * render)
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
    return render;
}

void            this_game(t_game * g, SDL_Rect rect, SDL_Renderer * render)
{
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
        move_forward(g->player);
//      Need a function to set delay associated with bonus (fast)
//      Fucntion wich will draw the snake
        SDL_RenderClear(render);
        render = draw_walls(g, rect, render);
        render = draw_snake(g->player, render, rect);
        SDL_Delay(1000);
    }
}

SDL_Renderer *      draw_snake(t_player *p, SDL_Renderer *render, SDL_Rect rect)
{
    t_pile_element  *e;
    int     cr;
    int     cv;
    int     cb;

    for (e = p->body->first; e != 0; e = e->next) {
        rect.x = e->data.coordonate.x;
        rect.y = e->data.coordonate.y;
        print_int(rect.y);
        print_char(':');
        print_int(rect.x);
        print_char('\n');
        cr = 255;
        cv = 255;
        cb = 255;
        SDL_SetRenderDrawColor(render,cr,cv,cb,255);
        SDL_RenderFillRect(render, &rect);
    }
    print_char('\n');
    SDL_RenderPresent(render);
    return render;
}