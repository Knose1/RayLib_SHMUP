#pragma once
#include "raylib.h"
#include "Shmup/AGraphicObject.h"
#include "Namespaces/GameStatus.h"

class Explosion :
	public AGraphicObject
{
	public:
		const float FRAME_RATE = 2.0f;
		static constexpr unsigned int FRAMES = 5u;
		const float START_COUNTDOWN = FRAMES * FRAME_RATE * GameStatus::constantFrameTime;

	//----------------------------------//

	public:
		unsigned int frame = 0u;
	private:
		float countdown;
		bool deleted = false;
	
	//----------------------------------//

	public:
		Explosion(Vector2 position);

	private:
		virtual void Update() override;
		virtual void Draw() override;
};