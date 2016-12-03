#ifndef _GAMEOBJECT_h
#define _GAMEOBJECT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include "Bitmap.h"
#include "Point.h"

class GameObject
{
public:

	GameObject(const Point& position);
	virtual ~GameObject()
	{
	}

	virtual void ActOnFrame() = 0;
	virtual const Bitmap& GetBitmap() const = 0;
	virtual Point GetPosition() const = 0;

protected:
	Point position;
};

#endif

