#ifndef SNAKE_PILE_H
#define SNAKE_PILE_H

/* Helpers */

typedef struct  data_s
{
  int           foo;
}               data_t;

typedef struct              pile_element_s
{
  data_t                    data;
  struct pile_element_s *   next;
  struct pile_element_s *   precedent;
}                           pile_element_t;

typedef struct      pile_list_s
{
  pile_element_t *  first;
  pile_element_t *  last;
  int               size;
}                   pile_list_t;

/* Usage functions */

pile_list_t * pile_create   (void);
void          pile_stack    (pile_list_t * l, data_t p);
data_t        pile_unstack  (pile_list_t * l);
void          pile_free     (pile_list_t * l);

#endif //SNAKE_PILE_H
