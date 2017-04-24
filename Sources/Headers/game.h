#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

/* Helpers */

typedef struct  axe_s
{
  int           x;
  int           y;
}               axe_t

typedef struct      game_s
{
    axe_t           size;
}                   game_t;

/* Usage functions */

game_t new_game(void);

#endif //SNAKE_GAME_H
