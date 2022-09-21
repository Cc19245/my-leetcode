cmake_minimum_required(VERSION 3.0)
project(my-leetcode)

set(CMAKE_BUILD_TYPE Debug)  # 如果想使用gdb调试功能，这里必须手动设置成Debug模式
add_executable(main main.cpp)