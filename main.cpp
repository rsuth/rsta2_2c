// 10/27 -- got it working
// 7:30p start
// 11:30p stop
// 
// 10/28 -- added sound/control
// 8:00 start
// 10:30 stop

#include<iostream>
#include"RSUtils.h"
#include"RicksMover.h"
#include<Windows.h>
#include<time.h>


using namespace std;

void around(int steps);	
void step(int steps);
void control();

int main(){
	showCursor(false);
	printBackground(7, ' ');
	step(1000);
	control();
	hitEnter();
	return 0;
}

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
	mover.moveTo(1, 1);
	mover.leaveTrail = true;
	srand(time(NULL));
	for (int k = 0; k < 30; k++){
		mover.addObstacle(rand() % MAX_COLS-1, rand() % MAX_ROWS-1);
	}

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
	direction d = NONE;
	RicksMover mover;
	mover.color = 249;
	mover.addObstacle(4, 4);
	mover.leaveTrail = false;
	srand(time(NULL));
	for (int k = 0; k < 30; k++){
		mover.addObstacle(rand() % MAX_COLS - 1, rand() % MAX_ROWS + 1);
	}

	do
	{
		mover.drawBoard();
		d = NONE;
		d = getDirection();
		if (d == LEFT){
			mover.moveLeft();
			mover.drawBoard();
		}
		if (d == RIGHT){
			mover.moveRight();
			mover.drawBoard();
		}
		if (d == UP){
			mover.moveUp();
			mover.drawBoard();
		}
		if (d == DOWN){
			mover.moveDown();
			mover.drawBoard();
		}

	} while (true);
}