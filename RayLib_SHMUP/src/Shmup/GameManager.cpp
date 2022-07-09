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

	auto visuals = InstanceList<AGraphicObject>::GetInstances();
	
	for (auto it = visuals.begin(); it != visuals.end(); ++it)
		(*it)->Draw();
}

const void GameManager::Update()
{
	Controller::DoSwitch();

	//Do update
	auto behaviours = InstanceList<AGraphicObject>::GetInstances();

	for (auto it = behaviours.begin(); it != behaviours.end(); ++it)
		(*it)->Update();
}

const void GameManager::TestCollisions()
{
	auto collidable = InstanceList<ACollidable>::GetInstances();
	ACollidable* collidableA;
	ACollidable* collidableB;
	ACollider* colliderA;
	ACollider* colliderB;
	bool isCollision;
	int iplusone;

	for (auto a = collidable.begin(); a != collidable.end(); ++a)
	{
		collidableA = *a;
		colliderA = collidableA->GetCollider();
		for (auto b = collidable.begin(); b != collidable.end(); ++b)
		{
			if (a == b) continue;

			collidableB = *b;
			colliderB = collidableB->GetCollider();

			if (!ColliderSettings::AreCollidableLayers(colliderA->layer, colliderB->layer))
				continue;

			isCollision = colliderA->Calculation(collidableA->GetTransform(), collidableB->GetCollider(), collidableB->GetTransform());
			if (isCollision)
			{
				collidableA->OnCollision(collidableB);
				collidableB->OnCollision(collidableA);
				break;
			}
		}
	}
}
