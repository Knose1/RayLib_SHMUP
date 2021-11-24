#pragma once
#include "Shmup/Visual.h"
#include "Shmup/Shoot.h"
#include "Shmup/Paterns/PaternVSpread.h"
#include "Shmup/Paterns/PaternLinear.h"

class Player :
    public GraphicObject
{
	private: 
		static Patern* paterns[];
		int _currentPatern = 0;
		Patern* patern = paterns[_currentPatern];

	public:
		//static Player* instance;
		std::vector<Shoot*> shoots;
		
		Player();
		~Player();

		virtual void Update() override;
		virtual void Draw() override;

	protected:
		int GetPaternIndex();
		void SetPaternIndex(int currentPatern);

	private:
		void DoShoot(Vector2 toMouse);
		Shoot* CreateShoot();
        Shoot* FindShootOrCreate();
};