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
	void HandleInput(Input input);
	Point GetPosition() const;
	const Bitmap& GitBitmap() const;
private:
	Point currentPosition;
	int moveSpeed;
	Bitmap defaultBitmap;
	Bitmap leftStrafeBitmap;
	Bitmap rightStrafeBitmap;
	CurrentStrafe currentStrafe;
};

#endif

