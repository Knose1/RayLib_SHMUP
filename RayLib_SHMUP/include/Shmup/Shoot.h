#pragma once
#include "raylib.h"
#include "Shmup/IMovable.h"
#include "Shmup/Paterns/APatern.h"


class Shoot :
	public AMovable
{
	private:
		unsigned int type;
		unsigned long long spawnIndex;
		bool fired;
		APatern* patern;

	public:
		Shoot(unsigned long long i, APatern* patern, unsigned int type = 0);
		~Shoot();

		unsigned long long GetSpawnIndex();
		
		void SetDefault(unsigned long long i, APatern* patern);

		bool GetFired();
		void SetFired(bool fired);
		void SetPatern(APatern* patern);

		// Hérité via GraphicObject
		virtual void Update() override;

};