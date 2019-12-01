//
// Created by Leke Mula on 21.11.19.
//

#ifndef COMPILE_SCHEDULER_SOLUTION_H
#define COMPILE_SCHEDULER_SOLUTION_H

#include <unordered_map>
#include "server.h"
#include "compilation_step.h"

class Solution {
private:
    unordered_map<string, vector<int>> _sourceFileCompilations;
    vector<CompilationStep> _compilations;

public:
    Solution();

    bool compile(CompilationStep & step);
    bool complete(vector<SourceFilePtr> sourceFiles);
    bool hasCompiled(SourceFilePtr & sourceFile);
    unique_ptr<CompilationStep> earliestCompilation(SourceFilePtr & sourceFile);
    int closestCompilationStart(SourceFilePtr & sourceFile, ServerPtr & server);
    int replicatedAt(SourceFilePtr & sourceFile);
    string toString() const;

    friend std::ostream &operator<<(std::ostream &os, Solution const &s);
};




#endif //COMPILE_SCHEDULER_SOLUTION_H
