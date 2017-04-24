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

typedef struct      game_s
{
    axe_t           size;
}                   game_t;

/* Usage functions */

game_t *    new_game    (int x, int y);
game_t *    load_game   (char * s);
void        play_game   (game_t * g);

#endif //SNAKE_GAME_H
