cmake_minimum_required(VERSION 3.10.0)

project(Snake)

add_executable(Snake main.cpp ./src/Game.cpp)

target_include_directories(Snake PRIVATE ${CMAKE_BINARY_DIR}/include)
target_include_directories(Snake PRIVATE "C:/Program Files (x86)/C++/Packages/SFML-2.5.1/SFML-2.5.1/include")

target_link_libraries(Snake sfml-system sfml-graphics sfml-window)