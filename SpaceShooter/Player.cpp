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

Player::Player(int startPositionX, int startPositionY) :
defaultBitmap(defaultPlayerBitmap), 
leftStrafeBitmap(leftStrafePlayerBitmap), 
rightStrafeBitmap(rightStrafePlayerBitmap),
heartFull(heartFullBitmap),
heartEmpty(heartEmptyBitmap)
{
	this->currentPosition.x = startPositionX;
	this->currentPosition.y = startPositionY;
	this->moveSpeed = 2;

	this->defaultBitmap.width = 8;
	this->defaultBitmap.height = 8;

	this->leftStrafeBitmap.width = 8;
	this->leftStrafeBitmap.height = 8;

	this->rightStrafeBitmap.width = 8;
	this->rightStrafeBitmap.height = 8;

	this->heartEmpty.width = 8;
	this->heartEmpty.height = 6;

	this->heartFull.width = 8;
	this->heartFull.height = 6;

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
	this->currentPosition.x += movement;

	if (input.trigger)
	{
		if (this->AllowedToShoot())
		{
			UpdateShootTime();
			Point bulletPoint;
			bulletPoint.y = currentPosition.y;
			bulletPoint.x = currentPosition.x + 8 / 2;
			Bullet* bullet = new Bullet(bulletPoint);
			WorldState::instance()->AddDynamicGameObject(bullet);
		}
	}
	
}

Point Player::GetPosition() const
{
	return this->currentPosition;
}

const Bitmap& Player::GitBitmap() const
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

const Bitmap& Player::GetHeart(int i) const
{
	if (i < 2)
	{
		return heartFull;
	}
	return heartEmpty;
}
