cmake_minimum_required(VERSION 3.14)
project(compile_scheduler)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
add_executable(compile_scheduler main.cpp src/source_file.cpp include/source_file.h include/compilation_target.h src/input_parser.cpp include/input_parser.h include/server.h)