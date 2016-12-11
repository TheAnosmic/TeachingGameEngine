#include "Enemy.h"
#include "DynamicGameObject.h"
#include "GameObject.h"
#include "WorldState.h"
#include "Display.h"
#include "Player.h"
#include <Adafruit_SSD1306.h>

#include "Input.h"

#define OLED_RESET 4

Adafruit_SSD1306 displayImplementation(OLED_RESET);

#define INPUT_LEFT 0
#define INPUT_TRIGGER 5
#define INPUT_RIGHT 2

#define TARGET_FRAME_RATE 20
#define _FRAME_RATE_MS (1000.0 / TARGET_FRAME_RATE)


void setupInput()
{
	pinMode(INPUT_LEFT, INPUT_PULLUP);
	pinMode(INPUT_TRIGGER, INPUT_PULLUP);
	pinMode(INPUT_RIGHT, INPUT_PULLUP);
}

void setupDisplay()
{
	displayImplementation.begin(SSD1306_SWITCHCAPVCC, 0x3C);
	displayImplementation.clearDisplay();
	displayImplementation.display();
}

Input getPlayerInput(void)
{
	Input playerInput;
	playerInput.left = digitalRead(INPUT_LEFT) == LOW;
	playerInput.right = digitalRead(INPUT_RIGHT) == LOW;
	playerInput.trigger = digitalRead(INPUT_TRIGGER) == LOW;
	return playerInput;
}

Player player(SSD1306_LCDWIDTH / 2, SSD1306_LCDHEIGHT - 9);
Display display(displayImplementation);
unsigned long frameStartTime;



void setup() {
	Serial.begin(115200);
	Serial.println("Start");

	WorldState::InitInstance(player);
	setupInput();
	setupDisplay();

	frameStartTime = millis();

}


void loop() {

	Input input = getPlayerInput();
	player.HandleInput(input);


	display.StartFrame();
	display.Draw(player.GitBitmap(), player.GetPosition());

	Point heartPoint;
	heartPoint.x = 1;
	heartPoint.y = 20;
	display.Draw(player.GetHeart(0), heartPoint);
	heartPoint.x += 8;
	display.Draw(player.GetHeart(1), heartPoint);
	heartPoint.x += 8;
	display.Draw(player.GetHeart(2), heartPoint);

	WorldState& worldState = *WorldState::instance();
	for (int i = 0; i < worldState.GetLastGameObjectIndex(); ++i)
	{
		GameObject* gameObject = worldState.GetGameObjects()[i];
		if (gameObject->IsAlive())
		{
			gameObject->ActOnFrame();
		}
		
	}

	for (int i = 0; i < worldState.GetLastGameObjectIndex(); ++i)
	{
		GameObject* gameObject = worldState.GetGameObjects()[i];
		if (gameObject->IsAlive())
		{
			display.Draw(gameObject->GetBitmap(), gameObject->GetPosition());
		}
	}

	DynaminGameObject* next = worldState.GetDynamicGameObjectsHead();
	while (next != nullptr)
	{
		next->ActOnFrame();
		next = next->GetNext();
	}
	next = worldState.GetDynamicGameObjectsHead();
	while (next != nullptr)
	{
		display.Draw(next->GetBitmap(), next->GetPosition());
		next = next->GetNext();
	}

	display.EndFrame();
	unsigned long currentTime = millis();
	unsigned long elapsedTime = currentTime - frameStartTime;
	if (_FRAME_RATE_MS < elapsedTime)
	{
		Serial.print("Warning: target frame rate did not reached (");
		Serial.print(_FRAME_RATE_MS);
		Serial.print(" < ");
		Serial.print(elapsedTime);
		Serial.println(")");
	}
	else
	{
		delay(_FRAME_RATE_MS - elapsedTime);
//		Serial.print("Frame ");
//		Serial.print(elapsedTime);
//		Serial.println("ms");
	}

	frameStartTime = millis();

}