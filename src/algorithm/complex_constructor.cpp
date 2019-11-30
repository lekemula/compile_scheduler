//
// Created by Leke Mula on 30.11.19.
//

#include <iostream>
#include <random>
#include "algorithm/complex_constructor.h"

int ComplexConstructor::_incrementalCost(CompilationStep & candidate) {
    int isCompiled = _solution.hasCompiled(candidate.sourceFile) ? 1 : 0;
    int dependencies = candidate.sourceFile->getDependencies().size();
    int compilationStartSecond = candidate.startAtSecond;
    int cost = (dependencies * 10000) + compilationStartSecond;

//    std::cout << "Cost=" << cost << " " << candidate.server->getId() << "<>" << candidate.sourceFile->getId()
//              << " - dependencies: " << dependencies << " startTime: " << compilationStartSecond << std::endl;

    return cost;
}

vector<CompilationStep> ComplexConstructor::_buildCandidateList(Problem & problem) {
    vector<CompilationStep> candidates;

    for (auto & server : problem.servers) {
        for (auto & sourceFile : problem.sourceFiles) {
            if(_solution.hasCompiled(sourceFile)){
                continue;
            }

            int closestStartSecond = _solution.closestCompilationStart(sourceFile, server);

            if (closestStartSecond >= 0) {
                candidates.push_back({ closestStartSecond, server, sourceFile });
            }
        }
    }

    return candidates;
}

ComplexConstructor::ComplexConstructor() {}
