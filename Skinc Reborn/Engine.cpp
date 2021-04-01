#include "Engine.h"


Engine::Engine(map scenario, int playerspeed, int playerfirepower, int playerhealth, int bothealth, int botspeed, int botfirepower, skintype playerskin, botskintype botskin, difficulty gamedif, bool spell1, bool spell2, bool spell3) : player(700,100,playerskin), terrain(scenario), hud(window, playerhealth, bothealth, scenario), bot(1, 1, gamedif, botskin), weapon(true), botweapon(false), nuke(true), soundmanager(botskin)//, botnuke(false)
{
	l_createearth=spell1;
	l_fly=spell2;
	l_nuke=spell3;
	bot.setmaxhealth((float)bothealth);
	bot.setspeed(botspeed);
	this->pSpeed=playerspeed;
	this->pDmg=playerfirepower/20;
	weapon.setfirepower(playerfirepower);
	this->bDmg=botfirepower/20;
	botweapon.setfirepower(botfirepower);
	this->pHp=playerhealth;
	viewPosition.x=screenwidth/2;
	viewPosition.y=screenheight/2;
	view.reset(sf::FloatRect(0,0,screenwidth,screenheight));
	view.setViewport(sf::FloatRect(0,0,1.0f,1.0f));
	botPrevPos.x=0;
	botPrevPos.y=0;
	movchange=0;

	//Spawn locations depending on map:
	switch(scenario){
	case BASE : {player.setspawn(200,400); bot.setspawn(1000,400); break;}
	case FOREST : {bot.setspawn(313,255); break;}
	case DESERT : {player.setspawn(180,300); bot.setspawn(1000,300); break;}
	case VOLCANO : {player.setspawn(1000,300); bot.setspawn(50,10); break;}
	case CRYSTAL : {player.setspawn(150,300); bot.setspawn(1070,300); break;}
	case INDUSTRIAL : {player.setspawn(200,300); bot.setspawn(1070,300); break;}
	case ARENA : {player.setspawn(150,300); bot.setspawn(1070,300); break;}
	}

	if (!bwTexture.loadFromFile("resource/wiz_spbl.png")) std::cout<<"No file found (bWizardPNG)"<<std::endl;
	bwSprite.setTexture(bwTexture);

	if(!tutorialfont.loadFromFile("resource/8bit_font.ttf")) std::cout<<"No file found(fontTTF)"<<std::endl;
	tut=sf::Text("empty",tutorialfont);
	tut.setCharacterSize(25);
	tut.setColor(sf::Color::Black);

	window.create(sf::VideoMode(screenwidth,screenheight), "Skinc: Reborn");
	window.setVisible(false);
	window.setView(view);

	window.setFramerateLimit(33); //increase frame stability due to float-inaccuracy
	atc_cdt.restart();
	nuke_cdt.restart();
	ce_cdt.restart();
	taunt_cdt.restart();

	terrain.draw(window);
	player.draw(window);
	bot.draw(window);
	clock.restart();
}


Engine::~Engine(void)
{
}

int Engine::GameLoop()
{
	window.setVisible(true);

	soundmanager.playmusic();

	clock.restart();
	atc_cdt.restart();
	nuke_cdt.restart();
	ce_cdt.restart();

	bot.say(START);

	while(window.isOpen() && hud.health.getValue()>0 && hud.enemyhealth.getValue()>0)
	{
		frametime=clock.getElapsedTime().asSeconds();
		if(1/clock.getElapsedTime().asSeconds()<25) std::cout<<"LOW FPS: "<<1/clock.getElapsedTime().asSeconds()<<std::endl; //If fps drops, output a warnign message
		clock.restart();
		window.clear();

		terrain.draw(window);

		//Reset all values
		sf::Vector2f mousePosition(sf::Mouse::getPosition(window).x+view.getCenter().x-screenwidth/2, sf::Mouse::getPosition(window).y+view.getCenter().y-screenheight/2); //get absolute Mouse position
		bot.setFrametime(frametime);
		player.setFrametime(frametime);//needs to be done before any velocity-changes
		nuke.setframetime(frametime);
		player.setVX(0);
		bot.setVX(0);
		player.setshield(false);
		bot.setshield(false);
		bot.sethealth(hud.enemyhealth.getValue());

		//INPUT
			while(window.pollEvent(event))
			{
				if(event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) window.close();
				if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left && !(hud.strength.getValue()<=0 || hud.mana.getValue()<=0)) {player.setFiring(true); soundmanager.playbeam(); atc_cdt.restart();}
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) && ce_cdt.getElapsedTime().asSeconds() > createearthcooldown && l_createearth) {terrain.createland(mousePosition, 60,100); ce_cdt.restart();}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && !nuke.getactive() && nuke_cdt.getElapsedTime().asSeconds() > nukecooldown && l_nuke) {nuke.spawnnuke(player.getPos(),mousePosition); nuke_cdt.restart(); soundmanager.playnuke();}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && l_fly) player.setVY(-pSpeed);
			else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && player.collideBot(terrain)) player.setVY(-pSpeed);
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) player.setVX(-pSpeed);
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) player.setVX(pSpeed);
			if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Right) && hud.mana.getValue()>0 && !player.getFiring()) {hud.mana.decreaseValue(1); player.setshield(true); if(hud.strength.getValue()>1) hud.strength.decreaseValue(1);}
			else if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && hud.strength.getValue()<=hud.mana.getValue() && atc_cdt.getElapsedTime().asSeconds() > attackcooldown) {hud.strength.increaseValue(1);}
			else if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {hud.mana.increaseValue(40*frametime);} //optional: player.slow(0.7); --note:player.slow() doesnt actually do anything.

		//BOT-INPUT
			bot.react(player.getPos(), mousePosition, terrain, player.getFiring());
			if(bot.getstate()==LOAD) bot.increasemana(40*frametime);
			if(bot.getstate()==ATTACK && !bot.getFiring()) {bot.setFiring(true); soundmanager.playbotbeam();}
			if(bot.getstate()==DEFEND) bot.setshield(true);
			else if(bot.getstate()==ATTACK && botweapon.fire(terrain, bot.getPos(), bot.getaim(), window, player.getPos()) && !player.getshield()) {hud.health.decreaseValue(bDmg);}
			if(bot.getstate()==ATTACK)  bot.increasemana(-1);
			else soundmanager.stopbotbeam();
			if(bot.getcheat()!=INACTIVE)
			{
				if(bot.getcheat()==SUDDENHEAL) {hud.enemyhealth.increaseValue(hud.enemyhealth.getValue()/2); bot.cheatsinactive();}
				else if(bot.getcheat()==SSAIYAN) {hud.mana.decreaseValue(1); hud.health.decreaseValue(1);}
			}
			if(taunt_cdt.getElapsedTime().asSeconds()>tauntcooldown) {bot.say(FIGHT); taunt_cdt.restart();}
			

		//PROCESS-INPUT
			if(player.getFiring())
			{
				if(weapon.fire(terrain, player.getPos(),mousePosition,window, bot.getPos()) && !bot.getshield()) hud.enemyhealth.decreaseValue(pDmg);
				hud.strength.decreaseValue(1);
				hud.mana.decreaseValue(1);
				if(hud.strength.getValue()<=0 || hud.mana.getValue()<=0) {player.setFiring(false); soundmanager.stopbeam();}
			}

			//UPDATE OBJECTS
			botPrevPos=bot.getPos();
			player.update(window, terrain);
			bot.update(window, terrain);
			if(nuke.getactive()) {if(nuke.update(terrain, window, bot.getPos())) hud.enemyhealth.decreaseValue(pDmg*20);} //pDmg*20=p_firepower=nukedamage
			if((int)atc_cdt.getElapsedTime().asSeconds() <= attackcooldown) hud.atc_cd.setValue((int)atc_cdt.getElapsedTime().asSeconds());
			if(l_nuke && (int)nuke_cdt.getElapsedTime().asSeconds() <= nukecooldown) hud.nuke_cd.setValue((int)nuke_cdt.getElapsedTime().asSeconds());
			if(l_createearth && (int)ce_cdt.getElapsedTime().asSeconds() <= createearthcooldown) hud.ce_cd.setValue((int)ce_cdt.getElapsedTime().asSeconds());
			if(bot.getPos()==botPrevPos) movchange++;
			if(movchange>105) {terrain.explode(sf::Vector2f(bot.getPos().x+botwidth/2, bot.getPos().y+botheight/2), nukeradius); movchange=0; /*botnuke.spawnnuke(bot.getPos(),player.getPos());*/} //if bot hasnt moved(becasue stuck in terrain) for 3s*35fps=105 frames, spawn nuke.

			//custom, only y-oriented view:
			if(player.getY()>200 && player.getY()<650) viewPosition.y=player.getY()+playerheight/2+100;//+smth because of bigger hud on bottom side
			viewPosition.x=screenwidth/2;
			/*/right/top margin //FOR FULLY POSITION-REALATIVE VIEW (OTHERWISE JUST Y-COORDIANTE):
			if(player.getX()+playerwidth/2>screenwidth/2) viewPosition.x=player.getX()+playerwidth/2;
			else viewPosition.x=screenwidth/2;
			if(player.getY()+playerheight/2>screenheight/2) viewPosition.y=player.getY()+playerheight/2;
			else viewPosition.y=screenheight/2;*/
			/*left/bot margin(TODO)
			not working because left/bot margin executes AFTER right/top==lower priority
			if(player.getX()+15<1280-(screenwidth/2)) viewPosition.x=player.getX()+15;//1280 map-length
			else viewPosition.x=1280-(screenwidth/2);
			if(player.getY()+15<680-(screenheight/2)) viewPosition.y=player.getY()+15;//680 map-height
			else viewPosition.y=680-(screenheight/2);
			*/
			view.setCenter(viewPosition);
			window.setView(view);

			hud.update(viewPosition, window);

			window.display();
	}

	soundmanager.stopallsound();
	window.clear();
	//DEFEAT:
	if(hud.health.getValue()<=0)
	{
		sf::Texture defTexture;
		if(!defTexture.loadFromFile("resource/defeat_img.png")) std::cout<<"No file found (DefeatPNG)"<<std::endl;
		sf::Sprite defSprite;
		defSprite.setTexture(defTexture);
	
		defSprite.setPosition(viewPosition.x-400,viewPosition.y-400);
		while(window.pollEvent(event) || window.isOpen())
		{
			window.clear();
			bot.defeated(window, viewPosition);
			window.draw(defSprite);
			if(event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {soundmanager.stopmusic(); window.close(); return 0;}
			if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {window.close(); soundmanager.stopmusic(); return 0;}
			window.display();
		}
		soundmanager.stopmusic(); 
		return 0;
	}
	//VICTORY:
	else if(hud.enemyhealth.getValue()<=0)
	{
		sf::Texture vicTexture;
		if(!vicTexture.loadFromFile("resource/victory_img.png")) std::cout<<"No file found (VictoryPNG)"<<std::endl;
		sf::Sprite vicSprite;
		vicSprite.setTexture(vicTexture);
		vicSprite.setPosition(viewPosition.x-400,viewPosition.y-400);
		bot.say(DEFEATED);
		while(window.pollEvent(event) || window.isOpen())
		{
			window.clear();
			bot.defeated(window, viewPosition);
			window.draw(vicSprite);
			if(event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {soundmanager.stopmusic(); window.close(); return hud.health.getValue();}
			if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {soundmanager.stopmusic(); window.close(); return hud.health.getValue();}
			window.display();
		}
		soundmanager.stopmusic(); 
		return hud.health.getValue();
	}
	//GAME CLOSED:
	soundmanager.stopmusic();
	return 0;
}


/*
* Bascially the same as GameLoop() but with reduced funtionality (no taunts for example) and with Tutorial outputs.
*/
int Engine::TutorialLoop()
{
	tutStep=L_MOVE;
	window.setVisible(true);

	soundmanager.playmusic();

	while(window.isOpen() && hud.health.getValue()>0 && hud.enemyhealth.getValue()>0)
	{
		frametime=clock.getElapsedTime().asSeconds();
		std::cout<<"FPS: "<<1/clock.getElapsedTime().asSeconds()<<std::endl;
		clock.restart();
		window.clear();

		terrain.draw(window);

		sf::Vector2f mousePosition(sf::Mouse::getPosition(window).x+view.getCenter().x-screenwidth/2, sf::Mouse::getPosition(window).y+view.getCenter().y-screenheight/2); //get absolute Mouse position
		bot.setFrametime(frametime);
		player.setFrametime(frametime);//needs to be done before any velocity-changes
		nuke.setframetime(frametime);
		player.setVX(0);
		bot.setVX(0);
		player.setshield(false);
		bot.setshield(false);
		bot.sethealth(hud.enemyhealth.getValue());

		//TUTORIAL OUTPUT:
		switch(tutStep){
		case L_MOVE : {tut.setString("Welcome to the battlefield!\nYou will battle your\nyour opponents in places\nlike this one.\nIn order to move around,\nuse [W] [A] and [D].\n\nNote that the battlefield\nis restricted to\ncertain boundaries."); break;}
		case L_RECHARGE : {tut.setString("There are three basic\nactions in Skinc:\nrecharge, attack and\ndefend.\nIn order for you to\nattack or defend,\nyou need mana.\nPress [R] to recharge\nyour mana and observe\nyour mana-bar slowly\nfilling up!"); break;}
		case L_SHOOT : {tut.setString("Hold [LMB] to charge\nyour attack, notice\nyour strength-bar\nquickly filling up.\nOnce you release [LMB]\nyour attack will begin.\nNotice that attacking has\na 3 second cooldown-timer\nat the botom.\nSo chose wisely the moment\nand strength of\nyour attack!"); break;}
		case L_USESHIELD : {tut.setString("The red bar represents\nyour health, the purple\none the health of your\nenemy. In order to defend\nyourself from an hostile\nattack, press [RMB] to\nactivate your shield.\nSince the shield costs\nas much mana as\nattacking, it is\nvital to only use\nit when necessary."); break;}
		case L_HSHIELD : {tut.setString("It is important to know\nthat when pressing\nmultiple buttons at the\nsame time, recharching\nhas the lowest priority.\nAlso, if you can not\nuse your shield while\nchanneling your attack.\nNow on to some more\nadvanced spells!"); break;}
		case L_FLY : {tut.setString("There are three advanced\nspells which you can\nunlock by winning in\nthe chamionship.\nThe first one is\ncompletely passive and\nallows you to fly.\nGo ahead and try it out!\n(Use [W] [A] and [D]\nto fly)"); break;}
		case L_CEARTH : {tut.setString("The second one is called\n'summon earth' and lets\nyou create an earth-\nbarrier to protect\nyourself or jump on to.\nPress [3] to summon\nan earth barrier!\nThese act like normal\nterrain and are\non a 15-second\ncooldown as you can\nsee down below."); break;}
		case L_NUKE : {tut.setString("The last one is a\ndestrucive spell refered\nto as 'nuke'.\nPress [1] to fire one!\nThese projectiles are\non a 15-secon cooldown\naswell and do a lot of\ndamage. But since they are\nreally hard to hit, it\nmight be wiser to use them\nwhen you get stuck\nin the terrain."); break;}
		case L_CHAMP : {tut.setString("You seem to be\na fast learner.\nI believe that was\nall you need to know.\nBut, are you ready for\nthe Skinc-championship?\nWell, lets find out..."); break;}
		case L_PRACTICE : {tut.setString("I am going to\nsummon a practice\nunit for you\nso you may put\nto practice what\nyou just learned.\nDont worry, this one\nwill not do much\ndamage.\nIf you get bored, you\ncan close the game anytime\nby pressing [Escape]."); break;}
		}

		//INPUT
			while(window.pollEvent(event))
			{
				if(event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) window.close();
				if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left && !(hud.strength.getValue()<=0 || hud.mana.getValue()<=0)) {player.setFiring(true); soundmanager.playbeam(); atc_cdt.restart();}
				if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space) tutStep = static_cast<tutorialsteps>( static_cast<int>(tutStep) + 1 );
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) && ce_cdt.getElapsedTime().asSeconds() > createearthcooldown && tutStep>=L_CEARTH) {terrain.createland(mousePosition, 60,100); ce_cdt.restart();}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && !nuke.getactive() && nuke_cdt.getElapsedTime().asSeconds() > nukecooldown && tutStep>=L_NUKE) {nuke.spawnnuke(player.getPos(),mousePosition); nuke_cdt.restart(); soundmanager.playnuke();}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && tutStep>=L_FLY) player.setVY(-pSpeed);
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && tutStep<L_FLY && player.collideBot(terrain)) player.setVY(-pSpeed);
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) player.setVX(-pSpeed);
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) player.setVX(pSpeed);
			if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Right) && hud.mana.getValue()>0 && !player.getFiring() && tutStep>=L_USESHIELD) {hud.mana.decreaseValue(1); player.setshield(true); if(hud.strength.getValue()>1) hud.strength.decreaseValue(1);}
			else if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && hud.strength.getValue()<=hud.mana.getValue() && atc_cdt.getElapsedTime().asSeconds() > attackcooldown && tutStep>=L_SHOOT) {hud.strength.increaseValue(1);}
			else if(sf::Keyboard::isKeyPressed(sf::Keyboard::R) && tutStep>=L_RECHARGE) {hud.mana.increaseValue(40*frametime);} //optional: player.slow(0.7); --note:player.slow() doesnt actually do anything.

		//BOT-INPUT
			if(tutStep>=L_END){
				bot.react(player.getPos(), mousePosition, terrain, player.getFiring());
				if(bot.getstate()==LOAD) bot.increasemana(40*frametime);
				if(bot.getstate()==ATTACK && !bot.getFiring()) {bot.setFiring(true);  soundmanager.playbotbeam();}
				if(bot.getstate()==DEFEND) bot.setshield(true);
				else if(bot.getstate()==ATTACK && botweapon.fire(terrain, bot.getPos(), bot.getaim(), window, player.getPos()) && !player.getshield()) {hud.health.decreaseValue(bDmg);}
				if(bot.getstate()==ATTACK)  bot.increasemana(-1);
				else soundmanager.stopbotbeam();
				if(bot.getcheat()!=INACTIVE)
				{
					if(bot.getcheat()==SUDDENHEAL) {hud.enemyhealth.increaseValue(hud.enemyhealth.getValue()/2); bot.cheatsinactive();}
					else if(bot.getcheat()==SSAIYAN) {hud.mana.decreaseValue(1); hud.health.decreaseValue(1);}
				}
			}

		//PROCESS-INPUT
			if(player.getFiring())
			{
				if(weapon.fire(terrain, player.getPos(),mousePosition,window, bot.getPos()) && !bot.getshield() && tutStep>=L_END) hud.enemyhealth.decreaseValue(pDmg);
				hud.strength.decreaseValue(1);
				hud.mana.decreaseValue(1);
				if(hud.strength.getValue()<=0 || hud.mana.getValue()<=0) {player.setFiring(false); soundmanager.stopbeam();}
			}

			//UPDATE OBJECTS
			player.update(window, terrain);
			if(tutStep>=L_END) {botPrevPos=bot.getPos(); bot.update(window, terrain);}

			if(nuke.getactive()) {if(nuke.update(terrain, window, bot.getPos())) hud.enemyhealth.decreaseValue(pDmg*20);} //pDmg*20=p_firepower=nukedamage
			if((int)atc_cdt.getElapsedTime().asSeconds() <= attackcooldown && tutStep>=L_SHOOT) hud.atc_cd.setValue((int)atc_cdt.getElapsedTime().asSeconds());
			if((int)nuke_cdt.getElapsedTime().asSeconds() <= nukecooldown && tutStep>=L_NUKE) hud.nuke_cd.setValue((int)nuke_cdt.getElapsedTime().asSeconds());
			if((int)ce_cdt.getElapsedTime().asSeconds() <= createearthcooldown && tutStep>=L_CEARTH) hud.ce_cd.setValue((int)ce_cdt.getElapsedTime().asSeconds());

			//custom, only y-oriented view:
			if(player.getY()>200 && player.getY()<650) viewPosition.y=player.getY()+playerheight/2+100;//+smth because of bigger hud on bottom side
			viewPosition.x=screenwidth/2;
			view.setCenter(viewPosition);
			window.setView(view);

			if(tutStep<L_END){
				bwSprite.setPosition(viewPosition.x+380,viewPosition.y-350);
				tut.setPosition(viewPosition.x+390,viewPosition.y-350);
				window.draw(bwSprite);
				window.draw(tut);
			}

			hud.update(viewPosition, window);


			window.display();
	}
	soundmanager.stopmusic();
	soundmanager.stopallsound();
	window.clear();
	return 0;
}




/*
* TABLE OF DAMAGE
* P_FIREPOWER	|	ATTACKDAMAGE	|	ATTACKRADIUS(TERRAIN)	|	NUKE DAMAGE
* FORMULA:
*   X				X/20					8+(X/100)*7					X
* NORMAL VALUES:
*	20				20/20=1					8+(20/100)*7=8				20
*	40				40/20=2					8+(40/100)*7=11				40
*	60				60/20=3					8+(60/100)*7=12				60
*	80				80/20=4					8+(80/100)*7=13				80
*	100				100/20=5				8+(100/100)*7=15			100
* BIG/MAXED VALUES:
*	150				150/20=8				8+(150/100)*7=18			150
*/