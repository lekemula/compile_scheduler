cmake_minimum_required(VERSION 3.14)
project(compile_scheduler)

set(CMAKE_CXX_STANDARD 14)

# Source files
set(SOURCES
    main.cpp
    src/source_file.cpp
    src/input_parser.cpp
    src/compilation_step.cpp
    src/server.cpp
    src/solution.cpp
    src/algorithm/grasp.cpp
    src/algorithm/greedy_constructor.cpp
    src/algorithm/complex_constructor.cpp
    src/helpers.cpp
    src/algorithm/closest_compilation_start_constructor.cpp
    src/algorithm/least_busy_server_constructor.cpp
    src/algorithm/greedy_unique_source_files_constructor.cpp
)

# Header files
set(HEADERS
    include/source_file.h
    include/compilation_target.h
    include/input_parser.h
    include/server.h
    include/solution.h
    include/algorithm/grasp.h
    include/algorithm/problem.h
    include/algorithm/greedy_constructor.h
    include/algorithm/complex_constructor.h
    include/helpers.h
    include/algorithm/closest_compilation_start_constructor.h
    include/algorithm/least_busy_server_constructor.h
    include/algorithm/greedy_unique_source_files_constructor.h
    include/algorithm/cost_functions/cost_function.h
    include/algorithm/cost_functions/most_dependencies_cost.h
    include/algorithm/cost_functions/least_target_dependants_cost.h
)

# Include directories
include_directories(include)

# Add executable
add_executable(compile_scheduler ${SOURCES} ${HEADERS})

# Set required C++ features
target_compile_features(compile_scheduler PRIVATE cxx_std_14)

# Link required 3rd party libraries
# target_link_libraries(compile_scheduler PRIVATE some_library)

