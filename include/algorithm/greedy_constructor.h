//
// Created by Leke Mula on 30.11.19.
//

#ifndef COMPILE_SCHEDULER_GREEDY_CONSTRUCTOR_H
#define COMPILE_SCHEDULER_GREEDY_CONSTRUCTOR_H

#include "cost_functions/cost_function.h"
#include "problem.h"
#include "solution.h"

class GreedyConstructor {
 protected:
  Solution _solution;
  shared_ptr<CostFunction> _costFunction;

  virtual void _buildCandidateList(Problem& problem, vector<CompilationStep>& candidates) = 0;
  virtual void _restrictCandidateList(vector<CompilationStep>& candidates);
  virtual CompilationStep _pickNextRandom(vector<CompilationStep>& restrictedCandidateList);
  virtual int _incrementalCost(CompilationStep& candidate);

 public:
  virtual unique_ptr<Solution> construct(Problem& problem);
  GreedyConstructor(shared_ptr<CostFunction> costFunction);
};

#endif  // COMPILE_SCHEDULER_GREEDY_CONSTRUCTOR_H
