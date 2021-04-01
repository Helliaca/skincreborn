#include "player.h"
#include <iostream>


player::player(float x, float y, skintype skin)
{
	srand( (unsigned)10);
	position.x=x;
	position.y=y;
	velocity.x=0;
	velocity.y=0;
	firing=false;
	
	switch(skin){
	case DEMENTOR : {if (!playerTexture.loadFromFile("playersprites/player_sprite_dementor.png")) std::cout<<"No file found (playerSpritePNG)"<<std::endl; break;}
	case ALTAIR : {if (!playerTexture.loadFromFile("playersprites/player_sprite_altair.png")) std::cout<<"No file found (playerSpritePNG)"<<std::endl; break;}
	case FREEMAN : {if (!playerTexture.loadFromFile("playersprites/player_sprite_freeman.png")) std::cout<<"No file found (playerSpritePNG)"<<std::endl; break;}
	case ASH : {if (!playerTexture.loadFromFile("playersprites/player_sprite_ash.png")) std::cout<<"No file found (playerSpritePNG)"<<std::endl; break;}
	default : {if (!playerTexture.loadFromFile("playersprites/player_sprite_dementor.png")) std::cout<<"No file found (playerSpritePNG)"<<std::endl; break;}
	}
	playerSprite.setTexture(playerTexture);
	playerSprite.setTextureRect(sf::IntRect(playerwidth,playerheight,playerwidth,playerheight));

	if (!shieldTexture.loadFromFile("resource/shield_player.png")) std::cout<<"No file found (shieldSpritePNG)"<<std::endl;
	shieldSprite.setTexture(shieldTexture);
}


player::~player(void)
{
}


void player::draw(sf::RenderWindow &window)
{
	playerSprite.setPosition(position.x,position.y);
	window.draw(playerSprite);
}


void player::update(sf::RenderWindow &window, terrain &terrain)
{
	if(!collideBot(terrain)) velocity.y+=g;//Apply gravity
	else if(collideBot(terrain) && velocity.y>0) velocity.y=0;
	if(collideTop(terrain) && velocity.y<0) velocity.y=0;
	
	/*
	* This upcoming algortihm deals with the player moving uphill.
	* If you have trouble understanding, it is heavily oriented (though not identical) with this simple terrain-principle:
	* http://gamedevelopment.tutsplus.com/tutorials/coding-destructible-pixel-terrain-how-to-make-everything-explode--gamedev-45
	*/
	//movement in -x direction
	if (velocity.x < 0) {
		for (int leftY = (int)position.y - playerheight/2; leftY <= (int)position.y + playerheight/2; leftY++) {
			if (terrain.isPixelSolid((int)position.x, leftY)) {
				// next move from the edge to the right, inside the box (stop it at 1/4th the player width)
				for (int xCheck = (int)position.x - playerwidth/4; xCheck < (int)position.x - playerwidth; xCheck--) {
					if (terrain.isPixelSolid(xCheck, leftY)) {
						position.x = xCheck + playerwidth/2; // push the block over 
						break; 
					}
				}
				if (leftY > position.y && !collideTop(terrain)) {
					position.y -= 1;
				}
				else {
					velocity.x *= (-0.4)*frametime;
					//position.x += 2*frametime;
				}
			}
		}
	}
	// movement in x direction
	if (velocity.x > 0) {
		for (int rightY = (int)position.y - playerheight/2; rightY <= (int)position.y + playerheight/2; rightY++) {
			if (terrain.isPixelSolid((int)position.x + playerwidth, rightY)) {
				for (int xCheck = (int)position.x + playerwidth/4; xCheck < (int)position.x; xCheck++) {
					if (terrain.isPixelSolid(xCheck, rightY)) {
						position.x = xCheck - playerwidth/2;
						break; 
					}
				}
				if (rightY > position.y && !collideTop(terrain)) {
					position.y -= 1;
				}
				else {
					velocity.x *= (-0.4)*frametime;
					//position.x -= 2*frametime;
				}
			}
		}
	}




	position+=velocity*frametime;
	

	if(position.x<=2) position.x=2;
	else if(position.x>mapwidth-playerwidth) position.x=mapwidth-playerwidth;
	if(position.y<=2) position.y=2;
	else if(position.y>mapheight-playerheight) position.y=mapheight-playerheight;

	//see readme in playersprites-folder for further documentation.
	if(velocity.x>0) spritePos.x=playerwidth*2;
	else if(velocity.x<0) spritePos.x=0;
	else if(velocity.x==0) spritePos.x=playerwidth;
	if(velocity.y<0) spritePos.y=0;
	else if(velocity.y>=0) spritePos.y=playerheight;

	playerSprite.setTextureRect(sf::IntRect(spritePos,sf::Vector2i(playerwidth,playerheight)));

	//shield
	if(getshield())
	{
		shieldSprite.setPosition(position.x-5,position.y-5);
		window.draw(shieldSprite);
	}
	draw(window);
}

bool player::collideBot(terrain &terrain)
{
	//possible save of performance: only check corners (+ maybe middle) isntead of full row
	for(int i=0; i<playerwidth; i++)
	{
	if(terrain.isPixelSolid((int)position.x+i, (int)position.y+playerheight+1)) return true; //+1 because BELOW player
	}
	return false;
}

bool player::collideLeft(terrain &terrain)
{
	for(int i=0; i<playerheight; i++)
	{
	if(terrain.isPixelSolid((int)position.x-1, (int)position.y+i)) return true; //-1 will lead to Error if at the very left side of map!! (because to the lef tof the player)
	}
	return false;
}

bool player::collideRight(terrain &terrain)
{
	for(int i=0; i<playerheight; i++)
	{
	if(terrain.isPixelSolid((int)position.x+playerwidth+1, (int)position.y+i)) return true; //+1 because to the right player may lead to error when to the very right of the map
	}
	return false;
}

bool player::collideTop(terrain &terrain)
{
	for(int i=0; i<playerwidth; i++)
	{
	if(terrain.isPixelSolid((int)position.x+i, (int)position.y-1)) return true; //-1 because ABOVE the player
	}
	return false;
}

void player::setshield(bool shield)
{
	this->shield=shield;
}