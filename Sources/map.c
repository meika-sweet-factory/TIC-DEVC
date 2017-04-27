#include <stdlib.h>
#include "../Headers/helpers/string.h"
#include "../Headers/memory.h"
#include "../Headers/map.h"

_Bool               generate_map(game_t * g, const char * x, const char * y)
{
    unsigned short  i;
    unsigned short  j;

    g->size.x = str_to_unshort(x);
    g->size.y = str_to_unshort(y);
    if (!(g->map = init_map(g->size.x, g->size.y))) return ERROR;
    for (i = 0; i < g->size.y; ++i) {
        if (!(g->map[i] = init_map_cell(g->size.x))) return ERROR;
        for (j = 0; j < g->size.x; ++j) {
            if ((j == 0)||(j == g->size.x - 1)) g->map[i][j] = '1';
            else if (((i == 0) || (i == g->size.y -1)) && j != g->size.x -1) g->map[i][j] = '1';
            else if (j != g->size.x) g->map[i][j] = ' ';
        }
        g->map[i][j] = '\0';
        j = 0;
    }
    return SUCCESS
}
