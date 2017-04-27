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

typedef struct      game_s
{
    char **         board;
    axe_t           size;
}                   game_t;

#endif //_SNAKE_STUCTURE_GAME_H_
