#pragma once
#include "Shmup/Collision/Collider.h"
#include "Shmup/InstanceList.h"

/// <summary>
/// An object that posses a collider
/// </summary>
class ACollidable : 
	public InstanceList<ACollidable>
{
	protected:
		/// <summary>
		/// The collider
		/// </summary>
		ACollider* collider = nullptr;
	
	public:
		/// <summary>
		/// A getter for the collider
		/// </summary>
		ACollider* GetCollider();
		/// <summary>
		/// Called when colliding with another object
		/// </summary>
		/// <param name="other">The object that collided</param>
		virtual void OnCollision(ACollidable* other) = 0;
		/// <summary>
		/// Retrieve the transform for collider calculation
		/// </summary>
		virtual Transform2D GetTransform() = 0;

		explicit ACollidable();
		virtual ~ACollidable();

	protected:
		/// <summary>
		/// Add the collider to calculations
		/// </summary>
		void Enable();
		/// <summary>
		/// Remove the collider from calculations
		/// </summary>
		void Disable();
};