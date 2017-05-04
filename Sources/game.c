#include <SDL2/SDL.h>
#include "../Headers/helpers/conversion.h"
#include "../Headers/initiator/file.h"
#include "../Headers/initiator/generate.h"
#include "../Headers/interface.h"
#include "../Headers/game.h"
#include "../Headers/memory.h"

/* Internal functions prototype */

SDL_Renderer    *remake_game(t_game *g, SDL_Window *w, SDL_Renderer *r);

/* Usable functions */

inline _Bool    new_game(
    const char * restrict x,
    const char * restrict y,
    _Bool (*process)(t_game *g))
{
    t_game      *g;

    if (!(g = create_game())) return EXIT_FAILURE;
    if (!generate_map(g, str_to_axe(x, y))) return EXIT_FAILURE;
    if (!process(g)) return EXIT_FAILURE;
    free_game(g);
    return EXIT_SUCCESS;
}

inline _Bool    load_game(
    const char * restrict f,
    _Bool (*process)(t_game *g))
{
    t_game      *g;

    if (!(g = create_game())) return EXIT_FAILURE;
    if (!load_map(g, f)) return EXIT_FAILURE;
    if (!process(g)) return EXIT_FAILURE;
    free_game(g);
    return EXIT_SUCCESS;
}

_Bool               play_normal_game(t_game *g)
{
    int             i;
    SDL_Event       e;
    SDL_Window      *w;
    SDL_Renderer    *r;

    w = 0;
    r = 0;
    r = init_sdl(g, w, r);
    for (i = 0; i >= 0; ++i) {
        if (i == 0) sdl_engine(g, r);
        while(SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) i = -2;
            if (e.type == SDL_KEYDOWN){
                if (e.key.keysym.sym == SDLK_y) {
                    r = remake_game(g, w, r);
                    sdl_engine(g, r);
                }
                if (e.key.keysym.sym == SDLK_n) {
                    i = -2;
                }
            }
        }
    }
    free_sdl(w, r);
    return SUCCESS;
}

/* Internal functions */

inline SDL_Renderer *remake_game(t_game *g, SDL_Window *w, SDL_Renderer *r)
{
    t_axe           size;

    free_sdl(w, r);
    r = init_sdl(g, w, r);
    size = g->map->size;
    free_player(g->player);
    g->player = 0;
    free_map(g->map);
    g->map = 0;
    if (g->file != 0) load_map(g, g->file);
    else generate_map(g, size);
    return r;
}