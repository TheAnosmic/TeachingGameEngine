#ifndef _BULLET_h
#define _BULLET_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include "GameObject.h"

class Bullet : GameObject
{
public:
	explicit Bullet(const Point& position)
		: GameObject(position)
	{
	}

	void ActOnFrame() override;
	const Bitmap& GetBitmap() const override;
	Point GetPosition() const override;

};


#endif

