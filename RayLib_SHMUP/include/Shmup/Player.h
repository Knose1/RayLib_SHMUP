#pragma once
#include "Shmup/Shoot.h"
#include "Shmup/Paterns/Shoot/PaternVSpread.h"
#include "Shmup/Paterns/Shoot/PaternLinear.h"

class Player :
	public AMovable
{
	private: 
		static APatern* paterns[];
		int _currentPatern = 0;
		APatern* patern = paterns[_currentPatern];

	public:
		//static Player* instance;
		std::vector<Shoot*> shoots;
		
		Player();
		~Player();

		virtual void Update() override;

	protected:
		int GetPaternIndex();
		void SetPaternIndex(int currentPatern);

	private:
		void DoShoot(Vector2 direction);
		Shoot* CreateShoot();
        Shoot* FindShootOrCreate();
};