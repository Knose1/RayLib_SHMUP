#include "raylib.h"
#include "raymath.h"
#include "Namespaces/GameStatus.h"
#include "Namespaces/MathUtils.h"
#include "Shmup/Paterns/Shoot/PaternRotate.h"
#include "Shmup/Movable/Shoot.h"

void PaternRotate::DoPatern(AMovable* movable, IPaternData* data)
{
	Shoot* shoot = (Shoot*)movable;

	float angle = MathUtils::cartesianToPolar(shoot->direction) + 1.5f * (shoot->GetSpawnIndex() % 2 - 0.5f);
	shoot->direction = MathUtils::polarToCartesian(angle);
	shoot->orientation = angle * MathUtils::signf(shoot->speed);
	shoot->position = Vector2Add(shoot->position, Vector2Scale(shoot->direction, shoot->speed));

	shoot->speed += 0.1f;
}

void PaternRotate::SetDefault(IPaternData* data)
{
}