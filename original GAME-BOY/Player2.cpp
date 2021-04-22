#include "Player2.h"

Player2::Player2()
{
	this->defaultSetting();
}

void Player2::defaultSetting()
{


	this->setConLeft(true, 'j');
	this->setConRight(true, 'l');
	this->setConDown(true, 'k');
	this->setConUp(true, 'i');
}
