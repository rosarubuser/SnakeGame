cmake_minimum_required(VERSION 3.17)
project(SnakeGame)

set(CMAKE_CXX_STANDARD 17)

add_executable(SnakeGame main.c Display.c Display.h)
target_link_libraries(SnakeGame ncurses)
