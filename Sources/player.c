#include "../Headers/player.h"

#include "../Headers/helpers/print.h"

_Bool                   move(t_player * p, t_axe d)
{
    t_axe               a;
    t_axe               b;
    t_pile_element *    e;
    int                 i;

    i = 0;
    if (p->body->first->next->data.coordonate.x == d.x &&
        p->body->first->next->data.coordonate.y == d.y) return ERROR;
    a = p->body->first->data.coordonate;
    p->body->first->data.coordonate.x = d.x;
    p->body->first->data.coordonate.y = d.y;
    for (e = p->body->first->next; e != 0; e = e->next) {
        b = e->data.coordonate;
        e->data.coordonate = a;
        a = b;
        print_int(i);
        i++;
    }
    return SUCCESS;
}

inline void move_forward(t_player *p)
{
    t_axe   d;

    d = p->body->first->data.coordonate;
    if (p->direction == LEFT) d.x -= 10;
    else if (p->direction == RIGHT) d.x += 10;
    else if (p->direction == TOP) d.y -= 10;
    else if (p->direction == BOT) d.y += 10;
    move(p, d);
}

inline void     add_player_queue(t_player *p, t_axe a)
{
    t_pile_data e;

    e.coordonate = a;
    pile_stack(p->body, e);
}
