#include"../Headers/helpers/print.h"
#include"../Headers/helpers/type.h"
#include"../Headers/game.h"

int             main(int argc, char * argv[])
{
    game_t *    game;

    game = 0;
    if (argc == 3 && is_digit(argv[1]) && is_digit(argv[2]))
        return new_game(game, argv[1], argv[2], play_game(game)));
    else if (argc == 2 && is_alnum(argv[1]))
        return load_game(game, argv[1], play_game(game)));
    print_str("Please, enter a file or the width and height\n");
    return 1;
}
