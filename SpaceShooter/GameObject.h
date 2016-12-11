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
protected:
	Point position;

public:
	GameObject(short x, short y);
	GameObject(const Point& position);
	virtual ~GameObject()
	{
	}

	virtual void ActOnFrame() = 0;
	virtual const Bitmap& GetBitmap() const = 0;
	virtual const Point& GetPosition() const { return position; };
	void SetPosition(const Point& point) { position = point; };
	virtual bool IsAlive() const = 0;
	virtual void Destroy() { };

};

#endif

