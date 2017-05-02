/*
** random.h for Snake in /home/asuramaru/Projects/snake/Headers/helpers
**
**        Made by BAILLIF Killian
**        Login   <bailli_k@etna-alternance.net>
**
** Started on  Tue May  2 15:32:14 2017 BAILLIF Killian
** Last update Tue May  2 15:32:24 2017 BAILLIF Killian
*/

#ifndef _RANDOM_H_
#define _RANDOM_H_

#include "../../Headers/structures/geometry.h"
#include "../../Headers/structures/game.h"

t_axe           generate_rand_pos   (t_game * g, int type);
unsigned short  rand_pos            (unsigned short max);
unsigned short  initial_rand_pos    (unsigned short max);

#endif //_RANDOM_H_
