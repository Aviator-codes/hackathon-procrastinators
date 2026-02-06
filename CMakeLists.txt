cmake_minimum_required(VERSION 3.10)
project(main)

add_executable(main
    src/main.cpp
    src/glad.c
    src/WindowHandler/WindowHandler.cpp
)

include_directories(${PROJECT_NAME} dependencies/include)

target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/dependencies/libs/libglfw3.a)