/*
* Skinc: Reborn
* © Benjamin Kahl aka Helliaca aka Elanus19
* This is an open source project, you may use,
* change and redistribute this code for any 
* non-commercial purpose.
* Please note that you may only redistribute 
* the source code. Concerning artwork, music 
* sound and others you need permission of their
* respective authors.
*/

/*
* The main.cpp file works as the window-manager, depending on the extern variable nextwindow, which will respectively changed
* by other menu-windows a window will be opened.
* This is so we never have multiple windows open at the same time.
*/


#include "GameContainer.h"
#include "chp_menu.h"
#include "main_menu_w.h"
#include "profile_menu.h"
#include "credits_menu.h"
#include "splashscreen_menu.h"
#include "custom_menu.h"
#include "global_values.h"
#include "loaded_profile.h"
#include "game_settings.h"
#include <SFML/Audio.hpp>

//EXTERN VARIABLES:
/*
* All these variables are declared in either global_values, game_settings or loaded_profile and will be used throughout the project.
*/
window nextwindow=CLOSE;
std::string p_name="";
skintype p_skin=DEMENTOR;
bool p_firststart=true;
level p_level=NEWB;
map g_map=DESERT;
int g_bothealth=100;
int g_botspeed=10500;
int g_botfirepower=20;
botskintype g_botskin=B_DEMENTOR;
int p_health=100;
int p_speed=10500;
int p_firepower=10;
int p_lvluppoints=0;
difficulty g_diff=STANDARD;


//[System::STAThreadAttribute] //not necesary for remastered main menu
int main()
{
	GameContainer game;

	nextwindow=PROFILE;

	sf::Music menumusic;
	if(!menumusic.openFromFile("music/devastation and revenge.ogg")) std::cout<<"File not found(devas&revengeOGG)"<<std::endl;

	std::cout<<"Welcome to Skinc: Reborn! This is an open source, non-commercial project."<<std::endl;

	while(nextwindow!=CLOSE)
	{
		switch(nextwindow) {
		case CUSTOM : {
			game.setGameMode(CUSTOMGAME);
			nextwindow=MAIN;
			SkincReborn::custom_menu^cg = gcnew SkincReborn::custom_menu();
			cg->ShowDialog();
			break;}
		case PROFILE : {
			nextwindow=CLOSE;
			SkincReborn::profile_menu^pmenu = gcnew SkincReborn::profile_menu();
			pmenu->ShowDialog();
			if(p_firststart) {if(!menumusic.openFromFile("music/devastation and revengesplashscreen.ogg")) std::cout<<"File not found(devas&revengesplashOGG)"<<std::endl;}
			else menumusic.play();
			break;}
		case MAIN : {
			nextwindow=CLOSE;
			game.setGameMode(TUTOR);
			SkincReborn::main_menu_w^menu = gcnew SkincReborn::main_menu_w();
			menu->ShowDialog(); break;}
		case CHAMPIONSHIP : {
			if(p_level>=COMPLETE) {menumusic.stop(); menumusic.openFromFile("music/hero down.ogg"); menumusic.play();}
			nextwindow=MAIN;
			game.setGameMode(CHAMP);
			SkincReborn::chp_menu^chp = gcnew SkincReborn::chp_menu();
			chp->ShowDialog(); break;}
		case LOADING : {
			menumusic.stop();
			nextwindow=MAIN;
			game.launch();
			if(!menumusic.openFromFile("music/devastation and revenge.ogg")) std::cout<<"File not found(devas&revengeOGG)"<<std::endl;
			menumusic.play();
			break;}
		case SPLASH : {
			nextwindow=MAIN;
			menumusic.play();
			SkincReborn::splashscreen_menu^spmenu = gcnew SkincReborn::splashscreen_menu();
			spmenu->ShowDialog();
			break;}
		case CREDITS : {
			nextwindow=MAIN;
			SkincReborn::credits_menu^cr = gcnew SkincReborn::credits_menu();
			cr->ShowDialog(); break;}
		default : {nextwindow=CLOSE; break;}
		}
	}
}