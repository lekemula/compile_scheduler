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
    vector<SourceFilePtr> _parsedSourceFiles;
    unordered_map<string, SourceFilePtr> _parsedSourceFilesMap;

    void _open();
    void _close();
    void _parseInputMetadata();
    void _parseSourceFiles();
    void _parseFileDependencies(SourceFilePtr &sourceFile);
    void _parseFileTargets();
    void _addParsedSourceFile(SourceFilePtr &sourceFile);
    SourceFilePtr _findSourceFile(string id);

public:
    InputParser(string inputSourcePath);
    vector<SourceFilePtr> parse(InputMetadata& inputMetadata);
};


#endif //COMPILE_SCHEDULER_INPUT_PARSER_H
