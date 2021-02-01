#ifndef SNAKE_H
#define SNAKE_H

#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include <sys/time.h>
#include "canvas.h"
#include "food.h"

#define SNAKE_SYMBOL '@'    // snake body symbol
#define  MAX_NODE 25    // maximum no. of snake body nodes
#define DFT_SPEED 50    // to control the default snake speed

/*
 * location of the snake head
 * typedef to avoid duplicated declaration of 'struct'
 */
typedef struct snake_node {
    int x_pos;  // head of the snake_node
    int y_pos;
    struct snake_node *prev;
    struct snake_node *next;
} snake_node;

struct snake_node *head, *tail; // sets two dummy nodes for DLL snake structure

void snake_create();    // use doubly linked list to create a snake

void snake_move();  // control the snake movement
int set_timer(int n_msecs);   // set the timer to run the snake_move function
void key_control();     // using the keyboard to control the game;

void snake_insert_node(int x, int y);   // lengthen the snake body
void snake_delete_node();   // delete single snake node
void snake_clear();   // delete all the snake nodes

#endif