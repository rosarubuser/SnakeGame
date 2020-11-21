#pragma once

// Ruochen Wang ruochwang@gmail.com

#include <ncurses.h>
#include <vector>
#include "Snake.h"

class Canvas {
public:
    void getCurrentScreenSize();
    void refreshScreen();

    void init();

    void stop();



private:
    int x;
    int y;
    std::vector<Snake> snakes;
};
