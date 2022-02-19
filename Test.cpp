#include <cassert>
#include <ServiceLocator.hpp>

//interface
class IMathService
{
public:
	virtual ~IMathService() {};

	virtual float add(const float& a, const float& b) = 0;
	virtual float subtract(const float& a, const float& b) = 0;
	virtual float multiply(const float& a, const float& b) = 0;
	virtual float divide(const float& a, const float& b) = 0;
};

//implementation
class MathService : public IMathService
{
public:
	int state;

	float add(const float& a, const float& b) override { return a + b; }
	float subtract(const float& a, const float& b) override { return a - b; }
	float multiply(const float& a, const float& b) override { return a * b; }
	float divide(const float& a, const float& b) override { return a / b; }
};

int main()
{
	ServiceLocator locator;

	//Single instance creation => everytime "resolve" gets called the same instance will be returned
	locator.registerInstance<IMathService>(new MathService());

	auto mathService = locator.resolve<IMathService>();
	assert(mathService);
	assert(mathService->add(10, 20) == 30);
	assert(mathService->subtract(30, 10) == 20);
	assert(mathService->multiply(2, 2.5) == 5);
	assert(mathService->divide(30, 10) == 3);

	//simple check if it's really the same instance
	auto test = std::static_pointer_cast<MathService>(mathService);
	assert(test->state == 0);
	test->state = 1;
	test = std::static_pointer_cast<MathService>(locator.resolve<IMathService>());
	assert(test->state == 1);


	//explicit clear of all instances
	locator.clear();
	//there should be no IMathService anymore
	mathService = locator.resolve<IMathService>();
	assert(!mathService);


	//you can create lazy instances with a delegate which returns a shared ptr
	//the instance will be created everytime the "resolve" method gets called
	locator.registerCreator<IMathService>([]() { return std::make_shared<MathService>(); });
	
	mathService = locator.resolve<IMathService>();
	assert(mathService);

	//same check as above but this time changing the state and resolving the service should return an other instance
	test = std::static_pointer_cast<MathService>(mathService);
	assert(test->state == 0);
	test->state = 1;

	test = std::static_pointer_cast<MathService>(locator.resolve<IMathService>());
	assert(test->state == 0);

	return 0;
}