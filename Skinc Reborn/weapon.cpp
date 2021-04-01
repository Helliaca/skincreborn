#include "weapon.h"


weapon::weapon(bool player)
{
	firepower=10; //default firepower
	if(player)
	{
		if (!beamtexture.loadFromFile("resource/laser_blue.png")) std::cout<<"No file found(lasertexturePNG)"<<std::endl;
		beamtexture.setRepeated(true);
		beamtexture.setSmooth(true);
		beam.setTexture(beamtexture);
	}
	else
	{
		if (!beamtexture.loadFromFile("resource/laser_red.png")) std::cout<<"No file found(lasertexturePNG)"<<std::endl;
		beamtexture.setRepeated(true);
		beamtexture.setSmooth(true);
		beam.setTexture(beamtexture);
	}
	if (!crittexture.loadFromFile("resource/laser_crit.png")) std::cout<<"No file found(lasertexturePNG)"<<std::endl;
	crittexture.setRepeated(true);
	crittexture.setSmooth(true);
}
	


weapon::~weapon(void)
{
}

//return true if enemy is hit
bool weapon::fire(terrain &terrain, sf::Vector2f &playerPos, sf::Vector2f &mousePos, sf::RenderWindow &window, sf::Vector2f enemyPos)
{
	beam.setRotation(0);
	//create vector from player to mouse with length of 1
	sf::Vector2f direction=mousePos-playerPos;
	float length=sqrt((direction.x*direction.x)+(direction.y*direction.y));
	direction*=(1/length);//unit-vector mousePos

	//Rotation of the beam:
	beam.setPosition(playerPos);
	if(mousePos.y>playerPos.y) beam.rotate(acos(direction.x)*(180/PI));
	else beam.rotate(0-acos(direction.x)*(180/PI));

	sf::Vector2f currentPos;
	sf::Vector2f weg;
	float distance;
	static int animation=200;
	animation-=10;
	if(animation<-100) animation=200;
	//move in steps of firepower/3 towards mouse and check if isPixelSolid
	for(currentPos=playerPos; currentPos.x<mapwidth && currentPos.y<mapheight && currentPos.x>0 && currentPos.y>0; currentPos+=(direction*(firepower/3)))
	{
		sf::Vector2f enDist = currentPos-enemyPos; //Enemy distance from beam
		//float enDistance = sqrt(enDist.x*enDist.x + enDist.y*enDist.y); //previously used to check if enemy is hit or not. changed to following:
		//if(currentPosX-playerPosX<=playerwidth && currentPosY-playerPosY<=playerheight)

		//if enemy is hit
		if(enDist.x<=playerwidth && enDist.y<=playerheight && enDist.x>=0 && enDist.y>=0) //NOTE: WILL NOT WORK IF PLAYERDIMENSIONS AND BOTDIMENSIONS DIFFER!
		{
			weg = currentPos-playerPos;
			distance = sqrt(weg.x*weg.x + weg.y*weg.y);
			beam.setTextureRect(sf::IntRect(playerPos.x+animation,0,distance,15));
			window.draw(beam);
			return true;
		}
		//if terrain is hit
		else if(terrain.isPixelSolid(currentPos)) 
		{
			terrain.explode(currentPos, firepower);
			sf::Vector2f weg = currentPos-playerPos;
			distance = sqrt(weg.x*weg.x + weg.y*weg.y);
			beam.setTextureRect(sf::IntRect(playerPos.x+animation,0,distance,15));
			window.draw(beam);
			return false;
		}
	}
	//if nothing is hit:
	weg = currentPos-playerPos;
	distance = sqrt(weg.x*weg.x + weg.y*weg.y);
	//beam.setScale(sf::Vector2f(distance,15)); this is from when beam was a rectangleshape, not a sprite.
	beam.setTextureRect(sf::IntRect(playerPos.x+animation,0,distance,15));
	window.draw(beam);
	return false;
}


void weapon::setfirepower(float arg)
{
	//Chek at the bottom of Engine.cpp for a firepower-table
	this->firepower=((float)(arg/100)*7)+8;
}