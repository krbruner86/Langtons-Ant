/*
 * Program name: Board.cpp
 * Description: This is the class implementation file for Board.hpp. The Board class holds the dimensions of the
 * simulation board, creates the board, and prints the board.
 */

#include <iostream>
#include "Board.hpp"

// sets the number of rows for the board, accepts an int
void Board::setRows(int r) {
	rows = r;
}

// sets the number of columns for the board, accepts an int
void Board::setCols(int c) {
	columns = c;
}

// returns the private member variable, rows, the number of rows for the board
int Board::getRows() {
	return rows;
}

// returns the private member variable, columns, the number of columns for the board
int Board::getCols() {
	return columns;
}

// uses private member variables to create a dynamically allocated game board, returns a pointer to pointers array game
// board filled with 0's
int** Board::createBoard() {

	int** board = new int*[rows];

	for (int i =0; i < rows; i++) {
		board[i] = new int[columns];
	}

	// fills board with 0's
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			board[i][j] = 0;
		}
	}

	return board;
}

// displays the board, takes a 2d array of pointers to ints, and 2 int's, the ant row location, and the ant column
// location
void Board::printBoard(int** board, int antR, int antC) {

	// print top edge of game board
	for (int i = 0; i < (columns + 2); i++) {
		std::cout << "-";
	}
	std::cout << std::endl;

	// print game board
	for (int i = 0; i < rows; i++) {
		std::cout << "|";
		for (int j = 0; j < columns; j++) {
			// if ant is at location print a star
			if (i == antR && j == antC) {
				std::cout << "*";
			}
			else if (!board[i][j]) {
				std::cout << " ";
			}
			else {
				std::cout << "#";
			}
			if (j+1 == columns) {
				std::cout << "|" << std::endl;
			}
		}
	}

	// print bottom edge of game board
	for (int i = 0; i < (columns + 2); i++) {
		std::cout << "-";
	}
	std::cout << std::endl;
}
