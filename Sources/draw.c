/*
** draw.c for  in /home/killianb/Documents/code_c/libsdl/snake/Sources
** 
** Made by BAILLIF Killian
** Login   <bailli_k@etna-alternance.net>
** 
** Started on  Wed May  3 14:21:24 2017 BAILLIF Killian
** Last update Wed May  3 14:21:27 2017 BAILLIF Killian
*/
#include "../Headers/draw.h"

SDL_Renderer *      draw_snake(t_player *p, SDL_Renderer *render, SDL_Rect rect)
{
    t_pile_element  *e;
    uint8_t         cr;
    uint8_t         cv;
    uint8_t         cb;

    for (e = p->body->first; e != 0; e = e->next) {
        rect.x = e->data.coordonate.x;
        rect.y = e->data.coordonate.y;
        cr = 255;
        cv = 255;
        cb = 255;
        SDL_SetRenderDrawColor(render,cr,cv,cb,255);
        SDL_RenderFillRect(render, &rect);
    }
    SDL_RenderPresent(render);
    return render;
}

SDL_Renderer *  draw_walls(t_game * g, SDL_Rect rect, SDL_Renderer * render)
{
    t_axe       m;
    t_axe       map;
    uint8_t     cr;
    uint8_t     cv;
    uint8_t     cb;

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

SDL_Renderer *      draw_spawn(t_map * m, SDL_Renderer *render, SDL_Rect rect, char spawn)
{
    uint8_t         cr;
    uint8_t         cv;
    uint8_t         cb;

    if (spawn == 'b') {
        rect.x = m->spawns.bonus.x;
        rect.y = m->spawns.bonus.y;
        cr = 0;
        cv = 255;
        cb = 0;
    } else {
        rect.x = m->spawns.malus.x;
        rect.y = m->spawns.malus.y;
        cr = 255;
        cv = 0;
        cb = 0;
    }
    SDL_SetRenderDrawColor(render,cr,cv,cb,255);
    SDL_RenderFillRect(render, &rect);
    SDL_RenderPresent(render);
    return render;
}
