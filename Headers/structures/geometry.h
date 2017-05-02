#ifndef _SNAKE_STUCTURE_GEOMETRY_H_
#define _SNAKE_STUCTURE_GEOMETRY_H_

typedef union   s_number
{
    int         snint;
    unsigned    unint;
    short       snshort;
    unsigned    unshort;
}               u_number;

typedef struct      s_axe
{
    unsigned short  x;
    unsigned short  y;
}                   t_axe;

#endif //_SNAKE_STUCTURE_GEOMETRY_H_
