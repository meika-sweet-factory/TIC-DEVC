#include<stdlib.h>
#include"pile.h"

/* Internal functions */

pile_element_t * list_extract(pile_list_t * l);

/* Usage functions */

/**
 * create a list
 *
 * @param   void
 * @return  pile_list_t
 */
pile_list_t *       pile_create()
{
    pile_list_t *   l;

    l = malloc(sizeof(l));
    l->first = NULL;
    l->last = NULL;
    l->size = 0;
    return l;
}

/**
 * stack a data
 *
 * @param   pile_list_t - l
 *          data_t - p
 * @return: void
 */
void                    pile_stack(pile_list_t * l, data_t p)
{
    pile_element_t *    e;

    e = malloc(sizeof(e));
    e->next = NULL;
    e->precedent = NULL;
    if (l->size == 0) l->last = e;
    else {
        l->first->next = e;
        e->precedent = l->first;
    }
    l->last = e;
    l->size++;
}

/**
 * unstack last data
 *
 * @param   pile_list_t - l
 * @return  data_t
 */
data_t                  pile_unstack(pile_list_t * l)
{
    pile_element_t *    e;
    data_t              d;

    e = list_extract(l);
    d = e->data;
    free(e);
    return d;
}

/**
 * destruct list
 *
 * @param   pile_list_t - l
 * @return  void
 */
void pile_free(pile_list_t * l)
{
    while (!(l->size == 0)) free(list_extract(l));
    free(l);
}

/* Internal function */

/**
 * extract an element
 *
 * @param   pile_list_t - l
 * @return  pile_element_t
 */
pile_element_t *        list_extract(pile_list_t * l)
{
    pile_element_t *    e;

    e = NULL;
    if (!(l->size == 0)) {
        e = l->first;
        l->first = e->next;
        e->next = NULL;
        l->size--;
        if (l->size == 0) l->last = NULL;
    }
    return e;
}
