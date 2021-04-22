#pragma once
#include "Player.h"
class Player2 : public Player
{
private:



public:
	Player2() {
		this->rest();
		this->setConUp(true, 'i');
		this->setConDown(true, 'k');
		this->setConLeft(true, 'j');
		this->setConRight(true, 'l');
	}

	



};

