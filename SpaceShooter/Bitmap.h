// Bitmap.h

#ifndef _BITMAP_h
#define _BITMAP_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class Bitmap
{
public:
	explicit Bitmap(int size);
	byte *bits;
	int width;
	int height;
	~Bitmap();

	static const Bitmap& OnePixel();

private:
	Bitmap(const Bitmap &bitmap) = delete;
	static Bitmap* m_OnePixel;
};


inline Bitmap::Bitmap(int size)
{
	bits = new byte[size];
}

inline Bitmap::~Bitmap()
{
	Serial.print("Dtor ");
	Serial.println(width);
	delete[] bits;
}

inline const Bitmap& Bitmap::OnePixel()
{
	if (m_OnePixel == nullptr)
	{
		m_OnePixel = new Bitmap(1);
		m_OnePixel->bits[0] = 0b11111111;
		m_OnePixel->height = 1;
		m_OnePixel->width = 1;
	}
	return *m_OnePixel;
}
#endif

