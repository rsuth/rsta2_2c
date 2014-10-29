#ifndef RICKSMOVER_H
#define RICKSMOVER_H
#include<string>
#include"Constants.h"

using namespace std;

class RicksMover
{
private:
	int row;
	int col;
	char bgChar;
	char board[MAX_ROWS+1][MAX_COLS+1];
	void initializeBoard();
public:
	RicksMover();
	~RicksMover(){}
	void moveTo(int x, int y);
	void moveTo(int x, int y, string message);
	void addObstacle(int _col, int _row);
	void addObstacle(int _col, int _row, char obs);
	bool moveUp();
	bool moveDown();
	bool moveLeft();
	bool moveRight();
	void drawBoard();
	bool leaveTrail;
	char displayChar;
	int color;
};


#endif /*RICKSMOVER_H*/