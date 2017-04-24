#include"Headers/game.h"

game_t      new_game()
{
    game_t  g;

    game = (game_t) malloc(sizeof(g));
    game->size.x = 10;
    game->size.y = 10;
    return g;
}
