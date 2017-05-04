#include <stdlib.h>
#include "../../Headers/memory.h"

/* Usable functions */

inline _Bool init_map(t_game *g, t_axe s)
{
    if (s.x < MIN_WEED || s.x > MAX_WEED) return ERROR;
    if (s.y < MIN_HEIGHT || s.y > MAX_HEIGHT) return ERROR;
    if (!(g->map = (t_map *) malloc(sizeof(t_map)))) return ERROR;
    g->map->size = s;
    g->map->board = (t_board **) malloc((unsigned long) s.y * sizeof(t_board *));
    g->map->board[0] = create_map_cell(s.x);
    g->map->spawns.bonus.x = 0;
    g->map->spawns.bonus.y = 0;
    g->map->spawns.malus.x = 0;
    g->map->spawns.malus.y = 0;
    return SUCCESS;
}

inline t_board * create_map_cell(int x)
{
    return (t_board *) malloc((unsigned long) (x + 1) * sizeof(t_board));
}

inline void free_map(t_map *m)
{
    int     i;

    for (i = 0; i != m->size.y; ++i) free(m->board[i]);
    free(m->board);
    free(m);
}
