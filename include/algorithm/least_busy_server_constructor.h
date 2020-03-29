//
// Created by Leke Mula on 02.12.19.
//

#ifndef COMPILE_SCHEDULER_LEAST_BUSY_SERVER_CONSTRUCTOR_H
#define COMPILE_SCHEDULER_LEAST_BUSY_SERVER_CONSTRUCTOR_H

#include "greedy_constructor.h"

/*
 *  - Select least busy server
 *  - For each non compiled file
 *      - add as candidate if can be compiled for least busy server
 *  - cost = Dependencies
 * */
class LeastBusyServerConstructor : public GreedyConstructor {
protected:
    virtual void _buildCandidateList(Problem & problem, vector<CompilationStep> & candidates) override;
    virtual int _incrementalCost(CompilationStep & candidate) override;
public:
    LeastBusyServerConstructor();
};


#endif //COMPILE_SCHEDULER_LEAST_BUSY_SERVER_CONSTRUCTOR_H
