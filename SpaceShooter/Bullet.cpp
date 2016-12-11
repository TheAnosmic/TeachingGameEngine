// 
// 
// 

#include <Adafruit_SSD1306.h>
#include "Bullet.h"


void Bullet::ActOnFrame()
{
	this->position.y -= 3;
}

const Bitmap& Bullet::GetBitmap() const
{
	return Bitmap::OnePixel();
}

Point Bullet::GetPosition() const
{
	return this->position;
}

bool Bullet::IsAlive() const
{
	return position.x >= 0 && position.x <= SSD1306_LCDWIDTH &&
		position.y >= 0 && position.y <= SSD1306_LCDHEIGHT;
}