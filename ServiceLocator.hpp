#pragma once

#include <functional>
#include <memory>
#include <unordered_map>

class ServiceLocator
{
public:
	ServiceLocator();
	~ServiceLocator();

	void clear();

	template<typename T>
	void registerInstance(T* instance = new T());

	template<typename T>
	void registerCreator(std::function<std::shared_ptr<T>()> creator = []() { return std::make_shared<T>(); });

	template<typename T>
	std::shared_ptr<T> resolve() const;

private:
	std::unordered_map<size_t, std::shared_ptr<void>> instances;
	std::unordered_map<size_t, std::function<std::shared_ptr<void>()>> creators;
};

#include "ServiceLocator.inl"
