/*
** print.h for Snake in /home/asuramaru/Projects/snake/Headers/structures
**
**        Made by PHETSINORATH William
**        Login   <phetsi_w@etna-alternance.net>
**
** Started on  Tue May  2 15:32:14 2017 PHETSINORATH William
** Last update Tue May  2 15:32:24 2017 PHETSINORATH William
*/

#ifndef _SNAKE_STUCTURE_GAME_H_
#define _SNAKE_STUCTURE_GAME_H_

#include "geometry.h"
#include "player.h"
#include "map.h"

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
    int         i;
    t_map *     map;
    t_player *  player;
}               t_game;

#endif //_SNAKE_STUCTURE_GAME_H_
