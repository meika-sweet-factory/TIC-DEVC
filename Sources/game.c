#include "../Headers/helpers/string.h"
#include "../Headers/helpers/print.h"
#include "../Headers/file.h"
#include "../Headers/game.h"
#include "../Headers/memory.h"

/* Usable functions */

inline int new_game(game_t * g, const char * x, const char * y, _Bool (* callback)(game_t * g))
{
    if (!(g = init_game())) return EXIT_FAILURE;
    g->size.x = str_to_int(x);
    g->size.y = str_to_int(y);
    if (!callback(g)) return EXIT_FAILURE;
    free_game(g);
    return EXIT_SUCCESS;
}

inline int load_game(game_t * g, const char * f, _Bool (* callback)(game_t * g))
{
    if (!(g = init_game())) return EXIT_FAILURE;
    if (!load_file(g, f, callback)) return EXIT_FAILURE;
    free_game(g);
    return EXIT_SUCCESS;
}

_Bool play_game(game_t * g)
{
    (void) g;
    return 1;
}
