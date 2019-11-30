//
// Created by Leke Mula on 30.11.19.
//

#include <random>
#include <iostream>
#include "algorithm/greedy_constructor.h"

unique_ptr<Solution> GreedyConstructor::construct(Problem & problem) {
    int step = -1;
    while (!_solution.complete(problem.sourceFiles)) {
        step += 1;
        std::cout << "STEP " << step << std::endl;

        vector<CompilationStep> candidates = _buildCandidateList(problem);
        _restrictCandidateList(candidates);
        auto next = _pickNextRandom(candidates);
        _solution.compile(next);
    }

    return std::make_unique<Solution>(_solution);
}

void GreedyConstructor::_restrictCandidateList(vector<CompilationStep> & candidates){
    std::sort(candidates.begin(), candidates.end(), [this](auto & c1, auto & c2){
        return this->_incrementalCost(c1) < this->_incrementalCost(c2);
    });

    int cardinality = candidates.size() * 10/100;
    cardinality = cardinality == 0 ? 1 : cardinality;

    candidates = vector<CompilationStep>(candidates.begin(), candidates.begin() + cardinality);
}

CompilationStep GreedyConstructor::_pickNextRandom(vector<CompilationStep> & restrictedCandidateList) {
    auto start = restrictedCandidateList.begin();
    auto end = restrictedCandidateList.end();
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dis(0, std::distance(start, end - 1));
    std::advance(start, dis(gen));

    return *start;
}