cmake_minimum_required(VERSION 3.2)

project(StirlingEngine LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
option(BUILD_SHARED_LIBS "Build shared libaries" OFF)

file(GLOB_RECURSE SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)


include(FetchContent)
FetchContent_Declare(SFML
	GIT_REPOSITORY https://github.com/SFML/SFML.git
	GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_library(${PROJECT_NAME} STATIC ${SOURCE_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics)

install(TARGETS ${PROJECT_NAME})