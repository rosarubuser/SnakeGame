#include "Canvas.h"
#include <string>
#include <iostream>

static int LEFT_EDGE = 0;
static int RIGHT_EDGE = COLS - 1;
static int TOP_ROW = 5;
static int BOT_ROW = LINES - 1;     // LINES & COLS are default properties of a screen

void Canvas::initDsp() {
    initscr();  // initialize the screen
    cbreak();   // break the line buffering (receive key input one by one)
    noecho();   // shield input ?
    curs_set(0);    // make terminal cursor invisible
    attrset(A_NORMAL);   // turn off all the previous attributes ?

    attron(A_REVERSE);  // turn on reverse ?

    char wall = '1';
    for (int i = 0; i < LINES; i++) {
        mvaddch(i, LEFT_EDGE, wall);
        mvaddch(i, RIGHT_EDGE, wall);
    }

    for (int i = 0; i < COLS; i++) {
        mvaddch(0, i, '0');
        mvaddch(TOP_ROW, i, wall);
        mvaddch(BOT_ROW, i, wall);
    }

    attroff(A_REVERSE);     //turn off reverse?

    std::string tmp1 = std::to_string(RIGHT_EDGE);
    const char* check1 = tmp1.c_str();
    std::string tmp2 = std::to_string(COLS);
    const char* check2 = tmp2.c_str();

    mvaddstr(1, 2, "This is a testing y = 1 x = 2");
    mvaddstr(2, 2, check1);
    mvaddstr(3, 2, check2);
    mvaddstr(4, 2, "This is a testing y = 4 x = 2");
}

