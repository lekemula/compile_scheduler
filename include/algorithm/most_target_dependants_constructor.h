//
// Created by Leke Mula on 05.04.20.
//

#ifndef COMPILE_SCHEDULER_MOST_TARGET_DEPENDANTS_CONSTRUCTOR_H
#define COMPILE_SCHEDULER_MOST_TARGET_DEPENDANTS_CONSTRUCTOR_H

#include "least_busy_server_constructor.h"

class MostTargetDependantsConstructor : public LeastBusyServerConstructor {
protected:
    virtual int _incrementalCost(CompilationStep & candidate) override;
public:
    MostTargetDependantsConstructor(){};
};


#endif //COMPILE_SCHEDULER_MOST_TARGET_DEPENDANTS_CONSTRUCTOR_H
