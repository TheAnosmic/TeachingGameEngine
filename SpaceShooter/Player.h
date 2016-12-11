// Player.h

#ifndef _PLAYER_h
#define _PLAYER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include "Point.h"
#include "Input.h"
#include "Bitmap.h"

enum class CurrentStrafe
{
	CENTER,
	LEFT,
	RIGHT
};

class Player
{
public:
	Player(int startPositionX, int startPositionY);
	bool AllowedToShoot() const;
	void UpdateShootTime();
	void HandleInput(Input input);
	Point GetPosition() const;
	const Bitmap& GitBitmap() const;
	const Bitmap& GetHeart(int i) const;
private:
	Point currentPosition;
	int moveSpeed;
	Bitmap defaultBitmap;
	Bitmap leftStrafeBitmap;
	Bitmap rightStrafeBitmap;
	Bitmap heartFull;
	Bitmap heartEmpty;
	CurrentStrafe currentStrafe;
	long long lastShootTime = 0;
	const int shootInterval = 100;
};

#endif

