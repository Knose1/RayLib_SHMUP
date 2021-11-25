#include <iostream>
#include <cassert>
#include "raylib.h"
#include "raymath.h"
#include "Shmup/Player.h"
#include "Shmup/Shoot.h"
#include "Namespaces/Controller.h"
#include "Namespaces/GameStatus.h"
#include "Namespaces/Files.h"

APatern* Player::paterns[] = { new PaternLinear(), new PaternVSpread() };

unsigned long long shootIndex = 0;

#pragma region Constructor / Destructor
Player::Player() : AMovable()
{
	texture = LoadTexture(Files::SHIP_TEXTURE);
	source = Files::GetSourceRect(texture, Files::SHIP_TEXTURE_SIZE, {0,0});
	position = { GameStatus::screenWidth / 2, GameStatus::screenHeight / 2 };
	scale = { 3.0f, 3.0f };
	center = { 0.5f, 0.5f };
	orientation = 0;
	tint = WHITE;
	direction = { 0, -1};
	position.y = GameStatus::screenHeight - source.height * scale.y;

	//assert(Player::instance != nullptr);
	//Player::instance = this;

	for (size_t i = 0; i < GameStatus::nbShots; i++)
	{
		shoots.push_back(CreateShoot());
	}
}

Player::~Player()
{
	//Player::instance = nullptr;
	for (std::vector<Shoot*>::iterator it = shoots.end(); it != shoots.begin(); --it)
		delete *it;

	shoots.clear();
}
#pragma endregion

#pragma region Abstract implementation
void Player::Update()
{
	const Vector2 right = { 1, 0 };
	Vector2 toMouse = Controller::GetPlayerDirection(position); //Vector2Subtract(mousePos, playerTurret.position);
	orientation = Vector2Angle(right, Vector2Scale(direction, 1000));
	
	if (Controller::Shoot()) DoShoot(direction);

	if (Controller::PreviousPatern()) 
	{
		SetPaternIndex(GetPaternIndex() - 1);
	}
	else if (Controller::NextPatern()) 
	{
		SetPaternIndex(GetPaternIndex() + 1);
	}
}
#pragma endregion

#pragma region Getter / Setter
int Player::GetPaternIndex()
{
	return _currentPatern;
}

void Player::SetPaternIndex(int currentPatern)
{
	size_t size = std::size(paterns);
	if (currentPatern < 0)
	{
		currentPatern = size + (currentPatern % size);
	}

	_currentPatern = currentPatern % size;
	patern = paterns[_currentPatern];
	shootIndex = 0;
}
#pragma endregion

void Player::DoShoot(Vector2 direction)
{	
	Shoot* shoot = FindShootOrCreate();
	shoot->direction = Vector2Normalize(direction);

	Vector2 dir = shoot->direction;
	Vector2 normalDir = dir;
	normalDir.y = normalDir.x;
	normalDir.x = -shoot->direction.y;

	shoot->position = Vector2Add(position, Vector2Scale(dir, texture.width));
	shoot->SetFired(true);
}

Shoot* Player::CreateShoot() 
{
	Shoot* shoot = new Shoot(shootIndex++, patern);
	return shoot;
}

Shoot* Player::FindShootOrCreate() 
{
	for (std::vector<Shoot*>::iterator it = shoots.begin(); it != shoots.end(); ++it)
	{
		if ((*it)->GetFired() == false)
		{
			(*it)->SetDefault(shootIndex++, patern);
			return (*it);
		}
	}

	return CreateShoot();
}