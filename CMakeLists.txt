cmake_minimum_required(VERSION 3.10)
project(particles C)

set(CMAKE_C_STANDARD 11)

# Find SDL2 package
find_package(SDL2 REQUIRED)

# Include SDL2 headers
include_directories(${SDL2_INCLUDE_DIRS})

# Add executable target
add_executable(particles main.c
        particle.c
        window.c
        headers/window.h
        headers/particle.h
        square.c
        headers/square.h
        situations.c
        headers/situations.h
        headers/constants.h
        storage/all_particles.c
        headers/all_particles.h)

# Link SDL2 library to the executable
target_link_libraries(particles ${SDL2_LIBRARIES})
