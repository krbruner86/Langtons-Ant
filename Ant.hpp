/*
 * Program name: Ant.hpp
 * Description: This is the class specification file for Ant.cpp. The Ant class holds the location of the ant, the ants
 * orientation, and moves the ant.
 */

#ifndef PROJECT1_ANT_HPP
#define PROJECT1_ANT_HPP

#include "Board.hpp"

class Ant {

	private:
		int col_loc;
		int row_loc;
		int orientation;

	public:

		Ant() {
			setCol(0);
			setRow(0);
			setOrientation(0);
		}

		// getters
		int getCol();
		int getRow();
		int getOrientation();

		//setters
		void setCol(int);
		void setRow(int);
		void setOrientation(int);

		// accessor
		void move(int**, Board);

};

#endif //PROJECT1_ANT_HPP
