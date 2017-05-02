/*
** geometry.h for Snake in /home/asuramaru/Projects/snake/Headers/structures
**
**        Made by PHETSINORATH William
**        Login   <phetsi_w@etna-alternance.net>
**
** Started on  Tue May  2 15:32:14 2017 PHETSINORATH William
** Last update Tue May  2 15:32:24 2017 PHETSINORATH William
*/

#ifndef _SNAKE_STUCTURE_GEOMETRY_H_
#define _SNAKE_STUCTURE_GEOMETRY_H_

typedef union   s_number
{
    int         snint;
    unsigned    unint;
    short       snshort;
    unsigned    unshort;
}               u_number;

typedef struct      s_axe
{
    unsigned short  x;
    unsigned short  y;
}                   t_axe;

#endif //_SNAKE_STUCTURE_GEOMETRY_H_
