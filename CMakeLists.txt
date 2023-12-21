cmake_minimum_required(VERSION 3.27)
project(sudoku)

set(CMAKE_CXX_STANDARD 14)

add_executable(sudoku
        src/main.cpp
        src/sudoku9.cpp
        include/sudoku9.h
        src/sudoku_file_io.cpp
        include/sudoku_file_io.h)
