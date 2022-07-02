#pragma once
#include <iostream>
#include <sstream>
#include "Shmup/IMovable.h"
#include "Shmup/Paterns/Enemy/SequenceMovePatern.h"

/// <summary>
/// An enemy spaceship
/// </summary>
class Enemy :
	public InstanceList<Enemy>,
	public AMovable
{
	public:
		/// <summary>
		/// The sequence patern of the enemy
		/// </summary>
		SequenceMovePatern* patern = new SequenceMovePatern();
		
		/// <summary>
		/// Create a new enemy
		/// </summary>
		/// <param name="spawnIndex">The index of the enemy</param>
		/// <param name="position">The start position</param>
		/// <param name="direction">The start direction of the enemy</param>
		/// <param name="tint">The tint of the sprite</param>
		/// <param name="type">The sprite to use</param>
		Enemy(unsigned long long spawnIndex, Vector2 position, Vector2 direction, Color tint, unsigned int type);
		virtual ~Enemy() override;

		virtual void Update() override;
	
	protected:
		/// <summary>
		/// Randomely change the patern settings of the enemy
		/// </summary>
		void RandomChangeSettings();

	private:
		unsigned long long spawnIndex;
		float rotationSpeedDefault;
		float rotationSpeed;
		float rotationAcceleration;
		bool isNegativeRotationSpeed;
};
