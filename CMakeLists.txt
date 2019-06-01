cmake_minimum_required(VERSION 3.13)
project(leetcode)

set(CMAKE_CXX_STANDARD 14)

#include_directories(.)
include_directories(src)
include_directories(src/leetcode)

add_executable(leetcode
        src/leetcode/leetcode_common.h
        src/leetcode/two-sum.cpp
        src/FirstProblem.cpp
        src/src_export.h
        src/uva_shortcut.h
        common.h
        main.cpp)
