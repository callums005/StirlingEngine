cmake_minimum_required(VERSION 3.2)

project(Sandbox LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
option(BUILD_SHARED_LIBS "Build shared libaries" OFF)

file(GLOB_RECURSE SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_DIR})

add_subdirectory(StirlingEngine)

target_link_libraries(${PROJECT_NAME} PUBLIC StirlingEngine)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/StirlingEngine/include)