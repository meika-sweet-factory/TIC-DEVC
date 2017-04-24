#ifndef SNAKE_MAIN_H
#define SNAKE_MAIN_H

/* Helpers */

typedef struct      snake_s
{
    axe_t           position;
    int             size;
    int             speed;
    int             score;
}                   snake_t;

#endif //SNAKE_MAIN_H
