CMAKE_MINIMUM_REQUIRED(VERSION 3.13.4)
PROJECT(BallAdventure)
set(CMAKE_CXX_FLAGS "-std=c++17 -g")
# set(SFML_STATIC_LIBRARIES TRUE)
SET(CMAKE_CXX_STANDARD 17)

INCLUDE_DIRECTORIES(project/include)

find_package(SFML 2.5 COMPONENTS graphics audio system window REQUIRED)

add_executable(BallAdventure main.cpp)

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio sfml-system sfml-window )


