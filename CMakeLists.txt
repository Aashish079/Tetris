cmake_minimum_required(VERSION 3.25)
project(sfml_test)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp
        src/state_machine.cpp
        src/game.cpp
        src/asset_manager.cpp
        src/Intro_State.cpp
        src/MainMenuState.cpp
        src/GamePlayState.cpp
        src/InputManager.cpp

)
add_executable(sfml_test ${SOURCE_FILES})
#include_directories(inc)
include_directories(/opt/homebrew/include/SFML inc)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
