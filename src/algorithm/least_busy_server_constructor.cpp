//
// Created by Leke Mula on 02.12.19.
//

#include "algorithm/least_busy_server_constructor.h"

//
// Created by Leke Mula on 30.11.19.
//

#include <iostream>
#include <random>

#include "algorithm/least_busy_server_constructor.h"

void LeastBusyServerConstructor::_buildCandidateList(Problem & problem, vector<CompilationStep> & candidates) {
    ServerPtr leastBusyServer = *std::min_element(problem.servers.begin(), problem.servers.end(), [](ServerPtr & s1, ServerPtr & s2) -> bool {
        return s1->getCompilationTime() < s2->getCompilationTime();
    });

    for (auto & sourceFile : problem.sourceFiles) {
        if(_solution.hasCompiled(sourceFile)){
            continue;
        }

        int closestStartSecond = _solution.closestCompilationStart(sourceFile, leastBusyServer);

        if (closestStartSecond >= 0) {
            candidates.push_back({ closestStartSecond, leastBusyServer, sourceFile });
        }
    }
}

int LeastBusyServerConstructor::_incrementalCost(CompilationStep & candidate) {
    int dependencies = candidate.sourceFile->getDependencies().size();
    int compilationStartSecond = candidate.startAtSecond;
    int cost = (dependencies * 10000) + compilationStartSecond;

//    std::cout << "Cost=" << cost << " " << candidate.server->getId() << "<>" << candidate.sourceFile->getId()
//              << " - dependencies: " << dependencies << " startTime: " << compilationStartSecond << std::endl;

    return cost;
}

LeastBusyServerConstructor::LeastBusyServerConstructor() {}
