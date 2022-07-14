#include "Shmup/Collision/ACollidable.h"
#include "Shmup/Collision/CollisionManager.h"
#include "Shmup/InstanceList.hpp"

ACollidable::ACollidable()
{
	InstanceList<ACollidable>::AddInstance(this);
};

ACollidable::~ACollidable()
{
	InstanceList<ACollidable>::RemoveInstance(this);
	Disable();
};

void ACollidable::Enable()
{
	CollisionManager::Register(this);
};

void ACollidable::Disable() 
{
	CollisionManager::Unregister(this);
}

ACollider* ACollidable::GetCollider() { return this->collider; }
