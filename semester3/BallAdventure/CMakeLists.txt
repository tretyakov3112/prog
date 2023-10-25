cmake_minimum_required(VERSION 3.11)

set(CMAKE_CXX_FLAGS "-std=c++17 -g")
set(SFML_STATIC_LIBRARIES TRUE)

project(BallAdventure)

find_package(SFML COMPONENTS Graphics REQUIRED)

add_executable(main main.cpp)

target_link_libraries(main SFML::Graphics)
