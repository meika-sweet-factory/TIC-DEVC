#ifndef _SNAKE_PILE_H_
#define _SNAKE_PILE_H_

#include "../structures/geometry.h"

typedef struct  s_pile_data
{
    t_axe       position;
}               t_pile_data;

typedef struct              pile_element_s
{
    t_pile_data             data;
    struct pile_element_s * next;
    struct pile_element_s * precedent;
}                           pile_element_t;

typedef struct        s_pile_list
{
    pile_element_t *  first;
    pile_element_t *  last;
    int               size;
}                     t_pile_list;

/* Usage functions */

t_pile_list *   pile_create   (void);
void            pile_stack    (t_pile_list * l, t_pile_data p);
t_pile_data     pile_unstack  (t_pile_list * l);
void            pile_free     (t_pile_list * l);

#endif //_SNAKE_PILE_H_
