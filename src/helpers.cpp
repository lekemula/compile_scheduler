//
// Created by Leke Mula on 01.12.19.
//
#include "helpers.h"
#include <chrono>
#include <iostream>

typedef void (* ExecutionBlock)();

int measureBlockExecution(std::string title, std::function<void()> executionBlock){
    auto t1 = std::chrono::high_resolution_clock::now();
    executionBlock();
    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
//    std::cout << title << " duration = " << duration << std::endl;

    return duration;
}