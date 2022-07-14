#include "Namespaces/Files.h"
#include "Shmup/Explosion.h"
#include "Namespaces/GameStatus.h"

Explosion::Explosion(Vector2 position) : AGraphicObject()
{
	this->position = position;
	texture = LoadTextureFromImage(Files::TILES_IMAGE);
	source = {};
	center = { 0.5f, 0.5f };
	scale = { 2.5f, 2.5f };
	orientation = 0;
	tint = WHITE;
	
	frame = 0;
	countdown = START_COUNTDOWN;
}

void Explosion::Update()
{
	countdown -= GameStatus::constantFrameTime;
	frame = (START_COUNTDOWN - countdown) / (FRAME_RATE * GameStatus::constantFrameTime);
	if (countdown <= 0)
	{
		if (deleted) delete this;
		deleted = true;
	}
}

void Explosion::Draw()
{
	if (deleted) return;

	source = Files::GetSourceRect(this->texture, Files::TILES_TEXTURE_SIZE, { (float)frame + 4, 0 });
	DefaultDrawMethod(texture, position, source, center, scale, orientation, tint);
}
