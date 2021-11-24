#pragma once
#include <iostream>
#include <sstream>
#include "MyClasses/Visual.h"
#include "MyClasses/IMovable.h"

class Enemy :
	public GraphicObject,
	public InstanceList<Enemy>,
	public IMovable
{
	public:
		
		Enemy(unsigned long long spawnIndex, Vector2 position, Vector2 direction, Color tint);
		~Enemy();

		virtual void Update() override;
		virtual void Draw() override;
	
	protected:
		void RandomChangeSettings();

	private:
		unsigned long long spawnIndex;
		float rotationSpeedDefault;
		float rotationSpeed;
		float rotationAcceleration;
		Texture2D colorTexture;
		Rectangle colorTexSource;
		Rectangle collisionBox;
		bool isNegativeRotationSpeed;
};
