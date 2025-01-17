cmake_minimum_required(VERSION 3.15...3.31)
project(Spyro-dotd-Save-Editor LANGUAGES CXX)
set (CMAKE_CXX_STANDARD 20)

set(SOURCES src/save_data.cpp src/gui.cpp src/main.cpp)
add_executable(Spyro-dotd-Save-Editor ${SOURCES})
target_include_directories(Spyro-dotd-Save-Editor PRIVATE ${PROJECT_SOURCE_DIR}/include)

add_subdirectory(wxWidgets)
target_link_libraries(Spyro-dotd-Save-Editor wx::core)
