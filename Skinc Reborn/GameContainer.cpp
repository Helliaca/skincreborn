#include "GameContainer.h"



GameContainer::GameContainer(void)
{
	gmode=CUSTOMGAME;
	map_sprite.scale(0.5,0.5);
	pl_sprite.scale(0.8,0.8);
}

void GameContainer::launch()
{
	loadingscreen.create(sf::VideoMode(550,350), "LOADING");
	sf::Event start;

	//SET STATS AND OUTPUT LORE (in case of Championship)
	if(gmode==CHAMP)
	{
		switch(p_level){
		case NEWB : {g_botskin=S_BOGBEARD; break;}
		case BOGBEARD : {g_botskin=S_BOGBEARD; g_map=FOREST; g_diff=STANDARD; g_bothealth=300; g_botspeed=10200; g_botfirepower=30; name="Reiny Bogbeard"; lore="As a practitioner of the druidical arts,\nReiny is fascinated by the magic of nature magic and,\ntherefore, is perfectly at home in the ancient\nforest of the island. Eager to advance in the championship\nin order to stop the tainting pollution from the\nindustrial area further north he has become\na supreme fighter, despite his considerable age."; break;}
		case LYNWOOD : {g_botskin=S_LYNWOOD; g_map=DESERT; g_diff=MEDIUM; g_bothealth=500; g_botspeed=10500; g_botfirepower=40; name="Captain Lynwood"; lore="Previously known as Corporal Lynwood, the old war\nveteran was promoted to the rank of Captain.\nHis endeavours in the army made him a master tactician,\nwhat helped him maintain his position amongst the\nSkinc-Champions throughout the years."; break;}
		case FIRELORD : {g_botskin=S_FIRELORD; g_map=VOLCANO; g_diff=MEDIUM; g_bothealth=666; g_botspeed=11500; g_botfirepower=60; name="Zydar the Firelord"; lore="According to druid Bogbeard,\nZydar would see the world burn\nif he could be king of the ashes.\nForged in pain, this arch-warlock of the fires has\nsettled himself at the cursed volcano\nto the west of the island.\n"; break;}
		case TERIDAX : {g_botskin=S_TERIDAX; g_map=CRYSTAL; g_diff=CHEATING; g_bothealth=1337; g_botspeed=11000; g_botfirepower=40; name="Nadir Teridax"; lore="Once an honored and respected warrior, Nadir was\ncorrupted by the shadows and embarked on a path\nof death and darkness. Known to have fully embraced\nthe arts of cheating, Nadir has been wreaking havoc\nin the hostile crystal caverns."; break;}
		case BOT : {g_botskin=S_BOT; g_map=INDUSTRIAL; g_diff=HARD; g_bothealth=1994; g_botspeed=10500; g_botfirepower=100; name="Project THS-1338"; lore="The product of the greatest scientists of Darksteam-City\nuniting with the distinct purpose of creating\na machine with a single purpose: killing.\nUsing the best cognitive-computing-processors,\nTHS-1338 is known to have almost impecable aiming capabilites."; break;}
		case LANCE : {g_botskin=S_LANCE; g_map=ARENA; g_diff=MERCILESS; g_bothealth=3000; g_botspeed=12000; g_botfirepower=120; name="Lance"; lore="Known to be the most extraordinatry warrior,\nLance has faced and defeated all the hazards the island\nhad to offer.\nHe has defended his rank as the Skinc champion\nfor a long time against all sorts of enemies.\nHe will not go down without a bloody fight.\n"; break;}
		case COMPLETE : {g_botskin=S_BOGBEARD; break;}
		default : {g_botskin=S_BOGBEARD; break;}
		}
	}
	//SET STATS for Tutorial
	else if(gmode==TUTOR)
	{
		g_map=BASE;
		g_bothealth=100;
		g_botspeed=1;
		g_botfirepower=10;
		g_botskin=T_TRAININGDUMMY;
		g_diff=EASY;
	}
	else {lore=""; name="";}

	initializeLoadingScreen();
	updateLoadingScreen();

	//Get available spells:
	bool fly = (p_level > BOGBEARD);
	bool nuke = (p_level > LYNWOOD);
	bool createearth = (p_level > FIRELORD);

	Engine mainengine(g_map, p_speed, p_firepower, p_health, g_bothealth, g_botspeed, g_botfirepower, p_skin, g_botskin, g_diff, createearth, fly, nuke);
	t_status.setString("- Ready! Press Spacebar to start! -");
	while(loadingscreen.isOpen())
	{
		updateLoadingScreen();
		while( loadingscreen.pollEvent(start))
		{
		if(start.type == sf::Event::Closed || (start.type == sf::Event::KeyReleased && start.key.code == sf::Keyboard::Space)) loadingscreen.close();
		}
	}

	int score;
	if(gmode!=TUTOR) score=mainengine.GameLoop();
	else score=mainengine.TutorialLoop();

	//If player wins in championship, gain a level and better stats.
	if (score>0 && gmode==CHAMP) {
		switch(p_level){
		case NEWB : {p_level=BOGBEARD; break;}
		case BOGBEARD : {p_level=LYNWOOD; p_health+=200; p_speed+=400; p_firepower+=10; break;}
		case LYNWOOD : {p_level=FIRELORD; p_health+=200; p_speed+=400; p_firepower+=10; break;}
		case FIRELORD : {p_level=TERIDAX; p_health+=300; p_speed+=400; p_firepower+=10; break;}
		case TERIDAX : {p_level=BOT; p_health+=500; p_speed+=400; p_firepower+=15; break;}
		case BOT : {p_level=LANCE; p_health+=1000; p_speed+=400; p_firepower+=15; break;}
		case LANCE : {p_level=COMPLETE; p_health+=2500; p_speed+=400; p_firepower+=10; break;}
		case COMPLETE : {p_level=COMPLETE; break;}
		default : {break;}
		}
		p_lvluppoints++;
		nextwindow=CHAMPIONSHIP;
	}
}


void GameContainer::initializeLoadingScreen()
{
	if(gmode!=TUTOR && !bg_texture.loadFromFile("menuresource/loading_screen_bg.png")) std::cout<<"No file found (loadingscreenPNG)"<<std::endl;
	else if(gmode==TUTOR && !bg_texture.loadFromFile("menuresource/loading_screen_bgtut.png")) std::cout<<"No file found (loadingscreentutorialPNG)"<<std::endl;
	bg_sprite.setTexture(bg_texture);
	bg_sprite.setPosition(0,0);

	switch(g_map){
	case BASE : {if(!map_texture.loadFromFile("menuresource/map_sp/splash_base.png")) std::cout<<"No file found (splashBasePNG)"<<std::endl; break;}
	case FOREST : {if(!map_texture.loadFromFile("menuresource/map_sp/splash_forest.png")) std::cout<<"No file found (splashForestPNG)"<<std::endl; break;}
	case DESERT : {if(!map_texture.loadFromFile("menuresource/map_sp/splash_desert.png")) std::cout<<"No file found (splashDesertPNG)"<<std::endl; break;}
	case VOLCANO : {if(!map_texture.loadFromFile("menuresource/map_sp/splash_volcano.png")) std::cout<<"No file found (splashVolcanoPNG)"<<std::endl; break;}
	case CRYSTAL : {if(!map_texture.loadFromFile("menuresource/map_sp/splash_crystal.png")) std::cout<<"No file found (splashCrystalPNG)"<<std::endl; break;}
	case INDUSTRIAL : {if(!map_texture.loadFromFile("menuresource/map_sp/splash_industrial.png")) std::cout<<"No file found (splashIndustrialPNG)"<<std::endl; break;}
	case ARENA : {if(!map_texture.loadFromFile("menuresource/map_sp/splash_arena.png")) std::cout<<"No file found (splashArenaPNG)"<<std::endl; break;}
	default : {if(!map_texture.loadFromFile("menuresource/map_sp/splash_base.png")) std::cout<<"No file found (splashBasePNG)"<<std::endl; break;}
	}
	map_sprite.setTexture(map_texture);
	//map_sprite.scale(0.5,0.5); moved to constructor
	map_sprite.setPosition(10,230);

	switch(g_botskin){
	case B_DEMENTOR : {if(!pl_texture.loadFromFile("menuresource/splash_dementor.png")) std::cout<<"No file found (splashDementorPNG)"<<std::endl; break;}
	case B_ALTAIR : {if(!pl_texture.loadFromFile("menuresource/splash_altair.png")) std::cout<<"No file found (splashAltairPNG)"<<std::endl; break;}
	case B_FREEMAN : {if(!pl_texture.loadFromFile("menuresource/splash_freeman.png")) std::cout<<"No file found (splashFreemanPNG)"<<std::endl; break;}
	case B_ASH : {if(!pl_texture.loadFromFile("menuresource/splash_ash.png")) std::cout<<"No file found (splashAshPNG)"<<std::endl; break;}
	case S_BOGBEARD : {if(!pl_texture.loadFromFile("menuresource/splash_bogbeard.png")) std::cout<<"No file found (splashBogbeardPNG)"<<std::endl; break;}
	case S_LYNWOOD : {if(!pl_texture.loadFromFile("menuresource/splash_lynwood.png")) std::cout<<"No file found (splashLynwoodPNG)"<<std::endl; break;}
	case S_FIRELORD : {if(!pl_texture.loadFromFile("menuresource/splash_firelord.png")) std::cout<<"No file found (splashFirelordPNG)"<<std::endl; break;}
	case S_TERIDAX : {if(!pl_texture.loadFromFile("menuresource/splash_teridax.png")) std::cout<<"No file found (splashTeridaxPNG)"<<std::endl; break;}
	case S_BOT : {if(!pl_texture.loadFromFile("menuresource/splash_bot.png")) std::cout<<"No file found (splashBotPNG)"<<std::endl; break;}
	case S_LANCE : {if(!pl_texture.loadFromFile("menuresource/splash_lance.png")) std::cout<<"No file found (splashLancePNG)"<<std::endl; break;}
	default : {if(!pl_texture.loadFromFile("menuresource/splash_dementor.png")) std::cout<<"No file found (splashDementorPNG)"<<std::endl; break;}
	}
	pl_sprite.setTexture(pl_texture);
	//pl_sprite.scale(0.8,0.8); moved to constructor
	pl_sprite.setPosition(10,50);

	switch(g_map){
	case BASE : {map="Training Grounds\n"; break;}
	case FOREST : {map="Sacred Forest\n"; break;}
	case DESERT : {map="Enchanted Desert\n"; break;}
	case VOLCANO : {map="Forsaken Mountain\n"; break;}
	case CRYSTAL : {map="Crystal Caves\n"; break;}
	case INDUSTRIAL : {map="Darksteam Citadel\n"; break;}
	case ARENA : {map="Skinc Arena"; break;}
	default : {map=""; break;}
	}

	switch(g_diff){
	case EASY : {difficulty="Easy"; break;};
	case STANDARD : {difficulty="Standard"; break;};
	case MEDIUM : {difficulty="Medium"; break;};
	case CHEATING : {difficulty="Cheating"; break;};
	case HARD : {difficulty="Hard"; break;};
	case MERCILESS : {difficulty="Merciless"; break;};
	default : {difficulty="?"; break;};
	}

	if(!t_font.loadFromFile("resource/Bilbo.otf")) std::cout<<"No file found(fontOTF)"<<std::endl;
	t_string.str("");
	t_string<<name<<"\nDifficulty: "<<difficulty<<"\n"<<lore<<"\n\nMap: "<<map;
	t_text=sf::Text(t_string.str(),t_font);
	t_text.setCharacterSize(23);
	t_text.setPosition(160,0);
	if(!t_sfont.loadFromFile("resource/8bit_font.ttf")) std::cout<<"No file found(fontTTF)"<<std::endl;
	if(gmode==TUTOR) t_status=sf::Text("Loading tutorial...",t_sfont);
	else t_status=sf::Text("Loading...",t_sfont);
	t_status.setCharacterSize(25);
	t_status.setColor(sf::Color::Red);
	t_status.setPosition(170,260);
}


void GameContainer::updateLoadingScreen()
{
	if(gmode==TUTOR)
	{
		loadingscreen.clear();
		loadingscreen.draw(bg_sprite);
		loadingscreen.draw(map_sprite);
		t_text.setString("Map: Training Gorunds\nMode: Tutorial");
		loadingscreen.draw(t_text);
		loadingscreen.draw(t_status);
		loadingscreen.display();
	}
	else {
		loadingscreen.clear();
		loadingscreen.draw(bg_sprite);
		loadingscreen.draw(pl_sprite);
		loadingscreen.draw(map_sprite);
		loadingscreen.draw(t_text);
		loadingscreen.draw(t_status);
		loadingscreen.display();
	}
}
