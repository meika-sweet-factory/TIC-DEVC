#include "../Headers/player.h"

#include "../Headers/helpers/print.h"

_Bool                   move(t_player * p, t_axe d, t_game * g)
{
    t_axe               a;
    t_axe               b;
    t_pile_element *    e;
    int                 i;

    i = 0;
    if (p->body->first->next->data.coordonate.x == d.x &&
        p->body->first->next->data.coordonate.y == d.y) return ERROR;
    if (g->map->board[d.y/10][d.x/10] == WALL) return ERROR;
    a = p->body->first->data.coordonate;
    p->body->first->data.coordonate.x = d.x;
    p->body->first->data.coordonate.y = d.y;
    for (e = p->body->first->next; e != 0; e = e->next) {
        b = e->data.coordonate;
        e->data.coordonate = a;
        a = b;
        i++;
    }
    return SUCCESS;
}

inline _Bool move_forward(t_player *p, t_game * g)
{
    t_axe   d;

    d = p->body->first->data.coordonate;
    if (p->direction == LEFT) d.x -= 10;
    else if (p->direction == RIGHT) d.x += 10;
    else if (p->direction == TOP) d.y -= 10;
    else if (p->direction == BOT) d.y += 10;
    if (!move(p, d, g)) return ERROR;
    return SUCCESS;
}

inline void     add_player_queue(t_player *p, t_axe a)
{
    t_pile_data e;

    e.coordonate = a;
    pile_stack(p->body, e);
}
