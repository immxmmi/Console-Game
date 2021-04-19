#pragma once
#include <iostream>
class Field
{
private:
	//WIDTH
	int width;
	int min_Width = 10;
	int max_Width = 60;
	//HEIGHT
	int height;
	int min_Height = 10;
	int max_Height = 30;
	//EDGE
	int y_edge = 2;
	int x_edge = 31;
	//FIELD
	void print_widthMenu();
	void print_heightMenu();


public:
	char field[100][100] = {};
	Field();
	void printField();
	void drawField();

	char askMe(char input);


	void setHeight();
	void setWidth();
	int getWidth();
	int getHeight();
	int getX_edge();
	int getY_edge();

};

