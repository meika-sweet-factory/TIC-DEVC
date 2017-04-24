#ifndef __SNAKE_STUCTURE_PLAYER_H__
#define __SNAKE_STUCTURE_PLAYER_H__

#include"geometry.h"

typedef struct      player_s
{
    axe_t           position;
    int             size;
    int             speed;
    int             score;
}                   player_t;

#endif //__SNAKE_STUCTURE_PLAYER_H__
