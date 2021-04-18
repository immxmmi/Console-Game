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

void Player::setControl()
{
	char Key;
	
	this->print_controlMenu();
	
	do{
	std::cin >> Key;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	if (Key != this->getConUp() || Key != this->getConDown() || Key != this->getConLeft() || Key != this->getConRight() || Key != 'q') {
		std::cout << "Wrong" << std::endl;
	}
	
	if (Key == this->getConUp()) {
		std::cout << std::endl;
		std::cout << "Press new UP:  ";
		this->setConUp();
		this->print_controlMenu();

	}


	if (Key == this->getConDown()) {
		std::cout << std::endl;
		std::cout << "Press new DOWN:  ";
		this->setConDown();
		this->print_controlMenu();
	}

	if (Key == this->getConLeft()) {
		std::cout << std::endl;
		std::cout << "Press new LEFT:  ";
		this->setConLeft();
		this->print_controlMenu();
	}

	if (Key == this->getConRight()) {
		std::cout << std::endl;
		std::cout << "Press new RIGHT:  ";
		this->setConRight();
		this->print_controlMenu();
	}

	} while ( Key != 'q');

}


// GET 
//##NAV
char Player::getConUp()
{
	return this->cont_up;
}
char Player::getConRight()
{
	return this->cont_right;
}
char Player::getConDown()
{
	return this->cont_down;
}
char Player::getConLeft()
{
	return this->cont_left;
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
void Player::print_controlMenu() {
	system("cls");
	std::cout << std::endl << std::endl << std::endl;
	std::cout << std::endl << std::endl << std::endl;
	std::cout << "					************************************" << std::endl;
	std::cout << "					**             CONTROL            **" << std::endl;
	std::cout << "					************************************" << std::endl;
	std::cout << "					**                                **" << std::endl;
	std::cout << "					**       UP:              " << this->getConUp() << "       **" << std::endl;
	std::cout << "					**       DOWN:            " << this->getConDown() << "       **" << std::endl;
	std::cout << "					**       LEFT:            " << this->getConLeft() << "       **" << std::endl;
	std::cout << "					**       RIGHT:           " << this->getConRight() <<"       **" << std::endl;
	std::cout << "					**                                **" << std::endl;
	std::cout << "					**       QUIT:            q       **" << std::endl;
	std::cout << "					**                                **" << std::endl;
	std::cout << "					************************************" << std::endl;
	std::cout << "					*                Momo              *" << std::endl;
	std::cout << "					************************************" << std::endl;
}


void Player::setConUp() {
	char input;

	do {
	std::cin >> input;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (input == 'q') { std::cout << "TRY AGAIN" << std::endl; }

	} while (input == 'q');
	this->cont_up = input;
}
void Player::setConDown() {
	char input;

	do {
		std::cin >> input;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (input == 'q') { std::cout << "TRY AGAIN" << std::endl; }

	} while (input == 'q');
	this->cont_down = input;
}
void Player::setConRight() {
	char input;

	do {
		std::cin >> input;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (input == 'q') { std::cout << "TRY AGAIN" << std::endl; }

	} while (input == 'q');
	this->cont_right = input;
}
void Player::setConLeft() {
	char input;

	do {
		std::cin >> input;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (input == 'q') { std::cout << "TRY AGAIN" << std::endl; }

	} while (input == 'q');
	this->cont_left = input;
}
