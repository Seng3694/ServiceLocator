cmake_minimum_required(VERSION 3.5)

project (ServiceLocator)

set(HEADERS
	"ServiceLocator.hpp"
)

set(SOURCES
	"ServiceLocator.cpp"
)

set(INLINES
	"ServiceLocator.inl"
)

add_library(${PROJECT_NAME} ${HEADERS} ${SOURCES} ${INLINES})
target_include_directories(${PROJECT_NAME} PUBLIC "./")

add_executable(${PROJECT_NAME}Test Test.cpp)
target_link_libraries(${PROJECT_NAME}Test ${PROJECT_NAME})
