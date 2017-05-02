/*
** game.c for Snake in /home/asuramaru/Projects/snake/Sources/memory
**
**        Made by PHETSINORATH William
**        Login   <phetsi_w@etna-alternance.net>
**
** Started on  Tue May  2 15:32:14 2017 PHETSINORATH William
** Last update Tue May  2 15:32:24 2017 PHETSINORATH William
*/

#include <stdlib.h>
#include "../../Headers/memory.h"

inline t_game * create_game(void)
{
    return (t_game *) malloc(sizeof(t_game));
}

inline void free_game(t_game * g)
{
    free_map(g);
    free_player(g);
    free(g);
}
