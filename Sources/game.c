#include "../Headers/helpers/conversion.h"
#include "../Headers/file.h"
#include "../Headers/interface.h"
#include "../Headers/map.h"
#include "../Headers/memory.h"
#include "../Headers/game.h"

/* Usable functions */

inline _Bool    new_game(t_game * g,
                      const char * x,
                      const char * y,
                      _Bool (* callback)(t_game * g))
{
    if (!(g = create_game())) return EXIT_FAILURE;
    if (!generate_map(g, str_to_axe(x, y))) return EXIT_FAILURE;
    if (!callback(g)) return EXIT_FAILURE;
//    free_game(g);
    return EXIT_SUCCESS;
}

inline _Bool load_game(t_game * g,
                       const char * f,
                       _Bool (* callback)(t_game * g))
{
    if (!(g = create_game())) return EXIT_FAILURE;
    if (!load_file(g, f)) return EXIT_FAILURE;
    if (!callback(g)) return EXIT_FAILURE;
//    free_game(g);
    return EXIT_SUCCESS;
}

_Bool play_game(t_game * g)
{
    sdl_engine(g);
    return SUCCESS;
}