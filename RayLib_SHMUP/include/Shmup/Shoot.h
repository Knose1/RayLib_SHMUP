#pragma once
#include "raylib.h"
#include "MyClasses/Visual.h"
#include "MyClasses/IMovable.h"
#include "MyClasses/Paterns/Patern.h"


class Shoot :
	public GraphicObject,
	public IMovable
{
	private:
		unsigned long long spawnIndex;
		bool fired;
		int _currentPatern = 0;
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