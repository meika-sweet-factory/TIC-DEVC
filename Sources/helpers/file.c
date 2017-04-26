#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "../../Headers/helpers/file.h"

_Bool file_size(game_t * g, const char * f);

_Bool               read_file(game_t * g, const char * f)
{
    int             of;
    unsigned short  j;
    unsigned short  i;
    unsigned short  k;
    char            bf[4096];

    if (!(file_size(g, f))) return ERROR;
    if ((of = open(f, O_RDONLY)) == -1) return ERROR;
    j = 0;
    if (!(g->board = (char **) malloc((long unsigned int) g->size.y * sizeof(char **)))) return ERROR;
    g->board[0] = (char *) malloc((long unsigned int) g->size.x * sizeof(char *));
    while (read(of, &bf, 4096) > 0) {
        for (i = 0, k = 0; bf[k] != '\0'; ++j, ++k) {
            if (bf[k] == '\n') {
                ++i;
                g->board[i] = (char *) malloc((long unsigned int) g->size.x * sizeof(char *));
                j = 0;
            } else g->board[i][j] = bf[k];
        }
    }
    close(of);
    return SUCCESS;
}

inline _Bool        file_size(game_t * g, const char * f)
{
    int             of;
    unsigned short  j;
    unsigned short  i;
    unsigned short  k;
    unsigned short  tmp;
    char            bf[4096];

    if ((of = open(f, O_RDONLY)) == -1) return ERROR;
    j = 0;
    tmp = 0;
    while (read(of, &bf, 4096) > 0) {
        for (i = 0, k = 0; bf[k] != '\0'; ++j, ++k) {
            if (bf[k] == '\n') {
                ++i;
                if (j > tmp) tmp = j;
                j = 0;
            }
            if (tmp > 100 || i > 100) return ERROR;
        }
    }
    g->size.x = tmp;
    g->size.y = i;
    close(of);
    return SUCCESS;
}