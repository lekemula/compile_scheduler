//
// Created by Leke Mula on 23.05.20.
//

#ifndef COMPILE_SCHEDULER_LEAST_TARGET_DEPENDANTS_COST_H
#define COMPILE_SCHEDULER_LEAST_TARGET_DEPENDANTS_COST_H


#include "cost_function.h"

class LeastTargetDependantsCost : public CostFunction {
    int operator () (SourceFilePtr & sourceFile) override {
        int deepTargetDependantsCount = sourceFile->getTargetDependantsWithDistance().size();

        return -deepTargetDependantsCount;
    }
};

#endif //COMPILE_SCHEDULER_LEAST_TARGET_DEPENDANTS_COST_H
