// Map.h

#ifndef _MAP_h
#define _MAP_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include "Enemy.h"
#include "WorldState.h"

static const byte ENEMY_COUNT = 15;

class Map
{
public:
	explicit Map(const Point& startPoint);
	void AddEnemies(WorldState* worldState);
private:
	Enemy enemies[ENEMY_COUNT];
};

#endif

