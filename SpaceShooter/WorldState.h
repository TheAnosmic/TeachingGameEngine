#ifndef _WORLDSTATE_h
#define _WORLDSTATE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Player.h"
#include "GameObject.h"
#include "DynamicGameObject.h"

class WorldState
{
	static WorldState* currentWorldState;
	explicit WorldState(const Player& player);

public:
	static void InitInstance(const Player& player);
	static WorldState* instance();
	const Player &player;
	/**
	 * \brief Adds a game object to the currently lived objects
	 * \param gameObject - pointer on the heap, WorldState will take ownership of the pointer.
	 */
	void AddGameObject(GameObject* gameObject);
	void AddDynamicGameObject(DynaminGameObject* gameObject);

	GameObject** GetGameObjects();
	int GetLastGameObjectIndex() const;
	DynaminGameObject* GetDynamicGameObjectsHead();

private:
	int gameObjectsIndex = 0;
	GameObject** gameObjects = new GameObject*[30];
	DynaminGameObject* dynamicObjectsHead;
};


#endif

