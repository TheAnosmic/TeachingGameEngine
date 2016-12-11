#include "Bitmap.h"
#include <avr/pgmspace.h>


Bitmap::Bitmap(const byte* data)
{
	this->data = data;
}

byte Bitmap::GetByte(byte position) const
{
	return pgm_read_byte_near(data + position);
}

Bitmap::~Bitmap()
{
}

Bitmap* Bitmap::m_OnePixel = nullptr;

const Bitmap& Bitmap::OnePixel()
{
	if (m_OnePixel == nullptr)
	{
		m_OnePixel = new Bitmap(new byte{0b11111111});
		m_OnePixel->height = 1;
		m_OnePixel->width = 1;
	}
	return *m_OnePixel;
}