#include "GAME.h"


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