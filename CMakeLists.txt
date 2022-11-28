cmake_minimum_required(VERSION 3.10.0)

project(Snake)

add_executable(Snake main.cpp ./src/Game.cpp ./src/Snake.cpp ./src/Food.cpp ./src/Bomb.cpp ./src/Menu.cpp ./src/Button.cpp ./src/ButtonText.cpp)

target_include_directories(Snake PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(Snake PRIVATE "YOUR_PATH_TO_SFML_INCLUDE_FOLDER")

target_link_directories(Snake PRIVATE ${CMAKE_SOURCE_DIR}/build/Release)

target_link_libraries(Snake sfml-system-2 sfml-graphics-2 sfml-window-2)
