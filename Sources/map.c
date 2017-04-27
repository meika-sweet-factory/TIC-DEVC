#include <stdlib.h>
#include "../Headers/helpers/print.h"
#include "../Headers/helpers/string.h"
#include "../Headers/helpers/random.h"
#include "../Headers/memory.h"
#include "../Headers/map.h"

t_game             *generate_bonus_malus(t_game *g);
t_axe              generate_rand_pos(t_game *g);

_Bool              generate_map(t_game * g, const char * x, const char * y)
{
    unsigned short i;
    unsigned short j;

    g->size.x = str_to_unshort(x);
    g->size.y = str_to_unshort(y);
    if (!(g->map = init_map(g->size.x, g->size.y))) return ERROR;
    for (i = 0; i < g->size.y; ++i) {
        if (!(g->map[i] = init_map_cell(g->size.x))) return ERROR;
        for (j = 0; j < g->size.x; ++j) {
            if ((j == 0)||(j == g->size.x - 1)) g->map[i][j] = '1';
            else if (((i == 0) || (i == g->size.y -1)) && j != g->size.x -1) g->map[i][j] = '1';
            else if (j != g->size.x) g->map[i][j] = ' ';
        }
        g->map[i][j] = '\0';
        j = 0;
    }
    g = generate_bonus_malus(g);
    for (i = 0; i < g->size.y; ++i) {
        print_str(g->map[i]);
        print_char('\n');
    }
    return SUCCESS;
}


t_game             *generate_bonus_malus(t_game *g)
{
    t_axe          bonus;
    t_axe          malus;

    bonus = generate_rand_pos(g);
    g->map[bonus.x][bonus.y] = 'B';
    malus = generate_rand_pos(g);
    while ((malus.y == bonus.y) && (malus.x == malus.x))
        malus = generate_rand_pos(g);
    g->map[malus.x][malus.y] = 'M';
    return g;
}


t_axe              generate_rand_pos(t_game *g)
{
    t_axe          item;

    item.x = rand_pos(g->size.x);
    item.y = rand_pos(g->size.y);
    return item;
}
