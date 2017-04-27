#ifndef _SNAKE_FILE_H_
#define _SNAKE_FILE_H_

/* Helpers */

#include "structures/type.h"
#include "structures/game.h"

/* Usage functions */

_Bool load_file(game_t * g, const char * f, _Bool (* callback)(game_t * g));

#endif //_SNAKE_FILE_H_
