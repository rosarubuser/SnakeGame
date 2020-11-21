
#include "Canvas.h"

void Canvas::getCurrentScreenSize() { 
    getmaxyx(stdscr, y, x);
}

void Canvas::refreshScreen() {
    getCurrentScreenSize();
}
