#include <stdlib.h>
#include "../../Headers/memory.h"

/* Usable functions */

inline t_game   *create_game(void)
{
    t_game      *g;

    g = (t_game *) malloc(sizeof(t_game));
    g->player = 0;
    g->map = 0;
    g->file = 0;
    return g;
}

inline void free_game(t_game *g)
{
    free_map(g->map);
    free_player(g->player);
    free(g);
}
