#pragma once    // include this file for once

#define SNAKE_SYMBOL '@'    // snake body symbol
#define FOOD_SYMBOL '*'     // food symbol
#define  MAX_NODE 30    // maximum no. of snake body nodes
#define DFT_SPEED 50    // default snake speed


/*
 * location of the snake head
 */
struct snake_node {
    int x_pos;  // head of the snake_node
    int y_pos;
    struct snake_node *prev;
    struct snake_node *next;
};

/*
 * location of the food
 */
struct position {
    int x_pos;
    int y_pos;
};

void warp_up();     // turn of the ncurses? TODO
void key_control();     // using the keyboard to control the snake; TODO
int set_ticker(int n_msecs);   // TODO ??

void snake_create();    // use doubly linked list to create a snake
void snake_insert_node();   // lengthen the snake body
void snake_delete_node();   // delete the snake body node?
void snake_clear();   // delete all the snake nodes

void snake_move_control();  // control the snake movement
void snake_die(int n);      // different ways to die; n is the die mode
