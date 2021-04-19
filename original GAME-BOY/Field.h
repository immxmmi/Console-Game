#pragma once
#include <iostream>
class Field
{
private:
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

	//GENERAL
	Field();
	char field[100][100] = {};


	//SETTER
	void setSpace(int x, int y, char symbol);
	void setHeight(int check);
	void setWidth(int check);
	//GETTER
	int getWidth();
	int getHeight();
	int getX_edge();
	int getY_edge();
	char getSpace(int x, int y);

	//ACTION
	void drawField();

	//PRINTER
	void printField();






};

