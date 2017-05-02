/*
** player.c for Snake in /home/asuramaru/Projects/snake/Sources/memory
**
**        Made by PHETSINORATH William
**        Login   <phetsi_w@etna-alternance.net>
**
** Started on  Tue May  2 15:32:14 2017 PHETSINORATH William
** Last update Tue May  2 15:32:24 2017 PHETSINORATH William
*/

#include "../../Headers/chain/pile.h"
#include "../../Headers/memory.h"

inline _Bool    init_player(t_game * g, t_axe s)
{
    t_pile_data p;

    if (!(g->player->body = pile_create())) return ERROR;
    p.coordonate.x = s.x/2;
    p.coordonate.y = s.y/2;
    pile_stack(g->player->body, p);
    --p.coordonate.x;
    pile_stack(g->player->body, p);
    return SUCCESS;
}

inline void free_player(t_game * g)
{
    pile_free(g->player->body);
}
