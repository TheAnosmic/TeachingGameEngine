#include "Enemy.h"

const byte enemyDefaultBitmap[] PROGMEM =
{
	0b11000110,
	0b10111010,
	0b00000000,
	0b10101010,
	0b01010100,
	0b00111000
};


Enemy::Enemy() : GameObject(0, 0)
{
}

void Enemy::ActOnFrame()
{

}

const Bitmap& Enemy::GetBitmap() const
{
	return *Enemy::bitmap;
}

bool Enemy::IsAlive() const
{
	return position.x > 0;
}

void Enemy::SetPosition(short x, short y)
{
	position.x = x;
	position.y = y;
}

byte Enemy::GetWidth()
{
	return 10;
}

void Enemy::Destroy()
{
	position.x = -1;
}

Bitmap *Enemy::bitmap = new Bitmap(enemyDefaultBitmap, 8, 6);
