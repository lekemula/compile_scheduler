//
// Created by Leke Mula on 02.12.19.
//

#include "algorithm/closest_compilation_start_constructor.h"

//
// Created by Leke Mula on 30.11.19.
//

#include <iostream>
#include <random>
#include <helpers.h>

void ClosestCompilationStartConstructor::_buildCandidateList(Problem & problem, vector<CompilationStep> & candidates) {
    ServerPtr leastBusyServer;

    measureBlockExecution("_buildCandidateList__leastBusyServer", [&leastBusyServer, problem]() mutable {
        leastBusyServer = *std::min_element(problem.servers.begin(), problem.servers.end(), [](ServerPtr & s1, ServerPtr & s2) -> bool {
            return s1->getCompilationTime() < s2->getCompilationTime();
        });
    });

    for (auto & sourceFile : problem.sourceFiles) {
        bool hasCompiled = false;

        measureBlockExecution("_buildCandidateList__hasCompiled", [&hasCompiled, this, sourceFile]() mutable {
            hasCompiled = _solution.hasCompiled(sourceFile);
        });

        if(hasCompiled){
            continue;
        }

        int closestStartSecond = 0;

        measureBlockExecution("_buildCandidateList__closestStartSecond", [&closestStartSecond, this, sourceFile, leastBusyServer]() mutable {
            closestStartSecond = _solution.closestCompilationStart(sourceFile, leastBusyServer);
        });

        if (closestStartSecond >= 0) {
            candidates.push_back({ closestStartSecond, leastBusyServer, sourceFile });
        }
    }
}

int ClosestCompilationStartConstructor::_incrementalCost(CompilationStep & candidate) {
    int dependencies = candidate.sourceFile->getDependencies().size();
    int compilationStartSecond = candidate.startAtSecond;
    int cost = (dependencies * 10000) + compilationStartSecond;

    return cost;
}

ClosestCompilationStartConstructor::ClosestCompilationStartConstructor() {}
