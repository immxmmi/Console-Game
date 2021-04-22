#pragma once

#include <iostream>
#include <conio.h>
#include <time.h>
#include "Level.h"


 class Player//:Level
{

private:

	char cont_down;
	char cont_up;
	char cont_left;
	char cont_right;

	bool gameOver;



protected :


public:
	enum class nav { STOP, LEFT, RIGHT, UP, DOWN }; // NAVIGATION 
	nav control;
	void rest();



	char charakter;
	int level;
	int life;
	int x;
	int y;


	// Generall
	Player();

	// ACTION
	void input();

	// CONTROL
	char getConUp();
	char getConDown();
	char getConRight();
	char getConLeft();
	void setConUp(bool defaultSetting, char key);
	void setConDown(bool defaultSetting, char key);
	void setConRight(bool defaultSetting, char key);
	void setConLeft(bool defaultSetting, char key);
	void setControl(int player);

	// CHARACTER
	void setCharacter(int player);

	// PRINT MENU
	void print_controlMenu(int player);
	void print_characterMenu(int player);



};

