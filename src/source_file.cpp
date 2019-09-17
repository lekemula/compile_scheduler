//
// Created by leke on 9/7/19.
//

#include "source_file.h"

SourceFile::SourceFile(string id, int compilationTime, int replicationTime) :
        _id(id),
        _compilationTime(compilationTime),
        _replicationTime(replicationTime) {}

SourceFile::SourceFile(string id, int compilationTime, int replicationTime, unique_ptr<CompilationTarget>& compilationTarget) :
        SourceFile::SourceFile(id, compilationTime, replicationTime) {
        _compilationTarget = move(compilationTarget);
}

string SourceFile::toString() const {
    string output = "<Source File ID: " + getId() +
                    ", Compilation Time: " + to_string(getCompilationTime()) +
                    ", Replication Time: " + to_string(getReplicationTime());

    if (_compilationTarget != NULL) {
        output += ", Target Deadline: " + to_string(_compilationTarget->deadline);
        output += ", Points:" + to_string(_compilationTarget->goalPoints);
    }

    if (_dependencies.size() > 0) {
        string fileIds = "";
        for (auto& dependencyPair : _dependencies) {
            shared_ptr<SourceFile> dependency = dependencyPair.second;
            fileIds += " " + dependency->getId();
        }

        output += ", Dependency IDs {" + fileIds + " }";
    }

    output += ">";
    return output;
}

bool SourceFile::operator==(SourceFile const &otherFile) {
    return getId() == otherFile.getId();
}

bool SourceFile::operator!=(SourceFile const &otherFile) {
    return getId() != otherFile.getId();
}

const CompilationTarget& SourceFile::getCompilationTarget() const {
    return *_compilationTarget;
}

const SourceFile &SourceFile::setCompilationTarget(unique_ptr<CompilationTarget> compilationTarget) {
    if (!_compilationTarget) {
        _compilationTarget = move(compilationTarget);
    }

    return *this;
}

const SourceFile &SourceFile::addDependency(shared_ptr<SourceFile> sourceFile) {
    _dependencies[sourceFile->getId()] = sourceFile;
    return *this;
}

std::ostream &operator<<(std::ostream &os, SourceFile const &f) {
    return os << f.toString();
}