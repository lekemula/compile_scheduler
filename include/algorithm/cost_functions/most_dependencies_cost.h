//
// Created by Leke Mula on 23.05.20.
//

#ifndef COMPILE_SCHEDULER_MOST_DEPENDENCIES_COST_H
#define COMPILE_SCHEDULER_MOST_DEPENDENCIES_COST_H

#include "cost_function.h"

class MostDependenciesCost : public CostFunction {
  int operator()(SourceFilePtr& sourceFile) override {
    int dependencies = sourceFile->getDependencies().size();
    int cost         = dependencies;

    return cost;
  }
};

#endif  // COMPILE_SCHEDULER_MOST_DEPENDENCIES_COST_H
