#pragma once
#include <iostream>
#include <sstream>
#include "Shmup/Visual.h"
#include "Shmup/IMovable.h"

class Enemy :
	public GraphicObject,
	public InstanceList<Enemy>,
	public IMovable
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
