#ifndef __SNAKE_STUCTURE_GAME_H__
#define __SNAKE_STUCTURE_GAME_H__

#include"geometry.h"

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

#endif //__SNAKE_STUCTURE_GAME_H__
