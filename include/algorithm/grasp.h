//
// Created by Leke Mula on 25.11.19.
//

#ifndef COMPILE_SCHEDULER_GRASP_H
#define COMPILE_SCHEDULER_GRASP_H

#include <vector>
#include <source_file.h>
#include <solution.h>

class Grasp {
    struct Problem {
        vector<SourceFilePtr> sourceFiles;
        vector<ServerPtr> servers;
    };

private:
    Problem _problem;
    int _maxIterations;

    void _constructGreedyRandomizedSolution(Problem problem, Solution & solution);
    void _restrictCandidateList(vector<CompilationStep> & candidates, Solution & solution);
    CompilationStep _pickNextRandom(vector<CompilationStep> & restrictedCandidateList);
    int _incrementalCost(CompilationStep & candidate);
public:
    Grasp(Problem problem, int maxIterations);
    Solution perform();
};


#endif //COMPILE_SCHEDULER_GRASP_H
