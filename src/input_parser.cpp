//
// Created by leke on 9/7/19.
//

#include "input_parser.h"

#include <sstream>

InputParser::InputParser(string inputSourcePath) : _inputSourcePath(inputSourcePath){};

vector<SourceFilePtr> InputParser::parse(InputMetadata &outInputMetadata) {
  _open();

  if (_file.is_open()) {
    _parseInputMetadata();
    _parseSourceFiles();
    _parseFileTargets();
  }

  _close();

  outInputMetadata = _metadata;
  return _parsedSourceFiles;
}

void InputParser::_open() { _file.open(_inputSourcePath); }

void InputParser::_close() { _file.close(); }

void InputParser::_parseInputMetadata() {
  int filesCount, targetFilesCount, serversCount = 0;
  string inputMetas;
  getline(_file, inputMetas);
  stringstream inputMetasStream(inputMetas);
  inputMetasStream >> filesCount >> targetFilesCount >> serversCount;
  _metadata = InputMetadata{filesCount, targetFilesCount, serversCount};
}

void InputParser::_parseSourceFiles() {
  for (int i = 0; i < _metadata.filesCount; ++i) {
    string id;
    int compilationTime;
    int replicationTime;

    string fileInfos;
    getline(_file, fileInfos);
    stringstream fileInfosStream(fileInfos);
    fileInfosStream >> id >> compilationTime >> replicationTime;

    SourceFilePtr sourceFile(new SourceFile(id, compilationTime, replicationTime));
    _addParsedSourceFile(sourceFile);
    _parseFileDependencies(sourceFile);
  }
}

void InputParser::_parseFileDependencies(SourceFilePtr &sourceFile) {
  string fileDependencies;
  getline(_file, fileDependencies);
  stringstream fileDependenciesStream(fileDependencies);
  int dependenciesCount;
  fileDependenciesStream >> dependenciesCount;

  for (int i = 0; i < dependenciesCount; ++i) {
    string dependencyId;
    fileDependenciesStream >> dependencyId;
    sourceFile->addDependency(_findSourceFile(dependencyId));
  }
}

void InputParser::_parseFileTargets() {
  for (int i = 0; i < _metadata.targetsCount; ++i) {
    string targetInfos;
    string sourceFileId;
    int deadline, goalPoints;

    getline(_file, targetInfos);
    stringstream targetInfosStream(targetInfos);
    targetInfosStream >> sourceFileId >> deadline >> goalPoints;
    _findSourceFile(sourceFileId)
        ->setCompilationTarget(unique_ptr<CompilationTarget>(new CompilationTarget{deadline, goalPoints}));
  }
}

void InputParser::_addParsedSourceFile(SourceFilePtr &sourceFile) {
  _parsedSourceFilesMap[sourceFile->getId()] = sourceFile;
  _parsedSourceFiles.push_back(sourceFile);
}

SourceFilePtr InputParser::_findSourceFile(string id) { return _parsedSourceFilesMap[id]; }
