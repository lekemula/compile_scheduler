//
// Created by Leke Mula on 21.11.19.
//

#include <iostream>
#include <sstream>
#include "solution.h"

Solution::Solution(){}

bool Solution::compile(SourceFilePtr & sourceFile, ServerPtr & server) {
    int compilationStartSecond = closestCompilationStart(sourceFile, server);
    server->compile(sourceFile);

    _compilations.push_back({ compilationStartSecond, server, sourceFile });
    _sourceFileCompilations[sourceFile->getId()].push_back(_compilations.size() - 1);

    return true;
}

string Solution::toString() const {
    stringstream result;

    for(auto & compilation : _compilations){
        result << compilation.toString() << "\n";
    }

    return result.str();
}

bool Solution::hasCompiled(SourceFilePtr & sourceFile) {
    auto it = _sourceFileCompilations.find(sourceFile->getId());

    if(it == _sourceFileCompilations.end()){
        return false;
    }

    return true;
}

bool Solution::complete(vector<SourceFilePtr> sourceFiles) {
    for (auto & sourceFile : sourceFiles) {
        if(!hasCompiled(sourceFile)){
            return false;
        }
    }

    return true;
}

std::ostream & operator<<(std::ostream & os, Solution const & s) {
    return os << s.toString();
}

int Solution::closestCompilationStart(SourceFilePtr & sourceFile, ServerPtr & onServer) {
    int closestCompilationStartAt = onServer->getCompilationTime();

    for(auto & dependency : sourceFile->getDependencies()){
        if(!hasCompiled(dependency)) return -1;
        if(onServer->hasCompiled(dependency)) continue;

        vector<CompilationStep> compilationOnOtherServers;

        for(int compilationStepIndex : _sourceFileCompilations[dependency->getId()]){
            compilationOnOtherServers.push_back(_compilations[compilationStepIndex]);
        }

        CompilationStep earliestCompilation = *std::min_element(
            compilationOnOtherServers.begin(),
            compilationOnOtherServers.end(),
            [](auto & compStep1, auto & compStep2) -> int {
                return compStep1.startAtSecond < compStep2.startAtSecond;
            });

        int replicationAtSecond = earliestCompilation.replicationAtSecond();
        int waitReplicationTime = replicationAtSecond - closestCompilationStartAt;

        if(waitReplicationTime > 0){
            closestCompilationStartAt += waitReplicationTime;
        }
    }

    return closestCompilationStartAt;
}
