//
// Created by Leke Mula on 19.11.19.
//
#include "compilation_step.h"

#include <iostream>
#include <sstream>

// <Server: s1, SourceFile: c1, startedAt: 10seconds, finishedAt: 20seconds, replicatedAt: 30seconds>
std::ostream& operator<<(std::ostream& os, CompilationStep compilationStep) {
  std::cout << compilationStep.toString();

  return os;
}

int CompilationStep::finishAtSecond() { return sourceFile->getCompilationTime() + startAtSecond; }

int CompilationStep::replicationAtSecond() { return finishAtSecond() + sourceFile->getReplicationTime(); }

string CompilationStep::toString() const {
  int finishedAt   = startAtSecond + sourceFile->getCompilationTime();
  int replicatedAt = finishedAt + sourceFile->getReplicationTime();
  stringstream result;

  result << "<";
  result << "Server: " << server->getId() << ", ";
  result << "SourceFile: " << sourceFile->getId() << ", ";
  result << "startedAt: " << startAtSecond << "seconds"
         << ", ";
  result << "finishedAt: " << finishedAt << ", ";
  result << "replicatedAt: " << replicatedAt;
  result << ">";

  return result.str();
}

int CompilationStep::score() { return sourceFile->getPoints(finishAtSecond()); }
