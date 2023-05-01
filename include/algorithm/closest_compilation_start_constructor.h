//
// Created by Leke Mula on 02.12.19.
//

#ifndef COMPILE_SCHEDULER_CLOSEST_COMPILATION_START_CONSTRUCTOR_H
#define COMPILE_SCHEDULER_CLOSEST_COMPILATION_START_CONSTRUCTOR_H

#include "greedy_constructor.h"

/*
 *  - Select least busy server
 *  - For each non compiled file
 *      - calculate closest compilation start (check dependencies & replication)
 *      - add as candidate if can be compiled for least busy server
 *  - cost = (Dependencies * 10000) +  compilationStartSecond
 * */
class ClosestCompilationStartConstructor : public GreedyConstructor {
 protected:
  virtual void _buildCandidateList(Problem& problem, vector<CompilationStep>& candidates) override;
  virtual int _incrementalCost(CompilationStep& candidate) override;

 public:
  ClosestCompilationStartConstructor(shared_ptr<CostFunction> costFunction) : GreedyConstructor(costFunction){};
};

#endif  // COMPILE_SCHEDULER_CLOSEST_COMPILATION_START_CONSTRUCTOR_H
