cmake_minimum_required(VERSION 3.10)
project(Tetris)

set(CMAKE_CXX_STANDARD 20)
set(SFML_DIR "SFML-2.6.1/lib/cmake/SFML/")

find_package(SFML COMPONENTS graphics audio REQUIRED)

add_executable(Tetris main.cpp libs.hpp menu/menu.cpp menu/menu.hpp widgets/widgets.cpp widgets/widgets.hpp)

target_link_libraries(Tetris sfml-graphics sfml-audio sfml-window)
