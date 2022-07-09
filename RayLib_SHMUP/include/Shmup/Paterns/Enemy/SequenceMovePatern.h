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
		enum class Type
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
			int one   = startIndex + 1;
			int two   = startIndex + 2;
			int three = startIndex + 3;
			int four  = startIndex + 4;

			sequence->type			= (SequenceMovePatern::Type)std::stof(input[startIndex]);
			sequence->startTime		= std::stof(input[one]);
			sequence->endTime		= std::stof(input[two]);
			sequence->rotationSpeed = std::stof(input[three]);
			sequence->speed			= std::stof(input[four]);
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
