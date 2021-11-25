#pragma once
#include "raylib.h"
#include "AGraphicObject.h"

class AMovable :
	public AGraphicObject
{
	public:
		Vector2 direction;
		float speed;
};