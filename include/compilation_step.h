//
// Created by Leke Mula on 19.11.19.
//

#ifndef COMPILE_SCHEDULER_COMPILATION_STEP_H
#define COMPILE_SCHEDULER_COMPILATION_STEP_H

#include <string>

#include "server.h"

struct CompilationStep {
  int startAtSecond;
  ServerPtr server;
  SourceFilePtr sourceFile;

  int score() const;
  int finishAtSecond() const;
  int replicationAtSecond() const;
  string toString() const;
};

typedef shared_ptr<CompilationStep> CompilationStepPtr;

std::ostream& operator<<(std::ostream& os, CompilationStep compilationStep);

#endif  // COMPILE_SCHEDULER_COMPILATION_STEP_H
