//
// Created by Leke Mula on 21.11.19.
//

#include <iostream>
#include <sstream>
#include "solution.h"

Solution::Solution(){}

bool Solution::compile(SourceFilePtr & sourceFile, ServerPtr & server) {
    if(!server->canCompile(sourceFile)){
        return false;
    }

    int compilationStartSecond = server->getCompilationTime();
    server->compile(sourceFile);
    _compilations.push_back({ compilationStartSecond, server, sourceFile });

    return true;
}

string Solution::toString() {
    stringstream result;

    for(auto & compilation : _compilations){
        result << compilation.toString() << "\n";
    }

    return result.str();
}
