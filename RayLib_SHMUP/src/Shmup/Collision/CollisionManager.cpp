#include "Shmup/Collision/CollisionManager.h"
#include "Shmup/Collision/ACollidable.h"
#include "Shmup/InstanceList.hpp"
#include <algorithm>

std::map<CollisionLayer, std::vector<ACollidable*>> CollisionManager::layeredCollisions =
{
	{CollisionLayer::Default, {}},
	{CollisionLayer::Ennemy , {}},
	{CollisionLayer::Player , {}},
};

void CollisionManager::Register(ACollidable* collidable)
{
	auto layer = collidable->GetCollider()->layer;
	auto& list = layeredCollisions[layer];
	if (std::find(list.begin(), list.end(), collidable) == list.end()) 
	{
		list.push_back(collidable);
		//layeredCollisions[layer] = list;
	}
};

void CollisionManager::Unregister(ACollidable* collidable)
{
	auto layer = collidable->GetCollider()->layer;
	auto& list = layeredCollisions[layer];

	if (std::find(list.begin(), list.end(), collidable) != list.end()) 
	{
		std::remove(list.begin(), list.end(), collidable);
		list.resize(list.size() - 1);
		//layeredCollisions[layer] = list;
	}
};

void CollisionManager::Update()
{
	auto collidable = InstanceList<ACollidable>::GetInstances();

	CollisionLayer minLayer = CollisionLayer::Default;
	CollisionLayer maxLayer = CollisionLayer::COUNT;

	std::vector<ACollidable*> collidersA;
	std::vector<ACollidable*> collidersB;

	ACollidable* collidableA;
	ACollidable* collidableB;

	ACollider* colliderA;
	ACollider* colliderB;

	bool isCollision = false;

	for (CollisionLayer layerA = minLayer; layerA < maxLayer; layerA = CollisionLayer(static_cast<int>(layerA) + 1))
	{
		for (CollisionLayer layerB = layerA; layerB < maxLayer; layerB = CollisionLayer(static_cast<int>(layerB) + 1))
		{
			if (!ColliderSettings::AreCollidableLayers(layerA, layerB)) continue;

			collidersA = CollisionManager::layeredCollisions[layerA];
			collidersB = CollisionManager::layeredCollisions[layerB];

			for (int i = collidersA.size() - 1; i >= 0; i--)
			{
				collidableA = collidersA[i];
				colliderA = collidableA->GetCollider();
				for (int j = collidersB.size() - 1; j >= 0; j--) 
				{
					collidableB = collidersB[j];
					if (collidableB == nullptr || collidableA == nullptr) continue;
					if (collidableB == collidableA) continue;
					colliderB = collidableB->GetCollider();

					isCollision = colliderA->Calculation(collidableA->GetTransform(), colliderB, collidableB->GetTransform());
					if (isCollision)
					{
						collidableA->OnCollision(collidableB);
						collidableB->OnCollision(collidableA);

						break;
					}

				}

				if (isCollision) 
				{
					isCollision = true;
					break;
				}
			}


		}
	}
};