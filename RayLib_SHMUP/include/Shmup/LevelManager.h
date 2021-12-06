#pragma once
#include <iostream>
#include <string>
#include <vector>
static class LevelManager
{
	public:
		struct LevelSequence
		{
			float time;
			int spawnCount;
			float spawnInterval;
			int enemyColor;
			int enemyPatern;
			int enemyBulletPatern;
		};

	private:
		static constexpr int SEQUENCE_FIELD_COUNT = 6;
		static std::vector<LevelManager::LevelSequence> sequence;

	public: 
		static void Init(char* levelFile);
		static void Update();

		static void InitSequence(LevelSequence* sequence, std::vector<std::string> input, int startIndex)
		{
			sequence->time				= std::stof(input[startIndex]);
			sequence->spawnCount		= std::stoi(input[startIndex + 1]);
			sequence->spawnInterval		= std::stof(input[startIndex + 2]);
			sequence->enemyColor		= std::stoi(input[startIndex + 3]);
			sequence->enemyPatern		= std::stoi(input[startIndex + 4]);
			sequence->enemyBulletPatern = std::stoi(input[startIndex + 5]);
		};
};
std::vector<LevelManager::LevelSequence> LevelManager::sequence;