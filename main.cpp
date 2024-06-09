#include "raylib.h"
#include <iostream>

using namespace std;

int player_score = 0;
int cpu_score = 0;

class Ball {
public:
	float x, y;
	int speed_x, speed_y;
	int radius;

	void Draw()
	{
		DrawCircle(x, y, radius, WHITE);
	}
	void Update()
	{
		x += speed_x;
		y += speed_y;

		if (y + radius >= GetScreenHeight() || y - radius <= 0)
		{
			speed_y *= -1;
		}
		if (x + radius >= GetScreenWidth() || x - radius <= 0)
		{
			speed_x *= -1;
		}
	}
};

class Paddle {

protected:

	void LimitMovement()
	{
		if (y <= 0)
		{
			y = 0;
		}
		if (y + height >= GetScreenHeight())
		{
			y = GetScreenHeight() - height;
		}
	}

public:
	float x, y;
	float width, height;
	int speed;

	void Draw()
	{
		DrawRectangle(x, y, width, height, WHITE);
	}

	void Update()
	{
		if (IsKeyDown(KEY_UP))
		{
			y = y - speed;
		}
		if (IsKeyDown(KEY_DOWN))
		{
			y = y + speed;
		}
		LimitMovement();
	}
};

class CpuPaddle : public Paddle {
public:
	void Update(int ball_y)
	{
		if (y + height > ball_y)
		{
			y = y - speed;
		}
		if (y + height / 2 <= ball_y)
		{
			y = y + speed;
		}
		LimitMovement();
	}

};

Ball ball;
Paddle player;
CpuPaddle cpu;

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 800;
const int FPS = 45;

int ball_spd_x = 5;
int ball_spd_y = 5;

int main()
{
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pong");
	SetTargetFPS(FPS);

	ball.radius = 10;
	ball.x = SCREEN_WIDTH / 2;
	ball.y = SCREEN_HEIGHT / 2;
	ball.speed_x = 7;
	ball.speed_y = 7;

	player.width = 25;
	player.height = 120;
	player.x = SCREEN_WIDTH - player.width - 10;
	player.y = SCREEN_HEIGHT / 2 - player.height / 2;
	player.speed = 6;

	cpu.width = 25;
	cpu.height = 120;
	cpu.x = 10;
	cpu.y = SCREEN_HEIGHT / 2 - cpu.height / 2;
	cpu.speed = 6;

	while (WindowShouldClose() == false)
	{
		BeginDrawing();

		if (CheckCollisionCircleRec(Vector2{ ball.x, ball.y }, ball.radius, Rectangle{ player.x, player.y, player.width, player.height }))
		{
			ball.speed_x *= -1;
		}
		if (CheckCollisionCircleRec(Vector2{ ball.x, ball.y }, ball.radius, Rectangle{ cpu.x, cpu.y, cpu.width, cpu.height }))
		{
			ball.speed_x *= -1;
		}
		ClearBackground(BLACK);
		ball.Update();
		ball.Draw();
		cpu.Draw();
		cpu.Update(ball.y);
		player.Draw();
		player.Update();

		EndDrawing();
	}
}

