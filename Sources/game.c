#include "../Headers/file.h"
#include "../Headers/map.h"
#include "../Headers/memory.h"
#include "../Headers/game.h"

/* Usable functions */

inline _Bool new_game(t_game * g,
                      const char * restrict x,
                      const char * restrict y,
                      _Bool (* callback)(t_game * g))
{
    g->map.size.x = str_to_unshort(x);
    g->map.size.y = str_to_unshort(y);
    if (!(g = init_game())) return EXIT_FAILURE;
    if (!generate_map(g)) return EXIT_FAILURE;
    if (!callback(g)) return EXIT_FAILURE;
    free_game(g);
    return EXIT_SUCCESS;
}

inline _Bool load_game(t_game * g,
                       const char * f,
                       _Bool (* callback)(t_game * g))
{
    if (!(g = init_game())) return EXIT_FAILURE;
    if (!load_file(g, f, callback)) return EXIT_FAILURE;
    free_game(g);
    return EXIT_SUCCESS;
}

_Bool play_game(t_game * g)
{
    (void) g;
    return SUCCESS;
}
