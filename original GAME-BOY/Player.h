#pragma once

#include <iostream>
#include <conio.h>
#include <time.h>
#include "Level.h"


class Player: public Level
{

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

	// ACTION
	void action();
	void input();
	void Load();

	// CONTROL
	char getConUp();
	char getConDown();
	char getConRight();
	char getConLeft();
	void setConUp();
	void setConDown();
	void setConRight();
	void setConLeft();

	// PRINT MENU
	void print_controlMenu();
	void print_charakterMenu();

public:

	Player();
	void setHeight2();
	void setWidth2();
	void setControl();
	void setCharaker();
	void start();
};

