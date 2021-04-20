#include "Player.h"

Player::Player() {

	this->Name = "TEST";
	this->players = false;
	this->charakter = (char)176;
	this->level = 0;
	this->life = 0;
	this->x = this->getX_edge();
	this->y = this->getHeight() - 1;
	this->score = 0;
	this->scoreLimit = 200;
	this->gameOver  = false;
	this->cont_down  = 's';
	this->cont_up    = 'w';
	this->cont_right = 'd';
	this->cont_left  = 'a';
}
void Player::action()
{
	switch (this->control)
	{
	case nav::LEFT:if (this->getSpace(this->x - 1, this->y) != this->wall) { this->x--; }; control =  nav::STOP; break;
	case nav::RIGHT:if (this->getSpace(this->x + 1, this->y) != this->wall) { this->x++; }; control = nav::STOP; break;
	case nav::UP:if (this->getSpace(this->x, this->y - 1) != this->wall) { this->y--; }; control =	  nav::STOP; break;
	case nav::DOWN:if (this->getSpace(this->x, this->y + 1) != this->wall) { this->y++; }; control =  nav::STOP; break;
		default:break;
	}
	this->setSpace(this->x, this->y, this->charakter);
	//if (this->y == this->getHeight() / 2 && this->x == this->getWidth()) { this->gameOver == true; }
}
void Player::input() {
	if (_kbhit())
	{
		char input = _getch();
		if (input == this->cont_left) {
			this->control = nav::LEFT;
			this->Load();
		}
		if (input == this->cont_right) {
			this->control = nav::RIGHT;
			this->Load();

		}
		if (input == this->cont_up) {
			this->control = nav::UP;
			this->Load();
		}
		if (input == this->cont_down) {
			this->control = nav::DOWN;
			this->Load();
		}
		if (input == 'q') {
			this->gameOver = true;
		}
	}
}
void Player::start()
{
	setCharacter(1);
	this->Load();
	while (this->gameOver != true) {
		this->input();
		if (this->y == this->getHeight() / 2 && this->x == this->getWidth()) { this->gameOver = true; }
	}
	this->gameOver = false;
	system("cls");
}
void Player::Load()
{

		system("cls");
		this->drawField();
		//this->Wall(1,2,4,1);
		this->LevelMenu(1);

		this->action();
		this->printField(); 
	
}
void Player::Settings(char input) 
{
	switch (input) {
		case 'h':this->setHeight(0); break;
		case 'w':this->setWidth(0); break;
		case 'c':this->setControl(); break;
		case 'p':this->setCharacter(1); break;
	}
}


//##################### Charakter #######################\\

void Player::setCharacter(int player){
	char Charakter1 = (char)176;
	char Charakter2 = (char)219;
	char Charakter3 = (char)178;
	char Charakter4 = (char)177;
	char Charakter5 = (char)245;
	char Charakter6 = (char)184;
	char Charakter7 = (char)169;
	char input = 'w';


	do {
		system("cls");
		this->print_characterMenu(player);
		std::cin >> input;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		switch (input)
		{
		case 'a': 	this->charakter = Charakter1; break;
		case 'b': 	this->charakter = Charakter2; break;
		case 'c': 	this->charakter = Charakter3; break;
		case 'd': 	this->charakter = Charakter4; break;
		case 'e': 	this->charakter = Charakter5; break;
		case 'f': 	this->charakter = Charakter6; break;
		case 'g': 	this->charakter = Charakter7; break;
		default: break;
		}
	} while (input != 'a' && input != 'b' && input != 'c' && input != 'd' && input != 'e' && input != 'f' && input != 'g' && input != 'q');

}
void Player::print_characterMenu(int player)
{
	char Charakter1 = (char)176;
	char Charakter2 = (char)219;
	char Charakter3 = (char)178;
	char Charakter4 = (char)177;
	char Charakter5 = (char)245;
	char Charakter6 = (char)184;
	char Charakter7 = (char)169;

	std::cout << std::endl << std::endl << std::endl;
	std::cout << std::endl << std::endl << std::endl;
	std::cout << "					*************************************" << std::endl;
	std::cout << "					**           CHARAKTER "<< player << "          **" << std::endl;
	std::cout << "					*************************************" << std::endl;
	std::cout << "					**                                 **" << std::endl;
	std::cout << "					**       a ............... " << Charakter1 << "       **" << std::endl;
	std::cout << "					**       b ............... " << Charakter2 << "       **" << std::endl;
	std::cout << "					**       c ............... " << Charakter3 << "       **" << std::endl;
	std::cout << "					**       d ............... " << Charakter4 << "       **" << std::endl;
	std::cout << "					**       e ............... " << Charakter5 << "       **" << std::endl;
	std::cout << "					**       f ............... " << Charakter6 << "       **" << std::endl;
	std::cout << "					**       g ............... " << Charakter7 << "       **" << std::endl;
	std::cout << "					**                                 **" << std::endl;
	std::cout << "					*************************************" << std::endl;
	std::cout << "					*              Momo                 *" << std::endl;
	std::cout << "					*************************************" << std::endl;
	std::cout << std::endl << std::endl;
	std::cout << "Character:  ";
};

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

