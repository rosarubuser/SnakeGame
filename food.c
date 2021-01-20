#include "food.h"

void food_disp(){
    srand(time(0)); // produce a seed
    food_pos.x = rand() % (COLS - 2) + 1;
    food_pos.y = rand() % (LINES - TOP_ROW - 2) + TOP_ROW + 1;
    mvaddch(food_pos.y, food_pos.x, FOOD_SYMBOL);
    refresh();
}
