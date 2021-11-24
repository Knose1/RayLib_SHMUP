#pragma once
#include "Shmup/InstanceList.h"

template<typename T>
static inline void AddInstance(T* meToo)
{
	InstanceList<T>::instances.push_back(meToo);
}

template<typename T>
static inline void RemoveInstance(T* meToo)
{
	auto position = std::find(InstanceList<T>::instances.begin(), InstanceList<T>::instances.end(), meToo);
	if (position != InstanceList<T>::instances.end()) // if equal, means the element was not found
		InstanceList<T>::instances.erase(position);
}