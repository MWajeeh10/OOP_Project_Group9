cmake_minimum_required(VERSION 3.12)
project(LUDOGame)

set(CMAKE_CXX_STANDARD 14)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

add_executable(LUDOGame main.cpp game.cpp)

target_include_directories(LUDOGame PRIVATE ${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})
target_link_libraries(LUDOGame PRIVATE ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
