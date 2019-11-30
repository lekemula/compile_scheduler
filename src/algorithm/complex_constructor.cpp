//
// Created by Leke Mula on 30.11.19.
//

#include <iostream>
#include <random>
#include "algorithm/complex_constructor.h"

unique_ptr<Solution> ComplexConstructor::construct(Problem & problem) {
    int step = -1;
    while (!_solution.complete(problem.sourceFiles)) {
        step += 1;
        std::cout << "STEP " << step << std::endl;

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

        _restrictCandidateList(candidates);
        auto next = _pickNextRandom(candidates);

        _solution.compile(next);
    }

    return std::make_unique<Solution>(_solution);
}

void ComplexConstructor::_restrictCandidateList(vector<CompilationStep> & candidates){
    std::sort(candidates.begin(), candidates.end(), [this](auto & c1, auto & c2){
        return this->_incrementalCost(c1) < this->_incrementalCost(c2);
    });

    int cardinality = candidates.size() * 10/100;
    cardinality = cardinality == 0 ? 1 : cardinality;

    candidates = vector<CompilationStep>(candidates.begin(), candidates.begin() + cardinality);
}

int ComplexConstructor::_incrementalCost(CompilationStep & candidate) {
    int dependencies = candidate.sourceFile->getDependencies().size();
    int compilationStartSecond = candidate.startAtSecond;

    std::cout << "Cost s" << candidate.server->getId() << "<>" << candidate.sourceFile->getId()
              << " - dependencies: " << dependencies << " startTime: " << compilationStartSecond << std::endl;

    return (dependencies * 10000) + compilationStartSecond;
}

CompilationStep ComplexConstructor::_pickNextRandom(vector<CompilationStep> & restrictedCandidateList) {
    auto start = restrictedCandidateList.begin();
    auto end = restrictedCandidateList.end();
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dis(0, std::distance(start, end - 1));
    std::advance(start, dis(gen));

    return *start;
}

ComplexConstructor::ComplexConstructor() {}
