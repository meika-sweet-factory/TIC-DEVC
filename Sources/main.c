#include "../Headers/helpers/print.h"
#include "../Headers/helpers/type.h"
#include "../Headers/game.h"

int main(int ac, char *av[])
{
    if (ac == 3 && is_digit(av[1]) && is_digit(av[2])) {
        return new_game(av[1], av[2], play_game);
    } else if (ac == 2) {
        return load_game(av[1], play_game);
    }
    print_str("Please, enter a file or width and height of the map.\n");
    return EXIT_FAILURE;
}
