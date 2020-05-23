//
// Created by Leke Mula on 23.05.20.
//

#ifndef COMPILE_SCHEDULER_COST_FUNCTION_H
#define COMPILE_SCHEDULER_COST_FUNCTION_H

#include <compilation_step.h>

class CostFunction {
public:
    virtual int operator () (SourceFilePtr & sourceFile) = 0;
};


#endif //COMPILE_SCHEDULER_COST_FUNCTION_H
