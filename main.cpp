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
/****
* Stars
* =====
*	1.	include a member variable for any ascii char
*	2.	include a member variable for color
*	3.	Add overloaded “move” functions that have 
*		an integer parameter to indicate the number of 
*		rows or columns the character will move
*	4&5.In the displayPlayArea function add “obstacles” 
*		that act like “walls” to prevent character from 
*		moving past them
*`	6.	Add a spiral pattern function
*	7.	Add a function that displays the current state
*		of all member variables.
*
*	TOTAL: 7
*/
/****
* CUSTOM DEFINED FUNCTION LIST:
* 
* around
* control
* goodBye 
* jumpDemo
* mainMenu
* step
* 
*/

#include<iostream>		// for cout messages, debugging
#include"RSUtils.h"		// for moveCursor, showCursor, changeColor
#include"RicksMover.h"	// Mover class, the logic behind the program
#include"RSWindow.h"	// Window class for making windows for menu, etc.
#include<Windows.h>		// for Sleep
#include<time.h>		// for random seed in randomized funtions
#include<vector>		// to store message contents for RSWindow
#include<conio.h>		// for _getch in mainMenu

// using standard namespace
using namespace std;


/*============START-FUNCTION-PROTOTYPES===============*/

// NAME: around
// DESC: moves the char around the board in a spiral pattern
//		 takes the number of steps to run the loop as a param.
void around(int steps);	

// NAME: step
// DESC: moves the char around the board in a stepping pattern 
//       until it hits an obstacle, then moves in the opposite
//       direction and repeats. param steps is the number of steps 
//		 the character will take.
void step(int steps);

// NAME: control
// DESC: allows the char to be controlled by the keyboard arrows.
void control();

// NAME: jumpDemo
// DESC: Demonstrates jump function by randomly jumping around
//		 the board.
void jumpDemo();

// NAME: mainMenu
// DESC: runs a loop: displays a menu, gets a keyboard selection, 
//		 and calls the selected function.
void mainMenu();

// NAME: goodBye
// DESC: prints a farewell message, the id info, and the stars.
void goodBye();

/*============END-FUNCTION-PROTOTYPES==================*/

/*==================START-MAIN=========================*/
int main(){
	showCursor(false);  // Tells windows console not to display the cursor
	mainMenu();			// starts the menu loop
	return 0;
}
/*==================END-MAIN==========================*/


/*============START-FUNCTION-DEFINITIONS==============*/
void around(int steps){
	RicksMover mover;
	mover.displayChar = '\002';
	mover.color = 252;
	mover.moveTo(1, 1);
	mover.leaveTrail = true;
	for (int i = 0; i < steps; i++){
		while (mover.moveRight()){
			mover.drawBoard();
			Sleep(SPEED);
		}
		while (mover.moveDown()){
			mover.drawBoard();
			Sleep(SPEED);
		}
		while (mover.moveLeft()){
			mover.drawBoard();
			Sleep(SPEED);
		}
		while (mover.moveUp()){
			mover.drawBoard();
			Sleep(SPEED);
		}
	}
}

void step(int steps){
	RicksMover mover;
	mover.displayChar = '\xFE'; //square block: xFE
	mover.color = 249;
	mover.moveTo(3, 1);
	mover.leaveTrail = true;

	for (int i = 0; i < steps; i++){
		mover.drawBoard();
		Sleep(SPEED);
		if (!mover.moveRight()){
			while (mover.moveLeft()){
				mover.drawBoard();
				Sleep(SPEED);
			}
		}
		mover.drawBoard();
		Sleep(SPEED);
		if (!mover.moveDown()){
			while (mover.moveUp()){
			mover.drawBoard();
			Sleep(SPEED);
			}
		}
	}


}

void control(){
	bool quit = false;
	direction d = NONE;
	
	RicksMover mover;
	mover.color = 249;
	mover.leaveTrail = false;

	srand(time(NULL));
	for (int k = 0; k < 5; k++){
		mover.addObstacle((rand() % (MAX_COLS-1))+1, (rand() % (MAX_ROWS-1))+1);
	}
	
	do
	{
		mover.drawBoard();
		d = getDirection();
		
		if (d == LEFT){
			mover.moveLeft();
		}
		else
		if (d == RIGHT){
			mover.moveRight();
		}
		else
		if (d == UP){
			mover.moveUp();
		}
		else
		if (d == DOWN){
			mover.moveDown();
		}
		else
		if (d == QUIT){
			quit = true;
		}
		Sleep(SPEED);
	} while (!quit);
}

void mainMenu(){
	
	bool q = false;
	
	vector<string> menuContent;
	menuContent.push_back("C. Run Control");
	menuContent.push_back("S. Run Spiral"); 
	menuContent.push_back("T. Run Stepper");
	menuContent.push_back("J. Run Jump");
	menuContent.push_back("Q. Quit");

	
	RSWindow menuWindow(20, 5, 40, 12, 24, "RicksMover Class");
	menuWindow.setContent(menuContent);
	printBackground(7);

	do{
		printBackground(7);
		menuWindow.draw();
		switch (toupper(_getch())){
		case 'S':
			printBackground(7);
			around(10);
			hitEnter();
			break;
		case 'C':
			printBackground(7);
			moveCursor((MAX_COLS + COL_PAD / 2) - 2, MAX_ROWS + ROW_PAD + 2);
			changeColor(12);
			cout << "ESC: Stop Loop";
			control();
			hitEnter();
			break;
		case 'T':
			printBackground(7);
			step(30);
			hitEnter();
			break;
		case'J':
			jumpDemo();
			break;
		case 'Q':
			q = true;
			goodBye();
			break;
		}

	} while (!q);

}

void jumpDemo(){
	RicksMover j;
	j.color = 245;
	j.leaveTrail = false;

	printBackground(7);
	j.drawBoard();
	hitEnter();
	srand(time(NULL));
	for (int i = 0; i < 30; i++){
		j.jump((rand() % (MAX_ROWS - 2)) + 1, (rand() % (MAX_COLS - 2)) + 1);
		j.drawBoard();
		Sleep(300);
	}
	hitEnter();
}

void goodBye(){
	
	vector<string> byeMessage;
	byeMessage.push_back("");
	byeMessage.push_back("");
	byeMessage.push_back("    Thank you for running TA2.2C-");
	byeMessage.push_back("           Getting Classy        ");
	
	vector<string> IDinfo;
	IDinfo.push_back("Programmer: Rick Sutherland");
	IDinfo.push_back("Assignment #: TA#2.2C");
	IDinfo.push_back("Assignment Name: Getting Classy");
	IDinfo.push_back("Course: CISC 205 OOPS (T/TH 9:35)");
	IDinfo.push_back("Instructor: Larry Forman");
	IDinfo.push_back("Hours: 9.75");
	IDinfo.push_back("Difficulty: 7");
	IDinfo.push_back("Competion Date : 11 / 3 / 2014");
	IDinfo.push_back("Project Name: RSTA2_2C");

	vector<string> stars;
	stars.push_back("1.   include a member variable for any ascii char");
	stars.push_back("2.   include a member variable for color");
	stars.push_back("3.   Add overloaded move functions that have");
	stars.push_back("     an integer parameter to indicate the number of");
	stars.push_back("     rows or columns the character will move");
	stars.push_back("4&5. In the displayPlayArea function add \"obstacles\"");
	stars.push_back("6.   Add a spiral pattern function");
	stars.push_back("7.   Add a function that displays the current state");
	stars.push_back("     of all member variables");
	stars.push_back("");
	stars.push_back("TOTAL STARS = 7");


	RSWindow bye(20, 3, 40, 15, 111, "Goodbye");
	
	bye.setContent(byeMessage);
	bye.draw();
	hitEnter();

	bye.title = "ID INFO";
	bye.color = 79;
	bye.setContent(IDinfo);
	bye.draw();
	hitEnter();

	bye.width = 60;
	bye.height = 17;
	bye.xpos = 10;
	bye.title = "STARS";
	bye.color = 240;
	bye.setContent(stars);
	bye.draw();
	hitEnter();
}
/*============END-FUNCTION-DEFINITIONS===============*/