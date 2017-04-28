#include <stdlib.h>
#include "../../Headers/memory.h"

inline char **  init_map(t_game * g, t_axe s)
{
    char **     b;

    if (s.x > MIN_WEED && s.x< MAX_WEED) return ERROR;
    if (s.y > MIN_WEED && s.y < MAX_HEIGHT) return ERROR;
    g->map.size = s;
    b = (char **) malloc((long unsigned int) s.y * sizeof(char **));
    b[0] = map_cell_create(x);
    return b;
}

inline char * map_cell_create(int x)
{
    return (char *) malloc((long unsigned int) (x + 1) * sizeof(char *));
}

inline void free_map(t_game * g)
{
    int i;

    for (i = 0; i != g->map.size.y; ++i) free(g->map.board[i]);
    free(g->map.board);
}
