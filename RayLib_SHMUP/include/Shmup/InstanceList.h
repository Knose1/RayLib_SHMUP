#pragma once
#include <iostream>
#include <vector>

template <class T>
class InstanceList
{
	public:
		static std::vector<T*> instances;
};
template <typename T> std::vector<T*> InstanceList<T> ::instances;

template <typename T>
inline void AddInstance(T* meToo);

template <typename T>
inline void RemoveInstance(T* meToo);