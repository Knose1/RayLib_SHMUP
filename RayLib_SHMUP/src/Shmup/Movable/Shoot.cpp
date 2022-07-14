#include "raylib.h"
#include "Namespaces/Controller.h"
#include "Namespaces/GameStatus.h"
#include "Namespaces/Files.h"
#include "Shmup/Movable/Shoot.h"

#pragma region Constructor / Destructor
Shoot::Shoot(unsigned long long i, APatern* patern, CollisionLayer layer, unsigned int type) : AMovable(), ACollidable()
{
	this->type = type;
	texture = LoadTexture(Files::TILES_TEXTURE);
	source = Files::GetSourceRect(texture, Files::TILES_TEXTURE_SIZE, {(float)type, 0});
	center = {0.5f, 0.5f};
	scale = { 2, 2 };
	position = { -100, -100 };
	orientation = 90;
	tint = WHITE;

	collider = new CircleCollider(center, scale.x * source.width / 2 * 0.9, layer);
	
	SetDefault(i, patern);
}

Shoot::~Shoot()
{
	delete collider;
}
#pragma endregion

#pragma region Getter / Setter
bool Shoot::GetFired()
{
	return fired;
}

void Shoot::SetFired(bool fired)
{
	this->fired = fired;
	if (!fired) SetDefault(spawnIndex, patern);

	if (fired) Enable();
	else Disable();
}

void Shoot::SetPatern(APatern* patern)
{
	this->patern = patern;
}
#pragma endregion

void Shoot::SetDefault(unsigned long long i, APatern* patern)
{
	spawnIndex = i;
	this->patern = patern;

	position = {0,0};
	direction = {0,0};
	speed = 10;
	fired = false;
}

unsigned long long Shoot::GetSpawnIndex()
{
	return spawnIndex;
}

void Shoot::Update()
{
	if (!fired) return;

	patern->DoPatern(this, nullptr);
	
	//Outside of the screen
	if (position.x < -100 || position.y < -100 || position.x > GameStatus::screenWidth + 100 || position.y > GameStatus::screenHeight + 100)
		SetFired(false);
}

void Shoot::Draw()
{
	if (fired) AGraphicObject::Draw();
}

void Shoot::OnCollision(ACollidable * other)
{
	SetFired(false);
}

Transform2D Shoot::GetTransform()
{
	return { position, orientation, scale };
}
