#pragma once

#include "player.h"
#include "bot.h"
#include "terrain.h"
#include "global_values.h"
#include "weapon.h"
#include "hud.h"
#include "soundManager.h"
#include "nuke.h"
#include <SFML/Graphics.hpp>


class Engine
{
public:
	Engine(map scenario, int speed, int firepower, int health, int bothealth, int botspeed, int botfirepower, skintype skin, botskintype botskin, difficulty gamedif, bool spell1, bool spell2, bool spell3);
	~Engine(void);
	int GameLoop();
	int TutorialLoop();
private:
	float frametime;
	sf::RenderWindow window;
	soundManager soundmanager;
	player player;
	weapon botweapon;
	weapon weapon;
	//nuke botnuke; changed: bot doesnt use nukes anymore.
	nuke nuke;
	bot bot;
	terrain terrain;
	sf::Clock clock;
	sf::Event event;
	sf::View view;
	sf::Vector2f viewPosition;
	hud hud;
	int pSpeed, pDmg, pHp; //player-stats
	int bDmg;
	//Cooldowns:
	sf::Clock atc_cdt;
	sf::Clock nuke_cdt;
	sf::Clock ce_cdt;
	sf::Clock taunt_cdt;
	//Variables to process whether if the bot got stuck in the terrain(not AI-dependant):
	sf::Vector2f botPrevPos;
	int movchange;
	//TutorialLoop variables:
	tutorialsteps tutStep;
	sf::Texture bwTexture;
	sf::Sprite bwSprite;
	sf::Font tutorialfont;
	sf::Text tut;
	//available spells:
	bool l_nuke, l_createearth, l_fly;
};

