/****
*  ID information
*  ==============
*	Programmer:	Rick Sutherland
*	Assignment #: TA#2.2C
*	Assignment Name: Getting Classy
*	Course: CISC 205 OOPS
*	Class Meeting Time:	T/TH 9:35
*	Instructor:	Larry Forman
*	Hours: 9.75
*	Difficulty: 5
*	Competion Date: 11/3/2014
*	Project Name: RSTA2_2C
*/

#ifndef RICKSMOVER_H
#define RICKSMOVER_H
#include<string>		//for strings
#include"Constants.h"	// for stuff like max sizes, padding

// USING STANDARD NAMESPACE
using namespace std;

class RicksMover
{
private:
	/*=====PRIVATE MEMBER VARIABLES======*/
	int row;							// holds the row number
	int col;							// holds the collumn number
	char bgChar;						// the character to be used as background of board
	char board[MAX_ROWS+1][MAX_COLS+1]; // the board array
	/*==================================*/
	
	/*=====PRIVATE MEMBER FUNCTIONS======*/
	
	// NAME: initializeBoard()
	// DESC: readys the gameboard, fills the array with spaces 
	//       and the "fences" around the area.
	void initializeBoard();			
	
	/*==================================*/

public:
	/*====PUBLIC MEMBER VARIABLES=======*/
	
	bool leaveTrail;
	char displayChar;
	int color;
	
	/*==================================*/
	
	/*====PUBLIC MEMBER FUNCTIONS=======*/
	
	// NAME: RicksMover
	// DESC: Default constructor. makes a board, initializes
	//		 and sets some default values.
	RicksMover();

	// NAME: RicksMover
	// DESC: Default destructor. does nothing.
	~RicksMover(){}

	// NAME: moveTo
	// DESC: changes the row and col variables to params 
	//		 _row and _col. (Checks to make sure they 
	//		 are within the range of the board.) if 
	//		 not, a message is displayed. Overloaded
	//		 to print a string message after moving.
	void moveTo(int _row, int _col);
	void moveTo(int _row, int _col, string message);
	
	// NAME: getRow
	// DESC: returns the value in member variable row.
	int getRow();
	
	// NAME: getCol
	// DESC: returns the value in member variable col.
	int getCol();

	// NAME: setRow
	// DESC: sets the value in member variable row.
	void setRow(int _row);

	// NAME: setCol
	// DESC: sets the value in member variable col.
	void setCol(int _col);

	// NAME: jump
	// DESC: runs moveTo with the parameters.
	//		 basically just a wrapper.
	void jump(int _row, int _col);

	// NAME: addObstacle
	// DESC: insets a character into the gameboard array
	//		 at row _row, and col _col. the char defaults
	//		 to '#' but can be changed with the overloaded
	//		 function param obs.
	void addObstacle(int _col, int _row);
	void addObstacle(int _col, int _row, char obs);
	
	// NAME: displayStats
	// DESC: prints status of all member variables to the side
	//		 of the board.
	void displayStats();

	// NAME: move functions
	// DESC: moves the char in the direction indicated by the 
	//		 function name. optionally pass the number of spaces
	//		 to move as a parameter(default is one). Will not move
	//		 if the space in front is not a background character,
	//		 including the tail. all return a bool for success
	//		 (if the move was successful, return true, otherwise
	//		 false will be returned.)
	bool moveUp();
	bool moveUp(int spaces);
	bool moveDown();
	bool moveDown(int spaces);
	bool moveLeft();
	bool moveLeft(int spaces);
	bool moveRight();
	bool moveRight(int spaces);

	// NAME: drawBoard
	// DESC: draws the board array to the screen, using defined constants 
	//       for how much left/top padding to use.
	void drawBoard();
	
	/*==================================*/
};


#endif /*RICKSMOVER_H*/