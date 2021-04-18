#pragma once

#include <iostream>
#include <conio.h>
#include <time.h>
#include "Field.h"

class Field;
class Player
{
	Field* field = new Field(); // FIELD --> POINTER

private:

	std::string Name;
	bool players;
	char charakter;
	int level;
	int life;
	int x;
	int y;
	int score;
	int scoreLimit;
	bool gameOver;
	enum nav { STOP = 0, LEFT, RIGHT, UP, DOWN }; // NAVIGATION 
	nav control;

public:

	Player();
	void action();
	void printField();
	void input();
	void test();



};

