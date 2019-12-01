cmake_minimum_required(VERSION 3.14)
project(compile_scheduler)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
add_executable(
        compile_scheduler
        main.cpp
        src/source_file.cpp
        include/source_file.h
        include/compilation_target.h
        src/input_parser.cpp
        include/input_parser.h
        include/server.h
        src/compilation_step.cpp
        include/compilation_step.h
        src/server.cpp
        src/solution.cpp include/solution.h src/algorithm/grasp.cpp include/algorithm/grasp.h include/algorithm/problem.h src/algorithm/greedy_constructor.cpp include/algorithm/greedy_constructor.h src/algorithm/complex_constructor.cpp include/algorithm/complex_constructor.h src/helpers.cpp include/helpers.h)