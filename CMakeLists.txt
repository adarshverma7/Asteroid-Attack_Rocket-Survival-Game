# Minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Project name and language
project(SpaceRocketGame LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the SFML library
find_package(SFML 2.5 COMPONENTS graphics window system audio REQUIRED)

# Define the executable
add_executable(SpaceRocketGame main.cpp)

# Link SFML libraries
target_link_libraries(SpaceRocketGame PRIVATE sfml-graphics sfml-window sfml-system sfml-audio)

# Specify the include directories (optional if SFML is installed system-wide)
# target_include_directories(SpaceRocketGame PRIVATE ${SFML_INCLUDE_DIR})

# Copy assets to the build directory
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
