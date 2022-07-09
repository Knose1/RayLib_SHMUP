#pragma once
#include "Shmup/Collision/Collider.h"
#include "Shmup/InstanceList.h"

class ACollidable : 
	public InstanceList<ACollidable>
{
	protected:
		ACollider* collider;
	
	public:
		ACollider* GetCollider() { return this->collider; };
		virtual void OnCollision(ACollidable * other) = 0;
		virtual Transform2D GetTransform() = 0;

		explicit ACollidable(ACollider* collider)
		{
			this->collider = collider;
			AddInstance(this);
		}

		virtual ~ACollidable()
		{
			delete collider;
			RemoveInstance(this);
		}
};