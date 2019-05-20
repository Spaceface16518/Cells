cmake_minimum_required(VERSION 3.14)
project(cells)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (UNIX)
    include_directories("/usr/local/include") # For Homebrew packages mainly
endif ()

find_package(SFML 2.5 REQUIRED COMPONENTS graphics)


add_executable(cells main.cpp game.cpp game.h Board.cpp Board.h Cell.cpp Cell.h mod.h options.cpp options.h)
add_executable(test test.cpp catch.h Board.cpp Board_test.cpp Board.h Cell.cpp Cell.h mod.h mod_test.cpp game.cpp game.h)

target_link_libraries(cells sfml-graphics)
target_link_libraries(test sfml-graphics)