#include<sys/stat.h>
#include<stddef.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include"../../Headers/helpers/file.h"

_Bool               read_file(game_t * restrict g, char * restrict d)
{
    int             f;
    short           j;
    unsigned short  i;
    char            bf[4096]; // Optimized systems block sizes

    if ((f = open(d, O_RDONLY))) return ERROR;
    if ((g->board = (char **) malloc(file_size(d)))) return ERROR;
    while (read(f, &bf, 4096) > 0) {
        for (i = 0, j = 0; bf != '\0'; ++j) {
            if (bf[j] == '\n') ++i, j = -1;
            else g->board[i][j] = bf[j];
        }
    }
    return SUCCESS;
}

size_t      file_size(const char * restrict f) {
    struct  stat st;

    if (stat(f, &st) != 0) return ERROR;
    return (size_t) st.st_size;
}
