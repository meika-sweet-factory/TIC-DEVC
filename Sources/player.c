/*
** player.c for Snake in /home/asuramaru/Projects/snake/Sources
**
**        Made by BAILLIF Killian
**        Login   <bailli_k@etna-alternance.net>
**
** Started on  Tue May  2 15:32:14 2017 BAILLIF Killian
** Last update Tue May  2 15:32:24 2017 BAILLIF Killian
*/

#include "../Headers/player.h"

_Bool                   move(t_player * p, t_axe d)
{
    t_axe               a;
    t_axe               b;
    t_pile_element *    e;

    if (p->body->first->next->data.coordonate.x == d.x &&
        p->body->first->next->data.coordonate.y == d.y) return ERROR;
    p->body->first->data.coordonate.x += d.x;
    p->body->first->data.coordonate.y += d.y;
    a = p->body->first->data.coordonate;
    for (e = p->body->first; e != 0; e = e->next) {
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

void        go_forward(t_player * p)
{
    t_axe   d;

    if (p->direction == LEFT) d.x = -1;
    else if (p->direction == RIGHT) d.x = 1;
    else if (p->direction == TOP) d.y = -1;
    else if (p->direction == BOT) d.y = 1;
    move(p, d);
}

_Bool           add_meat(t_player * p, t_axe d)
{
    t_pile_data meat;

    meat.coordonate = d;
    pile_stack(p->body, meat);
    return SUCCESS;
}
