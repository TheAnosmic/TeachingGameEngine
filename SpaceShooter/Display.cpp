#include "Display.h"


Display::Display(Adafruit_SSD1306 &displayImplementation): m_displayImplementation(displayImplementation)
{

}

void Display::draw_frame()
{
	int width = this->m_displayImplementation.width();
	for (int i = 0; i < this->m_displayImplementation.height(); ++i)
	{
		m_displayImplementation.drawPixel(width - 1, i, WHITE);
		m_displayImplementation.drawPixel(30, i, WHITE);
	}
	m_displayImplementation.drawChar(1, 0, '9', WHITE, BLACK, 1);
	m_displayImplementation.drawChar(8, 0, '9', WHITE, BLACK, 1);
	m_displayImplementation.drawChar(15, 0, '9', WHITE, BLACK, 1);
	m_displayImplementation.drawChar(22, 0, '9', WHITE, BLACK, 1);

}

void Display::StartFrame()
{
	m_displayImplementation.clearDisplay();

	draw_frame();

}

void Display::EndFrame()
{
	m_displayImplementation.display();
}

void Display::Draw(const Bitmap& bitmap, const Point& position)
{
	for (int i = 0; i < bitmap.height; ++i)
	{
		for (int j = 0; j < bitmap.width; ++j)
		{
			int bitnum = i * bitmap.width + j;
			int bitIndex = (1 << (bitnum % 8));
			byte b = bitmap.GetByte(bitnum / 8);
			bool isOn = b & bitIndex;
			if (isOn)
			{
				// TODO: different x/y orientation screens
				int line = position.y + (bitnum / bitmap.width);
				int column = position.x + (bitnum % bitmap.width);
				m_displayImplementation.drawPixel(column, line, WHITE);
			}
		}
	}
	
}