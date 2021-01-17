#include "canvas.h"
#include "food.h"
#include "snake.h"

int main() {
    init_disp();
    food_disp();
    snake_create();
    signal(SIGALRM, snake_move);
    set_timer(DFT_SPEED);
    key_control();
    wrap_up();
    return 0;
};
