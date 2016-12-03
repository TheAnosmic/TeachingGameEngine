#include "WorldState.h"


WorldState::WorldState(const Player& player) : player(player)
{
}

void WorldState::InitInstance(const Player& player)
{
	WorldState::currentWorldState = new WorldState(player);
}

WorldState* WorldState::instance()
{
	return currentWorldState;
}


WorldState* WorldState::currentWorldState = nullptr;
