#pragma once
#include <assert.h>
#include "Field.h"
#include "Menu.h"
#include "Player.h"
#include "GAME.h"

class Test: public Field, public Level, public Menu, public Player, public GAME
{
};

