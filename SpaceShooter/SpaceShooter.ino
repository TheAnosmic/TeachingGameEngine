#include "Map.h"
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
#define BUZZER A0

#define TARGET_FRAME_RATE 15
#define _FRAME_RATE_MS (1000.0 / TARGET_FRAME_RATE)


void setupInput()
{
	pinMode(INPUT_LEFT, INPUT_PULLUP);
	pinMode(INPUT_TRIGGER, INPUT_PULLUP);
	pinMode(INPUT_RIGHT, INPUT_PULLUP);
	pinMode(BUZZER, OUTPUT);
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
Map enemiesMap(Point(50, 10));
unsigned long frameStartTime;


void setup() {
	Serial.begin(115200);
	Serial.println("Start");

	WorldState::InitInstance(player);
	enemiesMap.AddEnemies(WorldState::instance());
	setupInput();
	setupDisplay();

	frameStartTime = millis();
	tone(BUZZER, 440);
	delay(100);
	noTone(BUZZER);
}

template <class T>
void gameObjectFrame(T *gameObjects, int gameObjectSize);

template <class T>
void gameObjectFrame(T *gameObjects, int gameObjectSize)
{
	for (int i = 0; i < gameObjectSize; ++i)
	{
		T &gameObject = gameObjects[i];
		if (gameObject.IsAlive())
		{
			gameObject.ActOnFrame();
			display.Draw(gameObject.GetBitmap(), gameObject.GetPosition());
		}
	}
}


void loop() {

	Input input = getPlayerInput();
	player.HandleInput(input);


	display.StartFrame();
	display.Draw(player.GetBitmap(), player.GetPosition());

	Point heartPoint(1, 20);
	display.Draw(player.GetHeart(0), heartPoint);
	heartPoint.x += 8;
	display.Draw(player.GetHeart(1), heartPoint);
	heartPoint.x += 8;
	display.Draw(player.GetHeart(2), heartPoint);

	WorldState& worldState = *WorldState::instance();
	Enemy* gameObjects = worldState.enemies;
	int gameObjectSize = worldState.enemiesSize;
	gameObjectFrame(gameObjects, gameObjectSize);
	Bullet* bullets = worldState.bullets;
	gameObjectSize = worldState.bulletsSize;
	gameObjectFrame(bullets, gameObjectSize);

	for (int i = 0; i < worldState.bulletsSize; ++i)
	{
		Bullet &bullet = bullets[i];
		if (!bullet.IsAlive())
		{
			continue;
		}
		const Point &bulletPoint = bullet.GetPosition();
		for (int j = 0; j < worldState.enemiesSize; ++j)
		{
			Enemy &enemy = worldState.enemies[j];
			if (!enemy.IsAlive())
			{
				continue;
			}
			const Point &enemyPoint = enemy.GetPosition();
			if (enemyPoint.x <= bulletPoint.x &&
				enemyPoint.x + Enemy::width >= bulletPoint.x &&
				enemyPoint.y <= bulletPoint.y &&
				enemyPoint.y + Enemy::height >= bulletPoint.y)
			{
				enemy.Destroy();
				bullet.Destroy();
				break;
			}
		}
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
