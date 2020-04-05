#include <iostream>
#include <server.h>
#include <solution.h>
#include "source_file.h"
#include "input_parser.h"
#include <algorithm>
#include <algorithm/grasp.h>
#include <algorithm/complex_constructor.h>
#include <algorithm/least_busy_server_constructor.h>
#include <algorithm/closest_compilation_start_constructor.h>
#include <algorithm/most_target_dependants_constructor.h>
#include "helpers.h"

void printSourceFiles(vector<SourceFilePtr> & sourceFiles){
    for (auto & sourceFile : sourceFiles) {
        cout << *sourceFile << endl;
    }

    cout << endl;
}

void printInputInfos(InputMetadata & inputMetadata){
    cout << "Total Files: " << inputMetadata.filesCount << endl;
    cout << "Target Files: " << inputMetadata.targetsCount << endl;
    cout << "Servers: " << inputMetadata.serversCount << endl;
}

void printResults(Solution & solution){
    cout << solution;
    cout << "TOTAL SCORE = " << solution.score() << endl;
}

Problem parseSourceFilesFromFile(string filePath, InputMetadata & outMetadata){
    InputParser inputParser(filePath);
    vector<ServerPtr> servers;
    auto sourceFiles = inputParser.parse(outMetadata);

    for (int i = 0; i < outMetadata.serversCount; ++i) {
        servers.push_back(ServerPtr(new Server(i)));
    }

    return Problem({ sourceFiles, servers });
}

int main(int argc, char * argv[]) {
    const char * inputFilePath = argv[1];

    InputMetadata inputMetadata;
    auto problem = parseSourceFilesFromFile(inputFilePath, inputMetadata);

    printInputInfos(inputMetadata);
    printSourceFiles(problem.sourceFiles);

    const int greedyConstructorsCount = 4;

    string greedyConstructorNames[greedyConstructorsCount] {
        "MostTargetDependantsConstructor",
        "ClosestCompilationStartConstructor",
        "LeastBusyServerConstructor",
        "ComplexConstructor",
    };

    shared_ptr<GreedyConstructor> greedyConstructors[greedyConstructorsCount] = {
        shared_ptr<GreedyConstructor>(new MostTargetDependantsConstructor()),
        shared_ptr<GreedyConstructor>(new ClosestCompilationStartConstructor()),
        shared_ptr<GreedyConstructor>(new LeastBusyServerConstructor()),
        shared_ptr<GreedyConstructor>(new ComplexConstructor())
    };

    for (int i = 0; i < greedyConstructorsCount; ++i) {
        string greedyConstructorName = greedyConstructorNames[i];
        auto greedyConstructor = greedyConstructors[i];
        auto problem = parseSourceFilesFromFile(inputFilePath, inputMetadata);

        cout << "Running with " + greedyConstructorName + " constructor" << endl;

        Grasp grasp(problem, *greedyConstructor, 100);
        unique_ptr<Solution> solution;

        int execTime = measureBlockExecution("Grasp Construction Performance", [& solution, grasp]() mutable{
            solution = grasp.perform();
        });

        printResults(*solution);
        cout << "Execution time: " << execTime << endl;
    }

    return 0;
}