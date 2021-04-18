#include "Player.h"



Player::Player() {

	this->Name = "TEST";
	this->players = false;
	this->charakter = 'X';
	this->level = 0;
	this->life = 0;
	this->x = field->getX_edge();
	this->y = field->getHeight() - 1;
	this->score = 0;
	this->scoreLimit = 200;
	this->gameOver = false;

}


void Player::action()
{
	switch (this->control)
	{
	case LEFT: if (this->x > field->getX_edge()) { this->x--; }; control = STOP; break;
	case RIGHT: if (this->x < field->getWidth() - 1) { this->x++; } control = STOP; break;
	case UP: if (this->y > field->getY_edge() + 1)this->y--; control = STOP; break;
	case DOWN: if (this->y < field->getHeight() - 1)this->y++; control = STOP; break;
	default:break;
	}
	field->field[20][60] = '#';


	if (field->field[this->y][this->x] != '#') {
		field->field[this->y][this->x] = this->charakter;
	}

}



void Player::printField() {
	for (int y = 0; y <= field->getHeight(); y++) {
		for (int x = 0; x <= field->getWidth(); x++) {
			std::cout << field->field[y][x];
		}
		std::cout << std::endl;
	}
}

void Player::input() {
	if (_kbhit()) // drücken einer Taste
	{
		switch (_getch())
		{
		case 'a': this->control = LEFT; break;
		case 'd': this->control = RIGHT; break;
		case 'w': this->control = UP; break;
		case 's': this->control = DOWN; break;
			//case 'x': currentPlayer->gameOver = true; break;
		}
	}
}


void Player::test()
{
	while (true) {

		field->drawField();
		this->input();
		system("cls");
		this->action();
		printField();
	}
}
