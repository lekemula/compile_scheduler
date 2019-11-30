//
// Created by Leke Mula on 19.11.19.
//

#ifndef COMPILE_SCHEDULER_COMPILATION_STEP_H
#define COMPILE_SCHEDULER_COMPILATION_STEP_H

#include "server.h"
#include <string>

struct CompilationStep{
    int startAtSecond;
    ServerPtr server;
    SourceFilePtr sourceFile;

    int finishAtSecond();
    int replicationAtSecond();
    string toString() const;
};

typedef shared_ptr<CompilationStep> CompilationStepPtr;

std::ostream & operator<<(std::ostream & os, CompilationStep compilationStep);

#endif //COMPILE_SCHEDULER_COMPILATION_STEP_H
