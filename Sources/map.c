#include <stdlib.h>
#include "../Headers/helpers/string.h"
#include "../Headers/helpers/random.h"
#include "../Headers/memory.h"
#include "../Headers/player.h"
#include "../Headers/map.h"

_Bool       generate_map(t_game * g)
{
    t_axe   a;

    if (!(g->map.board = init_map(g->map.size.x, g->map.size.y))) return ERROR;
    for (a.i = 0; a.i < g->map.size.y; ++a.i) {
        if (!(g->map.board[a.i] = init_map_cell(g->map.size.x))) return ERROR;
        for (a.j = 0; a.j < g->map.size.x; ++a.j)
            if ((a.j == 0)||(a.j == g->map.size.x - 1))
                g->map.board[a.i][a.j] = '1';
            else if (((a.i == 0) || (a.i == g->map.size.y -1)) && a.j != g->map.size.x -1) 
                g->map.board[a.i][a.j] = '1';
            else if (a.j != g->map.size.x)
                g->map.board[a.i][a.j] = ' ';
        g->map.board[a.i][a.j] = '\0';
        a.j = 0;
    }
    if (!generate_spawn(g)) return ERROR;
    generate_snake(g);
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

    bonus = generate_rand_pos(g);
    g->map.spawns.bonus.x = bonus.x;
    g->map.spawns.bonus.y = bonus.y;
    malus = generate_rand_pos(g);
    while ((malus.y == bonus.y) && (malus.x == bonus.x)) malus = generate_rand_pos(g);
    g->map.spawns.malus.x = malus.x;
    g->map.spawns.malus.y = malus.y;
}

t_axe       generate_rand_pos(t_game * g)
{
    t_axe   item;

    item.x = rand_pos(g->map.size.x);
    item.y = rand_pos(g->map.size.y);
    return item;
}
