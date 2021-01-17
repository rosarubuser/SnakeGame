cmake_minimum_required(VERSION 3.17)
project(SnakeGame)

set(CMAKE_C_STANDARD 11)

add_executable(SnakeGame main.c canvas.c canvas.h food.c food.h snake.h snake.c)
target_link_libraries(SnakeGame ncurses)
