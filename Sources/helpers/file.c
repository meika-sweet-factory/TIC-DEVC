#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "../../Headers/helpers/file.h"

axe_t   file_size   (int d);
game_t  * malloc_for_life(axe_t size_map, game_t * g);

_Bool               read_file(game_t * g, char * d)
{
    int             f;
    unsigned short  j;
    unsigned short  i;
    unsigned short  k;
    char            bf[4096]; // Optimized systems block size
    axe_t           final_size;

    j = 0;
    if ((f = open(d, O_RDONLY)) == -1) return ERROR;
    final_size = file_size(f);
    g = malloc_for_life(final_size, g);
    f = open(d, O_RDONLY);
    if (!(g->board = (char **) malloc((long unsigned int) final_size.y * sizeof(char **)))) return ERROR;
    g->board[0] = (char*) malloc((long unsigned int) final_size.x * sizeof(char*));
    while (read(f, &bf, 4096) > 0) {
        for (i = 0, k = 0; bf[k] != '\0' ; ++j, ++k)
        {
            if (bf[k] == '\n')
            {
                ++i;
                g->board[i] = (char*) malloc((long unsigned int) final_size.x * sizeof(char*));
                j = 0;
            } else g->board[i][j] = bf[k];
        }
    }
    return SUCCESS;
}

axe_t               file_size(int file)
{
    unsigned short  j;
    unsigned short  i;
    unsigned short  k;
    unsigned short  tmp;
    char            bf[4096];
    axe_t           size;

    j = 0;
    tmp = 0;
    while (read(file, &bf, 4096) > 0) {
        for (i = 0, k = 0; bf[k] != '\0' ; ++j, ++k)
        {
            if (bf[k] == '\n')
            {
                ++i;
                if (j > tmp) tmp = j;
                j = 0;
            };
        }
    }
    size.x = tmp;
    size.y = i;
    close(file);
    return size;
}

game_t             * malloc_for_life(axe_t size_map, game_t * g)
{
    unsigned short  i;


    for (i = 0; i < size_map.y; ++i)
    {

    }
    return g;
}
