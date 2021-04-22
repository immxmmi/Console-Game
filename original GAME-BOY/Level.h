#pragma once
#include "Field.h"
class Level : public Field
{
private:
	int limit = 0;
	int space = 0;
	int index = 0;
	int index2 = 0;

	
protected:
public:

	bool levelStart = true;

	void Wall(int index, int index2, int space, int limit);
	void LevelMenu(int level);
	void DrawLevel(int level);
	void Level1();
	void Level2();
	void Level3();
	void Level4();

	int randGen2000(int max);
};

