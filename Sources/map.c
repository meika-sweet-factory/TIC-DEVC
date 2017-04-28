#include <stdlib.h>
#include "../Headers/helpers/print.h"
#include "../Headers/helpers/random.h"
#include "../Headers/memory.h"
#include "../Headers/player.h"
#include "../Headers/map.h"
#include "../Headers/helpers/conversion.h"

_Bool       generate_map(t_game * g, t_axe s)
{
    t_axe   a;

    if (s.x > MIN_WEED && s.x< MAX_WEED) return ERROR;
    if (s.y > MIN_WEED && s.y < MAX_HEIGHT) return ERROR;
    g->map.size.x = s.x;
    g->map.size.y = s.y;
    if (!(g->map.board = init_map(s.x, s.y))) return ERROR;
    for (a.y = 0; a.y < s.y; ++a.y) {
        if (!(g->map.board[a.y] = init_map_cell(s.x))) return ERROR;
        for (a.x = 0; a.x < s.x; ++a.x) {
            if ((a.x == 0)||(a.x == s.x - 1)) g->map.board[a.y][a.x] = '1';
            else if (((a.y == 0) || (a.y == s.y -1)) && a.x != s.x -1) g->map.board[a.y][a.x] = '1';
            else if (a.x != s.x) g->map.board[a.y][a.x] = ' ';
        }
        g->map.board[a.y][a.x] = '\0';
        a.x = 0;
    }
    generate_spawn(g);
    if (!generate_snake(g)) return ERROR;
    return SUCCESS;
}

_Bool generate_snake(t_game * g)
{
    if (!(g->player.body = pile_create())) return ERROR;
    g->map.board[g->map.size.y/2][(g->map.size.x/2) - 1] = 's';
    g->map.board[g->map.size.y/2][g->map.size.x/2] = 's';
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
