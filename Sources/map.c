#include <stdlib.h>
#include "../Headers/helpers/random.h"
#include "../Headers/map.h"
#include "../Headers/memory.h"
#include "../Headers/player.h"
#include "../Headers/memory.h"

_Bool       generate_map(t_game * g, t_axe s)
{
    t_axe   a;

    if (!init_map(g, s)) return ERROR;
    for (a.y = 0; a.y < s.y; ++a.y) {
        if (!(g->map.board[a.y] = map_cell_create(s.x))) return ERROR;
        for (a.x = 0; a.x < s.x; ++a.x) {
            if ((a.x == 0)||(a.x == s.x - 1)) g->map.board[a.y][a.x] = '1';
            else if (((a.y == 0) || (a.y == s.y -1)) && a.x != s.x -1) g->map.board[a.y][a.x] = '1';
            else if (a.x != s.x) g->map.board[a.y][a.x] = ' ';
        }
        g->map.board[a.y][a.x] = '\0';
        a.x = 0;
    }
    generate_spawn(g);
    if (!init_player(g, s)) return ERROR;
    return SUCCESS;
}

void        generate_spawn(t_game * g)
{
    t_axe   bonus;
    t_axe   malus;

    bonus = generate_rand_pos(g, 0);
    g->map.spawns.bonus.x = bonus.x;
    g->map.spawns.bonus.y = bonus.y;
    malus = generate_rand_pos(g, 0);
    while (malus.y == bonus.y && malus.x == bonus.x) malus = generate_rand_pos(g, 0);
    g->map.spawns.malus.x = malus.x;
    g->map.spawns.malus.y = malus.y;
}
