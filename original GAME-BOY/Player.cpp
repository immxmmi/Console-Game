#include "Player.h"

Player::Player() {
	this->rest();
	this->cont_down  = 's';
	this->cont_up    = 'w';
	this->cont_right = 'd';
	this->cont_left  = 'a';
}
void Player::rest() {
	this->charakter = (char)176;
	this->level = 0;
	this->life = 0;
	//this->x = this->getX_edge();
	//this->y = this->getHeight() - 1;
	this->x = 0;
	this->y = 0;
	this->gameOver = false;
}




void Player::input() {
	if (_kbhit())
	{
		char input = _getch();
		if (input == this->cont_left) {
			this->control = nav::LEFT;
			//this->Load();
		}
		if (input == this->cont_right) {
			this->control = nav::RIGHT;
			//this->Load();

		}
		if (input == this->cont_up) {
			this->control = nav::UP;
			//this->Load();
		}
		if (input == this->cont_down) {
			this->control = nav::DOWN;
			//this->Load();
		}
		if (input == 'q') {
			this->gameOver = true;
		}
	}
}











//##################### Charakter #######################\\

// SETTER (character)
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


//###################### Control #######################\\

// GETTER(Control)
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


// SETTER (Control)
void Player::setControl(int player)
{
	char Key;
	this->print_controlMenu(player);
	do {
		std::cin >> Key;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (Key != this->getConUp() && Key != this->getConDown() && Key != this->getConLeft() && Key != this->getConRight() && Key != 'q') {
			std::cout << "ERROR: Wrong Key -> Try again!" << std::endl;
		}
		if (Key == this->getConUp()) {
			std::cout << std::endl;
			std::cout << "Press new UP:  ";
			this->setConUp(false , 'a');
			this->print_controlMenu(player);
		}
		if (Key == this->getConDown()) {
			std::cout << std::endl;
			std::cout << "Press new DOWN:  ";
			this->setConDown(false, 'a');
			this->print_controlMenu(player);
		}
		if (Key == this->getConLeft()) {
			std::cout << std::endl;
			std::cout << "Press new LEFT:  ";
			this->setConLeft(false, 'a');
			this->print_controlMenu(player);
		}
		if (Key == this->getConRight()) {
			std::cout << std::endl;
			std::cout << "Press new RIGHT:  ";
			this->setConRight(false, 'a');
			this->print_controlMenu(player);
		}
	} while (Key != 'q');

}
void Player::setConUp(bool defaultSetting,char key) {
	char input;

	if (defaultSetting == false) {
		do {
			std::cin >> input;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (input == 'q' || input == this->getConDown() || input == this->getConLeft() || input == this->getConRight()) { std::cout << "TRY AGAIN" << std::endl; }

		} while (input == 'q' || input == this->getConDown() || input == this->getConLeft() || input == this->getConRight());
		this->cont_up = input;
	}else(this->cont_up = key);
}
void Player::setConDown(bool defaultSetting, char key) {
	char input;
	if (defaultSetting == false) {
	do {
		std::cin >> input;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (input == 'q' || input == this->getConUp() || input == this->getConLeft() || input == this->getConRight()) { std::cout << "TRY AGAIN" << std::endl; }

	} while (input == 'q' || input == this->getConUp() || input == this->getConLeft() || input == this->getConRight());
	this->cont_down = input;
	}
	else(this->cont_up = key);
}
void Player::setConRight(bool defaultSetting, char key) {
	char input;
	if (defaultSetting == false) {
	do {
		std::cin >> input;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (input == 'q' || input == this->getConDown() || input == this->getConLeft() || input == this->getConUp()) { std::cout << "TRY AGAIN" << std::endl; }

	} while (input == 'q' || input == this->getConDown() || input == this->getConLeft() || input == this->getConUp());
	this->cont_right = input;
	}
	else(this->cont_up = key);
}
void Player::setConLeft(bool defaultSetting, char key) {
	char input;
	if (defaultSetting == false) {
	do {
		std::cin >> input;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (input == 'q' || input == this->getConDown() || input == this->getConUp() || input == this->getConRight()) { std::cout << "TRY AGAIN" << std::endl; }

	} while (input == 'q' || input == this->getConDown() || input == this->getConUp() || input == this->getConRight());
	this->cont_left = input;
	}
	else(this->cont_up = key);
}


//PRINTER(Menu)
void Player::print_controlMenu(int player) {
	system("cls");
	std::cout << std::endl << std::endl << std::endl;
	std::cout << std::endl << std::endl << std::endl;
	std::cout << "					************************************" << std::endl;
	std::cout << "					**             CONTROL  "<< player << "         **" << std::endl;
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
	std::cout << "					**               Momo             **" << std::endl;
	std::cout << "					************************************" << std::endl;
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
	std::cout << "					**           CHARAKTER " << player << "          **" << std::endl;
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

