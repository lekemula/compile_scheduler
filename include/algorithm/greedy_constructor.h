//
// Created by Leke Mula on 30.11.19.
//

#ifndef COMPILE_SCHEDULER_GREEDY_CONSTRUCTOR_H
#define COMPILE_SCHEDULER_GREEDY_CONSTRUCTOR_H


#include "solution.h"
#include "problem.h"

class GreedyConstructor {
public:
    virtual unique_ptr<Solution> construct(Problem & problem) = 0;
};


#endif //COMPILE_SCHEDULER_GREEDY_CONSTRUCTOR_H
