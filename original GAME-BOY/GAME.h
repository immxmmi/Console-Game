#pragma once
#include "Player1.h"
#include "Player2.h"
#include "Level.h"
class GAME : Level, Player1, Player2
{
private:
	bool gameOver;
	bool gameWin;
	int level;
	
	void Level(int level) {
		this->Level::LevelMenu(level);
	}

public:

	GAME() {
		this->gameOver = false;
		this->gameWin = false;
		this->level = 1;

		Player1::x = Level::getX_edge();
		Player1::y = Level::getHeight() -1;
	}





	void Load()
	{
		system("cls");
		Level::LevelMenu(1);
		//this->Level::setSpace(Player1::x, Player1::y, Player1::charakter);
		this->action();
		Level::printField();
	}

	void start()
	{
		Player1::setCharacter(1);
		this->Load();
		while (this->gameOver != true) {
			this->input();
			if (Player1::y == Level::getHeight() / 2 && Player1::x == Level::getWidth()) { this->gameOver = true; }
		}

	}


	void action()
	{
		switch (Player1::control)
		{
		case  Player1::nav::LEFT: if (Level::getSpace(Player1::x - 1,Player1::y)    !=  Level::wall) { /*gehöört hier hin*/Player1::x--;}; Player1::control = nav::STOP; break;
		case  Player1::nav::RIGHT:if(Level::getSpace(Player1::x + 1, Player1::y)    !=  Level::wall) {Player1::x++; }; Player1::control = nav::STOP; break;
		case  Player1::nav::UP:   if(Level::getSpace(Player1::x,     Player1::y - 1)!= Level::wall) {Player1::y--; }; Player1::control = nav::STOP; break;
		case  Player1::nav::DOWN: if(Level::getSpace(Player1::x,     Player1::y + 1)!=  Level::wall) {Player1::y++; }; Player1::control = nav::STOP; break;
			default:break;
		}
		this->Level::setSpace(Player1::x, Player1::y, Player1::charakter);
	}





public: void Settings(char input);



	void input() {
		if (_kbhit())
		{
			char input = _getch();
			if (input == Player1::getConLeft()) {
				Player1::control = Player1::nav::LEFT;
				this->Load();
			}
			if (input == Player1::getConRight()) {
				Player1::control = Player1::nav::RIGHT;
				this->Load();

			}
			if (input == Player1::getConUp()) {
				Player1::control = Player1::nav::UP;
				this->Load();
			}
			if (input == Player1::getConDown()) {
				Player1::control = Player1::nav::DOWN;
				this->Load();
			}
			if (input == 'q') {
				this->gameOver = true;
			}
		}
	}
















	void check(int oldx, int oldy, bool start) {

		if (start != true) {
			if (Player1::x != oldx && Player1::y != oldy) {
				this->Level::setSpace(oldx, oldy, ' ');
				this->Level::setSpace(Player1::x, Player1::y, Player1::charakter);
			}
		}

	}

};

