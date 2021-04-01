#include "bot.h"
#include <time.h>


bot::bot(float x, float y, difficulty diff, botskintype skin)
{
	srand( (unsigned)time( NULL ) );
	currentcheat=INACTIVE;
	reactiontime=1;
	actiontime=1;
	currentstate=IDLE;
	health=100;
	mana=0;
	bSpeed=10500;
	position.x=x;
	position.y=y;
	velocity.x=0;
	velocity.y=0;
	aimPos.x=1;
	aimPos.y=1;
	firing=false;
	this->diff=diff;
	cone=1000;
	safe=0.05;
	highrisk=0.4;
	shootmana=90;
	stockmana=20;
	aimspeed=0.05;
	loadTauntProfile(skin);
	loadDifficultyProfile(diff);

	if(!cloakbuffer.loadFromFile("sound/cloak.wav")) std::cout<<"File not found (cloaksoundWAV)"<<std::endl;
	cloak.setBuffer(cloakbuffer);
	cloak.setVolume(90);
	cloak.setLoop(false);

	if(!ssaiyanbuffer.loadFromFile("sound/ssaiyan.wav")) std::cout<<"File not found (ssaiyansoundWAV)"<<std::endl;
	ssaiyan.setBuffer(ssaiyanbuffer);
	ssaiyan.setVolume(90);
	ssaiyan.setLoop(false);

	if(!speechbubblefont.loadFromFile("resource/8bit_font.ttf")) std::cout<<"No file found(fontTTF)"<<std::endl;
	taunt=sf::Text("empty",speechbubblefont);
	taunt.setCharacterSize(20);
	taunt.setColor(sf::Color::Black);
	taunt.setStyle(sf::Text::Bold);

	if (!speechbubbletexture.loadFromFile("resource/speechbubble.png")) std::cout<<"No file found(speechbubblePNG)"<<std::endl;
	speechbubble.setTexture(speechbubbletexture);


	switch(skin){
	case B_DEMENTOR : {if (!botTexture.loadFromFile("playersprites/player_sprite_dementor.png")) std::cout<<"No file found(dementorPNG)"<<std::endl; break;}
	case B_ALTAIR : {if (!botTexture.loadFromFile("playersprites/player_sprite_altair.png")) std::cout<<"No file found(altairPNG)"<<std::endl; break;}
	case B_FREEMAN : {if (!botTexture.loadFromFile("playersprites/player_sprite_freeman.png")) std::cout<<"No file found(freemanPNG)"<<std::endl; break;}
	case B_ASH : {if (!botTexture.loadFromFile("playersprites/player_sprite_ash.png")) std::cout<<"No file found(ashPNG)"<<std::endl; break;}
	case S_BOGBEARD : {if (!botTexture.loadFromFile("playersprites/chp_sprite_bogbeard.png")) std::cout<<"No file found(bogbeardPNG)"<<std::endl; break;}
	case S_LYNWOOD : {if (!botTexture.loadFromFile("playersprites/chp_sprite_lynwood.png")) std::cout<<"No file found(lynwoodPNG)"<<std::endl; break;}
	case S_FIRELORD : {if (!botTexture.loadFromFile("playersprites/chp_sprite_firelord.png")) std::cout<<"No file found(firelordPNG)"<<std::endl; break;}
	case S_TERIDAX : {if (!botTexture.loadFromFile("playersprites/chp_sprite_teridax.png")) std::cout<<"No file found(teridaxPNG)"<<std::endl; break;}
	case S_BOT : {if (!botTexture.loadFromFile("playersprites/chp_sprite_bot.png")) std::cout<<"No file found(botPNG)"<<std::endl; break;}
	case S_LANCE : {if (!botTexture.loadFromFile("playersprites/chp_sprite_lance.png")) std::cout<<"No file found(lancePNG)"<<std::endl; break;}
	case T_TRAININGDUMMY : {if (!botTexture.loadFromFile("playersprites/tut_sprite_trainingdummy.png")) std::cout<<"No file found(trainingdummyPNG)"<<std::endl; break;}
	default : {if (!botTexture.loadFromFile("playersprites/chp_sprite_dementor.png")) std::cout<<"No file found(dementorPNG)"<<std::endl; break;}
	}
	botSprite.setTexture(botTexture);
	botSprite.setTextureRect(sf::IntRect(botwidth,botheight,botwidth,botheight));
	if (skin==S_BOT || skin==S_LANCE) {if (!shieldTexture.loadFromFile("resource/shield_special.png")) std::cout<<"No file found (shieldSpritePNG)"<<std::endl;}
	else if (!shieldTexture.loadFromFile("resource/shield_evil.png")) std::cout<<"No file found (shieldSpritePNG)"<<std::endl;
	shieldSprite.setTexture(shieldTexture);
	reacttimer.restart();
	actiontimer.restart();
	cloaktimer.restart();

	taunting=true;
}


bot::~bot(void)
{
	
}


void bot::draw(sf::RenderWindow &window)
{
	botSprite.setPosition(position.x,position.y);
	window.draw(botSprite);
}


void bot::update(sf::RenderWindow &window, terrain &terrain)
{
	if(!collideBot(terrain)) velocity.y+=g; //apply gravity (g declared in global_values)
	else if(collideBot(terrain) && velocity.y>0) velocity.y=0;
	if(collideTop(terrain) && velocity.y<0) velocity.y=0;

	/*
	* This upcoming algortihm deals with the player moving uphill.
	* If you have trouble understanding, it is heavily oriented (though not identical) with this simple terrain-principle:
	* http://gamedevelopment.tutsplus.com/tutorials/coding-destructible-pixel-terrain-how-to-make-everything-explode--gamedev-45
	*/
	//Movement in -x-direction
	if (velocity.x < 0) {
      for (int leftY = (int)position.y - botheight/2; leftY <= (int)position.y + botheight/2; leftY++) {
        if (terrain.isPixelSolid((int)position.x, leftY)) {
          // next move from the edge to the right, inside the box (stop it at 1/4th the bot width)
          for (int xCheck = (int)position.x - botwidth/4; xCheck < (int)position.x - botwidth; xCheck--) {
            if (terrain.isPixelSolid(xCheck, leftY)) {
              position.x = xCheck + botwidth/2; // push the block over 
              break; 
            }
          }
          if (leftY > position.y && !collideTop(terrain)) {
            position.y -= 1;
          }
          else {
            velocity.x *= (-0.4)*frametime;
          }
        }
      }
    }
    //Movement in x-direction
    if (velocity.x > 0) {
      for (int rightY = (int)position.y - botheight/2; rightY <= (int)position.y + botheight/2; rightY++) {
        if (terrain.isPixelSolid((int)position.x + botwidth, rightY)) {
          for (int xCheck = (int)position.x + botwidth/4; xCheck < (int)position.x; xCheck++) {
            if (terrain.isPixelSolid(xCheck, rightY)) {
              position.x = xCheck;
              break; 
            }
          }
          if (rightY > position.y && !collideTop(terrain)) {
            position.y -= 1;
          }
          else {
            velocity.x *= (-0.4)*frametime;
          }
        }
      }
    }


	position+=velocity*frametime; //Correct velocity in case framerate changes. Note: Because of float-inaccuracy this doesnt work well with big framerate changes (like from 1000fps to 40). Therefore (as you will see in Engine.cpp the FramerateLimit is set to around 30.


	if(position.x<=2) position.x=2; //Map Limit at 2 pixels from the edge
	else if(position.x>mapwidth-botwidth) position.x=mapwidth-botwidth;
	if(position.y<=2) position.y=2; // same for altitiude
	else if(position.y>mapheight-botheight) position.y=mapheight-botheight;

	/*
	* These few lines set the proper player/bot-sprite depending on movement. If you ahve trouble understanding check the readme in the playersprites folder.
	*/
	if(velocity.x>0) spritePos.x=botwidth*2;
	else if(velocity.x<0) spritePos.x=0;
	else if(velocity.x==0) spritePos.x=botwidth;
	if(velocity.y<0) spritePos.y=0;
	else if(velocity.y>=0) spritePos.y=botheight;

	//These lines only apply to Cheating-bots adn deal with the graphics and sounds of cloaking and super-saiyan.
	if(currentcheat==CLOAK)
	{
		if(cloaktimer.getElapsedTime().asSeconds()<1) //blurr-effect
		{
			cloak.play(); //sound
			spritePos.x=botwidth*2;
			spritePos.y=botheight*2;
		}
		else if(cloaktimer.getElapsedTime().asSeconds()<8) //fully invisible
		{
			spritePos.x=botwidth;
			spritePos.y=botheight*2;
		}
		else if(cloaktimer.getElapsedTime().asSeconds()<9) //blurr-out-effect 
		{
			cloak.play(); //sound
			spritePos.x=botwidth*2;
			spritePos.y=botheight*2;
		}
		else currentcheat=INACTIVE;
	}
	else if(currentcheat==SSAIYAN)
	{
		if(cloaktimer.getElapsedTime().asSeconds()<3)
		{
			spritePos.x=0;
			spritePos.y=botheight*2;
		}
		else currentcheat=INACTIVE;
	}

	botSprite.setTextureRect(sf::IntRect(spritePos,sf::Vector2i(botwidth,botheight)));

	draw(window);

	//Speechbubble
	if(taunting)
	{
		speechbubble.setPosition(position.x-20, position.y-50);
		taunt.setPosition(position.x-10, position.y-49);
		if(taunttimer.getElapsedTime().asSeconds() > 5) taunting=false; //3=seconds bot taunts
		window.draw(speechbubble);
		window.draw(taunt);
	}
	//Shield
	if(getshield())
	{
		mana--;
		shieldSprite.setPosition(position.x-5,position.y-5);
		window.draw(shieldSprite);
	}
}

/*
* This function deals with the AI. Note that all AIs work in a very similar way. However their aiming-speed and other stats are altered in the loadDifficultyProfile-function.
*/
void bot::react(sf::Vector2f playerPos, sf::Vector2f PlmousePos, terrain &terrain, bool playerFiring)
{
	//3 static variables which will determine a random action
	static int move=-1; //move left, right, up or idle
	static int action=-1; //attack defend load or idle
	static int hax=-1; //see: cheatbot
	float danger=-1;

	playerPos.x+=playerwidth/2;
	playerPos.y+=playerheight/2;
	if(playerFiring) danger = (maxhealth/(health+1))*(1/abs(PlmousePos.x+PlmousePos.y-position.x-position.y)); //The danger of depends on the bots health and the distance of the playermouse to him (and if the player is firing at all)
	switch (diff) {
		case CHEATING : {
			if(actiontimer.getElapsedTime().asSeconds()>actiontime)
			{
				if(mana<=stockmana) currentstate=LOAD;
				else if(mana>=shootmana) {currentstate=ATTACK; aimPos.x=playerPos.x+cone*((float) rand() / (RAND_MAX)); aimPos.y=playerPos.y+cone*((float) rand() / (RAND_MAX));}
				if(danger > safe && mana>1) currentstate=DEFEND;
				actiontimer.restart();
			}
			if(danger > highrisk) currentstate=DEFEND;//If danger surpases a highrisk limit, interrupt anything and defend instead.

			if(reacttimer.getElapsedTime().asSeconds()>reactiontime)
			{
				move=rand()%3;
				reacttimer.restart();
				hax=rand()%20; //1/20 chance of cheating every time he moves.
				if(hax==0 && currentcheat==INACTIVE) //CHEATS ACTIVE
				{
					say("HAAAAX!");
					hax=rand()%4; //4 cheats are available: Healing himself (this is done in Engine.GameLoop(), cloaking (see bot.update), supersaiyan (see engine + bot.update) and teleport which is done right here.
					if(hax==0) currentcheat=SUDDENHEAL;
					else if(hax==1) {currentcheat=CLOAK; cloaktimer.restart();}
					else if(hax==2) {currentcheat=SSAIYAN; ssaiyan.play(); cloaktimer.restart();}
					else if(hax==3) {currentcheat=TELEPORT; position.x=playerPos.x-playerwidth/2+1; position.y=playerPos.y-playerheight/2+1; currentcheat=INACTIVE;}
					hax=-1;
				}
			}
			if(move==2 && position.x>100) setVX(-bSpeed);
			else if(move==1 && position.y>50) setVY(-bSpeed);
			else if(move==0 && position.x<1100) setVX(bSpeed);
			break;
		}
		case EASY : { //The very basic bot. He will laod until shootmana is reached and then fire until stockmana is reached. Every reactiontime seconds change movement.
			if(mana<=stockmana) currentstate=LOAD;
			if(mana>=shootmana) currentstate=ATTACK;

			if(reacttimer.getElapsedTime().asSeconds()>reactiontime)
			{
				move=rand()%3;
				reacttimer.restart();
			}
			if(move==2 && !collideLeft(terrain)) setVX(-bSpeed);
			else if(move==0 && !collideRight(terrain)) setVX(bSpeed);
			else setVY(-bSpeed);
			break;
		}
		case MERCILESS : { //Merciless and Standard bot are extremly similar, I suggest you look at Standard first and you will see there is almost no difference.
			if(actiontimer.getElapsedTime().asSeconds()>actiontime)
			{
				if(mana<=stockmana) currentstate=LOAD;
				else if(mana>=shootmana) {currentstate=ATTACK; aimPos.x=playerPos.x+cone*((float) rand() / (RAND_MAX)); aimPos.y=playerPos.y+cone*((float) rand() / (RAND_MAX));}
				if(danger > safe && mana>1) currentstate=DEFEND;
				actiontimer.restart();
			}
			if(danger > highrisk) currentstate=DEFEND;
			if(health<maxhealth/10 && playerFiring && mana>1) currentstate=DEFEND;

			if(reacttimer.getElapsedTime().asSeconds()>reactiontime)
			{
				move=rand()%3;
				reacttimer.restart();
			}
			if(move==2 && position.x>100) setVX(-bSpeed);
			else if(move==1 && position.y>50) setVY(-bSpeed);
			else if(move==0 && position.x<1100) setVX(bSpeed);
			break;
		}
		default : { //Standard, Medium and Hard bot are all the same and only differenciate from their stats in bot.loadDifficultyProfile. This is the very skeleton for all AIs in this game.
			if(actiontimer.getElapsedTime().asSeconds()>actiontime)
			{//Load till shootmana, then attack till stockmana. Initial aiming-position is in a certain cone (check LDP) and is slowly corrected towards the actual palyer position.
				if(mana<=stockmana) currentstate=LOAD;
				else if(mana>=shootmana) {currentstate=ATTACK; aimPos.x=playerPos.x+cone*((float) rand() / (RAND_MAX)); aimPos.y=playerPos.y+cone*((float) rand() / (RAND_MAX));}
				if(danger > safe && mana>1) currentstate=DEFEND;
				actiontimer.restart();
			}
			if(danger > highrisk) currentstate=DEFEND; //Interrupt if danger too high

			if(reacttimer.getElapsedTime().asSeconds()>reactiontime) //Random movement
			{
				move=rand()%3;
				reacttimer.restart();
			}
			if(move==2 && position.x>100) setVX(-bSpeed);
			else if(move==1 && position.y>50) setVY(-bSpeed);
			else if(move==0 && position.x<1100) setVX(bSpeed);
			break;
		}
	}

	//A few guards that make sure the bot is not able to do something while he has no mana.
	if(currentstate!=ATTACK) firing=false;
	if((currentstate==ATTACK || currentstate==DEFEND) && mana<=0) currentstate=IDLE;
	//Correct the aimingposition towards the actual player-position.
	if(currentstate==ATTACK)
	{
		aimPos+=aimspeed*(playerPos-aimPos);
	}
}


bool bot::collideBot(terrain &terrain)
{
	for(int i=0; i<botwidth; i++)
	{
	if(terrain.isPixelSolid((int)position.x+i, (int)position.y+botheight+1)) return true; //+1 because BELOW bot
	}
	return false;
}

bool bot::collideLeft(terrain &terrain)
{
	//possible save of performance: only check corners (+ maybe middle) isntead of full row
	for(int i=0; i<botheight; i++)
	{
	if(terrain.isPixelSolid((int)position.x-1, (int)position.y+i)) return true; //-1 will lead to Error if at the very left side of map! (because to the left of the bot)
	}
	return false;
}

bool bot::collideRight(terrain &terrain)
{
	//possible save of performance: only check corners (+ maybe middle) isntead of full row
	for(int i=0; i<botheight; i++)
	{
	if(terrain.isPixelSolid((int)position.x+botwidth+1, (int)position.y+i)) return true; //+1 because to the right bot may lead to error when to the very right of the map
	}
	return false;
}

bool bot::collideTop(terrain &terrain)
{
	//possible save of performance: only check corners (+ maybe middle) isntead of full row
	for(int i=0; i<botwidth; i++)
	{
	if(terrain.isPixelSolid((int)position.x+i, (int)position.y-1)) return true; //-1 because ABOVE the bot
	}
	return false;
}

//This will ste the text of the Speechbubble above the bot and make it visible for a few seconds.
void bot::say(sf::String text)
{
	taunttimer.restart();
	taunt.setString(text);
	taunting=true;
}

//This will choose a random string from loadTauntProfile and show it depending on the situation
void bot::say(taunttype situation)
{
	int random=-1;
	taunttimer.restart();
	if(situation==START)
	{
		random=rand()%starttauntsize;
		taunt.setString(taunt_start_List[random]);
	}
	else if(situation==FIGHT)
	{
		random=rand()%fighttauntsize;
		taunt.setString(taunt_fight_List[random]);
	}
	else if(situation==DEFEATED)
	{
		random=rand()%defeattauntsize;
		taunt.setString(taunt_defeat_List[random]);
	}
	//taunt.setString(taunt_defeat_List[random]);
	taunting=true;
}

//This is basically bot.update for the defeat or victory screen.
void bot::defeated(sf::RenderWindow &window, sf::Vector2f viewPosition)
{
	position.x=viewPosition.x+botwidth/2-100;
	position.y=viewPosition.y+botheight/2+150;
	spritePos.x=botwidth;
	spritePos.y=botheight;
	botSprite.setTextureRect(sf::IntRect(spritePos,sf::Vector2i(botwidth,botheight)));
	speechbubble.setPosition(position.x-20, position.y-50);
	taunt.setPosition(position.x-10, position.y-49);
	window.draw(speechbubble);
	window.draw(taunt);
	draw(window);
}

//The taunt profile depends fully on the skin of the bot.
void bot::loadTauntProfile(botskintype profile)
{
	switch(profile){
	case S_BOGBEARD : {
		taunt_start_List[0]="Get out of my forest!";
		taunt_start_List[1]="Feel the wrath\nof nature!";
		taunt_start_List[2]="Natures wrath is\nupon you!";
		taunt_fight_List[0]="Do not defile the\nland!";
		taunt_fight_List[1]="Mother nature\nbe with me!";
		taunt_fight_List[2]="I only respond\nto natural law!";
		taunt_fight_List[3]="I am the living\nman.";
		taunt_fight_List[4]="My trees!";
		taunt_fight_List[5]="Ruined the land!";
		taunt_fight_List[6]="Feel the thorns'\nembrace!";
		taunt_fight_List[7]="The forest holds\nmany surprises...";
		taunt_fight_List[8]="Weapons...\nare for the weak!";
		taunt_fight_List[9]="Nature is my path.";
		taunt_defeat_List[0]="Do... not defile...\n...the land...";
		taunt_defeat_List[1]="I... have failed.";
		taunt_defeat_List[2]="Nature is...\neternal...";
		break;}
	case S_LYNWOOD : {
		taunt_start_List[0]="Maggots!";
		taunt_start_List[1]="You are weak!";
		taunt_start_List[2]="CHAAARGE!";
		taunt_fight_List[0]="You're going\ndown dirtbag!";
		taunt_fight_List[1]="Yore dead freeman";
		taunt_fight_List[2]="Move your\nbutt soldier!";
		taunt_fight_List[3]="Go go go!";
		taunt_fight_List[4]="Get your\nsorry-ass moving!";
		taunt_fight_List[5]="Affirmative sir.";
		taunt_fight_List[6]="Hit the dirt\nsoldier!";
		taunt_fight_List[7]="Forward!";
		taunt_fight_List[8]="Move move move!";
		taunt_fight_List[9]="This should only\ntake a minute...";
		taunt_defeat_List[0]="I will not\ntolerate failure.";
		taunt_defeat_List[1]="You deserve a\nmedal soldier!";
		taunt_defeat_List[2]="The worm has turned.";
		break;}
	case S_FIRELORD : {					   
		taunt_start_List[0]="The whole world\nshall burn!";
		taunt_start_List[1]="The inferno\nbegins...";
		taunt_start_List[2]="By fire be purged!";
		taunt_fight_List[0]="All will burn!";
		taunt_fight_List[1]="The world heaves\nwith my torment.";
		taunt_fight_List[2]="Cast your light\nupon us!";
		taunt_fight_List[3]="Born amidst salt\nand smoke. ";
		taunt_fight_List[4]="Come the dawn\nyou shall burn.";
		taunt_fight_List[5]="Reborn...\nfrom the ashes.";
		taunt_fight_List[6]="My flames are\neternal!";
		taunt_fight_List[7]="The fire cleanses\ntheir impurity!";
		taunt_fight_List[8]="You are nothing\nbut ashes...";
		taunt_fight_List[9]="Like wildfire...";
		taunt_defeat_List[0]="The world will be\nconsumed in my flames.";
		taunt_defeat_List[1]="The night is dark\nand full of terrors...";
		taunt_defeat_List[2]="My fire... extinguished";
		break;}
	case S_TERIDAX : {
		taunt_start_List[0]="sv_cheats 1";
		taunt_start_List[1]="sv_cheats 1";
		taunt_start_List[2]="sv_cheats 1";
		taunt_fight_List[0]="Freeze.";
		taunt_fight_List[1]="impulse 101";
		taunt_fight_List[2]="Victory or death!";
		taunt_fight_List[3]="You fool...";
		taunt_fight_List[4]="You dare challenge\nme?";
		taunt_fight_List[5]="I am the darkness.";
		taunt_fight_List[6]="I thought you'd be\nbetter than this.";
		taunt_fight_List[7]="Unlimited power!";
		taunt_fight_List[8]="Success is my\nonly option.";
		taunt_fight_List[9]="Rohan is mine!";
		taunt_defeat_List[0]="How...?";
		taunt_defeat_List[1]="sv_cheats 0";
		taunt_defeat_List[2]="sv_cheats 0";
		break;}
	case S_BOT : {
		taunt_start_List[0]="Target acquired.";
		taunt_start_List[1]="Exterminate.";
		taunt_start_List[2]="Enemy spotted";
		taunt_fight_List[0]="Subjet threat level:\n-1";
		taunt_fight_List[1]="404: Mana not found";
		taunt_fight_List[2]="Anihilate.";
		taunt_fight_List[3]="The time of men\nhas come to an end.";
		taunt_fight_List[4]="I see you.";
		taunt_fight_List[5]="Destroy all humans.";
		taunt_fight_List[6]="Robit. Cheese.";
		taunt_fight_List[7]="Exterminate.";
		taunt_fight_List[8]="Beep boop.";
		taunt_fight_List[9]="1110 1111\n1111 0010"; //shortened verison of "noob" translated to binary
		taunt_defeat_List[0]="CRITICAL ERROR";
		taunt_defeat_List[1]="The cake is a lie.";
		taunt_defeat_List[2]="0x0000001";
		break;}
	case S_LANCE : {
		taunt_start_List[0]="I've been expecting\nyou...";
		taunt_start_List[1]="Good luck,\nyou'll need it.";
		taunt_start_List[2]="I have been waiting\nfor you.";
		taunt_fight_List[0]="Outstanding!";
		taunt_fight_List[1]="I stand for\njustice!";
		taunt_fight_List[2]="The force is strong\nwith this one.";
		taunt_fight_List[3]="I have stood before\na thousand...";
		taunt_fight_List[4]="We finally meet...";
		taunt_fight_List[5]="A worthy opponent.";
		taunt_fight_List[6]="I will fight with\nhonour!";
		taunt_fight_List[7]="Skinc is love,\nSkinc is life.";
		taunt_fight_List[8]="I sense real\ntalent in you.";
		taunt_fight_List[9]="I never give up!";
		taunt_defeat_List[0]="...It's over.";
		taunt_defeat_List[1]="Victory is yours.";
		taunt_defeat_List[2]="You have become\ntruly powerful.";
		break;}
	default : {
		taunt_start_List[0]="Let the games begin!";
		taunt_start_List[1]="Let's fight!";
		taunt_start_List[2]="gl hf";
		taunt_fight_List[0]="Ouch!";
		taunt_fight_List[1]="Ha-ha!";
		taunt_fight_List[2]="Die!";
		taunt_fight_List[3]="You underestimate\nmy power!";
		taunt_fight_List[4]="Is this all you\nhave to offer?";
		taunt_fight_List[5]="!!!";
		taunt_fight_List[6]="I will not\nallow this!";
		taunt_fight_List[7]="Your death\nis imminent!";
		taunt_fight_List[8]="Fight until\nthe end!";
		taunt_fight_List[9]="Wow!";
		taunt_defeat_List[0]="I feel...\ncold.";
		taunt_defeat_List[1]="You win,\nthis time.";
		taunt_defeat_List[2]="gg wp";
		break;}
	}
}


void bot::loadDifficultyProfile(difficulty dif)
{
	/* STANDARD STATS:
	float reactiontime=1;
	float actiontime=1;
	const int cone=1000;
	const float safe=0.05;
	const float highrisk=0.4;
	const int shootmana=90;
	const int stockmana=20;
	const float aimspeed=0.05;*/
	switch(dif) {
	case EASY : {
		reactiontime=1.3;
		actiontime=1;
		cone=1000;
		safe=0.1;
		highrisk=0.5;
		shootmana=90;
		stockmana=0;
		aimspeed=0.03;
		break;}
	case STANDARD : {
		reactiontime=1;
		actiontime=1;
		cone=1000;
		safe=0.05;
		highrisk=0.4;
		shootmana=90;
		stockmana=20;
		aimspeed=0.05;
		break;}
	case MEDIUM : {
		reactiontime=0.8;
		actiontime=1.2;
		cone=500;
		safe=0.05;
		highrisk=0.35;
		shootmana=100;
		stockmana=20;
		aimspeed=0.08;
		break;}
	case HARD : {
		reactiontime=0.5;
		actiontime=1.3;
		cone=200;
		safe=0.06;
		highrisk=0.3;
		shootmana=110;
		stockmana=15;
		aimspeed=0.1;
		break;}
	case CHEATING : {
		reactiontime=0.9;
		actiontime=1;
		cone=100;
		safe=0.05;
		highrisk=0.4;
		shootmana=100;
		stockmana=20;
		aimspeed=0.02;
		break;}
	case MERCILESS : {
		reactiontime=0.5;
		actiontime=1.3;
		cone=100;
		safe=0.04;
		highrisk=0.3;
		shootmana=130;
		stockmana=20;
		aimspeed=0.2;
		break;}
	}
}