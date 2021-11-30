#include "raylib.h"
#include "raymath.h"
#include "Namespaces/MathUtils.h"
#include "Shmup/Paterns/Shoot/PaternLinear.h"
#include "Shmup/Shoot.h"

void PaternLinear::DoPatern(AMovable* shoot, IPaternData* data)
{
	shoot->orientation = MathUtils::cartesianToPolar(shoot->direction) * MathUtils::signf(shoot->speed);
	shoot->position = Vector2Add(shoot->position, Vector2Scale(shoot->direction, shoot->speed));
}

void PaternLinear::SetDefault(IPaternData* data)
{
}
