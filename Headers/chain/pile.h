/*
** pile.h for Snake in /home/asuramaru/Projects/snake/Headers/chain
**
**        Made by PHETSINORATH William
**        Login   <phetsi_w@etna-alternance.net>
**
** Started on  Tue May  2 15:32:14 2017 PHETSINORATH William
** Last update Tue May  2 15:32:24 2017 PHETSINORATH William
*/

#ifndef _SNAKE_PILE_H_
#define _SNAKE_PILE_H_

#include "../structures/player.h"

/* Usage functions */

t_pile_list *   pile_create   (void);
void            pile_stack    (t_pile_list * l, t_pile_data p);
t_pile_data     pile_unstack  (t_pile_list * l);
void            pile_free     (t_pile_list * l);

#endif //_SNAKE_PILE_H_
