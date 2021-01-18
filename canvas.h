#ifndef CANVAS_H
#define CANVAS_H

#include <ncurses.h>
#include "snake.h"

#define TOP_ROW 6       // the Line No. that the top row in for the main interface
#define BOT_ROW     LINES - 1   // LINES here is a default screen property of the interface
#define LEFT_EDGE 0     // the left edge location
#define RIGHT_EDGE  COLS - 1    // the right edge location; COLS here is a screen property

void init_disp();   // initialize and display the interface;
void gameover(int n);   // different ways to end the game; n is the mode
void wrap_up(); // do the wrap-up work after ending the game

#endif