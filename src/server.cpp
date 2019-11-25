#include "server.h"
#include <algorithm>
#include <numeric>

using namespace std;

Server::Server(int id, vector<SourceFilePtr> compiledFiles) : _id(id), _compiledFiles(compiledFiles) {}

Server::Server(int id) : _id(id) { }

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

int Server::getCompilationTime(){
    return accumulate(_compiledFiles.begin(), _compiledFiles.end(), 0, [](int sum, SourceFilePtr sourceFile){
        return sum + sourceFile->getCompilationTime();
    });
}

int Server::getId() {
    return _id;
}
