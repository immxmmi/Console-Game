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
	char cont_down;
	char cont_up;
	char cont_right;
	char cont_left;
	enum nav { STOP = 0, LEFT, RIGHT, UP, DOWN }; // NAVIGATION 
	nav control;

	// Generall
	void setCharacter();

	// ACTION
	void action();
	void input();
	void Load();

	// CONTROL
	void setControl();
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
	void print_characterMenu();


public:
	Player();
	void Settings(char input); // h --> height // --> w-->width // --> c-->control // --> p-->character
	void start();
};

