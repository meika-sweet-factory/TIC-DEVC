#include <unistd.h>
#include "../../Headers/helpers/print.h"

/* Usable functions */

inline void print_char(char c)
{
    write(1, &c, 1);
}

void                print_str(const char * s)
{
    const char *    bfs;

    bfs = s;
    while (*bfs != '\0') print_char(*bfs), ++bfs;
}

void    print_unint(int n)
{
    int	b;

    if (n < 10) {
        print_char((char) (n + 48));
        return VOID;
    }
    b = 1;
    while (b <= (n / 10)) b *= 10;
    while (b >= 1) {
        print_char((char) (n / b + '0'));
        n %= b;
        b /= 10;
    }
}

void print_int(int n)
{
    if (n == -2147483647) print_str((char *) ("-2147483647"));
    if (n < 0) print_char('-'), n *= -1;
    print_unint((int) n);
}
