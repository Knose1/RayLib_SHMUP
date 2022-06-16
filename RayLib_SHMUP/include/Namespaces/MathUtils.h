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

	/// <summary>
	/// Interpolation using a geometric sequence that converge toward <see cref="target"/>.
	/// </summary>
	/// <param name="current">u(n)</param>
	/// <param name="target">lim(u(n))</param>
	/// <param name="strength">q</param>
	/// <returns>
	/// u(n+1) = u(n) + ( lim(u(n)) - u(n) ) * q
	/// </returns>
	static float geometricalInterpolation(float current, float target, float strength)
	{
		return current + (target - current) * strength;
	}

	/// <summary>
	/// Interpolation using a geometric sequence that converge toward <see cref="target"/>.
	/// </summary>
	/// <param name="current">u(n)</param>
	/// <param name="target">lim(u(n))</param>
	/// <param name="strength">q</param>
	/// <returns>
	/// u(n+1) = u(n) + ( lim(u(n)) - u(n) ) * q
	/// </returns>
	static Vector2 geometricalInterpolation(Vector2 current, Vector2 target, float strength)
	{
		return {
			geometricalInterpolation(current.x, target.x, strength),
			geometricalInterpolation(current.y, target.y, strength)
		};
	}

	static Vector2 orthogonalVector2(Vector2 v) { return { -v.y, v.x }; }
};