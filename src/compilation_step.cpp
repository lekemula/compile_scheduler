//
// Created by Leke Mula on 19.11.19.
//
#include <iostream>
#include <sstream>
#include "compilation_step.h"

// <Server: s1, SourceFile: c1, startedAt: 10seconds, finishedAt: 20seconds, replicatedAt: 30seconds>
std::ostream & operator<<(std::ostream & os, CompilationStep compilationStep){
    std::cout << compilationStep.toString();

    return os;
}

string CompilationStep::toString() {
    int finishedAt = compilationStartSecond + sourceFile->getCompilationTime();
    int replicatedAt = finishedAt + sourceFile->getReplicationTime();
    stringstream result;

    result << "<";
    result << "Server: " << server->getId() << ", ";
    result << "SourceFile: " << sourceFile->getId() << ", ";
    result << "startedAt: " << compilationStartSecond << "seconds" << ", ";
    result << "finishedAt: " << finishedAt << ", ";
    result << "replicatedAt: " << replicatedAt;
    result << ">";

    return result.str();
}
