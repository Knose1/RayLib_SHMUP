#pragma once
#include "raylib.h"
#include "raymath.h"

namespace MathUtils
{
	float signf(float f);

	float scalePolarVec2DNonOpti(float angle, Vector2 cartesianScale);
	
	/// <summary>
	/// Given then angle of a polar vector and a cartesian scale, calculate the angle in degree
	/// </summary>
	float scalePolarVec2D(float angle, Vector2 cartesianScale);
	
	/// <summary>
	/// Calculate the angle in degree
	/// </summary>
	float cartesianToPolar(Vector2 cartesian);
	
	/// <summary>
	/// Calculate the vector from degree
	/// </summary>
	Vector2 polarToCartesian(float polar);
};