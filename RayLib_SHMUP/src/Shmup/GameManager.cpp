#include <iostream>
#include <vector>
#include "Namespaces/Utils.h"
#include "Namespaces/GameStatus.h"
#include "Namespaces/Controller.h"
#include "MyClasses/GameManager.h"
#include "MyClasses/Player.h"
#include "MyClasses/Visual.h"
#include "MyClasses/Enemy.h"

Player* player;
void GameManager::Init()
{
	for (size_t i = 0; i < GameStatus::enemyCountConst; i++)
	{
		Enemy* enemy = new Enemy(
			i,
			{ Utils::randMToN(100.0f, GameStatus::screenWidth - 100.0f), Utils::randMToN(100.0f, GameStatus::screenHeight - 100.0f) }, //position;
			{ Utils::rand01(), Utils::rand01() }, //direction;
			ColorFromNormalized({ (float)GetRandomValue(0,255), (float)GetRandomValue(0,255), (float)GetRandomValue(0,255), 1 }) //tint;
		);
	}

	player = new Player();
}

void GameManager::Render()
{
	ClearBackground(BLANK);

	std::vector<GraphicObject*> visuals = GraphicObject::instances;
	
	for (std::vector<GraphicObject*>::iterator it = visuals.begin(); it != visuals.end(); ++it)
		(*it)->Draw();
}

void GameManager::Update()
{
	Controller::DoSwitch();

	//Do update
	std::vector<GraphicObject*> behaviours = GraphicObject::instances;

	for (std::vector<GraphicObject*>::iterator it = behaviours.begin(); it != behaviours.end(); ++it)
		(*it)->Update();
}
