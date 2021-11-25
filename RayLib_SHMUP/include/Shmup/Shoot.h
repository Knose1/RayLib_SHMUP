#pragma once
#include "raylib.h"
#include "Shmup/IMovable.h"
#include "Shmup/Paterns/Patern.h"


class Shoot :
	public AMovable
{
	private:
		unsigned long long spawnIndex;
		bool fired;
		Patern* patern;

	public:
		Shoot(unsigned long long i, Patern* patern);
		~Shoot();

		unsigned long long GetSpawnIndex();
		
		void SetDefault(unsigned long long i, Patern* patern);

		bool GetFired();
		void SetFired(bool fired);
		void SetPatern(Patern* patern);

		// Hérité via GraphicObject
		virtual void Update() override;

};