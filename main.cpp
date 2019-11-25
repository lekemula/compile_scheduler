#include <iostream>
#include <server.h>
#include <solution.h>
#include "source_file.h"
#include "input_parser.h"

int main(int argc, char * argv[]) {
    const char * inputFilePath = argv[1];

    InputParser inputParser(inputFilePath);
    InputMetadata inputMetadata;
    ServerPtr server(new Server(1));

    auto sourceFiles = inputParser.parse(inputMetadata);

    cout << "Total Files: " << inputMetadata.filesCount << endl;
    cout << "Target Files: " << inputMetadata.targetsCount << endl;
    cout << "Servers: " << inputMetadata.serversCount << endl;

    for (auto & sourceFile : sourceFiles) {
        cout << *sourceFile << endl;
    }

    Solution solution;

    solution.compile(sourceFiles[0], server);
    solution.compile(sourceFiles[1], server);

    cout << solution.toString();

//    cout << sourceFiles[4]->getPoints(45) << endl;
//    cout << server->getCompilationTime();

//    {
//          t0, s0, c0 // 15
//          t0, s1, c1 // 18
//          t15, s0, c2 // 30
//          t10, s1, c3 // 23
//
//    }

    return 0;
}