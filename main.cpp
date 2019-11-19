#include <iostream>
#include "source_file.h"
#include "input_parser.h"

int main(int argc, char* argv[]) {
    const char* inputFilePath = argv[1];

    InputParser inputParser(inputFilePath);
    InputMetadata inputMetadata;

    auto sourceFiles = inputParser.parse(inputMetadata);

    cout << "Total Files: " << inputMetadata.filesCount << endl;
    cout << "Target Files: " << inputMetadata.targetsCount << endl;
    cout << "Servers: " << inputMetadata.serversCount << endl;

    for(shared_ptr<SourceFile> sourceFile : sourceFiles){
        std::cout << *sourceFile << std::endl;
    }

    return 0;
}