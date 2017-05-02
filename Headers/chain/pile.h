#ifndef _SNAKE_PILE_H_
#define _SNAKE_PILE_H_

#include "../structures/player.h"

/* Usage functions */

t_pile_list *   pile_create   (void);
void            pile_stack    (t_pile_list * l, t_pile_data p);
t_pile_data     pile_unstack  (t_pile_list * l);
void            pile_free     (t_pile_list * l);

#endif //_SNAKE_PILE_H_
