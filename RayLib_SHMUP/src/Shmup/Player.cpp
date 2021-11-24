#include <iostream>
#include <cassert>
#include "raylib.h"
#include "raymath.h"
#include "Shmup/Player.h"
#include "Shmup/Shoot.h"
#include "Namespaces/Controller.h"
#include "Namespaces/GameStatus.h"

constexpr auto PLAYER_TEXTURE = "./assets/textures/Player.png";
Patern* Player::paterns[] = { new PaternLinear(), new PaternVSpread() };

unsigned long long shootIndex = 0;

#pragma region Constructor / Destructor
Player::Player() : GraphicObject()
{
	texture = LoadTexture(PLAYER_TEXTURE);
	source = { 0,0, (float)texture.width, (float)texture.height };
	position = { GameStatus::screenWidth / 2, GameStatus::screenHeight / 2 };
	scale = { 2.0f, 2.0f };
	orientation = 0;
	tint = WHITE;

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
	Draw();

	const Vector2 right = { 1, 0 };
	Vector2 toMouse = Controller::GetPlayerDirection(position); //Vector2Subtract(mousePos, playerTurret.position);
	orientation = Vector2Angle(right, toMouse);

	if (Controller::Shoot()) DoShoot(toMouse);

	if (Controller::PreviousPatern()) 
	{
		SetPaternIndex(GetPaternIndex() - 1);
	}
	else if (Controller::NextPatern()) 
	{
		SetPaternIndex(GetPaternIndex() + 1);
	}
}

void Player::Draw()
{
	float width = (float)texture.width;
	float height = (float)texture.height;
	float scaledW = width * scale.x;
	float scaledH = height * scale.y;
	Vector2 offset = { height * scale.x / 2, height * scale.y / 2 };

	DrawTexturePro(
		texture,
		source,
		{ position.x, position.y, scaledW, scaledH },
		offset,
		orientation,
		tint
	);
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

void Player::DoShoot(Vector2 toMouse)
{	
	Shoot* shoot = FindShootOrCreate();
	shoot->direction = Vector2Normalize(toMouse);

	Vector2 dir = shoot->direction;
	Vector2 normalDir = dir;
	normalDir.y = normalDir.x;
	normalDir.x = -shoot->direction.y;

	shoot->position = Vector2Add(position, Vector2Scale(dir, texture.width * scale.x));
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