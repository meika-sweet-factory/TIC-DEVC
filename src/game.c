#include<stdlib.h>
#include"Headers/common.h"
#include"Headers/game.h"

game_t *        new_game(int x, int y)
{
    game_t *    g;

    g = (game_t *) malloc(sizeof(g));
    g->size.x = x;
    g->size.y = y;
    return g;
}

game_t * load_game(char * s)
{
    (void) s;
    game_t *    g;

    g = (game_t *) malloc(sizeof(g));
    return g;
}

void play_game(game_t * g)
{
    (void) g;
}