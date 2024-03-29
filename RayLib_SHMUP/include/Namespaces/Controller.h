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
	Vector2 GetPlayerDirection(Vector2 playerTurretPosition);

	/// <summary>
	/// Return true if the player is shooting
	/// </summary>
	/// <returns></returns>
	bool Shoot(float fireRate=0, float* countdown = nullptr);

	/// <summary>
	/// Function called each frame to know if
	/// </summary>
	void DoSwitch();
    bool PreviousPatern();
    bool NextPatern();
}