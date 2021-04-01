#include "soundManager.h"
#include <time.h>


soundManager::soundManager(botskintype enemy)
{
	if(!beambuffer.loadFromFile("sound/beam.wav")) std::cout<<"File not found(beamWAV)"<<std::endl;
	beam.setBuffer(beambuffer);
	beam.setVolume(50);

	if(!botbeambuffer.loadFromFile("sound/beam_bot.wav")) std::cout<<"File not found(botbeamWAV)"<<std::endl;
	botbeam.setBuffer(botbeambuffer);
	botbeam.setVolume(80);

	if(!nukebuffer.loadFromFile("sound/nuke.wav")) std::cout<<"File not found(nukeWAV)"<<std::endl;
	nuke.setBuffer(nukebuffer);
	nuke.setVolume(100);

	switch(enemy){
	case S_BOGBEARD : {if(!soundtrack.openFromFile("music/all this.ogg")) std::cout<<"File not found(allthisOGG)"<<std::endl;
		soundtrack.setVolume(50);
		break;}
	case S_LYNWOOD : {if(!soundtrack.openFromFile("music/movement proposition.ogg")) std::cout<<"File not found(movpropositionOGG)"<<std::endl;
		soundtrack.setVolume(50);
		break;}
	case S_FIRELORD : {if(!soundtrack.openFromFile("music/volatile reaction.ogg")) std::cout<<"File not found(volatilereactionOGG)"<<std::endl;
		soundtrack.setVolume(50);
		break;}
	case S_TERIDAX : {if(!soundtrack.openFromFile("music/hitman.ogg")) std::cout<<"File not found(hitmanOGG)"<<std::endl;
		soundtrack.setVolume(50);
		break;}
	case S_BOT : {if(!soundtrack.openFromFile("music/ropocalypse 2.ogg")) std::cout<<"File not found(ropocalypseOGG)"<<std::endl;
		soundtrack.setVolume(50);
		break;}
	case S_LANCE : {if(!soundtrack.openFromFile("music/undaunted.ogg")) std::cout<<"File not found(undauntedOGG)"<<std::endl;
		soundtrack.setVolume(50);
		break;}
	case T_TRAININGDUMMY : {if(!soundtrack.openFromFile("music/future gladiator.ogg")) std::cout<<"File not found(futuregladiatorOGG)"<<std::endl;
		soundtrack.setVolume(50);
		break;}
	default : {
		srand( (unsigned)time( NULL ) );
		int random=rand()%2;
		if(random==0) {if(!soundtrack.openFromFile("music/firebrand.ogg")) std::cout<<"File not found(firebrandOGG)"<<std::endl;}
		else if(!soundtrack.openFromFile("music/prelude and action.ogg")) std::cout<<"File not found(preludeandactionOGG)"<<std::endl;
		soundtrack.setVolume(50);
		break;}
	}
	soundtrack.setLoop(true);
}


soundManager::~soundManager(void)
{
}

void soundManager::playbeam()
{ beam.play(); }

void soundManager::stopbeam()
{ beam.stop(); }

void soundManager::playbotbeam()
{ botbeam.play(); }

void soundManager::stopbotbeam()
{ botbeam.stop(); }

void soundManager::playnuke()
{ nuke.play(); }

void soundManager::stopnuke()
{ nuke.stop(); }


void soundManager::playmusic()
{
	soundtrack.play();
}

void soundManager::stopallsound()
{
	soundtrack.stop();
	beam.stop();
	botbeam.stop();
	nuke.stop();
	//...
}

void soundManager::stopmusic()
{
	soundtrack.stop();
}