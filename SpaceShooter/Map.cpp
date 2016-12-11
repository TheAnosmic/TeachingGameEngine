#include "Map.h"
#include "WorldState.h"


Map::Map(const Point& startPoint)
{
	Point point(startPoint);

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			Enemy* enemy = &enemies[i * 5 + j];
			enemy->SetPosition(point.x, point.y);
			point.x += 10;
		}
		point.x = startPoint.x;
		point.y += 10;
	}
}

void Map::AddEnemies(WorldState *worldState)
{
	worldState->enemies = enemies;
	worldState->enemiesSize = ENEMY_COUNT;
}
