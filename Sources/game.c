#include<stdlib.h>
#include"../Headers/helpers/string.h"
#include"../Headers/helpers/print.h"
#include"../Headers/helpers/file.h"
#include"../Headers/game.h"

/* Private functions prototype */


/* Usable functions */

int new_game(game_t * g, char * x, char * y, int (*callback)(game_t * g))
{
    if ((g = (game_t *) malloc(sizeof(g)))) return 1;
    if (!(g->size.x = str_to_int(x))) return 1;
    if (!(g->size.y = str_to_int(y))) return 1;
    if (!callback(g)) return 1;
    free(g);
    return 0;
}

int load_game(game_t * g, char * d, int (*callback)(game_t * g))
{
    if ((g = (game_t *) malloc(sizeof(g)))) return 1;
    if (!read_file(g, d)) return 1;
    if (!callback(g)) return 1;
    free(g);
    return 0;
}

int play_game(game_t * g)
{
    (void) g;
    return 1;
}
