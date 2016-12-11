// Player.h

#ifndef _PLAYER_h
#define _PLAYER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include "GameObject.h"
#include "Input.h"
#include "Bitmap.h"

enum class CurrentStrafe : byte
{
	CENTER,
	LEFT,
	RIGHT
};

class Player : public GameObject
{
public:
	Player(short x, short y);
	bool AllowedToShoot() const;
	void UpdateShootTime();
	void HandleInput(Input input);
	const Bitmap& GetHeart(byte i) const;
	void ActOnFrame() override;
	const Bitmap& GetBitmap() const override;
	bool IsAlive() const override;
private:
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

