//
// Created by leke on 9/18/19.
//

#ifndef COMPILE_SCHEDULER_SERVER_H
#define COMPILE_SCHEDULER_SERVER_H

#include <vector>
#include <memory>
#include "source_file.h"

class Server{
private:
    vector<SourceFilePtr> _compiledFiles;

public:
    Server();
    Server(vector<SourceFilePtr> compiledFiles);
    bool hasCompiled(SourceFilePtr const & sourceFile);
    bool canCompile(SourceFilePtr & sourceFile);
    void compile(SourceFilePtr const & sourceFile);
};
#endif //COMPILE_SCHEDULER_SERVER_H
