//
// Created by leke on 9/7/19.
//
#ifndef COMPILE_SCHEDULER_SOURCEFILE_H
#define COMPILE_SCHEDULER_SOURCEFILE_H

#include <map>
#include <memory>
#include <ostream>
#include <string>
#include <unordered_map>

#include "compilation_target.h"

using namespace std;

class SourceFile : public std::enable_shared_from_this<SourceFile> {
  typedef shared_ptr<SourceFile> SourceFilePtr;

  struct TargetDistance {
    int distance;
    SourceFilePtr targetSourceFile;
  };

 private:
  string _id;
  int _compilationTime;
  int _replicationTime;
  unique_ptr<CompilationTarget> _compilationTarget;
  unordered_map<string, SourceFilePtr> _dependencies = {};
  unordered_map<string, SourceFilePtr> _dependants   = {};  // Files that depend on this file

 public:
  SourceFile(string id, int compilationTime, int replicationTime);
  SourceFile(string id, int compilationTime, int replicationTime, unique_ptr<CompilationTarget> &compilationTarget);

  string getId() const { return _id; }
  int getReplicationTime() const { return _replicationTime; }
  int getCompilationTime() const { return _compilationTime; };
  const CompilationTarget &getCompilationTarget() const;
  const SourceFile &setCompilationTarget(unique_ptr<CompilationTarget> compilationTarget);
  const SourceFile &addDependency(SourceFilePtr sourceFile);
  bool isTargetFile() { return _compilationTarget != NULL; }
  int getPoints(int compiledAt) const;
  vector<SourceFilePtr> getDependencies() const;
  int dependenciesCount() const;
  int dependantsCount() const;
  vector<TargetDistance> getTargetDependantsWithDistance(int distance = 0) const;

  string toString() const;

  bool operator==(SourceFile const &otherFile) const;
  bool operator!=(SourceFile const &otherFile) const;

  friend std::ostream &operator<<(std::ostream &os, SourceFile const &f);
};

typedef shared_ptr<SourceFile> SourceFilePtr;

#endif  // COMPILE_SCHEDULER_SOURCEFILE_H
