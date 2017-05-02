#include "../Headers/player.h"

_Bool                   move(t_game * g, t_axe d)
{
    t_axe               a;
    t_axe               b;
    t_pile_element *    e;

    if (g->player.body->first->next->data.coordonate.x == d.x &&
        g->player.body->first->next->data.coordonate.y == d.y) return ERROR;
    g->player.body->first->data.coordonate.x += d.x;
    g->player.body->first->data.coordonate.y += d.y;
    a = g->player.body->first->data.coordonate;
    for (e = g->player.body->first; e != 0; e = e->next) {
        if (a.x == 0 && a.y == 0) {
            b = e->data.coordonate;
            e->data.coordonate = a;
            a.x = 0;
            a.y = 0;
        } else {
            a = e->data.coordonate;
            e->data.coordonate = b;
            b.x = 0;
            b.y = 0;
        }
    }
    return SUCCESS;
}

void        go_forward(t_game * g)
{
    t_axe   d;

    if (g->player.direction == LEFT) d.x = -1;
    else if (g->player.direction == RIGHT) d.x = 1;
    else if (g->player.direction == TOP) d.y = -1;
    else if (g->player.direction == BOT) d.y = 1;
    move(g, d);
}

_Bool           add_meat(t_game * g, t_axe d)
{
    t_pile_data meat;

    meat.coordonate = d;
    pile_stack(g->player.body, meat);
    return SUCCESS;
}
