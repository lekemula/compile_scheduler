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
    int _id;
    vector<SourceFilePtr> _compiledFiles;

public:
    Server(int id);
    Server(int id, vector<SourceFilePtr> compiledFiles);
    bool hasCompiled(SourceFilePtr const & sourceFile);
    bool canCompile(SourceFilePtr & sourceFile);
    void compile(SourceFilePtr const & sourceFile);
    int getCompilationTime();
    int getId();
};

typedef shared_ptr<Server> ServerPtr;
#endif //COMPILE_SCHEDULER_SERVER_H
