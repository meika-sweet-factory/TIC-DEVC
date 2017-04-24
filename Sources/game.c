#include<stdlib.h>
#include"../Headers/helpers/string.h"
#include"../Headers/game.h"

int new_game(game_t * g, char * x, char * y)
{
    g = (game_t *) malloc(sizeof(g));
    g->size.x = str_to_int(x);
    g->size.y = str_to_int(y);
    return 1;
}

int load_game(game_t * g, char * s)
{
    (void) s;

    // if ((file = open(directory, O_RDONLY)) {
    //     return 0;
    // }
    g = (game_t *) malloc(sizeof(g));
    return 1;
}

int play_game(game_t * g)
{
    (void) g;
    return 1;
}