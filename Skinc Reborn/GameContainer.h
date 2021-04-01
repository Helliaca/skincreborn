#pragma once
#include "Engine.h"
#include "loaded_profile.h"
#include "game_settings.h"

class GameContainer
{
public:
	GameContainer(void);
	void launch();
	void setGameMode(gamemode arg) {this->gmode=arg;};
private:
	sf::RenderWindow loadingscreen;
	gamemode gmode;

	//Loading screen resources:
	void initializeLoadingScreen();
	void updateLoadingScreen();
	sf::Texture bg_texture;
	sf::Sprite bg_sprite;
	sf::Texture pl_texture;
	sf::Sprite pl_sprite;
	sf::Texture map_texture;
	sf::Sprite map_sprite;
	sf::Text t_text;
	sf::Text t_status;
	sf::Font t_font;
	sf::Font t_sfont;
	std::ostringstream t_string;
	std::string name, map, difficulty, lore;
};

