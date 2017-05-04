#include "../../Headers/helpers/print.h"
#include "../../Headers/memory.h"
#include "../../Headers/player.h"

/* Usable functions */

inline _Bool init_player(t_game * g, t_axe a)
{
    a.x *= 10;
    a.y *= 10;
    if (g->player) add_player_queue(g->player, a);
    else {
        if (!(g->player = (t_player *) malloc(sizeof(t_player)))) return ERROR;
        if (!(g->player->body = pile_create())) return ERROR;
        g->player->direction = RIGHT;
        g->player->score = 0;
        g->player->stat.size = 0;
        g->player->stat.speed = 0;
        add_player_queue(g->player, a);
    }
    return SUCCESS;
}

inline void free_player(t_player * p)
{
    pile_free(p->body);
    free(p);
}
