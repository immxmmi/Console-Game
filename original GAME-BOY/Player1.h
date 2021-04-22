#pragma once
#include "Player.h"
class Player1 : public Player
{
	private:
	public:
		//Default
		Player1() {
			this->rest();
	
			this->setConDown(true,'s');
			this->setConLeft(true, 'a');
			this->setConRight(true,'d');
			this->setConUp(true, 'w');
		}



};

