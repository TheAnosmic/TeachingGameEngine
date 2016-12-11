// DynamicGameObject.h

#ifndef _DYNAMICGAMEOBJECT_h
#define _DYNAMICGAMEOBJECT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include "GameObject.h"

class DynaminGameObject : public GameObject
{
public:
	explicit DynaminGameObject(const Point& position);

	DynaminGameObject *prev;
	DynaminGameObject *next;

	void Detach()
	{
		if (prev != nullptr)
		{
			prev->next = next;
		}
		if (next != nullptr)
		{
			next->prev = prev;
		}
	}

	virtual void Destroy() = 0;
};

#endif

