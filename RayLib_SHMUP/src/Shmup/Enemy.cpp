#include "raylib.h"
#include "raymath.h"
#include "Shmup/Enemy.h"
#include "Shmup/InstanceList.hpp"
#include "Namespaces/GameStatus.h"
#include "Namespaces/Utils.h"
#include "Files.cpp"

constexpr unsigned int SHIP_COLUMNS_COUNT = 4;
constexpr unsigned int SHIP_TYPES_MAX_INDEX = SHIP_COLUMNS_COUNT*3-1; //4 columns, 3 lines, index starts at 0

Enemy::Enemy(unsigned long long spawnIndex, Vector2 position, Vector2 direction, Color tint, unsigned int type) : GraphicObject()
{
	if (type > SHIP_TYPES_MAX_INDEX) type = SHIP_TYPES_MAX_INDEX;

	this->spawnIndex = spawnIndex;
	this->position = position;
	this->direction = direction;
	this->tint = tint;
	texture = LoadTexture(SHIP_TEXTURE);
	center = { 0.5f,0.5f };
	scale = { 1,1 };
	orientation = 180;
	source = GetSourceRect(texture, SHIP_TEXTURE_SIZE, { (float)(type%SHIP_COLUMNS_COUNT), (float)(type/SHIP_COLUMNS_COUNT)+3});
	
	RandomChangeSettings();
	AddInstance(this);
}

Enemy::~Enemy()
{
	GraphicObject::~GraphicObject();
	RemoveInstance(this);
}

void Enemy::Update()
{
	if (position.x > 50 && position.y > 50 && position.x < GameStatus::screenWidth - 50 && position.y < GameStatus::screenHeight - 50)
	{
		direction = Vector2Rotate(direction, rotationSpeed + Utils::randMToN(-1, 1));
		isNegativeRotationSpeed ?
			rotationSpeed += rotationAcceleration :
			rotationSpeed -= rotationAcceleration;

		if (rotationSpeedDefault * (signbit(rotationSpeedDefault) ? -1 : 1) < rotationSpeed * (signbit(rotationSpeed) ? -1 : 1))
		{
			rotationSpeed = rotationSpeedDefault * (signbit(rotationSpeedDefault) ? -1 : 1) * (signbit(rotationSpeed) ? -1 : 1);
			isNegativeRotationSpeed = !isNegativeRotationSpeed;

			if (isNegativeRotationSpeed)
				RandomChangeSettings();
		}
	}

	position = Vector2Add(position, Vector2Scale(direction, speed));

	Vector2 speedDirection = Vector2Scale(direction, 1000);
	orientation = Vector2Angle({ 1,1 }, speedDirection) - 45;
#if DEBUG
	DrawLineV(position, Vector2Add(position, speedDirection), WHITE);
#endif

	Vector2 enemyHalfSize = { texture.width / 2, texture.height / 2 };

	if (   position.x < enemyHalfSize.x && speedDirection.x <= 0
		|| position.x > GameStatus::screenWidth - enemyHalfSize.x && speedDirection.x >= 0
	)
	{
		direction = Vector2Reflect(speedDirection, { 1,0 });
		RandomChangeSettings();
	}
	else if (  position.y < enemyHalfSize.y && speedDirection.y <= 0
			|| position.y > GameStatus::screenHeight - enemyHalfSize.y && speedDirection.y >= 0
	)
	{
		direction = Vector2Reflect(speedDirection, { 0,1 });
		RandomChangeSettings();
	}

	direction = Vector2Normalize(direction);
}

void Enemy::RandomChangeSettings()
{
	rotationSpeedDefault = rotationSpeed = (spawnIndex % 2 == 1 ? Utils::randMToN(1, 2) : -Utils::randMToN(1, 2)) + Utils::randMToN(-0.5f, 0.5f);
	rotationAcceleration = Utils::randMToN(0.003f, 0.02f);
	isNegativeRotationSpeed = signbit(rotationSpeed);
	speed = Utils::randMToN(3, 5);
}