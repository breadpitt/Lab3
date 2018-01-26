cmake_minimum_required(VERSION 3.8)
project(OSLab3)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp PageFrameAllocator.cpp PageFrameAllocator.h)
add_executable(OSLab3 ${SOURCE_FILES})