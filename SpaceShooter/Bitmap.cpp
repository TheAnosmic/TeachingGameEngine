#include "Bitmap.h"
#include <avr/pgmspace.h>

const byte black[] PROGMEM = { 0b11111111 };

Bitmap::Bitmap(const byte* data, byte width, byte height): width(width), height(height), data(data)
{
}


byte Bitmap::GetByte(byte position) const
{
	return pgm_read_byte_near(data + position);
}

Bitmap::~Bitmap()
{
}

void Bitmap::DebugPrint() const
{
	for (int i = 0; i < height; ++i)
	{
		byte b = GetByte(i);
		for (int j = 0; j < width; ++j)
		{
			if (b & (1 << j))
			{
				Serial.print("#");
			} else
			{
				Serial.print("-");
			}
		}
		Serial.println();
	}
}

Bitmap* Bitmap::m_OnePixel = nullptr;

const Bitmap& Bitmap::OnePixel()
{
	if (m_OnePixel == nullptr)
	{
		m_OnePixel = new Bitmap(black, 1, 1);
	}
	return *m_OnePixel;
}