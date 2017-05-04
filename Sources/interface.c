#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include <time.h>
#include <stdbool.h>
#include "../Headers/memory.h"
#include "../Headers/interface.h"
#include "../Headers/player.h"
#include "../Headers/draw.h"

#include "../Headers/helpers/print.h"

void event_loop(t_game *g, SDL_Rect rect, SDL_Renderer * render);
bool     game_over(t_map * m, SDL_Renderer * render);

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
    render = draw_walls(g, rect, render);
//  Ici la boucle;
    event_loop(g, rect, render);
    free_sdl(window, render);
    return SUCCESS;
}

void            event_loop(t_game * g, SDL_Rect rect, SDL_Renderer * render)
{
    bool        run;
    SDL_Event   e;

    run = true;
    g->player->stat.speed = 500;
    while (run) {
        while(SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) run = false;
            else if (e.type == SDL_KEYDOWN) {
                if (e.key.keysym.sym == SDLK_UP) g->player->direction = 0;
                else if (e.key.keysym.sym == SDLK_DOWN) g->player->direction = 1;
                else if (e.key.keysym.sym == SDLK_RIGHT) g->player->direction = 2;
                else if (e.key.keysym.sym == SDLK_LEFT) g->player->direction = 3;
            }
        }
        SDL_RenderClear(render);
        if (!move_forward(g->player, g)) run = game_over(g->map, render);
        render = draw_spawn(g->map, render, rect, 'b');
        render = draw_spawn(g->map, render, rect, 's');
        render = draw_walls(g, rect, render);
        render = draw_snake(g->player, render, rect);
        SDL_RenderPresent(render);
        SDL_Delay(g->player->stat.speed);
    }
    SDL_Delay(1000);
}

inline bool     game_over(t_map * m, SDL_Renderer * render)
{
    TTF_Font * font;
    SDL_Color color;
    SDL_Surface * font_surface;
    SDL_Texture * text;
    SDL_Rect fontrect;

    font = TTF_OpenFont("/home/killianb/Documents/code_c/libsdl/snake/Ressources/Default.ttf", m->size.x + 5);
    color.r = 255;
    color.g = 0;
    color.b = 0;
    color.a = 255;
    font_surface = TTF_RenderText_Solid(font, "GAME OVER", color);
    print_str("fwe");
    text = SDL_CreateTextureFromSurface(render, font_surface);
    SDL_FreeSurface(font_surface);
    fontrect.x = fontrect.y = 10;
    SDL_QueryTexture(text, NULL, NULL, &fontrect.w, &fontrect.h);
    SDL_RenderCopy(render, text, NULL, &fontrect);
    return false;
}
