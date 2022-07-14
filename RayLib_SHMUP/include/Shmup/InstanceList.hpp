#pragma once
#include "Shmup/InstanceList.h"

template<typename T>
std::vector<T*> InstanceList<T>::GetInstances() 
{
	// Compile-time check
	static_assert(std::is_base_of<InstanceList<T>, T>::value, "type parameter of this class must derive from InstanceList");

	return InstanceManager<T>::instances;
}

template<class T>
void InstanceList<T>::AddInstance(T* meToo)
{
	// Compile-time check
	static_assert(std::is_base_of<InstanceList<T>, T>::value, "type parameter of this class must derive from InstanceList");

	InstanceManager<T>::instances.push_back(meToo);
}

template<class T>
void InstanceList<T>::RemoveInstance(T* meToo)
{
	// Compile-time check
	static_assert(std::is_base_of<InstanceList<T>, T>::value, "type parameter of this class must derive from InstanceList");

	auto& list = InstanceManager<T>::instances;
	std::remove(list.begin(), list.end(), meToo);
	list.resize(list.size() - 1);
}

template <typename T> std::vector<T*> InstanceManager<T>::instances;