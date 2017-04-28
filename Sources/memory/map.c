#include <stdlib.h>
#include "../../Headers/memory.h"

inline char **  init_map(int x, int y)
{
    char **     b;

    b = (char **) malloc((long unsigned int) y * sizeof(char **));
    b[0] = init_map_cell(x);
    return b;
}

inline char * init_map_cell(int x)
{
    return (char *) malloc((long unsigned int) (x + 1) * sizeof(char *));
}

inline void free_map(t_game * g)
{
    int i;

    for (i = 0; i != g->map.size.y; ++i) free(g->map.board[i]);
    free(g->map.board);
}
