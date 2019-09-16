//
// Created by leke on 9/7/19.
//

#ifndef COMPILE_SCHEDULER_INPUT_PARSER_H
#define COMPILE_SCHEDULER_INPUT_PARSER_H

#include <fstream>
#include <map>
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
    vector<SourceFile*> _parsedSourceFiles;
    map<string, SourceFile*> _parsedSourceFilesMap;

    void _open();
    void _close();
    void _parseInputMetadata();
    void _parseSourceFiles();
    void _parseFileDependencies(SourceFile *sourceFile);
    void _parseFileTargets();
    void _addParsedSourceFile(SourceFile* sourceFile);
    SourceFile* _findSourceFile(string id);

public:
    InputParser(string inputSourcePath);
    ~InputParser();
    vector<SourceFile*> parse();
};


#endif //COMPILE_SCHEDULER_INPUT_PARSER_H
