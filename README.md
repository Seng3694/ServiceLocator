# C++ Simple ServiceLocator #
A simple implementation of the service locator design pattern in C++.

## Usage ##

### Single Instance ###
Register an instance:
```cpp
ServiceLocator locator;
locator.registerInstance<IMathService>(new MathService());
```
And resolve it somewhere else:
```cpp
auto svc1 = locator.resolve<IMathService>();
auto svc2 = locator.resolve<IMathService>(); // <= same instance
```


### Lazy Initialization ###
Register a delegate which creates a shared pointer to the corresponding instance:
```cpp
ServiceLocator locator;
locator.registerCreator<IMathService>([]() { return std::make_shared<MathService>(); });
```
Everytime you call `resolve`, the service locator will call the delegate and return the pointer:
```cpp
auto svc1 = locator.resolve<IMathService>();
auto svc2 = locator.resolve<IMathService>(); // <= not the same instance
```

### Clearing all registrations

You can clear all registrations manually (will be called in destructor automatically):
```cpp
locator.clear();
```

## License ##

You can redistribute it and/or modify it under the terms of the MIT license. See [LICENSE][1] for details.

[1]:LICENSE