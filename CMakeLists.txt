cmake_minimum_required(VERSION 3.13)
project(leetcode)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(src)
include_directories(src/leetcode)

find_package(fmt)

file(GLOB leetcode_SRC
    "*.cpp"
    "*.h"
    "src/*.cpp"
    "src/*.h"
    "src/leetcode/*.h"
    "src/leetcode/*.cpp"
        "src/leetcode/dp/*"
        "src/leetcode/design/*"
)

add_executable(leetcode ${leetcode_SRC} src/leetcode/design/ThreadsCase1.cpp src/leetcode/LowerCase.cpp)