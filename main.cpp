/*
 * Program name: main.cpp
 * Description: This is the main program for Langton's Ant. Follow the on-screen prompts to run the simulation.
 */

#include <iostream>
#include "menu.hpp"
#include "Ant.hpp"
#include "Board.hpp"

/*
 * This program will run the Langton's Ant simulation based on user inputted values. To run this program type ./main
 * in the command line. Follow the on-screen menu prompts to run the program.
 */
int main() {

	// creates a menu object to call menu functions
	Menu menu;


	// integer to hold main menu selection
	int option;
	option = menu.mainMenu();

	// continue running program as long as quit is not selected
	while (option != 2) {

		// create objects to be used in simulation
		Board board;
		Ant ant;

		// holds options to set-up simulation, allocates memory
		int* options = menu.setup();

		// set the board up and set ant location
		board.setCols(options[0]);
		board.setRows(options[1]);
		ant.setCol(options[3]);
		ant.setRow(options[4]);

		// create game board array, allocates memory
		int** gameBoard = board.createBoard();

		// run the simulation for as many steps as the user selected
		do {
			menu.header();

			ant.move(gameBoard, board);

			options[2]--;
			board.printBoard(gameBoard, ant.getRow(),ant.getCol());
		} while (options[2] > 0);

		// show the final board and ask if user wants to play again
		menu.header();
		board.printBoard(gameBoard, ant.getRow(),ant.getCol());

		// free memory from 2d array game board
		for (int i = 0; i < board.getRows(); i++) {
			delete[] gameBoard[i];
		}
		delete[] gameBoard;

		// free memory from options array
		delete[] options;

		option = menu.gameOver();

	}

	// exit if user chooses to do so
	return 0;
}