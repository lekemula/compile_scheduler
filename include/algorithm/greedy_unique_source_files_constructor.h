//
// Created by Leke Mula on 23.05.20.
//

#ifndef COMPILE_SCHEDULER_GREEDY_UNIQUE_SOURCE_FILES_CONSTRUCTOR_H
#define COMPILE_SCHEDULER_GREEDY_UNIQUE_SOURCE_FILES_CONSTRUCTOR_H

#include "greedy_constructor.h"

class GreedyUniqueSourceFilesConstructor : public GreedyConstructor {
 private:
  vector<SourceFilePtr> _notCompiledOrderedSourceFiles;

 protected:
  virtual void _buildCandidateList(Problem& problem, vector<CompilationStep>& candidates);
  virtual CompilationStep _pickNextRandom(vector<CompilationStep>& restrictedCandidateList);
  virtual int _incrementalCost(CompilationStep& candidate);

 public:
  virtual unique_ptr<Solution> construct(Problem& problem);
  GreedyUniqueSourceFilesConstructor(shared_ptr<CostFunction> costFunction) : GreedyConstructor(costFunction){};
};

#endif  // COMPILE_SCHEDULER_GREEDY_UNIQUE_SOURCE_FILES_CONSTRUCTOR_H
