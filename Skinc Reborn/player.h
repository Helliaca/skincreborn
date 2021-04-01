#pragma once

#include <SFML/Graphics.hpp>
#include "terrain.h"
#include "global_values.h"

class player
{
public:
	player(float x, float y, skintype skin);
	~player(void);
	void setshield(bool shield);
	bool getshield() {return shield;}
	void update(sf::RenderWindow &window, terrain &terrain);
	void draw(sf::RenderWindow &window);
	float getX() {return position.x;}
	float getY() {return position.y;}
	sf::Vector2f getPos() {return position;}
	void setVX(float arg) {velocity.x=arg*frametime;}
	void setVY(float arg) {velocity.y=arg*frametime;}
	bool collideBot(terrain &terrain);
	bool collideTop(terrain &terrain);
	bool collideLeft(terrain &terrain);
	bool collideRight(terrain &terrain);
	void setFrametime(float arg) {frametime=arg;}
	void setFiring(bool arg) {firing=arg;}
	bool getFiring() {return firing;}
	void slow(float amount) {velocity.x*=amount;} //This function only works if calles from within player.update!
	void setspawn(float x, float y) {position.x=x; position.y=y;}
private:
	bool firing;
	bool shield;
	float frametime;
	sf::Texture shieldTexture;
	sf::Sprite shieldSprite;
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Texture playerTexture;
	sf::Sprite playerSprite;
	sf::Vector2i spritePos;
};

