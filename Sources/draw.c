/*
** draw.c for  in /home/killianb/Documents/code_c/libsdl/snake/Sources
** 
** Made by BAILLIF Killian
** Login   <bailli_k@etna-alternance.net>
** 
** Started on  Wed May  3 14:21:24 2017 BAILLIF Killian
** Last update Wed May  3 14:21:27 2017 BAILLIF Killian
*/

#include <SDL2/SDL_ttf.h>
#include <unistd.h>
#include "../Headers/helpers/conversion.h"
#include "../Headers/draw.h"

/* Usable functions */

SDL_Renderer    *draw_walls(t_game *g, SDL_Renderer *rd, SDL_Rect rc)
{
    uint8_t     cr;
    uint8_t     cv;
    uint8_t     cb;
    t_axe       m;
    t_axe       map;

    SDL_SetRenderDrawBlendMode(rd, SDL_BLENDMODE_BLEND);
    for (m.y = 0, map.y = 0; m.y < g->map->size.y * 10; m.y += 10, ++map.y) {
        for (m.x = 0, map.x = 0; m.x < g->map->size.x * 10; m.x += 10, ++map.x) {
            rc.x = m.x;
            rc.y = m.y;
            if (g->map->board[map.y][map.x] == WALL) {
                cr = 255;
                cv = 255;
                cb = 255;
            } else {
                cr = 0;
                cv = 0;
                cb = 0;
            }
            SDL_SetRenderDrawColor(rd,cr,cv,cb,100);
            SDL_RenderFillRect(rd, &rc);
        }
    }
    return rd;
}

/* https://definitely/ not a solid snake OMG */

SDL_Renderer        *draw_snake(t_player *p, SDL_Renderer *rd, SDL_Rect rc)
{
    uint8_t         cr;
    uint8_t         cv;
    uint8_t         cb;
    t_pile_element  *e;

    for (e = p->body->first; e != 0; e = e->next) {
        rc.x = e->data.coordonate.x;
        rc.y = e->data.coordonate.y;
        cr = 255;
        cv = 255;
        cb = 255;
        SDL_SetRenderDrawColor(rd,cr,cv,cb,255);
        SDL_RenderFillRect(rd, &rc);
    }
    return rd;
}

SDL_Renderer    *draw_spawn(t_map *m, SDL_Renderer *rd, SDL_Rect rc, char spawn)
{
    uint8_t     cr;
    uint8_t     cv;
    uint8_t     cb;

    if (spawn == 'b') {
        rc.x = m->spawns.bonus.x;
        rc.y = m->spawns.bonus.y;
        cr = 0;
        cv = 255;
        cb = 0;
    } else {
        rc.x = m->spawns.malus.x;
        rc.y = m->spawns.malus.y;
        cr = 255;
        cv = 0;
        cb = 0;
    }
    SDL_SetRenderDrawColor(rd,cr,cv,cb,255);
    SDL_RenderFillRect(rd, &rc);
    return rd;
}

SDL_Renderer        *draw_score(SDL_Renderer *rd, SDL_Rect rc, const char *title)
{
    char            str[4096];
    TTF_Font        *font;
    SDL_Color       color;
    SDL_Surface     *font_surface;
    SDL_Texture     *text;

    getcwd(str, sizeof(str));
    str_cat(str, "/Resources/Pixeland.ttf");
    font = TTF_OpenFont(str, 35);
    color.r = 255;
    color.g = 0;
    color.b = 0;
    color.a = 255;
    font_surface = TTF_RenderText_Solid(font, title, color);
    text = SDL_CreateTextureFromSurface(rd, font_surface);
    SDL_FreeSurface(font_surface);
    SDL_QueryTexture(text, NULL, NULL, &rc.w, &rc.h);
    SDL_RenderCopy(rd, text, NULL, &rc);
    return rd;
}

SDL_Renderer        *draw_intscore(SDL_Renderer *rd, SDL_Rect rc, int score)
{
    char            str[4096];
    char            *str2;
    TTF_Font        *font;
    SDL_Color       color;
    SDL_Surface     *font_surface;
    SDL_Texture     *text;

    str2 = malloc(sizeof(char *));
    str2 = int_to_str(score, str2);
    getcwd(str, sizeof(str));
    str_cat(str, "/Resources/Pixeland.ttf");
    font = TTF_OpenFont(str, 35);
    color.r = 255;
    color.g = 0;
    color.b = 0;
    color.a = 255;
    font_surface = TTF_RenderText_Solid(font, str2, color);
    text = SDL_CreateTextureFromSurface(rd, font_surface);
    SDL_FreeSurface(font_surface);
    SDL_QueryTexture(text, NULL, NULL, &rc.w, &rc.h);
    SDL_RenderCopy(rd, text, NULL, &rc);
    return rd;
}

void            draw_string(t_map *m, SDL_Renderer *rd, SDL_Rect rc, const char *msg)
{
    char        str[4096];
    TTF_Font    *font;
    SDL_Color   color;
    SDL_Surface *font_surface;
    SDL_Texture *text;

    getcwd(str, sizeof(str));
    str_cat(str, "/Resources/Default.ttf");
    font = TTF_OpenFont(str, m->size.x + 5);
    color.r = 255;
    color.g = 0;
    color.b = 0;
    color.a = 255;
    font_surface = TTF_RenderText_Solid(font, msg, color);
    text = SDL_CreateTextureFromSurface(rd, font_surface);
    SDL_FreeSurface(font_surface);
    SDL_QueryTexture(text, NULL, NULL, &rc.w, &rc.h);
    SDL_RenderCopy(rd, text, NULL, &rc);
}
