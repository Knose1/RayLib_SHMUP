#include "Shmup/Collision/CollisionManager.h"
#include "Shmup/Collision/ACollidable.h"
#include "Shmup/InstanceList.hpp"

std::map<CollisionLayer, std::vector<ACollidable*>> CollisionManager::layeredCollisions =
{
	{CollisionLayer::Default, {}},
	{CollisionLayer::Ennemy , {}},
	{CollisionLayer::Player , {}},
};

void CollisionManager::Register(ACollidable* collidable)
{
	layeredCollisions[collidable->GetCollider()->layer].push_back(collidable);
};

void CollisionManager::Unregister(ACollidable* collidable)
{
	auto list = layeredCollisions[collidable->GetCollider()->layer];
	std::remove(list.begin(), list.end(), collidable);
};

void CollisionManager::Update()
{
	auto collidable = InstanceList<ACollidable>::GetInstances();

	CollisionLayer minLayer = CollisionLayer::Default;
	CollisionLayer maxLayer = CollisionLayer(static_cast<int>(CollisionLayer::COUNT) - 1);

	std::vector<ACollidable*> collidersA;
	std::vector<ACollidable*> collidersB;

	ACollidable* collidableA;
	ACollidable* collidableB;

	ACollider* colliderA;
	ACollider* colliderB;

	bool isCollision;

	for (CollisionLayer layerA = minLayer; layerA < maxLayer; layerA = CollisionLayer(static_cast<int>(layerA) + 1))
	{
		for (CollisionLayer layerB = layerA; layerB < maxLayer; layerB = CollisionLayer(static_cast<int>(layerB) + 1))
		{
			if (!ColliderSettings::AreCollidableLayers(layerA, layerB)) continue;

			collidersA = CollisionManager::layeredCollisions[layerA];
			collidersB = CollisionManager::layeredCollisions[layerB];

			for (auto& i = --collidersA.end(); true; i--)
			{
				collidableA = *i;
				colliderA = collidableA->GetCollider();
				for (auto& j = --collidersB.end(); true; j--)
				{
					collidableB = *j;
					if (collidableB == collidableA) continue;
					colliderB = collidableB->GetCollider();

					isCollision = colliderA->Calculation(collidableA->GetTransform(), collidableB->GetCollider(), collidableB->GetTransform());
					if (isCollision)
					{
						collidableA->OnCollision(collidableB);
						collidableB->OnCollision(collidableA);
					}

					if (i == collidersB.begin()) break;
				}
				if (i == collidersA.begin()) break;
			}


		}
	}
};