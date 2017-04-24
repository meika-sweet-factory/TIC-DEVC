#include<stdlib.h>
#include"../Headers/helpers/string.h"
#include"../Headers/helpers/print.h"
#include"../Headers/game.h"

int new_game(game_t * g, char * x, char * y)
{
    if ((g = (game_t *) malloc(sizeof(g)))) return 0;
    if (!(g->size.x = str_to_int(x))) return 0;
    if (!(g->size.y = str_to_int(y))) return 0;
    return 1;
}

int load_game(game_t * g, char * d)
{
    if ((file = open(d, O_RDONLY)) return 0;
    if ((g = (game_t *) malloc(sizeof(g)))) return 0;
    return 1;
}

int play_game(game_t * g)
{
    (void) g;
    return 1;
}

int read_file(char ** g)
{
    char            b[4096]; // Optimized systems block sizes 
    char **         g;
    unsigned short  i;
    unsigned short  j;

    while (read(file, &b, 4096) > 0) {
        for (i = 0, j = 0; b[i][j] != '\0'; ++j) {
            if (b[i][j] == '\n') ++i, j = -1;
            else g[i][j] = b[i][j];
        }
    }
    return 1;
}