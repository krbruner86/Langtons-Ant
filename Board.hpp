/*
 * Program name: Board.hpp
 * Description: This is the class specification file for Board.cpp. The Board class holds the dimensions of the
 * simulation board, creates the board, and prints the board.
 */

#ifndef PROJECT1_BOARD_HPP
#define PROJECT1_BOARD_HPP

class Board {

private:
	int columns;
	int rows;

public:
	// default constructor
	Board() {
		setRows(0);
		setCols(0);
	}

	// getters
	int getRows();
	int getCols();

	// setters
	void setRows(int);
	void setCols(int);

	// accessors
	int** createBoard();
	void printBoard(int**, int, int);

};

#endif //PROJECT1_BOARD_HPP
