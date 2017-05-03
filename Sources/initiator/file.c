#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "../../Headers/helpers/conversion.h"
#include "../../Headers/initiator/file.h"
#include "../../Headers/player.h"
#include "../../Headers/memory.h"

_Bool           load_base   (t_game *g, int of);
_Bool           load_data   (t_game *g, int of);
void            load_spawns (t_game *g, t_axe a, char c);

_Bool   load_map(t_game * restrict g, const char * restrict f)
{
    int of;

    if ((of = open(f, O_RDONLY)) == -1) return ERROR;
    if (!(load_base(g, of))) return ERROR;
    close(of);
    if ((of = open(f, O_RDONLY)) == -1) return ERROR;
    if (!(load_data(g, of))) return ERROR;
    close(of);
    return SUCCESS;
}

inline _Bool        load_base(t_game *g, int of)
{
    unsigned short  k;
    unsigned short  tmp;
    char            bf[4096];
    t_axe           a;

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

_Bool               load_data(t_game *g, int of)
{
    unsigned short  k;
    unsigned short  r;
    char            bf[4096];
    t_axe           a;

    a.x = 0;
    while ((r = read(of, &bf, sizeof(bf))) > 0) {
        for (a.y = 0, k = 0; k < r; ++k) {
            if (bf[k] == 'b' || bf[k] == 'm') {
                load_spawns(g, a, bf[k]);
                g->map->board[a.y][a.x++] = ' ';
            } else if (bf[k] == 's') {
                init_player(g, a);
                g->map->board[a.y][a.x++] = ' ';
            } else if (bf[k] == '\n' || bf[k] == '\0') {
                g->map->board[a.y][a.x + 1] = '\0';
                if (!(g->map->board[++a.y] = create_map_cell(g->map->size.x + 1))) return ERROR;
                a.x = 0;
            } else g->map->board[a.y][a.x++] = bf[k];
        }
    }
    return SUCCESS;
}

void load_spawns(t_game * g, t_axe a, char c)
{
    if (c == 'b') {
        g->map->spawns.bonus.x = a.x;
        g->map->spawns.bonus.y = a.y;
    }
    else {
        g->map->spawns.malus.x = a.x;
        g->map->spawns.malus.y = a.y;
    }
}
