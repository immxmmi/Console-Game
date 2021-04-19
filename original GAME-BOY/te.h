#pragma once
#include "Field.h"
class te : Field
{

private:
protected:
public:
	void test() {
		this->drawField();
		this->setWidth(20);
		this->setHeight(10);
		this->field[15][5]= 'D';
		this->printField();
	}
};

