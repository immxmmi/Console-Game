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

void Level::LevelMenu(int level)
{
	switch (level)
	{
	case 1: Level1(); break;
	case 2: Level2(); break;
	case 3: Level3(); break;
	case 4: Level4(); break;
	default:
		break;
	}
}

void Level::Level1()
{
	setWidth(10);
	setHeight(10);
}

void Level::Level2()
{
	setWidth(20);
	setHeight(20);
}

void Level::Level3()
{
	setWidth(30);
	setHeight(30);
}

void Level::Level4()
{
	setWidth(24);
	setHeight(25);
}
