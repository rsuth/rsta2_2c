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
#include"RicksMover.h"	// header file with class
#include"RSUtils.h"		// for moveCursor, colors, etc.
#include"Constants.h"	// for Max sizes, padding
#include<iostream>		// for output
#include<iomanip>		// for manipulating output format
#include<string>		// for using strings
#include<Windows.h>		// Sleep()

// USING STANDARD NAMESPACE
using namespace std;

/*=======================================================*/
/*==========BEGIN=FUNCTION=DEFINITIONS===================*/
/*=======================================================*/
// NAME: RicksMover
// DESC: Default constructor. makes a board, initializes
//		 and sets some default values.
RicksMover::RicksMover(){
	row = MAX_ROWS / 2;
	col = MAX_COLS / 2;
	color = 7;
	leaveTrail = false;
	displayChar = '\xFE';
	bgChar = ' ';
	initializeBoard();
	board[row][col] = displayChar;
}

// NAME: moveTo
// DESC: changes the row and col variables to params 
//		 _row and _col. (Checks to make sure they 
//		 are within the range of the board.) if 
//		 not, a message is displayed. Overloaded
//		 to print a string message after moving.
void RicksMover::moveTo(int _row, int _col){
	if (_col > 0 && _row > 0 && _col < MAX_COLS && _row < MAX_ROWS){
		board[row][col] = bgChar;
		row = _row;
		col = _col;
		board[row][col] = displayChar;
	}
	else{
		moveCursor(((MAX_COLS + COL_PAD)/2)+8,MAX_ROWS+ROW_PAD+2);
		cout << "invalid moveTo()";
		cout << "_row= " << _row << "_col= " << _col;
		hitEnter();
	}
}

void RicksMover::moveTo(int x, int y, string message){
	if (x > 0 && y > 0 && x < MAX_COLS && y < MAX_ROWS){
		board[row][col] = bgChar;
		col = x;
		row = y;
		moveCursor(x+COL_PAD, y+ROW_PAD);
		cout << message;
	}
	else{
		moveCursor(((MAX_COLS+COL_PAD) / 2) - 8, MAX_ROWS+ ROW_PAD + 1);
		cout << "invalid moveTo()";
		hitEnter((MAX_COLS + 6) / 2, MAX_ROWS + 4);
	}
}

// NAME: move functions
// DESC: moves the char in the direction indicated by the 
//		 function name. optionally pass the number of spaces
//		 to move as a parameter(default is one). Will not move
//		 if the space in front is not a background character,
//		 including the tail. all return a bool for success
//		 (if the move was successful, return true, otherwise
//		 false will be returned.)
bool RicksMover::moveUp(){
	
	bool success=true;

	if (board[row - 1][col] == bgChar){
		if (!leaveTrail){
			board[row][col] = bgChar;
		}
		row = row-1;
		board[row][col] = displayChar;
	}

	else{
		moveCursor(col+COL_PAD, (row+ROW_PAD) - 1);
		cout << "*";
		Sleep(10);
		success = false;
	}

	return success;
}

bool RicksMover::moveUp(int spaces){

	bool success = true;

	for (int i = 0; i < spaces; i++){
		success = moveUp();
	}

	return success;
}

bool RicksMover::moveDown(){
	
	bool success = true;

	if (board[row + 1][col] == bgChar){
		if (!leaveTrail){
			board[row][col] = bgChar;
		}
		row = row + 1;
		board[row][col] = displayChar;

	}
	else{
		moveCursor(col + COL_PAD, row + ROW_PAD + 1);
		cout << "*";
		Sleep(10);
		success = false;
	}
	
	return success;
}

bool RicksMover::moveDown(int spaces){
	
	bool success = true;
	
	for (int i = 0; i < spaces; i++){
		success = moveDown();
	}

	return success;
}

bool RicksMover::moveLeft(){
	
	bool success = true;

	if (board[row][col - 1] == bgChar){
		if (!leaveTrail){
			board[row][col] = bgChar;
		}
		col = col - 1;
		board[row][col] = displayChar;
	}
	else{
		moveCursor(COL_PAD + col - 1, row + ROW_PAD);
		cout << "*";
		Sleep(10);
		success = false;
	}
	return success;
}

bool RicksMover::moveLeft(int spaces){

	bool success = true;

	for (int i = 0; i < spaces; i++){
		success = moveLeft();
	}

	return success;
}

bool RicksMover::moveRight(){
	
	bool success = true;

	if (board[row][col + 1] == bgChar){
		
		if (!leaveTrail){
			board[row][col] = bgChar;
		}
		col++;
		board[row][col] = displayChar;
	}
	else{
		moveCursor(COL_PAD + col + 1, row + ROW_PAD);
		cout << "*";
		Sleep(10);
		success = false;
	}

	return success;
}

bool RicksMover::moveRight(int spaces){

	bool success = true;

	for (int i = 0; i < spaces; i++){
		success = moveRight();
	}

	return success;
}

// NAME: drawBoard
// DESC: draws the board array to the screen, using defined constants 
//       for how much left/top padding to use.
void RicksMover::drawBoard(){
	moveCursor(COL_PAD, ROW_PAD);
	for (int i = 0; i <= MAX_ROWS; i++){
		for (int j = 0; j <= MAX_COLS; j++){
			if (board[i][j] == displayChar){ changeColor(color); }
			cout << board[i][j];
			changeColor(BOARD_COLOR);
		}
		moveCursor(COL_PAD, ROW_PAD + i+1);
	}
	RicksMover::displayStats();
}

// NAME: initializeBoard()
// DESC: readys the gameboard, fills the array with spaces 
//       and the "fences" around the area.
void RicksMover::initializeBoard(){
	
	board[0][0] = '\311';
	board[MAX_ROWS][MAX_COLS] = '\274';
	board[0][MAX_COLS] = '\273';
	board[MAX_ROWS][0] = '\310';

	for (int i = 1; i < MAX_ROWS; i++){
		board[i][0] = '\272';
		board[i][MAX_COLS] = '\272';
	}
	for (int i = 1; i < MAX_COLS; i++){
		board[0][i] = '\315';
		board[MAX_ROWS][i] = '\315';
	}

	for (int i = 1; i < MAX_ROWS; i++){
		for (int j = 1; j < MAX_COLS; j++){
			board[i][j] = bgChar;
		}
	}
}

// NAME: addObstacle
// DESC: insets a character into the gameboard array
//		 at row _row, and col _col. the char defaults
//		 to '#' but can be changed with the overloaded
//		 function param obs.
void RicksMover::addObstacle(int _col, int _row){
	board[_row][_col] = '#';
}

void RicksMover::addObstacle(int _col, int _row, char obs){
	board[_row][_col] = obs;
}

// NAME: displayStats
// DESC: prints status of all member variables to the side
//		 of the board.
void RicksMover::displayStats(){
	moveCursor(53, 6);
	cout << "Row: " << setw(2) << row;
	moveCursor(53, 7);
	cout << "Col: " << setw(2) << col;
	moveCursor(53, 8);
	cout << "leaveTrail: "; 
	if (leaveTrail)
		cout << "True";
	else
		cout << "False";
	moveCursor(53, 9);
	cout << "Color: " << setw(2) << color;
	moveCursor(53, 10);
	cout << "displayChar: ";
	changeColor(color);
	cout << displayChar;
	changeColor(240);
	moveCursor(53, 11);
	cout << "bgChar: " << bgChar;

}

// NAME: jump
// DESC: runs moveTo with the parameters.
//		 basically just a wrapper.
void RicksMover::jump(int _row, int _col){
	RicksMover::moveTo(_row, _col);
}

/*=======================================================*/
/*==========END=FUNCTION=DEFINITIONS=====================*/
/*=======================================================*/