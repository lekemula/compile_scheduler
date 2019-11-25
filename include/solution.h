//
// Created by Leke Mula on 21.11.19.
//

#ifndef COMPILE_SCHEDULER_SOLUTION_H
#define COMPILE_SCHEDULER_SOLUTION_H

#include "server.h"
#include "compilation_step.h"

class Solution {
private:
    vector<CompilationStep> _compilations;
public:
    Solution();

    bool compile(SourceFilePtr & sourceFile, ServerPtr & server);
    string toString();
};


#endif //COMPILE_SCHEDULER_SOLUTION_H
