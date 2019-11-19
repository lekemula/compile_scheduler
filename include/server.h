//
// Created by leke on 9/18/19.
//

#ifndef COMPILE_SCHEDULER_SERVER_H
#define COMPILE_SCHEDULER_SERVER_H

#include <vector>
#include <memory>
#include "source_file.h"

class Server{
//    static vector CompilationSteps
    bool canCompile(SourceFile& sourceFile);
private:
    vector<shared_ptr<SourceFile>> _compiledFiles;

};

struct CompilationStep{
    Server server;
    SourceFile sourceFile;
};
#endif //COMPILE_SCHEDULER_SERVER_H
