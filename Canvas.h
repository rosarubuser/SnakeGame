#pragma once
#include <ncurses.h>

class Canvas {
public:
    static void initDsp();

private:
    // TODO: not sure weather to declare extern variables?
    // TODO: not sure to use static or extern
    static int TOP_ROW;
    static int BOT_ROW;
    static int LEFT_EDGE;
    static int RIGHT_EDGE;
};
