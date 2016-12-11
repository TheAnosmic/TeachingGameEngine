#include "WorldState.h"

WorldState::WorldState(const Player& player) : 
player(player),
bullets(nullptr),
bulletsSize(0),
enemies(nullptr),
enemiesSize(0)
{
}

void WorldState::InitInstance(const Player& player)
{
	currentWorldState = new WorldState(player);
}

WorldState* WorldState::instance()
{
	return currentWorldState;
}



WorldState* WorldState::currentWorldState = nullptr;
