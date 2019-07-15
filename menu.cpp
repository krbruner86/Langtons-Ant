/*
 * Program name: menu.cpp
 * Description: This is the class implementation file for menu.cpp. This program displays on-screen prompts to the user.
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>  // for 'system' call
#include <climits>  // for MAX_INT constant
#include "menu.hpp"
#include "getInt.hpp"

// prototype so the getInt function can be used
int getInt(int,int);

// displays the main menu. returns an integer, the menu selection
int Menu::mainMenu() {

	header();
	std::cout << "1. Start Langton's Ant simulation\n";
	std::cout << "2. Quit\n\n";

	return getInt(1,2);
}

// get params from user for simulation
int* Menu::setup() {

	// allocates space for array to hold options that returns to main
	int* arr = new int[5];

	header();
	std::cout << "How many columns would you like to have?\n";
	arr[0] = getInt(2,50);
	std::cout << "How many rows would you like to have?\n";
	arr[1] = getInt(2,50);
	std::cout << "How many steps would you like the simulation to run?\n";
	arr[2] = getInt(1,INT_MAX);
	std::cout << "What column would you like the ant to start?\n";
	arr[3] = getInt(1,arr[0]);
	std::cout << "What row would you like the ant to start?\n";
	arr[4] = getInt(1,arr[1]);

	return arr;
}

// displays header
void Menu::header() {
	system("clear");
	std::cout << "\nWelcome to Langton's Ant Simulation!\n\n";
}

// menu displayed after the end of the simulation
int Menu::gameOver() {

	std::cout << "\n~- Simulation Over! -~\n\n";
	std::cout << "1. Start Langton's Ant simulation\n";
	std::cout << "2. Quit\n\n";

	return getInt(1,2);
}