#ifndef _SNAKE_STUCTURE_PLAYER_H_
#define _SNAKE_STUCTURE_PLAYER_H_

#include "geometry.h"

typedef struct      player_s
{
    axe_t           position;
    int             size;
    int             speed;
    int             score;
}                   player_t;

#endif //_SNAKE_STUCTURE_PLAYER_H_
