#pragma once
namespace GameStatus
{
#if _DEBUG
	const float testingHoldTime = 2;
#endif
	const int nbShots = 1000;
	const int enemyCountConst = 30;

	const int screenWidth = 800;
	const int screenHeight = 1000;

	const int frameRate = 60;
	const float constantFrameTime = 1.0f/frameRate;
};