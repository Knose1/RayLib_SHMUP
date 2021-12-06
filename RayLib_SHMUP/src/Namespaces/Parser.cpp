#include "raylib.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <typeinfo>
#include "Namespaces/Utils.h"
#include "Namespaces/Parser.h"

std::vector<std::string> Parser::ParseCSV(const char* string, int size) 
{
	std::string myString = Utils::s_replace(Utils::s_replace(Utils::s_replace(std::string(string), "(;\r\n)|(\r\n)|(;\n)|(\n)", ";"), ";$", ""), "(\s|;)+", ";");
	std::vector<std::string> splited = Utils::s_split(myString, ';');

	//Check if correct number of fields by sequence
	if (splited.size() % size != 0)
	{
#if _DEBUG
		throw std::length_error("Incorrect size");
#endif // _DEBUG
		std::cerr << "Sequence Incorrect size at " << __func__;
	}

	return splited;
}

std::vector<SequenceMovePatern::Sequence> Parser::GetSequencePatern(const char* string)
{
	//Remove the last comma and the return; Split string
	std::vector<std::string> splited = ParseCSV(string, SequenceMovePatern::SEQUENCE_FIELD_COUNT);
	std::vector<SequenceMovePatern::Sequence> toReturn;

	//Init sequence list
	const size_t length = splited.size() / SequenceMovePatern::SEQUENCE_FIELD_COUNT;
	for (size_t i = 0; i < length; i++)
	{
		SequenceMovePatern::Sequence sequence{SequenceMovePatern::Type::CONTINUS,1,2,3,4};
		SequenceMovePatern::InitSequence(&sequence, splited, i* SequenceMovePatern::SEQUENCE_FIELD_COUNT);
		
		/*for (size_t j = 0; j < SequenceMovePatern::SEQUENCE_FIELD_COUNT; j++)
		{
			auto owo = typeid(pSequence).name();
			*(pSequence++) = splited[SequenceMovePatern::SEQUENCE_FIELD_COUNT * i + j];
		}*/
		toReturn.push_back(sequence);
	}

	return toReturn;
}