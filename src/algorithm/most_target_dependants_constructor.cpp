//
// Created by Leke Mula on 05.04.20.
//

#include "algorithm/most_target_dependants_constructor.h"

int MostTargetDependantsConstructor::_incrementalCost(CompilationStep & candidate) {
    SourceFilePtr sourceFile = candidate.sourceFile;
    int deepTargetDependantsCount = sourceFile->getTargetDependantsWithDistance().size();

    return -deepTargetDependantsCount;
}
