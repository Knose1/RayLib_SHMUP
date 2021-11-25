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
		APatern* patern;

	public:
		Shoot(unsigned long long i, APatern* patern);
		~Shoot();

		unsigned long long GetSpawnIndex();
		
		void SetDefault(unsigned long long i, APatern* patern);

		bool GetFired();
		void SetFired(bool fired);
		void SetPatern(APatern* patern);

		// H�rit� via GraphicObject
		virtual void Update() override;

};