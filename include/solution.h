//
// Created by Leke Mula on 21.11.19.
//

#ifndef COMPILE_SCHEDULER_SOLUTION_H
#define COMPILE_SCHEDULER_SOLUTION_H

#include "server.h"
#include "compilation_step.h"

class Solution {
private:
    map<string, vector<int>> _sourceFileCompilations;
    vector<CompilationStep> _compilations;

public:
    Solution();

    bool compile(CompilationStep & step);
    bool complete(vector<SourceFilePtr> sourceFiles);
    bool hasCompiled(SourceFilePtr & sourceFile);
    int closestCompilationStart(SourceFilePtr & sourceFile, ServerPtr & server);
    string toString() const;

    friend std::ostream &operator<<(std::ostream &os, Solution const &s);
};




#endif //COMPILE_SCHEDULER_SOLUTION_H
