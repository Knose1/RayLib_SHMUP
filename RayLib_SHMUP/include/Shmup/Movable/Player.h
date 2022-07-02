#pragma once
#include "Shmup/Movable/Shoot.h"
#include "Shmup/Paterns/Shoot/PaternVSpread.h"
#include "Shmup/Paterns/Shoot/PaternLinear.h"

/// <summary>
/// The player
/// </summary>
class Player :
	public AMovable
{
	private: 
		/// <summary>
		/// The shoot paterns
		/// </summary>
		static APatern* paterns[];
		/// <summary>
		/// Current shoot patern index
		/// </summary>
		int _currentPatern = 0;
		/// <summary>
		/// Current shoot patern
		/// </summary>
		APatern* patern = paterns[_currentPatern];

	public:
		/// <summary>
		/// Player shoots
		/// </summary>
		std::vector<Shoot*> shoots;

		/// <summary>
		/// Construct a new player
		/// </summary>
		Player();
		/// <summary>
		/// Construct the player
		/// </summary>
		virtual ~Player() override;

		virtual void Update() override;

	protected:
		/// <summary>
		/// Get current patern
		/// </summary>
		int GetPaternIndex();
		/// <summary>
		/// Set current patern
		/// </summary>
		void SetPaternIndex(int currentPatern);

	private:
		/// <summary>
		/// Create a shoot in a direction
		/// </summary>
		void DoShoot(Vector2 direction);
		Shoot* CreateShoot();
        Shoot* FindShootOrCreate();
};