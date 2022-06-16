#include "raylib.h"
#include "Generator.h"
#include <iostream>

int main(void)
{
	// Initialization
	//--------------------------------------------------------------------------------------
	InitWindow(100, 100, "Test Generator");

	SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
	//--------------------------------------------------------------------------------------
	MyStruct str = MyStruct();
	str.init();

	int frame = 0;
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

		ClearBackground(WHITE);
		str.next();
		std::cout << "frame: " << frame << "; value:" << str.GetValue() << std::endl;

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}