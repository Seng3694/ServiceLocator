#include "ServiceLocator.hpp"

ServiceLocator::ServiceLocator() 
	: instances(), creators() 
{
}

ServiceLocator::~ServiceLocator()
{
	clear();
}

void ServiceLocator::clear()
{
	instances.clear();
	creators.clear();
}