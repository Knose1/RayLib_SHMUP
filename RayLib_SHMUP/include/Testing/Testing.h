#pragma once
#include "raylib.h";
#include "raymath.h";
#include "Namespaces/GameStatus.h";

namespace Testing 
{
	void DebugCurveCenter(Vector2 minCoord, Vector2 maxCoord, float thickness, Color color) 
	{
		Vector2 center = {
			Remap(0, minCoord.x, maxCoord.x, 0, GameStatus::screenWidth),
			Remap(0, minCoord.y, maxCoord.y, 0, GameStatus::screenHeight)
		};

		DrawLineEx({		0, center.y }, { GameStatus::screenWidth,center.y				  }, thickness, color);
		DrawLineEx({ center.x, 0		}, { center.x				,GameStatus::screenHeight }, thickness, color);
	}
	void DebugCurve(float (*function)(float), Vector2 minCoord, Vector2 maxCoord, int iterationCount, float thickness, Color color)
	{
		Vector2 pos = Vector2Zero();
		Vector2 oldPos = Vector2Zero();
		for (int i = 0; i < iterationCount; i++)
		{
			pos.x = Lerp(minCoord.x, maxCoord.x, (float)i / iterationCount);
			pos.y = function(pos.x);

			pos.x = Remap(pos.x, minCoord.x, maxCoord.x, 0, GameStatus::screenWidth);
			pos.y = Remap(pos.y, minCoord.y, maxCoord.y, 0, GameStatus::screenHeight);

			if (i != 0) 
			{
				DrawLineEx(oldPos, pos, thickness, color);
			}
		}
	}
}