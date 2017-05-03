#include "../Headers/helpers/conversion.h"
#include "../Headers/initiator/file.h"
#include "../Headers/initiator/generate.h"
#include "../Headers/interface.h"
#include "../Headers/memory.h"
#include "../Headers/game.h"

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
    sdl_engine(g);
    return SUCCESS;
}