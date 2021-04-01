#pragma once
#include "terrain.h"
#include <SFML/Audio.hpp>


class bot
{
public:
	bot(float x, float y, difficulty diff, botskintype skin);
	~bot(void);
	void react(sf::Vector2f playerPos, sf::Vector2f PlmousePos, terrain &terrain, bool playerFiring);
	void update(sf::RenderWindow &window, terrain &terrain);
	void draw(sf::RenderWindow &window);
	float getX() {return position.x;}
	float getY() {return position.y;}
	sf::Vector2f getPos() {return position;}
	sf::Vector2f getaim() {return aimPos;}
	void setVX(float arg) {velocity.x=arg*frametime;}
	void setVY(float arg) {velocity.y=arg*frametime;}
	bool collideBot(terrain &terrain);
	bool collideTop(terrain &terrain);
	bool collideLeft(terrain &terrain);
	bool collideRight(terrain &terrain);
	void setFrametime(float arg) {frametime=arg;}
	void setFiring(bool arg) {firing=arg;}
	bool getFiring() {return firing;}
	state getstate() {return currentstate;}
	void increasemana(float delta) {mana+=delta;}
	void sethealth(float hp) {health=hp;}
	void setspeed(int speed) {bSpeed=speed;}
	void setmaxhealth(float maxhp) {maxhealth=maxhp;}
	void setshield(bool shield) {this->shield=shield;}
	bool getshield() {return shield;}
	void say(taunttype situation);
	void say(sf::String text);
	void defeated(sf::RenderWindow &window, sf::Vector2f viewPosition);
	void cheatsinactive() {currentcheat=INACTIVE;}
	void loadTauntProfile(botskintype profile);
	void loadDifficultyProfile(difficulty dif);
	cheats getcheat() {return currentcheat;}
	void setspawn(float x, float y) {position.x=x; position.y=y;}
private:
	sf::Clock reacttimer;
	sf::Clock actiontimer;
	sf::Clock cloaktimer;
	float reactiontime;
	float actiontime;
	float health, mana, maxhealth;
	int bSpeed;
	state currentstate;
	bool firing;
	bool shield;
	float frametime;
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Vector2f aimPos;
	sf::Texture botTexture;
	sf::Sprite botSprite;
	sf::Vector2i spritePos;

	sf::Texture shieldTexture;
	sf::Sprite shieldSprite;

	sf::Clock taunttimer;
	sf::Text taunt;
	sf::Texture speechbubbletexture;
	sf::Sprite speechbubble;
	bool taunting;
	sf::Font speechbubblefont;

	difficulty diff;

	cheats currentcheat;

	sf::SoundBuffer cloakbuffer;
	sf::Sound cloak;
	sf::SoundBuffer ssaiyanbuffer;
	sf::Sound ssaiyan;

	std::string taunt_fight_List[fighttauntsize];
	std::string taunt_start_List[starttauntsize];
	std::string taunt_defeat_List[defeattauntsize];

	int cone;
	float safe;
	float highrisk;
	int shootmana;
	int stockmana;
	float aimspeed;
};

