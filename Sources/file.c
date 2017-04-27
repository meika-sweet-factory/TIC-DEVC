#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "../Headers/file.h"
#include "../Headers/memory.h"
#include "../Headers/helpers/print.h"

_Bool       file_size   (t_game * restrict g, const char * restrict f);
t_game *    get_data    (t_game * g, int of);
void        set_spawns  (t_game * g, char c, unsigned short i, unsigned short j);

_Bool               load_file(t_game * restrict g,
                              const char * restrict f,
                              _Bool (* callback)(t_game * g))
{
    int             of;

    if (!(file_size(g, f))) return ERROR;
    if ((of = open(f, O_RDONLY)) == -1) return ERROR;
    g = get_data(g, of);
    close(of);
    if (!callback(g)) return ERROR;
    free_map(g);
    return SUCCESS;
}

inline _Bool        file_size(t_game * restrict g,
                                const char * restrict f)
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
    g->map.size.x = tmp;
    g->map.size.y = ++i;
    close(of);
    return SUCCESS;
}

t_game *            get_data(t_game * g, int of)
{
    unsigned short  j;
    unsigned short  i;
    unsigned short  k;
    unsigned short  r;
    char            bf[4096];

    j = 0;
    if (!(g->map.board = init_map(g->map.size.x, g->map.size.y))) return ERROR;
    while ((r = (unsigned short) read(of, &bf, 4096)) > 0)
        for (i = 0, k = 0; k < r; ++k) {
            if (bf[k] == 'b' || bf[k] == 'm') {
                set_spawns(g, bf[k], i, j);
                g->map.board[i][j++] = ' ';
            }
            else if (bf[k] == '\n') {
                g->map.board[i][j + 1] = '\0';
                if (!(g->map.board[++i] = init_map_cell(g->map.size.x + 1))) return ERROR;
                j = 0;
            } else g->map.board[i][j++] = bf[k];
        }
    return g;
}

void set_spawns(t_game * g, char c, unsigned short i, unsigned short j)
{
    if (c == 'b') {
        g->map.spawns.bonus.x = j;
        g->map.spawns.bonus.y = i;
    } else {
        g->map.spawns.malus.x = j;
        g->map.spawns.malus.y = i;
    }
}
