#include <stdlib.h>
#include "../../Headers/memory.h"

inline t_game * create_game(void)
{
    return (t_game *) malloc(sizeof(t_game));
}

inline void free_game(t_game * g)
{
    free_map(g);
    free_player(g);
    free(g);
}
