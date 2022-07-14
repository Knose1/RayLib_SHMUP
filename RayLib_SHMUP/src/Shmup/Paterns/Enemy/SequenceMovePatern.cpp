#include "raylib.h"
#include "raymath.h"
#include "Namespaces/GameStatus.h"
#include "Namespaces/MathUtils.h"
#include "Shmup/AMovable.h"
#include "Shmup/Paterns/Enemy/SequenceMovePatern.h"

void SequenceMovePatern::SetDefault(IPaternData* data)
{
	// Cast Data
	//--------------------------------------------------------//
	SequenceMovePatern::SequencePatern* sequencePatern;
	sequencePatern = (SequenceMovePatern::SequencePatern*)data;

	size_t length = sequencePatern->paternSequence.size();
	sequencePatern->sequenceDone.clear();
	sequencePatern->sequenceDone.resize(length);
	sequencePatern->time = 0;
}

void SequenceMovePatern::DoPatern(AMovable* movable, IPaternData* data)
{
	SequenceMovePatern::SequencePatern* sequencePatern;
	
	float rotation = movable->orientation;
	Vector2 position = movable->position;
	Vector2 direction = movable->direction;
	float timeScaled = GameStatus::constantFrameTime * movable->speed;

	// Cast Data
	//--------------------------------------------------------//
	sequencePatern = (SequenceMovePatern::SequencePatern*)data;
	

	// Enable instant array
	//--------------------------------------------------------//
	size_t length = sequencePatern->paternSequence.size();
	if (sequencePatern->sequenceDone.size() != length)
	{
		sequencePatern->sequenceDone.clear();
		sequencePatern->sequenceDone.resize(length);
	}

	// Get direction and rotation
	//--------------------------------------------------------//
	for (size_t i = 0; i < length; i++)
	{
		auto sequence = sequencePatern->paternSequence[i];
		if (sequencePatern->time < sequence.startTime || sequencePatern->time > sequence.endTime)
			continue;
		switch (sequence.type)
		{
			case(SequenceMovePatern::Type::SET):
			{
				if (sequencePatern->sequenceDone[i])
					continue;
				
				rotation = sequence.rotationSpeed;
				direction = Vector2Scale(MathUtils::polarToCartesian(rotation), sequence.speed);

				sequencePatern->sequenceDone[i] = true;
			}
			case(SequenceMovePatern::Type::INSTANT):
			{
				if (sequencePatern->sequenceDone[i])
					continue;
				
				rotation += sequence.rotationSpeed;
				direction = Vector2Scale(MathUtils::polarToCartesian(rotation), sequence.speed);

				sequencePatern->sequenceDone[i] = true;
			}

			case(SequenceMovePatern::Type::CONTINUS):
			{
				rotation += sequence.rotationSpeed * timeScaled;
				direction = Vector2Scale(MathUtils::polarToCartesian(rotation), sequence.speed);
			}
			default:
				continue;
		}
	}

	position = Vector2Add(position, Vector2Scale(direction, timeScaled));
	//ComputerOffset(rotation, position, *sequencePatern);
	movable->position = position;
	movable->orientation = rotation;
	movable->direction = direction;
	sequencePatern->time += timeScaled;
}
