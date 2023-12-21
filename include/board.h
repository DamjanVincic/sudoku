/**
 * @file board.h
 * @brief Declaration of the Board class
 * @date December 21, 2023
 * @author Damjan Vincic
*/

#ifndef SUDOKU_BOARD_H
#define SUDOKU_BOARD_H
#include <vector>

/**
 * @class Board
 * @brief Class for sudoku board representation and related methods
*/
class Board {
    /**
     * @brief 2D vector representing the sudoku board
     */
    std::vector<std::vector<unsigned short>> board;
public:
    /**
     * @brief Empty constructor for the Board class
     */
    Board();

    /**
     * @brief Constructor for the Board class
     * @param board 2D vector representing the sudoku board
     */
    Board(const std::vector<std::vector<unsigned short>>& board);

    /**
     * @brief Copy constructor for the Board class
     * @param other The other Board object to be copied
     */
    Board(const Board& other);

    /**
     * @brief Assignment operator for the Board class
     * @param other The other Board object to be copied.
     * @return
     */
    Board& operator=(const Board& other);

    /**
     * @brief Checks if a number can be placed in a given cell
     * @param row Row of the cell
     * @param col Column of the cell
     * @param num Number to be placed
     * @return True if the number can be placed, false otherwise
     */
    bool isSafe(int row, int col, unsigned short num);
    
    /**
     * @brief Fill the diagonal subgrids of the sudoku board
     */
    void fillDiagonalSubgrids();

    /**
     * @brief Print the sudoku board
    */
    void print();

    /**
     * @brief Returns the sudoku board
     * @return The sudoku board
     */
    std::vector<std::vector<unsigned short>> getBoard() const;

    std::vector<unsigned short>& operator[](int i);
    const std::vector<unsigned short>& operator[](int i) const;
};
#endif //SUDOKU_BOARD_H