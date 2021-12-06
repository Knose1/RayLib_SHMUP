#include <iostream>
#include <cassert>
#include "raylib.h"
#include "raymath.h"
#include "Shmup/Player.h"
#include "Shmup/Shoot.h"
#include "Namespaces/MathUtils.h"
#include "Namespaces/Controller.h"
#include "Namespaces/GameStatus.h"
#include "Namespaces/Files.h"

APatern* Player::paterns[] = { new PaternLinear(), new PaternVSpread() };

constexpr Vector2 SCALE = { 2.5f, 2.5f };
constexpr float CONTROLS_INTERPOLATE_THRESHOLD = 0.04f;
Vector2 directionInput = { 0, -0.1};

constexpr float DEFAULT_FIRE_RATE = 0.1f;
float countdown = DEFAULT_FIRE_RATE;
float* countdownPtr = &countdown;


unsigned long long shootIndex = 0;
float maxRotateAngle;

#pragma region Constructor / Destructor
Player::Player() : AMovable()
{
	texture = LoadTexture(Files::SHIP_TEXTURE);
	source = Files::GetSourceRect(texture, Files::SHIP_TEXTURE_SIZE, {0,0});
	position = { GameStatus::screenWidth / 2, GameStatus::screenHeight / 2 };
	scale = SCALE;
	center = { 0.5f, 0.5f };
	orientation = 0;
	tint = WHITE;
	direction = { 0, -1};
	position.y = GameStatus::screenHeight - source.height * scale.y;
	speed = 500;

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
	Vector2 directionInputRaw = Controller::GetPlayerDirection(position); //Vector2Subtract(mousePos, playerTurret.position);
	directionInput = MathUtils::geometricalInterpolation(directionInput, directionInputRaw, CONTROLS_INTERPOLATE_THRESHOLD);
	
	if (directionInput.x != 0 || directionInput.y != 0) 
	{
		direction = {directionInput.x, directionInput.y};
		orientation = Vector2Angle(right, direction);
	}
	else
	{
		direction = MathUtils::polarToCartesian(orientation);
	}
	position = Vector2Add(Vector2Scale(directionInput, speed*GameStatus::constantFrameTime), position);

	scale = SCALE;
	scale.x -= directionInput.y * 0.4f;


	//float bulletAddSpeed = speed * GameStatus::constantFrameTime * Vector2DotProduct(directionInput, Vector2Normalize(direction));
	//bulletAddSpeed = Clamp(bulletAddSpeed, -2, 2);

	if (Controller::Shoot(DEFAULT_FIRE_RATE, countdownPtr)) DoShoot(direction);

	if (Controller::PreviousPatern()) 
	{
		SetPaternIndex(GetPaternIndex() - 1);
	}
	else if (Controller::NextPatern()) 
	{
		SetPaternIndex(GetPaternIndex() + 1);
	}

	position.x = Clamp(position.x, 0, GameStatus::screenWidth);
	position.y = Clamp(position.y, 0, GameStatus::screenHeight);
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
	shoot->direction = direction = Vector2Normalize(direction);
	
	Vector2 dir = direction;
	Vector2 normalDir = dir;
	normalDir.y = normalDir.x;
	normalDir.x = -direction.y;

	shoot->position = position;
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
