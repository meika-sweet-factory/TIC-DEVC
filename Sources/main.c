/*
** main.c for Snake in /home/asuramaru/Projects/snake/Sources
**
**        Made by PHETSINORATH William
**        Login   <phetsi_w@etna-alternance.net>
**
** Started on  Tue May  2 15:32:14 2017 PHETSINORATH William
** Last update Tue May  2 15:32:24 2017 PHETSINORATH William
*/

#include "../Headers/helpers/print.h"
#include "../Headers/helpers/type.h"
#include "../Headers/game.h"

int             main(int argc, char * argv[])
{
    t_game *    game;

    game = 0;
    if (argc == 3 && is_digit(argv[1]) && is_digit(argv[2]))
        return new_game(game, argv[1], argv[2], play_game);
    else if (argc == 2)
        return load_game(game, argv[1], play_game);
    print_str("Please, enter a file or width and height of the map.\n");
    return EXIT_FAILURE;
}
