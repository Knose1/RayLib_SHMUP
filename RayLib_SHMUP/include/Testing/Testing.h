#pragma once
#include "raylib.h";
#include "raymath.h";
#include "Namespaces/GameStatus.h";

namespace Testing 
{
	void DebugCurveAxes(Vector2 minCoord, Vector2 maxCoord, float thickness, Color color, bool yIsUp=true) 
	{
		float bottom = yIsUp ? GameStatus::screenHeight : 0;
		float top    = yIsUp ? 0 : GameStatus::screenHeight;

		Vector2 center = {
			Remap(0, minCoord.x, maxCoord.x, 0, GameStatus::screenWidth),
			Remap(0, minCoord.y, maxCoord.y, bottom, top)
		};

		DrawLineEx({		0, center.y }, { GameStatus::screenWidth,center.y				  }, thickness, color);
		DrawLineEx({ center.x, 0		}, { center.x				,GameStatus::screenHeight }, thickness, color);

		DrawCircle(GameStatus::screenWidth, center.y, thickness+5, color);
		DrawCircle(center.x, top, thickness+5, color);
	}
	void DebugCurve(float (*function)(float), Vector2 minCoord, Vector2 maxCoord, int iterationCount, float thickness, Color color, bool yIsUp=true)
	{
		float bottom = yIsUp ? GameStatus::screenHeight : 0;
		float top = yIsUp ? 0 : GameStatus::screenHeight;

		Vector2 pos = Vector2Zero();
		Vector2 oldPos = Vector2Zero();
		for (int i = 0; i < iterationCount; i++)
		{
			pos.x = Lerp(minCoord.x, maxCoord.x, (float)i / iterationCount);
			pos.y = function(pos.x);

			pos.x = Remap(pos.x, minCoord.x, maxCoord.x, 0, GameStatus::screenWidth);
			pos.y = Remap(pos.y, minCoord.y, maxCoord.y, bottom, top);

			if (i != 0) 
			{
				DrawLineEx(oldPos, pos, thickness, color);
			}

			oldPos = pos;
		}
	}
}