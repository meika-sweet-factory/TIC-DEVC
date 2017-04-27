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

typedef struct      map_size_s
{
    unsigned short  x;
    unsigned short  y;
}                   map_size_t;

typedef struct  game_s
{
    char **     map;
    map_size_t  size;
}               game_t;

#endif //_SNAKE_STUCTURE_GAME_H_
