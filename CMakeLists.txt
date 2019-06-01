cmake_minimum_required(VERSION 3.13)
project(SHuva)

set(CMAKE_CXX_STANDARD 14)

include_directories(/usr/local/lib/)
include_directories(/usr/local/include/)
include_directories(src)
include_directories(src/leetcode)

add_executable(SHuva
                main.cpp
                common.h
                src/FirstProblem.cpp
                src/uva_shortcut.h
                src/src_export.h
                src/leetcode/leetcode_common.h
                src/leetcode/two-sum.cpp)

