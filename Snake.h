#pragma once

class Snake {
public: 
    void dead();

    void move(int direction); // direction: 0-up, 1-down, 2-right, 3-left

    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();




private:
        int length;
};
