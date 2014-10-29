#include"RSUtils.h"
#include"RSWindow.h"
#include<string>
#include<Windows.h>
#include<vector>
#include<iostream>

using namespace std;

RSWindow::RSWindow(){
	xpos = 5;
	ypos = 5;
	width = 5;
	height = 3;
	color = 30;
	title = "";
	shadow = true;
	shadowColor = 7;
}

RSWindow::~RSWindow(){}

RSWindow::RSWindow(int xpos, int ypos){
	this->xpos = xpos;
	this->ypos = ypos;
	//default values
	title = " ";
	color = 21;
	width = 10;
	height = 5;
	shadow = true;
	shadowColor = 7;
}

RSWindow::RSWindow(int xpos, int ypos, string title){
	this->xpos = xpos;
	this->ypos = ypos;
	this->title = title;
	//default values
	color = 21;
	width = 10;
	height = 5;
	shadow = true;
	shadowColor = 7;
}

RSWindow::RSWindow(int _xpos, int _ypos, int _width, int _height, string _title){
	xpos = _xpos;
	ypos = _ypos;
	width = _width;
	height = _height;
	title = _title;
	
	//default values
	color = 21;
	shadow = true;
	shadowColor = 7;
}

RSWindow::RSWindow(int xpos, int ypos, int width, int height, int color, string title){
	this->xpos = xpos;
	this->ypos = ypos;
	this->width = width;
	this->height = height;
	this->color = color;
	this->title = title;
	shadow = true;
	shadowColor = 7;
}

RSWindow::RSWindow(int xpos, int ypos, int width, int height, int color){
	this->xpos = xpos;
	this->ypos = ypos;
	this->width = width;
	this->height = height;
	this->color = color;
	this->title = title;
	shadow = true;
	shadowColor = 7;
}

void RSWindow::draw(){
	
	// first print shadow if shadow = true
	if(shadow){
		moveCursor(xpos+1, ypos+1);
		changeColor(shadowColor);	
		for(int j = ypos+1; j < ypos + height + 1; j++){
			for(int i = 0; i <= width; i++){
				cout << " ";
			}
		moveCursor(xpos+1, j);
		}
	}

	// Now Print Window
	moveCursor(xpos, ypos);
	changeColor(color);	
	for(int j = ypos; j < ypos + height; j++){
		for(int i = 0; i <= width; i++){
			cout << " ";
		}
		moveCursor(xpos, j);
	}
	
	// print title border:
	moveCursor(xpos, ypos);
	cout << "\311";
	for(int i = 0; i < width-1; i++){
		cout << "\315";
	}
	cout << "\273";

	moveCursor(xpos, ypos+1);
	cout << "\272";
	moveCursor(xpos+width, ypos+1);
	cout << "\272";

	moveCursor(xpos, ypos+2);
	cout << "\310";
	
	moveCursor(xpos+1, ypos+2);
	for(int i = 0; i < width-1; i++){
		cout << "\315";
	}

	moveCursor(xpos+width, ypos+2);
	cout << "\274";
	// end border printing


	// Put the cursor at the middle of the window
	moveCursor((xpos+(width/2)-(title.length()/2)), ypos+1);
	
	// print the window title
	cout << title;

	// print the window content
	for(unsigned int i = 0; i < content.size(); i++){
		moveCursor(xpos+1, ypos + i + 4);
		cout << content[i];
	}
}

void RSWindow::setContent(vector<string> _content){
	content.swap(_content);
}



