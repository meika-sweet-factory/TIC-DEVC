#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "../Headers/file.h"
#include "../Headers/memory.h"
#include "../Headers/helpers/print.h"

_Bool file_size(game_t * g, const char * f);

_Bool               load_file(game_t * g, const char * f, _Bool (* callback)(game_t * g))
{
    int             of;
    unsigned short  j;
    unsigned short  i;
    unsigned short  k;
    unsigned short  r;
    char            bf[4096];

    if (!(file_size(g, f))) return ERROR;
    if ((of = open(f, O_RDONLY)) == -1) return ERROR;
    j = 0;
    if (!(g->map = init_map(g->size.x, g->size.y))) return ERROR;
    while ((r = (unsigned short) read(of, &bf, 4096)) > 0)
        for (i = 0, k = 0; k < r; ++k) {
            if (bf[k] == '\n') {
                g->map[i][j + 1] = '\0';
                if (!(g->map[++i] = init_map_cell(g->size.x + 1))) return ERROR;
                j = 0;
            } else g->map[i][j++] = bf[k];
        }
    close(of);
    if (!callback(g)) return ERROR;
    free_map(g);
    return SUCCESS;
}

inline _Bool        file_size(game_t * g, const char * f)
{
    int             of;
    unsigned short  j;
    unsigned short  i;
    unsigned short  k;
    unsigned short  tmp;
    char            bf[4096];

    if ((of = open(f, O_RDONLY)) == -1) return ERROR;
    j = 0;
    tmp = 0;
    while (read(of, &bf, sizeof(bf)) > 0)
        for (i = 0, k = 0; bf[k] != '\0'; ++j, ++k) {
            if (bf[k] == '\n') {
                ++i;
                if (j > tmp) tmp = j;
                j = 0;
            }
            if (tmp > 100 || i > 100) return ERROR;
        }
    g->size.x = tmp;
    g->size.y = ++i;
    close(of);
    return SUCCESS;
}