// 
// 
// 

#include "Bullet.h"



void Bullet::ActOnFrame()
{
	this->position.y += 3;
}

const Bitmap& Bullet::GetBitmap() const
{
	return Bitmap::OnePixel();
}

Point Bullet::GetPosition() const
{
	return this->position;
}
