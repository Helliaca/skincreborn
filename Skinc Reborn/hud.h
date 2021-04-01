#pragma once

#include "valueBar.h"
#include "global_values.h"
#include <iostream>

class hud
{
public:
	hud(sf::RenderWindow &window, int maxhealth, int maxEhealth, map overlay);
	~hud(void);
	void update(sf::Vector2f viewPos, sf::RenderWindow &window);
	//health/mana/strength bars:
	valueBar strength;
	valueBar mana;
	valueBar health;
	valueBar enemyhealth;
	//COOLDOWNS
	valueBar atc_cd;
	valueBar nuke_cd;
	valueBar ce_cd;
private:
	sf::Texture hudtexture;
	sf::Sprite hud_overlay;
	sf::Texture hudundertexture;
	sf::Sprite hud_underlay;
};

