#include <iostream>
#include <server.h>
#include "source_file.h"
#include "input_parser.h"

int main(int argc, char* argv[]) {
    const char* inputFilePath = argv[1];

    InputParser inputParser(inputFilePath);
    InputMetadata inputMetadata;
    Server server;

    auto sourceFiles = inputParser.parse(inputMetadata);

    cout << "Total Files: " << inputMetadata.filesCount << endl;
    cout << "Target Files: " << inputMetadata.targetsCount << endl;
    cout << "Servers: " << inputMetadata.serversCount << endl;

    Server server2 = server;
    server.compile(sourceFiles[1]);

    cout << server2.canCompile(sourceFiles[3]);

//    {
//          t0, s0, c0 // 15
//          t0, s1, c1 // 18
//          t15, s0, c2 // 30
//          t10, s1, c3 // 23
//
//    }

    return 0;
}