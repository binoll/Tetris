cmake_minimum_required(VERSION 3.00)
project(Tetris)

set(CMAKE_CXX_STANDARD 14)
set(SFML_DIR "SFML-2.6.0/lib/cmake/SFML/")
set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc")
set(SFML_STATIC_LIBRARIES TRUE)

find_package(SFML COMPONENTS graphics audio window system REQUIRED)

add_executable(Tetris main.cpp menu/menu.cpp widgets/widgets.cpp)

target_link_libraries(Tetris sfml-graphics sfml-audio sfml-window sfml-system)

add_custom_target(openal32 COMMAND ${CMAKE_COMMAND} -E copy "${PROJECT_SOURCE_DIR}/SFML-2.6.0/bin/openal32.dll" ${CMAKE_BINARY_DIR})
add_dependencies(Tetris openal32)
