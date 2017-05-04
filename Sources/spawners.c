#include <stdlib.h>
#include <time.h>
#include "../Headers/spawners.h"
#include "../Headers/player.h"
#include "../Headers/helpers/random.h"

_Bool get_spawn(t_player * p, t_map * m)
{
    t_axe bs;
    t_axe ms;

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
    return SUCCESS;
}

void    rand_bonus(t_player * p)
{
    int b;

    srand((unsigned int) (time(NULL) + (rand() % 100)));
    b = (rand() % 2);
    ++p->score;
    if (b == 0)
    {
        add_player_queue(p, p->body->first->data.coordonate);
    } else {
        p->stat.speed -= 10;
    }
}

_Bool rand_malus(t_player * p)
{
    int b;

    srand((unsigned int) (time(NULL) + (rand() % 100)));
    b = (rand() % 2);
    if (b == 0) {
        return ERROR;
    } else {
        if (p->body->size > 2) remove_player_queue(p);
        else return ERROR;
    }
    return SUCCESS;
}