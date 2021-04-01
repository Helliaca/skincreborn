#pragma once

#include "terrain.h"
#include "global_values.h"

class nuke
{
public:
	nuke(bool player);
	~nuke(void);
	bool update(terrain &terrain, sf::RenderWindow &window, sf::Vector2f enemyPos);
	void setframetime(float arg) {frametime=arg;}
	void spawnnuke(sf::Vector2f position, sf::Vector2f aimPos);
	bool getactive(){return active;}
private:
	bool active;
	sf::Vector2f position;
	sf::Vector2f speed;
	sf::Texture nuketexture;
	sf::Sprite nukesprite;
	float frametime;
};

