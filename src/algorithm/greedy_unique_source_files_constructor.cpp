//
// Created by Leke Mula on 23.05.20.
//

#include <helpers.h>
#include "algorithm/greedy_unique_source_files_constructor.h"

void GreedyUniqueSourceFilesConstructor::_buildCandidateList(Problem & problem, vector<CompilationStep> & candidates) {
    ServerPtr leastBusyServer;

    measureBlockExecution("_buildCandidateList__leastBusyServer", [&leastBusyServer, problem]() mutable {
        leastBusyServer = *std::min_element(problem.servers.begin(), problem.servers.end(), [](ServerPtr & s1, ServerPtr & s2) -> bool {
            return s1->getCompilationTime() < s2->getCompilationTime();
        });
    });

    int max = min(this->_notCompiledOrderedSourceFiles.size(), (unsigned long)100);

    for (int i = 0; i < max; ++i) {
        auto sourceFile = this->_notCompiledOrderedSourceFiles[i];
        bool hasCompiled = false;

        measureBlockExecution("_buildCandidateList__hasCompiled", [&hasCompiled, this, sourceFile]() mutable {
            hasCompiled = _solution.hasCompiled(sourceFile);
        });

        if(hasCompiled){
            continue;
        }

        candidates.push_back({ -1, leastBusyServer, sourceFile });
    };
}

int GreedyUniqueSourceFilesConstructor::_incrementalCost(CompilationStep & candidate) {
    return 0;
}

CompilationStep GreedyUniqueSourceFilesConstructor::_pickNextRandom(vector<CompilationStep> & restrictedCandidateList) {
    auto nextRandomCompilationStep = GreedyConstructor::_pickNextRandom(restrictedCandidateList);
    auto compiledSourceFile = nextRandomCompilationStep.sourceFile;

    std::vector<SourceFilePtr>::iterator compiledFilePosition = std::find(this->_notCompiledOrderedSourceFiles.begin(), this->_notCompiledOrderedSourceFiles.end(), compiledSourceFile);

    if(compiledFilePosition != this->_notCompiledOrderedSourceFiles.end()){
        this->_notCompiledOrderedSourceFiles.erase(compiledFilePosition);
    }

    return nextRandomCompilationStep;
}

unique_ptr<Solution> GreedyUniqueSourceFilesConstructor::construct(Problem & problem) {
    this->_notCompiledOrderedSourceFiles = problem.sourceFiles;

    std::sort (this->_notCompiledOrderedSourceFiles.begin(),  this->_notCompiledOrderedSourceFiles.end(), [] (SourceFilePtr file1, SourceFilePtr file2) -> bool {
        file1->getTargetDependantsWithDistance().size() > file2->getTargetDependantsWithDistance().size();
    });

    return GreedyConstructor::construct(problem);
}

GreedyUniqueSourceFilesConstructor::GreedyUniqueSourceFilesConstructor() {}
