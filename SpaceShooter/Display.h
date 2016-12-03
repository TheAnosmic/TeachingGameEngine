#ifndef _DISPLAY_h
#define _DISPLAY_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Bitmap.h"
#include "Point.h"
#include <Adafruit_SSD1306.h>

class Display
{
public:
	explicit Display(Adafruit_SSD1306 &displayImplementation);
	void StartFrame();
	void EndFrame();
	void Draw(const Bitmap& bitmap, const Point& position);

private:
	// TODO: make it generic display
	Adafruit_SSD1306 &m_displayImplementation;
};


#endif

