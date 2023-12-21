/**
 * @file sudoku9.h
 * @brief Declaration of the Sudoku9 class
 * @date December 21, 2023
 * @author Damjan Vincic
 */

#ifndef SUDOKU_SUDOKU9_H
#define SUDOKU_SUDOKU9_H
#include <vector>

/**
 * @class Sudoku9
 * @brief Class for sudoku representation and related methods
 */
class Sudoku9 {
private:
    /**
     * @brief 2D vector representing the sudoku board
     */
    std::vector<std::vector<unsigned short>> board;

    /**
     * @brief Fill the diagonal subgrids of the sudoku board
     */
    void fillDiagonalSubgrids();
public:
    /**
     * @brief Empty constructor for the Sudoku9 class
     */
    Sudoku9();

    /**
     * @brief Constructor for the Sudoku9 class
     * @param board 2D vector representing the sudoku board
     */
    Sudoku9(const std::vector<std::vector<unsigned short>>& board);

    /**
     * @brief Copy constructor for the Sudoku9 class
     * @param other Sudoku9 object to be copied
     */
    Sudoku9& operator=(const Sudoku9& other);

    /**
     * @brief Checks if a number can be placed in a given cell
     * @param row Row of the cell
     * @param col Column of the cell
     * @param num Number to be placed
     * @return True if the number can be placed, false otherwise
     */
    bool isSafe(int row, int col, unsigned short num);

    /**
     * @brief Solves the sudoku board
     * @return True if the sudoku is solved, false otherwise
     */
    bool solveSudoku();

    /**
     * @brief Generates a sudoku board
     */
    void generateSudoku();

    /**
     * @brief Prints the sudoku board
     */
    void printBoard();

    /**
     * @brief Checks if the sudoku board is valid
     * @return True if the sudoku board is valid, false otherwise
    */
    bool checkSolutionValidity();

    std::vector<unsigned short> operator[](int i);
    const std::vector<unsigned short> operator[](int i) const;
};
#endif //SUDOKU_SUDOKU9_H
