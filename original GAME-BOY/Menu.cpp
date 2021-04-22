#include "Menu.h"
#include "Player.h"
#include "Player2.h"
#include "Player1.h"
#include "GAME.h"
#include <iostream>


GAME game;

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
	std::cout << "					**    Player1:                     **" << std::endl;
	std::cout << "					**    a ................ CONTROL   **" << std::endl;
	std::cout << "					**    b ................ CHARAKTER **" << std::endl;
	std::cout << "					**                                 **" << std::endl;
	std::cout << "					**    Player2:                     **" << std::endl;
	std::cout << "					**    c ................ CONTROL   **" << std::endl;
	std::cout << "					**    d ................ CHARAKTER **" << std::endl;
	std::cout << "					**                                 **" << std::endl;
	std::cout << "					**    WINDOW:                      **" << std::endl;
	std::cout << "					**    e ................  HEIGHT   **" << std::endl;
	std::cout << "					**    f .................  WIDTH   **" << std::endl;
	std::cout << "					**                                 **" << std::endl;
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
	} while (input != 'a' && input != 'b' && input != 'c' && input != 'd' && input != 'e' && input != 'f' && input != 'q');
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
		case 'a': {game.Settings(input); break; }
		case 'b': {game.Settings(input); break; }
		case 'c': {game.Settings(input); break; }
		case 'd': {game.Settings(input); break; }
		case 'e': {game.Settings(input); break; }
		case 'f': {game.Settings(input); break; }
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
		case 'p': {game.start(); break; }
		case 'e': {game.Settings('c'); break; }
		case 'i': {game.start(); break; }
		case 's': {settingMenu(); system("cls"); break; }
		}

	} while (input != 'q');




}
//#######################################