//
// Created by Leke Mula on 30.11.19.
//

#ifndef COMPILE_SCHEDULER_COMPLEX_CONSTRUCTOR_H
#define COMPILE_SCHEDULER_COMPLEX_CONSTRUCTOR_H


#include "greedy_constructor.h"

class ComplexConstructor : public GreedyConstructor {
private:
    Solution _solution;
    void _restrictCandidateList(vector<CompilationStep> & candidates);
    CompilationStep _pickNextRandom(vector<CompilationStep> & restrictedCandidateList);
    int _incrementalCost(CompilationStep & candidate);
public:
    ComplexConstructor();
    unique_ptr<Solution> construct(Problem & problem) override;
};


#endif //COMPILE_SCHEDULER_COMPLEX_CONSTRUCTOR_H
