cmake_minimum_required(VERSION 3.14)
project(PhysicsEngine)

# Use modern C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Download and configure raylib directly from GitHub
include(FetchContent)
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.0 # Pulling the stable 5.0 release
)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # We don't need to build raylib's examples
FetchContent_MakeAvailable(raylib)

# Create your executable and link raylib to it
add_executable(${PROJECT_NAME} main.cpp particle.cpp)
#add_executable(${PROJECT_NAME} vector2.cpp)
#add_executable(${PROJECT_NAME} particle.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)