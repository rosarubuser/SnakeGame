#include "Display.h"
#include <ncurses.h>

/*
 * init and display the interface
 * return: none
 */
void init_disp() {
    char wall = 's';    // TESTING

    initscr();  // initialize the ncurses
    cbreak();   // receive the input in buffer
    noecho();   // not display the key input on interface
    curs_set(0);    // make terminal cursor invisible

    attrset(A_NORMAL);   // set the display property to normal mode
    attron(A_REVERSE);  // turn on reverse to display

    // to draw the left & right columns
    for (int i = 0; i < LINES; i++) {
        mvaddch(i, LEFT_EDGE, wall);
        mvaddch(i, RIGHT_EDGE, wall);
    }

    //draw the three rows: 0, TOP_ROW(5) & BOT_ROW for the game zone
    // game starts at Line 6
    for (int i = 0; i < COLS; i++) {
        mvaddch(0, i, '0');
        mvaddch(TOP_ROW, i, wall);
        mvaddch(BOT_ROW, i, wall);
    }
    attroff(A_REVERSE);     //turn off reverse effect

    // game description(from Line 1 to Line 4)
    mvaddstr(1, 2, "Game: Snake    Version: 1.0    Date: 2021/01/16");
    mvaddstr(2, 2, "Author: Lily LI    Contact: rosarubuser@gmail.com");
    mvaddstr(3, 2, "Rule: Press 'f' to speed up. 's' to slow down. 'q' to quit");
    mvaddstr(4, 2, "      Use Navigation key to control the movement");

    refresh();  // update the screen
}

