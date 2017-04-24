#include<stdlib.h>
#include"file.h"

/* Internal functions */

file_element_t * list_extract(file_list_t * l);

/* Usage functions */

/**
 * create a list
 *
 * @param   void
 * @return  file_list_t
 */
file_list_t *       file_create()
{
    file_list_t *   l;

    l = (file_list_t)malloc(sizeof(l));
    l->first = NULL;
    l->last = NULL;
    l->size = 0;
    return l;
}

/**
 * stack a data
 *
 * @param   file_list_t - l
 *          data_t - p
 * @return: void
 */
void                    file_thread(file_list_t * l, data_t p)
{
    file_element_t *    e;

    e = malloc(sizeof(e));
    e->next = NULL;
    e->precedent = NULL;
    if (l->size == 0) l->first = e;
    else {
        l->last->next = e;
        e->precedent = l->last;
    }
    l->last = e;
    l->size++;
}

/**
 * unstack last data
 *
 * @param   file_list_t - l
 * @return  data_t
 */
data_t                  file_unthread(file_list_t * l) {
    file_element_t *    e;
    data_t              d;

    e = list_extract(l);
    d = e->data;
    free(e);
    return d;
}

/**
 * destruct list
 *
 * @param   file_list_t - l
 * @return  void
 */
void file_free(file_list_t * l)
{
    while (!(l->size == 0)) free(list_extract(l));
    free(l);
}

/* Internal function */

/**
 * extract an element
 *
 * @param   file_list_t - l
 * @return  file_element_t
 */
file_element_t *        list_extract(file_list_t * l)
{
    file_element_t *    e;

    e = NULL;
    if (!(l->size == 0)) {
        e = l->last;
        l->last = e->precedent;
        l->size--;
        if (!(l->size == 0)) {
            e->next = NULL;
            l->last->next = NULL;
        }
    } else l->first = NULL;
  return e;
}
