#define screenwidth 1280
#define screenheight 924
#define playerwidth 40
#define playerheight 70
#define PI 3.1416
#define botheight 70
#define botwidth 40
#define mapheight 920//actual map-height minus stable, non-destructible floor (actual is 924)
#define mapwidth 1280
#define g 25 //gravity
#define attackcooldown 3
#define nukecooldown 15
#define createearthcooldown 15
#define tauntcooldown 18
#define nukeradius 50
#define fighttauntsize 10
#define starttauntsize 3
#define defeattauntsize 3

#ifndef _global_values_
#define _global_values_
typedef enum state{ATTACK, DEFEND, LOAD, IDLE};
typedef enum map{BASE, FOREST, DESERT, VOLCANO, CRYSTAL, INDUSTRIAL, ARENA, CUSTOMMAP};
typedef enum difficulty{EASY, STANDARD, MEDIUM, HARD, CHEATING, MERCILESS};
typedef enum window{MAIN, CHAMPIONSHIP, CREDITS, LOADING, CLOSE, PROFILE, CUSTOM, SPLASH};
typedef enum gamemode{CUSTOMGAME, CHAMP, TUTOR};
typedef enum skintype {DEMENTOR=1, ALTAIR, FREEMAN, ASH};
typedef enum botskintype {T_TRAININGDUMMY=0, B_DEMENTOR=1, B_ALTAIR, B_FREEMAN, B_ASH, S_BOGBEARD, S_LYNWOOD, S_FIRELORD, S_TERIDAX, S_BOT, S_LANCE};
typedef enum cheats {SUDDENHEAL, CLOAK, TELEPORT, SSAIYAN, INACTIVE};
typedef enum tutorialsteps {L_MOVE=1, L_RECHARGE, L_SHOOT, L_USESHIELD, L_HSHIELD, L_FLY, L_CEARTH, L_NUKE, L_CHAMP, L_PRACTICE, L_END};
typedef enum taunttype {START, FIGHT, DEFEATED};
extern window nextwindow;
#endif