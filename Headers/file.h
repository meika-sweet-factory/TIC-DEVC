#ifndef _SNAKE_FILE_H_
#define _SNAKE_FILE_H_

/* Helpers */

#include "structures/type.h"
#include "structures/game.h"

/* Usage functions */

_Bool load_file(t_game * g, const char * f, _Bool (* callback)(t_game * g));

#endif //_SNAKE_FILE_H_
