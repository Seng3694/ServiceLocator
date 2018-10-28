#pragma once
#include "ServiceLocator.h"

template<typename T>
void ServiceLocator::registerInstance(T* instance)
{
	int hash = typeid(T).hash_code();
	if (instances.find(hash) == instances.end())
		instances.emplace(hash, instance);
}

template<typename T>
void ServiceLocator::registerCreator(std::function<std::shared_ptr<T>()> creator)
{
	int hash = typeid(T).hash_code();
	if (creators.find(hash) == creators.end())
		creators.emplace(hash, creator);
}

template<typename T>
std::shared_ptr<T> ServiceLocator::resolve() const
{
	int hash = typeid(T).hash_code();
	auto itr1 = instances.find(hash);
	if (itr1 != instances.end())
		return std::static_pointer_cast<T>(itr1->second);

	auto itr2 = creators.find(hash);
	if (itr2 != creators.end())
		return std::static_pointer_cast<T>(itr2->second());

	return nullptr;
}