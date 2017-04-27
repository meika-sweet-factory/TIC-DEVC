#include "../Headers/file.h"
#include "../Headers/map.h"
#include "../Headers/memory.h"
#include "../Headers/game.h"

/* Usable functions */

inline int new_game(game_t * g, const char * x, const char * y, _Bool (* callback)(game_t * g))
{
    if (!(g = init_game())) return EXIT_FAILURE;
    if (!init_map(g, x, y)) return EXIT_FAILURE;
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
