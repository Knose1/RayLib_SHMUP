#pragma once
#include "raylib.h"
#include "raymath.h"

namespace Controller
{	
	/// <summary>
	/// Get the direction of the player
	/// </summary>
	/// <param name="playerTurretPosition">The position of the player (to do calculation with the mouse)</param>
	/// <returns>The direction</returns>
	Vector2 GetTurretDirection(Vector2 playerTurretPosition);

	/// <summary>
	/// Return true of the player is shooting
	/// </summary>
	/// <returns></returns>
	bool Shoot();

	/// <summary>
	/// Function called each frame to know if
	/// </summary>
	void DoSwitch();
    bool PreviousPatern();
    bool NextPatern();
}