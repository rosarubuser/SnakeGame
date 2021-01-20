#include "snake.h"

int move_x = 1; // snake movement vector
int move_y = 0;
// set two timers to control the speed;
// e.g. cycle_to_move higher->larger time interval to call snake_move -> snake body updated slower
int cycle_to_move = 5, cycle_count_down = 5;

void snake_create() {
    snake_node *temp = (snake_node *)malloc(sizeof(snake_node)); // return a snack node pointer
    head = (snake_node *)malloc(sizeof(snake_node));
    tail = (snake_node *)malloc(sizeof(snake_node));

    if (temp == NULL || head == NULL || tail == NULL)   // avoid getting none pointer
        perror("malloc error");

    // default snake location
    temp->x_pos = 5;
    temp->y_pos = 10;
    head->prev = NULL;
    tail->next = NULL;
    head->next = temp;
    temp->next = tail;
    tail->prev = temp;
    temp->prev = head;
    mvaddch(temp->y_pos, temp->x_pos, SNAKE_SYMBOL);
    refresh();
}

/*
 * set a timer according to the passed-in n_msec(milliseconds)
 * to give signal ITIMER_REAL every 50 msec(adjusted on the default snake speed)
 * return: whether the timer set successfully. return 0 if successful, otherwise -1
 */
int set_timer(int n_msec) {
    struct itimerval new_timeset;
    long n_sec, n_usec;

    n_sec = n_msec / 1000;
    n_usec = n_msec % 1000 * 1000L;  // convert to microsecond; data type long

    // set the time interval
    new_timeset.it_interval.tv_sec = n_sec;
    new_timeset.it_interval.tv_usec = n_usec;

    // start to count down
    new_timeset.it_value.tv_sec = n_sec;
    new_timeset.it_value.tv_usec = n_usec;

    // Parameter: set timer according to real time; pass in the itimerval time set;
    // set ovalue as NULL
    return setitimer(ITIMER_REAL, &new_timeset, NULL);
}

void snake_move() {
    static int length = 1;
    // initialize the length as 1 for only once; retain the same variable for each call
    int length_flag = 0;    // to mark whether to add the snake length
    int moved = 0;
    signal(SIGALRM, SIG_IGN);
    // change the handler snake_move to ignored to avoid duplicated alarm in set_timer

    // judge if the snake crash on the wall
    if ((head->next->x_pos == RIGHT_EDGE - 1 && move_x == 1)
        || (head->next->x_pos == LEFT_EDGE + 1 && move_x == -1)
        || (head->next->y_pos == TOP_ROW + 1 && move_y == -1)
        || (head->next->y_pos == BOT_ROW - 1 && move_y == 1)) {
        gameover(1);
        return;
    }

    // snake crash on itself
    if (mvinch(head->next->y_pos + move_y, head->next->x_pos + move_x) == SNAKE_SYMBOL) {
        gameover(2);
        return;
    }

    // eg. if cycle_count_down = 5, repeat the func. for 4 times to control the speed
    // why not directly change signal time interval? bcs it resembles the TIMES of the interval
    if (cycle_to_move > 0 && cycle_count_down-- == 1) {
        snake_insert_node(head->next->x_pos + move_x, head->next->y_pos + move_y);
        cycle_count_down = cycle_to_move;    // reset cycle_count_down
        moved = 1;
    }

    if(moved) {
        // eat the food
        if (head->next->x_pos == food_pos.x && head->next->y_pos == food_pos.y) {
            length_flag = 1;
            length++;
            if (length >= MAX_NODE) {
                gameover(0);    // win the game
                return;
            }
            else
                food_disp();    // produce new food
        }

        if (length_flag == 0) {
            mvaddch(tail->prev->y_pos, tail->prev->x_pos, ' ');
            snake_delete_node();
        }
        mvaddch(head->next->y_pos, head->next->x_pos, SNAKE_SYMBOL);
        refresh();
    }

    signal(SIGALRM, snake_move);    // reset the handler to snake_move
}

/*
 * control the movement by move_x, move_y & speed of snake by cycle_to_move
 */
void key_control() {
    keypad(stdscr, true);   // enable to the keypad
    int input = getch();
    while (input != 'q') {
        switch (input) {
            case 'f':   // speed up
                if (cycle_to_move == 1)    // 1 is the fastest speed
                    break;
                cycle_to_move--;
                break;
            case 's':   // slow down
                if (cycle_to_move == 8)    // 8 is the lowest speed
                    break;
                cycle_to_move++;
                break;
            case KEY_LEFT:  // of int type
                // if the snake nodes are more than 1, it cannot turn around
                if (tail->prev->prev->prev != NULL && move_x == 1 && move_y == 0)
                    break;
                move_x = -1;
                move_y = 0;
                break;
            case KEY_RIGHT:
                if (tail->prev->prev->prev != NULL && move_x == -1 && move_y == 0)
                    break;
                move_x = 1;
                move_y = 0;
                break;
            case KEY_UP:
                if (tail->prev->prev->prev != NULL && move_x == 0 && move_y == 1)
                    break;
                move_x = 0;
                move_y = -1;
                break;
            case KEY_DOWN:
                if (tail->prev->prev->prev != NULL && move_x == 0 && move_y == -1)
                    break;
                move_x = 0;
                move_y = 1;
                break;
        }
        input = getch();
    }
}

/*
 * insert the node at the front
 */
void snake_insert_node(int x, int y) {
    typedef struct snake_node snake_node;
    snake_node *temp = (snake_node *)malloc(sizeof(snake_node));
    if (temp == NULL)
        perror("malloc error");
    temp->x_pos = x;
    temp->y_pos = y;
    temp->prev = head;
    head->next->prev = temp;
    temp->next = head->next;
    head->next = temp;
}

/*
 * delete the node at the end and reconstruct the snake nodes
 */
void snake_delete_node() {
    snake_node *temp;
    temp = tail->prev;
    tail->prev = tail->prev->prev;
    temp->prev->next = tail;
    free(temp);
}

/*
 * delete the whole snake nodes
 */
void snake_clear() {
    while (head->next != tail)
        snake_delete_node();
    // TODO: why not delete the pointer directly???
    // head->next = NULL;
    // tail->prev = NULL;
    free(head);
    free(tail);
}