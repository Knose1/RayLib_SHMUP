#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include "Namespaces/Utils.h"
#include "Shmup/Paterns/Enemy/SequenceMovePatern.h"
namespace Parser
{
	std::vector<std::string> ParseCSV(const char* string, int size);
	std::vector<SequenceMovePatern::Sequence> GetSequencePatern(const char* string);
}