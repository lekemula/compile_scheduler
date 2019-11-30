//
// Created by Leke Mula on 30.11.19.
//

#ifndef COMPILE_SCHEDULER_COMPLEX_CONSTRUCTOR_H
#define COMPILE_SCHEDULER_COMPLEX_CONSTRUCTOR_H


#include "greedy_constructor.h"

class ComplexConstructor : public GreedyConstructor {
protected:
    virtual vector<CompilationStep> _buildCandidateList(Problem & problem) override;
    virtual int _incrementalCost(CompilationStep & candidate) override;
public:
    ComplexConstructor();
};


#endif //COMPILE_SCHEDULER_COMPLEX_CONSTRUCTOR_H
