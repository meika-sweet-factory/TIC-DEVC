#include "../../Headers/player.h"
#include "../../Headers/memory.h"

inline _Bool    init_player(t_game *g, t_axe a)
{
    if (g->player) {
        add_player_queue(g->player, a);
        return SUCCESS;
    }
    if (!(g->player = (t_player *) malloc(sizeof(t_player)))) return ERROR;
    if (!(g->player->body = pile_create())) return ERROR;
    return SUCCESS;
}

inline void free_player(t_player *p)
{
    pile_free(p->body);
    free(p);
}
