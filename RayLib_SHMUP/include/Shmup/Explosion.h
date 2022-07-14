#pragma once
#include "raylib.h"
#include "Shmup/AGraphicObject.h"
#include "Namespaces/GameStatus.h"

/// <summary>
/// An explosion animation. It automatiquely delete itself at the end
/// </summary>
class Explosion :
	public AGraphicObject
{
	public:
		/// <summary>
		/// Number of frames before showing next frame
		/// </summary>
		const float FRAME_RATE = 2.0f;
		/// <summary>
		/// Number of frames in the animation
		/// </summary>
		static constexpr unsigned int FRAMES = 5u;
	private:
		/// <summary>
		/// The countdown at start of animation
		/// </summary>
		const float START_COUNTDOWN = FRAMES * FRAME_RATE * GameStatus::constantFrameTime;

	//----------------------------------//
	
	private:
		/// <summary>
		/// Current frame of the animation
		/// </summary>
		unsigned int frame = 0u;
		/// <summary>
		/// Countdown before the end of the animation
		/// </summary>
		float countdown;
		/// <summary>
		/// Whether the object has reached the end of the animation or not
		/// </summary>
		bool deleted = false;
	
	//----------------------------------//

	public:
		Explosion(Vector2 position);

	private:
		virtual void Update() override;
		virtual void Draw() override;
};