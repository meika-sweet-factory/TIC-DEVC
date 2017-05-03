#include <stdlib.h>
#include "../../Headers/helpers/random.h"
#include "../../Headers/initiator/generate.h"
#include "../../Headers/memory.h"
#include "../../Headers/player.h"
#include "../../Headers/memory.h"

void    generate_spawns (t_map * m);
void    generate_snake  (t_player * p, t_axe a);

_Bool       generate_map(t_game * g, t_axe s)
{
    t_axe   a;

    if (!init_map(g, s)) return ERROR;
    for (a.y = 0; a.y < s.y; ++a.y) {
        if (!(g->map->board[a.y] = create_map_cell(s.x))) return ERROR;
        for (a.x = 0; a.x < s.x; ++a.x) {
            if ((a.x == 0 || a.x == s.x - 1) || ((a.y == 0 || a.y == s.y - 1) && a.x != s.x - 1)) {
                g->map->board[a.y][a.x] = WALL;
            } else if (a.x != s.x) g->map->board[a.y][a.x] = TERRAIN;
        }
        g->map->board[a.y][a.x] = '\0';
        a.x = 0;
    }
    s.x /= 2;
    s.y /= 2;
    if (!init_player(g, s)) return ERROR;
    generate_spawns(g->map);
    generate_snake(g->player, s);
    return SUCCESS;
}

inline void generate_spawns(t_map * m)
{
    t_axe   bs;
    t_axe   ms;

    bs = generate_rand_pos(m, 0);
    m->spawns.bonus.x = bs.x * 10;
    m->spawns.bonus.y = bs.y * 10;
    ms = generate_rand_pos(m, 0);
    while (ms.y == bs.y && ms.x == bs.x) ms = generate_rand_pos(m, 0);
    m->spawns.malus.x = ms.x * 10;
    m->spawns.malus.y = ms.y * 10;
}

inline void         generate_snake(t_player *p, t_axe a)
{
    a.x = (a.x / 2) * 10;
    a.y = (a.y / 2) * 10;
    add_player_queue(p, a);
}