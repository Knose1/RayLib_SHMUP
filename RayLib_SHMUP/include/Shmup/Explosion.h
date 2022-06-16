#pragma once
#include "raylib.h"
#include "Shmup/AGraphicObject.h"

class Explosion :
	public AGraphicObject
{
	public:
		const float FRAME_RATE = 30.0f;
		static constexpr unsigned int FRAMES = 5u;

	//----------------------------------//

	public:
		Texture2D texture;
		unsigned int frame = 0u;
	private:
		float countdown;
	
	//----------------------------------//

	public:
		Explosion(Vector2 position);

	private:
		virtual void Update() override;
		virtual void Draw() override;
};