cmake_minimum_required(VERSION 3.23)
project(
	linear-algebra
	VERSION 1.0
	DESCRIPTION ""
	LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()
include(GoogleTest)

add_subdirectory(lib)
add_subdirectory(test)
add_subdirectory(exercises)