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
	explicit Bitmap(const byte*);
	int width;
	int height;
	byte GetByte(byte position) const;
	~Bitmap();

	static const Bitmap& OnePixel();

private:
	Bitmap(const Bitmap &bitmap) = delete;
	static Bitmap* m_OnePixel;
	const byte *data;
};

#endif
