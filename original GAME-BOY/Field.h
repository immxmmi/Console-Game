#pragma once
#include <iostream>
class Field
{
private:
	char field[100][100] = {};
	//WIDTH
	int width;
	int min_Width;
	int max_Width;

	//HEIGHT
	int height;
	int min_Height;
	int max_Height;
	//EDGE
	int y_edge;
	int x_edge;
	//PRINT
	void print_widthMenu();
	void print_heightMenu();
	char inputChange(char input);



public:
	char wall;
	int getY_edge();
	int getX_edge();
	//GENERAL
	Field();
	//SETTER
	void setSpace(int x, int y, char symbol);
	void setHeight(int check);
	void setWidth(int check);
	//GETTER
	int getWidth();
	int getHeight();
	char getSpace(int x, int y);

	//ACTION
	void drawField();
	//PRINTER
	void printField();





};

