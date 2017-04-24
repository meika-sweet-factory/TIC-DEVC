#ifndef FILE_H
#define FILE_H

/* Helpers */

typedef struct  data_s
{
  int           foo;
}               data_t;

typedef struct              file_element_s
{
  data_t                    data;
  struct file_element_s *   next;
  struct file_element_s *   precedent;
}                           file_element_t;

typedef struct      file_list_s
{
  file_element_t *  first;
  file_element_t *  last;
  int               size;
}                   file_list_t;

/* Usage functions */

file_list_t *   file_create     (void);
void            file_thread     (file_list_t * l, data_t p);
data_t          file_unthread   (file_list_t * l);
void            file_free       (file_list_t * l);

#endif //FILE_H
