/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "Namespaces/GameStatus.h"
#include "Shmup/GameManager.h"

#if _DEBUG
#include "Testing/MainTesting.h"
#endif

int main(void)
{
	// Initialization
	//--------------------------------------------------------------------------------------
	InitWindow(GameStatus::screenWidth, GameStatus::screenHeight, "Shmup");

	SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
	//--------------------------------------------------------------------------------------

	GameManager::Init();
#if _DEBUG
	bool isDebugTesting = false;
	float timeout = GameStatus::testingHoldTime;
#endif

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();
#if _DEBUG
		if (IsKeyDown(KEY_COMMA)) 
		{
			if (timeout > 0) {
				timeout -= GetFrameTime();
				if (timeout < 0) 
					isDebugTesting = !isDebugTesting;
			}
		}
		else
		{
			timeout = GameStatus::testingHoldTime;
		}

		if (!isDebugTesting)
		{
#endif
			GameManager::Render();
			GameManager::Update();
#if _DEBUG
		}
		else
		{
			ClearBackground(WHITE);
			// Testing
			//-/--------------------------------------------------------------------------------
			Testing::ExecuteTesting();
			//-/--------------------------------------------------------------------------------
		}
#endif
		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}