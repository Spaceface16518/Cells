cmake_minimum_required(VERSION 3.14)
project(cells)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Curses 6.1 REQUIRED)

include_directories(${CURSES_INCLUDE_DIR})

add_executable(cells main.cpp game.cpp game.h Board.cpp Board.h Cell.cpp Cell.h mod.h options.cpp options.h)
add_executable(test test.cpp catch.h Board.cpp Board_test.cpp Board.h Cell.cpp Cell.h mod.h mod_test.cpp game.cpp game.h)

target_link_libraries(cells ${CURSES_LIBRARIES})
target_link_libraries(test ${CURSES_LIBRARIES})