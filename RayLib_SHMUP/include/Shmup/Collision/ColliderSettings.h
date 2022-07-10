#pragma once
#include <vector>

enum class CollisionLayer : int
{
	Default,
	Ennemy,
	Player,
	COUNT
};

static class ColliderSettings
{
	public:
		static const std::vector<std::vector<bool>> CollisionTable;

		static bool AreCollidableLayers(CollisionLayer a, CollisionLayer b);
};