#pragma once

#include <iostream>
#include <conio.h>
#include <time.h>
#include "Field.h"
#include "te.h"


class Player
{
	Field* field = new Field(); // FIELD --> POINTER
	te* level1 = new te(); // FIELD --> POINTER

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
	char cont_down = 's';
	char cont_up = 'w';
	char cont_right = 'd';
	char cont_left = 'a';
	enum nav { STOP = 0, LEFT, RIGHT, UP, DOWN }; // NAVIGATION 
	nav control;

	char getConUp();
	char getConDown();
	char getConRight();
	char getConLeft();
	void setConUp();
	void setConDown();
	void setConRight();
	void setConLeft();
	void print_controlMenu();
	void Mauer(int index, int index2, int space, int limit);
	void action();
	void input();
	void Load();

public:

	Player();


	void setControl();
	void test();




};

