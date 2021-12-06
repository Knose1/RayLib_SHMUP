#include <string>
#include <vector>

#include "Shmup/LevelManager.h"
#include "Namespaces/Parser.h"

void LevelManager::Init(char* levelFile)
{
	auto csv = Parser::ParseCSV(levelFile, LevelManager::SEQUENCE_FIELD_COUNT);

	const size_t length = csv.size() / LevelManager::SEQUENCE_FIELD_COUNT;
	for (size_t i = 0; i < length; i++)
	{
		LevelManager::LevelSequence levelSequence {};
		LevelManager::InitSequence(&levelSequence, csv, i * LevelManager::SEQUENCE_FIELD_COUNT);

		sequence.push_back(levelSequence);
	}
}

void LevelManager::Update()
{

}