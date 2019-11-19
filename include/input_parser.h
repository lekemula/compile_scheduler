//
// Created by leke on 9/7/19.
//

#ifndef COMPILE_SCHEDULER_INPUT_PARSER_H
#define COMPILE_SCHEDULER_INPUT_PARSER_H

#include <fstream>
#include <map>
#include <memory>
#include <string>
#include <fstream>
#include <vector>
#include "source_file.h"

using namespace std;

struct InputMetadata {
    int filesCount;
    int targetsCount;
    int serversCount;
};

class InputParser {
private:
    string _inputSourcePath;
    ifstream _file;
    InputMetadata _metadata;
    vector<shared_ptr<SourceFile>> _parsedSourceFiles;
    map<string, shared_ptr<SourceFile>> _parsedSourceFilesMap;

    void _open();
    void _close();
    void _parseInputMetadata();
    void _parseSourceFiles();
    void _parseFileDependencies(shared_ptr<SourceFile> &sourceFile);
    void _parseFileTargets();
    void _addParsedSourceFile(shared_ptr<SourceFile> &sourceFile);
    shared_ptr<SourceFile> _findSourceFile(string id);

public:
    InputParser(string inputSourcePath);
    vector<shared_ptr<SourceFile>> parse(InputMetadata& inputMetadata);
};


#endif //COMPILE_SCHEDULER_INPUT_PARSER_H
