#ifndef CONSTANTS_H
#define CONSTANTS_H

#include<string>

using namespace std;

const string MY_NAME = "Rick S.";
const int MAX_ROWS = 20;
const int MAX_COLS = 60;
const int ROW_PAD = 2;
const int COL_PAD = 10;
const int SPEED = 0;
const int BOARD_COLOR = 240;

#endif /*CONSTANTS_H*/


/*
The following are all defined as constants in <windows.h>:

BACKGROUND_INTENSITY	= 128;
BACKGROUND_RED			=  64;
BACKGROUNDGREEN			=  32;
BACKGROUND_BLUE			=  16;
FOREGROUND_INTENSITY	=   8;
FOREGROUND_RED			=   4;
FOREGROUND_GREEN		=   2;
FOREGROUND_BLUE			=   1;

with the following combinations:

COLOR NAME		BACKGROUND #	FOREGROUND #

Black				 0				0		(= No Blue, no Green, no Red)
Blue				16				1		(= Blue)
Green				32				2		(= Green)
Cyan				48				3		(= Blue  + Green)
Red					64				4		(= Red)
Magenta				80				5		(= Blue  + Red)
Yellow				96				6		(= Green + Red)
White			   112				7		(= Blue  + Green + Red)
Intensity + Black  128				8		(= Intensity alone)
Intensity + Blue   144				9		(= Intensity + Blue)
etc.			   ...			  ...
Intensity + White  240			   15		(= Intensity + Blue + Green + Red)

Then, you can combine any backgound color with any foreground color
simply by adding the two corresponding values, like:

Background Yellow  + Foreground Red =
96    +             4   = 100

Background Intensity + Yellow and Foreground Intensity + Red =
128      +   96    +                 8     +  4   = 236

*/