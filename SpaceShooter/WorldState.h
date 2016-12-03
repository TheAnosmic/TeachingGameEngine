#ifndef _WORLDSTATE_h
#define _WORLDSTATE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Player.h"

class WorldState
{
	static WorldState* currentWorldState;
	explicit WorldState(const Player& player);

public:
	static void InitInstance(const Player& player);
	static WorldState* instance();
	const Player &player;

};


#endif

