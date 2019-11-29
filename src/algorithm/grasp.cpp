//
// Created by Leke Mula on 25.11.19.
//

#include "algorithm/grasp.h"
#include <algorithm>
#include <random>
#include <iostream>

Grasp::Grasp(Problem problem, int maxIterations)
    : _problem(problem), _maxIterations(maxIterations) {
}

Solution Grasp::perform() {
    unique_ptr<Solution> solution(new Solution());

    _constructGreedyRandomizedSolution(_problem, *solution);

    return *solution;
}

void Grasp::_constructGreedyRandomizedSolution(Grasp::Problem problem, Solution & solution) {
    int step = -1;
    while (!solution.complete(problem.sourceFiles)) {
        step += 1;
        std::cout << "STEP " << step << std::endl;

        vector<CompilationStep> candidates;

        for (auto & server : problem.servers) {
            for (auto & sourceFile : problem.sourceFiles) {
                if(solution.hasCompiled(sourceFile)){
                    continue;
                }

                int closestStartSecond = solution.closestCompilationStart(sourceFile, server);

                if (closestStartSecond >= 0) {
                    candidates.push_back({ closestStartSecond, server, sourceFile });
                }
            }
        }

        _restrictCandidateList(candidates, solution);
        auto next = _pickNextRandom(candidates);

        solution.compile(next.sourceFile, next.server);
    }
}

void Grasp::_restrictCandidateList(vector<CompilationStep> & candidates, Solution & solution){
    std::sort(candidates.begin(), candidates.end(), [this, solution](auto & c1, auto & c2){
        return this->_incrementalCost(c1) < this->_incrementalCost(c2);
    });

    int cardinality = candidates.size() * 10/100;
    cardinality = cardinality == 0 ? 1 : cardinality;

    candidates = vector<CompilationStep>(candidates.begin(), candidates.begin() + cardinality);
}

int Grasp::_incrementalCost(CompilationStep & candidate) {
    int dependencies = candidate.sourceFile->getDependencies().size();
    int compilationStartSecond = candidate.startAtSecond;

    std::cout << "Cost s" << candidate.server->getId() << "<>" << candidate.sourceFile->getId()
        << " - dependencies: " << dependencies << " startTime: " << compilationStartSecond << std::endl;

    return (dependencies * 10000) + compilationStartSecond;
}

CompilationStep Grasp::_pickNextRandom(vector<CompilationStep> & restrictedCandidateList) {
    auto start = restrictedCandidateList.begin();
    auto end = restrictedCandidateList.end();
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dis(0, std::distance(start, end - 1));
    std::advance(start, dis(gen));

    return *start;
}
