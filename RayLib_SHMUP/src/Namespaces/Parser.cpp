#include "raylib.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <typeinfo>
#include "Namespaces/Utils.h"
#include "Namespaces/Parser.h"

std::vector<std::string> Parser::ParseCSV(const char* string, int size) 
{
	//Replace new line by
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
	/*//Remove the last comma and the return; Split string
	std::vector<std::string> splited = ParseCSV(string, SequenceMovePatern::SEQUENCE_FIELD_COUNT);
	std::vector<SequenceMovePatern::Sequence> toReturn;

	//Init sequence list
	SequenceMovePatern::Sequence sequence;
	const size_t length = splited.size() / SequenceMovePatern::SEQUENCE_FIELD_COUNT;
	for (size_t i = 0; i < length; i++)
	{
		sequence = {SequenceMovePatern::Type::CONTINUS,1,2,3,4};
		SequenceMovePatern::InitSequence(&sequence, splited, i* SequenceMovePatern::SEQUENCE_FIELD_COUNT);
		
		toReturn.push_back(sequence);
	}

	return toReturn;*/

	return ParseCSV<SequenceMovePatern::Sequence>(string, SequenceMovePatern::SEQUENCE_FIELD_COUNT, SequenceMovePatern::InitSequence);
}


template<typename T>
std::vector<T> Parser::ParseCSV(const char* string, int size, void lineParser(T* object, std::vector<std::string> stringInput, int startIndex))
{
	//Remove the last comma and the return; Split string
	std::vector<std::string> splited = ParseCSV(string, size);
	std::vector<T> toReturn;

	//Init list item
	T sequence;
	const size_t length = splited.size() / size;
	for (size_t i = 0; i < length; i++)
	{
		sequence = {};
		lineParser(&sequence, splited, i * size);

		toReturn.push_back(sequence);
	}

	return toReturn;
}