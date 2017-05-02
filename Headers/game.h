/*
** game.h for Snake in /home/asuramaru/Projects/snake/Headers
**
**        Made by PHETSINORATH William
**        Login   <phetsi_w@etna-alternance.net>
**
** Started on  Tue May  2 15:32:14 2017 PHETSINORATH William
** Last update Tue May  2 15:32:24 2017 PHETSINORATH William
*/

#ifndef _SNAKE_GAME_H_
#define _SNAKE_GAME_H_

#include "common.h"
#include "structures/game.h"

/* Usage functions */

_Bool   new_game    (t_game * g, const char * x, const char * y, _Bool (* callback)(t_game * g));
_Bool   load_game   (t_game * g, const char * f, _Bool (* callback)(t_game * g));
_Bool   play_game   (t_game * g);

#endif //_SNAKE_GAME_H_
