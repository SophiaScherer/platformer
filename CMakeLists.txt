cmake_minimum_required(VERSION 3.26)
project(platformer)

set(CMAKE_CXX_STANDARD 23)

file(COPY "external/lib/" DESTINATION "bin/")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(platformer source/main.cpp
    source/Square.h
    source/Square.cpp
    source/Platform.h
    source/Platform.cpp
    source/constants.h
    source/Object.cpp
    source/Object.h
)

target_include_directories(${PROJECT_NAME} PUBLIC
  external/include
)

target_link_directories(${PROJECT_NAME} PUBLIC
  external/lib
)

target_link_libraries(${PROJECT_NAME} PRIVATE
  sfml-audio
  sfml-graphics
  sfml-main
  sfml-network
  sfml-system
  sfml-window
)