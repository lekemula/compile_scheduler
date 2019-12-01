//
// Created by Leke Mula on 30.11.19.
//

#include <random>
#include <iostream>
#include "algorithm/greedy_constructor.h"
#include "helpers.h"

unique_ptr<Solution> GreedyConstructor::construct(Problem & problem) {
    int step = -1;

    bool solutionComplete = false;
    while (!solutionComplete) {
        step += 1;
        std::cout << "STEP " << step << std::endl;

        vector<CompilationStep> candidates;
        _buildCandidateList(problem, candidates); // TODO: Potential performance problem!
        _restrictCandidateList(candidates); // TODO: Potential performance problem!

        auto next = _pickNextRandom(candidates);
        _solution.compile(next);

//        int candidatesCount = candidates.size();
//        cout << "Candidates count:" << candidates.size() << endl;
//        int time = measureBlockExecution("solutionComplete", [this, solutionComplete, problem]() mutable {
//
//        });
//        cout << "Execution time per candidate = " << time / (double) candidatesCount << endl;
        solutionComplete = _solution.complete(problem.sourceFiles);
    }

    return std::make_unique<Solution>(_solution);
}

void GreedyConstructor::_restrictCandidateList(vector<CompilationStep> & candidates){
    unordered_map<long int, int> candidatesCosts;

    for(auto & candidate : candidates){
        auto candidateAddress = (long int)&candidate;
        candidatesCosts[candidateAddress] = this->_incrementalCost(candidate);
    }

    std::sort(candidates.begin(), candidates.end(), [this, candidatesCosts](auto & c1, auto & c2){
        auto c1Address = (long int)&c1;
        auto c2Address = (long int)&c2;

        return  candidatesCosts.find(c1Address)->second < candidatesCosts.find(c2Address)->second;
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