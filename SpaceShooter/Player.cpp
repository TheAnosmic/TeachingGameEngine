#include "Player.h"


Player::Player(int startPositionX, int startPositionY) :
defaultBitmap(8), leftStrafeBitmap(8), rightStrafeBitmap(8)
{
	this->currentPosition.x = startPositionX;
	this->currentPosition.y = startPositionY;
	this->moveSpeed = 2;
	this->defaultBitmap.bits = new byte[8]
	{ 0b00011000,
		0b00100100,
		0b00100100,
		0b01100110,
		0b01000010,
		0b01000010,
		0b10100101,
		0b01000010 };
	this->defaultBitmap.width = 8;
	this->defaultBitmap.height = 8;

	this->leftStrafeBitmap.bits = new byte[8]
	{	0b00010000,
		0b00101000,
		0b00101000,
		0b01101100,
		0b01000100,
		0b01000100,
		0b10101010,
		0b01000100 };
	this->leftStrafeBitmap.width = 8;
	this->leftStrafeBitmap.height = 8;

	this->rightStrafeBitmap.bits = new byte[8]
	{	0b00001000,
		0b00010100,
		0b00010100,
		0b00110110,
		0b00100010,
		0b00100010,
		0b01010101,
		0b00100010 };
	this->rightStrafeBitmap.width = 8;
	this->rightStrafeBitmap.height = 8;
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
