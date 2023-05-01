//
// Created by Leke Mula on 21.11.19.
//

#ifndef COMPILE_SCHEDULER_SOLUTION_H
#define COMPILE_SCHEDULER_SOLUTION_H

#include <unordered_map>

#include "compilation_step.h"
#include "server.h"

class Solution {
 private:
  unordered_map<string, vector<int>> _sourceFileCompilations;
  vector<CompilationStep> _compilations;

 public:
  Solution();

  bool compile(CompilationStep &step);
  bool complete(vector<SourceFilePtr> sourceFiles) const;
  bool hasCompiled(SourceFilePtr &sourceFile) const;
  unique_ptr<CompilationStep> earliestCompilation(SourceFilePtr &sourceFile) const;
  int closestCompilationStart(SourceFilePtr &sourceFile, ServerPtr &server) const;
  int replicatedAt(SourceFilePtr &sourceFile) const;
  int score() const;
  string toString() const;

  friend std::ostream &operator<<(std::ostream &os, Solution const &s);
};

#endif  // COMPILE_SCHEDULER_SOLUTION_H
