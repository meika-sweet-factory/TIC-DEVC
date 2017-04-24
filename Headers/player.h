#ifndef SNAKE_PLAYER_H
#define SNAKE_PLAYER_H

#include"game.h"

/* Helpers */

typedef struct      snake_s
{
    axe_t           position;
    int             size;
    int             speed;
    int             score;
}                   snake_t;

#endif //SNAKE_PLAYER_H
