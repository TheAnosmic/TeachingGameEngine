#ifndef _BULLET_h
#define _BULLET_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include "DynamicGameObject.h"
#include "Bitmap.h"

class Bullet : public DynaminGameObject
{
public:
	explicit Bullet(const Point& position)
		: DynaminGameObject(position)
	{
	}

	void ActOnFrame() override;
	const Bitmap& GetBitmap() const override;
	Point GetPosition() const override;
	bool IsAlive() const override;
};


#endif

