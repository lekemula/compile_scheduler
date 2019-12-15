//
// Created by Leke Mula on 21.11.19.
//

#include <iostream>
#include <sstream>
#include "solution.h"

Solution::Solution(){}

bool Solution::compile(CompilationStep & step) {
    auto server = step.server;
    auto sourceFile = step.sourceFile;

    if(step.startAtSecond == -1){
        step.startAtSecond = closestCompilationStart(sourceFile, server);
    }

    server->compile(sourceFile);
    _compilations.push_back(step);
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

        int replicationAtSecond = replicatedAt(dependency);
        int waitReplicationTime = replicationAtSecond - closestCompilationStartAt;

        if(waitReplicationTime > 0){
            closestCompilationStartAt += waitReplicationTime;
        }
    }

    return closestCompilationStartAt;
}

unique_ptr<CompilationStep> Solution::earliestCompilation(SourceFilePtr & sourceFile) {
    auto findIterator = _sourceFileCompilations.find(sourceFile->getId());

    if(findIterator != _sourceFileCompilations.end()){
        vector<int> compilationIndexes = findIterator->second;
        return make_unique<CompilationStep>(_compilations[compilationIndexes[0]]);
    }

    return NULL;
}

int Solution::replicatedAt(SourceFilePtr & sourceFile) {
    auto fileEarliestCompilation = earliestCompilation(sourceFile);

    if(fileEarliestCompilation){
        return fileEarliestCompilation->replicationAtSecond();
    }

    return -1;
}

int Solution::score() {
    int score = 0;

    for(auto & compilationStep : _compilations){
        score += compilationStep.score();
    }

    return score;
}
