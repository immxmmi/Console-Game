#include "Menu.h"
#include "Player.h"
#include <iostream>


Player player;

//PRINT  MENU############################
void Menu::print_Menu()
{
	std::cout << std::endl << std::endl << std::endl;
	std::cout << std::endl << std::endl << std::endl;
	std::cout << "					************************************" << std::endl;
	std::cout << "					*            GAME-MENU             *" << std::endl;
	std::cout << "					************************************" << std::endl;
	std::cout << "					**                                **" << std::endl;
	std::cout << "					**    p .............. 1-PLAYER   **" << std::endl;
	std::cout << "					**    e .............. 2-PLAYER   **" << std::endl;
	std::cout << "					**    s ............... SETTING   **" << std::endl;
	std::cout << "					**    i .................. INFO   **" << std::endl;
	std::cout << "					**    q .................. QUIT   **" << std::endl;
	std::cout << "					**                                **" << std::endl;
	std::cout << "					************************************" << std::endl;
	std::cout << "					*              Momo                *" << std::endl;
	std::cout << "					************************************" << std::endl;
}
void Menu::print_settingMenu()
{
	std::cout << std::endl << std::endl << std::endl;
	std::cout << std::endl << std::endl << std::endl;
	std::cout << "					*************************************" << std::endl;
	std::cout << "					**             SETTING             **" << std::endl;
	std::cout << "					*************************************" << std::endl;
	std::cout << "					**                                 **" << std::endl;
	std::cout << "					**    c ................ CONTROL   **" << std::endl;
	std::cout << "					**    h ................  HEIGHT   **" << std::endl;
	std::cout << "					**    w .................  WIDTH   **" << std::endl;
	std::cout << "					**    q ..................  BACK   **" << std::endl;
	std::cout << "					**                                 **" << std::endl;
	std::cout << "					*************************************" << std::endl;
	std::cout << "					*              Momo                 *" << std::endl;
	std::cout << "					*************************************" << std::endl;
}
//#######################################

//INPUT##################################
char Menu::getSettingInput() {
	char input = 'A';
	do {
		std::cin >> input;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (input != 'h' && input != 'w' && input != 'c' && input != 'q');
	return input;
}
char Menu::getMenuInput() {
	char input = 'A';
	do {
		std::cin >> input;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (input != 'p' && input != 'e' && input != 's' && input != 'i' && input != 'q');
	return input;
}
//#######################################

//MENU ##################################
void Menu::settingMenu() {
	char input;
	do {
		system("cls");
		this->print_settingMenu();
		input = this->getSettingInput();
		switch (input) {
		case 'c': {player.setControl(); break; }
		case 'h': {player.setHeight2(); break; }
		case 'w': {player.setWidth2(); break; }
		}



	} while (input != 'q');

}
void Menu::menu()
{
	char input = '#';

	do {
		print_Menu();
		input = getMenuInput();
		system("cls");

		switch (input) {
		case 'p': {player.start(); break; }
		case 'e': { player.start(); break; }
		case 'i': {std::cout << "press: i" << std::endl; break; }
		case 's': {settingMenu(); system("cls"); break; }
		}

	} while (input != 'q');




}
//#######################################