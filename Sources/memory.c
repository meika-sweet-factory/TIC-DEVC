#include <stdlib.h>
#include "../Headers/memory.h"
#include "../Headers/helpers/print.h"

inline game_t * init_game(void)
{
    return (game_t *) malloc(sizeof(game_t));
}

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

inline void free_game(game_t * g)
{
    free(g);
}

inline  void free_map(game_t * g)
{
    int i;

    free(g->map);
    for (i = 0; g->map[i] != '\0'; ++i) free(g->map[i]);
}
