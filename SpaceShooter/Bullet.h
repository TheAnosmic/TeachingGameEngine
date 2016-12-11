#ifndef _BULLET_h
#define _BULLET_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include "GameObject.h"
#include "Bitmap.h"

class Bullet : public GameObject
{
public:
	Bullet();

	void ActOnFrame() override;
	const Bitmap& GetBitmap() const override;
	bool IsAlive() const override;


	static GameObject* Create(const Point& point);
	void Destroy() override;
};


#endif

