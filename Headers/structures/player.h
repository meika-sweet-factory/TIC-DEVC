/*
** player.h for Snake in /home/asuramaru/Projects/snake/Headers/structures
**
**        Made by PHETSINORATH William
**        Login   <phetsi_w@etna-alternance.net>
**
** Started on  Tue May  2 15:32:14 2017 PHETSINORATH William
** Last update Tue May  2 15:32:24 2017 PHETSINORATH William
*/

#ifndef _SNAKE_STUCTURE_PLAYER_H_
#define _SNAKE_STUCTURE_PLAYER_H_

#include "geometry.h"

typedef enum s_direction { TOP, BOT, RIGHT, LEFT } e_direction;

/* Pile */

typedef struct  s_pile_data
{
    t_axe       coordonate;
}               t_pile_data;

typedef struct              s_pile_element
{
    t_pile_data             data;
    struct s_pile_element * next;
    struct s_pile_element * precedent;
}                           t_pile_element;

typedef struct        s_pile_list
{
    t_pile_element *  first;
    t_pile_element *  last;
    int               size;
}                     t_pile_list;

/* Player */

typedef struct  s_stat
{
    int         size;
    int         speed;
}               t_stat;

typedef struct      s_player
{
    t_stat          stat;
    t_pile_list *   body;
    e_direction     direction;
    int             score;
}                   t_player;

#endif //_SNAKE_STUCTURE_PLAYER_H_
