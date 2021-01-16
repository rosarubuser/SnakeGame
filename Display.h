#pragma once

#define TOP_ROW 5       // the line no. that the top row in for the game zone
#define BOT_ROW     LINES - 1   // LINES here is a screen property for the game zone
#define LEFT_EDGE 0     // the left edge location
#define RIGHT_EDGE  COLS - 1    // the right edge location; COLS here is a screen property

void init_disp();   // initialize and Display the interface;
