#include <iostream>
#include <set>
#include "Namespaces/Random.h"
#include "Namespaces/GameStatus.h"
#include "Namespaces/Controller.h"
#include "Shmup/GameManager.h"
#include "Shmup/Movable/Player.h"
#include "Shmup/AGraphicObject.h"
#include "Shmup/Movable/Enemy.h"
#include "Shmup/InstanceList.hpp"
#include "Shmup/Collision/CollisionManager.h"
#include "Shmup/LevelManager.h"

Player* player;
const char* LEVEL = "./assets/Shmup/Levels/Level1.csv";
void GameManager::Init()
{
	LevelManager::Init(LoadFileText(LEVEL));

	/*for (size_t i = 0; i < GameStatus::enemyCountConst; i++)
	{
		new Enemy(
			i,
			{ Random::randMToN(100.0f, GameStatus::screenWidth - 100.0f), Random::randMToN(100.0f, GameStatus::screenHeight - 100.0f) }, //position;
			{ Random::rand01(), Random::rand01() }, //direction;
			ColorFromNormalized({ (float)GetRandomValue(0,255), (float)GetRandomValue(0,255), (float)GetRandomValue(0,255), 1 }), //tint;
			{ (unsigned)GetRandomValue(0,11) }
		);
	}*/

	player = new Player();
}

const void GameManager::Render()
{
	ClearBackground(RAYWHITE);

	auto visuals = InstanceList<AGraphicObject>::GetInstances();
	
	for (auto it = visuals.rbegin(); it != visuals.rend(); ++it)
		(*it)->Draw();
}

const void GameManager::Update()
{
	Controller::DoSwitch();
	LevelManager::Update();

	//Do update
	auto behaviours = InstanceList<AGraphicObject>::GetInstances();

	for (auto it = behaviours.begin(); it != behaviours.end(); ++it)
		(*it)->Update();
}

const void GameManager::TestCollisions()
{
	CollisionManager::Update();
}
