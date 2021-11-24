#include "raylib.h"
#include "raymath.h"
#include "MyClasses/Paterns/PaternLinear.h"
#include "MyClasses/Shoot.h"

void PaternLinear::DoPatern(Shoot* shoot, IPaternData* data)
{
	shoot->position = Vector2Add(shoot->position, Vector2Scale(shoot->direction, shoot->speed));
}
