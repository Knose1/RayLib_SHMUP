#pragma once
#include "raylib.h"
#include "Shmup/AMovable.h"
#include "Shmup/Paterns/APatern.h"
#include "Shmup/Collision/Collider.h"
#include "Shmup/Collision/ACollidable.h"

/// <summary>
/// An shoot (player or enemy)
/// </summary>
class Shoot :
	public AMovable,
	public ACollidable
{
	private:
		/// <summary>
		/// The sprite to use. Is an index on the spritesheet.
		/// </summary>
		unsigned int type;
		/// <summary>
		/// The index of the spawned shoot
		/// </summary>
		unsigned long long spawnIndex;
		/// <summary>
		/// True if fired
		/// </summary>
		bool fired;
		/// <summary>
		/// The move patern of the shoot
		/// </summary>
		APatern* patern;

	public:
		/// <summary>
		/// Create a shoot
		/// </summary>
		/// <param name="i">The index of the spawned shoot</param>
		/// <param name="patern">The move patern of the shoot</param>
		/// <param name="layer">The collision layer of the shoot</param>
		/// <param name="type">The sprite of the shoot on the spritesheet</param>
		explicit Shoot(unsigned long long i, APatern* patern, CollisionLayer layer, unsigned int type = 3);
		virtual ~Shoot() override;

		/// <summary>
		/// The index of the spawned shoot
		/// </summary>
		/// <returns></returns>
		unsigned long long GetSpawnIndex();
		
		/// <summary>
		/// Reset the shoot
		/// </summary>
		/// <param name="i">The index of the spawned shoot</param>
		/// <param name="patern">The move patern of the shoot</param>
		void SetDefault(unsigned long long i, APatern* patern, float speed=10);

		/// <summary>
		/// True if fired
		/// </summary>
		bool GetFired();
		/// <summary>
		/// Set if the shoot is fired or not
		/// </summary>
		/// <param name="fired"></param>
		void SetFired(bool fired);
		/// <summary>
		/// Set the patern of the shoot
		/// </summary>
		/// <param name="patern"></param>
		void SetPatern(APatern* patern);


		virtual void Update() override;
		virtual void Draw() override;

		virtual void OnCollision(ACollidable* other) override;

		virtual Transform2D GetTransform() override;

};