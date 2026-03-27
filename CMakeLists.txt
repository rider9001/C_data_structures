cmake_minimum_required(VERSION 3.22)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if(NOT CMAKE_BUILD_TYPE)
        set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_C_FLAGS_DEBUG "-g -Wall -Wextra -lm")
set(CMAKE_C_FLAGS_RELASE "-O2 -lm")
set(CMAKE_BUILD_PARALLEL_LEVEL 8)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin")
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

file(GLOB SOURCES
    "src/*.c"
)

file(GLOB HEADERS
    "inc/*.h"
)

project(structures C)
include_directories(${PROJECT_SOURCE_DIR}/inc ${PROJECT_SOURCE_DIR}/src)
add_executable(vector vector_test.c ${SOURCES})
add_executable(hashmap hashmap_test.c ${SOURCES})