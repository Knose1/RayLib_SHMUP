#include <iostream>
#include <vector>
#include "raylib.h"
#include "raymath.h"
#include "Shmup/AGraphicObject.h"
#include "Shmup/InstanceList.hpp"

void AGraphicObject::Draw() 
{
	DefaultDrawMethod(
		texture,
		position,
		source,
		center,
		scale,
		orientation,
		tint
	);
}
void AGraphicObject::DefaultDrawMethod(
	Texture2D texture,
	Vector2 position,
	Rectangle source,
	Vector2 center,
	Vector2 scale,
	float orientation,
	Color tint
)
{
	float width = (float)source.width;
	float height = (float)source.height;
	float scaledW = width * scale.x;
	float scaledH = height * scale.y;
	Vector2 offset = Vector2Multiply(center, { scaledW, scaledH });

	DrawTexturePro(
		texture,
		source,
		{ position.x, position.y, scaledW, scaledH },
		offset,
		orientation,
		tint
	);
}

AGraphicObject::AGraphicObject()
{
	AddInstance(this);
}

AGraphicObject::~AGraphicObject()
{
	RemoveInstance(this);
}
