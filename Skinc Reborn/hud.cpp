#include "hud.h"


hud::hud(sf::RenderWindow &window, int maxhealth, int maxEhealth, map overlay) : strength(window, sf::Vector2f(65,screenheight-120),sf::Vector2f(screenwidth-60,30), 100), mana(window, sf::Vector2f(65,screenheight-90), sf::Vector2f(screenwidth-60,30), 100), health(window, sf::Vector2f(65,screenheight-60), sf::Vector2f(screenwidth-60,30), maxhealth), enemyhealth(window, sf::Vector2f(255,15), sf::Vector2f(760,30), maxEhealth),
	atc_cd(window, sf::Vector2f(297,883), sf::Vector2f(220,28), attackcooldown) , nuke_cd(window, sf::Vector2f(526,883), sf::Vector2f(220,28), nukecooldown) , ce_cd(window, sf::Vector2f(748,883), sf::Vector2f(220,28), createearthcooldown)
{
	atc_cd.setValue(attackcooldown);
	atc_cd.setColor(sf::Color::Cyan);
	ce_cd.setColor(sf::Color::Cyan);
	nuke_cd.setColor(sf::Color::Cyan);
	mana.setColor(sf::Color::Blue);
	health.setColor(sf::Color::Red);
	enemyhealth.setColor(sf::Color::Magenta);
	health.setValue(maxhealth);
	enemyhealth.setValue(maxEhealth);

	switch (overlay){ //hud overlay:
		case BASE : {
			if (!hudtexture.loadFromFile("resource/hudoverlay/hud_basic.png")) std::cout<<"ERR: No file found(hudPNG)"<<std::endl; break;}
		case FOREST : {
			if (!hudtexture.loadFromFile("resource/hudoverlay/hud_forest.png")) std::cout<<"ERR: No file found(hudPNG)"<<std::endl; break;}
		case DESERT : {
			if (!hudtexture.loadFromFile("resource/hudoverlay/hud_desert.png")) std::cout<<"ERR: No file found(hudPNG)"<<std::endl; break;}
		case VOLCANO : {
			if (!hudtexture.loadFromFile("resource/hudoverlay/hud_volcano.png")) std::cout<<"ERR: No file found(hudPNG)"<<std::endl; break;}
		case CRYSTAL : {
			if (!hudtexture.loadFromFile("resource/hudoverlay/hud_crystal.png")) std::cout<<"ERR: No file found(hudPNG)"<<std::endl; break;}
		case INDUSTRIAL : {
			if (!hudtexture.loadFromFile("resource/hudoverlay/hud_industrial.png")) std::cout<<"ERR: No file found(hudPNG)"<<std::endl; break;}
		case ARENA : {
			if (!hudtexture.loadFromFile("resource/hudoverlay/hud_arena.png")) std::cout<<"ERR: No file found(hudPNG)"<<std::endl; break;}
		case CUSTOMMAP : {
			if (!hudtexture.loadFromFile("resource/hudoverlay/hud_custom.png")) std::cout<<"ERR: No file found(hudPNG)"<<std::endl; break;}
		default : {
			if (!hudtexture.loadFromFile("resource/hudoverlay/hud_basic.png")) std::cout<<"ERR: No file found(hudPNG)"<<std::endl; break;}
	}

	hud_overlay.setTexture(hudtexture);
	hud_overlay.setTextureRect(sf::IntRect(0,0,screenwidth,screenheight));
	if (!hudundertexture.loadFromFile("resource/hud_underlay.png")) std::cout<<"ERR: No file found(hudunderlayPNG)"<<std::endl;
	hud_underlay.setTexture(hudundertexture);
	hud_underlay.setTextureRect(sf::IntRect(0,0,screenwidth,screenheight));
}


hud::~hud(void)
{
}

void hud::update(sf::Vector2f viewPos, sf::RenderWindow &window)
{
	//Position-settings of overly-objects:
	hud_underlay.setPosition(viewPos.x-screenwidth/2,viewPos.y-screenheight/2);
	window.draw(hud_underlay);

	strength.changePos(sf::Vector2f(viewPos.x-screenwidth/2+65, viewPos.y-screenheight/2+720));
	strength.update(window);

	mana.changePos(sf::Vector2f(viewPos.x-screenwidth/2+30, viewPos.y-screenheight/2+775));
	mana.update(window);

	health.changePos(sf::Vector2f(viewPos.x-screenwidth/2+30, viewPos.y-screenheight/2+826));
	health.update(window);

	enemyhealth.changePos(sf::Vector2f(viewPos.x-screenwidth/2+255, viewPos.y-screenheight/2+10));
	enemyhealth.update(window);

	atc_cd.changePos(sf::Vector2f(viewPos.x-screenwidth/2+297, viewPos.y-screenheight/2+883));
	atc_cd.update(window);

	nuke_cd.changePos(sf::Vector2f(viewPos.x-screenwidth/2+526, viewPos.y-screenheight/2+883));
	nuke_cd.update(window);

	ce_cd.changePos(sf::Vector2f(viewPos.x-screenwidth/2+748, viewPos.y-screenheight/2+883));
	ce_cd.update(window);

	hud_overlay.setPosition(viewPos.x-screenwidth/2,viewPos.y-screenheight/2);
	window.draw(hud_overlay);
}
