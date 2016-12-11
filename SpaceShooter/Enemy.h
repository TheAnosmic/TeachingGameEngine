#ifndef _ENEMY_h
#define _ENEMY_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include "GameObject.h"




class Enemy : public GameObject
{
public:
	Enemy();
	explicit Enemy(const Point& position)
		: GameObject(position)
	{
	}

	void ActOnFrame() override;
	const Bitmap& GetBitmap() const override;
	bool IsAlive() const override;
	void SetPosition(short x, short y);
	static byte GetWidth();


	void Destroy() override;
	static const byte width = 7;
	static const byte height = 7;
private:
	static Bitmap *bitmap;
};

#endif

