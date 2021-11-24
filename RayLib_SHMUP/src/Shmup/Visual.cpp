#include <iostream>
#include <vector>
#include "raylib.h"
#include "raymath.h"
#include "MyClasses/Visual.h"
#include "MyClasses/InstanceList.hpp"

void GraphicObject::Draw() 
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
void GraphicObject::DefaultDrawMethod(
	Texture2D texture,
	Vector2 position,
	Rectangle source,
	Vector2 center,
	Vector2 scale,
	float orientation,
	Color tint
)
{
	float width = (float)texture.width;
	float height = (float)texture.height;
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

GraphicObject::GraphicObject()
{
	AddInstance(this);
}

GraphicObject::~GraphicObject()
{
	RemoveInstance(this);
}
