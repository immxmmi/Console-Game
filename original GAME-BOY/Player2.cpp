#include "Player2.h"

Player2::Player2()
{
		this->setConUp(true, 'i');
		this->setConDown(true, 'k');
		this->setConLeft(true, 'j');
		this->setConRight(true, 'l');
}

void Player2::defaultSetting()
{
	this->setConUp(true, 'i');
	this->setConDown(true, 'k');
	this->setConLeft(true, 'j');
	this->setConRight(true, 'l');
}
