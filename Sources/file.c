#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "../Headers/file.h"
#include "../Headers/memory.h"
#include "../Headers/helpers/print.h"

_Bool       file_size   (t_game * restrict g, const char * restrict f);
t_game *    get_data    (t_game * g, int of);
void        set_spawns  (t_game * g, t_axe a, char c);

_Bool   load_file(t_game * restrict g, const char * restrict f)
{
    int of;

    if (!(file_size(g, f))) return ERROR;
    if ((of = open(f, O_RDONLY)) == -1) return ERROR;
    g = get_data(g, of);
    close(of);
    return SUCCESS;
}

inline _Bool        file_size(t_game * restrict g, const char * restrict f)
{
    int             of;
    unsigned short  k;
    unsigned short  tmp;
    char            bf[4096];
    t_axe           a;

    if ((of = open(f, O_RDONLY)) == -1) return ERROR;
    a.x = 0;
    tmp = 0;
    while (read(of, &bf, sizeof(bf)) > 0)
        for (a.y = 0, k = 0; bf[k] != '\0'; ++a.x, ++k) {
            if (bf[k] == '\n') {
                ++a.y;
                if (a.x > tmp) tmp = a.x;
                a.x = 0;
            }
        }
    if (a.x > MIN_WEED && a.x< MAX_WEED) return ERROR;
    if (a.y > MIN_WEED && a.y < MAX_HEIGHT) return ERROR;
    g->map.size.x = tmp;
    g->map.size.y = ++a.y;
    close(of);
    return SUCCESS;
}

t_game *            get_data(t_game * g, int of)
{
    unsigned short  k;
    unsigned short  r;
    char            bf[4096];
    t_axe           a;

    a.x = 0;
    if (!(g->map.board = init_map(g->map.size.x, g->map.size.y))) return ERROR;
    while ((r = (unsigned short) read(of, &bf, 4096)) > 0)
        for (a.y = 0, k = 0; k < r; ++k) {
            if (bf[k] == 'b' || bf[k] == 'm') {
                set_spawns(g, a, bf[k]);
                g->map.board[a.y][a.x++] = ' ';
            }
            else if (bf[k] == '\n') {
                g->map.board[a.y][a.x + 1] = '\0';
                if (!(g->map.board[++a.y] = init_map_cell(g->map.size.x + 1))) return ERROR;
                a.x = 0;
            } else g->map.board[a.y][a.x++] = bf[k];
        }
    return g;
}

void set_spawns(t_game * g, t_axe a, char c)
{
    if (c == 'b') {
        g->map.spawns.bonus.x = a.x;
        g->map.spawns.bonus.y = a.y;
    } else {
        g->map.spawns.malus.x = a.x;
        g->map.spawns.malus.y = a.y;
    }
}
