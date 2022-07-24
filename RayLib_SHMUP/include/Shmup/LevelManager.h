#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Paterns/Enemy/SequenceMovePatern.h"

/// <summary>
/// Create the level by spawning the enemies. Work in progess...
/// </summary>
static class LevelManager
{
	public:
		struct LevelSequence
		{
			public:
				float time;
				int spawnCount;
				float spawnInterval;
				int enemyColor;
				SequenceMovePatern::SequencePatern enemyPatern;
				int enemyBulletPatern;
		};

	private:
		static constexpr int SEQUENCE_FIELD_COUNT = 11;
		static std::vector<LevelManager::LevelSequence> sequence;
		static std::vector<int> spawned;
		static float time;
		
	public: 
		static void Init(const char* levelFile);
		static void Update();

		inline static void InitSequence(LevelSequence* sequence, std::vector<std::string> input, int startIndex);
};