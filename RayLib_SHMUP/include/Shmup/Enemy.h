#pragma once
#include <iostream>
#include <sstream>
#include "Shmup/IMovable.h"
#include "Shmup/Paterns/Enemy/SequenceMovePatern.h"

class Enemy :
	public InstanceList<Enemy>,
	public AMovable
{
	public:
		SequenceMovePatern* patern = new SequenceMovePatern();
		
		Enemy(unsigned long long spawnIndex, Vector2 position, Vector2 direction, Color tint, unsigned int type);
		virtual ~Enemy() override;

		virtual void Update() override;
	
	protected:
		void RandomChangeSettings();

	private:
		unsigned long long spawnIndex;
		float rotationSpeedDefault;
		float rotationSpeed;
		float rotationAcceleration;
		bool isNegativeRotationSpeed;
};
