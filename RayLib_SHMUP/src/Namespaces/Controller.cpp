#pragma once
#include <iostream>
#include "raylib.h"
#include "raymath.h"
#include "Namespaces/Controller.h"

const bool isRaffal=true;
bool isGamePad=false;
Vector2 oldDirection = {1.f, 0.f};
Vector2 Controller::GetPlayerDirection(Vector2 playerTurretPosition)
{
	float LGetDirection(bool negative, bool positive);

	Vector2 toReturn;
	switch (isGamePad)
	{
		case true:
			toReturn = Vector2Scale({ GetGamepadAxisMovement(0, 0), GetGamepadAxisMovement(0, 1) }, 10000);
			break;
		default:
			toReturn = { 
				LGetDirection(IsKeyDown(KEY_LEFT), IsKeyDown(KEY_RIGHT)), 
				LGetDirection(IsKeyDown(KEY_UP), IsKeyDown(KEY_DOWN))
			};
			break;
	}
		
	if (toReturn.x == 0 && toReturn.y == 0)
	{
		return oldDirection;
	}

	oldDirection = toReturn;
		
	return toReturn;
}
bool Controller::Shoot()
{
	return isRaffal ? 
		(isGamePad ? IsGamepadButtonDown(0, 7) : IsMouseButtonDown(0)) :
		(isGamePad ? IsGamepadButtonPressed(0, 7) : IsMouseButtonPressed(0))
	;
}

bool Controller::PreviousPatern() 
{
	return (isGamePad ? IsGamepadButtonPressed(0, 9) : IsKeyPressed(KeyboardKey::KEY_LEFT_SHIFT));
}
bool Controller::NextPatern()
{
	return (isGamePad ? IsGamepadButtonPressed(0, 11) : IsKeyPressed(KeyboardKey::KEY_RIGHT_SHIFT));
}

void Controller::DoSwitch()
{
	if (GetGamepadAxisMovement(0, 0) == 1 || GetGamepadAxisMovement(0, 1) == 1 || GetGamepadButtonPressed() != -1) isGamePad = true;
	else if (IsMouseButtonPressed(0) || GetKeyPressed() != 0) isGamePad = false;
}

/// <summary>
/// Not useable outside of <see cref="GetPlayerDirection"/>
/// </summary>
/// <param name="negative"></param>
/// <param name="positive"></param>
/// <returns></returns>
float LGetDirection(bool negative, bool positive)
{
	if (negative && positive) return 0;
	if (negative) return -1;
	if (positive) return 1;
	return 0;
}