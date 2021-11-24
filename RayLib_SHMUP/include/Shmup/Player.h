#pragma once
#include "MyClasses/Visual.h"
#include "MyClasses/Shoot.h"
#include "MyClasses/Paterns/PaternVSpread.h"
#include "MyClasses/Paterns/PaternLinear.h"

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