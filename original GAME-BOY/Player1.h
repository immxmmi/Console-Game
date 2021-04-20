#pragma once
#include "Player.h"
class Player1 : public Player
{
private:
public:
	void test2() {
		this->Settings('c');
	}
	void print_characterMenu2()
	{
		char Charakter1 = 176;
		char Charakter2 = 219;
		char Charakter3 = 178;
		char Charakter4 = 177;
		char Charakter5 = 245;
		char Charakter6 = 184;
		char Charakter7 = 169;

		std::cout << std::endl << std::endl << std::endl;
		std::cout << std::endl << std::endl << std::endl;
		std::cout << "					*************************************" << std::endl;
		std::cout << "					**           CHARAKTER 2           **" << std::endl;
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


};

