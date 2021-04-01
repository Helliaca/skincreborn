#include "nuke.h"



nuke::nuke(bool player)
{
	if(player) {if (!nuketexture.loadFromFile("resource/nuke_blue.png")) std::cout<<"No file found(NukePNG)"<<std::endl;}
	else {if (!nuketexture.loadFromFile("resource/nuke_red.png")) std::cout<<"No file found(NukePNG)"<<std::endl;} //note: bot doesnt actually use any nuke.
	nukesprite.setTexture(nuketexture);
}

void nuke::spawnnuke(sf::Vector2f position, sf::Vector2f aimPos)
{
	this->position=position;
	speed=(aimPos-position);
	speed+=speed; //double speed for more responsiveness and accuracy
	nukesprite.setPosition(position);
	active=true;
}

nuke::~nuke(void)
{
}

//Retruns true if enemy is hit. otherwise false.
bool nuke::update(terrain &terrain, sf::RenderWindow &window, sf::Vector2f enemyPos)
{
	if(active)
	{
		window.draw(nukesprite);
		speed.y+=g/3; //1/3 of gravity applied to nuke
		position+=speed*frametime;
		//nuke out of map
		if(position.x>=mapwidth || position.y>=mapheight || position.x<=0 || position.y<=0) {active=false; return false;}
		//nuke hits player
		else if(position.x>=enemyPos.x && position.y>=enemyPos.y && position.x<=enemyPos.x+botwidth && position.y<=enemyPos.y+botheight)
		{
			terrain.explode(position,nukeradius); //destroy terrain in case enemy player was standing on the ground.
			active=false;
			return true;
		}
		//nuke hits ground but not player
		else if(terrain.isPixelSolid(position))
		{
			enemyPos.x+=botwidth/2;
			enemyPos.y+=botheight/2;
			terrain.explode(position,nukeradius);
			active=false;
			sf::Vector2f DtoE=position-enemyPos; //Vector from current position to enemy
			float distance=sqrt((DtoE.x*DtoE.x)+(DtoE.y*DtoE.y))+botheight/2;
			if(distance <= nukeradius) return true;
			else return false;
		}
		nukesprite.setPosition(position);
	}
	return false;
}
