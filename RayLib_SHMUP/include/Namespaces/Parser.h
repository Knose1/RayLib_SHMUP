#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include "Namespaces/Utils.h"
#include "Shmup/Paterns/Enemy/SequenceMovePatern.h"
namespace Parser
{
	std::vector<SequenceMovePatern::Sequence> GetSequencePatern(const char* string);
}