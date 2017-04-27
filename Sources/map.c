#include <stdlib.h>
#include "../../Headers/helpers/new_map.h"
#include "../../Headers/helpers/print.h"

_Bool               create_file(game_t * g)
{
    unsigned int    i;
    unsigned int    j;

    if (!(g->board = init_board(g->size.x, g->size.y))) return ERROR;
    for (i = 0; i < g->size.y; ++i) {
        if (!(g->board[i] = init_board_cell(g->size.x))) return ERROR;
        for (j = 0; j < g->size.x; ++j) {
            if ((j == 0)||(j == g->size.x - 1)) g->board[i][j] = '1';
            else if (((i == 0) || (i == g->size.y -1)) && j != g->size.x -1) g->board[i][j] = '1';
            else if (j != g->size.x) g->board[i][j] = ' ';
        }
        g->board[i][j] = '\0';
        j = 0;
    }
    return SUCCESS
}
