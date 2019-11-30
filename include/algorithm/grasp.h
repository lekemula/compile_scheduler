//
// Created by Leke Mula on 25.11.19.
//

#ifndef COMPILE_SCHEDULER_GRASP_H
#define COMPILE_SCHEDULER_GRASP_H

#include <vector>
#include <source_file.h>
#include "solution.h"
#include "problem.h"
#include "greedy_constructor.h"

class Grasp {

private:
    Problem _problem;
    int _maxIterations;
    GreedyConstructor & _greedyConstructor;

    unique_ptr<Solution> _constructGreedyRandomizedSolution();
public:
    Grasp(Problem problem, GreedyConstructor & greedyConstructor, int maxIterations);
    unique_ptr<Solution> perform();
};


#endif //COMPILE_SCHEDULER_GRASP_H
