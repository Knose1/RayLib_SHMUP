#pragma once
#include <vector>

enum class CollisionLayer : int
{
	Default = 0,
	Ennemy  = 1,
	Player  = 2
};

static class ColliderSettings
{
	public:
		static const std::vector<std::vector<bool>> CollisionTable;

		static bool AreCollidableLayers(CollisionLayer a, CollisionLayer b);
};