#include "raylib.h"
#include "raymath.h"
#include "Namespaces/MathUtils.h"
#include "Namespaces/GameStatus.h"
#include "Namespaces/Random.h"
#include "Shmup/Paterns/Shoot/PaternVSpread.h"
#include "Shmup/Movable/Shoot.h"

void PaternVSpread::DoPatern(AMovable* movable, IPaternData* data)
{
	Shoot* shoot = (Shoot*)movable;
	if (shoot->position.x > 50 && shoot->position.y > 50 && shoot->position.x < GameStatus::screenWidth - 50 && shoot->position.y < GameStatus::screenHeight - 50)
	{
		shoot->direction = Vector2Rotate(shoot->direction, (shoot->GetSpawnIndex() % 2 == 1 ? 1.0f : -1.0f) + Random::randMToN(-1, 1));
		shoot->speed -= 0.1f;
	}

	shoot->orientation = MathUtils::cartesianToPolar(shoot->direction) - 180 * signbit(shoot->speed);
	shoot->position = Vector2Add(shoot->position, Vector2Scale(shoot->direction, shoot->speed));
}

void PaternVSpread::SetDefault(IPaternData* data)
{
}