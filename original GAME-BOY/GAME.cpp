#include "GAME.h"


//GENERAL
GAME::GAME() {
	this->gameOver = false;
	this->gameWin = false;
	this->morePlayer = false;
	this->level = 1;

	Player1::x = Level::getX_edge();
	Player1::y = Level::getHeight() - 1;
	Player2::x = Level::getX_edge();
	Player2::y = Level::getHeight() - 1;
}


void GAME::restartW()
{
	this->gameWin = false;
	Player1::x = Level::getX_edge();
	Player1::y = Level::getHeight() - 1;
	Player2::x = Level::getX_edge();
	Player2::y = Level::getHeight() - 1;
}

void GAME::restartO()
{
	this->gameOver = false;
	this->gameWin = false;
	this->morePlayer = false;
	this->level = 1;

	Player1::x = Level::getX_edge();
	Player1::y = Level::getHeight() - 1;
	Player2::x = Level::getX_edge();
	Player2::y = Level::getHeight() - 1;
}



//GAME START
void GAME::start(bool morePlayer)
{
	this->morePlayer = morePlayer;

	// Player 1;
	Player1::setCharacter(1);
	if (this->morePlayer == true) {
		// Player 2;	
		Player2::setCharacter(2);
	}

	this->Load();
	while (this->gameOver != true) {
		while (gameWin != true) {
			this->input();
			if (Player1::y == Level::getHeight() / 2 && Player1::x == Level::getWidth()) { this->gameWin = true;this->level++; }
			if (this->morePlayer == true) {
				if (Player2::y == Level::getHeight() / 2 && Player2::x == Level::getWidth()) { this->gameWin = true; this->level++; }
			}

			if (gameOver == true) {break;}
		}
		if (gameOver == true){break;}
		else { this->restartW(); }
	}

}




void GAME::action()
{

	switch (Player1::control)
	{
	case  Player1::nav::LEFT: if (Level::getSpace(Player1::x - 1, Player1::y) != Level::wall) { Player1::x--; }; Player1::control = nav::STOP; break;
	case  Player1::nav::RIGHT:if (Level::getSpace(Player1::x + 1, Player1::y) != Level::wall) { Player1::x++; }; Player1::control = nav::STOP; break;
	case  Player1::nav::UP:   if (Level::getSpace(Player1::x, Player1::y - 1) != Level::wall) { Player1::y--; }; Player1::control = nav::STOP; break;
	case  Player1::nav::DOWN: if (Level::getSpace(Player1::x, Player1::y + 1) != Level::wall) { Player1::y++; }; Player1::control = nav::STOP; break;
	default:break;
	}
	this->Level::setSpace(Player1::x, Player1::y, Player1::charakter);

	if (this->morePlayer == true) {
		switch (Player2::control)
		{
		case  Player2::nav::LEFT: if (Level::getSpace(Player2::x - 1, Player2::y) != Level::wall) { Player2::x--; }; Player2::control = nav::STOP; break;
		case  Player2::nav::RIGHT:if (Level::getSpace(Player2::x + 1, Player2::y) != Level::wall) { Player2::x++; }; Player2::control = nav::STOP; break;
		case  Player2::nav::UP:   if (Level::getSpace(Player2::x, Player2::y - 1) != Level::wall) { Player2::y--; }; Player2::control = nav::STOP; break;
		case  Player2::nav::DOWN: if (Level::getSpace(Player2::x, Player2::y + 1) != Level::wall) { Player2::y++; }; Player2::control = nav::STOP; break;
		default:break;
		}
		this->Level::setSpace(Player2::x, Player2::y, Player2::charakter);
	}
}
void GAME::input() {
	if (_kbhit())
	{
		char input = _getch();

		//Player 1:
		// 
		//UP
		if (input == Player1::getConUp()) {
			Player1::control = Player1::nav::UP;
			this->Load();
		}


		//DOWN
		if (input == Player1::getConDown()) {
			Player1::control = Player1::nav::DOWN;
			this->Load();
		}


		// LEFT
		if (input == Player1::getConLeft()) {
			Player1::control = Player1::nav::LEFT;
			this->Load();
		}



		//RIGHT
		if (input == Player1::getConRight()) {
			Player1::control = Player1::nav::RIGHT;
			this->Load();

		}


		if (this->morePlayer == true) {

			// PLAYER 2

			//UP
			if (input == Player2::getConUp()) {
				Player2::control = Player2::nav::UP;
				this->Load();
			}

			//LEFT
			if (input == Player2::getConLeft()) {
				Player2::control = Player2::nav::LEFT;
				this->Load();
			}

			//DOWN
			if (input == Player2::getConDown()) {
				Player2::control = Player2::nav::DOWN;
				this->Load();
			}

			//RIGHT
			if (input == Player2::getConRight()) {
				Player2::control = Player2::nav::RIGHT;
				this->Load();

			}
		}


		if (input == 'q') {
			this->gameOver = true;
			
		}
	}
}
void GAME::Load() {
	system("cls");
	Level::LevelMenu(this->level);
	this->action();
	Level::printField();
}


// SETTINGS
void GAME::Settings(char input)
{
	switch (input) {
		case 'a':Player1::setControl(1); break;
		case 'b':Player1::setCharacter(1); break;
		case 'c':Player2::setControl(2); break;
		case 'd':Player2::setCharacter(2); break;
		case 'e':Level::setHeight(0); break;
		case 'f':Level::setWidth(0); break;
	}
}