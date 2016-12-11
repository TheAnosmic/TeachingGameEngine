#include <Adafruit_SSD1306.h>
#include "Bullet.h"
#include "WorldState.h"

static const byte NUM_BULLETS = 10;
static Bullet bullets[NUM_BULLETS];

Bullet::Bullet() : GameObject(Point(-1, -1))
{

}


void Bullet::ActOnFrame()
{
	this->position.y -= 3;
}

const Bitmap& Bullet::GetBitmap() const
{
	return Bitmap::OnePixel();
}

bool Bullet::IsAlive() const
{
	return position.y >= 0;
}

GameObject* Bullet::Create(const Point& point)
{
	if (WorldState::instance()->bullets == nullptr)
	{
		WorldState::instance()->bullets = bullets;
		WorldState::instance()->bulletsSize = NUM_BULLETS;
	}
	for (int i = 0; i < NUM_BULLETS; ++i)
	{
		if (!bullets[i].IsAlive())
		{
			bullets[i].SetPosition(point);
			return &bullets[i];
		}
	}
	return nullptr;
}

void Bullet::Destroy()
{
	position.y = -1;
}
