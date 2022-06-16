#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <regex>
#include "Namespaces/Utils.h"


/*char* Utils::s_replace(char* string, const char* toReplace, const char* replaced)
{
	if (&toReplace == '\0') return string;

	std::vector<char*> replacePositions;
	char* stringIterator = string;
	const char* toReplaceIterator;

	int stringSize = 0;
	while (stringIterator != '\0')
	{
		++stringSize;
		char* stringLastPointer = stringIterator;
		toReplaceIterator = toReplace;

		while (&toReplaceIterator == &stringIterator)
		{
			
		}
	}

	char* toReturn = new char[stringSize+replacePositions.size()];

	return toReturn;
}*/

std::string Utils::s_replace(std::string string, const char* toReplace, const char* replaced)
{
	return std::regex_replace(string, std::regex(toReplace), replaced);
}

std::vector<std::string> Utils::s_split(const char* string, char separator)
{
	std::string input = string;
	size_t length = std::strlen(string);
	std::vector<std::string> toReturn;

	int copySize;
	char myChar;
	size_t lastI = 0;
	for (size_t i = 0; i < length; i++)
	{
		myChar = *(string++);
		if (myChar == separator) 
		{
			copySize = i - lastI;
			toReturn.push_back(input.substr(lastI, copySize));
			lastI = i+1;
		}
	}

	copySize = length-lastI;
	toReturn.push_back(input.substr(lastI, copySize));
	return toReturn;
}

std::vector<std::string> Utils::s_split(std::string string, char separator)
{
	std::string input = string;
	size_t length = string.length();
	std::vector<std::string> toReturn;

	int copySize;
	char myChar;
	size_t lastI = 0;
	for (size_t i = 0; i < length; i++)
	{
		myChar = string[i];
		if (myChar == separator) 
		{
			copySize = i - lastI;
			toReturn.push_back(input.substr(lastI, copySize));
			lastI = i+1;
		}
	}

	copySize = length-lastI;
	toReturn.push_back(input.substr(lastI, copySize));
	return toReturn;
}