#pragma once
#include "Field.h"
class Level : public Field
{
private:
protected:
public:

	void Wall(int index, int index2, int space, int limit);
	void LevelMenu(int level);
	void Level1();
	void Level2();
	void Level3();
	void Level4();
};

