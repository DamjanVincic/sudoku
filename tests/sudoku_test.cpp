/**
 * @file sudoku_test.cpp
 * @brief Unit tests for the Sudoku9 class
 * @date December 27, 2023
 * @author Damjan Vincic
 */

#include <gtest/gtest.h>
#include "../include/sudoku9.h"

/**
 * @class SudokuTest
 * @brief Unit tests for Sudoku9 class
 */
class SudokuTest : public ::testing::Test {
protected:
    /**
     * @brief 2D vector representing the sudoku board
     */
    std::vector<std::vector<unsigned short>> testBoard;

    /**
     * @brief Sudoku9 object representing the sudoku board
     */
    Sudoku9 sudoku;
    void SetUp() override {
        testBoard = {
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
        sudoku = Sudoku9(testBoard);
    }
};

/**
 * @brief Test for the empty constructor
 */
TEST_F(SudokuTest, EmptyConstructorTest) {
    Sudoku9 sudoku;
    ASSERT_EQ(sudoku.getBoard().getBoard(), sudoku.getOriginalBoard().getBoard());
}

/**
 * @brief Test for the constructor with parameters
 */
TEST_F(SudokuTest, ConstructorTest) {
    ASSERT_EQ(sudoku.getBoard().getBoard(), testBoard);
}

/**
 * @brief Tests if the sudoku solving works correctly
 */
TEST_F(SudokuTest, SolveSudokuTest) {
    std::vector<std::vector<unsigned short>> unsolvableBoard = {
            {5, 3, 0, 0, 7, 0, 0, 0, 0},
            {6, 0, 0, 1, 9, 5, 0, 0, 0},
            {0, 9, 8, 0, 0, 0, 0, 6, 0},
            {8, 0, 0, 0, 6, 0, 0, 0, 3},
            {4, 0, 0, 8, 0, 3, 0, 0, 1},
            {7, 0, 0, 0, 2, 0, 0, 0, 6},
            {0, 6, 0, 0, 0, 0, 2, 8, 0},
            {0, 0, 0, 4, 1, 5, 0, 0, 5},
            {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    ASSERT_TRUE(sudoku.solveSudoku());
    ASSERT_FALSE(Sudoku9(unsolvableBoard).solveSudoku());
}

/**
 * @brief Tests if the board generation works correctly
 */
TEST_F(SudokuTest, GenerateSudokuTest) {
    Sudoku9 sudoku;
    sudoku.generateSudoku();
    ASSERT_TRUE(sudoku.solveSudoku());
}

/**
 * @brief Tests if the solution checking works correctly
 */
TEST_F(SudokuTest, CheckSolutionTest) {
    std::vector<std::vector<unsigned short>> solvedBoard = {
            {5, 3, 4, 6, 7, 8, 9, 1, 2},
            {6, 7, 2, 1, 9, 5, 3, 4, 8},
            {1, 9, 8, 3, 4, 2, 5, 6, 7},
            {8, 5, 9, 7, 6, 1, 4, 2, 3},
            {4, 2, 6, 8, 5, 3, 7, 9, 4},
            {7, 1, 3, 9, 2, 4, 8, 5, 6},
            {9, 6, 1, 5, 3, 7, 2, 8, 4},
            {2, 8, 7, 4, 1, 9, 6, 3, 5},
            {3, 4, 5, 2, 8, 6, 1, 7, 9}
    };
    sudoku.setSolution(solvedBoard);
    sudoku.checkSolution();
    ASSERT_EQ(sudoku.getNumberOfInvalidCells(), 2);

    sudoku.solveSudoku();
    ASSERT_EQ(sudoku.getNumberOfValidCells(), 49);
}