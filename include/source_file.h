//
// Created by leke on 9/7/19.
//
#ifndef COMPILE_SCHEDULER_SOURCEFILE_H
#define COMPILE_SCHEDULER_SOURCEFILE_H

#include <string>
#include <map>
#include <memory>
#include "compilation_target.h"

using namespace std;

class SourceFile {
private:
    string _id;
    int _compilationTime;
    int _replicationTime;
    unique_ptr<CompilationTarget> _compilationTarget;
    map<string, shared_ptr<SourceFile>> _dependencies = {};

public:
    SourceFile(string id, int compilationTime, int replicationTime);
    SourceFile(string id, int compilationTime, int replicationTime, unique_ptr<CompilationTarget>& compilationTarget);

    string                   getId() const { return _id; }
    int                      getReplicationTime() const { return _replicationTime; }
    int                      getCompilationTime() const { return _compilationTime; };
    const CompilationTarget& getCompilationTarget() const;
    const SourceFile&        setCompilationTarget(unique_ptr<CompilationTarget>compilationTarget);
    const SourceFile&        addDependency(shared_ptr<SourceFile> sourceFile);
    bool                     isTargetFile() { return _compilationTarget != NULL; }

    string toString() const;

    bool operator ==(SourceFile const &otherFile);
    bool operator !=(SourceFile const &otherFile);
};

std::ostream &operator<<(std::ostream &os, SourceFile const &f);

#endif //COMPILE_SCHEDULER_SOURCEFILE_H
