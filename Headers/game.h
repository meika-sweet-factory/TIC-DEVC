#ifndef __SNAKE_GAME_H__
#define __SNAKE_GAME_H__

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
    char **         board;
    axe_t           size;
}                   game_t;

/* Usage functions */

int new_game    (game_t * g, char * x, char * y, int (*callback)(game_t * g));
int load_game   (game_t * g, char * d, int (*callback)(game_t * g));
int play_game   (game_t * g);

#endif //__SNAKE_GAME_H__
