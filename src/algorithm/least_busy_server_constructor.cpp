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

#include "algorithm/least_busy_server_constructor.h"

void LeastBusyServerConstructor::_buildCandidateList(Problem & problem, vector<CompilationStep> & candidates) {
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

        candidates.push_back({ -1, leastBusyServer, sourceFile });
    }
}

int LeastBusyServerConstructor::_incrementalCost(CompilationStep & candidate) {
    int dependencies = candidate.sourceFile->getDependencies().size();
    int cost = dependencies;

    return cost;
}
