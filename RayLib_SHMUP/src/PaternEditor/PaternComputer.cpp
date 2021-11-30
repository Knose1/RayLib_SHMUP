#include <iostream>
#include <vector>
#include "raylib.h"
#include "PaternEditor/PaternComputer.h"
#include "Namespaces/GameStatus.h"
#include "Namespaces/Random.h"

std::vector<Vector2> pos;

void PaternComputer::SetPatern(std::vector<SequenceMovePatern::Sequence> patern)
{
	data.paternSequence = patern;
	data.time = 0;
	oldPosition = position = {startPositionX, startPositionY};
	orientation = 0;
	direction = { 0,1 };
	pos.clear();

	this->patern->SetDefault(&data);
}

void DrawDebug(Vector2 position);
void PaternComputer::Update()
{
	patern->DoPatern(this, &data);
	pos.push_back(position);
	DrawDebug(position);
}

void DrawDebug(Vector2 position) 
{
	size_t size = pos.size();
	for (size_t i = 1; i < size; i++)
	{
		DrawLineEx(pos[i-1], pos[i], 1, RED);
	}
	
	DrawCircleV(position, 5, RED);
}