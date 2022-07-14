#pragma once
#include <vector>
#include <map>
#include "Shmup/Collision/ColliderSettings.h"
#include "Shmup/Collision/ACollidable.h"

/// <summary>
/// Put the collidables in their respective layer and do the collision calculation loop.
/// </summary>
static class CollisionManager
{
	private:
		static std::map<CollisionLayer, std::vector<ACollidable*>> layeredCollisions;
	public:
		/// <summary>
		/// Register a collidable for collision.
		/// </summary>
		static void Register(ACollidable* collidable);
		/// <summary>
		/// Remove a collidable from the collisions.
		/// </summary>
		static void Unregister(ACollidable* collidable);
		/// <summary>
		/// The collision calculation loop.
		/// </summary>
		static void Update();
};