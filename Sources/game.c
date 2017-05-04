#include <SDL2/SDL.h>
#include "../Headers/helpers/conversion.h"
#include "../Headers/initiator/file.h"
#include "../Headers/initiator/generate.h"
#include "../Headers/interface.h"
#include "../Headers/memory.h"
#include "../Headers/game.h"


#include "../Headers/helpers/print.h"
/* Usable functions */

inline _Bool    new_game(
    const char * restrict x,
    const char * restrict y,
    _Bool (* process)(t_game * g))
{
    t_game *    g;

    if (!(g = create_game())) return EXIT_FAILURE;
    if (!generate_map(g, str_to_axe(x, y))) return EXIT_FAILURE;
    if (!process(g)) return EXIT_FAILURE;
    free_game(g);
    return EXIT_SUCCESS;
}

inline _Bool    load_game(
    const char * restrict f,
    _Bool (* process)(t_game * g))
{
    t_game *    g;

    if (!(g = create_game())) return EXIT_FAILURE;
    if (!load_map(g, f)) return EXIT_FAILURE;
    if (!process(g)) return EXIT_FAILURE;
    free_game(g);
    return EXIT_SUCCESS;
}

_Bool play_normal_game(t_game *g)
{
    SDL_Event   e;
    int         i;
    SDL_Window *    window;
    SDL_Renderer *  render;

    window = 0;
    render = 0;
    render = init_sdl(g, window, render);
    for (i = 0; i >= 0; ++i) {
        if (i == 0) {
            sdl_engine(g, render);
        }
        while(SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) i = -2;
            if (e.type == SDL_KEYDOWN){
                if (e.key.keysym.sym == SDLK_y) {
                    SDL_RenderClear(render);
                    sdl_engine(g, render);
                };
                if (e.key.keysym.sym == SDLK_n) {
                    i = -2;
                }
            }
        }
    }
    free_sdl(window, render);
    return SUCCESS;
}