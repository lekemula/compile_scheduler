//
// Created by leke on 9/7/19.
//
#ifndef COMPILE_SCHEDULER_SOURCEFILE_H
#define COMPILE_SCHEDULER_SOURCEFILE_H

#include <string>
#include <map>
#include <memory>
#include <ostream>
#include <unordered_map>
#include "compilation_target.h"

using namespace std;

class SourceFile {
    typedef shared_ptr<SourceFile> SourceFilePtr;
private:
    string _id;
    int _compilationTime;
    int _replicationTime;
    unique_ptr<CompilationTarget> _compilationTarget;
    unordered_map<string, SourceFilePtr> _dependencies = {};

public:
    SourceFile(string id, int compilationTime, int replicationTime);
    SourceFile(string id, int compilationTime, int replicationTime, unique_ptr<CompilationTarget>& compilationTarget);

    string                          getId() const { return _id; }
    int                             getReplicationTime() const { return _replicationTime; }
    int                             getCompilationTime() const { return _compilationTime; };
    const CompilationTarget&        getCompilationTarget() const;
    const SourceFile&               setCompilationTarget(unique_ptr<CompilationTarget>compilationTarget);
    const SourceFile&               addDependency(SourceFilePtr sourceFile);
    bool                            isTargetFile() { return _compilationTarget != NULL; }
    int                             getPoints(int compiledAt);
    vector<SourceFilePtr>           getDependencies();

    string toString() const;

    bool operator ==(SourceFile const &otherFile);
    bool operator !=(SourceFile const &otherFile);

    friend std::ostream &operator<<(std::ostream &os, SourceFile const &f);
};

typedef shared_ptr<SourceFile> SourceFilePtr;


#endif //COMPILE_SCHEDULER_SOURCEFILE_H
