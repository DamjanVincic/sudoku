cmake_minimum_required(VERSION 3.27)
project(sudoku)

set(CMAKE_CXX_STANDARD 14)

add_executable(sudoku
        src/main.cpp
        src/sudoku9.cpp
        include/sudoku9.h
        src/sudoku_file_io.cpp
        include/sudoku_file_io.h
        src/board.cpp
        include/board.h)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(sudoku_test
        tests/sudoku_test.cpp
        tests/board_test.cpp
        tests/sudoku_file_io_test.cpp
        src/sudoku9.cpp
        src/board.cpp
        src/sudoku_file_io.cpp)

target_link_libraries(sudoku_test gtest_main)

include(GoogleTest)
gtest_discover_tests(sudoku_test)