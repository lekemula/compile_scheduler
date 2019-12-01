//
// Created by Leke Mula on 01.12.19.
//

#ifndef COMPILE_SCHEDULER_HELPERS_H
#define COMPILE_SCHEDULER_HELPERS_H

#include <string>

int measureBlockExecution(std::string title, std::function<void()> executionBlock);

#endif //COMPILE_SCHEDULER_HELPERS_H
