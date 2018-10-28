cmake_minimum_required(VERSION 3.5)

project (ServiceLocationTest)

set(SOURCES
	"Main.cpp" 
	"ServiceLocator.cpp" 
	"ServiceLocator.h" 
	"ServiceLocator.inl"
)

add_executable(${PROJECT_NAME} ${SOURCES})