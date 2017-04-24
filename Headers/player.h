#ifndef __SNAKE_PLAYER_H__
#define __SNAKE_PLAYER_H__

#include"game.h"

/* Helpers */

typedef struct      snake_s
{
    axe_t           position;
    int             size;
    int             speed;
    int             score;
}                   snake_t;

#endif //__SNAKE_PLAYER_H__
