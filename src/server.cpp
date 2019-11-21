#include "server.h"
#include <algorithm>

using namespace std;

Server::Server(vector<SourceFilePtr> compiledFiles) : _compiledFiles(compiledFiles) { }

Server::Server() { }

void Server::compile(SourceFilePtr const & sourceFile) {
    this->_compiledFiles.push_back(sourceFile);
}


bool Server::hasCompiled(SourceFilePtr const & sourceFile) {
    return find(_compiledFiles.begin(), _compiledFiles.end(), sourceFile) != _compiledFiles.end();
}

bool Server::canCompile(SourceFilePtr & sourceFile) {
    for (auto & fileDependency : sourceFile->getDependencies()) {
        if (!hasCompiled(fileDependency)){
            return false;
        }
    }

    return true;
}
