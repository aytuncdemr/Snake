cmake_minimum_required(VERSION 3.10.0)

project(Snake)

add_executable(Snake main.cpp ./src/Game.cpp ./src/Snake.cpp ./src/Food.cpp ./src/Bomb.cpp)

target_include_directories(Snake PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(Snake PRIVATE "C:/Program Files (x86)/C++/Packages/SFML-2.5.1/SFML-2.5.1/include")

target_link_directories(Snake PRIVATE ${CMAKE_SOURCE_DIR}/build/Release)

target_link_libraries(Snake sfml-system-2 sfml-graphics-2 sfml-window-2)