#include "terrain.h"


terrain::terrain(map scenario)
{
	switch (scenario){
		case BASE : {
			if(!this->terrainImg.loadFromFile("maps/base.png")) std::cout<<"ERR: Map not found! (mapPNG)"<<std::endl;
			if(!this->bg_terrainTexture.loadFromFile("mapbackgrounds/bg_base.png")) std::cout<<"ERR: Map background not found! (mapbgPNG)"<<std::endl; break;}
		case FOREST : {
			if(!this->terrainImg.loadFromFile("maps/forest.png")) std::cout<<"ERR: Map not found! (mapPNG)"<<std::endl;
			if(!this->bg_terrainTexture.loadFromFile("mapbackgrounds/bg_forest.png")) std::cout<<"ERR: Map background not found! (mapbgPNG)"<<std::endl; break;}
		case DESERT : {
			if(!this->terrainImg.loadFromFile("maps/desert.png")) std::cout<<"ERR: Map not found! (mapPNG)"<<std::endl;
			if(!this->bg_terrainTexture.loadFromFile("mapbackgrounds/bg_desert.png")) std::cout<<"ERR: Map background not found! (mapbgPNG)"<<std::endl; break;}
		case VOLCANO : {
			if(!this->terrainImg.loadFromFile("maps/volcano.png")) std::cout<<"ERR: Map not found! (mapPNG)"<<std::endl;
			if(!this->bg_terrainTexture.loadFromFile("mapbackgrounds/bg_volcano.png")) std::cout<<"ERR: Map background not found! (mapbgPNG)"<<std::endl; break;}
		case CRYSTAL : {
			if(!this->terrainImg.loadFromFile("maps/crystal_cave.png")) std::cout<<"ERR: Map not found! (mapPNG)"<<std::endl;
			if(!this->bg_terrainTexture.loadFromFile("mapbackgrounds/bg_crystal_cave.png")) std::cout<<"ERR: Map background not found! (mapbgPNG)"<<std::endl; break;}
		case INDUSTRIAL : {
			if(!this->terrainImg.loadFromFile("maps/industrial.png")) std::cout<<"ERR: Map not found! (mapPNG)"<<std::endl;
			if(!this->bg_terrainTexture.loadFromFile("mapbackgrounds/bg_industrial.png")) std::cout<<"ERR: Map background not found! (mapbgPNG)"<<std::endl; break;}
		case ARENA : {
			if(!this->terrainImg.loadFromFile("maps/arena.png")) std::cout<<"ERR: Map not found! (mapPNG)"<<std::endl;
			if(!this->bg_terrainTexture.loadFromFile("mapbackgrounds/bg_arena.png")) std::cout<<"ERR: Map background not found! (mapbgPNG)"<<std::endl; break;}
		case CUSTOMMAP : {
			if(!this->terrainImg.loadFromFile("maps/custom.png")) std::cout<<"ERR: Map not found! (mapPNG)"<<std::endl;
			if(!this->bg_terrainTexture.loadFromFile("mapbackgrounds/bg_custom.png")) std::cout<<"ERR: Map background not found! (mapbgPNG)"<<std::endl; break;}
		default : {
			if(!this->terrainImg.loadFromFile("maps/base.png")) std::cout<<"ERR: Map not found! (mapPNG)"<<std::endl;
			if(!this->bg_terrainTexture.loadFromFile("mapbackgrounds/bg_base.png")) std::cout<<"ERR: Map background not found! (mapbgPNG)"<<std::endl; break;}
	}
	
	this->bg_terrainSprite.setTexture(this->bg_terrainTexture);
	for(int i=0; i<mapwidth; i++)
	{
		for(int j=0; j<mapheight; j++)
		{
			if(this->terrainImg.getPixel(i,j)==sf::Color(255,0,255)) this->terrainImg.setPixel(i,j,sf::Color::Transparent);
		}
	}

	this->terrainTexture.loadFromImage(this->terrainImg);
	this->terrainTexture.setSmooth(true);
	this->terrainSprite.setTexture(this->terrainTexture);

	//for(int i=0; i<6400; i++) pixel[i]=0; //MET2: set the array full of transparent pixels.
}

terrain::~terrain(void)
{
}

void terrain::draw(sf::RenderWindow &window)
{
	window.draw(bg_terrainSprite);
	this->terrainSprite.setTexture(this->terrainTexture); //this very line eats more than 90% of the framerate of the game. SFML is not properly buid to deal with destructible terrain. If the framerate-cap is removed and this line is commented out the game reaches over to 1k fps
	window.draw(terrainSprite);
}

bool terrain::isPixelSolid(int x, int y)
{
	if(x<=1 || y<=1) return true;
	if(terrainImg.getPixel(x,y)==sf::Color::Transparent) return false;
	return true;
}

bool terrain::isPixelSolid(sf::Vector2f position)
{
	if(terrainImg.getPixel((int)position.x,(int)position.y)==sf::Color::Transparent) return false;
	return true;
}

void terrain::explode(sf::Vector2f position, float radius)
{
	if(position.x>mapwidth || position.y>mapheight || position.x<=0 || position.y<=0) return;
	float radiusSq=radius*radius;
	for(int x=position.x-radius; x<position.x+radius; x++)
	{
		for(int y=position.y-radius; y<position.y+radius; y++)
		{
			if(x<mapwidth && y<mapheight && x>1 && y>1 && isPixelSolid(x,y))
			{
					float xDiff = x - position.x;
					float yDiff = y - position.y;
					float distSq = xDiff * xDiff + yDiff * yDiff;
					// if the distance squared is less than radius squared, then it's within the explosion radius
					if (distSq < radiusSq) removePixel(x,y);
			}
		}
	}
	terrainTexture.update(terrainImg); //not needed for MET2
	
	//terrainTexture.update(pixel,20,20,position.x,position.y); //MET2: Applying an array of pixels to the map. MUCH quicker than the above, but only can make squares. Also, it changes the texture, but not the actual image, therefor the terrain doesnt actually change, it just looks different.
}

void terrain::removePixel(int x, int y)
{
	terrainImg.setPixel(x,y,sf::Color::Transparent);
}

void terrain::createland(sf::Vector2f position, int width, int height)
{
	for(int x=position.x; x<position.x+width && x<mapwidth; x++)
	{
		for(int y=position.y; y<position.y+height && y<mapheight; y++)
		{
			terrainImg.setPixel(x,y,sf::Color(36,28,19)); //use #362819 for earth and #252525 for stone
		}
	}
	terrainTexture.update(terrainImg);
}