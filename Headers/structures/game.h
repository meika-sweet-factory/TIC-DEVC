#ifndef _SNAKE_STUCTURE_GAME_H_
#define _SNAKE_STUCTURE_GAME_H_

#include "geometry.h"

enum bonus
{
    GROW,
    FASTER,
};

enum mallus
{
    DIVIDE,
    DEATH
};

typedef struct  s_game
{
    char **     map;
    t_axe       size;
}               t_game;

#endif //_SNAKE_STUCTURE_GAME_H_
