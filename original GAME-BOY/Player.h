#pragma once

#include <iostream>
#include <conio.h>
#include <time.h>
#include "Level.h"


 class Player: public Level
{

private:

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
	char cont_left;
	char cont_right;
	enum class nav { STOP, LEFT, RIGHT, UP, DOWN }; // NAVIGATION 
	nav control;

	// Generall
	

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



	void rest();
public:
	Player();
	void Settings(char input); // h --> height // --> w-->width // --> c-->control // --> p-->character
	
	void print_characterMenu(int player);
	void setCharacter(int player);
	void setControl();


	void start();

};

