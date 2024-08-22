cmake_minimum_required(VERSION 3.10)

# Set the project name
project(assemble)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Find SDL2 package
find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})

# Add the executable
add_executable(assemble
    src/assemble.cpp
)
