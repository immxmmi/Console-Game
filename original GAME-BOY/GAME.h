#pragma once
#include "Player1.h"
#include "Player2.h"
#include "Level.h"
class GAME : Level, Player1, Player2
{
private:

	//GAME
	bool gameOver;
	bool gameWin;
	bool morePlayer;
	
	//ACTION
	void Load();
	void input();
	void action();

	//LEVEL
	void Level(int level);
	int level;
	

public:

	//GENERAL
	GAME();

	//GAME START
	void start(bool morePlayer);

	//SETTINGS
	void Settings(char input);









};

