#include <iostream>
#include <vector>
#include "Namespaces/Random.h"
#include "Namespaces/GameStatus.h"
#include "Namespaces/Controller.h"
#include "Shmup/GameManager.h"
#include "Shmup/Player.h"
#include "Shmup/AGraphicObject.h"
#include "Shmup/Enemy.h"

Player* player;
void GameManager::Init()
{
	for (size_t i = 0; i < GameStatus::enemyCountConst; i++)
	{
		Enemy* enemy = new Enemy(
			i,
			{ Random::randMToN(100.0f, GameStatus::screenWidth - 100.0f), Random::randMToN(100.0f, GameStatus::screenHeight - 100.0f) }, //position;
			{ Random::rand01(), Random::rand01() }, //direction;
			ColorFromNormalized({ (float)GetRandomValue(0,255), (float)GetRandomValue(0,255), (float)GetRandomValue(0,255), 1 }), //tint;
			{ (unsigned)GetRandomValue(0,11) }
		);
	}

	player = new Player();
}

const void GameManager::Render()
{
	ClearBackground(RAYWHITE);

	std::vector<AGraphicObject*> visuals = AGraphicObject::instances;
	
	for (std::vector<AGraphicObject*>::iterator it = visuals.begin(); it != visuals.end(); ++it)
		(*it)->Draw();
}

const void GameManager::Update()
{
	Controller::DoSwitch();

	//Do update
	std::vector<AGraphicObject*> behaviours = AGraphicObject::instances;

	for (std::vector<AGraphicObject*>::iterator it = behaviours.begin(); it != behaviours.end(); ++it)
		(*it)->Update();
}
