#pragma once
#include "Shmup/Collision/Collider.h"
#include "Shmup/InstanceList.h"

class ACollidable : 
	public InstanceList<ACollidable>
{
	protected:
		ACollider* collider = nullptr;
	
	public:
		ACollider* GetCollider();
		virtual void OnCollision(ACollidable * other) = 0;
		virtual Transform2D GetTransform() = 0;

		explicit ACollidable();

		virtual ~ACollidable();

	protected:
		void Init();
};