#include <iostream>
#include <server.h>
#include <solution.h>
#include "source_file.h"
#include "input_parser.h"
#include <algorithm>
#include <algorithm/grasp.h>
#include <algorithm/complex_constructor.h>
#include <algorithm/least_busy_server_constructor.h>

void printSourceFiles(vector<SourceFilePtr> & sourceFiles){
    for (auto & sourceFile : sourceFiles) {
        cout << *sourceFile << endl;
    }

    cout << endl;
}

int main(int argc, char * argv[]) {
    const char * inputFilePath = argv[1];

    InputParser inputParser(inputFilePath);
    InputMetadata inputMetadata;
    ServerPtr server(new Server(1));

    auto sourceFiles = inputParser.parse(inputMetadata);
    auto orderedSourceFiles = sourceFiles;

//    std::sort(orderedSourceFiles.begin(), orderedSourceFiles.end(), [](SourceFilePtr & sf1, SourceFilePtr & sf2) -> bool {
//        return (sf1->getDependencies().size() < sf2->getDependencies().size());
//    });

    cout << "Total Files: " << inputMetadata.filesCount << endl;
    cout << "Target Files: " << inputMetadata.targetsCount << endl;
    cout << "Servers: " << inputMetadata.serversCount << endl;

    printSourceFiles(sourceFiles);
//    cout << endl;
//    printSourceFiles(orderedSourceFiles);

    vector<ServerPtr> servers;

    for (int i = 0; i < inputMetadata.serversCount; ++i) {
        servers.push_back(ServerPtr(new Server(i)));
    }

    LeastBusyServerConstructor greedyConstructor;
    Grasp grasp({ sourceFiles, servers }, greedyConstructor, 100);

    cout << *grasp.perform();
//    cout << solution.toString();

//    Solution solution;
//    solution.compile(sourceFiles[0], servers[0]);
//    cout << solution.closestCompilationStart(sourceFiles[2], servers[1]);

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