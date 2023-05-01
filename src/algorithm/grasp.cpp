//
// Created by Leke Mula on 25.11.19.
//

#include "algorithm/grasp.h"

#include <algorithm>
#include <iostream>
#include <random>

Grasp::Grasp(Problem problem, GreedyConstructor& greedyConstructor, int maxIterations)
    : _problem(problem), _greedyConstructor(greedyConstructor), _maxIterations(maxIterations) {}

unique_ptr<Solution> Grasp::perform() { return _constructGreedyRandomizedSolution(); }

unique_ptr<Solution> Grasp::_constructGreedyRandomizedSolution() { return _greedyConstructor.construct(_problem); }
