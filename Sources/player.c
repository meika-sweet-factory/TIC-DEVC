#include "../Headers/player.h"

_Bool   move(t_player * p, t_axe d)
{
    if (p->body->first->precedent->data.coordonate.x == d.x &&
        p->body->first->precedent->data.coordonate.y == d.y) return ERROR;
    move(p, d);
    return SUCCESS;
}

_Bool           add_meat(t_player * p, t_axe d)
{
    t_pile_data meat;

    meat.coordonate = d;
    pile_stack(p->body, meat);
    return SUCCESS;
}