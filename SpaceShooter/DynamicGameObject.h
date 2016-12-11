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

	DynaminGameObject* GetNext();
	void SetNext(DynaminGameObject *next);

private:
	DynaminGameObject *next;
};

#endif

