#pragma once
#include "Field.h"
class te : Field
{

private:
protected:
public:
	

	void Mauer(int index, int index2, int space, int limit) {

		for (int i = 0; i < limit; i++) {
			for (int y = this->getHeight() - 1; y > this->getY_edge() + 1; y--)
				for (int x = this->getX_edge() + index; x < getX_edge() + index2; x++) {
					setSpace(x, y, '#');
				}

			index += space;
			index2 += space;


			for (int y = this->getHeight() - 2; y > this->getY_edge(); y--)
				for (int x = this->getX_edge() + index; x < getX_edge() + index2; x++) {
					setSpace(x, y, '#');
				}
			index += space;
			index2 += space;
		}
	}
	

	void test() {


		this->setWidth(50);
		this->setHeight(20);

		this->drawField();

		
			this->Mauer(3, 5, 6 , 3);

		this->printField();
	}

};


