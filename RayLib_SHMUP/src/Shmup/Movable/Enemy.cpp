#include "raylib.h"
#include "raymath.h"
#include "Shmup/Movable/Enemy.h"
#include "Shmup/InstanceList.hpp"
#include "Shmup/Explosion.h"
#include "Namespaces/GameStatus.h"
#include "Namespaces/Random.h"
#include "Namespaces/Files.h"

constexpr unsigned int SHIP_LINE_COUNT = 2;
constexpr unsigned int SHIP_COLUMNS_COUNT = 4;
constexpr unsigned int SHIP_TYPES_MAX_INDEX = SHIP_COLUMNS_COUNT*SHIP_LINE_COUNT-1; //4 columns, 3 lines, index starts at 0

//WARNING: The width and height of the enemy are inverted

Enemy::Enemy(unsigned long long spawnIndex, SequenceMovePatern::SequencePatern sequence, unsigned int type) : AMovable(), ACollidable()
{
	if (type > SHIP_TYPES_MAX_INDEX) type = SHIP_TYPES_MAX_INDEX;

	this->spawnIndex = spawnIndex;
	this->position = { 0, 0};
	this->direction = { 0, 1};
	this->tint = WHITE;
	texture = Files::GetShipTexture();
	center = { 0.5f,0.5f };
	scale = { 2.5f,2.5f };
	orientation = 0;
	source = Files::GetSourceRect(texture, Files::SHIP_TEXTURE_SIZE, { (float)(type%SHIP_COLUMNS_COUNT), (float)(type/SHIP_COLUMNS_COUNT)+1});
	paternSequence = sequence;

	collider = new RectCollider(center, source.height * scale.x * 0.4, source.width * scale.y * 0.9, CollisionLayer::Ennemy);

	patern->SetDefault(&paternSequence);

	ACollidable::Enable();

}

Enemy::~Enemy()
{
	delete patern;
	/*new Enemy(
		spawnIndex,
		{ Random::randMToN(100.0f, GameStatus::screenWidth - 100.0f), Random::randMToN(100.0f, GameStatus::screenHeight - 100.0f) }, //position;
		{ Random::rand01(), Random::rand01() }, //direction;
		ColorFromNormalized({ (float)GetRandomValue(0,255), (float)GetRandomValue(0,255), (float)GetRandomValue(0,255), 1 }), //tint;
		{ (unsigned)GetRandomValue(0,11) }
	);*/
}

void Enemy::Update()
{
	patern->DoPatern(this, &paternSequence);
	/*if (position.x > 50 && position.y > 50 && position.x < GameStatus::screenWidth - 50 && position.y < GameStatus::screenHeight - 50)
	{
		direction = Vector2Rotate(direction, rotationSpeed + Random::randMToN(-1, 1));
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
	orientation = Vector2Angle({ 1,0 }, speedDirection);
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

	direction = Vector2Normalize(direction);*/
}

void Enemy::RandomChangeSettings()
{
	/*rotationSpeedDefault = rotationSpeed = (spawnIndex % 2 == 1 ? Random::randMToN(1, 2) : -Random::randMToN(1, 2)) + Random::randMToN(-0.5f, 0.5f);
	rotationAcceleration = Random::randMToN(0.003f, 0.02f);
	isNegativeRotationSpeed = signbit(rotationSpeed);
	speed = Random::randMToN(3, 5);*/
}

Transform2D Enemy::GetTransform()
{
	return {position, orientation, scale};
}

void Enemy::OnCollision(ACollidable * other)
{
	new Explosion(position);
	delete this;
}
