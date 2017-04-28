#include "../../Headers/chain/pile.h"
#include "../../Headers/memory.h"

inline _Bool init_player(t_game * g)
{
    t_axe       middle;
    t_pile_data pos;

    if (!(g->player.body = pile_create())) return ERROR;
    middle.x = g->map.size.x/2;
    middle.y = g->map.size.y/2;
    pos.coordonate = middle;
    pile_stack(g->player.body, pos);
    middle.x = (short unsigned)((g->map.size.x/2) - 1);
    pos.coordonate = middle;
    pile_stack(g->player.body, pos);
    return SUCCESS;
}

inline void free_player(t_game * g)
{
    pile_free(g->player.body);
}
