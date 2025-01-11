cmake_minimum_required(VERSION 3.15...3.31)

project(
	Spyro-dotd-Save-Editor
	VERSION 1.0
	LANGUAGES CXX)

set(SOURCES src/uuid.cpp src/save_data.cpp src/main.cpp)

add_executable(Spyro-dotd-Save-Editor ${SOURCES})
target_include_directories(Spyro-dotd-Save-Editor PRIVATE ${PROJECT_SOURCE_DIR}/include)
