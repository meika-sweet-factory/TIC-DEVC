#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "../../Headers/helpers/conversion.h"
#include "../../Headers/initiator/file.h"
#include "../../Headers/player.h"
#include "../../Headers/memory.h"

/* Internal functions prototype */

_Bool   load_base   (t_game *g, int of);
_Bool   load_data   (t_game *g, int of);
void    load_spawns (t_map *m, t_axe a, char c);

/* Usable functions */

_Bool   load_map(t_game * restrict g, const char * restrict f)
{
    int of;

    if ((of = open(f, O_RDONLY)) == -1) return ERROR;
    g->file = f;
    if (!(load_base(g, of))) return ERROR;
    close(of);
    if ((of = open(f, O_RDONLY)) == -1) return ERROR;
    if (!(load_data(g, of))) return ERROR;
    close(of);
    return SUCCESS;
}

/* Internal functions */

inline _Bool    load_base(t_game *g, int of)
{
    int         k;
    int         tmp;
    char        bf[4096];
    t_axe       a;

    a.x = 0;
    tmp = 0;
    while (read(of, &bf, sizeof(bf)) > 0) {
        for (a.y = 0, k = 0; bf[k] != '\0'; ++a.x, ++k) {
            if (bf[k] == '\n' || bf[k] == '\0') {
                ++a.y;
                if (a.x - 1 > tmp) tmp = a.x;
                a.x = 0;
            }
        }
    }
    a.x = tmp;
    a.y += 1;
    if (!(init_map(g, a))) return ERROR;
    return SUCCESS;
}

inline _Bool    load_data(t_game *g, int of)
{
    int         k;
    ssize_t     r;
    char        bf[4096];
    t_axe       a;

    a.x = 0;
    while ((r = read(of, &bf, sizeof(bf))) > 0) {
        for (a.y = 0, k = 0; k < r; ++k) {
            if (bf[k] == 'b' || bf[k] == 'm') {
                load_spawns(g->map, a, bf[k]);
                g->map->board[a.y][a.x++] = TERRAIN;
            } else if (bf[k] == 's') {
                init_player(g, a);
                g->map->board[a.y][a.x++] = TERRAIN;
            } else if (bf[k] == '\n' || bf[k] == '\0') {
                g->map->board[a.y][a.x + 1] = '\0';
                if (!(g->map->board[++a.y] = create_map_cell(g->map->size.x + 1))) return ERROR;
                a.x = 0;
            } else if (bf[k] == '1')g->map->board[a.y][a.x++] = WALL;
            else g->map->board[a.y][a.x++] = TERRAIN;
        }
    }
    return SUCCESS;
}

inline void load_spawns(t_map *m, t_axe a, char c)
{
    if (c == 'b') {
        m->spawns.bonus.x = a.x * 10;
        m->spawns.bonus.y = a.y * 10;
    } else {
        m->spawns.malus.x = a.x * 10;
        m->spawns.malus.y = a.y * 10;
    }
}
