#include "canvas.h"

/*
 * init and display the interface
 * return: none
 */
void init_disp() {
    char wall = ' ';    // TESTING

    initscr();  // initialize the ncurses
    cbreak();   // receive the input in buffer
    noecho();   // not display the key input on interface
    curs_set(0);    // make terminal cursor invisible

    attrset(A_NORMAL);   // set the display property to normal mode
    attron(A_REVERSE);  // turn on reverse to display

    // to draw the left & right columns
    for (int i = 0; i < LINES; i++) {
        mvaddch(i, LEFT_EDGE, wall);
        mvaddch(i, RIGHT_EDGE, wall);
    }

    //draw the three rows: 0, TOP_ROW(5) & BOT_ROW for the game zone
    // game starts at Line 6
    for (int i = 0; i < COLS; i++) {
        mvaddch(0, i, '-');
        mvaddch(TOP_ROW, i, wall);
        mvaddch(BOT_ROW, i, wall);
    }
    attroff(A_REVERSE);     //turn off reverse effect

    // game description(from Line 1 to Line 4)
    mvaddstr(1, 2, "Game: Snake    Version: 1.0    Date: 2021/01/16");
    mvaddstr(2, 2, "Author: Lily LI    Contact: rosarubuser@gmail.com");
    mvaddstr(3, 2, "Rule: Press 'f' to speed up. 's' to slow down. 'q' to quit");
    mvaddstr(4, 2, "      Use Navigation key to control the movement");

    refresh();  // update the screen
}

void gameover(int n) {
    switch(n) {
        case 0:
            mvaddstr(LINES / 2, COLS / 3 - 4, "WIN! PRESS ANY KEY TO EXIT.");
            break;
        case 1:
            mvaddstr(LINES / 2, COLS / 3 - 4, "CRASH THE WALL! PRESS ANY KEY TO EXIT.");
            break;
        case 2:
            mvaddstr(LINES / 2, COLS / 3 - 4, "EAT YOURSELF! PRESS ANY KEY TO EXIT.");
            break;
    }
    refresh();
    set_timer(0);
    // TODO
}

void wrap_up() {
    set_timer(0);   // turn off the timer
    // getchar();  //??
    snake_clear();
    endwin();   // should always call endwin() before turning off curses & exit the terminal
    exit(0);
}