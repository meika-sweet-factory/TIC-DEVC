#include <stdlib.h>
#include <time.h>
#include "../Headers/helpers/random.h"
#include "../Headers/player.h"
#include "../Headers/spawners.h"

/* Internal functions prototype */

_Bool   check_elements(t_map *m,t_player *p, t_axe d);

/* Usable function */

_Bool               move(t_map *m, t_player *p, t_axe d)
{
    int             i;
    t_axe           a;
    t_axe           b;
    t_pile_element  *e;

    i = 0;
    if (p->body->first->next->data.coordonate.x == d.x &&
        p->body->first->next->data.coordonate.y == d.y) return ERROR;
    if (!check_elements(m, p, d)) return ERROR;
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

inline _Bool    move_forward(t_map *m, t_player *p)
{
    t_axe       d;

    d = p->body->first->data.coordonate;
    if (p->direction == LEFT) d.x -= 10;
    else if (p->direction == RIGHT) d.x += 10;
    else if (p->direction == TOP) d.y -= 10;
    else if (p->direction == BOT) d.y += 10;
    if (!move(m, p, d)) return ERROR;
    return SUCCESS;
}

inline void     add_player_queue(t_player *p, t_axe a)
{
    t_pile_data e;

    e.coordonate = a;
    pile_stack(p->body, e);
}

inline void     remove_player_queue(t_player *p)
{
    pile_unstack(p->body);
}

/* Internal functions */

_Bool               check_elements(t_map * m, t_player * p, t_axe d)
{
    t_pile_element  *e;

    if (m->board[d.y / 10][d.x / 10] == WALL) return ERROR;
    if (p->body->first->data.coordonate.x == m->size.x * 10 ||
            p->body->first->data.coordonate.y == m->size.y * 10 ||
            p->body->first->data.coordonate.x == 0 ||
            p->body->first->data.coordonate.y == 0) return ERROR;
    if (!get_spawn(m, p)) return ERROR;
    for (e = p->body->first->next->next; e != 0; e = e->next) {
        if (p->body->first->data.coordonate.x == e->data.coordonate.x &&
                p->body->first->data.coordonate.y == e->data.coordonate.y)
            return ERROR;
    }
    return SUCCESS;
}
