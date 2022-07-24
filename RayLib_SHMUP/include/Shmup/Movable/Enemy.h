#pragma once
#include <iostream>
#include <sstream>
#include "Shmup/AMovable.h"
#include "Shmup/Paterns/Enemy/SequenceMovePatern.h"
#include "Shmup/Collision/Collider.h"
#include "Shmup/Collision/ACollidable.h"

/// <summary>
/// An enemy spaceship
/// </summary>
class Enemy :
	public AMovable,
	public ACollidable
{
	private:
		unsigned long long spawnIndex;

	public:
		/// <summary>
		/// The sequence patern of the enemy
		/// </summary>
		SequenceMovePatern* patern = new SequenceMovePatern();
		SequenceMovePatern::SequencePatern paternSequence;
		
		/// <summary>
		/// Create a new enemy
		/// </summary>
		/// <param name="spawnIndex">The index of the enemy</param>
		/// <param name="position">The start position</param>
		/// <param name="direction">The start direction of the enemy</param>
		/// <param name="tint">The tint of the sprite</param>
		/// <param name="type">The sprite to use</param>
		explicit Enemy(unsigned long long spawnIndex, SequenceMovePatern::SequencePatern sequence, unsigned int type);
		virtual ~Enemy() override;

		virtual void Update() override;
		virtual void OnCollision(ACollidable* other) override;
		virtual Transform2D GetTransform() override;
	
	protected:
		/// <summary>
		/// Randomely change the patern settings of the enemy
		/// </summary>
		void RandomChangeSettings();
};
