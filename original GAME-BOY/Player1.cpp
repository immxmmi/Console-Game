#include "Player1.h"

Player1::Player1() {
	this->setConDown(true, 's');
	this->setConLeft(true, 'a');
	this->setConRight(true, 'd');
	this->setConUp(true, 'w');
}

void Player1::defaultSetting()
{
	this->setConDown(true, 's');
	this->setConLeft(true, 'a');
	this->setConRight(true, 'd');
	this->setConUp(true, 'w');
}
