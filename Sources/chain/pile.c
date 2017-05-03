#include <stdlib.h>
#include "../../Headers/chain/pile.h"

/* Internal functions */

t_pile_element * pile_list_extract(t_pile_list * l);

/* Usage functions */

/**
 * create a list
 *
 * @param   void
 * @return  t_pile_list
 */
t_pile_list *       pile_create()
{
    t_pile_list *   l;

    l = (t_pile_list *) malloc(sizeof(t_pile_list));
    l->first = 0;
    l->last = 0;
    l->size = 0;
    return l;
}

/**
 * stack a data
 *
 * @param   t_pile_list - l
 *          t_pile_data - p
 * @return: void
 */
void                    pile_stack(t_pile_list * l, t_pile_data p)
{
    t_pile_element *    e;

    e = malloc(sizeof(t_pile_element));
    e->data = p;
    e->next = 0;
    e->precedent = 0;
    if (l->size == 0) l->first = e;
    else {
        e->next = l->first->next;
        l->first->next = e;
        e->precedent = l->first;
    }
    l->last = e;
    l->size++;
}

/**
 * unstack last data
 *
 * @param   t_pile_list - l
 * @return  t_pile_data
 */
t_pile_data             pile_unstack(t_pile_list * l)
{
    t_pile_element *    e;
    t_pile_data         d;

    e = pile_list_extract(l);
    d = e->data;
    free(e);
    return d;
}

/**
 * destruct list
 *
 * @param   t_pile_list - l
 * @return  void
 */
void pile_free(t_pile_list * l)
{
    while (l->size != 0) free(pile_list_extract(l));
    free(l);
}

/* Internal function */

/**
 * extract an element
 *
 * @param   t_pile_list - l
 * @return  t_pile_element
 */
t_pile_element *        pile_list_extract(t_pile_list * l)
{
    t_pile_element *    e;

    e = 0;
    if (l->size != 0) {
        e = l->first;
        l->first = e->next;
        e->next = 0;
        l->size--;
        if (l->size == 0) l->last = 0;
    }
    return e;
}
