//
// Created by Leke Mula on 30.11.19.
//

#ifndef COMPILE_SCHEDULER_COMPLEX_CONSTRUCTOR_H
#define COMPILE_SCHEDULER_COMPLEX_CONSTRUCTOR_H


#include "greedy_constructor.h"

/*
 *  - For each server sorted by compilation time
 *      - For non compiled files in server
 *          - calculate closest compilation start (check dependencies and replication)
 *          - add candidate if can be compiled
 *
 *  - cost = (Dependencies * 10000) +  compilationStartSecond
 * */
class ComplexConstructor : public GreedyConstructor {
protected:
    virtual void _buildCandidateList(Problem & problem, vector<CompilationStep> & candidates) override;
    virtual int _incrementalCost(CompilationStep & candidate) override;
public:
    ComplexConstructor();
};


#endif //COMPILE_SCHEDULER_COMPLEX_CONSTRUCTOR_H
