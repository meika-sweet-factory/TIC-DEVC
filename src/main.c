#include"Headers/common.h"
#include"Headers/input.h"
#include"Headers/main.h"

int         main(int argc, char * argv[])
{
    game_t  game;

    if (argc == 3 && is_digit(argv[1]) && is_digit(argv[2])) {
        game = new_game(argv[1], arg[2]);
    } else if (argc == 2 && is_alnum(arg[1])) {
        game = load_game(argv[1]);
    } else if (argc > 1) {
        print_str("non");
        return 0;
    }
    play_game(game);
    return 1;
}
