#pragma once

#include <SFML/Audio.hpp>
#include <iostream>
#include "global_values.h"

/*
* This class is responsible for all sound inside the engine only.
* EDIT: Certein sounds concernign the Cheating-bot (cloak-sound and ssaiyan-sound) have been moved to and are managed at bot.h
*/
class soundManager
{
public:
	soundManager(botskintype enemy); //Soundtrack dependant on botskin.
	~soundManager(void);
	void playbeam();
	void stopbeam();
	void playbotbeam();
	void stopbotbeam();
	void playnuke();
	void stopnuke();
	void playmusic();
	void stopallsound(); //Note: this doesnt actually stop the soundtrack. Use stopmusic() for that.
	void stopmusic();
private:
	sf::SoundBuffer beambuffer;
	sf::Sound beam;
	sf::SoundBuffer botbeambuffer;
	sf::Sound botbeam;
	sf::SoundBuffer nukebuffer;
	sf::Sound nuke;
	sf::Music soundtrack;
};

