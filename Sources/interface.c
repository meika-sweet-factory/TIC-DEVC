#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "../Headers/helpers/conversion.h"
#include "../Headers/draw.h"
#include "../Headers/interface.h"
#include "../Headers/memory.h"
#include "../Headers/player.h"

/* Internal functions prototype */

void            event_loop      (t_game *g, SDL_Rect rect, SDL_Renderer * render);
_Bool           game_over       (t_map *m, SDL_Renderer *render);
SDL_Renderer    *game_interface (t_game *g, SDL_Renderer *render, SDL_Rect rect, int timerini);

/* Usable functions */

_Bool           sdl_engine(t_game *g, SDL_Renderer *rd)
{
    SDL_Rect    rect;

    rect.w = 10;
    rect.h = 10;
    rd = draw_walls(g, rd, rect);
    event_loop(g, rect, rd);
    return SUCCESS;
}

/* Internal functions */

void            event_loop(t_game *g, SDL_Rect rect, SDL_Renderer *rd)
{
    int         timerini;
    _Bool       run;
    SDL_Event   e;

    timerini = (int) time(NULL);
    run = TRUE;
    g->player->stat.speed = SPEED;
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
        SDL_RenderClear(rd);
        if (!move_forward(g->map, g->player)) run = game_over(g->map, rd);
        rd = game_interface(g, rd, rect, timerini);
        SDL_RenderPresent(rd);
        SDL_Delay(g->player->stat.speed);
    }
    SDL_Delay(1000);
}

inline _Bool    game_over(t_map *m, SDL_Renderer *rd)
{
    SDL_Rect    rc;

    rc.x = rc.y = 10;
    draw_string(m, rd, rc, "Game Over");
    rc.y = 17 + m->size.x;
    rc.x = 10;
    draw_string(m, rd, rc,"Replay y or n");
    return FALSE;
}


SDL_Renderer    *game_interface(t_game *g, SDL_Renderer *rd, SDL_Rect rc, int ti)
{
    rd = draw_spawn(g->map, rd, rc, 'b');
    rd = draw_spawn(g->map, rd, rc, 's');
    rd = draw_walls(g, rd, rc);
    rd = draw_snake(g->player, rd, rc);
    rc.x =  g->map->size.x * 10 + 2;
    rc.y = 40;
    rd = draw_score(rd, rc, "Score");
    rc.x += 70;
    rd = draw_intscore(rd, rc, g->player->score);
    rc.x =  g->map->size.x * 10 + 2;
    rc.y = 10;
    rd = draw_score(rd, rc, "Time");
    rc.x += 58;
    rd = draw_intscore(rd, rc, (int) time(NULL) - ti);
    return rd;
}
