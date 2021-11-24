#include "raylib.h"
#include "raymath.h"
#include "Shmup/Paterns/PaternLinear.h"
#include "Shmup/Shoot.h"

void PaternLinear::DoPatern(Shoot* shoot, IPaternData* data)
{
	shoot->position = Vector2Add(shoot->position, Vector2Scale(shoot->direction, shoot->speed));
}

void PaternLinear::SetDefault(Shoot* shoot)
{
}
