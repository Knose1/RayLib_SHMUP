#pragma once
#include <iostream>
#include <sstream>
#include "Shmup/IMovable.h"

class Enemy :
	public InstanceList<Enemy>,
	public AMovable
{
	public:
		
		Enemy(unsigned long long spawnIndex, Vector2 position, Vector2 direction, Color tint, unsigned int type);
		~Enemy();

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
