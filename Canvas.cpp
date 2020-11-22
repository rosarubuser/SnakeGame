#include "Canvas.h"

int Canvas::TOP_ROW = 5;
int Canvas::BOT_ROW = LINES - 1;    // TODO: where is LINES
int Canvas::LEFT_EDGE = 0;
int Canvas::RIGHT_EDGE = COLS - 1;  // TODO: where is COLS

void Canvas::initDsp() {
    initscr();  // initialize the screen?
    cbreak();   // break the line buffering
    noecho();   // shield input
    curs_set(0);    // make cursor invisible
    attrset(A_NORMAL);   // turn off all the previous attributes?

    attron(A_REVERSE);  // ?

    char wall = 'c';
    for (int i = 0; i < LINES; i++) {
        mvaddch(i, LEFT_EDGE, wall);
        mvaddch(i, RIGHT_EDGE, wall);
    }

    for (int i = 0; i < COLS; i++) {
        mvaddch(0, i, 'x');
        mvaddch(TOP_ROW, i, wall);
        mvaddch(BOT_ROW, i, wall);
    }

    attroff(A_REVERSE);     //?

    mvaddstr(1, 2, "This is a testing y = 1 x = 2");
    mvaddstr(2, 2, "This is a testing y = 2 x = 2");
    mvaddstr(3, 2, "This is a testing y = 3 x = 2");
    mvaddstr(4, 2, "This is a testing y = 4 x = 2");

    refresh();
}

