//
// Created by Leke Mula on 30.11.19.
//

#ifndef COMPILE_SCHEDULER_GREEDY_CONSTRUCTOR_H
#define COMPILE_SCHEDULER_GREEDY_CONSTRUCTOR_H


#include "solution.h"
#include "problem.h"

class GreedyConstructor {
protected:
    Solution _solution;

    virtual vector<CompilationStep> _buildCandidateList(Problem & problem) = 0;
    virtual void _restrictCandidateList(vector<CompilationStep> & candidates);
    CompilationStep _pickNextRandom(vector<CompilationStep> & restrictedCandidateList);
    virtual int _incrementalCost(CompilationStep & candidate) = 0;
public:
    unique_ptr<Solution> construct(Problem & problem);
};

#endif //COMPILE_SCHEDULER_GREEDY_CONSTRUCTOR_H
