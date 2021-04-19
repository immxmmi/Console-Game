#include "Level.h"

void Level::Wall(int index, int index2, int space, int limit)
{		
			for (int i = 0; i < limit; i++) {
				for (int y = this->getHeight() - 1; y > this->getY_edge() + 1; y--)
					for (int x = this->getX_edge() + index; x < this->getX_edge() + index2; x++) {
						this->setSpace(x, y, this->wall);
					}
		
				index += space;
				index2 += space;
		
		
				for (int y = this->getHeight() - 2; y > this->getY_edge(); y--)
					for (int x = this->getX_edge() + index; x < this->getX_edge() + index2; x++) {
						this->setSpace(x, y, this->wall);
					}
				index += space;
				index2 += space;
			}
		}
