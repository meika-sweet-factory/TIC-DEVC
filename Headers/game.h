#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

/* Helpers */

enum bonus
{
    GROW,
    FASTER,
};

enum mallus
{
    DIVIDE,
    DEATH
};

typedef struct  axe_s
{
    int         x;
    int         y;
}               axe_t;

typedef struct      game_s
{
    axe_t           size;
}                   game_t;

/* Usage functions */

int new_game    (game_t * g, char * x, char * y);
int load_game   (game_t * g, char * s);
int play_game   (game_t * g);

#endif //SNAKE_GAME_H
