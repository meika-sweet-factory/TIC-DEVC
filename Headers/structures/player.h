#ifndef _SNAKE_STUCTURE_PLAYER_H_
#define _SNAKE_STUCTURE_PLAYER_H_

#include "geometry.h"

typedef struct      s_player
{
    t_axe           position;
    int             size;
    int             speed;
    int             score;
}                   t_player;

#endif //_SNAKE_STUCTURE_PLAYER_H_
