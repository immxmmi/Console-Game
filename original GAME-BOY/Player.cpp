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
	case LEFT: if (this->x > field->getX_edge()) { 
		
		

		
		this->x--; }; control = STOP; break;







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
void Player::input() {
	if (_kbhit())
	{
		char input = _getch();
		if (input == this->cont_left) {
			this->control = LEFT;
			this->Load();
		}
		if (input == this->cont_right) {
			this->control = RIGHT;
			this->Load();

		}
		if (input == this->cont_up) {
			this->control = UP;
			this->Load();
		}
		if (input == this->cont_down) {
			this->control = DOWN;
			this->Load();
		}
		if (input == 'q') {
			this->gameOver = true;
		}
	}
}

void Player::test()
{
	this->Load();
	while (this->gameOver != true) {
		this->input();

	}

	this->gameOver = false;
	system("cls");
}
void Player::printField() {
	for (int y = 0; y <= field->getHeight(); y++) {
		for (int x = 0; x <= field->getWidth(); x++) {
			std::cout << field->field[y][x];
		}
		std::cout << std::endl;
	}
}

void Player::Load()
{
	system("cls");
	field->drawField();
	this->action();
	printField();
}








//###################### Control #######################\\

// GETTER
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

// SETTER
void Player::setControl()
{
	char Key;
	this->print_controlMenu();
	do {
		std::cin >> Key;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (Key != this->getConUp() && Key != this->getConDown() && Key != this->getConLeft() && Key != this->getConRight() && Key != 'q') {
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
	} while (Key != 'q');

}

void Player::setConUp() {
	char input;

	do {
	std::cin >> input;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (input == 'q' || input == this->getConDown() || input == this->getConLeft() || input == this->getConRight()) { std::cout << "TRY AGAIN" << std::endl; }

	} while (input == 'q' || input == this->getConDown() || input == this->getConLeft() || input == this->getConRight());
	this->cont_up = input;
}
void Player::setConDown() {
	char input;

	do {
		std::cin >> input;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (input == 'q' || input == this->getConUp() || input == this->getConLeft() || input == this->getConRight()) { std::cout << "TRY AGAIN" << std::endl; }

	} while (input == 'q' || input == this->getConUp() || input == this->getConLeft() || input == this->getConRight());
	this->cont_down = input;
}
void Player::setConRight() {
	char input;

	do {
		std::cin >> input;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (input == 'q' || input == this->getConDown() || input == this->getConLeft() || input == this->getConUp()) { std::cout << "TRY AGAIN" << std::endl; }

	} while (input == 'q' || input == this->getConDown() || input == this->getConLeft() || input == this->getConUp());
	this->cont_right = input;
}
void Player::setConLeft() {
	char input;

	do {
		std::cin >> input;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (input == 'q' || input == this->getConDown() || input == this->getConUp() || input == this->getConRight()) { std::cout << "TRY AGAIN" << std::endl; }

	} while (input == 'q' || input == this->getConDown() || input == this->getConUp() || input == this->getConRight());
	this->cont_left = input;
}

// PRINT
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
	std::cout << "					**       RIGHT:           " << this->getConRight() << "       **" << std::endl;
	std::cout << "					**                                **" << std::endl;
	std::cout << "					**       QUIT:            q       **" << std::endl;
	std::cout << "					**                                **" << std::endl;
	std::cout << "					************************************" << std::endl;
	std::cout << "					*                Momo              *" << std::endl;
	std::cout << "					************************************" << std::endl;
}
