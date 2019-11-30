//
// Created by Leke Mula on 30.11.19.
//

#ifndef COMPILE_SCHEDULER_PROBLEM_H
#define COMPILE_SCHEDULER_PROBLEM_H

#include <server.h>

struct Problem {
    vector<SourceFilePtr> sourceFiles;
    vector<ServerPtr> servers;
};

#endif //COMPILE_SCHEDULER_PROBLEM_H
