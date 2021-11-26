#include "raylib.h"
#include "Namespaces/Controller.h"
#include "Namespaces/GameStatus.h"
#include "Namespaces/Files.h"
#include "Shmup/Shoot.h"

#pragma region Constructor / Destructor
Shoot::Shoot(unsigned long long i, APatern* patern, unsigned int type) : AMovable()
{
	this->type = type;
	texture = LoadTexture(Files::TILES_TEXTURE);
	source = Files::GetSourceRect(texture, Files::TILES_TEXTURE_SIZE, {0, (float)type});
	center = {0.5f, 0.5f};
	scale = { 1, 1 };
	orientation = 90;
	tint = WHITE;

	SetDefault(i, patern);
}

Shoot::~Shoot()
{
	AGraphicObject::~AGraphicObject();
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