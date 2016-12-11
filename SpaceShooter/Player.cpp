#include "Player.h"
#include "Bullet.h"
#include "WorldState.h"

const byte defaultPlayerBitmap[] PROGMEM =
{ 
0b00011000,
0b00100100,
0b00100100,
0b01100110,
0b01000010,
0b01000010,
0b10100101,
0b01000010 
};

const byte leftStrafePlayerBitmap[] PROGMEM =
{ 
0b00010000,
0b00101000,
0b00101000,
0b01101100,
0b01000100,
0b01000100,
0b10101010,
0b01000100 
};

const byte rightStrafePlayerBitmap[] PROGMEM =
{ 
0b00001000,
0b00010100,
0b00010100,
0b00110110,
0b00100010,
0b00100010,
0b01010101,
0b00100010 
};

const byte heartFullBitmap[] PROGMEM =
{ 
0b01101100,
0b11111110,
0b11111110,
0b01111100,
0b00111000,
0b00010000 
};


const byte heartEmptyBitmap[] PROGMEM =
{ 
0b01101100,
0b10010010,
0b10000010,
0b01000100,
0b00101000,
0b00010000 
};

Player::Player(short x, short y) : GameObject(x, y),
                               moveSpeed(2),
                               defaultBitmap(defaultPlayerBitmap, 8, 8),
                               leftStrafeBitmap(leftStrafePlayerBitmap, 8, 8),
                               rightStrafeBitmap(rightStrafePlayerBitmap, 8, 8),
                               heartFull(heartFullBitmap, 8, 6),
                               heartEmpty(heartEmptyBitmap, 8, 6),
							   currentStrafe(CurrentStrafe::CENTER)
{
}


bool Player::AllowedToShoot() const
{
	unsigned long currentTime = millis();
	return this->lastShootTime + this->shootInterval <= currentTime;
}

void Player::UpdateShootTime()
{
	this->lastShootTime = millis();
}

void Player::HandleInput(Input input)
{
	int movement = 0;
	if (input.left)
	{
		movement -= this->moveSpeed;
	}

	if (input.right)
	{
		movement += this->moveSpeed;
	}

	if (movement > 0)
	{
		this->currentStrafe = CurrentStrafe::RIGHT;
	} else if (movement < 0)
	{
		this->currentStrafe = CurrentStrafe::LEFT;
	} else
	{
		this->currentStrafe = CurrentStrafe::CENTER;
	}
	this->position.x += movement;

	if (input.trigger)
	{
		if (this->AllowedToShoot())
		{
			UpdateShootTime();
			Point bulletPoint(this->position.x + 8 / 2, this->position.y);
			Bullet::Create(bulletPoint);
		}
	}
	
}


const Bitmap& Player::GetBitmap() const
{
	switch (currentStrafe)
	{
	case CurrentStrafe::LEFT:
		return leftStrafeBitmap;
	case CurrentStrafe::RIGHT:
		return rightStrafeBitmap;
	case CurrentStrafe::CENTER:
	default:
		return defaultBitmap;
	}
}

bool Player::IsAlive() const
{
	return true;
}

const Bitmap& Player::GetHeart(byte i) const
{
	if (i < 2)
	{
		return heartFull;
	}
	return heartEmpty;
}

void Player::ActOnFrame()
{
}
