#ifndef FOOD_H
#define FOOD_H

#include <stdlib.h>
#include <sys/time.h>
#include <ncurses.h>
#include "canvas.h"

#define FOOD_SYMBOL '*'     // food symbol

/*
 * location of the food
 */
struct food_pos {
    int x;
    int y;
} food_pos;

/*
 * display the food
 */
void food_disp();   // display the food; TODO

#endif
