#include <Shmup/Collision/ColliderSettings.h>

const std::vector<std::vector<bool>> ColliderSettings::CollisionTable = {
	/*         *//* Default, Ennemy, Player */
	/* Default */ { false                   },
	/* Ennemy  */ { false  , false          },
	/* Player  */ { true   , false , false  }
};

bool ColliderSettings::AreCollidableLayers(CollisionLayer a, CollisionLayer b)
{
	return CollisionTable[(int)std::max(a, b)][(int)std::min(a, b)];
}