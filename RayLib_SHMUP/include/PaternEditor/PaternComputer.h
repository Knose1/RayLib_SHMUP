#pragma once
#include "Shmup/Paterns/Enemy/SequenceMovePatern.h"
#include "Shmup/AMovable.h"

class PaternComputer :
    public AMovable
{
	public:
		SequenceMovePatern::SequencePatern data;
		float startPositionX = 0;
		float startPositionY = 0;
	
private:
		SequenceMovePatern* patern = new SequenceMovePatern();
		Vector2 oldPosition;

	public:
		void SetPatern(std::vector<SequenceMovePatern::Sequence> patern);
		virtual void Update() override;
};