#include <iostream>
#include "source_file.h"
#include "compilation_target.h"
#include "input_parser.h"

int main(int argc, char* argv[]) {
    const char* inputFilePath = argv[1];

    InputParser inputParser(inputFilePath);

    for(SourceFile* sourceFile : inputParser.parse()){
        std::cout << *sourceFile << std::endl;
    }

    return 0;
}