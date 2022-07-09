#pragma once
#include <iostream>
#include <vector>

/// <summary>
/// Add a static list for the class <typeparamref name="T"/>
/// </summary>
/// <typeparam name="T">The type of the list. Please ensure that it's a child of InstanceList</typeparam>
template <class T>
class InstanceList
{
	public:
		static std::vector<T*> GetInstances();

		/// <summary>
		/// Add an instance of to the list
		/// </summary>
		/// <typeparam name="T">The type of the list. Please ensure that it's a child of InstanceList</typeparam>
		/// <param name="meToo">The object to add</param>
		static void AddInstance(T* meToo);

		/// <summary>
		/// Remove an instance of to the list
		/// </summary>
		/// <typeparam name="T">The type of the list. Please ensure that it's a child of InstanceList</typeparam>
		/// <param name="meToo">The object to remove</param>
		static void RemoveInstance(T* meToo);
};

template <class T>
class InstanceManager
{
	public:
		static std::vector<T*> instances;
};