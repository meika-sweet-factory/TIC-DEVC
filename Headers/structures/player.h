#ifndef _SNAKE_STUCTURE_PLAYER_H_
#define _SNAKE_STUCTURE_PLAYER_H_

#include "geometry.h"
#include "../chain/pile.h"

typedef struct  s_pstat
{
    int         size;
    int         speed;
}               t_pstat;

typedef struct  s_player
{
    t_pstat     stat;
    t_pile_list body;
    int         score;
}               t_player;

#endif //_SNAKE_STUCTURE_PLAYER_H_
