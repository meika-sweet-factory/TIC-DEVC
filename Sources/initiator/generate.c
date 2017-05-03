#include <stdlib.h>
#include "../../Headers/helpers/random.h"
#include "../../Headers/initiator/generate.h"
#include "../../Headers/memory.h"
#include "../../Headers/player.h"
#include "../../Headers/memory.h"

void    generate_spawns (t_map *m);
void    generate_snake  (t_player *p, t_axe a);

_Bool       generate_map(t_game *g, t_axe s)
{
    t_axe   a;

    if (!init_map(g, s)) return ERROR;
    for (a.y = 0; a.y < s.y; ++a.y) {
        if (!(g->map->board[a.y] = create_map_cell(s.x))) return ERROR;
        for (a.x = 0; a.x < s.x; ++a.x) {
            if ((a.x == 0)||(a.x == s.x - 1)) g->map->board[a.y][a.x] = '1';
            else if (((a.y == 0) || (a.y == s.y -1)) && a.x != s.x -1) g->map->board[a.y][a.x] = '1';
            else if (a.x != s.x) g->map->board[a.y][a.x] = ' ';
        }
        g->map->board[a.y][a.x] = '\0';
        a.x = 0;
    }
    generate_spawns(g->map);
    if (!init_player(g, s)) return ERROR;
    generate_snake(g->player, s);
    return SUCCESS;
}

inline void generate_spawns(t_map *m)
{
    t_axe   bonus;
    t_axe   malus;

    bonus = generate_rand_pos(m, 0);
    m->spawns.bonus.x = bonus.x;
    m->spawns.bonus.y = bonus.y;
    malus = generate_rand_pos(m, 0);
    while (malus.y == bonus.y && malus.x == bonus.x) {
        malus = generate_rand_pos(m, 0);
    }
    m->spawns.malus.x = malus.x;
    m->spawns.malus.y = malus.y;
}

inline void         generate_snake(t_player *p, t_axe a)
{
    a.x = a.x / 2 * 10;
    a.y = a.y / 2 * 10;
    add_player_queue(p, a);
    --a.x;
    add_player_queue(p, a);
    --a.x;
    add_player_queue(p, a);
}