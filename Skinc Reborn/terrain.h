#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "global_values.h"

class terrain
{
	public:
	terrain(map scenario);
	~terrain(void);
	void draw(sf::RenderWindow &window);
	bool isPixelSolid(int x, int y);
	bool isPixelSolid(sf::Vector2f position);
	void removePixel(int x, int y);
	void explode(sf::Vector2f position, float radius);
	void createland(sf::Vector2f position, int width, int height);
private:
	sf::Image terrainImg;
	sf::Sprite terrainSprite;
	sf::Texture terrainTexture;
	sf::Sprite bg_terrainSprite;
	sf::Texture bg_terrainTexture;
	//sf::Uint8 pixel[6400]; //MET2: A second method concerning destructible terrain is having an array of transparent pixels and applying it to a certain part of the image. all other comments with the label "MET2" will have to do with this.
};

