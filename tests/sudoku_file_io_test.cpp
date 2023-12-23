/**
 * @file sudoku_file_io_test.cpp
 * @brief Unit tests for the SudokuFileIO class
 * @date December 23, 2023
 * @author Damjan Vincic
 */

#include <gtest/gtest.h>
#include <fstream>
#include "../include/sudoku_file_io.h"

class SudokuFileIOTest : public ::testing::Test {
protected:
    SudokuFileIO sudokuFileIO;
    void SetUp() override {
        sudokuFileIO = SudokuFileIO();
    }
};

TEST_F(SudokuFileIOTest, InvalidFileTest) {
    ASSERT_THROW(sudokuFileIO.read("invalid_file.txt"), std::runtime_error);
}

TEST_F(SudokuFileIOTest, ReadWriteTest) {
    std::vector<std::vector<unsigned short>> testBoard = {
            {5, 3, 0, 0, 7, 0, 0, 0, 0},
            {6, 0, 0, 1, 9, 5, 0, 0, 0},
            {0, 9, 8, 0, 0, 0, 0, 6, 0},
            {8, 0, 0, 0, 6, 0, 0, 0, 3},
            {4, 0, 0, 8, 0, 3, 0, 0, 1},
            {7, 0, 0, 0, 2, 0, 0, 0, 6},
            {0, 6, 0, 0, 0, 0, 2, 8, 0},
            {0, 0, 0, 4, 1, 9, 0, 0, 5},
            {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    Sudoku9 sudoku(testBoard);

    std::ofstream file("test.txt");
    if (file.is_open()) {
        sudokuFileIO.write("test.txt", sudoku);
        file.close();
    }

    std::ifstream file2("test.txt");
    if (file2.is_open()) {
        std::vector<std::vector<unsigned short>> board = sudokuFileIO.read("test.txt");
        file2.close();
        ASSERT_EQ(board, testBoard);
    }
    std::remove("test.txt");
}
