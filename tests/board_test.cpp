/*
 * @file board_test.cpp
 * @brief Unit tests for the Board class
 * @date December 22, 2023
 * @author Damjan Vincic
 */

#include <gtest/gtest.h>
#include "../include/board.h"
#include <vector>

class BoardTest : public ::testing::Test {
protected:
    std::vector<std::vector<unsigned short>> testBoard;
    Board board;
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
        board = Board(testBoard);
    }
};

TEST_F(BoardTest, EmptyConstructorTest) {
    Board board;
    ASSERT_EQ(board.getBoard(), std::vector<std::vector<unsigned short>>(9, std::vector<unsigned short>(9, 0)));
}

TEST_F(BoardTest, ConstructorTest) {
    Board board(testBoard);
    ASSERT_EQ(board.getBoard(), testBoard);
}

TEST_F(BoardTest, CopyConstructorTest) {
    Board boardCopy(board);
    ASSERT_EQ(boardCopy.getBoard(), board.getBoard());
}

TEST_F(BoardTest, IsSafeTest) {
    ASSERT_TRUE(board.isSafe(0, 2, 4));
    ASSERT_TRUE(board.isSafe(0, 2, 1));
    ASSERT_TRUE(board.isSafe(0, 2, 2));
    ASSERT_FALSE(board.isSafe(0, 2, 3));
    ASSERT_FALSE(board.isSafe(0, 2, 5));
    ASSERT_FALSE(board.isSafe(0, 2, 6));
    ASSERT_FALSE(board.isSafe(0, 2, 7));
    ASSERT_FALSE(board.isSafe(0, 2, 8));
    ASSERT_FALSE(board.isSafe(0, 2, 9));
}

TEST_F(BoardTest, FillDiagonalSubgridsTest) {
    Board board;
    board.fillDiagonalSubgrids();
    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; ++j) {
            ASSERT_NE(board[i + j/3][i + j%3], 0);
        }
    }
}
