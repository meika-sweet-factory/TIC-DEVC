#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include "../Headers/helpers/conversion.h"
#include "../Headers/memory.h"
#include "../Headers/interface.h"
#include "../Headers/player.h"
#include "../Headers/draw.h"

#include "../Headers/helpers/print.h"

void event_loop(t_game *g, SDL_Rect rect, SDL_Renderer * render);
_Bool     game_over(t_map * m, SDL_Renderer * render);
char *my_strcat(char *dest, char *src);
SDL_Renderer * game_interface(t_game * g, SDL_Renderer * render, SDL_Rect rect, int timerini);

_Bool               sdl_engine(t_game * g, SDL_Renderer * render)
{
    SDL_Rect        rect;

    rect.w = 10;
    rect.h = 10;
    render = draw_walls(g, rect, render);
    event_loop(g, rect, render);
    return SUCCESS;
}

void            event_loop(t_game * g, SDL_Rect rect, SDL_Renderer * render)
{
    _Bool        run;
    SDL_Event   e;
    int         timerini;

    timerini = (int)time(NULL);
    run = TRUE;
    g->player->stat.speed = 100;
    while (run) {
        while(SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) run = FALSE;
            else if (e.type == SDL_KEYDOWN) {
                if (e.key.keysym.sym == SDLK_UP) g->player->direction = 0;
                else if (e.key.keysym.sym == SDLK_DOWN) g->player->direction = 1;
                else if (e.key.keysym.sym == SDLK_RIGHT) g->player->direction = 2;
                else if (e.key.keysym.sym == SDLK_LEFT) g->player->direction = 3;
            }
        }
        SDL_RenderClear(render);
        if (!move_forward(g->player, g)) run = game_over(g->map, render);
        render = game_interface(g, render, rect, timerini);
        SDL_RenderPresent(render);
        SDL_Delay(g->player->stat.speed);
    }
    SDL_Delay(1000);
}

inline _Bool     game_over(t_map * m, SDL_Renderer * render)
{

    SDL_Rect fontrect;

    fontrect.x = fontrect.y = 10;
    draw_string("Game Over", fontrect, render, m);
    fontrect.y = 17 + m->size.x;
    fontrect.x = 10;
    draw_string("Replay y or n", fontrect, render, m);
    return FALSE;
}


SDL_Renderer * game_interface(t_game * g, SDL_Renderer * render, SDL_Rect rect, int timerini)
{
    int timer2 = (int)time(NULL) - timerini;
    render = draw_spawn(g->map, render, rect, 'b');
    render = draw_spawn(g->map, render, rect, 's');
    render = draw_walls(g, rect, render);
    render = draw_snake(g->player, render, rect);
    rect.x =  g->map->size.x * 10 + 2;
    rect.y = 40;
    render = draw_score(render, "Score", rect);
    rect.x += 70;
    render = draw_intscore(render, rect, g->player->score);
    rect.x =  g->map->size.x * 10 + 2;
    rect.y = 10;
    render = draw_score(render, "Time", rect);
    rect.x += 58;
    render = draw_intscore(render, rect, timer2);
    return render;
}