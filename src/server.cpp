#include "server.h"

#include <algorithm>
#include <numeric>

using namespace std;

Server::Server(int id, vector<SourceFilePtr> compiledFiles)
    : _id(id), _compilationTime(0), _compiledFiles(compiledFiles) {}

Server::Server(int id) : _id(id), _compilationTime(0) {}

void Server::compile(SourceFilePtr const& sourceFile) {
  this->_compiledFiles.push_back(sourceFile);
  this->_compilationTime += sourceFile->getCompilationTime();
  this->_sourceFileCompilations[sourceFile->getId()].push_back(_compiledFiles.size() - 1);
}

bool Server::hasCompiled(SourceFilePtr const& sourceFile) {
  return _sourceFileCompilations.find(sourceFile->getId()) != _sourceFileCompilations.end();
}

bool Server::canCompile(SourceFilePtr& sourceFile) {
  for (auto& fileDependency : sourceFile->getDependencies()) {
    if (!hasCompiled(fileDependency)) {
      return false;
    }
  }

  return true;
}

int Server::getCompilationTime() { return _compilationTime; }

int Server::getId() { return _id; }
