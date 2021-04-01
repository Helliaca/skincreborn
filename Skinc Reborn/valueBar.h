#pragma once

#include <SFML/Graphics.hpp>
#include <sstream>

class valueBar
{
public:
	valueBar(sf::RenderWindow &window, sf::Vector2f position, sf::Vector2f size, int max);
	~valueBar(void);
	int getValue() {return value;}
	bool setValue(short int value);
	bool increaseValue(short int delta);
	bool decreaseValue(short int delta);
	void update(sf::RenderWindow &window);
	void changePos(sf::Vector2f position);
	void setColor(sf::Color color); //This functiona ctually only does something with the colors sf:: Blue, Red, Magenta, Cyan. Add an additional statement to this function if other colors should be used.
private:
	sf::Font indicatorfont;
	sf::Text indicator;
	//sf::RectangleShape bar; //can be used if instead of an image you want to use a color-bar
	sf::Texture bartexture;
	sf::Sprite bar;

	short int value;
	short int maxvalue;
	std::ostringstream indicatortext; 
	sf::Vector2f size;
};

