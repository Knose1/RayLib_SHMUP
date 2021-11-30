#pragma once
#include "Shmup/Paterns/AOffsetablePatern.h"
#include <iostream>
#include <string>
#include <vector>
class SequenceMovePatern :
	public AOffsetablePatern
{
	public: 
		static constexpr int SEQUENCE_FIELD_COUNT = 5;
		enum Type
		{
			INSTANT = 0,
			CONTINUS = 1,
			SET = 2
		};
		struct Sequence 
		{
			Type type;
			float startTime;
			float endTime;
			float rotationSpeed;
			float speed;
		};
		
		static void InitSequence(Sequence* sequence, std::vector<std::string> input, int startIndex)
		{
			sequence->type			= (SequenceMovePatern::Type)std::stod(input[startIndex    ]);
			sequence->startTime		= std::stod(input[startIndex + 1]);
			sequence->endTime		= std::stod(input[startIndex + 2]);
			sequence->rotationSpeed = std::stod(input[startIndex + 3]);
			sequence->speed			= std::stod(input[startIndex + 4]);
		};

		struct SequencePatern : public AOffsetablePatern::IOffserablePaternData
		{
			std::vector<Sequence> paternSequence;
			std::vector<bool> sequenceDone;
			float time;
		};

		// Inherited via AOffsetablePatern
		virtual void SetDefault(IPaternData* data) override;
		virtual void DoPatern(AMovable* movable, IPaternData* data) override;
};
