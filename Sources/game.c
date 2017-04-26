#include<stdlib.h>
#include"../Headers/helpers/string.h"
#include"../Headers/helpers/print.h"
#include"../Headers/helpers/file.h"
#include"../Headers/game.h"

/* Usable functions */

inline int new_game(game_t * g, char * x, char * y, int (*callback)(game_t * g))
{
    if (!(g = (game_t *) malloc(sizeof(game_t)))) return EXIT_FAILURE;
    g->size.x = str_to_int(x);
    g->size.y = str_to_int(y);
    if (!callback(g)) return 1;
    free(g);
    return EXIT_SUCCESS;
}

inline int load_game(game_t * g, char * d, int (* callback)(game_t * g))
{
    if (!(g = (game_t *) malloc(sizeof(game_t)))) return EXIT_FAILURE;
    if (!read_file(g, d)) return EXIT_FAILURE;
    if (!callback(g)) return EXIT_FAILURE;
    free(g);
    return EXIT_SUCCESS;
}

int play_game(game_t * g)
{
    (void) g;
    return 1;
}
