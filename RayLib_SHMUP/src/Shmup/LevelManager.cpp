#include <string>
#include <vector>

#include "Shmup/LevelManager.h"
#include "Shmup/Movable/Enemy.h"
#include "Namespaces/Parser.h"
#include "Namespaces/GameStatus.h"

std::vector<LevelManager::LevelSequence> LevelManager::sequence = {};
std::vector<int> LevelManager::spawned = {};
float LevelManager::time = 0;

void LevelManager::Init(const char* levelFile)
{
	auto csv = Parser::ParseCSV(levelFile, LevelManager::SEQUENCE_FIELD_COUNT);

	const size_t length = csv.size() / LevelManager::SEQUENCE_FIELD_COUNT;
	for (size_t i = 0; i < length; i++)
	{
		LevelManager::LevelSequence levelSequence {};
		LevelManager::InitSequence(&levelSequence, csv, i * LevelManager::SEQUENCE_FIELD_COUNT);

		sequence.push_back(levelSequence);
		spawned.push_back(0);
	}
}

void LevelManager::Update()
{
	int spawn;
	LevelManager::LevelSequence current;

	size_t length = sequence.size();
	for (size_t i = 0; i < length; i++)
	{
		spawn = spawned[i];
		current = sequence[i];
		if (
			current.spawnCount <= spawn ||
			time < current.time + current.spawnInterval * spawn
		)
			continue;

		++spawned[i];
		new Enemy(spawn, current.enemyPatern, current.enemyColor);
	}

	time += GameStatus::constantFrameTime;
}

inline void LevelManager::InitSequence(LevelSequence* sequence, std::vector<std::string> input, int startIndex)
{
	sequence->time = std::stof(input[startIndex]);
	sequence->spawnCount = std::stoi(input[startIndex + 1]);
	sequence->spawnInterval = std::stof(input[startIndex + 2]);
	sequence->enemyColor = std::stoi(input[startIndex + 3]);

	std::string file = input[startIndex + 4];
	file.insert(0, "./assets/Shmup/paterns/");
	file.append(".csv");

	SequenceMovePatern::SequencePatern patern = {};
	patern.paternSequence = Parser::GetSequencePatern(LoadFileText(file.c_str()));
	patern.time = 0;
	patern.positionOffset = 
	{ 
		std::stof(input[startIndex + 5]),
		std::stof(input[startIndex + 6])
	};
	patern.scaleOffset = 
	{ 
		std::stof(input[startIndex + 7]),
		std::stof(input[startIndex + 8])
	};
	patern.rotationOffset = std::stof(input[startIndex + 9]);
	patern.rotationCenter = patern.scaleCenter = { GameStatus::screenWidth / 2, GameStatus::screenHeight / 2 };

	sequence->enemyPatern = patern;
	sequence->enemyBulletPatern = std::stoi(input[startIndex + 10]);
}
