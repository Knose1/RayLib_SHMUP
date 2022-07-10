#pragma once
#include <vector>
#include <map>
#include "Shmup/Collision/ColliderSettings.h"
#include "Shmup/Collision/ACollidable.h"

static class CollisionManager
{
	private:
		static std::map<CollisionLayer, std::vector<ACollidable*>> layeredCollisions;
	public:
		static void Register(ACollidable* collidable);
		static void Unregister(ACollidable* collidable);
		static void Update();
};