#include"RSUtils.h"
#include<Windows.h>
#include<iostream>
#pragma comment(lib, "User32.lib")

using namespace std;

void moveCursor(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void changeColor(int colorValue){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorValue);
}

void printBackground(){
	moveCursor(0,0);
	changeColor(7);
	for(int i = 0; i < 40; i++){
		for(int j = 0; j < 80; j++){
			cout << ' ';
		}
	}
	moveCursor(0,0);
}

void printBackground(int colorValue){
	moveCursor(0,0);
	changeColor(colorValue);
	for(int i = 0; i < 40; i++){
		for(int j = 0; j < 80; j++){
			cout << ' ';
		}
	}
	moveCursor(0,0);
}

void printBackground(int colorValue, char patternChar){
	moveCursor(0,0);
	changeColor(colorValue);
	for(int i = 0; i < 40; i++){
		for(int j = 0; j < 80; j++){
			cout << patternChar;
		}
	}
	moveCursor(0,0);
}

void hitEnter(){
	moveCursor(37, 23);
	changeColor(7);
	cout << "[ENTER]";
	cin.ignore(10000, '\n');
}

void hitEnter(int xpos, int ypos){
	moveCursor(xpos, ypos);
	changeColor(7);
	cout << "[ENTER]";
	cin.ignore(10000, '\n');
}

void hitEnter(int xpos, int ypos, int color){
	moveCursor(xpos, ypos);
	changeColor(color);
	cout << "[ENTER]";
	cin.ignore(10000, '\n');
}

void showCursor(bool show) 
{
	// thanks to 
	// http://stackoverflow.com/questions/18028808/blinking-underscore-with-console
	
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor;
	GetConsoleCursorInfo(h, &cursor);
	cursor.bVisible = show;
	SetConsoleCursorInfo(h, &cursor);
}

direction getDirection(){
	if (GetKeyState(VK_LEFT) < 0){
		return LEFT;
	}
	else if (GetKeyState(VK_RIGHT) < 0){
		return RIGHT;
	}
	else if (GetKeyState(VK_UP) < 0){
		return UP;
	}
	else if (GetKeyState(VK_DOWN) < 0){
		return DOWN;
	}
	else
		return NONE;
}
