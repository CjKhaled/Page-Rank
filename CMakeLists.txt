cmake_minimum_required(VERSION 3.27)
project(Project2)

set(CMAKE_CXX_STANDARD 17)

set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

Include(FetchContent)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.4.0 # seems to work with CLion - if you run into problems, try an older version of catch2 v3
)
FetchContent_MakeAvailable(Catch2)

include_directories(test-unit)

add_executable(Main
        main.cpp
        src/AdjacencyList.cpp
        src/AdjacencyList.h
)

add_executable(Tests
        test-unit/test.cpp)

target_link_libraries(Tests PRIVATE Catch2::Catch2WithMain)
