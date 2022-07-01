#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include "Namespaces/Utils.h"
#include "Shmup/Paterns/Enemy/SequenceMovePatern.h"

namespace Parser
{
	/// <summary>
	/// Parse a csv content into a std::vector.<br/>
	/// The size is used to check the line size in the csv content. (line returns are detected as semicolon)
	/// </summary>
	/// <param name="string">The content</param>
	/// <param name="size">The size of a line</param>
	/// <returns>Return an array with all the data.</returns>
	/// <exception>length_error</exception>
	std::vector<std::string> ParseCSV(const char* string, int size);

	template <typename T>
	/// <summary>
	/// Parse a csv content into a std::vector.<br/>
	/// The size is used to check the line size in the csv content. (line returns are detected as semicolon)
	/// </summary>
	/// <typeparam name="T">The type of the line</typeparam>
	/// <param name="string">The content</param>
	/// <param name="size">The size of a line</param>
	/// <param name="lineParser">The function to parse the line</param>
	/// <returns>Return an array with all the data.</returns>
	/// <exception>length_error</exception>
	std::vector<T> ParseCSV(const char* string, int size, void lineParser(T* object, std::vector<std::string> stringInput, int startIndex));
	std::vector<SequenceMovePatern::Sequence> GetSequencePatern(const char* string);

}