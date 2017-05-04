#include <time.h>
#include <stdlib.h>
#include "../Headers/player.h"
#include "../Headers/helpers/random.h"

#include "../Headers/helpers/print.h"

_Bool check_elements(t_map * m,t_player* p, t_axe d);
void    rand_bonus(t_player * p);
void     remove_player_queue(t_player *p);
_Bool rand_malus(t_player * p);

_Bool                   move(t_player * p, t_axe d, t_game * g)
{
    t_axe               a;
    t_axe               b;
    t_pile_element *    e;
    int                 i;

    i = 0;
    if (p->body->first->next->data.coordonate.x == d.x &&
        p->body->first->next->data.coordonate.y == d.y) return ERROR;
    if (!check_elements(g->map,g->player,d)) return ERROR;
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

inline void     remove_player_queue(t_player *p)
{
    pile_unstack(p->body);
}

_Bool check_elements(t_map * m, t_player * p, t_axe d)
{
    t_axe   bs;
    t_axe   ms;
    t_pile_element *    e;

    if (m->board[d.y/10][d.x/10] == WALL) return ERROR;
    if (p->body->first->data.coordonate.x == m->size.x*10 ||
            p->body->first->data.coordonate.y == m->size.y*10 ||
            p->body->first->data.coordonate.x == 0 ||
            p->body->first->data.coordonate.y == 0) return ERROR;
    if (p->body->first->data.coordonate.x == m->spawns.bonus.x &&
            p->body->first->data.coordonate.y == m->spawns.bonus.y) {
        bs = generate_rand_pos(m, 0);
        m->spawns.bonus.x = bs.x * 10;
        m->spawns.bonus.y = bs.y * 10;
        rand_bonus(p);
    }
    if (p->body->first->data.coordonate.x == m->spawns.malus.x &&
            p->body->first->data.coordonate.y == m->spawns.malus.y) {
        ms = generate_rand_pos(m, 0);
        m->spawns.malus.x = ms.x * 10;
        m->spawns.malus.y = ms.y * 10;
        if (!rand_malus(p)) return ERROR;
    }
    for (e = p->body->first->next->next; e != 0; e = e->next) {
        if (p->body->first->data.coordonate.x == e->data.coordonate.x &&
                p->body->first->data.coordonate.y == e->data.coordonate.y)
            return ERROR;
    }
    return SUCCESS;
}

void    rand_bonus(t_player * p)
{
    int b;

    srand((unsigned int) (time(NULL) + (rand() % 100)));
    b = (rand() % 2);
    ++p->score;
    print_int(p->score);
    if (b == 0)
    {
        add_player_queue(p, p->body->first->data.coordonate);
    } else {
        p->stat.speed -= 50;
    }
}

_Bool rand_malus(t_player * p)
{
    int b;

    srand((unsigned int) (time(NULL) + (rand() % 100)));
    b = (rand() % 2);
    if (b == 0)
    {
        return ERROR;
    } else {
        remove_player_queue(p);
    }
    return SUCCESS;
}