#ifndef __SNAKE_FILE_H__
#define __SNAKE_FILE_H__

/* Helpers */

#include"../structures/type.h"
#include"../structures/game.h"

/* Usage functions */

int     read_file   (game_t * g, char * d);
size_t  file_size   (const char * d);

#endif //__SNAKE_FILE_H__
