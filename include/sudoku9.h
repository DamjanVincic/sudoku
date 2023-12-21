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
    /**
     * @brief 2D vector representing the sudoku board
     */
    std::vector<std::vector<unsigned short>> board;

    /**
     * @brief Number of valid cells in the sudoku board
    */
    int numberOfValidCells = 0;

    /**
     * @brief Number of invalid cells in the sudoku board
    */
    int numberOfInvalidCells = 0;

    /**
     * @brief Number of games played
    */
    static int numberOfGames;

    /**
     * @brief Fill the diagonal subgrids of the sudoku board
     */
    void fillDiagonalSubgrids();

    /**
     * @brief Checks if a number can be placed in a given cell
     * @param row Row of the cell
     * @param col Column of the cell
     * @param num Number to be placed
     * @return True if the number can be placed, false otherwise
     */
    bool isSafe(int row, int col, unsigned short num);
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
     * @brief Checks if the sudoku board is solved, and updates the corresponding attributes.
    */
    void checkSolution();

    /**
     * @brief Returns the number of valid cells
     * @return Number of valid cells
    */
    int getNumberOfValidCells() const;

    /**
     * @brief Returns the number of invalid cells
     * @return Number of invalid cells
    */
    int getNumberOfInvalidCells() const;

    /**
     * @brief Returns the number of games played
     * @return Number of games played
    */
    static int& numberOfGamesPlayed();

    std::vector<unsigned short> operator[](int i);
    const std::vector<unsigned short> operator[](int i) const;
};
#endif //SUDOKU_SUDOKU9_H
