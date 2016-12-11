#include "WorldState.h"

WorldState::WorldState(const Player& player) : player(player), dynamicObjectsHead(nullptr)
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

void WorldState::AddGameObject(GameObject* gameObject)
{
	gameObjects[gameObjectsIndex] = gameObject;
	gameObjectsIndex++;
}

void WorldState::AddDynamicGameObject(DynaminGameObject* gameObject)
{
	DynaminGameObject* formerHead = this->dynamicObjectsHead;
	this->dynamicObjectsHead = gameObject;
	gameObject->SetNext(formerHead);
}

GameObject** WorldState::GetGameObjects()
{
	return gameObjects;
}

int WorldState::GetLastGameObjectIndex() const
{
	return gameObjectsIndex;
}

DynaminGameObject* WorldState::GetDynamicGameObjectsHead()
{
	return this->dynamicObjectsHead;
}

WorldState* WorldState::currentWorldState = nullptr;
