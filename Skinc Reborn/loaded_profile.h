#include <string>
#include "global_values.h"

#ifndef _loaded_profile_
#define _loaded_profile_

typedef enum level {NEWB=0, BOGBEARD=1, LYNWOOD=2, FIRELORD=3, TERIDAX=4, BOT=5, LANCE=6, COMPLETE=7};

extern std::string p_name; 
extern skintype p_skin; 
extern bool p_firststart;
extern level p_level;
extern int p_health;
extern int p_speed;
extern int p_firepower;
extern int p_lvluppoints;



#endif