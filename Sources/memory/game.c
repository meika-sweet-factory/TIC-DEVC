#include <stdlib.h>
#include "../../Headers/memory.h"

inline _Bool init_game(t_game * g)
{
    if (!(g = (t_game *) malloc(sizeof(t_game)))) return ERROR;
    return SUCCESS;
}

inline void free_game(t_game * g)
{
    free_map(g);
//    free_player(g);
    free(g);
}
