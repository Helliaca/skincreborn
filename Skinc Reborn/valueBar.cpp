#include "valueBar.h"
#include <iostream>


valueBar::valueBar(sf::RenderWindow &window, sf::Vector2f position, sf::Vector2f size, int max) : indicator()
{
	maxvalue=max;
	if (!bartexture.loadFromFile("resource/bar_strength.png")) std::cout<<"No file found(barPNG)"<<std::endl;
	bar.setTexture(bartexture);
	bar.setTextureRect(sf::IntRect(0,0,size.x,size.y));

	bar.setPosition(position);
	this->size=size;
	setValue(0);
	

	if(!indicatorfont.loadFromFile("resource/arial.ttf")) std::cout<<"No file found(fontTTF)"<<std::endl;
	indicatortext.str("");
	indicatortext<<value<<" / "<<maxvalue;
	indicator=sf::Text(indicatortext.str(),indicatorfont);
	indicator.setCharacterSize(20);
	indicator.setPosition(position);

	window.draw(bar);
}


valueBar::~valueBar(void)
{
}

void valueBar::update(sf::RenderWindow &window)
{
	window.draw(bar);
	window.draw(indicator);
}

bool valueBar::setValue(short int value)
{
	indicatortext.str("");
	indicatortext<<value<<" / "<<maxvalue;
	if(value <= maxvalue)
	{
		this->value = value;
		bar.setTextureRect(sf::IntRect(0,0,((float)value/maxvalue)*size.x, size.y));
		indicator.setString(indicatortext.str());
		return true;
	}
	else return false;
}

bool valueBar::increaseValue(short int delta)
{
	return setValue(value+delta);
}

bool valueBar::decreaseValue(short int delta)
{
	return setValue(value-delta);
}

void valueBar::changePos(sf::Vector2f position)
{
	bar.setPosition(position);
	indicator.setPosition(position.x+size.x/2-20,position.y);
}

void valueBar::setColor(sf::Color color)
{
	if(color==sf::Color::Blue)
	{
		if (!bartexture.loadFromFile("resource/bar_mana.png")) std::cout<<"No file found(barPNG)"<<std::endl;
		bar.setTexture(bartexture);
	}
	else if(color==sf::Color::Red)
	{
		if (!bartexture.loadFromFile("resource/bar_health.png")) std::cout<<"No file found(barPNG)"<<std::endl;
		bar.setTexture(bartexture);
	}
	else if(color==sf::Color::Magenta)
	{
		if (!bartexture.loadFromFile("resource/bar_enhp.png")) std::cout<<"No file found(barPNG)"<<std::endl;
		bar.setTexture(bartexture);
	}
	else if(color==sf::Color::Cyan)
	{
		if (!bartexture.loadFromFile("resource/bar_cooldown.png")) std::cout<<"No file found(barPNG)"<<std::endl;
		bar.setTexture(bartexture);
	}
	else
	{
		std::cout<<"ERR: Bar-colour not available, using strandard instead."<<std::endl;
	}
}