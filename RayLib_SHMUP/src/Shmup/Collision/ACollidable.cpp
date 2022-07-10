#include "Shmup/Collision/ACollidable.h"
#include "Shmup/Collision/CollisionManager.h"
#include "Shmup/InstanceList.hpp"

ACollidable::ACollidable()
{
	InstanceList<ACollidable>::AddInstance(this);
};

ACollidable::~ACollidable()
{
	delete collider;
	InstanceList<ACollidable>::RemoveInstance(this);
	CollisionManager::Unregister(this);
};

void ACollidable::Init()
{
	CollisionManager::Register(this);
};

ACollider* ACollidable::GetCollider() { return this->collider; };
