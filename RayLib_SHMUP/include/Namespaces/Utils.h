#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <functional>

namespace Utils
{
	//char* s_replace(char* string, const char* toReplace, const char* replaced);
	std::string s_replace(std::string string, const char* toReplace, const char* replaced);

	std::vector<std::string> s_split(const char* string, char separator);
	std::vector<std::string> s_split(std::string string, char separator);
	
	template<typename in, typename out>
	std::vector<out> vectorCast(std::function<out(in)> function, std::vector<in> vector) //out(*function)(in)
	{
		const size_t length = vector.size();
		std::vector<out> toReturn(length);
		for (size_t i = 0; i < length; i++)
		{
			toReturn[i] = function(vector[i]);
		}

		return toReturn;
	}
};