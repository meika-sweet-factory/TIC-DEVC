#include"../Headers/helpers/print.h"
#include"../Headers/helpers/type.h"
#include"../Headers/game.h"

int             main(int argc, char * argv[])
{
    game_t *    game;

    game = 0;
    if (argc == 3 && is_digit(argv[1]) && is_digit(argv[2])) {
        if(!new_game(game, argv[1], argv[2])) return 1;
    } else if (argc == 2 && is_alnum(argv[1])) {
        if(!load_game(game, argv[1])) return 1;
    } else if (argc > 1) {
        print_str("non\n");
        return 1;
    }
    return play_game(game);
}
