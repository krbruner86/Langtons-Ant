/*
 * Program name: Ant.cpp
 * Description: This is the class implementation file for Ant.hpp. The Ant class holds the location of the ant, the ants
 * orientation, and moves the ant.
 */

#include <iostream>
#include "Ant.hpp"
#include "Board.hpp"

// sets column for the ant, accepts an int. Updates private member variable col_loc
void Ant::setCol(int c) {
	//subtract 1 enter into board correctly since board is 0 indexed
	col_loc = c-1;
}

// sets row for the ant, accepts an int. Updates private member variable row_loc
void Ant::setRow(int r) {
	//subtract 1 enter into board correctly since board is 0 indexed
	row_loc = r-1;
}

// sets orientation for the ant, accepts an int. Updates private member variable orientation.
// 0 = north, 1 = east, 2 = south, 3 = west
void Ant::setOrientation(int o) {
	orientation = o;
}

// returns an int, private member variable col_loc, which is the column the ant is located
int Ant::getCol() {
	return col_loc;
}

// returns an int, private member variable row_loc, which is the row the ant is located
int Ant::getRow() {
	return row_loc;
}

// returns an int, private member variable orientation, which is the current orientation of the ant
int Ant::getOrientation() {
	return orientation;
}

// moves the ant, does error checking in the process
void Ant::move(int ** gameBoard, Board board) {


	int legal = 0;
	int color = 0;

	// loop that checks to make sure move will be in bounds of array
	do {

		// if square is white, the orientation will rotate clockwise and leave the square black
		if (!gameBoard[row_loc][col_loc]) {
			orientation++;
			color = 1;
		} else {
			// if the square is black, the orientation will rotate counter-clockwise and leave the square white
			orientation--;
			color = 0;
		}

		// resets the orientation if less than 0 or more than 3
		if (orientation > 3) {
			orientation = 0;
		} else if (orientation < 0) {
			orientation = 3;
		}

		// This block of if's checks to make sure the ant will stay inbounds.
		// If any condition is true then it will return to top of loop
		// which rotates the ant 90* in the direction specified by the color
		// and try again.

		// if ant orientation is north and is in the top row
		if (orientation == 0 && row_loc > 0) {
			legal = 1;
		}
		// if ant orientation is east and ant is in right most column
		else if (orientation == 1 && col_loc < board.getCols()-1) {
			legal = 1;
		}
		// if ant orientation is south and ant is in bottom row
		else if (orientation == 2 && row_loc < board.getRows()-1) {
			legal = 1;
		}
		// if ant orientation is west and is in first column
		else if (orientation == 3 && col_loc > 0) {
			legal = 1;
		}
	} while (!legal);

	// this block will switch the color of space and move the ant
	switch (orientation) {

		case 0:
			gameBoard[row_loc][col_loc] = color;
			row_loc--;
			break;
		case 1:
			gameBoard[row_loc][col_loc] = color;
			col_loc++;
			break;
		case 2:
			gameBoard[row_loc][col_loc] = color;
			row_loc++;
			break;
		case 3:
			gameBoard[row_loc][col_loc] = color;
			col_loc--;
			break;
	}
}