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
	InitWindow(GameStatus::screenWidth, GameStatus::screenHeight,
#if _DEBUG
	"Shmup Debug"
#else
	"Shmup"
#endif // _DEBUG
	);

	SetTargetFPS(GameStatus::frameRate);               // Set our game to run at 60 frames-per-second
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
#endif //_DEBUG
			GameManager::Update();
			GameManager::TestCollisions();
			GameManager::Render();
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
#endif //_DEBUG
		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}