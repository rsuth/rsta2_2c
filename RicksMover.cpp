#include"RicksMover.h"
#include"RSUtils.h"
#include"Constants.h"
#include<iostream>
#include<string>
#include<Windows.h> // Sleep()
#include<mmsystem.h>
#pragma comment(lib, "winmm.lib")

using namespace std;

RicksMover::RicksMover(){
	row = MAX_ROWS / 2;
	col = MAX_COLS / 2;
	color = 7;
	leaveTrail = false;
	displayChar = '\xFE';
	bgChar = ' ';
	initializeBoard();
}

void RicksMover::moveTo(int x, int y){
	if (x > 0 && y > 0 && x < MAX_COLS && y < MAX_ROWS){
		board[row][col] = bgChar;
		col = x;
		row = y;
		board[row][col] = displayChar;
	}
	else{
		moveCursor(((MAX_COLS + COL_PAD)/2)-8,MAX_ROWS+ROW_PAD+2);
		cout << "invalid moveTo()";
		hitEnter((MAX_COLS + 6) / 2, MAX_ROWS + 4);
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

bool RicksMover::moveUp(){
	
	bool success=true;

	if (board[row - 1][col] == bgChar || board[row - 1][col] == displayChar){
		if (!leaveTrail){
			board[row][col] = bgChar;
		}
		row = row-1;
		board[row][col] = displayChar;
		PlaySound(TEXT("step.wav"), 0, SND_SYNC);
	}

	else{
		moveCursor(col+COL_PAD, (row+ROW_PAD) - 1);
		cout << "*";
		Sleep(100);
		success = false;
		PlaySound(TEXT("oops.wav"), 0, SND_SYNC);
	}

	return success;
}

bool RicksMover::moveDown(){
	
	bool success = true;

	if (board[row + 1][col] == bgChar || board[row + 1][col] == displayChar){
		if (!leaveTrail){
			board[row][col] = bgChar;
		}
		row = row + 1;
		board[row][col] = displayChar;
		PlaySound(TEXT("step.wav"), 0, SND_SYNC);

	}
	else{
		moveCursor(col + COL_PAD, row + ROW_PAD + 1);
		cout << "*";
		Sleep(100);
		success = false;
		PlaySound(TEXT("oops.wav"), 0, SND_SYNC);
	}
	
	return success;
}

bool RicksMover::moveLeft(){
	
	bool success = true;

	if (board[row][col - 1] == bgChar || board[row][col - 1] == displayChar){
		if (!leaveTrail){
			board[row][col] = bgChar;
		}
		col = col - 1;
		board[row][col] = displayChar;
		PlaySound(TEXT("step.wav"), 0, SND_SYNC);
	}
	else{
		moveCursor(COL_PAD + col - 1, row + ROW_PAD);
		cout << "*";
		Sleep(100);
		success = false;
		PlaySound(TEXT("oops.wav"), 0, SND_SYNC);
	}
	return success;
}
bool RicksMover::moveRight(){
	
	bool success = true;

	if (board[row][col + 1] == bgChar || board[row][col + 1] == displayChar){
		if (!leaveTrail){
			board[row][col] = bgChar;
		}
		col = col + 1;
		board[row][col] = displayChar;
		PlaySound(TEXT("step.wav"), 0, SND_SYNC);
	}
	else{
		moveCursor(COL_PAD + col + 1, row + ROW_PAD);
		cout << "*";
		Sleep(100);
		success = false;
		PlaySound(TEXT("oops.wav"), 0, SND_SYNC);
	}
	return success;
}
void RicksMover::drawBoard(){
	board[row][col] = displayChar;
	moveCursor(COL_PAD, ROW_PAD);
	for (int i = 0; i <= MAX_ROWS; i++){
		for (int j = 0; j <= MAX_COLS; j++){
			if (board[i][j] == displayChar){ changeColor(color); }
			cout << board[i][j];
			changeColor(BOARD_COLOR);
		}
		moveCursor(COL_PAD, ROW_PAD + i+1);
	}
}

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

void RicksMover::addObstacle(int _col, int _row){
	board[_row][_col] = '#';
}

void RicksMover::addObstacle(int _col, int _row, char obs){
	board[_row][_col] = obs;
}