#pragma once

#include "terrain.h"
#include <math.h>
#include "global_values.h"

class weapon
{
public:
	weapon(bool player);
	~weapon(void);
	bool fire(terrain &terrain, sf::Vector2f &playerPos, sf::Vector2f &mousePos, sf::RenderWindow &window, sf::Vector2f enemyPos);
	void setfirepower(float arg); //Note Firepower and damage/tick etc. work with specific formulas. Check at the bottom of Engine.cpp for a table.
private:
	sf::Texture crittexture;
	sf::Texture beamtexture;
	sf::Sprite beam;
	float firepower;
};

