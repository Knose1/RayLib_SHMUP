#define _CRT_SECURE_NO_WARNINGS 1
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "raylib.h"
#include "Namespaces/GameStatus.h"
#include "PaternEditor/PaternComputer.h"
#include "Namespaces/Parser.h"

constexpr char START_CURVE[] = "assets/Shmup/paterns/simpleCurve.csv";

int main(void)
{
	// Initialization
	//--------------------------------------------------------------------------------------
	InitWindow(GameStatus::screenWidth, GameStatus::screenHeight, "Patern Editor");
	SetTargetFPS(GameStatus::frameRate);               // Set our game to run at 60 frames-per-second
	//--------------------------------------------------------------------------------------
	PaternComputer* computer = new PaternComputer();
	
	auto len = std::strlen(START_CURVE);
	char* currentCurve = new char[len];
	strcpy(currentCurve, START_CURVE);
	{
		char* content = LoadFileText(currentCurve);
		computer->SetPatern(Parser::GetSequencePatern(content));
		computer->speed = 1;
	}

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
		if (IsFileDropped())
		{
			int count = 0;
			char** droppedFiles = { 0 };
			droppedFiles = GetDroppedFiles(&count);
			
			//delete[] currentCurve;
			char* file = droppedFiles[0];
			auto len = std::strlen(file);
			currentCurve = new char[len];
			strcpy(currentCurve, file);
			if (IsFileExtension(droppedFiles[0], ".csv")) 
			{
				char* content = LoadFileText(currentCurve);
				computer->SetPatern(Parser::GetSequencePatern(content));
			}

			ClearDroppedFiles();
		}

		computer->Update();

		if (IsKeyPressed(KEY_COMMA))
		{
			char* content = LoadFileText(currentCurve);
			computer->SetPatern(Parser::GetSequencePatern(content));
			computer->speed = 1;
		}
		else if (IsKeyPressed(KEY_UP)) 
		{
			std::cout << "Speed: " << (computer->speed += 0.2) << std::endl;
		}
		else if (IsKeyPressed(KEY_DOWN)) 
		{
			std::cout << "Speed: " << (computer->speed -= 0.2) << std::endl;
		}
		else if (IsKeyPressed(KEY_LEFT)) 
		{
			const char* coord = IsKeyDown(KEY_LEFT_SHIFT) ? "Y" : "X";
			float* pos = IsKeyDown(KEY_LEFT_SHIFT) ? &computer->startPositionY : &computer->startPositionX;
			std::cout << "Pos"<< coord <<": "   << (*pos -= 1) << std::endl;
		}
		else if (IsKeyPressed(KEY_RIGHT))
		{
			const char* coord = IsKeyDown(KEY_LEFT_SHIFT) ? "Y" : "X";
			float* pos = IsKeyDown(KEY_LEFT_SHIFT) ? &computer->startPositionY : &computer->startPositionX;
			std::cout << "Pos" << coord << ": " << (*pos += 1) << std::endl;
		}
		else if (IsKeyPressed(KEY_KP_0))
		{
			std::cout << "Reset pos and speed" << std::endl;
			computer->speed = 1;
			computer->startPositionX = 0;
			computer->startPositionY = 0;
		}

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}