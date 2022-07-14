#pragma once
#include "raylib.h"

/// <summary>
/// A transform in two dimentions
/// </summary>
struct Transform2D 
{
	/// <summary>
	/// The position of the object
	/// </summary>
	Vector2 position = { 0,0 };
	/// <summary>
	/// The rotation of the object
	/// </summary>
	float rotation = 0;
	/// <summary>
	/// The scale of the object
	/// </summary>
	Vector2 scale = { 1,1 };
};