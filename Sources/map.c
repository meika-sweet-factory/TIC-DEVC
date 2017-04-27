#include <stdlib.h>
#include "../Headers/helpers/string.h"
#include "../Headers/memory.h"
#include "../Headers/map.h"

_Bool               init_map(game_t * g, const char * x, const char * y)
{
    unsigned int    i;
    unsigned int    j;

    g->size.x = str_to_int(x);
    g->size.y = str_to_int(y);
    if (!(g->board = init_board(g->size.x, g->size.y))) return ERROR;
    for (i = 0; i < (unsigned int) g->size.y; ++i) {
        if (!(g->board[i] = init_board_cell(g->size.x))) return ERROR;
        for (j = 0; j < (unsigned int) g->size.x; ++j) {
            if ((j == 0)||(j == (unsigned int) g->size.x - 1)) g->board[i][j] = '1';
            else if (((i == 0) || (i == (unsigned int) g->size.y -1)) && j != (unsigned int) g->size.x -1) g->board[i][j] = '1';
            else if (j != (unsigned int) g->size.x) g->board[i][j] = ' ';
        }
        g->board[i][j] = '\0';
        j = 0;
    }
    return SUCCESS
}
