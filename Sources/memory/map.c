#include <stdlib.h>
#include "../../Headers/memory.h"

inline _Bool    init_map(t_game *g, t_axe s)
{
    if (s.x < MIN_WEED || s.x > MAX_WEED) return ERROR;
    if (s.y < MIN_HEIGHT || s.y > MAX_HEIGHT) return ERROR;
    if (!(g->map = (t_map *) malloc(sizeof(t_map)))) return ERROR;
    g->map->size = s;
    g->map->board = (char **) malloc((unsigned long) s.y * sizeof(char *));
    g->map->board[0] = create_map_cell(s.x);
    return SUCCESS;
}

inline char * create_map_cell(int x)
{
    return (char *) malloc((unsigned long) (x + 1) * sizeof(char));
}

inline void free_map(t_map *m)
{
    int i;

    for (i = 0; i != m->size.y; ++i) free(m->board[i]);
    free(m->board);
    free(m);
}
