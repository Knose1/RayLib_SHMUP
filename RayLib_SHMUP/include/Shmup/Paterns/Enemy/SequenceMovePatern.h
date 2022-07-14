#pragma once
#include "Shmup/Paterns/AOffsetablePatern.h"
#include <iostream>
#include <string>
#include <vector>
/// <summary>
/// A patern computed by a sequence of rotation and velocity.<br/>
/// This patern can be loaded from a file content.
/// </summary>
class SequenceMovePatern :
	public AOffsetablePatern
{
	public: 
		/// <summary>
		/// The number of fields in a sequence
		/// </summary>
		static constexpr int SEQUENCE_FIELD_COUNT = 5;
		enum class Type
		{
			INSTANT = 0,
			CONTINUS = 1,
			SET = 2
		};
		/// <summary>
		/// A sequence for SequenceMovePatern
		/// </summary>
		struct Sequence 
		{
			Type type;
			float startTime;
			float endTime;
			float rotationSpeed;
			float speed;
		};
		
		/// <summary>
		/// Create a sequence from a file content
		/// </summary>
		/// <param name="sequence">The created sequence</param>
		/// <param name="input">The file content</param>
		/// <param name="startIndex">The index at which the first data can be found from the file content.</param>
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

		/// <summary>
		/// The datas of SequenceMovePatern.
		/// </summary>
		struct SequencePatern : public AOffsetablePatern::IOffserablePaternData
		{
			std::vector<Sequence> paternSequence;
			std::vector<bool> sequenceDone;
			float time;
		};

		virtual void SetDefault(IPaternData* data) override;
		virtual void DoPatern(AMovable* movable, IPaternData* data) override;
};
