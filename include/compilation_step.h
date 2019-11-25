//
// Created by Leke Mula on 19.11.19.
//

#ifndef COMPILE_SCHEDULER_COMPILATION_STEP_H
#define COMPILE_SCHEDULER_COMPILATION_STEP_H

#include "server.h"
#include <string>

struct CompilationStep{
    int compilationStartSecond;
    ServerPtr server;
    SourceFilePtr sourceFile;

    string toString();
};

std::ostream & operator<<(std::ostream & os, CompilationStep compilationStep);

#endif //COMPILE_SCHEDULER_COMPILATION_STEP_H
